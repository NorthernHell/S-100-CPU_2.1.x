/**************************************************************************
File:               shl_dword.h
Author:             ICS Triplex ISaGRAF
Creation date:      22/03/2007 - 11:45
POU name:           SHL_DWORD
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _SHL_DWORD_H /* nested Headers management */
#define _SHL_DWORD_H

/* function prototype */

ISANDTDLL void shl_dwordUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* OutParam,     /* In: Output parameter */
   void*       pvAdi         /* In: Pointer to ADI table */
#else
   strParamVa* OutParam      /* In: Output parameter */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _SHL_DWORD_H */

/* eof ********************************************************************/

