/**************************************************************************
File:               iir_vector.h
Author:             alex
Creation date:      15/03/2009 - 12:35
POU name:           IIR_vector
***************************************************************************/

#ifndef _IIR_VECTOR_H /* nested Headers management */
#define _IIR_VECTOR_H

/* function prototype */

void iir_vectorUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _IIR_VECTOR_H */

/* eof ********************************************************************/

