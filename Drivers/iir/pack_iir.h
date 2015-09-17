/**************************************************************************
File:               iirpack.h
Author:             root
Creation date:      17/10/2007 - 17:44
POU name:           
***************************************************************************/

#ifndef _PK_IIR_H /* nested Headers management */
#define _PK_IIR_H

/* include item definition */

#include "dios0def.h"
#include "iirf.h" /* "iirf */
#include "iir_create.h" /* "iir_create */
#include "iir.h" /* "iir */
#include "iir_vector.h"

/* package definition */

#define ISA_DECLARE_PACK_IIR \
ISA_DECLARE_PACKNAME("pack_iir") \
ISA_DECLARE_HANDLE("iirfUsfCall", iirfUsfCall) \
ISA_DECLARE_HANDLE("iir_createUsfCall", iir_createUsfCall) \
ISA_DECLARE_HANDLE("iirUsfCall", iirUsfCall) \
ISA_DECLARE_HANDLE("iir_vectorUsfCall", iir_vectorUsfCall) \
;

#endif /* _IIRPACK_H */

/* eof ********************************************************************/

