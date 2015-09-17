/**************************************************************************
File:               fdaserv.h
Author:             Lipovets
Creation date:      15/10/2007 - 16:07
Device name:        FDA_serv
***************************************************************************/

#ifndef _FDASERV_H /* nested Headers management */
#define _FDASERV_H

#include <dsys0def.h>
#include <dios0def.h>

/* prototypes */

typSTATUS  rtservIosInit
   (
   strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to init */
   );

void rtservIosExit
   (
   strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to exit */
   );

typSTATUS rtservfda_servIosOpen
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
   );

void rtservfda_servIosClose
   (
   strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
   );


typSTATUS rtservIosMdf
   (
   uchar          cuSubFunc,    /* Sub function switch */
   strRtIoDrv*    pRtIoDrv,     /* Driver run time io struct */
   uint32         luMdfType,    /* On line modification types */
   void*          pvRtIoDvc     /* Reserved for future extensions */
   );

typSTATUS rtservfda_servIosMdf
   (
   uchar          cuSubFunc,   /* Sub function switch */
   strRtIoCpxDvc* pRtIoCpxDvc, /* Complex device run time io struct */
   uint32         luMdfType,   /* On line modification types */
   strDfIoCpxDvc* pDfIoCpxDvc, /* New complex device default struct */
   void*          pvOemParam   /* New complex device OEM parameters */
   );



#endif /* _FDASERV_H */

/* eof ********************************************************************/

