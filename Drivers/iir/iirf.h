/**************************************************************************
File:               iirf.h
Author:             root
Creation date:      17/10/2007 - 17:45
POU name:           IIRf
***************************************************************************/

#ifndef _IIRF_H /* nested Headers management */
#define _IIRF_H

/* function prototype */

void iirfUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _IIRF_H */

/* eof ********************************************************************/

