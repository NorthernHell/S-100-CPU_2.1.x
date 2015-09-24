/**************************************************************************
File:               shr_lword.h
Author:             ICS Triplex ISaGRAF
Creation date:      27/03/2007 - 18:15
POU name:           SHR_LWORD
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _SHR_LWORD_H /* nested Headers management */
#define _SHR_LWORD_H

/* function prototype */

ISANDTDLL void shr_lwordUsfCall
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

#endif /* _SHR_LWORD_H */

/* eof ********************************************************************/

