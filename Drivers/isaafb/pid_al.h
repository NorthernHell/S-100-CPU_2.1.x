/**************************************************************************
File:               pid_al.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      15/02/2012 - 16:09
POU name:           PID_AL
***************************************************************************/

#ifndef _PID_AL_H /* nested Headers management */
#define _PID_AL_H

/* prototypes */

ISAAFBDLL void pid_alFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void pid_alFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void pid_alFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void pid_alFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void pid_alFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _PID_AL_H */

/* eof ********************************************************************/

