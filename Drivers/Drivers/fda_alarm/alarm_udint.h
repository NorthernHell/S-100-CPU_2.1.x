/**************************************************************************
File:               alarm_udint.h
Author:             Lipovets
Creation date:      21/12/2009 - 18:29
POU name:           alarm_udint
***************************************************************************/

#ifndef _ALARM_UDINT_H /* nested Headers management */
#define _ALARM_UDINT_H

/* function prototype */

void alarm_udintUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _ALARM_UDINT_H */

/* eof ********************************************************************/

