/**************************************************************************
File:               ratio.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           RATIO
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _RATIO_H /* nested Headers management */
#define _RATIO_H

/* prototypes */

ISAAFBDLL void ratioFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void ratioFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void ratioFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void ratioFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void ratioFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _RATIO_H */

/* eof ********************************************************************/

