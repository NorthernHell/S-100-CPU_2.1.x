/**************************************************************************
File:               rt_var_udint.h
Author:             Alexander
Creation date:      17/08/2006 - 16:59
POU name:           rt_var_udint
***************************************************************************/

#ifndef _RT_VAR_UDINT_H /* nested Headers management */
#define _RT_VAR_UDINT_H

/* function prototype */

void rt_var_udintUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _RT_VAR_UDINT_H */

/* eof ********************************************************************/

