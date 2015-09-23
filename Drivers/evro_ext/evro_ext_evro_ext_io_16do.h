/**************************************************************************
File:               evro_ext_evro_ext_io_16do.h
Author:             Umputun
Creation date:      19/07/2012 - 12:57
Device name:        IO_16DO
***************************************************************************/

#ifndef _EVRO_EXT_EVRO_EXT_IO_16DO_H /* nested Headers management */
#define _EVRO_EXT_EVRO_EXT_IO_16DO_H

/* prototypes */

typSTATUS evro_ext_evro_ext_io_16doIosOpen
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_ext_evro_ext_io_16doIosClose
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_ext_evro_ext_io_16doio16doIosWrite
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
);

void evro_ext_evro_ext_io_16doio16doIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

void evro_ext_evro_ext_io_16domodbusstatusIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_ext_evro_ext_io_16domodbusstatusIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);



#endif /* _EVRO_EXT_EVRO_EXT_IO_16DO_H */

/* eof ********************************************************************/

