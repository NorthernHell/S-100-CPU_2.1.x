/**************************************************************************
File:               evro_int_evro_int_evro_4ao.h
Author:             Umputun
Creation date:      21/07/2012 - 14:25
Device name:        EVRO_4AO
***************************************************************************/

#ifndef _EVRO_INT_EVRO_INT_EVRO_4AO_H /* nested Headers management */
#define _EVRO_INT_EVRO_INT_EVRO_4AO_H

/* prototypes */

typSTATUS evro_int_evro_int_evro_4aoIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_int_evro_int_evro_4aoIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_int_evro_int_evro_4aoIosWrite
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
);

void evro_int_evro_int_evro_4aoIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);
void evro_int_evro_int_evro_4ao_status_mIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_int_evro_int_evro_4ao_status_mIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);
#endif /* _EVRO_INT_EVRO_INT_EVRO_4AO_H */

/* eof ********************************************************************/

