/**************************************************************************
File:               limiter.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           LIMITER
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _LIMITER_H /* nested Headers management */
#define _LIMITER_H

/* prototypes */

ISAAFBDLL void limiterFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void limiterFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void limiterFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void limiterFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void limiterFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _LIMITER_H */

/* eof ********************************************************************/

