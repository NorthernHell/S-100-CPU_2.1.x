/**************************************************************************
File:               evro_int_evro_int_evro_6rtd_.h
Author:             umputun
Creation date:      21/07/2012 - 20:05
Device name:        EVRO_6rtd_
***************************************************************************/

#ifndef _EVRO_INT_EVRO_INT_EVRO_6RTD__H /* nested Headers management */
#define _EVRO_INT_EVRO_INT_EVRO_6RTD__H

/* prototypes */

typSTATUS evro_int_evro_int_evro_6rtd_IosOpen
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
   );

void evro_int_evro_int_evro_6rtd_IosClose
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
   );

void evro_int_evro_int_evro_6rtd_evro_6rtdIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_int_evro_int_evro_6rtd_evro_6rtdIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void evro_int_evro_int_evro_6rtd_status_mIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_int_evro_int_evro_6rtd_status_mIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );
#endif /* _EVRO_INT_EVRO_INT_EVRO_6rtd__H */

/* eof ********************************************************************/

