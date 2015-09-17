/**************************************************************************
File:               rt_var_int.h
Author:             Alexander
Creation date:      17/08/2006 - 16:59
POU name:           rt_var_int
***************************************************************************/

#ifndef _RT_VAR_INT_H /* nested Headers management */
#define _RT_VAR_INT_H

/* function prototype */

void rt_var_intUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _RT_VAR_INT_H */

/* eof ********************************************************************/

