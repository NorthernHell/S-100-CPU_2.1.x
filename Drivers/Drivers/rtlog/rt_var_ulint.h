/**************************************************************************
File:               rt_var_ulint.h
Author:             Alexander
Creation date:      17/08/2006 - 16:59
POU name:           rt_var_ulint
***************************************************************************/

#ifndef _RT_VAR_ULINT_H /* nested Headers management */
#define _RT_VAR_ULINT_H

/* function prototype */

void rt_var_ulintUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _RT_VAR_ULINT_H */

/* eof ********************************************************************/

