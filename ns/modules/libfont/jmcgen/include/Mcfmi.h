/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
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
/*******************************************************************************
 * Source date: 9 Apr 1997 21:45:13 GMT
 * netscape/fonts/cfmi module C header file
 * Generated by jmc version 1.8 -- DO NOT EDIT
 ******************************************************************************/

#ifndef _Mcfmi_H_
#define _Mcfmi_H_

#include "jmc.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 * cfmi
 ******************************************************************************/

/* The type of the cfmi interface. */
struct cfmiInterface;

/* The public type of a cfmi instance. */
typedef struct cfmi {
	const struct cfmiInterface*	vtable;
} cfmi;

/* The inteface ID of the cfmi interface. */
#ifndef JMC_INIT_cfmi_ID
extern EXTERN_C_WITHOUT_EXTERN const JMCInterfaceID cfmi_ID;
#else
EXTERN_C const JMCInterfaceID cfmi_ID = { 0x22420e05, 0x574c4001, 0x5a4e671e, 0x0b464713 };
#endif /* JMC_INIT_cfmi_ID */
/*******************************************************************************
 * cfmi Operations
 ******************************************************************************/

#define cfmi_getInterface(self, a, exception)	\
	(((self)->vtable->getInterface)(self, cfmi_getInterface_op, a, exception))

#define cfmi_addRef(self, exception)	\
	(((self)->vtable->addRef)(self, cfmi_addRef_op, exception))

#define cfmi_release(self, exception)	\
	(((self)->vtable->release)(self, cfmi_release_op, exception))

#define cfmi_hashCode(self, exception)	\
	(((self)->vtable->hashCode)(self, cfmi_hashCode_op, exception))

#define cfmi_equals(self, a, exception)	\
	(((self)->vtable->equals)(self, cfmi_equals_op, a, exception))

#define cfmi_clone(self, exception)	\
	(((self)->vtable->clone)(self, cfmi_clone_op, exception))

#define cfmi_toString(self, exception)	\
	(((self)->vtable->toString)(self, cfmi_toString_op, exception))

#define cfmi_finalize(self, exception)	\
	(((self)->vtable->finalize)(self, cfmi_finalize_op, exception))

#define cfmi_GetValue(self, a, exception)	\
	(((self)->vtable->GetValue)(self, cfmi_GetValue_op, a, exception))

#define cfmi_ListAttributes(self, exception)	\
	(((self)->vtable->ListAttributes)(self, cfmi_ListAttributes_op, exception))

/*******************************************************************************
 * cfmi Interface
 ******************************************************************************/

struct netscape_jmc_JMCInterfaceID;
struct java_lang_Object;
struct java_lang_String;
struct netscape_jmc_ConstCString;

struct cfmiInterface {
	void*	(*getInterface)(struct cfmi* self, jint op, const JMCInterfaceID* a, JMCException* *exception);
	void	(*addRef)(struct cfmi* self, jint op, JMCException* *exception);
	void	(*release)(struct cfmi* self, jint op, JMCException* *exception);
	jint	(*hashCode)(struct cfmi* self, jint op, JMCException* *exception);
	jbool	(*equals)(struct cfmi* self, jint op, void* a, JMCException* *exception);
	void*	(*clone)(struct cfmi* self, jint op, JMCException* *exception);
	const char*	(*toString)(struct cfmi* self, jint op, JMCException* *exception);
	void	(*finalize)(struct cfmi* self, jint op, JMCException* *exception);
	void*	(*GetValue)(struct cfmi* self, jint op, const char* a, JMCException* *exception);
	void*	(*ListAttributes)(struct cfmi* self, jint op, JMCException* *exception);
};

/*******************************************************************************
 * cfmi Operation IDs
 ******************************************************************************/

typedef enum cfmiOperations {
	cfmi_getInterface_op,
	cfmi_addRef_op,
	cfmi_release_op,
	cfmi_hashCode_op,
	cfmi_equals_op,
	cfmi_clone_op,
	cfmi_toString_op,
	cfmi_finalize_op,
	cfmi_GetValue_op,
	cfmi_ListAttributes_op
} cfmiOperations;

/*******************************************************************************
 * Writing your C implementation: "cfmi.h"
 * *****************************************************************************
 * You must create a header file named "cfmi.h" that implements
 * the struct cfmiImpl, including the struct cfmiImplHeader
 * as it's first field:
 * 
 * 		#include "Mcfmi.h" // generated header
 * 
 * 		struct cfmiImpl {
 * 			cfmiImplHeader	header;
 * 			<your instance data>
 * 		};
 * 
 * This header file will get included by the generated module implementation.
 ******************************************************************************/

/* Forward reference to the user-defined instance struct: */
typedef struct cfmiImpl	cfmiImpl;


/* This struct must be included as the first field of your instance struct: */
typedef struct cfmiImplHeader {
	const struct cfmiInterface*	vtablecfmi;
	jint		refcount;
} cfmiImplHeader;

/*******************************************************************************
 * Instance Casting Macros
 * These macros get your back to the top of your instance, cfmi,
 * given a pointer to one of its interfaces.
 ******************************************************************************/

#undef  cfmiImpl2nffmi
#define cfmiImpl2nffmi(cfmiImplPtr) \
	((nffmi*)((char*)(cfmiImplPtr) + offsetof(cfmiImplHeader, vtablecfmi)))

#undef  nffmi2cfmiImpl
#define nffmi2cfmiImpl(nffmiPtr) \
	((cfmiImpl*)((char*)(nffmiPtr) - offsetof(cfmiImplHeader, vtablecfmi)))

#undef  cfmiImpl2cfmi
#define cfmiImpl2cfmi(cfmiImplPtr) \
	((cfmi*)((char*)(cfmiImplPtr) + offsetof(cfmiImplHeader, vtablecfmi)))

#undef  cfmi2cfmiImpl
#define cfmi2cfmiImpl(cfmiPtr) \
	((cfmiImpl*)((char*)(cfmiPtr) - offsetof(cfmiImplHeader, vtablecfmi)))

/*******************************************************************************
 * Operations you must implement
 ******************************************************************************/


extern JMC_PUBLIC_API(void*)
_cfmi_getBackwardCompatibleInterface(struct cfmi* self, const JMCInterfaceID* iid,
	JMCException* *exception);

extern JMC_PUBLIC_API(void)
_cfmi_init(struct cfmi* self, JMCException* *exception, const char* a, const char* b, const char* c, jint d, jint e, jint f, jint g, jint h, jint i, jint j);

extern JMC_PUBLIC_API(void*)
_cfmi_getInterface(struct cfmi* self, jint op, const JMCInterfaceID* a, JMCException* *exception);

extern JMC_PUBLIC_API(void)
_cfmi_addRef(struct cfmi* self, jint op, JMCException* *exception);

extern JMC_PUBLIC_API(void)
_cfmi_release(struct cfmi* self, jint op, JMCException* *exception);

extern JMC_PUBLIC_API(jint)
_cfmi_hashCode(struct cfmi* self, jint op, JMCException* *exception);

extern JMC_PUBLIC_API(jbool)
_cfmi_equals(struct cfmi* self, jint op, void* a, JMCException* *exception);

extern JMC_PUBLIC_API(void*)
_cfmi_clone(struct cfmi* self, jint op, JMCException* *exception);

extern JMC_PUBLIC_API(const char*)
_cfmi_toString(struct cfmi* self, jint op, JMCException* *exception);

extern JMC_PUBLIC_API(void)
_cfmi_finalize(struct cfmi* self, jint op, JMCException* *exception);

extern JMC_PUBLIC_API(void*)
_cfmi_GetValue(struct cfmi* self, jint op, const char* a, JMCException* *exception);

extern JMC_PUBLIC_API(void*)
_cfmi_ListAttributes(struct cfmi* self, jint op, JMCException* *exception);

/*******************************************************************************
 * Factory Operations
 ******************************************************************************/

JMC_PUBLIC_API(cfmi*)
cfmiFactory_Create(JMCException* *exception, const char* a, const char* b, const char* c, jint d, jint e, jint f, jint g, jint h, jint i, jint j);

/******************************************************************************/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* _Mcfmi_H_ */
