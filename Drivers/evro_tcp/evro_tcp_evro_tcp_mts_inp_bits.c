/**************************************************************************
File:               evro_tcp_evro_tcp_mts_inp_bits.c
Author:             Umputun
Creation date:      16/02/2013 - 20:17
Device name:        MTS_INP_BITS
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_tcp_evro_tcp_mts_inp_bits.h>
#include <modbus/modbus.h>
extern modbus_mapping_t *mb_mapping;
/* OEM Parameters */





/****************************************************************************
function    : evro_tcp_evro_tcp_mts_inp_bitsIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_tcp_evro_tcp_mts_inp_bitsIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
)
{
    printf("MODBUS TCP SERVER input_bits INIT\n");
    return (0);
}

/****************************************************************************
function    : evro_tcp_evro_tcp_mts_inp_bitsIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_tcp_evro_tcp_mts_inp_bitsIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{
    printf("MODBUS TCP SERVER input_bits CLOSE\n");

}

/****************************************************************************
function    : evro_tcp_evro_tcp_mts_inp_bitsIosWrite
description : Simple device Write function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to write
return value: None
warning     :
****************************************************************************/

void evro_tcp_evro_tcp_mts_inp_bitsIosWrite
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
)
{
    strRtIoChan*     pChannel;
    strDfIoSplDvc*   pStaticDef;
    uint16           nbChannel;
    uint16           nbIndex;
    uchar*           pPhyData;      /* Physical value */
    uchar*           pLogData;      /* Logic Value */
    uchar            byElecData;    /* Electrical value ('1' or '0') */
    int              okChange;      /* indicate one of the channel has changed */
    pStaticDef =  pRtIoSplDvc->pDfIoSplDvc;
    nbChannel  =  pStaticDef->huNbChan;
    pChannel   =  pRtIoSplDvc->pRtIoChan;
    okChange = 0;
    /* Update all channels */
    for( nbIndex = 0; nbIndex < nbChannel; nbIndex++)
    {
        pPhyData = (uchar*)(pChannel->pvKerPhyData);
        pLogData = (uchar*)(pChannel->pvKerData);

        /* update the channel if not locked  */
        if(!(pChannel->cuIsLocked))
        {
            /* if value has changed or 1rst cycle */
            *pPhyData  = *pLogData;
            byElecData = *pPhyData;

            if ((pChannel->luCnvMult) != 1)    /* If the output is reversed */
            {
                if (*pLogData) byElecData = 0;
                else           byElecData = 1;
            }
            if((uchar*)(pChannel->pfnCnvCall) != 0)
            {
                pChannel->pfnCnvCall( ISA_IO_DIR_OUTPUT, &byElecData, &byElecData);
            }
        }
        else
        {
            byElecData = *pPhyData; /* previous value */
        }

        if (byElecData) mb_mapping->tab_input_bits[nbIndex] = 1;
        else            mb_mapping->tab_input_bits[nbIndex] = 0;
        pChannel++;
    }
}

/****************************************************************************
function    : evro_tcp_evro_tcp_mts_inp_bitsIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_tcp_evro_tcp_mts_inp_bitsIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
)
{
    uchar*        pPhyData;      /* Physical value */
    strRtIoChan*  pChannel;
    uchar         byElecData;    /* Electrical value ('1' or '0') */
    pChannel  = pRtIoSplDvc->pRtIoChan;
    pChannel += huChanNum;
    pPhyData  = (uchar*)(pChannel->pvKerPhyData);

    switch( cuSubFunct)
    {
    case ISA_IO_CTL_CHANLOCK:
        break;
    case ISA_IO_CTL_CHANUNLOCK:
        break;
    case ISA_IO_CTL_CHANOUTFORCE:
        byElecData = *pPhyData;
        /* convert with Gain and/or conversion function */
        if ((pChannel->luCnvMult) != 1)   /* If the output is reversed */
        {
            if (*pPhyData) byElecData = 0;
            else           byElecData = 1;
        }
        if((uchar*)(pChannel->pfnCnvCall) != 0)
        {
            pChannel->pfnCnvCall( ISA_IO_DIR_OUTPUT, &byElecData, &byElecData);
        }
        break;
    }
}