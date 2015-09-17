/**************************************************************************
File:               alarm_ulint.h
Author:             Lipovets
Creation date:      21/12/2009 - 18:29
POU name:           alarm_ulint
***************************************************************************/

#ifndef _ALARM_ULINT_H /* nested Headers management */
#define _ALARM_ULINT_H

/* function prototype */

void alarm_ulintUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _ALARM_ULINT_H */

/* eof ********************************************************************/

