/**************************************************************************
File:               rtpack.h
Author:             Alex
Creation date:      14/09/2006 - 20:03
POU name:
***************************************************************************/

#ifndef _PK_RTSCHED_H /* nested Headers management */
#define _PK_RTSCHED_H

/* include item definition */

#include "dios0def.h"
#include "rtsched.h" /* "rtsched */

/* package definition */

#define ISA_DECLARE_PACK_RTSCHED \
ISA_DECLARE_PACKNAME("pack_rtsched") \
ISA_DECLARE_HANDLE("realtimeschedIosInit", realtimeschedIosInit) \
ISA_DECLARE_HANDLE("realtimeschedIosExit", realtimeschedIosExit) \
ISA_DECLARE_HANDLE("realtimeschedrtschedIosOpen", realtimeschedrtschedIosOpen) \
ISA_DECLARE_HANDLE("realtimeschedrtschedIosClose", realtimeschedrtschedIosClose) \
ISA_DECLARE_HANDLE("realtimeschedrtschedIosRead", realtimeschedrtschedIosRead) \
ISA_DECLARE_HANDLE("realtimeschedrtschedIosCtl", realtimeschedrtschedIosCtl) \
;

#endif /* _PK_RTSCHED_H */

/* eof ********************************************************************/

