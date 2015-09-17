/**************************************************************************
File:               evro_ext_evro_ext_io_8aii.h
Author:             Umputun
Creation date:      19/07/2012 - 12:57
Device name:        IO_8AII
***************************************************************************/

#ifndef _EVRO_EXT_EVRO_EXT_IO_8AII_H /* nested Headers management */
#define _EVRO_EXT_EVRO_EXT_IO_8AII_H

/* prototypes */

typSTATUS evro_ext_evro_ext_io_8aiiIosOpen
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
   );

void evro_ext_evro_ext_io_8aiiIosClose
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
   );

void evro_ext_evro_ext_io_8aiiio8aiiIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_ext_evro_ext_io_8aiiio8aiiIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void evro_ext_evro_ext_io_8aiimodbusstatusIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_ext_evro_ext_io_8aiimodbusstatusIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );


#endif

/* eof ********************************************************************/

