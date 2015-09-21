/**************************************************************************
File:               evro_ext_evro_ext_io_6rtd.h
Author:             Umputun
Creation date:      19/07/2012 - 12:57
Device name:        io_6rtd
***************************************************************************/

#ifndef _EVRO_EXT_EVRO_EXT_IO_6RTD_H /* nested Headers management */
#define _EVRO_EXT_EVRO_EXT_IO_6RTD_H

/* prototypes */

typSTATUS evro_ext_evro_ext_io_6rtdIosOpen
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_ext_evro_ext_io_6rtdIosClose
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_ext_evro_ext_io_6rtdio6rtdIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_ext_evro_ext_io_6rtdio6rtdIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

void evro_ext_evro_ext_io_6rtdmodbusstatusIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_ext_evro_ext_io_6rtdmodbusstatusIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);


#endif

/* eof ********************************************************************/

