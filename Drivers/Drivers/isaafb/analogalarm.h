/**************************************************************************
File:               analogalarm.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           ANALOGALARM
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _ANALOGALARM_H /* nested Headers management */
#define _ANALOGALARM_H


/* prototypes */

ISAAFBDLL void analogalarmFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void analogalarmFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void analogalarmFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void analogalarmFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void analogalarmFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _ANALOGALARM_H */

/* eof ********************************************************************/

