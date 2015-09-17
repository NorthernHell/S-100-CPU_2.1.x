/**************************************************************************
File:               setpoint.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           SETPOINT
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _SETPOINT_H /* nested Headers management */
#define _SETPOINT_H

/* prototypes */

ISAAFBDLL void setpointFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void setpointFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void setpointFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void setpointFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void setpointFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _SETPOINT_H */

/* eof ********************************************************************/

