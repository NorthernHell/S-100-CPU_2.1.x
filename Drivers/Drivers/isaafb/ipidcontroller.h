/**************************************************************************
File:               ipidcontroller.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           IPIDCONTROLLER
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _IPIDCONTROLLER_H /* nested Headers management */
#define _IPIDCONTROLLER_H

/* prototypes */

ISAAFBDLL void ipidcontrollerFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void ipidcontrollerFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void ipidcontrollerFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void ipidcontrollerFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void ipidcontrollerFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _IPIDCONTROLLER_H */

/* eof ********************************************************************/

