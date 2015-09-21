/**************************************************************************
File:               ratelimiter.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           RATELIMITER
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _RATELIMITER_H /* nested Headers management */
#define _RATELIMITER_H

/* prototypes */

ISAAFBDLL void ratelimiterFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void ratelimiterFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void ratelimiterFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void ratelimiterFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void ratelimiterFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _RATELIMITER_H */

/* eof ********************************************************************/

