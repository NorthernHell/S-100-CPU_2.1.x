/**************************************************************************
File:               pack_evro_int.h
Author:             umputun
Creation date:      21/07/2012 - 20:05
POU name:           
***************************************************************************/

#ifndef _PACK_EVRO_INT_H /* nested Headers management */
#define _PACK_EVRO_INT_H

/* include item definition */

#include "dios0def.h"
#include "evro_int_evro_int_evro_8di_.h" /* "evro_8di_ */
#include "evro_int_evro_int_status_m.h" /* "status_m */
#include "evro_int_evro_int_evro_8ai_.h" /* "evro_8ai_ */
#include "evro_int_evro_int_evro_8dir.h" /* "evro_8dir */
#include "evro_int_evro_int_evro_8do_.h" /* "evro_8do_ */
#include "evro_int_evro_int_evro_8ao.h" /* "evro_8ao */
#include "evro_int_evro_int_evro_8ai.h" /* "evro_8ai */
#include "evro_int_evro_int_evro_8ao_.h" /* "evro_8ao_ */
#include "evro_int_evro_int_evro_8do.h" /* "evro_8do */
#include "evro_int_evro_int_evro_8di.h" /* "evro_8di */

#include "evro_int_evro_int_evro_16di_.h" /* "evro_16di_ */
#include "evro_int_evro_int_evro_16di.h" /* "evro_16di */
#include "evro_int_evro_int_evro_16dir.h" /* "evro_16dir */

/* package definition */

#define ISA_DECLARE_PACK_EVRO_INT \
ISA_DECLARE_PACKNAME("pack_evro_int") \
ISA_DECLARE_HANDLE("evro_int_evro_int_IosInit", evro_int_evro_int_IosInit) \
ISA_DECLARE_HANDLE("evro_int_evro_int_IosExit", evro_int_evro_int_IosExit) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8di_IosOpen", evro_int_evro_int_evro_8di_IosOpen) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8di_IosClose", evro_int_evro_int_evro_8di_IosClose) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8di_evro_8diIosRead", evro_int_evro_int_evro_8di_evro_8diIosRead) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8di_evro_8diIosCtl", evro_int_evro_int_evro_8di_evro_8diIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8di_evro_8dirIosRead", evro_int_evro_int_evro_8di_evro_8dirIosRead) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8di_evro_8dirIosCtl", evro_int_evro_int_evro_8di_evro_8dirIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8di_status_mIosRead", evro_int_evro_int_evro_8di_status_mIosRead) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8di_status_mIosCtl", evro_int_evro_int_evro_8di_status_mIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_16di_IosOpen", evro_int_evro_int_evro_16di_IosOpen) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_16di_IosClose", evro_int_evro_int_evro_16di_IosClose) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_16di_evro_16diIosRead", evro_int_evro_int_evro_16di_evro_16diIosRead) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_16di_evro_16diIosCtl", evro_int_evro_int_evro_16di_evro_16diIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_16di_evro_16dirIosRead", evro_int_evro_int_evro_16di_evro_16dirIosRead) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_16di_evro_16dirIosCtl", evro_int_evro_int_evro_16di_evro_16dirIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_16di_status_mIosRead", evro_int_evro_int_evro_16di_status_mIosRead) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_16di_status_mIosCtl", evro_int_evro_int_evro_16di_status_mIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_status_mIosOpen", evro_int_evro_int_status_mIosOpen) \
ISA_DECLARE_HANDLE("evro_int_evro_int_status_mIosClose", evro_int_evro_int_status_mIosClose) \
ISA_DECLARE_HANDLE("evro_int_evro_int_status_mIosRead", evro_int_evro_int_status_mIosRead) \
ISA_DECLARE_HANDLE("evro_int_evro_int_status_mIosCtl", evro_int_evro_int_status_mIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8ai_IosOpen", evro_int_evro_int_evro_8ai_IosOpen) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8ai_IosClose", evro_int_evro_int_evro_8ai_IosClose) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8ai_evro_8aiIosRead", evro_int_evro_int_evro_8ai_evro_8aiIosRead) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8ai_evro_8aiIosCtl", evro_int_evro_int_evro_8ai_evro_8aiIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8ai_status_mIosRead", evro_int_evro_int_evro_8ai_status_mIosRead) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8ai_status_mIosCtl", evro_int_evro_int_evro_8ai_status_mIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8dirIosOpen", evro_int_evro_int_evro_8dirIosOpen) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8dirIosClose", evro_int_evro_int_evro_8dirIosClose) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8dirIosRead", evro_int_evro_int_evro_8dirIosRead) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8dirIosCtl", evro_int_evro_int_evro_8dirIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_16dirIosOpen", evro_int_evro_int_evro_16dirIosOpen) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_16dirIosClose", evro_int_evro_int_evro_16dirIosClose) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_16dirIosRead", evro_int_evro_int_evro_16dirIosRead) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_16dirIosCtl", evro_int_evro_int_evro_16dirIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8do_IosOpen", evro_int_evro_int_evro_8do_IosOpen) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8do_IosClose", evro_int_evro_int_evro_8do_IosClose) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8do_evro_8doIosWrite", evro_int_evro_int_evro_8do_evro_8doIosWrite) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8do_evro_8doIosCtl", evro_int_evro_int_evro_8do_evro_8doIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8do_status_mIosRead", evro_int_evro_int_evro_8do_status_mIosRead) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8do_status_mIosCtl", evro_int_evro_int_evro_8do_status_mIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8aoIosOpen", evro_int_evro_int_evro_8aoIosOpen) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8aoIosClose", evro_int_evro_int_evro_8aoIosClose) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8aoIosWrite", evro_int_evro_int_evro_8aoIosWrite) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8aoIosCtl", evro_int_evro_int_evro_8aoIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8aiIosOpen", evro_int_evro_int_evro_8aiIosOpen) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8aiIosClose", evro_int_evro_int_evro_8aiIosClose) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8aiIosRead", evro_int_evro_int_evro_8aiIosRead) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8aiIosCtl", evro_int_evro_int_evro_8aiIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8ao_IosOpen", evro_int_evro_int_evro_8ao_IosOpen) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8ao_IosClose", evro_int_evro_int_evro_8ao_IosClose) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8ao_evro_8aoIosWrite", evro_int_evro_int_evro_8ao_evro_8aoIosWrite) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8ao_evro_8aoIosCtl", evro_int_evro_int_evro_8ao_evro_8aoIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8ao_status_mIosRead", evro_int_evro_int_evro_8ao_status_mIosRead) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8ao_status_mIosCtl", evro_int_evro_int_evro_8ao_status_mIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8doIosOpen", evro_int_evro_int_evro_8doIosOpen) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8doIosClose", evro_int_evro_int_evro_8doIosClose) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8doIosWrite", evro_int_evro_int_evro_8doIosWrite) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8doIosCtl", evro_int_evro_int_evro_8doIosCtl) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8diIosOpen", evro_int_evro_int_evro_8diIosOpen) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8diIosClose", evro_int_evro_int_evro_8diIosClose) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8diIosRead", evro_int_evro_int_evro_8diIosRead) \
ISA_DECLARE_HANDLE("evro_int_evro_int_evro_8diIosCtl", evro_int_evro_int_evro_8diIosCtl) \
;

#endif /* _PACK_EVRO_INT_H */

/* eof ********************************************************************/

