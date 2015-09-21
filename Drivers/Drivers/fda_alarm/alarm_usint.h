/**************************************************************************
File:               alarm_usint.h
Author:             Lipovets
Creation date:      21/12/2009 - 18:29
POU name:           alarm_usint
***************************************************************************/

#ifndef _ALARM_USINT_H /* nested Headers management */
#define _ALARM_USINT_H

/* function prototype */

void alarm_usintUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _ALARM_USINT_H */

/* eof ********************************************************************/

