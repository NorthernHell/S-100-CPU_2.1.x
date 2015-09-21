/**************************************************************************
File:               Template.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      18-December-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Template of functions for an IO driver

***************************************************************************
Modifications: (who / date / description)
---4.02 Released---
EDS/20-Sep-1999/ 
   Corrected fct name case

***************************************************************************/
#ifndef _TEMPLATE_H /* nested Headers management */
#define _TEMPLATE_H

#include <dios0def.h> /* Nested header required */

/* constants **************************************************************/

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module Template.c *******************************/
extern typSTATUS cjiosmpl_drvnm_IosInit
   (
   strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to init */
   );

extern void cjiosmpl_drvnm_IosExit
   (
   strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to exit */
   );

extern typSTATUS cjiosmpl_drvnm_l1dvcnm_IosOpen
   (
   void* pvRtIoDvc /* Run time io struct of the device to open */
   );

extern void cjiosmpl_drvnm_l1dvcnm_IosClose
   (
   void* pvRtIoDvc /* Run time io struct of the device to close */
   );

extern void cjiosmpl_drvnm_spldvcnm_IosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

extern void cjiosmpl_drvnm_spldvcnm_IosWrite
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
   );

extern void cjiosmpl_drvnm_spldvcnm_IosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */ 
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */ 
   uint16         huChanNum,    /* Channel number if any */ 
   void*          pvReserved    /* Reserved */ 
   );

#endif  /* nested Headers management */
/* eof ********************************************************************/
