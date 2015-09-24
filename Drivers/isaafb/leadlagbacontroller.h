/**************************************************************************
File:               leadlagbacontroller.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           LEADLAGBACONTROLLER
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _LEADLAGBACONTROLLER_H /* nested Headers management */
#define _LEADLAGBACONTROLLER_H

/* prototypes */

ISAAFBDLL void leadlagbacontrollerFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void leadlagbacontrollerFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void leadlagbacontrollerFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void leadlagbacontrollerFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void leadlagbacontrollerFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _LEADLAGBACONTROLLER_H */

/* eof ********************************************************************/

