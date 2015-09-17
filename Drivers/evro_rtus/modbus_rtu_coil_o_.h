/**************************************************************************
File:               modbus_rtu_coil_o_.h
Author:             Umputun
Creation date:      20/02/2013 - 12:46
Device name:        MODBUS_RTU_COIL_O_
***************************************************************************/

#ifndef _MODBUS_RTU_COIL_O__H /* nested Headers management */
#define _MODBUS_RTU_COIL_O__H

/* prototypes */

typSTATUS  _evro_rtus_evro_rtusIosInit
   (
   strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to init */
   );

void _evro_rtus_evro_rtusIosExit
   (
   strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to exit */
   );

typSTATUS _evro_rtus_evro_rtusmodbus_rtu_coil_o_IosOpen
   (
   strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
   );

void _evro_rtus_evro_rtusmodbus_rtu_coil_o_IosClose
   (
   strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
   );

void _evro_rtus_evro_rtusmodbus_rtu_coil_o_IosWrite
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
   );

void _evro_rtus_evro_rtusmodbus_rtu_coil_o_IosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

typSTATUS _evro_rtus_evro_rtusIosMdf
   (
   uchar          cuSubFunc,    /* Sub function switch */
   strRtIoDrv*    pRtIoDrv,     /* Driver run time io struct */
   uint32         luMdfType,    /* On line modification types */
   void*          pvRtIoDvc     /* Reserved for future extensions */
   );

typSTATUS _evro_rtus_evro_rtusmodbus_rtu_coil_o_IosMdf
   (
   uchar          cuSubFunc,  /* Sub function switch */
   strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
   uint32         luMdfType,  /* On line modification types */
   strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
   void*          pvOemSplDvc,/* New simple device OEM parameters */
   strDfIoChan*   pDfIoChan,  /* New first channel default struct */
   void*          pvOemChan   /* New first channel OEM parameters */
   );


#endif /* _MODBUS_RTU_COIL_O__H */

/* eof ********************************************************************/

