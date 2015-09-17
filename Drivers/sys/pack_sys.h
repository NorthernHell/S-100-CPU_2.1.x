/**************************************************************************
File:               pack_sys.h
Author:             alex
Creation date:      04/12/2008 - 15:21
POU name:           
***************************************************************************/

#ifndef _PACK_SYS_H /* nested Headers management */
#define _PACK_SYS_H

/* include item definition */

#include "dios0def.h"
#include "sys_kill.h" /* "sys_kill */
#include "sys_exec.h" /* "sys_exec */

/* package definition */

#define ISA_DECLARE_PACK_SYS \
ISA_DECLARE_PACKNAME("pack_sys") \
ISA_DECLARE_HANDLE("sys_killUsfCall", sys_killUsfCall) \
ISA_DECLARE_HANDLE("sys_execUsfCall", sys_execUsfCall) \
;

#endif /* _PACK_SYS_H */

/* eof ********************************************************************/

