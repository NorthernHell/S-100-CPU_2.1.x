/**************************************************************************
File:               rt_arr.h
Author:             Alexander
Creation date:      17/08/2006 - 14:20
POU name:           rt_arr
***************************************************************************/

#ifndef _RT_ARR_H /* nested Headers management */
#define _RT_ARR_H

/* function prototype */

void rt_arrUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _RT_ARR_H */

/* eof ********************************************************************/

