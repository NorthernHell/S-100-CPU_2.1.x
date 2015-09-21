/**************************************************************************
File:               alarm_sint.h
Author:             Lipovets
Creation date:      21/12/2009 - 18:29
POU name:           alarm_sint
***************************************************************************/

#ifndef _ALARM_SINT_H /* nested Headers management */
#define _ALARM_SINT_H

/* function prototype */

void alarm_sintUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _ALARM_SINT_H */

/* eof ********************************************************************/

