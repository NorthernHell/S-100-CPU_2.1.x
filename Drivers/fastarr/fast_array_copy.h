/**************************************************************************
File:               fast_array_copy.h
Author:             Levizi
Creation date:      01/09/2006 - 15:41
POU name:           Fast_array_copy
***************************************************************************/

#ifndef _FAST_ARRAY_COPY_H /* nested Headers management */
#define _FAST_ARRAY_COPY_H

/* function prototype */

void fast_array_copyUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _FAST_ARRAY_COPY_H */

/* eof ********************************************************************/

