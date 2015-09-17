/**************************************************************************
File:               evro_ext_evro_ext_io_4ro.h
Author:             Umputun
Creation date:      19/07/2012 - 12:57
Device name:        IO_4RO
***************************************************************************/

#ifndef _EVRO_EXT_EVRO_EXT_IO_4RO_H /* nested Headers management */
#define _EVRO_EXT_EVRO_EXT_IO_4RO_H

/* prototypes */

typSTATUS evro_ext_evro_ext_io_4roIosOpen
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
   );

void evro_ext_evro_ext_io_4roIosClose
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
   );

void evro_ext_evro_ext_io_4roio4roIosWrite
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
   );

void evro_ext_evro_ext_io_4roio4roIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void evro_ext_evro_ext_io_4romodbusstatusIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_ext_evro_ext_io_4romodbusstatusIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );
   #endif