/**************************************************************************
File:               leadlagcontroller.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           LEADLAGCONTROLLER
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _LEADLAGCONTROLLER_H /* nested Headers management */
#define _LEADLAGCONTROLLER_H

/* prototypes */

ISAAFBDLL void leadlagcontrollerFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void leadlagcontrollerFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void leadlagcontrollerFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void leadlagcontrollerFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void leadlagcontrollerFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _LEADLAGCONTROLLER_H */

/* eof ********************************************************************/

