/**************************************************************************
File:               biascalibration.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           BIASCALIBRATION
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _BIASCALIBRATION_H /* nested Headers management */
#define _BIASCALIBRATION_H

/* prototypes */

ISAAFBDLL void biascalibrationFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void biascalibrationFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void biascalibrationFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void biascalibrationFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void biascalibrationFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _BIASCALIBRATION_H */

/* eof ********************************************************************/

