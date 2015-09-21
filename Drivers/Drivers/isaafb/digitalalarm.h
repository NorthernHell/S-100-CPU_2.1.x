/**************************************************************************
File:               digitalalarm.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           DIGITALALARM
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _DIGITALALARM_H /* nested Headers management */
#define _DIGITALALARM_H

/* prototypes */

ISAAFBDLL void digitalalarmFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void digitalalarmFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void digitalalarmFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void digitalalarmFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void digitalalarmFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _DIGITALALARM_H */

/* eof ********************************************************************/

