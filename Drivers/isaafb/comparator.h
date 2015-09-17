/**************************************************************************
File:               comparator.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           COMPARATOR
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _COMPARATOR_H /* nested Headers management */
#define _COMPARATOR_H

/* prototypes */

ISAAFBDLL void comparatorFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void comparatorFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void comparatorFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void comparatorFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void comparatorFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _COMPARATOR_H */

/* eof ********************************************************************/

