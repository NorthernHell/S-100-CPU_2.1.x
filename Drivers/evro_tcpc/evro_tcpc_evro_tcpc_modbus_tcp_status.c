/**************************************************************************
File:               evro_tcpc_evro_tcpc_modbus_tcp_status.c
Author:             Umputun
Creation date:      25/02/2013 - 16:08
Device name:        MODBUS_TCP_STATUS
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_tcpc_evro_tcpc_modbus_tcp_status.h>


/****************************************************************************
function    : evro_tcpc_evro_tcpc_modbus_tcp_statusIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_tcpc_evro_tcpc_modbus_tcp_statusIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
)
{
    printf("Modbus status init\n");
    return (0);
}

/****************************************************************************
function    : evro_tcpc_evro_tcpc_modbus_tcp_statusIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_tcpc_evro_tcpc_modbus_tcp_statusIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{

}

/****************************************************************************
function    : evro_tcpc_evro_tcpc_modbus_tcp_statusIosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void evro_tcpc_evro_tcpc_modbus_tcp_statusIosRead
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
function    : evro_tcpc_evro_tcpc_modbus_tcp_statusIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_tcpc_evro_tcpc_modbus_tcp_statusIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
)
{

}