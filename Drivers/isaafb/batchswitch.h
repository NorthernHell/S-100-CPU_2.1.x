/**************************************************************************
File:               batchswitch.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           BATCHSWITCH
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _BATCHSWITCH_H /* nested Headers management */
#define _BATCHSWITCH_H

/* prototypes */

ISAAFBDLL void batchswitchFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void batchswitchFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void batchswitchFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void batchswitchFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void batchswitchFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _BATCHSWITCH_H */

/* eof ********************************************************************/

