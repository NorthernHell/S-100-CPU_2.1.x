/**************************************************************************
File:               pack_evro_rtus.h
Author:             Umputun
Creation date:      20/02/2013 - 12:47
POU name:           
***************************************************************************/

#ifndef _PACK_EVRO_RTUS_H /* nested Headers management */
#define _PACK_EVRO_RTUS_H

/* include item definition */

#include "dios0def.h"
#include "modbus_rtu_coil_o_.h" /* "modbus_rtu_coil_o_ */
#include "modbus_rtu_inp_bits_.h" /* "modbus_rtu_inp_bits_ */
#include "modbus_rtu_server.h" /* "modbus_rtu_server */
#include "modbus_rtu_coil_i_.h" /* "modbus_rtu_coil_i_ */
#include "modbus_rtu_inp_reg_.h" /* "modbus_rtu_inp_reg_ */
#include "modbus_rtu_holding_o_.h" /* "modbus_rtu_holding_o_ */
#include "modbus_rtu_holding_i_.h" /* "modbus_rtu_holding_i_ */

/* package definition */

#define ISA_DECLARE_PACK_EVRO_RTUS \
ISA_DECLARE_PACKNAME("pack_evro_rtus") \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusIosInit", _evro_rtus_evro_rtusIosInit) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusIosExit", _evro_rtus_evro_rtusIosExit) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_coil_o_IosOpen", _evro_rtus_evro_rtusmodbus_rtu_coil_o_IosOpen) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_coil_o_IosClose", _evro_rtus_evro_rtusmodbus_rtu_coil_o_IosClose) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_coil_o_IosWrite", _evro_rtus_evro_rtusmodbus_rtu_coil_o_IosWrite) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_coil_o_IosCtl", _evro_rtus_evro_rtusmodbus_rtu_coil_o_IosCtl) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_inp_bits_IosOpen", _evro_rtus_evro_rtusmodbus_rtu_inp_bits_IosOpen) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_inp_bits_IosClose", _evro_rtus_evro_rtusmodbus_rtu_inp_bits_IosClose) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_inp_bits_IosWrite", _evro_rtus_evro_rtusmodbus_rtu_inp_bits_IosWrite) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_inp_bits_IosCtl", _evro_rtus_evro_rtusmodbus_rtu_inp_bits_IosCtl) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_serverIosOpen", _evro_rtus_evro_rtusmodbus_rtu_serverIosOpen) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_serverIosClose", _evro_rtus_evro_rtusmodbus_rtu_serverIosClose) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_i_IosRead", _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_i_IosRead) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_i_IosCtl", _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_i_IosCtl) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_o_IosWrite", _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_o_IosWrite) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_o_IosCtl", _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_o_IosCtl) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_i_IosRead", _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_i_IosRead) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_i_IosCtl", _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_i_IosCtl) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_o_IosWrite", _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_o_IosWrite) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_o_IosCtl", _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_o_IosCtl) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_bits_IosWrite", _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_bits_IosWrite) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_bits_IosCtl", _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_bits_IosCtl) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_reg_IosWrite", _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_reg_IosWrite) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_reg_IosCtl", _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_reg_IosCtl) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_coil_i_IosOpen", _evro_rtus_evro_rtusmodbus_rtu_coil_i_IosOpen) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_coil_i_IosClose", _evro_rtus_evro_rtusmodbus_rtu_coil_i_IosClose) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_coil_i_IosRead", _evro_rtus_evro_rtusmodbus_rtu_coil_i_IosRead) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_coil_i_IosCtl", _evro_rtus_evro_rtusmodbus_rtu_coil_i_IosCtl) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_inp_reg_IosOpen", _evro_rtus_evro_rtusmodbus_rtu_inp_reg_IosOpen) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_inp_reg_IosClose", _evro_rtus_evro_rtusmodbus_rtu_inp_reg_IosClose) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_inp_reg_IosWrite", _evro_rtus_evro_rtusmodbus_rtu_inp_reg_IosWrite) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_inp_reg_IosCtl", _evro_rtus_evro_rtusmodbus_rtu_inp_reg_IosCtl) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_holding_o_IosOpen", _evro_rtus_evro_rtusmodbus_rtu_holding_o_IosOpen) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_holding_o_IosClose", _evro_rtus_evro_rtusmodbus_rtu_holding_o_IosClose) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_holding_o_IosWrite", _evro_rtus_evro_rtusmodbus_rtu_holding_o_IosWrite) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_holding_o_IosCtl", _evro_rtus_evro_rtusmodbus_rtu_holding_o_IosCtl) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_holding_i_IosOpen", _evro_rtus_evro_rtusmodbus_rtu_holding_i_IosOpen) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_holding_i_IosClose", _evro_rtus_evro_rtusmodbus_rtu_holding_i_IosClose) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_holding_i_IosRead", _evro_rtus_evro_rtusmodbus_rtu_holding_i_IosRead) \
ISA_DECLARE_HANDLE("_evro_rtus_evro_rtusmodbus_rtu_holding_i_IosCtl", _evro_rtus_evro_rtusmodbus_rtu_holding_i_IosCtl) \
;

#endif /* _PACK_EVRO_RTUS_H */

/* eof ********************************************************************/

