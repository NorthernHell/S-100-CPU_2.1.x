/**************************************************************************
File:               or_mask_word.h
Author:             ICS Triplex ISaGRAF
Creation date:      27/03/2007 - 10:27
POU name:           OR_MASK_WORD
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _OR_MASK_WORD_H /* nested Headers management */
#define _OR_MASK_WORD_H

/* function prototype */

ISANDTDLL void or_mask_wordUsfCall
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

#endif /* _OR_MASK_WORD_H */

/* eof ********************************************************************/

