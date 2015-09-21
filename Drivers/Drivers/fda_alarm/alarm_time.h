/**************************************************************************
File:               alarm_time.h
Author:             Lipovets
Creation date:      21/12/2009 - 18:29
POU name:           alarm_time
***************************************************************************/

#ifndef _ALARM_TIME_H /* nested Headers management */
#define _ALARM_TIME_H

/* function prototype */

void alarm_timeUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _ALARM_TIME_H */

/* eof ********************************************************************/

