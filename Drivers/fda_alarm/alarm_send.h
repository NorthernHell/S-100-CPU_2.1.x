/**************************************************************************
File:               alarm_send.h
Author:             Alexander
Creation date:      25/07/2007 - 13:04
POU name:           alarm_send
***************************************************************************/

#ifndef _ALARM_SEND_H /* nested Headers management */
#define _ALARM_SEND_H

/* function prototype */

void alarm_sendUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _ALARM_SEND_H */

/* eof ********************************************************************/

