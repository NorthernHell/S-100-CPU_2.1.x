/**************************************************************************
File:               rt_log_name.h
Author:             Alexander
Creation date:      16/02/2006 - 15:07
POU name:           rt_log_name
***************************************************************************/

#ifndef _RT_LOG_NAME_H /* nested Headers management */
#define _RT_LOG_NAME_H

/* function prototype */

void rt_log_nameUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _RT_LOG_NAME_H */

/* eof ********************************************************************/

