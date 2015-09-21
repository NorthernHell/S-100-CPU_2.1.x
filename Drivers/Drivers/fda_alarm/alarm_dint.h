/**************************************************************************
File:               alarm_dint.h
Author:             Lipovets
Creation date:      21/12/2009 - 18:29
POU name:           alarm_dint
***************************************************************************/

#ifndef _ALARM_DINT_H /* nested Headers management */
#define _ALARM_DINT_H

/* function prototype */

void alarm_dintUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _ALARM_DINT_H */

/* eof ********************************************************************/

