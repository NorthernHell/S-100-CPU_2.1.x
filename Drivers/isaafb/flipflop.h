/**************************************************************************
File:               flipflop.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           FLIPFLOP
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _FLIPFLOP_H /* nested Headers management */
#define _FLIPFLOP_H

/* prototypes */

ISAAFBDLL void flipflopFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void flipflopFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void flipflopFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void flipflopFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void flipflopFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _FLIPFLOP_H */

/* eof ********************************************************************/

