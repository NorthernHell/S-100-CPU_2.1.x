/**************************************************************************
File:               alarm_resend.h
Author:             Alexander
Creation date:      25/07/2007 - 13:04
POU name:           alarm_resend
***************************************************************************/

#ifndef _ALARM_RESEND_H /* nested Headers management */
#define _ALARM_RESEND_H

/* function prototype */

void alarm_resendUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _ALARM_RESEND_H */

/* eof ********************************************************************/

