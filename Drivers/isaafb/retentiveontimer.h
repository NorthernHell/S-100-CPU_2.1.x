/**************************************************************************
File:               retentiveontimer.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           RETENTIVEONTIMER
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _RETENTIVEONTIMER_H /* nested Headers management */
#define _RETENTIVEONTIMER_H

/* prototypes */

ISAAFBDLL void retentiveontimerFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void retentiveontimerFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void retentiveontimerFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void retentiveontimerFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void retentiveontimerFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _RETENTIVEONTIMER_H */

/* eof ********************************************************************/

