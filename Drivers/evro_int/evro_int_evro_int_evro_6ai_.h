/**************************************************************************
File:               evro_int_evro_int_evro_6ai_.h
Author:             umputun
Creation date:      21/07/2012 - 20:05
Device name:        EVRO_6AI_
***************************************************************************/

#ifndef _EVRO_INT_EVRO_INT_EVRO_6AI__H /* nested Headers management */
#define _EVRO_INT_EVRO_INT_EVRO_6AI__H

/* prototypes */

typSTATUS evro_int_evro_int_evro_6ai_IosOpen
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_int_evro_int_evro_6ai_IosClose
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_int_evro_int_evro_6ai_evro_6aiIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_int_evro_int_evro_6ai_evro_6aiIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

void evro_int_evro_int_evro_6ai_status_mIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_int_evro_int_evro_6ai_status_mIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);
#endif /* _EVRO_INT_EVRO_INT_EVRO_6AI__H */

/* eof ********************************************************************/

