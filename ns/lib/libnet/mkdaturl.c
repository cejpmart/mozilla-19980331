/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 */

#include "mkutils.h"
#include "mkgeturl.h"
#include "cvmime.h"
#include "mkdaturl.h"

extern int MK_OUT_OF_MEMORY;
extern int MK_MALFORMED_URL_ERROR;

/* format of the DATA: URL
 *
 * data:[CONTENT-TYPE][;base64],DATA
 */
PRIVATE int32
net_DataURLLoad (ActiveEntry * ce)
{
	char *data_buffer;
	XP_Bool is_base64 = FALSE;
	NET_StreamClass *stream;
	char *comma;

    ce->protocol = DATA_TYPE_URL;

	/* we need a buffer equal to or smaller than the size of the URL
	 */
	data_buffer = (char *)XP_ALLOC(XP_STRLEN(ce->URL_s->address)+1);

	if(!data_buffer)
		return(MK_OUT_OF_MEMORY);

	/* determine the content type */

	/* find the first comma */
	comma = XP_STRCHR(ce->URL_s->address, ',');

	/* if no comma abort */
	if(!comma)
	{
		ce->URL_s->error_msg = NET_ExplainErrorDetails(MK_MALFORMED_URL_ERROR, ce->URL_s->address);
		return(MK_MALFORMED_URL_ERROR);
	}

	/* fill in default content type */
	StrAllocCopy(ce->URL_s->content_type, TEXT_PLAIN);

	/* check for a content type */
	if(comma != ce->URL_s->address + XP_STRLEN("data:"))
	{
		*comma = '\0';
		XP_STRCPY(data_buffer, ce->URL_s->address + XP_STRLEN("data:"));		
		*comma = ',';

		/* check for base 64 encoding */
		if(strcasestr(data_buffer, "base64"))
			is_base64 = TRUE;

		/* parse the rest as a content-type */
		NET_ParseContentTypeHeader(ce->window_id, data_buffer, ce->URL_s, FALSE);

	}

	if(is_base64)
	{
		stream = NET_MimeEncodingConverter(ce->format_out, ENCODING_BASE64, ce->URL_s, ce->window_id);
	}
	else
	{
		/* open the outgoing stream
		 */
		stream = NET_StreamBuilder(ce->format_out, ce->URL_s, ce->window_id);
	}

	if(!stream)
	  {
		ce->URL_s->error_msg = NET_ExplainErrorDetails(MK_UNABLE_TO_CONVERT);
		ce->status = MK_UNABLE_TO_CONVERT;
		return (ce->status);
	  }

	/* @@@@ bug: ignore is_write_ready */

	/* copy the data part of the URL into a scratch buffer */
	XP_STRCPY(data_buffer, comma+1);

    ce->status = (*stream->put_block)(stream,
                                        data_buffer,
                                        XP_STRLEN(data_buffer));
    if(ce->status < 0)
      {
    	(*stream->abort)(stream, ce->status);
        return (ce->status);
      }

    (*stream->complete)(stream);

	ce->status = MK_DATA_LOADED;
    return(-1); /* all done */
	
}

/* called repeatedly from NET_ProcessNet to push all the
 * data up the stream
 */
PRIVATE int32
net_ProcessDataURL (ActiveEntry * cur_entry)
{
	XP_ASSERT(0);
	return(-1);
}

/* called by functions in mkgeturl to interrupt the loading of
 * an object.  (Usually a user interrupt) 
 */
PRIVATE int32
net_InterruptDataURL (ActiveEntry * cur_entry)
{
	XP_ASSERT(0);
	return(-1);
}

PRIVATE void
net_CleanupDataURL(void)
{

}

MODULE_PRIVATE void
NET_InitDataURLProtocol(void)
{
        static NET_ProtoImpl dataurl_proto_impl;

        dataurl_proto_impl.init = net_DataURLLoad;
        dataurl_proto_impl.process = net_ProcessDataURL;
        dataurl_proto_impl.interrupt = net_InterruptDataURL;
        dataurl_proto_impl.cleanup = net_CleanupDataURL;

        NET_RegisterProtocolImplementation(&dataurl_proto_impl, DATA_TYPE_URL);
}

