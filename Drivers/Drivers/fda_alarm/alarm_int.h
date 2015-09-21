/**************************************************************************
File:               alarm_int.h
Author:             Lipovets
Creation date:      21/12/2009 - 18:29
POU name:           alarm_int
***************************************************************************/

#ifndef _ALARM_INT_H /* nested Headers management */
#define _ALARM_INT_H

/* function prototype */

void alarm_intUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _ALARM_INT_H */

/* eof ********************************************************************/

