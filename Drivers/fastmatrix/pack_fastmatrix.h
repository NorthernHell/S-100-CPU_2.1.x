/**************************************************************************
File:               fastmatrix.h
Author:             Alex
Creation date:      29/10/2006 - 00:09
POU name:           
***************************************************************************/

#ifndef _PK_FASTMATRIX_H /* nested Headers management */
#define _PK_FASTMATRIX_H

/* include item definition */

#include "dios0def.h"
#include "fast_matrix_fill.h" /* "fast_matrix_fill */
#include "fast_matrix_copy.h" /* "fast_matrix_copy */
#include "fast_matrix_on_vec.h" /* "fast_matrix_on_vec */
#include "fast_matrix_zeroes.h" /* "fast_matrix_zeroes */
#include "fast_matrix_scale.h" /* "fast_matrix_scale */
#include "fast_matrix_add.h" /* "fast_matrix_add */
#include "fast_matrix_create.h" /* "fast_matrix_create */
#include "fast_matrix_linsolve.h" /* "fast_matrix_create */


/* package definition */

#define ISA_DECLARE_PACK_FASTMATRIX \
ISA_DECLARE_PACKNAME("pack_fastmatrix") \
ISA_DECLARE_HANDLE("fast_matrix_fillUsfCall", fast_matrix_fillUsfCall) \
ISA_DECLARE_HANDLE("fast_matrix_copyUsfCall", fast_matrix_copyUsfCall) \
ISA_DECLARE_HANDLE("fast_matrix_on_vecUsfCall", fast_matrix_on_vecUsfCall) \
ISA_DECLARE_HANDLE("fast_matrix_zeroesUsfCall", fast_matrix_zeroesUsfCall) \
ISA_DECLARE_HANDLE("fast_matrix_scaleUsfCall", fast_matrix_scaleUsfCall) \
ISA_DECLARE_HANDLE("fast_matrix_addUsfCall", fast_matrix_addUsfCall) \
ISA_DECLARE_HANDLE("fast_matrix_createUsfCall", fast_matrix_createUsfCall) \
ISA_DECLARE_HANDLE("fast_matrix_linsolveUsfCall", fast_matrix_linsolveUsfCall) \
;

#endif /* _PK_FASTMATRIX_H */

/* eof ********************************************************************/
