/**************************************************************************
File:               batchtotalizer.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           BATCHTOTALIZER
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _BATCHTOTALIZER_H /* nested Headers management */
#define _BATCHTOTALIZER_H

/* prototypes */

ISAAFBDLL void batchtotalizerFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void batchtotalizerFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void batchtotalizerFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void batchtotalizerFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void batchtotalizerFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _BATCHTOTALIZER_H */

/* eof ********************************************************************/

