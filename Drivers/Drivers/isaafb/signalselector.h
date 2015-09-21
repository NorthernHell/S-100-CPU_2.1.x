/**************************************************************************
File:               signalselector.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           SIGNALSELECTOR
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _SIGNALSELECTOR_H /* nested Headers management */
#define _SIGNALSELECTOR_H

/* prototypes */

ISAAFBDLL void signalselectorFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void signalselectorFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void signalselectorFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void signalselectorFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void signalselectorFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _SIGNALSELECTOR_H */

/* eof ********************************************************************/

