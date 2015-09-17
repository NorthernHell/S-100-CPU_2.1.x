/**************************************************************************
File:               modbus_rtu_holding_o_.c
Author:             Umputun
Creation date:      20/02/2013 - 12:46
Device name:        MODBUS_RTU_HOLDING_O_
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <modbus_rtu_holding_o_.h>
#include <modbus/modbus.h>
extern modbus_mapping_t *mb_mapping_rtu;
/* OEM Parameters */





/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_holding_o_IosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS _evro_rtus_evro_rtusmodbus_rtu_holding_o_IosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
)
{
    /*
     * Basically, for a complex device the driver can browse all
     * simple devices and perform corressponding initializations.
     * For a simple device it just initializes it.
     */
    printf("MODBUS RTU SERVER holding_o INIT\n");
    pvRtIoDvc->luUser = 1;
    return (0);
}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_holding_o_IosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_holding_o_IosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{
    printf("MODBUS RTU SERVER holding_o CLOSE\n");
}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_holding_o_IosWrite
description : Simple device Write function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to write
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_holding_o_IosWrite
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
)
{
    strRtIoChan*     pChannel;
    strDfIoSplDvc*   pStaticDef;
    uint16           nbChannel;
    uint16           nbIndex;

    int32*           pPhyData;  /* Physical value */
    int32*           pLogData;  /* Logic Value */
    int32            iElecData; /* Electrical value */
    int              iCountChange =0, okChange;
    pStaticDef =  pRtIoSplDvc->pDfIoSplDvc;
    nbChannel  =  pStaticDef->huNbChan;
    pChannel   =  pRtIoSplDvc->pRtIoChan;
    /* Update all channel  */
    for( nbIndex = 0; nbIndex < nbChannel; nbIndex++)
    {
        /* update the channel if not locked  */
        if(!(pChannel->cuIsLocked))
        {
            pPhyData = (int32*)(pChannel->pvKerPhyData);
            pLogData = (int32*)(pChannel->pvKerData);
            okChange = 0;
            /* if value has changed or 1rst cycle */
            if( *pLogData != *pPhyData || pRtIoSplDvc->luUser)
            {
                okChange = 1;
            }
            *pPhyData = *pLogData; /* Logic value = Physic Value */

            if((pChannel->pfnCnvCall) != 0) /* If there is a cnv */
                pChannel->pfnCnvCall( ISA_IO_DIR_OUTPUT, pPhyData, &iElecData);
            else
                iElecData = *pPhyData;

            /* Apply gain and offset  */
            if (pChannel->luCnvDiv != 0)
                iElecData = ((iElecData) * (int32)(pChannel->luCnvMult)
                             / (int32)(pChannel->luCnvDiv)) + (int32)(pChannel->luCnvOfs);

            /* If the variable has changed, we print in the file the new value */
            if (okChange)
            {
                mb_mapping_rtu->tab_registers[nbIndex]=iElecData;
                iCountChange++;
            }
        }
        pChannel++; /* Go to the next channel */
    }
    pRtIoSplDvc->luUser = 0; /* first call to Write has been done */
}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_holding_o_IosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_holding_o_IosCtl
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
    int32*        pPhyData;      /* Physical value */
    strRtIoChan*  pChannel;
    int32         iElecData;     /* Electrical value */
    pChannel  =  pRtIoSplDvc->pRtIoChan;
    pChannel += huChanNum;
    pPhyData  = (int32*)(pChannel->pvKerPhyData);

    switch( cuSubFunct)
    {
    case ISA_IO_CTL_CHANLOCK:
        break;
    case ISA_IO_CTL_CHANUNLOCK:
        break;
    case ISA_IO_CTL_CHANOUTFORCE:
        if((pChannel->pfnCnvCall) != 0) /* If there is a cnv */
            pChannel->pfnCnvCall( ISA_IO_DIR_OUTPUT, pPhyData, &iElecData);
        else
            iElecData = *pPhyData;
        /* Apply gain and offset  */
        if (pChannel->luCnvDiv != 0)
            iElecData = ((iElecData) * (int32)(pChannel->luCnvMult)
                         / (int32)(pChannel->luCnvDiv)) + (int32)(pChannel->luCnvOfs);
////
        break;
    }

}
/* eof ********************************************************************/

