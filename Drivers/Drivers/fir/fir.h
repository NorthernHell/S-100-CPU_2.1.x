/**************************************************************************
File:               fir.h
Author:             root
Creation date:      16/10/2007 - 11:09
POU name:           FIR
***************************************************************************/

#ifndef _FIR_H /* nested Headers management */
#define _FIR_H

/* function prototype */

void firUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _FIR_H */

/* eof ********************************************************************/

