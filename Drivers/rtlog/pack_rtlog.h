/**************************************************************************
File:               pk_rtlog.h
Author:             Alexander
Creation date:      17/08/2006 - 17:58
POU name:           
***************************************************************************/

#ifndef _PK_RTLOG_H /* nested Headers management */
#define _PK_RTLOG_H

/* include item definition */

#include "dios0def.h"
#include "rt_log.h" /* "rtlog */
#include "rt_log_name.h" /* "rt_log_name */
#include "rt_begin.h" /* "rt_begin */
#include "rt_all_by_type.h" /* "rt_all_by_type */
#include "rt_arr.h" /* "rt_arr */
#include "rt_var_ulint.h" /* "rt_var_ulint */
#include "rt_var_bool.h" /* "rt_var_bool */
#include "rt_var_uint.h" /* "rt_var_uint */
#include "rt_var_dint.h" /* "rt_var_dint */
#include "rt_var_lreal.h" /* "rt_var_lreal */
#include "rt_var_sint.h" /* "rt_var_sint */
#include "rt_var_time.h" /* "rt_var_time */
#include "rt_var_real.h" /* "rt_var_real */
#include "rt_var_int.h" /* "rt_var_int */
#include "rt_var_date.h" /* "rt_var_date */
#include "rt_var_udint.h" /* "rt_var_udint */
#include "rt_var_usint.h" /* "rt_var_usint */
#include "rt_var_lint.h" /* "rt_var_lint */

/* package definition */

#define ISA_DECLARE_PACK_RTLOG \
ISA_DECLARE_PACKNAME("pack_rtlog") \
ISA_DECLARE_HANDLE("rtlogsIosInit", rtlogsIosInit) \
ISA_DECLARE_HANDLE("rtlogsIosExit", rtlogsIosExit) \
ISA_DECLARE_HANDLE("rtlogsrtlogIosOpen", rtlogsrtlogIosOpen) \
ISA_DECLARE_HANDLE("rtlogsrtlogIosClose", rtlogsrtlogIosClose) \
ISA_DECLARE_HANDLE("rtlogsrtlogcontrolIosWrite", rtlogsrtlogcontrolIosWrite) \
ISA_DECLARE_HANDLE("rtlogsrtlogcontrolIosCtl", rtlogsrtlogcontrolIosCtl) \
ISA_DECLARE_HANDLE("rtlogsrtlogstateIosRead", rtlogsrtlogstateIosRead) \
ISA_DECLARE_HANDLE("rtlogsrtlogstateIosCtl", rtlogsrtlogstateIosCtl) \
ISA_DECLARE_HANDLE("rtlogsrtloginIosRead", rtlogsrtloginIosRead) \
ISA_DECLARE_HANDLE("rtlogsrtloginIosCtl", rtlogsrtloginIosCtl) \
ISA_DECLARE_HANDLE("rt_log_nameUsfCall", rt_log_nameUsfCall) \
ISA_DECLARE_HANDLE("rt_beginUsfCall", rt_beginUsfCall) \
ISA_DECLARE_HANDLE("rt_all_by_typeUsfCall", rt_all_by_typeUsfCall) \
ISA_DECLARE_HANDLE("rt_arrUsfCall", rt_arrUsfCall) \
ISA_DECLARE_HANDLE("rt_var_ulintUsfCall", rt_var_ulintUsfCall) \
ISA_DECLARE_HANDLE("rt_var_boolUsfCall", rt_var_boolUsfCall) \
ISA_DECLARE_HANDLE("rt_var_uintUsfCall", rt_var_uintUsfCall) \
ISA_DECLARE_HANDLE("rt_var_dintUsfCall", rt_var_dintUsfCall) \
ISA_DECLARE_HANDLE("rt_var_lrealUsfCall", rt_var_lrealUsfCall) \
ISA_DECLARE_HANDLE("rt_var_sintUsfCall", rt_var_sintUsfCall) \
ISA_DECLARE_HANDLE("rt_var_timeUsfCall", rt_var_timeUsfCall) \
ISA_DECLARE_HANDLE("rt_var_realUsfCall", rt_var_realUsfCall) \
ISA_DECLARE_HANDLE("rt_var_intUsfCall", rt_var_intUsfCall) \
ISA_DECLARE_HANDLE("rt_var_dateUsfCall", rt_var_dateUsfCall) \
ISA_DECLARE_HANDLE("rt_var_udintUsfCall", rt_var_udintUsfCall) \
ISA_DECLARE_HANDLE("rt_var_usintUsfCall", rt_var_usintUsfCall) \
ISA_DECLARE_HANDLE("rt_var_lintUsfCall", rt_var_lintUsfCall) \
;

#endif /* _PK_RTLOG_H */

/* eof ********************************************************************/

