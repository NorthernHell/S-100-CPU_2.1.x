/**************************************************************************
File:               pack_evro_tcp.h
Author:             Umputun
Creation date:      16/02/2013 - 20:17
POU name:           
***************************************************************************/

#ifndef _PACK_EVRO_TCP_H /* nested Headers management */
#define _PACK_EVRO_TCP_H

/* include item definition */

#include "dios0def.h"
#include "evro_tcp_evro_tcp_mts_holdingr_i.h" /* "mts_holdingr_i */
#include "evro_tcp_evro_tcp_modbus_tcp_server.h" /* "modbus_tcp_server */
#include "evro_tcp_evro_tcp_mts_inp_reg.h" /* "mts_inp_reg */
#include "evro_tcp_evro_tcp_mts_inp_bits.h" /* "mts_inp_bits */
#include "evro_tcp_evro_tcp_mts_coil_o.h" /* "mts_coil_o */
#include "evro_tcp_evro_tcp_mts_coil_i.h" /* "mts_coil_i */
#include "evro_tcp_evro_tcp_mts_holdingr_o.h" /* "mts_holdingr_o */

/* package definition */

#define ISA_DECLARE_PACK_EVRO_TCP \
ISA_DECLARE_PACKNAME("pack_evro_tcp") \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_IosInit", evro_tcp_evro_tcp_IosInit) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_IosExit", evro_tcp_evro_tcp_IosExit) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_holdingr_iIosOpen", evro_tcp_evro_tcp_mts_holdingr_iIosOpen) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_holdingr_iIosClose", evro_tcp_evro_tcp_mts_holdingr_iIosClose) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_holdingr_iIosRead", evro_tcp_evro_tcp_mts_holdingr_iIosRead) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_holdingr_iIosCtl", evro_tcp_evro_tcp_mts_holdingr_iIosCtl) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_modbus_tcp_serverIosOpen", evro_tcp_evro_tcp_modbus_tcp_serverIosOpen) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_modbus_tcp_serverIosClose", evro_tcp_evro_tcp_modbus_tcp_serverIosClose) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_modbus_tcp_servermts_coil_iIosRead", evro_tcp_evro_tcp_modbus_tcp_servermts_coil_iIosRead) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_modbus_tcp_servermts_coil_iIosCtl", evro_tcp_evro_tcp_modbus_tcp_servermts_coil_iIosCtl) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_modbus_tcp_servermts_coil_oIosWrite", evro_tcp_evro_tcp_modbus_tcp_servermts_coil_oIosWrite) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_modbus_tcp_servermts_coil_oIosCtl", evro_tcp_evro_tcp_modbus_tcp_servermts_coil_oIosCtl) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_modbus_tcp_servermts_holdingr_iIosRead", evro_tcp_evro_tcp_modbus_tcp_servermts_holdingr_iIosRead) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_modbus_tcp_servermts_holdingr_iIosCtl", evro_tcp_evro_tcp_modbus_tcp_servermts_holdingr_iIosCtl) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_modbus_tcp_servermts_holdingr_oIosWrite", evro_tcp_evro_tcp_modbus_tcp_servermts_holdingr_oIosWrite) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_modbus_tcp_servermts_holdingr_oIosCtl", evro_tcp_evro_tcp_modbus_tcp_servermts_holdingr_oIosCtl) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_modbus_tcp_servermts_inp_bitsIosWrite", evro_tcp_evro_tcp_modbus_tcp_servermts_inp_bitsIosWrite) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_modbus_tcp_servermts_inp_bitsIosCtl", evro_tcp_evro_tcp_modbus_tcp_servermts_inp_bitsIosCtl) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_modbus_tcp_servermts_inp_regIosWrite", evro_tcp_evro_tcp_modbus_tcp_servermts_inp_regIosWrite) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_modbus_tcp_servermts_inp_regIosCtl", evro_tcp_evro_tcp_modbus_tcp_servermts_inp_regIosCtl) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_inp_regIosOpen", evro_tcp_evro_tcp_mts_inp_regIosOpen) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_inp_regIosClose", evro_tcp_evro_tcp_mts_inp_regIosClose) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_inp_regIosWrite", evro_tcp_evro_tcp_mts_inp_regIosWrite) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_inp_regIosCtl", evro_tcp_evro_tcp_mts_inp_regIosCtl) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_inp_bitsIosOpen", evro_tcp_evro_tcp_mts_inp_bitsIosOpen) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_inp_bitsIosClose", evro_tcp_evro_tcp_mts_inp_bitsIosClose) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_inp_bitsIosWrite", evro_tcp_evro_tcp_mts_inp_bitsIosWrite) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_inp_bitsIosCtl", evro_tcp_evro_tcp_mts_inp_bitsIosCtl) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_coil_oIosOpen", evro_tcp_evro_tcp_mts_coil_oIosOpen) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_coil_oIosClose", evro_tcp_evro_tcp_mts_coil_oIosClose) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_coil_oIosWrite", evro_tcp_evro_tcp_mts_coil_oIosWrite) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_coil_oIosCtl", evro_tcp_evro_tcp_mts_coil_oIosCtl) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_coil_iIosOpen", evro_tcp_evro_tcp_mts_coil_iIosOpen) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_coil_iIosClose", evro_tcp_evro_tcp_mts_coil_iIosClose) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_coil_iIosRead", evro_tcp_evro_tcp_mts_coil_iIosRead) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_coil_iIosCtl", evro_tcp_evro_tcp_mts_coil_iIosCtl) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_holdingr_oIosOpen", evro_tcp_evro_tcp_mts_holdingr_oIosOpen) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_holdingr_oIosClose", evro_tcp_evro_tcp_mts_holdingr_oIosClose) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_holdingr_oIosWrite", evro_tcp_evro_tcp_mts_holdingr_oIosWrite) \
ISA_DECLARE_HANDLE("evro_tcp_evro_tcp_mts_holdingr_oIosCtl", evro_tcp_evro_tcp_mts_holdingr_oIosCtl) \
;

#endif /* _PACK_EVRO_TCP_H */

/* eof ********************************************************************/

