/**************************************************************************
File:               evro_ext_evro_ext_m_do.h
Author:             Umputun
Creation date:      19/07/2012 - 11:31
Device name:        M_DO
***************************************************************************/

#ifndef _EVRO_EXT_EVRO_EXT_M_DO_H /* nested Headers management */
#define _EVRO_EXT_EVRO_EXT_M_DO_H

/* prototypes */

typSTATUS  evro_ext_evro_ext_IosInit
(
    strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to init */
);

void evro_ext_evro_ext_IosExit
(
    strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to exit */
);

typSTATUS evro_ext_evro_ext_m_doIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
);

void evro_ext_evro_ext_m_doIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
);

void evro_ext_evro_ext_m_doIosWrite
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
);

void evro_ext_evro_ext_m_doIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
);
#endif /* _EVRO_EXT_EVRO_EXT_M_DO_H */

/* eof ********************************************************************/

