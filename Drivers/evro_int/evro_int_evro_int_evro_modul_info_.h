/**************************************************************************
File:               evro_int_evro_int_evro_modul_info_.h
Author:             umputun
Creation date:      21/07/2012 - 20:05
Device name:        EVRO_modul_info_
***************************************************************************/

#ifndef _EVRO_INT_EVRO_INT_EVRO_modul_info__H /* nested Headers management */
#define _EVRO_INT_EVRO_INT_EVRO_modul_info__H

/* prototypes */

typSTATUS evro_int_evro_int_evro_modul_info_IosOpen
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_int_evro_int_evro_modul_info_IosClose
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_int_evro_int_evro_modul_info_evro_modul_infoIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_int_evro_int_evro_modul_info_evro_modul_infoIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

void evro_int_evro_int_evro_modul_info_evro_avar_infoIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_int_evro_int_evro_modul_info_evro_avar_infoIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

void evro_int_evro_int_evro_modul_info_evro_temp_infoIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_int_evro_int_evro_modul_info_evro_temp_infoIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

void evro_int_evro_int_evro_modul_info_evro_indicate_infoIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_int_evro_int_evro_modul_info_evro_indicate_infoIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);


void evro_int_evro_int_evro_modul_info_status_mIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_int_evro_int_evro_modul_info_status_mIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

#endif /* _EVRO_INT_EVRO_INT_EVRO_modul_info__H */

/* eof ********************************************************************/

