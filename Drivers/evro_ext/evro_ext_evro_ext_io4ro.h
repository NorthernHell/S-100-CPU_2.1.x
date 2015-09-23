/**************************************************************************
File:               evro_ext_evro_ext_io4ro.h
Author:             Umputun
Creation date:      19/07/2012 - 11:31
Device name:        IO4RO
***************************************************************************/

#ifndef _EVRO_EXT_EVRO_EXT_IO4RO_H /* nested Headers management */
#define _EVRO_EXT_EVRO_EXT_IO4RO_H

/* prototypes */


typSTATUS evro_ext_evro_ext_io4roIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_ext_evro_ext_io4roIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_ext_evro_ext_io4roIosWrite
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
);

void evro_ext_evro_ext_io4roIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);



#endif /* _EVRO_EXT_EVRO_EXT_IO4RO_H */

/* eof ********************************************************************/

