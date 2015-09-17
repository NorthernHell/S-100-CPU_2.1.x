/**************************************************************************
File:               alarm_string.h
Author:             Lipovets
Creation date:      21/12/2009 - 18:29
POU name:           alarm_string
***************************************************************************/

#ifndef _ALARM_STRING_H /* nested Headers management */
#define _ALARM_STRING_H

/* function prototype */

void alarm_stringUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _ALARM_STRING_H */

/* eof ********************************************************************/

