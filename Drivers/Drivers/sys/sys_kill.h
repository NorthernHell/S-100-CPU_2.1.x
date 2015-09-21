/**************************************************************************
File:               sys_kill.h
Author:             alex
Creation date:      04/12/2008 - 15:22
POU name:           sys_kill
***************************************************************************/

#ifndef _SYS_KILL_H /* nested Headers management */
#define _SYS_KILL_H

/* function prototype */

void sys_killUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _SYS_KILL_H */

/* eof ********************************************************************/

