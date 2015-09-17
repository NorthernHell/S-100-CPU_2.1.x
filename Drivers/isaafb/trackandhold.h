/**************************************************************************
File:               trackandhold.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           TRACKANDHOLD
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _TRACKANDHOLD_H /* nested Headers management */
#define _TRACKANDHOLD_H

/* prototypes */

ISAAFBDLL void trackandholdFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void trackandholdFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void trackandholdFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void trackandholdFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void trackandholdFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _TRACKANDHOLD_H */

/* eof ********************************************************************/

