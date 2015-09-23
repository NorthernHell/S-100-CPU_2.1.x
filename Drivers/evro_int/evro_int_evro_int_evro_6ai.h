/**************************************************************************
File:               evro_int_evro_int_evro_6ai.h
Author:             Umputun
Creation date:      21/07/2012 - 14:25
Device name:        EVRO_6AI
***************************************************************************/

#ifndef _EVRO_INT_EVRO_INT_EVRO_6AI_H /* nested Headers management */
#define _EVRO_INT_EVRO_INT_EVRO_6AI_H

/* prototypes */

typSTATUS evro_int_evro_int_evro_6aiIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_int_evro_int_evro_6aiIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_int_evro_int_evro_6aiIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_int_evro_int_evro_6aiIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);

#endif /* _EVRO_INT_EVRO_INT_EVRO_6AI_H */

/* eof ********************************************************************/

