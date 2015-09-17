/**************************************************************************
File:               pktime.h
Author:             Lipovets
Creation date:      08/04/2008 - 20:04
POU name:           
***************************************************************************/

#ifndef _PK_TIME_H /* nested Headers management */
#define _PK_TIME_H

/* include item definition */
#include <dios0def.h>
#include "getcurrenttime.h" /* "getcurrtime */
#include "gethirestime.h" /* "gethirestime */

/* package definition */

#define ISA_DECLARE_PACK_TIME \
ISA_DECLARE_PACKNAME("pack_time") \
ISA_DECLARE_HANDLE("getcurrenttimeFblClassInit", getcurrenttimeFblClassInit) \
ISA_DECLARE_HANDLE("getcurrenttimeFblClassExit", getcurrenttimeFblClassExit) \
ISA_DECLARE_HANDLE("getcurrenttimeFblInstInit", getcurrenttimeFblInstInit) \
ISA_DECLARE_HANDLE("getcurrenttimeFblInstExit", getcurrenttimeFblInstExit) \
ISA_DECLARE_HANDLE("getcurrenttimeFblCall", getcurrenttimeFblCall) \
ISA_DECLARE_HANDLE("gethirestimeUsfCall", gethirestimeUsfCall) \
;

#endif /* _PACK_TIME_H */

/* eof ********************************************************************/

