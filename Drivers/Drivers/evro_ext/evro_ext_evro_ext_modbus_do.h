/**************************************************************************
File:               evro_ext_evro_ext_modbus_do.h
Author:             Umputun
Creation date:      19/07/2012 - 12:57
Device name:        Modbus_DO
***************************************************************************/

#ifndef _EVRO_EXT_EVRO_EXT_MODBUS_DO_H /* nested Headers management */
#define _EVRO_EXT_EVRO_EXT_MODBUS_DO_H

/* prototypes */

typSTATUS evro_ext_evro_ext_modbus_doIosOpen
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
   );

void evro_ext_evro_ext_modbus_doIosClose
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
   );

void evro_ext_evro_ext_modbus_dom_doIosWrite
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
   );

void evro_ext_evro_ext_modbus_dom_doIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void evro_ext_evro_ext_modbus_domodbusstatusIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_ext_evro_ext_modbus_domodbusstatusIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

#endif /* _EVRO_EXT_EVRO_EXT_MODBUS_DO_H */

/* eof ********************************************************************/

