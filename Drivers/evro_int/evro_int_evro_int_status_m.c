/**************************************************************************
File:               evro_int_evro_int_status_m.c
Author:             umputun
Creation date:      21/07/2012 - 20:05
Device name:        status_m
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_int_evro_int_status_m.h>

/* OEM Parameters */



/****************************************************************************
function    : evro_int_evro_int_IosInit
description : Driver Init function
parameters  :
   (input) strRtIoDrv* pRtIoDrv :  Run time io struct of the driver to init
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS  evro_int_evro_int_IosInit
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
function    :  evro_int_evro_int_IosExit
description : Driver Exit function
parameters  :
   (input) strRtIoDrv* pRtIoDrv :  Run time io struct of the driver to exit
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_IosExit
(
    strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to exit */
)
{

}

/****************************************************************************
function    : evro_int_evro_int_status_mIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_int_evro_int_status_mIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
)
{
    /*
     * Basically, for a complex device the driver can browse all
     * simple devices and perform corressponding initializations.
     * For a simple device it just initializes it.
     */
    printf("Status init\n");
    return (0);
}

/****************************************************************************
function    : evro_int_evro_int_status_mIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_status_mIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{
    printf("Status Exit\n");
}

/****************************************************************************
function    : evro_int_evro_int_status_mIosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_status_mIosRead
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
    strRtIoChan*        pChannel;
    strDfIoSplDvc*      pStaticDef;
    uint16              nbChannel;
    uint16              nbIndex;

    uchar*              pPhyData;   /* Physical value            */
    uchar*              pLogData;   /* Logical Value               */
    uchar               byElecData; /* Electrical value ('1' or '0') */


    strRtIoCpxDvc *cpxDev=(strRtIoCpxDvc *)pRtIoSplDvc->pvRtIoLevBack; /*  cpxDev->luUser
	- это и будет поле комплексного, которое будет одинаково и доступно для всех простых
	в составе этого комплесного  */


    pStaticDef = pRtIoSplDvc->pDfIoSplDvc;
    nbChannel  = pStaticDef->huNbChan;
    pChannel   = pRtIoSplDvc->pRtIoChan;
    /* Update all channels */
    for (nbIndex=0; nbIndex <  nbChannel ; nbIndex++)
    {
        pPhyData = (uchar*)(pChannel->pvKerPhyData);
        pLogData = (uchar*)(pChannel->pvKerData);


        byElecData = cpxDev->luUser;

        if((pChannel->pfnCnvCall) != 0)           /* If there is a conversion */
            pChannel->pfnCnvCall( ISA_IO_DIR_INPUT, &byElecData, &byElecData);


        if((pChannel->luCnvMult) != 1)            /* If the input is reversed */
        {
            if( *pPhyData == byElecData) /* If Physic value = Electrical value */
            {
                /* printf ("Input value - channel %d has changed\n",nbIndex); */
                if( byElecData) *pPhyData =0; /* Logic value != Physic value */
                else            *pPhyData =1;
            }
        }
        else                          /* If the input is direct */
        {
            if( byElecData != *pPhyData)
            {
                /* printf ("Input value - channel %d has changed\n",nbIndex); */
                *pPhyData = byElecData;
            }
        }
        /* update the channel if not locked */
        if (!(pChannel->cuIsLocked))  *pLogData = *pPhyData;

        pChannel++;
    }


}

/****************************************************************************
function    : evro_int_evro_int_status_mIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_status_mIosCtl
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