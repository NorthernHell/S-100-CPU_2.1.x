/**************************************************************************
File:               isetpack.h
Author:             Lipovets
Creation date:      24/01/2008 - 19:45
POU name:           
***************************************************************************/

#ifndef _PK_ISET_H /* nested Headers management */
#define _PK_ISET_H

/* include item definition */

#include "setread.h" /* "setread */
#include "setsave.h" /* "setsave */
#include "setregname.h" /* "setregname */

/* package definition */

#define ISA_DECLARE_PACK_ISET \
ISA_DECLARE_PACKNAME("pack_iset") \
ISA_DECLARE_HANDLE("setreadUsfCall", setreadUsfCall) \
ISA_DECLARE_HANDLE("setsaveUsfCall", setsaveUsfCall) \
ISA_DECLARE_HANDLE("setregnameUsfCall", setregnameUsfCall) \
;

#endif /* _PK_ISET_H */

/* eof ********************************************************************/

