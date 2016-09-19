/**************************************************************************
File:               pack_evro_tcpc.h
Author:             Umputun
Creation date:      25/02/2013 - 16:09
POU name:           
***************************************************************************/

#ifndef _PACK_EVRO_TCPC_H /* nested Headers management */
#define _PACK_EVRO_TCPC_H

/* include item definition */

#include "dios0def.h"
#include "evro_tcpc_evro_tcpc_mtcp_ai.h" /* "mtcp_ai */
#include "evro_tcpc_evro_tcpc_modbus_tcp_client_ai.h" /* "modbus_tcp_client_ai */
#include "evro_tcpc_evro_tcpc_mtcp_do.h" /* "mtcp_do */
#include "evro_tcpc_evro_tcpc_modbus_tcp_client_do.h" /* "modbus_tcp_client_do */
#include "evro_tcpc_evro_tcpc_modbus_tcp_status.h" /* "modbus_tcp_status */
#include "evro_tcpc_evro_tcpc_mtcp_di.h" /* "mtcp_di */
#include "evro_tcpc_evro_tcpc_modbus_tcp_client_di.h" /* "modbus_tcp_client_di */
#include "evro_tcpc_evro_tcpc_mtcp_ao.h" /* "mtcp_ao */
#include "evro_tcpc_evro_tcpc_modbus_tcp_client_ao.h" /* "modbus_tcp_client_ao */
#include "evro_tcpc_evro_tcpc_mtcp_ao_float.h" /* "mtcp_ao_float */
#include "evro_tcpc_evro_tcpc_modbus_tcp_client_ao_float.h" /* "modbus_tcp_client_ao_float */

/* package definition */

#define ISA_DECLARE_PACK_EVRO_TCPC \
ISA_DECLARE_PACKNAME("pack_evro_tcpc") \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_IosInit", evro_tcpc_evro_tcpc_IosInit) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_IosExit", evro_tcpc_evro_tcpc_IosExit) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_aiIosOpen", evro_tcpc_evro_tcpc_mtcp_aiIosOpen) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_aiIosClose", evro_tcpc_evro_tcpc_mtcp_aiIosClose) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_aiIosRead", evro_tcpc_evro_tcpc_mtcp_aiIosRead) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_aiIosCtl", evro_tcpc_evro_tcpc_mtcp_aiIosCtl) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_aiIosOpen", evro_tcpc_evro_tcpc_modbus_tcp_client_aiIosOpen) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_aiIosClose", evro_tcpc_evro_tcpc_modbus_tcp_client_aiIosClose) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_aimodbus_tcp_statusIosRead", evro_tcpc_evro_tcpc_modbus_tcp_client_aimodbus_tcp_statusIosRead) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_aimodbus_tcp_statusIosCtl", evro_tcpc_evro_tcpc_modbus_tcp_client_aimodbus_tcp_statusIosCtl) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_aimtcp_aiIosRead", evro_tcpc_evro_tcpc_modbus_tcp_client_aimtcp_aiIosRead) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_aimtcp_aiIosCtl", evro_tcpc_evro_tcpc_modbus_tcp_client_aimtcp_aiIosCtl) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_doIosOpen", evro_tcpc_evro_tcpc_mtcp_doIosOpen) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_doIosClose", evro_tcpc_evro_tcpc_mtcp_doIosClose) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_doIosWrite", evro_tcpc_evro_tcpc_mtcp_doIosWrite) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_doIosCtl", evro_tcpc_evro_tcpc_mtcp_doIosCtl) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_doIosOpen", evro_tcpc_evro_tcpc_modbus_tcp_client_doIosOpen) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_doIosClose", evro_tcpc_evro_tcpc_modbus_tcp_client_doIosClose) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_domodbus_tcp_statusIosRead", evro_tcpc_evro_tcpc_modbus_tcp_client_domodbus_tcp_statusIosRead) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_domodbus_tcp_statusIosCtl", evro_tcpc_evro_tcpc_modbus_tcp_client_domodbus_tcp_statusIosCtl) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_domtcp_doIosWrite", evro_tcpc_evro_tcpc_modbus_tcp_client_domtcp_doIosWrite) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_domtcp_doIosCtl", evro_tcpc_evro_tcpc_modbus_tcp_client_domtcp_doIosCtl) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_statusIosOpen", evro_tcpc_evro_tcpc_modbus_tcp_statusIosOpen) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_statusIosClose", evro_tcpc_evro_tcpc_modbus_tcp_statusIosClose) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_statusIosRead", evro_tcpc_evro_tcpc_modbus_tcp_statusIosRead) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_statusIosCtl", evro_tcpc_evro_tcpc_modbus_tcp_statusIosCtl) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_diIosOpen", evro_tcpc_evro_tcpc_mtcp_diIosOpen) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_diIosClose", evro_tcpc_evro_tcpc_mtcp_diIosClose) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_diIosRead", evro_tcpc_evro_tcpc_mtcp_diIosRead) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_diIosCtl", evro_tcpc_evro_tcpc_mtcp_diIosCtl) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_diIosOpen", evro_tcpc_evro_tcpc_modbus_tcp_client_diIosOpen) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_diIosClose", evro_tcpc_evro_tcpc_modbus_tcp_client_diIosClose) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_dimodbus_tcp_statusIosRead", evro_tcpc_evro_tcpc_modbus_tcp_client_dimodbus_tcp_statusIosRead) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_dimodbus_tcp_statusIosCtl", evro_tcpc_evro_tcpc_modbus_tcp_client_dimodbus_tcp_statusIosCtl) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_dimtcp_diIosRead", evro_tcpc_evro_tcpc_modbus_tcp_client_dimtcp_diIosRead) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_dimtcp_diIosCtl", evro_tcpc_evro_tcpc_modbus_tcp_client_dimtcp_diIosCtl) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_aoIosOpen", evro_tcpc_evro_tcpc_mtcp_aoIosOpen) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_aoIosClose", evro_tcpc_evro_tcpc_mtcp_aoIosClose) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_aoIosWrite", evro_tcpc_evro_tcpc_mtcp_aoIosWrite) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_aoIosCtl", evro_tcpc_evro_tcpc_mtcp_aoIosCtl) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_aoIosOpen", evro_tcpc_evro_tcpc_modbus_tcp_client_aoIosOpen) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_aoIosClose", evro_tcpc_evro_tcpc_modbus_tcp_client_aoIosClose) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_aomodbus_tcp_statusIosRead", evro_tcpc_evro_tcpc_modbus_tcp_client_aomodbus_tcp_statusIosRead) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_aomodbus_tcp_statusIosCtl", evro_tcpc_evro_tcpc_modbus_tcp_client_aomodbus_tcp_statusIosCtl) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_aomtcp_aoIosWrite", evro_tcpc_evro_tcpc_modbus_tcp_client_aomtcp_aoIosWrite) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_aomtcp_aoIosCtl", evro_tcpc_evro_tcpc_modbus_tcp_client_aomtcp_aoIosCtl) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_ao_floatIosOpen", evro_tcpc_evro_tcpc_mtcp_ao_floatIosOpen) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_ao_floatIosClose", evro_tcpc_evro_tcpc_mtcp_ao_floatIosClose) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_ao_floatIosWrite", evro_tcpc_evro_tcpc_mtcp_ao_floatIosWrite) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_mtcp_ao_floatIosCtl", evro_tcpc_evro_tcpc_mtcp_ao_floatIosCtl) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_ao_floatIosOpen", evro_tcpc_evro_tcpc_modbus_tcp_client_ao_floatIosOpen) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_ao_floatIosClose", evro_tcpc_evro_tcpc_modbus_tcp_client_ao_floatIosClose) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_ao_floatmodbus_tcp_statusIosRead", evro_tcpc_evro_tcpc_modbus_tcp_client_ao_floatmodbus_tcp_statusIosRead) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_ao_floatmodbus_tcp_statusIosCtl", evro_tcpc_evro_tcpc_modbus_tcp_client_ao_floatmodbus_tcp_statusIosCtl) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_ao_floatmtcp_ao_floatIosWrite", evro_tcpc_evro_tcpc_modbus_tcp_client_ao_floatmtcp_ao_floatIosWrite) \
ISA_DECLARE_HANDLE("evro_tcpc_evro_tcpc_modbus_tcp_client_ao_floatmtcp_ao_floatIosCtl", evro_tcpc_evro_tcpc_modbus_tcp_client_ao_floatmtcp_ao_floatIosCtl) \

;

#endif /* _PACK_EVRO_TCPC_H */

/* eof ********************************************************************/

