/**************************************************************************
File:               firf.h
Author:             root
Creation date:      16/10/2007 - 11:09
POU name:           FIRf
***************************************************************************/

#ifndef _FIRF_H /* nested Headers management */
#define _FIRF_H

/* function prototype */

void firfUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _FIRF_H */

/* eof ********************************************************************/

