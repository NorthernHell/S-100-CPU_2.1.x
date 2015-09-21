/**************************************************************************
File:               alarm_real.h
Author:             Lipovets
Creation date:      21/12/2009 - 18:29
POU name:           alarm_real
***************************************************************************/

#ifndef _ALARM_REAL_H /* nested Headers management */
#define _ALARM_REAL_H

/* function prototype */

void alarm_realUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _ALARM_REAL_H */

/* eof ********************************************************************/

