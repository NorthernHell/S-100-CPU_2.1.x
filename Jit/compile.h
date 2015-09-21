/**************************************************************************
File:               compile.h
Author:             Alex
Creation date:      23/03/2007 - 19:27
POU name:           
***************************************************************************/

#ifndef _COMPILE_H /* nested Headers management */
#define _COMPILE_H

/* include item definition */

#include "dios0def.h"
#include "cprint_str.h" /* "cprint_str */
#include "compile_end.h" /* "compile_end */
#include "compile_begin.h" /* "compile_begin */

/* package definition */

#define ISA_DECLARE_COMPILE \
ISA_DECLARE_PACKNAME("compile") \
ISA_DECLARE_HANDLE("cprint_strUsfCall", cprint_strUsfCall) \
ISA_DECLARE_HANDLE("compile_endUsfCall", compile_endUsfCall) \
ISA_DECLARE_HANDLE("compile_beginUsfCall", compile_beginUsfCall) \
;

#endif /* _COMPILE_H */

/* eof ********************************************************************/

