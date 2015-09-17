/**************************************************************************
File:               bias.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           BIAS
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _BIAS_H /* nested Headers management */
#define _BIAS_H

/* prototypes */

ISAAFBDLL void biasFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void biasFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void biasFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void biasFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void biasFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _BIAS_H */

/* eof ********************************************************************/

