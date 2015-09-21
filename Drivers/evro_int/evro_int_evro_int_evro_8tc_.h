/**************************************************************************
File:               evro_int_evro_int_evro_8tc_.h
Author:             umputun
Creation date:      21/07/2012 - 20:05
Device name:        EVRO_8tc_
***************************************************************************/

#ifndef _EVRO_INT_EVRO_INT_EVRO_8TC__H /* nested Headers management */
#define _EVRO_INT_EVRO_INT_EVRO_8TC__H

/* prototypes */

typSTATUS evro_int_evro_int_evro_8tc_IosOpen
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
   );

void evro_int_evro_int_evro_8tc_IosClose
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
   );

void evro_int_evro_int_evro_8tc_evro_8tcIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_int_evro_int_evro_8tc_evro_8tcIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void evro_int_evro_int_evro_8tc_status_mIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_int_evro_int_evro_8tc_status_mIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );
#endif /* _EVRO_INT_EVRO_INT_EVRO_8TC__H */

/* eof ********************************************************************/

