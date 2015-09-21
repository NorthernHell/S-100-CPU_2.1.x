/**************************************************************************
File:               fda_alarm.h
Author:             Lipovets
Creation date:      21/12/2009 - 18:14
POU name:           
***************************************************************************/

#ifndef _FDA_ALARM_H /* nested Headers management */
#define _FDA_ALARM_H

/* include item definition */

#include "dios0def.h"
#include "alarm_ulint.h" /* "alarm_ulint */
#include "alarm_lint.h" /* "alarm_lint */
#include "alarm.h" /* "alarm */
#include "alarm_resend.h" /* "alarm_resend */
#include "alarm_lreal.h" /* "alarm_lreal */
#include "alarm_int.h" /* "alarm_int */
#include "alarm_udint.h" /* "alarm_udint */
#include "alarm_string.h" /* "alarm_string */
#include "alarm_send.h" /* "alarm_send */
#include "alarm_bool.h" /* "alarm_bool */
#include "alarm_uint.h" /* "alarm_uint */
#include "alarm_dint.h" /* "alarm_dint */
#include "alarm_usint.h" /* "alarm_usint */
#include "alarm_sint.h" /* "alarm_sint */
#include "alarm_time.h" /* "alarm_time */
#include "alarm_real.h" /* "alarm_real */
#include "alarm_date.h" /* "alarm_date */

/* package definition */

#define ISA_DECLARE_PACK_FDA_ALARM \
ISA_DECLARE_PACKNAME("fda_alarm") \
ISA_DECLARE_HANDLE("alarm_ulintUsfCall", alarm_ulintUsfCall) \
ISA_DECLARE_HANDLE("alarm_lintUsfCall", alarm_lintUsfCall) \
ISA_DECLARE_HANDLE("rtalarmIosInit", rtalarmIosInit) \
ISA_DECLARE_HANDLE("rtalarmIosExit", rtalarmIosExit) \
ISA_DECLARE_HANDLE("rtalarmalarmIosOpen", rtalarmalarmIosOpen) \
ISA_DECLARE_HANDLE("rtalarmalarmIosClose", rtalarmalarmIosClose) \
ISA_DECLARE_HANDLE("rtalarmalarmsendIosWrite", rtalarmalarmsendIosWrite) \
ISA_DECLARE_HANDLE("rtalarmalarmsendIosCtl", rtalarmalarmsendIosCtl) \
ISA_DECLARE_HANDLE("rtalarmalarmstatusIosRead", rtalarmalarmstatusIosRead) \
ISA_DECLARE_HANDLE("rtalarmalarmstatusIosCtl", rtalarmalarmstatusIosCtl) \
ISA_DECLARE_HANDLE("alarm_resendUsfCall", alarm_resendUsfCall) \
ISA_DECLARE_HANDLE("alarm_lrealUsfCall", alarm_lrealUsfCall) \
ISA_DECLARE_HANDLE("alarm_intUsfCall", alarm_intUsfCall) \
ISA_DECLARE_HANDLE("alarm_udintUsfCall", alarm_udintUsfCall) \
ISA_DECLARE_HANDLE("alarm_stringUsfCall", alarm_stringUsfCall) \
ISA_DECLARE_HANDLE("alarm_sendUsfCall", alarm_sendUsfCall) \
ISA_DECLARE_HANDLE("alarm_boolUsfCall", alarm_boolUsfCall) \
ISA_DECLARE_HANDLE("alarm_uintUsfCall", alarm_uintUsfCall) \
ISA_DECLARE_HANDLE("alarm_dintUsfCall", alarm_dintUsfCall) \
ISA_DECLARE_HANDLE("alarm_usintUsfCall", alarm_usintUsfCall) \
ISA_DECLARE_HANDLE("alarm_sintUsfCall", alarm_sintUsfCall) \
ISA_DECLARE_HANDLE("alarm_timeUsfCall", alarm_timeUsfCall) \
ISA_DECLARE_HANDLE("alarm_realUsfCall", alarm_realUsfCall) \
ISA_DECLARE_HANDLE("alarm_dateUsfCall", alarm_dateUsfCall) \
;

#endif /* _FDA_ALARM_H */

/* eof ********************************************************************/

