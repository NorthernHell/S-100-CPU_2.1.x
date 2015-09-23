/**************************************************************************
File:               evro_int_evro_int_status_m.h
Author:             umputun
Creation date:      21/07/2012 - 20:05
Device name:        status_m
***************************************************************************/

#ifndef _EVRO_INT_EVRO_INT_STATUS_M_H /* nested Headers management */
#define _EVRO_INT_EVRO_INT_STATUS_M_H

/* prototypes */

typSTATUS  evro_int_evro_int_IosInit
(
    strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to init */
);

void evro_int_evro_int_IosExit
(
    strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to exit */
);

typSTATUS evro_int_evro_int_status_mIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_int_evro_int_status_mIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_int_evro_int_status_mIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_int_evro_int_status_mIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

typSTATUS evro_int_evro_int_IosMdf
(
    uchar          cuSubFunc,    /* Sub function switch */
    strRtIoDrv*    pRtIoDrv,     /* Driver run time io struct */
    uint32         luMdfType,    /* On line modification types */
    void*          pvRtIoDvc     /* Reserved for future extensions */
);

typSTATUS evro_int_evro_int_status_mIosMdf
(
    uchar          cuSubFunc,  /* Sub function switch */
    strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
    uint32         luMdfType,  /* On line modification types */
    strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
    void*          pvOemSplDvc,/* New simple device OEM parameters */
    strDfIoChan*   pDfIoChan,  /* New first channel default struct */
    void*          pvOemChan   /* New first channel OEM parameters */
);


#endif /* _EVRO_INT_EVRO_INT_STATUS_M_H */

/* eof ********************************************************************/

