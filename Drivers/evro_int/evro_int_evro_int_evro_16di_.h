/**************************************************************************
File:               evro_int_evro_int_evro_16di_.h
Author:             umputun
Creation date:      21/07/2012 - 20:05
Device name:        EVRO_16dI_
***************************************************************************/

#ifndef _EVRO_INT_EVRO_INT_EVRO_16dI__H /* nested Headers management */
#define _EVRO_INT_EVRO_INT_EVRO_16dI__H

/* prototypes */

typSTATUS evro_int_evro_int_evro_16di_IosOpen
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_int_evro_int_evro_16di_IosClose
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_int_evro_int_evro_16di_evro_16diIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_int_evro_int_evro_16di_evro_16diIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

void evro_int_evro_int_evro_16di_evro_16dirIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_int_evro_int_evro_16di_evro_16dirIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

void evro_int_evro_int_evro_16di_status_mIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_int_evro_int_evro_16di_status_mIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

#endif /* _EVRO_INT_EVRO_INT_EVRO_16dI__H */

/* eof ********************************************************************/

