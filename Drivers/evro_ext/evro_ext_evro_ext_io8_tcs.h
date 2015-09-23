/**************************************************************************
File:               evro_ext_evro_ext_io8_tcs.h
Author:             Umputun
Creation date:      19/07/2012 - 12:57
Device name:        IO8_TCS
***************************************************************************/

#ifndef _EVRO_EXT_EVRO_EXT_IO8_TCS_H /* nested Headers management */
#define _EVRO_EXT_EVRO_EXT_IO8_TCS_H

/* prototypes */

typSTATUS evro_ext_evro_ext_io8_tcsIosOpen
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_ext_evro_ext_io8_tcsIosClose
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_ext_evro_ext_io8_tcsio8tcsIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_ext_evro_ext_io8_tcsio8tcsIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

void evro_ext_evro_ext_io8_tcsmodbusstatusIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_ext_evro_ext_io8_tcsmodbusstatusIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);


#endif /* _EVRO_EXT_EVRO_EXT_IO8_TCS_H */

/* eof ********************************************************************/

