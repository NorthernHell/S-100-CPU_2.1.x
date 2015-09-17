/**************************************************************************
File:               alarm_date.h
Author:             Lipovets
Creation date:      21/12/2009 - 18:29
POU name:           alarm_date
***************************************************************************/

#ifndef _ALARM_DATE_H /* nested Headers management */
#define _ALARM_DATE_H

/* function prototype */

void alarm_dateUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _ALARM_DATE_H */

/* eof ********************************************************************/

