/**************************************************************************
File:               firpack.h
Author:             root
Creation date:      16/10/2007 - 11:09
POU name:           
***************************************************************************/

#ifndef _PK_FIR_H /* nested Headers management */
#define _PK_FIR_H

/* include item definition */

#include "dios0def.h"
#include "firf.h" /* "firf */
#include "fir_create.h" /* "fir_create */
#include "fir.h" /* "fir */
#include "fir_vector.h"

/* package definition */

#define ISA_DECLARE_PACK_FIR \
ISA_DECLARE_PACKNAME("pack_fir") \
ISA_DECLARE_HANDLE("firfUsfCall", firfUsfCall) \
ISA_DECLARE_HANDLE("fir_createUsfCall", fir_createUsfCall) \
ISA_DECLARE_HANDLE("firUsfCall", firUsfCall) \
ISA_DECLARE_HANDLE("fir_vectorUsfCall", fir_vectorUsfCall) \
;

#endif /* _PACK_FIR_H */

/* eof ********************************************************************/

