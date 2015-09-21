/**************************************************************************
File:               fir_vector.h
Author:             alex
Creation date:      15/03/2009 - 12:35
POU name:           FIR_vector
***************************************************************************/

#ifndef _FIR_VECTOR_H /* nested Headers management */
#define _FIR_VECTOR_H

/* function prototype */

void fir_vectorUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _FIR_VECTOR_H */

/* eof ********************************************************************/

