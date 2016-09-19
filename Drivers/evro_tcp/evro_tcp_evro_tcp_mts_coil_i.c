/**************************************************************************
File:               evro_tcp_evro_tcp_mts_coil_i.c
Author:             Umputun
Creation date:      16/02/2013 - 20:17
Device name:        MTS_COIL_I
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_tcp_evro_tcp_mts_coil_i.h>
#include <modbus/modbus.h>
extern modbus_mapping_t *mb_mapping;



/****************************************************************************
function    : evro_tcp_evro_tcp_mts_coil_iIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_tcp_evro_tcp_mts_coil_iIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
)
{
    printf("MODBUS TCP SERVER coil_i INIT\n");
    return (0);
}

/****************************************************************************
function    : evro_tcp_evro_tcp_mts_coil_iIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_tcp_evro_tcp_mts_coil_iIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{
    printf("MODBUS TCP SERVER coil_i CLOSE\n");

}

/****************************************************************************
function    : evro_tcp_evro_tcp_mts_coil_iIosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void evro_tcp_evro_tcp_mts_coil_iIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
)
{
    strRtIoChan*        pChannel;
    strDfIoSplDvc*      pStaticDef;
    uint16              nbChannel;
    uint16              nbIndex;

    uchar*              pPhyData;   /* Physical value            */
    uchar*              pLogData;   /* Logical Value               */
    uchar               byElecData; /* Electrical value ('1' or '0') */

    pStaticDef = pRtIoSplDvc->pDfIoSplDvc;
    nbChannel  = pStaticDef->huNbChan;
    pChannel   = pRtIoSplDvc->pRtIoChan;
    /* Update all channels */
    for (nbIndex=0; nbIndex <  nbChannel ; nbIndex++)
    {
        pPhyData = (uchar*)(pChannel->pvKerPhyData);
        pLogData = (uchar*)(pChannel->pvKerData);
        byElecData = mb_mapping->tab_bits[nbIndex];
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
function    : evro_tcp_evro_tcp_mts_coil_iIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_tcp_evro_tcp_mts_coil_iIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
)
{

}
