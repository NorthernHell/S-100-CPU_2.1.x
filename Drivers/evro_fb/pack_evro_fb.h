/**************************************************************************
File:               pack_evro_fb.h
Author:             automaten
Creation date:      06/06/2016 - 20:35
POU name:           
***************************************************************************/

#ifndef _PACK_EVRO_FB_H /* nested Headers management */
#define _PACK_EVRO_FB_H

/* include item definition */

#include "pid_evro.h" /* "pid_evro */

/* package definition */

#define ISA_DECLARE_PACK_EVRO_FB \
ISA_DECLARE_PACKNAME("pack_evro_fb") \
ISA_DECLARE_HANDLE("pid_evroFblClassInit", pid_evroFblClassInit) \
ISA_DECLARE_HANDLE("pid_evroFblClassExit", pid_evroFblClassExit) \
ISA_DECLARE_HANDLE("pid_evroFblInstInit", pid_evroFblInstInit) \
ISA_DECLARE_HANDLE("pid_evroFblInstExit", pid_evroFblInstExit) \
ISA_DECLARE_HANDLE("pid_evroFblCall", pid_evroFblCall) \
;

#endif /* _PACK_EVRO_FB_H */

/* eof ********************************************************************/

