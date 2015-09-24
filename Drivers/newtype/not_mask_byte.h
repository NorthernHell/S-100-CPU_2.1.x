/**************************************************************************
File:               not_mask_byte.h
Author:             ICS Triplex ISaGRAF
Creation date:      21/03/2007 - 16:38
POU name:           NOT_MASK_BYTE
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _NOT_MASK_BYTE_H /* nested Headers management */
#define _NOT_MASK_BYTE_H

/* function prototype */

ISANDTDLL void not_mask_byteUsfCall
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

#endif /* _NOT_MASK_BYTE_H */

/* eof ********************************************************************/

