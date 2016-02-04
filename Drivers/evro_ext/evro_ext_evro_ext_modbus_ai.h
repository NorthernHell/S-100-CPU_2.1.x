/**************************************************************************
File:               evro_ext_evro_ext_modbus_ai.h
Author:             Umputun
Creation date:      19/07/2012 - 12:57
Device name:        Modbus_AI
***************************************************************************/

#ifndef _EVRO_EXT_EVRO_EXT_MODBUS_AI_H /* nested Headers management */
#define _EVRO_EXT_EVRO_EXT_MODBUS_AI_H

/* prototypes */

typSTATUS evro_ext_evro_ext_modbus_aiIosOpen
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_ext_evro_ext_modbus_aiIosClose
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_ext_evro_ext_modbus_aim_aiIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_ext_evro_ext_modbus_aim_aiIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

void evro_ext_evro_ext_modbus_aimodbusstatusIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_ext_evro_ext_modbus_aimodbusstatusIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);


#endif /* _EVRO_EXT_EVRO_EXT_MODBUS_AI_H */

/* eof ********************************************************************/

