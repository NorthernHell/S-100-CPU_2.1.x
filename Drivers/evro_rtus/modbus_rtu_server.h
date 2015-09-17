/**************************************************************************
File:               modbus_rtu_server.h
Author:             Umputun
Creation date:      20/02/2013 - 12:46
Device name:        MODBUS_RTU_SERVER
***************************************************************************/

#ifndef _MODBUS_RTU_SERVER_H /* nested Headers management */
#define _MODBUS_RTU_SERVER_H

/* prototypes */

typSTATUS  _evro_rtus_evro_rtusIosInit
   (
   strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to init */
   );

void _evro_rtus_evro_rtusIosExit
   (
   strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to exit */
   );

typSTATUS _evro_rtus_evro_rtusmodbus_rtu_serverIosOpen
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
   );

void _evro_rtus_evro_rtusmodbus_rtu_serverIosClose
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
   );

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_i_IosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_i_IosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_o_IosWrite
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
   );

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_o_IosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_i_IosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_i_IosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_o_IosWrite
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
   );

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_o_IosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_bits_IosWrite
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
   );

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_bits_IosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_reg_IosWrite
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
   );

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_reg_IosCtl
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

typSTATUS _evro_rtus_evro_rtusmodbus_rtu_serverIosMdf
   (
   uchar          cuSubFunc,   /* Sub function switch */
   strRtIoCpxDvc* pRtIoCpxDvc, /* Complex device run time io struct */
   uint32         luMdfType,   /* On line modification types */
   strDfIoCpxDvc* pDfIoCpxDvc, /* New complex device default struct */
   void*          pvOemParam   /* New complex device OEM parameters */
   );

typSTATUS _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_i_IosMdf
   (
   uchar          cuSubFunc,  /* Sub function switch */
   strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
   uint32         luMdfType,  /* On line modification types */
   strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
   void*          pvOemSplDvc,/* New simple device OEM parameters */
   strDfIoChan*   pDfIoChan,  /* New first channel default struct */
   void*          pvOemChan   /* New first channel OEM parameters */
   );

typSTATUS _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_o_IosMdf
   (
   uchar          cuSubFunc,  /* Sub function switch */
   strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
   uint32         luMdfType,  /* On line modification types */
   strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
   void*          pvOemSplDvc,/* New simple device OEM parameters */
   strDfIoChan*   pDfIoChan,  /* New first channel default struct */
   void*          pvOemChan   /* New first channel OEM parameters */
   );

typSTATUS _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_i_IosMdf
   (
   uchar          cuSubFunc,  /* Sub function switch */
   strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
   uint32         luMdfType,  /* On line modification types */
   strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
   void*          pvOemSplDvc,/* New simple device OEM parameters */
   strDfIoChan*   pDfIoChan,  /* New first channel default struct */
   void*          pvOemChan   /* New first channel OEM parameters */
   );

typSTATUS _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_o_IosMdf
   (
   uchar          cuSubFunc,  /* Sub function switch */
   strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
   uint32         luMdfType,  /* On line modification types */
   strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
   void*          pvOemSplDvc,/* New simple device OEM parameters */
   strDfIoChan*   pDfIoChan,  /* New first channel default struct */
   void*          pvOemChan   /* New first channel OEM parameters */
   );

typSTATUS _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_bits_IosMdf
   (
   uchar          cuSubFunc,  /* Sub function switch */
   strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
   uint32         luMdfType,  /* On line modification types */
   strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
   void*          pvOemSplDvc,/* New simple device OEM parameters */
   strDfIoChan*   pDfIoChan,  /* New first channel default struct */
   void*          pvOemChan   /* New first channel OEM parameters */
   );

typSTATUS _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_reg_IosMdf
   (
   uchar          cuSubFunc,  /* Sub function switch */
   strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
   uint32         luMdfType,  /* On line modification types */
   strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
   void*          pvOemSplDvc,/* New simple device OEM parameters */
   strDfIoChan*   pDfIoChan,  /* New first channel default struct */
   void*          pvOemChan   /* New first channel OEM parameters */
   );



#endif /* _MODBUS_RTU_SERVER_H */

/* eof ********************************************************************/

