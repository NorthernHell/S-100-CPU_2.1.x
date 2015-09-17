/**************************************************************************
File:               evro_ext_evro_ext_modbus_di.h
Author:             Umputun
Creation date:      19/07/2012 - 12:57
Device name:        Modbus_DI
***************************************************************************/

#ifndef _EVRO_EXT_EVRO_EXT_MODBUS_DI_H /* nested Headers management */
#define _EVRO_EXT_EVRO_EXT_MODBUS_DI_H

/* prototypes */

typSTATUS evro_ext_evro_ext_modbus_diIosOpen
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
   );

void evro_ext_evro_ext_modbus_diIosClose
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
   );

void evro_ext_evro_ext_modbus_dim_diIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_ext_evro_ext_modbus_dim_diIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void evro_ext_evro_ext_modbus_dimodbusstatusIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_ext_evro_ext_modbus_dimodbusstatusIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );
#endif
/* eof ********************************************************************/

