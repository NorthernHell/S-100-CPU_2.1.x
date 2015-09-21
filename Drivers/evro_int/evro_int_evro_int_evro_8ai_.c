/**************************************************************************
File:               evro_int_evro_int_evro_8ai_.c
Author:             umputun
Creation date:      21/07/2012 - 20:05
Device name:        EVRO_8AI_
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_int_evro_int_evro_8ai_.h>
#include <evro_int_evro_int_evro_8ai.h>
#include <evro_int_evro_int_evro_avar_info.h>
#include <evro_int_evro_int_status_m.h>
/* OEM Parameters of complex device */
int modbus8ai=1;
int id_1;

/* OEM Parameters of linked simple devices */

typedef struct _tag_strEvro_8ai
{
    int32  ID;   /* Node ID */

} strOemParam;

typedef struct _tag_strEvro_avar_info
{
} strEvro_avar_info;



/****************************************************************************
function    : evro_int_evro_int_evro_8ai_IosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoCpxDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_int_evro_int_evro_8ai_IosOpen
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
)
{
    /*
     * Basically, for a complex device the driver can browse all
     * simple devices and perform corressponding initializations.
     * For a simple device it just initializes it.
     */
    strRtIoSplDvc* pRtIoSplDvc;
    pRtIoSplDvc = pvRtIoDvc->pRtIoSplDvc;
	strOemParam* pOemParam;
    pOemParam=(strOemParam*)(pRtIoSplDvc->pvOemParam);
	id_1=pOemParam->ID;
    if (evro_int_evro_int_evro_8aiIosOpen (pRtIoSplDvc) != 0)
    {
        printf("Error opening\n");
        return(BAD_RET);
    }
    pRtIoSplDvc = (strRtIoSplDvc*)(pRtIoSplDvc->pvDrvRtIoDvcNxt);
     if (evro_int_evro_int_evro_avar_infoIosOpen(pRtIoSplDvc) != 0)
    {
        printf("Error opening\n");
        return(BAD_RET);
    }
	if (evro_int_evro_int_status_mIosOpen(pRtIoSplDvc) != 0)
    {
        printf("Error opening\n");
        return(BAD_RET);
    }
    return (0);
}

/****************************************************************************
function    : evro_int_evro_int_evro_8ai_IosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoCpxDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_8ai_IosClose
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{
    strRtIoSplDvc* pRtIoSplDvc;
    pRtIoSplDvc = pvRtIoDvc->pRtIoSplDvc;
    evro_int_evro_int_evro_8aiIosClose (pRtIoSplDvc);
	pRtIoSplDvc = (strRtIoSplDvc*)(pRtIoSplDvc->pvDrvRtIoDvcNxt);
    evro_int_evro_int_evro_avar_infoIosClose(pRtIoSplDvc);
    pRtIoSplDvc = (strRtIoSplDvc*)(pRtIoSplDvc->pvDrvRtIoDvcNxt);
    evro_int_evro_int_status_mIosClose(pRtIoSplDvc);
}

/****************************************************************************
function    : evro_int_evro_int_evro_8ai_evro_8aiIosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_8ai_evro_8aiIosRead
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
    evro_int_evro_int_evro_8aiIosRead(pRtIoSplDvc);
    modbus8ai=pRtIoSplDvc->luUser;
}

/****************************************************************************
function    : evro_int_evro_int_evro_8ai_evro_8aiIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_8ai_evro_8aiIosCtl
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

/****************************************************************************
function    : evro_int_evro_int_evro_8ai_evro_avar_infoIosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_8ai_evro_avar_infoIosRead
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
    pRtIoSplDvc->luUser=id_1;
    evro_int_evro_int_evro_avar_infoIosRead(pRtIoSplDvc);
    modbus8ai=pRtIoSplDvc->luUser;
}

/****************************************************************************
function    : evro_int_evro_int_evro_8ai_evro_avar_infoIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_8ai_evro_avar_infoIosCtl
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


/****************************************************************************
function    : evro_int_evro_int_evro_8ai_status_mIosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_8ai_status_mIosRead
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
    pRtIoSplDvc->luUser=modbus8ai;
    evro_int_evro_int_status_mIosRead(pRtIoSplDvc);
}

/****************************************************************************
function    : evro_int_evro_int_evro_8ai_status_mIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_8ai_status_mIosCtl
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

