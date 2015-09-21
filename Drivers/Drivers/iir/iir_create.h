/**************************************************************************
File:               iir_create.h
Author:             root
Creation date:      17/10/2007 - 17:45
POU name:           IIR_create
***************************************************************************/

#ifndef _IIR_CREATE_H /* nested Headers management */
#define _IIR_CREATE_H

/* function prototype */

void iir_createUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _IIR_CREATE_H */

/* eof ********************************************************************/

