/**************************************************************************
File:               evro_int_evro_int_evro_8dir.h
Author:             Umputun
Creation date:      21/07/2012 - 14:25
Device name:        EVRO_8DIR
***************************************************************************/

#ifndef _EVRO_INT_EVRO_INT_EVRO_8DIR_H /* nested Headers management */
#define _EVRO_INT_EVRO_INT_EVRO_8DIR_H

/* prototypes */

typSTATUS evro_int_evro_int_evro_8dirIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_int_evro_int_evro_8dirIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_int_evro_int_evro_8dirIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
);

void evro_int_evro_int_evro_8dirIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);



#endif /* _EVRO_INT_EVRO_INT_EVRO_8DIR_H */

/* eof ********************************************************************/

