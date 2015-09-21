/**************************************************************************
File:               scaler.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           SCALER
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _SCALER_H /* nested Headers management */
#define _SCALER_H

/* prototypes */

ISAAFBDLL void scalerFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void scalerFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void scalerFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void scalerFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void scalerFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _SCALER_H */

/* eof ********************************************************************/

