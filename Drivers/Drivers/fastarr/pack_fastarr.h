/**************************************************************************
File:               pack_fastarr.h
Author:             Alex
Creation date:      01/10/2006 - 23:47
POU name:           
***************************************************************************/

#ifndef _PACK_FASTARR_H /* nested Headers management */
#define _PACK_FASTARR_H

/* include item definition */

#include "dios0def.h"
#include "fastlibinit.h"

#include "fast_array_range.h" /* "fast_array_range */
#include "fast_array_dot.h" /* "fast_array_dot */
#include "fast_array_create.h" /* "fast_array_create */
#include "fast_array_add.h" /* "fast_array_add */
#include "fast_array_cumulsum.h" /* "fast_array_cumulsum */
#include "fast_array_mul.h" /* "fast_array_mul */
#include "fast_array_zeroes.h" /* "fast_array_zeroes */
#include "fast_array_fill.h" /* "fast_array_fill */
#include "fast_array_copy.h" /* "fast_array_copy */
#include "fast_array_scale.h" /* "fast_array_scale */
#include "fast_array_max.h" /* "fast_array_max */
#include "fast_array_min.h" /* "fast_array_min */
#include "fast_array_spectrum.h" /* "fast_array_spectrum */

/* package definition */

#define ISA_DECLARE_PACK_FASTARR \
ISA_DECLARE_PACKNAME("pack_fastarr") \
ISA_DECLARE_HANDLE("fastlibinitUsfCall",fastlibinitUsfCall)\
ISA_DECLARE_HANDLE("fast_array_rangeUsfCall", fast_array_rangeUsfCall) \
ISA_DECLARE_HANDLE("fast_array_dotUsfCall", fast_array_dotUsfCall) \
ISA_DECLARE_HANDLE("fast_array_createUsfCall", fast_array_createUsfCall) \
ISA_DECLARE_HANDLE("fast_array_addUsfCall", fast_array_addUsfCall) \
ISA_DECLARE_HANDLE("fast_array_cumulsumUsfCall", fast_array_cumulsumUsfCall) \
ISA_DECLARE_HANDLE("fast_array_mulUsfCall", fast_array_mulUsfCall) \
ISA_DECLARE_HANDLE("fast_array_zeroesUsfCall", fast_array_zeroesUsfCall) \
ISA_DECLARE_HANDLE("fast_array_fillUsfCall", fast_array_fillUsfCall) \
ISA_DECLARE_HANDLE("fast_array_copyUsfCall", fast_array_copyUsfCall) \
ISA_DECLARE_HANDLE("fast_array_scaleUsfCall", fast_array_scaleUsfCall) \
ISA_DECLARE_HANDLE("fast_array_maxUsfCall",fast_array_maxUsfCall)\
ISA_DECLARE_HANDLE("fast_array_minUsfCall",fast_array_minUsfCall)\
ISA_DECLARE_HANDLE("fast_array_spectrumUsfCall",fast_array_spectrumUsfCall)\
;

#endif /* _PACK_FASTARR_H */

/* eof ********************************************************************/

