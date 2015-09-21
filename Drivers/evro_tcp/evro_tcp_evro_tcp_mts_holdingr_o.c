/**************************************************************************
File:               evro_tcp_evro_tcp_mts_holdingr_o.c
Author:             Umputun
Creation date:      16/02/2013 - 20:17
Device name:        MTS_HOLDINGR_O
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_tcp_evro_tcp_mts_holdingr_o.h>
#include <modbus/modbus.h>
extern modbus_mapping_t *mb_mapping;
/* OEM Parameters */




/****************************************************************************
function    : evro_tcp_evro_tcp_mts_holdingr_oIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_tcp_evro_tcp_mts_holdingr_oIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
)
{
    printf("MODBUS TCP SERVER holding_o INIT\n");
    pvRtIoDvc->luUser = 1;
    return (0);
}

/****************************************************************************
function    : evro_tcp_evro_tcp_mts_holdingr_oIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_tcp_evro_tcp_mts_holdingr_oIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{
    printf("MODBUS TCP SERVER holding_o CLOSE\n");

}

/****************************************************************************
function    : evro_tcp_evro_tcp_mts_holdingr_oIosWrite
description : Simple device Write function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to write
return value: None
warning     :
****************************************************************************/

void evro_tcp_evro_tcp_mts_holdingr_oIosWrite
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
)
{
////
    strRtIoChan*     pChannel;
    strDfIoSplDvc*   pStaticDef;
    uint16           nbChannel;
    uint16           nbIndex;

    uint16*           pPhyData;  /* Physical value */
    uint16*           pLogData;  /* Logic Value */
    uint16            iElecData; /* Electrical value */
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
            pPhyData = (uint16*)(pChannel->pvKerPhyData);
            pLogData = (uint16*)(pChannel->pvKerData);
            okChange = 0;
            /* if value has changed or 1rst cycle */
            if( *pLogData != *pPhyData || pRtIoSplDvc->luUser)
            {
                okChange = 1;
                printf("holding change");
            }
            *pPhyData = *pLogData; /* Logic value = Physic Value */

            if((pChannel->pfnCnvCall) != 0) /* If there is a cnv */
                pChannel->pfnCnvCall( ISA_IO_DIR_OUTPUT, pPhyData, &iElecData);
            else
                iElecData = *pPhyData;

            /* Apply gain and offset  */
            if (pChannel->luCnvDiv != 0)
                iElecData = ((iElecData) * (uint16)(pChannel->luCnvMult)
                             / (uint16)(pChannel->luCnvDiv)) + (uint16)(pChannel->luCnvOfs);

            /* If the variable has changed, we print in the file the new value */
            if (okChange)
            {
                mb_mapping->tab_registers[nbIndex]=iElecData;
                iCountChange++;
            }
        }
        pChannel++; /* Go to the next channel */
    }
    pRtIoSplDvc->luUser = 0; /* first call to Write has been done */
/////
}

/****************************************************************************
function    : evro_tcp_evro_tcp_mts_holdingr_oIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_tcp_evro_tcp_mts_holdingr_oIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
)
{
    uint16*        pPhyData;      /* Physical value */
    strRtIoChan*  pChannel;
    uint16         iElecData;     /* Electrical value */
    pChannel  =  pRtIoSplDvc->pRtIoChan;
    pChannel += huChanNum;
    pPhyData  = (uint16*)(pChannel->pvKerPhyData);

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
            iElecData = ((iElecData) * (uint16)(pChannel->luCnvMult)
                         / (uint16)(pChannel->luCnvDiv)) + (uint16)(pChannel->luCnvOfs);
////
        break;
    }


}
