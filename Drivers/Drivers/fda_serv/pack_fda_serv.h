/**************************************************************************
File:               pk_fdaserv.h
Author:             Lipovets
Creation date:      15/10/2007 - 16:17
POU name:           
***************************************************************************/

#ifndef _PK_FDA_SERV_H /* nested Headers management */
#define _PK_FDASERV_H

/* include item definition */

#include "dios0def.h"
#include "fdadev.h" /* "fda_serv */

/* package definition */

#define ISA_DECLARE_PACK_FDA_SERV \
ISA_DECLARE_PACKNAME("pack_fda_serv") \
ISA_DECLARE_HANDLE("rtservIosInit", rtservIosInit) \
ISA_DECLARE_HANDLE("rtservIosExit", rtservIosExit) \
ISA_DECLARE_HANDLE("rtservfda_servIosOpen", rtservfda_servIosOpen) \
ISA_DECLARE_HANDLE("rtservfda_servIosClose", rtservfda_servIosClose) \
;

#endif /* _PK_FDA_SERV_H */

/* eof ********************************************************************/

