/**************************************************************************
File:               shr_dword.h
Author:             ICS Triplex ISaGRAF
Creation date:      22/03/2007 - 11:45
POU name:           SHR_DWORD
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _SHR_DWORD_H /* nested Headers management */
#define _SHR_DWORD_H

/* function prototype */

ISANDTDLL void shr_dwordUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uint16      huNbInParam,  /* In: Number of input parameters */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* OutParam,     /* In: Output parameter */
   void*       pvAdi         /* In: Pointer to ADI table */
#else
   strParamVa* OutParam      /* In: Output parameter */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _SHR_DWORD_H */

/* eof ********************************************************************/

