/**************************************************************************
File:               gettimestruct.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           GET_TIME_STRUCT
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _GETTIMESTRUCT_H /* nested Headers management */
#define _GETTIMESTRUCT_H

/* prototypes */

ISAAFBDLL void get_time_structFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void get_time_structFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void get_time_structFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void get_time_structFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void get_time_structFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _GETTIMESTRUCT_H */

/* eof ********************************************************************/

