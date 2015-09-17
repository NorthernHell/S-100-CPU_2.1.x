/**************************************************************************
File:               iir.h
Author:             root
Creation date:      17/10/2007 - 17:45
POU name:           IIR
***************************************************************************/

#ifndef _IIR_H /* nested Headers management */
#define _IIR_H

/* function prototype */

void iirUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _IIR_H */

/* eof ********************************************************************/

