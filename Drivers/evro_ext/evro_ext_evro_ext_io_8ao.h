/**************************************************************************
File:               evro_ext_evro_ext_io_8ao.h
Author:             Umputun
Creation date:      19/07/2012 - 12:57
Device name:        IO_8AO
***************************************************************************/

#ifndef _EVRO_EXT_EVRO_EXT_IO_8AO_H /* nested Headers management */
#define _EVRO_EXT_EVRO_EXT_IO_8AO_H

/* prototypes */

typSTATUS evro_ext_evro_ext_io_8aoIosOpen
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_ext_evro_ext_io_8aoIosClose
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_ext_evro_ext_io_8aoio8aoIosWrite
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
);

void evro_ext_evro_ext_io_8aoio8aoIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

void evro_ext_evro_ext_io_8aomodbusstatusIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_ext_evro_ext_io_8aomodbusstatusIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

#endif /* _EVRO_EXT_EVRO_EXT_IO_8AO_H */

/* eof ********************************************************************/

