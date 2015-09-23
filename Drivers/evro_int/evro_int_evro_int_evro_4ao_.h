/**************************************************************************
File:               evro_int_evro_int_evro_4ao_.h
Author:             umputun
Creation date:      21/07/2012 - 20:05
Device name:        EVRO_4AO_
***************************************************************************/

#ifndef _EVRO_INT_EVRO_INT_EVRO_4AO__H /* nested Headers management */
#define _EVRO_INT_EVRO_INT_EVRO_4AO__H

/* prototypes */

typSTATUS evro_int_evro_int_evro_4ao_IosOpen
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_int_evro_int_evro_4ao_IosClose
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_int_evro_int_evro_4ao_evro_4aoIosWrite
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
);

void evro_int_evro_int_evro_4ao_evro_4aoIosCtl
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


typSTATUS evro_int_evro_int_IosMdf
(
    uchar          cuSubFunc,    /* Sub function switch */
    strRtIoDrv*    pRtIoDrv,     /* Driver run time io struct */
    uint32         luMdfType,    /* On line modification types */
    void*          pvRtIoDvc     /* Reserved for future extensions */
);

typSTATUS evro_int_evro_int_evro_4ao_IosMdf
(
    uchar          cuSubFunc,   /* Sub function switch */
    strRtIoCpxDvc* pRtIoCpxDvc, /* Complex device run time io struct */
    uint32         luMdfType,   /* On line modification types */
    strDfIoCpxDvc* pDfIoCpxDvc, /* New complex device default struct */
    void*          pvOemParam   /* New complex device OEM parameters */
);

typSTATUS evro_int_evro_int_evro_4ao_evro_4aoIosMdf
(
    uchar          cuSubFunc,  /* Sub function switch */
    strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
    uint32         luMdfType,  /* On line modification types */
    strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
    void*          pvOemSplDvc,/* New simple device OEM parameters */
    strDfIoChan*   pDfIoChan,  /* New first channel default struct */
    void*          pvOemChan   /* New first channel OEM parameters */
);

typSTATUS evro_int_evro_int_evro_4ao_status_mIosMdf
(
    uchar          cuSubFunc,  /* Sub function switch */
    strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
    uint32         luMdfType,  /* On line modification types */
    strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
    void*          pvOemSplDvc,/* New simple device OEM parameters */
    strDfIoChan*   pDfIoChan,  /* New first channel default struct */
    void*          pvOemChan   /* New first channel OEM parameters */
);



#endif /* _EVRO_INT_EVRO_INT_EVRO_4AO__H */

/* eof ********************************************************************/

