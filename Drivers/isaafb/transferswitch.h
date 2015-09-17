/**************************************************************************
File:               transferswitch.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           TRANSFERSWITCH
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _TRANSFERSWITCH_H /* nested Headers management */
#define _TRANSFERSWITCH_H

/* prototypes */

ISAAFBDLL void transferswitchFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void transferswitchFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void transferswitchFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void transferswitchFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void transferswitchFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _TRANSFERSWITCH_H */

/* eof ********************************************************************/

