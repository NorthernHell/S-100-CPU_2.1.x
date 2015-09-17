/**************************************************************************
File:               isandt_package.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      05/06/2009 - 11:21
***************************************************************************
Attached documents: 

***************************************************************************
Description:			Package identification

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/
#ifndef _ISANDT_PACKAGE_H /* nested Headers management */
#define _ISANDT_PACKAGE_H

/* include item definition */

#include "and_mask_byte.h"
#include "not_mask_byte.h"
#include "or_mask_byte.h"
#include "rol_byte.h"
#include "ror_byte.h"
#include "shl_byte.h"
#include "shr_byte.h"
#include "xor_mask_byte.h"

#include "and_mask_word.h"
#include "not_mask_word.h"
#include "or_mask_word.h"
#include "rol_word.h"
#include "ror_word.h"
#include "shl_word.h"
#include "shr_word.h"
#include "xor_mask_word.h"

#include "and_mask_dword.h"
#include "not_mask_dword.h"
#include "or_mask_dword.h"
#include "rol_dword.h"
#include "ror_dword.h"
#include "shl_dword.h"
#include "shr_dword.h"
#include "xor_mask_dword.h"

#include "abs_lreal.h"
#include "acos_lreal.h"
#include "asin_lreal.h"
#include "atan_lreal.h"
#include "cos_lreal.h"
#include "expt_lreal.h"
#include "log_lreal.h"
#include "pow_lreal.h"
#include "sin_lreal.h"
#include "sqrt_lreal.h"
#include "tan_lreal.h"
#include "trunc_lreal.h"

#include "and_mask_lword.h" 
#include "rol_lword.h" 
#include "xor_mask_lword.h"
#include "or_mask_lword.h" 
#include "ror_lword.h" 
#include "shl_lword.h"
#include "not_mask_lword.h"
#include "shr_lword.h" 

/* package definition */

#define ISA_DECLARE_PACK_NEWTYPE                                    \
ISA_DECLARE_PACKNAME("isandt_package")                                \
ISA_DECLARE_HANDLE("and_mask_byteUsfCall",    and_mask_byteUsfCall)   \
ISA_DECLARE_HANDLE("not_mask_byteUsfCall",    not_mask_byteUsfCall)   \
ISA_DECLARE_HANDLE("or_mask_byteUsfCall",     or_mask_byteUsfCall)    \
ISA_DECLARE_HANDLE("rol_byteUsfCall",         rol_byteUsfCall)        \
ISA_DECLARE_HANDLE("ror_byteUsfCall",         ror_byteUsfCall)        \
ISA_DECLARE_HANDLE("shl_byteUsfCall",         shl_byteUsfCall)        \
ISA_DECLARE_HANDLE("shr_byteUsfCall",         shr_byteUsfCall)        \
ISA_DECLARE_HANDLE("xor_mask_byteUsfCall",    xor_mask_byteUsfCall)   \
ISA_DECLARE_HANDLE("and_mask_wordUsfCall",    and_mask_wordUsfCall)   \
ISA_DECLARE_HANDLE("not_mask_wordUsfCall",    not_mask_wordUsfCall)   \
ISA_DECLARE_HANDLE("or_mask_wordUsfCall",     or_mask_wordUsfCall)    \
ISA_DECLARE_HANDLE("rol_wordUsfCall",         rol_wordUsfCall)        \
ISA_DECLARE_HANDLE("ror_wordUsfCall",         ror_wordUsfCall)        \
ISA_DECLARE_HANDLE("shl_wordUsfCall",         shl_wordUsfCall)        \
ISA_DECLARE_HANDLE("shr_wordUsfCall",         shr_wordUsfCall)        \
ISA_DECLARE_HANDLE("xor_mask_wordUsfCall",    xor_mask_wordUsfCall)   \
ISA_DECLARE_HANDLE("and_mask_dwordUsfCall",   and_mask_dwordUsfCall)  \
ISA_DECLARE_HANDLE("not_mask_dwordUsfCall",   not_mask_dwordUsfCall)  \
ISA_DECLARE_HANDLE("or_mask_dwordUsfCall",    or_mask_dwordUsfCall)   \
ISA_DECLARE_HANDLE("rol_dwordUsfCall",        rol_dwordUsfCall)       \
ISA_DECLARE_HANDLE("ror_dwordUsfCall",        ror_dwordUsfCall)       \
ISA_DECLARE_HANDLE("shl_dwordUsfCall",        shl_dwordUsfCall)       \
ISA_DECLARE_HANDLE("shr_dwordUsfCall",        shr_dwordUsfCall)       \
ISA_DECLARE_HANDLE("xor_mask_dwordUsfCall",   xor_mask_dwordUsfCall)  \
ISA_DECLARE_HANDLE("abs_lrealUsfCall",        abs_lrealUsfCall)       \
ISA_DECLARE_HANDLE("acos_lrealUsfCall",       acos_lrealUsfCall)      \
ISA_DECLARE_HANDLE("asin_lrealUsfCall",       asin_lrealUsfCall)      \
ISA_DECLARE_HANDLE("atan_lrealUsfCall",       atan_lrealUsfCall)      \
ISA_DECLARE_HANDLE("cos_lrealUsfCall",        cos_lrealUsfCall)       \
ISA_DECLARE_HANDLE("expt_lrealUsfCall",       expt_lrealUsfCall)      \
ISA_DECLARE_HANDLE("log_lrealUsfCall",        log_lrealUsfCall)       \
ISA_DECLARE_HANDLE("pow_lrealUsfCall",        pow_lrealUsfCall)       \
ISA_DECLARE_HANDLE("sin_lrealUsfCall",        sin_lrealUsfCall)       \
ISA_DECLARE_HANDLE("sqrt_lrealUsfCall",       sqrt_lrealUsfCall)      \
ISA_DECLARE_HANDLE("tan_lrealUsfCall",        tan_lrealUsfCall)       \
ISA_DECLARE_HANDLE("trunc_lrealUsfCall",      trunc_lrealUsfCall)     \
ISA_DECLARE_HANDLE("and_mask_lwordUsfCall",   and_mask_lwordUsfCall)  \
ISA_DECLARE_HANDLE("rol_lwordUsfCall",        rol_lwordUsfCall)       \
ISA_DECLARE_HANDLE("xor_mask_lwordUsfCall",   xor_mask_lwordUsfCall)  \
ISA_DECLARE_HANDLE("or_mask_lwordUsfCall",    or_mask_lwordUsfCall)   \
ISA_DECLARE_HANDLE("ror_lwordUsfCall",        ror_lwordUsfCall)       \
ISA_DECLARE_HANDLE("shl_lwordUsfCall",        shl_lwordUsfCall)       \
ISA_DECLARE_HANDLE("not_mask_lwordUsfCall",   not_mask_lwordUsfCall)  \
ISA_DECLARE_HANDLE("shr_lwordUsfCall",        shr_lwordUsfCall)


#endif /* _ISANDT_PACKAGE_H */

/* eof ********************************************************************/

