/**************************************************************************
File:               characterizer.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           CHARACTERIZER
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _CHARACTERIZER_H /* nested Headers management */
#define _CHARACTERIZER_H

/* prototypes */

ISAAFBDLL void characterizerFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void characterizerFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void characterizerFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void characterizerFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void characterizerFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _CHARACTERIZER_H */

/* eof ********************************************************************/

