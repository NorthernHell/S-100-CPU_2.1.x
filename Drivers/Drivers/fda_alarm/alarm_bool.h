/**************************************************************************
File:               alarm_bool.h
Author:             Lipovets
Creation date:      21/12/2009 - 18:29
POU name:           alarm_bool
***************************************************************************/

#ifndef _ALARM_BOOL_H /* nested Headers management */
#define _ALARM_BOOL_H

/* function prototype */

void alarm_boolUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _ALARM_BOOL_H */

/* eof ********************************************************************/

