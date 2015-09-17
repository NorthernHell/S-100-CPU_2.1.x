/**************************************************************************
File:               pack_evro_ext.h
Author:             Umputun
Creation date:      19/07/2012 - 12:59
POU name:           
***************************************************************************/

#ifndef _PACK_EVRO_EXT_H /* nested Headers management */
#define _PACK_EVRO_EXT_H

/* include item definition */

#include "dios0def.h"
#include "evro_ext_evro_ext_modbus_ai.h" /* "modbus_ai */
#include "evro_ext_evro_ext_io8_tcs.h" /* "io8_tcs */
#include "evro_ext_evro_ext_modbus_do.h" /* "modbus_do */
#include "evro_ext_evro_ext_io8tcs.h" /* "io8tcs */
#include "evro_ext_evro_ext_modbus_di.h" /* "modbus_di */
#include "evro_ext_evro_ext_io8aii.h" /* "io8aii */
#include "evro_ext_evro_ext_io16do.h" /* "io16do */
#include "evro_ext_evro_ext_m_ao.h" /* "m_ao */
#include "evro_ext_evro_ext_m_ai.h" /* "m_ai */
#include "evro_ext_evro_ext_io16di.h" /* "io16di */
#include "evro_ext_evro_ext_io_8aii.h" /* "io_8aii */
#include "evro_ext_evro_ext_io_8ao.h" /* "io_8ao */
#include "evro_ext_evro_ext_io_16do.h" /* "io_16do */
#include "evro_ext_evro_ext_io_16di.h" /* "io_16di */
#include "evro_ext_evro_ext_m_do.h" /* "m_do */
#include "evro_ext_evro_ext_m_di.h" /* "m_di */
#include "evro_ext_evro_ext_io8ao.h" /* "io8ao */
#include "evro_ext_evro_ext_io_4ro.h" /* "io_4ro */
#include "evro_ext_evro_ext_io4ro.h" /* "io4ro */
#include "evro_ext_evro_ext_modbusstatus.h" /* "modbusstatus */
#include "evro_ext_evro_ext_modbus_ao.h" /* "modbus_ao */

/* package definition */

#define ISA_DECLARE_PACK_EVRO_EXT \
ISA_DECLARE_PACKNAME("pack_evro_ext") \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_IosInit", evro_ext_evro_ext_IosInit) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_IosExit", evro_ext_evro_ext_IosExit) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_aiIosOpen", evro_ext_evro_ext_modbus_aiIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_aiIosClose", evro_ext_evro_ext_modbus_aiIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_aim_aiIosRead", evro_ext_evro_ext_modbus_aim_aiIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_aim_aiIosCtl", evro_ext_evro_ext_modbus_aim_aiIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_aimodbusstatusIosRead", evro_ext_evro_ext_modbus_aimodbusstatusIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_aimodbusstatusIosCtl", evro_ext_evro_ext_modbus_aimodbusstatusIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8_tcsIosOpen", evro_ext_evro_ext_io8_tcsIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8_tcsIosClose", evro_ext_evro_ext_io8_tcsIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8_tcsio8tcsIosRead", evro_ext_evro_ext_io8_tcsio8tcsIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8_tcsio8tcsIosCtl", evro_ext_evro_ext_io8_tcsio8tcsIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8_tcsmodbusstatusIosRead", evro_ext_evro_ext_io8_tcsmodbusstatusIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8_tcsmodbusstatusIosCtl", evro_ext_evro_ext_io8_tcsmodbusstatusIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_doIosOpen", evro_ext_evro_ext_modbus_doIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_doIosClose", evro_ext_evro_ext_modbus_doIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_dom_doIosWrite", evro_ext_evro_ext_modbus_dom_doIosWrite) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_dom_doIosCtl", evro_ext_evro_ext_modbus_dom_doIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_domodbusstatusIosRead", evro_ext_evro_ext_modbus_domodbusstatusIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_domodbusstatusIosCtl", evro_ext_evro_ext_modbus_domodbusstatusIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8tcsIosOpen", evro_ext_evro_ext_io8tcsIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8tcsIosClose", evro_ext_evro_ext_io8tcsIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8tcsIosRead", evro_ext_evro_ext_io8tcsIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8tcsIosCtl", evro_ext_evro_ext_io8tcsIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_diIosOpen", evro_ext_evro_ext_modbus_diIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_diIosClose", evro_ext_evro_ext_modbus_diIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_dim_diIosRead", evro_ext_evro_ext_modbus_dim_diIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_dim_diIosCtl", evro_ext_evro_ext_modbus_dim_diIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_dimodbusstatusIosRead", evro_ext_evro_ext_modbus_dimodbusstatusIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_dimodbusstatusIosCtl", evro_ext_evro_ext_modbus_dimodbusstatusIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8aiiIosOpen", evro_ext_evro_ext_io8aiiIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8aiiIosClose", evro_ext_evro_ext_io8aiiIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8aiiIosRead", evro_ext_evro_ext_io8aiiIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8aiiIosCtl", evro_ext_evro_ext_io8aiiIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io16doIosOpen", evro_ext_evro_ext_io16doIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io16doIosClose", evro_ext_evro_ext_io16doIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io16doIosWrite", evro_ext_evro_ext_io16doIosWrite) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io16doIosCtl", evro_ext_evro_ext_io16doIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_aoIosOpen", evro_ext_evro_ext_m_aoIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_aoIosClose", evro_ext_evro_ext_m_aoIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_aoIosWrite", evro_ext_evro_ext_m_aoIosWrite) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_aoIosCtl", evro_ext_evro_ext_m_aoIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_aiIosOpen", evro_ext_evro_ext_m_aiIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_aiIosClose", evro_ext_evro_ext_m_aiIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_aiIosRead", evro_ext_evro_ext_m_aiIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_aiIosCtl", evro_ext_evro_ext_m_aiIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io16diIosOpen", evro_ext_evro_ext_io16diIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io16diIosClose", evro_ext_evro_ext_io16diIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io16diIosRead", evro_ext_evro_ext_io16diIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io16diIosCtl", evro_ext_evro_ext_io16diIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_8aiiIosOpen", evro_ext_evro_ext_io_8aiiIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_8aiiIosClose", evro_ext_evro_ext_io_8aiiIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_8aiiio8aiiIosRead", evro_ext_evro_ext_io_8aiiio8aiiIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_8aiiio8aiiIosCtl", evro_ext_evro_ext_io_8aiiio8aiiIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_8aiimodbusstatusIosRead", evro_ext_evro_ext_io_8aiimodbusstatusIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_8aiimodbusstatusIosCtl", evro_ext_evro_ext_io_8aiimodbusstatusIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_8aoIosOpen", evro_ext_evro_ext_io_8aoIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_8aoIosClose", evro_ext_evro_ext_io_8aoIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_8aoio8aoIosWrite", evro_ext_evro_ext_io_8aoio8aoIosWrite) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_8aoio8aoIosCtl", evro_ext_evro_ext_io_8aoio8aoIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_8aomodbusstatusIosRead", evro_ext_evro_ext_io_8aomodbusstatusIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_8aomodbusstatusIosCtl", evro_ext_evro_ext_io_8aomodbusstatusIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_16doIosOpen", evro_ext_evro_ext_io_16doIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_16doIosClose", evro_ext_evro_ext_io_16doIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_16doio16doIosWrite", evro_ext_evro_ext_io_16doio16doIosWrite) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_16doio16doIosCtl", evro_ext_evro_ext_io_16doio16doIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_16domodbusstatusIosRead", evro_ext_evro_ext_io_16domodbusstatusIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_16domodbusstatusIosCtl", evro_ext_evro_ext_io_16domodbusstatusIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_16diIosOpen", evro_ext_evro_ext_io_16diIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_16diIosClose", evro_ext_evro_ext_io_16diIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_16diio16diIosRead", evro_ext_evro_ext_io_16diio16diIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_16diio16diIosCtl", evro_ext_evro_ext_io_16diio16diIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_16dimodbusstatusIosRead", evro_ext_evro_ext_io_16dimodbusstatusIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_16dimodbusstatusIosCtl", evro_ext_evro_ext_io_16dimodbusstatusIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_doIosOpen", evro_ext_evro_ext_m_doIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_doIosClose", evro_ext_evro_ext_m_doIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_doIosWrite", evro_ext_evro_ext_m_doIosWrite) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_doIosCtl", evro_ext_evro_ext_m_doIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_diIosOpen", evro_ext_evro_ext_m_diIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_diIosClose", evro_ext_evro_ext_m_diIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_diIosRead", evro_ext_evro_ext_m_diIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_m_diIosCtl", evro_ext_evro_ext_m_diIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8aoIosOpen", evro_ext_evro_ext_io8aoIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8aoIosClose", evro_ext_evro_ext_io8aoIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8aoIosWrite", evro_ext_evro_ext_io8aoIosWrite) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io8aoIosCtl", evro_ext_evro_ext_io8aoIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_4roIosOpen", evro_ext_evro_ext_io_4roIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_4roIosClose", evro_ext_evro_ext_io_4roIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_4roio4roIosWrite", evro_ext_evro_ext_io_4roio4roIosWrite) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_4roio4roIosCtl", evro_ext_evro_ext_io_4roio4roIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_4romodbusstatusIosRead", evro_ext_evro_ext_io_4romodbusstatusIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io_4romodbusstatusIosCtl", evro_ext_evro_ext_io_4romodbusstatusIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io4roIosOpen", evro_ext_evro_ext_io4roIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io4roIosClose", evro_ext_evro_ext_io4roIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io4roIosWrite", evro_ext_evro_ext_io4roIosWrite) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_io4roIosCtl", evro_ext_evro_ext_io4roIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbusstatusIosOpen", evro_ext_evro_ext_modbusstatusIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbusstatusIosClose", evro_ext_evro_ext_modbusstatusIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbusstatusIosRead", evro_ext_evro_ext_modbusstatusIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbusstatusIosCtl", evro_ext_evro_ext_modbusstatusIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_aoIosOpen", evro_ext_evro_ext_modbus_aoIosOpen) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_aoIosClose", evro_ext_evro_ext_modbus_aoIosClose) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_aom_aoIosWrite", evro_ext_evro_ext_modbus_aom_aoIosWrite) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_aom_aoIosCtl", evro_ext_evro_ext_modbus_aom_aoIosCtl) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_aomodbusstatusIosRead", evro_ext_evro_ext_modbus_aomodbusstatusIosRead) \
ISA_DECLARE_HANDLE("evro_ext_evro_ext_modbus_aomodbusstatusIosCtl", evro_ext_evro_ext_modbus_aomodbusstatusIosCtl) \
;

#endif /* _PACK_EVRO_EXT_H */

/* eof ********************************************************************/

