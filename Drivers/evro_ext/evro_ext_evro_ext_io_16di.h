/**************************************************************************
File:               evro_ext_evro_ext_io_16di.h
Author:             Umputun
Creation date:      19/07/2012 - 12:57
Device name:        IO_16DI
***************************************************************************/

#ifndef _EVRO_EXT_EVRO_EXT_IO_16DI_H /* nested Headers management */
#define _EVRO_EXT_EVRO_EXT_IO_16DI_H

/* prototypes */

typSTATUS evro_ext_evro_ext_io_16diIosOpen
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
   );

void evro_ext_evro_ext_io_16diIosClose
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
   );

void evro_ext_evro_ext_io_16diio16diIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_ext_evro_ext_io_16diio16diIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void evro_ext_evro_ext_io_16dimodbusstatusIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_ext_evro_ext_io_16dimodbusstatusIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );




#endif /* _EVRO_EXT_EVRO_EXT_IO_16DI_H */

/* eof ********************************************************************/

