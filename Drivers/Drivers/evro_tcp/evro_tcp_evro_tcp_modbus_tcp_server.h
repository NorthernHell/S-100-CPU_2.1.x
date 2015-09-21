/**************************************************************************
File:               evro_tcp_evro_tcp_modbus_tcp_server.h
Author:             Umputun
Creation date:      16/02/2013 - 20:16
Device name:        MODBUS_TCP_SERVER
***************************************************************************/

#ifndef _EVRO_TCP_EVRO_TCP_MODBUS_TCP_SERVER_H /* nested Headers management */
#define _EVRO_TCP_EVRO_TCP_MODBUS_TCP_SERVER_H

/* prototypes */

typSTATUS  evro_tcp_evro_tcp_IosInit
   (
   strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to init */
   );

void evro_tcp_evro_tcp_IosExit
   (
   strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to exit */
   );

typSTATUS evro_tcp_evro_tcp_modbus_tcp_serverIosOpen
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
   );

void evro_tcp_evro_tcp_modbus_tcp_serverIosClose
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
   );

void evro_tcp_evro_tcp_modbus_tcp_servermts_coil_iIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_tcp_evro_tcp_modbus_tcp_servermts_coil_iIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void evro_tcp_evro_tcp_modbus_tcp_servermts_coil_oIosWrite
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
   );

void evro_tcp_evro_tcp_modbus_tcp_servermts_coil_oIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void evro_tcp_evro_tcp_modbus_tcp_servermts_holdingr_iIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_tcp_evro_tcp_modbus_tcp_servermts_holdingr_iIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void evro_tcp_evro_tcp_modbus_tcp_servermts_holdingr_oIosWrite
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
   );

void evro_tcp_evro_tcp_modbus_tcp_servermts_holdingr_oIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void evro_tcp_evro_tcp_modbus_tcp_servermts_inp_bitsIosWrite
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
   );

void evro_tcp_evro_tcp_modbus_tcp_servermts_inp_bitsIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void evro_tcp_evro_tcp_modbus_tcp_servermts_inp_regIosWrite
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
   );

void evro_tcp_evro_tcp_modbus_tcp_servermts_inp_regIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );


typSTATUS evro_tcp_evro_tcp_IosMdf
   (
   uchar          cuSubFunc,    /* Sub function switch */
   strRtIoDrv*    pRtIoDrv,     /* Driver run time io struct */
   uint32         luMdfType,    /* On line modification types */
   void*          pvRtIoDvc     /* Reserved for future extensions */
   );

typSTATUS evro_tcp_evro_tcp_modbus_tcp_serverIosMdf
   (
   uchar          cuSubFunc,   /* Sub function switch */
   strRtIoCpxDvc* pRtIoCpxDvc, /* Complex device run time io struct */
   uint32         luMdfType,   /* On line modification types */
   strDfIoCpxDvc* pDfIoCpxDvc, /* New complex device default struct */
   void*          pvOemParam   /* New complex device OEM parameters */
   );

typSTATUS evro_tcp_evro_tcp_modbus_tcp_servermts_coil_iIosMdf
   (
   uchar          cuSubFunc,  /* Sub function switch */
   strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
   uint32         luMdfType,  /* On line modification types */
   strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
   void*          pvOemSplDvc,/* New simple device OEM parameters */
   strDfIoChan*   pDfIoChan,  /* New first channel default struct */
   void*          pvOemChan   /* New first channel OEM parameters */
   );

typSTATUS evro_tcp_evro_tcp_modbus_tcp_servermts_coil_oIosMdf
   (
   uchar          cuSubFunc,  /* Sub function switch */
   strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
   uint32         luMdfType,  /* On line modification types */
   strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
   void*          pvOemSplDvc,/* New simple device OEM parameters */
   strDfIoChan*   pDfIoChan,  /* New first channel default struct */
   void*          pvOemChan   /* New first channel OEM parameters */
   );

typSTATUS evro_tcp_evro_tcp_modbus_tcp_servermts_holdingr_iIosMdf
   (
   uchar          cuSubFunc,  /* Sub function switch */
   strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
   uint32         luMdfType,  /* On line modification types */
   strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
   void*          pvOemSplDvc,/* New simple device OEM parameters */
   strDfIoChan*   pDfIoChan,  /* New first channel default struct */
   void*          pvOemChan   /* New first channel OEM parameters */
   );

typSTATUS evro_tcp_evro_tcp_modbus_tcp_servermts_holdingr_oIosMdf
   (
   uchar          cuSubFunc,  /* Sub function switch */
   strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
   uint32         luMdfType,  /* On line modification types */
   strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
   void*          pvOemSplDvc,/* New simple device OEM parameters */
   strDfIoChan*   pDfIoChan,  /* New first channel default struct */
   void*          pvOemChan   /* New first channel OEM parameters */
   );

typSTATUS evro_tcp_evro_tcp_modbus_tcp_servermts_inp_bitsIosMdf
   (
   uchar          cuSubFunc,  /* Sub function switch */
   strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
   uint32         luMdfType,  /* On line modification types */
   strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
   void*          pvOemSplDvc,/* New simple device OEM parameters */
   strDfIoChan*   pDfIoChan,  /* New first channel default struct */
   void*          pvOemChan   /* New first channel OEM parameters */
   );

typSTATUS evro_tcp_evro_tcp_modbus_tcp_servermts_inp_regIosMdf
   (
   uchar          cuSubFunc,  /* Sub function switch */
   strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
   uint32         luMdfType,  /* On line modification types */
   strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
   void*          pvOemSplDvc,/* New simple device OEM parameters */
   strDfIoChan*   pDfIoChan,  /* New first channel default struct */
   void*          pvOemChan   /* New first channel OEM parameters */
   );



#endif /* _EVRO_TCP_EVRO_TCP_MODBUS_TCP_SERVER_H */

/* eof ********************************************************************/

