/**************************************************************************
File:               sys_exec.h
Author:             alex
Creation date:      04/12/2008 - 15:22
POU name:           sys_exec
***************************************************************************/

#ifndef _SYS_EXEC_H /* nested Headers management */
#define _SYS_EXEC_H

/* function prototype */

void sys_execUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _SYS_EXEC_H */

/* eof ********************************************************************/

