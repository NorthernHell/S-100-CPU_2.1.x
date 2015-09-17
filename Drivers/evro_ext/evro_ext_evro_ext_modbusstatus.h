/**************************************************************************
File:               evro_ext_evro_ext_modbusstatus.h
Author:             Umputun
Creation date:      19/07/2012 - 11:31
Device name:        modbusstatus
***************************************************************************/

#ifndef _EVRO_EXT_EVRO_EXT_MODBUSSTATUS_H /* nested Headers management */
#define _EVRO_EXT_EVRO_EXT_MODBUSSTATUS_H

/* prototypes */


typSTATUS evro_ext_evro_ext_modbusstatusIosOpen
   (
   strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
   );

void evro_ext_evro_ext_modbusstatusIosClose
   (
   strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
   );

void evro_ext_evro_ext_modbusstatusIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void evro_ext_evro_ext_modbusstatusIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );


#endif /* _EVRO_EXT_EVRO_EXT_MODBUSSTATUS_H */

/* eof ********************************************************************/

