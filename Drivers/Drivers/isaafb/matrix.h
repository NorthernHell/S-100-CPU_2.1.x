/**************************************************************************
File:               matrix.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           MATRIX
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _MATRIX_H /* nested Headers management */
#define _MATRIX_H

/* prototypes */

ISAAFBDLL void matrixFblClassInit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void matrixFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );
ISAAFBDLL void matrixFblInstInit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void matrixFblInstExit
   (
   void* pvBfData, /* In: Data */
   strParamVa* FblInst /* In: Function Block instance */
   );
ISAAFBDLL void matrixFblCall
   (
   void* pvBfData, /* In: Data */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* FblInst, /* In: Function Block instance */
   void* pvAdi          /* In: Pointer to ADI table */
#else
   strParamVa* FblInst /* In: Function Block instance */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _MATRIX_H */

/* eof ********************************************************************/

