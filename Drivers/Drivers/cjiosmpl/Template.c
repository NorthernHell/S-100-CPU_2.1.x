/**************************************************************************
File:               Template.c
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
   Added template.h include, corrected fct name case, added typical 
    implem comments

***************************************************************************/
#include <dsys0def.h>
#include <dios0def.h>
#include <Template.h>


/* constants **************************************************************/

/* types ******************************************************************/

/* static data ************************************************************/

/* exported data [NOT RECOMMENDED!] ***************************************/

/* imported data [NOT RECOMMENDED!] ***************************************/

/* callback services implemented in this file *****************************/

/* exported services ******************************************************/

/* imported services ******************************************************/

/* static services ********************************************************/



/****************************************************************************
function    : cjiosmpl_drvnm_IosInit
description : Driver Init function 
parameters  :
   (input) strRtIoDrv* pRtIoDrv :  Run time io struct of the driver to init
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/
typSTATUS  cjiosmpl_drvnm_IosInit
   (
   strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to init */
   )
{
   /*
    * Basically, the driver can browse all 
    * used devices and perform a global initialization
    */
   return (0);
}

/****************************************************************************
function    :  cjiosmpl_drvnm_IosExit
description : Driver Exit function 
parameters  :
   (input) strRtIoDrv* pRtIoDrv :  Run time io struct of the driver to exit
return value: None
warning     : 
****************************************************************************/
void cjiosmpl_drvnm_IosExit
   (
   strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to exit */
   )
{
   /*
    * This is the reverse of the previous function
    */
}

/****************************************************************************
function    : cjiosmpl_drvnm_l1dvcnm_IosOpen
description : Level 1 device Open function 
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
Note        :
   - Level 1 devices can be simple or complex. 
      The 'l1dvcnm' must be replaced with the corresponding simple or complex
      device name.
      The void* parameter may be replaced with the exact type of the device 
      according to if it is simple or complex.
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/
typSTATUS cjiosmpl_drvnm_l1dvcnm_IosOpen
   (
   void* pvRtIoDvc /* Run time io struct of the device to open */
   )
{
   /*
    * Basically, for a complex device the driver can browse all 
    * simple devices and perform corressponding initializations.
    * For a simple device it just initializes it.
    */
   return (0);
}

/****************************************************************************
function    : cjiosmpl_drvnm_l1dvcnm_IosClose
description : Level 1 device Close function 
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to close
return value: None
Note        :
   - Level 1 devices can be simple or complex. 
      The 'l1dvcnm' must be replaced with the corresponding simple or complex
      device name.
      The void* parameter may be replaced with the exact type of the device 
      according to if it is simple or complex.
warning     : 
****************************************************************************/
void cjiosmpl_drvnm_l1dvcnm_IosClose
   (
   void* pvRtIoDvc /* Run time io struct of the device to close */
   )
{
   /*
    * This is the reverse of the previous function
    */
}

/****************************************************************************
function    : cjiosmpl_drvnm_spldvcnm_IosRead
description : Simple device Read function 
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
Note        :
   - Obviously such function is meaningful only for input devices.
   - If the simple device is within a complex device, "SplDvcNm" within the
      function name is composed of the complex device name concatenated with
      the simple device name.
warning     : 
****************************************************************************/
void cjiosmpl_drvnm_spldvcnm_IosRead
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
   )
{
   /*
    * pRtIoSplDvc parameter allows you to access to strRtIoChan structure
    *  of information for each channel.
    * If required you can then also get strDfIoChan structure.
    *
    * Typical implementation for each channel:
    * (variables refer to structure fields):
        - Get input electrical value from sensor
        - If a conversion is required, convert it
          The info is in channel structures in following fields:
             cuCnvGainTyp != 0 ==> Gain/Offset to applied
             pfnCnvCall != 0   ==> 'C' conversion to applied
        - Update physical data (pvKerPhyData) with computed value 
        - If not locked (cuIsLocked) also update logical data (pvKerData)
    */
  
   /*
    * To improve performances, the number of locked channels is given to 
    * avoid testing each of them when no channels are locked or when all 
    * channels are locked.
    */
}

/****************************************************************************
function    : cjiosmpl_drvnm_spldvcnm_IosWrite
description : Simple device Write function 
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to write
return value: None
Note        :
   - Obviously such function is meaningful only for ouput devices.
   - If the simple device is within a complex device, "SplDvcNm" within the
      function name is composed of the complex device name concatenated with
      the simple device name.
warning     : 
****************************************************************************/
void cjiosmpl_drvnm_spldvcnm_IosWrite
   (
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
   )
{
   /*
    * pRtIoSplDvc parameter allows you to access to strRtIoChan structure
    *  of information for each channel.
    * If required you can then also get strDfIoChan structure.
    *
    * Typical implementation for each channel: 
    * (variables refer to structure fields):
        - If not locked (cuIsLocked)
           - Update physical data (pvKerPhyData) with logical data (pvKerData)
           - If a conversion is required, convert the data
             The info is in channel structures in following fields:
                cuCnvGainTyp != 0 ==> Gain/Offset to applied
                pfnCnvCall != 0   ==> 'C' conversion to applied
           - Apply just computed electrical value to the actuator
    */
  
   /*
    * To improve performances:
    * - The number of locked channels is given to avoid testing each of them
    *   when no channels are locked or when all channels are locked.
    *
    * - When a channel is not locked (update required), the physical data can
    *   be used as a previous value and compared to the logical data. 
    *   This allows to apply the electrical value to the actuator only in case
    *   of change detection. This is especially interesting in case of time 
    *   consuming hardware access (remote I/Os, network, etc.). 
    *   Then do not forget to update the physical data with the logical data
    */
}

/****************************************************************************
function    : cjiosmpl_drvnm_spldvcnm_IosCtl
description : Simple device Control function 
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter. 
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any. 
   (input) void* pvReserved :          Reserved. 
return value: None
Note        :
   - If the simple device is within a complex device, "SplDvcNm" within the
      function name is composed of the complex device name concatenated with
      the simple device name.
warning     : 
****************************************************************************/
void cjiosmpl_drvnm_spldvcnm_IosCtl
   (
   uchar          cuSubFunct,   /* Sub function parameter */ 
   strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */ 
   uint16         huChanNum,    /* Channel number if any */ 
   void*          pvReserved    /* Reserved */ 
   )  
{
   /*
    * cuSubFunct parameter gives a function code.
    * An important one is ISA_IO_CTL_CHANOUTFORCE to force the output
    *  specified by huChanNum.
    * In this case a typical implementation is:
       - if cuSubFunct equal ISA_IO_CTL_CHANOUTFORCE
          - If a conversion is required, convert physical data (pvKerPhyData)
            The info is in channel structures in following fields:
               cuCnvGainTyp != 0 ==> Gain/Offset to applied
               pfnCnvCall != 0   ==> 'C' conversion to applied
          - Apply just computed electrical value to the actuator
    */
}

/* eof ********************************************************************/
