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
/*-----------------------------------------*/
/*																		*/
/* Name:		<Xfe/DialogUtil.h>										*/
/* Description:	Dialog utilities header.								*/
/* Author:		Ramiro Estrugo <ramiro@netscape.com>					*/
/*																		*/
/*----------------------------------------------------------------------*/


#ifndef _XfeDialogUtil_h_						/* start DialogUtil.h	*/
#define _XfeDialogUtil_h_

#include <X11/Intrinsic.h>						/* Xt public defs		*/

#ifdef __cplusplus								/* start C++			*/
extern "C" {
#endif

/*----------------------------------------------------------------------*/
/*																		*/
/* Menus																*/
/*																		*/
/*----------------------------------------------------------------------*/
extern void
XfeUpdateDisplay				(Widget			w);
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*																		*/
/* Find the parent dialog for a widget									*/
/*																		*/
/*----------------------------------------------------------------------*/
extern Widget
XfeGetParentDialog				(Widget			w);
/*----------------------------------------------------------------------*/


#ifdef __cplusplus								/* end C++				*/
}
#endif

#endif											/* end DialogUtil.h		*/
