/**************************************************************************
File:               evro_int_evro_int_evro_16di.h
Author:             Umputun
Creation date:      21/07/2012 - 14:25
Device name:        EVRO_16dI
***************************************************************************/

#ifndef _EVRO_INT_EVRO_INT_EVRO_16dI_H /* nested Headers management */
#define _EVRO_INT_EVRO_INT_EVRO_16dI_H

/* prototypes */

typSTATUS evro_int_evro_int_evro_16diIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_int_evro_int_evro_16diIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_int_evro_int_evro_16diIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_int_evro_int_evro_16diIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);
#endif /* _EVRO_INT_EVRO_INT_EVRO_16dI_H */

/* eof ********************************************************************/

