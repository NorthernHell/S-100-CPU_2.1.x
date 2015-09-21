/**************************************************************************
File:               fir_create.h
Author:             root
Creation date:      16/10/2007 - 11:09
POU name:           FIR_create
***************************************************************************/

#ifndef _FIR_CREATE_H /* nested Headers management */
#define _FIR_CREATE_H

/* function prototype */

void fir_createUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _FIR_CREATE_H */

/* eof ********************************************************************/

