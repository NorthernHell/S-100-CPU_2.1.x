/**************************************************************************
File:               alarm_lint.h
Author:             Lipovets
Creation date:      21/12/2009 - 18:29
POU name:           alarm_lint
***************************************************************************/

#ifndef _ALARM_LINT_H /* nested Headers management */
#define _ALARM_LINT_H

/* function prototype */

void alarm_lintUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _ALARM_LINT_H */

/* eof ********************************************************************/

