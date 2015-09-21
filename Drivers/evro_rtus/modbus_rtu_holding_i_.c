/**************************************************************************
File:               modbus_rtu_holding_i_.c
Author:             Umputun
Creation date:      20/02/2013 - 12:46
Device name:        MODBUS_RTU_HOLDING_I_
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <modbus_rtu_holding_i_.h>
#include <modbus/modbus.h>
extern modbus_mapping_t *mb_mapping_rtu;
/* OEM Parameters */





/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_holding_i_IosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS _evro_rtus_evro_rtusmodbus_rtu_holding_i_IosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
)
{
    /*
     * Basically, for a complex device the driver can browse all
     * simple devices and perform corressponding initializations.
     * For a simple device it just initializes it.
     */
    printf("MODBUS RTU SERVER holding_i INIT\n");
    return (0);
}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_holding_i_IosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_holding_i_IosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{
    printf("MODBUS RTU SERVER holding_i CLOSE\n");
}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_holding_i_IosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_holding_i_IosRead
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

    uint16*              pPhyData;   /* Physical value */
    uint16*              pLogData;   /* Logical Value    */
    uint16               fElecData;
    float               fMult,fDiv,fOffset;
    pStaticDef =  pRtIoSplDvc->pDfIoSplDvc;
    nbChannel  =  pStaticDef->huNbChan;
    pChannel   =  pRtIoSplDvc->pRtIoChan;
    /*  Update all channel */
    for( nbIndex = 0; nbIndex < nbChannel; nbIndex++)
    {
        pPhyData = (uint16*)(pChannel->pvKerPhyData);
        pLogData = (uint16*)(pChannel->pvKerData);

        fElecData=mb_mapping_rtu->tab_registers[nbIndex];
        if((pChannel->pfnCnvCall) != 0) /* If there is a conversion */
        {
            pChannel->pfnCnvCall( ISA_IO_DIR_INPUT, &fElecData, &fElecData);
        }
        fMult   = *(float *)(&(pChannel->luCnvMult));
        fDiv    = *(float *)(&(pChannel->luCnvDiv ));
        fOffset = *(float *)(&(pChannel->luCnvOfs));
        if (fDiv != 0.0)
            fElecData = ((fElecData) * fMult  / fDiv) + fOffset;
        if( *pPhyData != fElecData) /* If Physic value != Electrical value */
        {
            *pPhyData = fElecData;
        }


        /* update the channel if not locked */
        if(!(pChannel->cuIsLocked))  *pLogData = *pPhyData;

        pChannel++;
    }
}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_holding_i_IosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_holding_i_IosCtl
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

