/**************************************************************************
File:               ratiocalibration.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           RATIOCALIBRATION
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _RATIOCALIBRATION_H /* nested Headers management */
#define _RATIOCALIBRATION_H

/* prototypes */

ISAAFBDLL void ratiocalibrationFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void ratiocalibrationFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void ratiocalibrationFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void ratiocalibrationFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void ratiocalibrationFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _RATIOCALIBRATION_H */

/* eof ********************************************************************/

