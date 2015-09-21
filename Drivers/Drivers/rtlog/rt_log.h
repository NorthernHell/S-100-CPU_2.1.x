/**************************************************************************
File:               rtlog.h
Author:             Alex
Creation date:      19/01/2006 - 16:29
Device name:        rtlog
***************************************************************************/

#ifndef _RTLOG_H /* nested Headers management */
#define _RTLOG_H

#include <dsys0def.h>
#include <dios0def.h>

/* prototypes */

typSTATUS  rtlogsIosInit
   (
   strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to init */
   );

void rtlogsIosExit
   (
   strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to exit */
   );

typSTATUS rtlogsrtlogIosOpen
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
   );

void rtlogsrtlogIosClose
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
   );

void rtlogsrtlogcontrolIosWrite
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
   );

void rtlogsrtlogcontrolIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void rtlogsrtlogstateIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void rtlogsrtlogstateIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );

void rtlogsrtloginIosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   );

void rtlogsrtloginIosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
   uint16         huChanNum,    /* Channel number if any */
   void*          pvReserved    /* Reserved */
   );




typSTATUS rtlogsIosMdf
   (
   uchar          cuSubFunc,    /* Sub function switch */
   strRtIoDrv*    pRtIoDrv,     /* Driver run time io struct */
   uint32         luMdfType,    /* On line modification types */
   void*          pvRtIoDvc     /* Reserved for future extensions */
   );

typSTATUS rtlogsrtlogIosMdf
   (
   uchar          cuSubFunc,   /* Sub function switch */
   strRtIoCpxDvc* pRtIoCpxDvc, /* Complex device run time io struct */
   uint32         luMdfType,   /* On line modification types */
   strDfIoCpxDvc* pDfIoCpxDvc, /* New complex device default struct */
   void*          pvOemParam   /* New complex device OEM parameters */
   );

typSTATUS rtlogsrtlogcontrolIosMdf
   (
   uchar          cuSubFunc,  /* Sub function switch */
   strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
   uint32         luMdfType,  /* On line modification types */
   strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
   void*          pvOemSplDvc,/* New simple device OEM parameters */
   strDfIoChan*   pDfIoChan,  /* New first channel default struct */
   void*          pvOemChan   /* New first channel OEM parameters */
   );

typSTATUS rtlogsrtlogstateIosMdf
   (
   uchar          cuSubFunc,  /* Sub function switch */
   strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
   uint32         luMdfType,  /* On line modification types */
   strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
   void*          pvOemSplDvc,/* New simple device OEM parameters */
   strDfIoChan*   pDfIoChan,  /* New first channel default struct */
   void*          pvOemChan   /* New first channel OEM parameters */
   );



#endif /* _RTLOG_H */

/* eof ********************************************************************/

