/**************************************************************************
File:               evro_ext_evro_ext_io_8ai.h
Author:             Umputun
Creation date:      19/07/2012 - 12:57
Device name:        IO_8AI
***************************************************************************/

#ifndef _EVRO_EXT_EVRO_EXT_IO_8AI_H /* nested Headers management */
#define _EVRO_EXT_EVRO_EXT_IO_8AI_H

/* prototypes */

typSTATUS evro_ext_evro_ext_io_8aiIosOpen
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
   );

void evro_ext_evro_ext_io_8aiIosClose
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
   );

void evro_ext_evro_ext_io_8aiio8aiIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_ext_evro_ext_io_8aiio8aiIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void evro_ext_evro_ext_io_8aimodbusstatusIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_ext_evro_ext_io_8aimodbusstatusIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );


#endif

/* eof ********************************************************************/

