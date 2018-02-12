/**************************************************************************
File:               evro_int_evro_int_evro_4ao.c
Author:             Umputun
Creation date:      21/07/2012 - 14:25
Device name:        EVRO_4AO
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_int_evro_int_evro_4ao.h>
#include "modbus/modbus.h"

/* OEM Parameters */

typedef struct _tag_strEvro_4ao
{
    int32  ID;   /* Node ID */
    int32  NCOM;   /* COM port number */
} strOemParam;


/****************************************************************************
function    : evro_int_evro_int_evro_4aoIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_int_evro_int_evro_4aoIosOpen
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
)
{   /*
     * Basically, for a complex device the driver can browse all
     * simple devices and perform corressponding initializations.
     * For a simple device it just initializes it.
     */
    strRtIoCpxDvc *cpxDev=(strRtIoCpxDvc *)pRtIoSplDvc->pvRtIoLevBack;
    strOemParam *oemCPar=(strOemParam *)cpxDev->pvOemParam;
    printf("EVRO 4AO init\n");
    
    modbus_t *ctx;
    if (oemCPar->NCOM==1) {ctx = modbus_new_rtu("/dev/ttySAC0", 230400, 'N', 8, 1);}
    if (oemCPar->NCOM==2) {ctx = modbus_new_rtu("/dev/ttySAC1", 230400, 'N', 8, 1);}
    if (oemCPar->NCOM==3) {ctx = modbus_new_rtu("/dev/ttySAC2", 230400, 'N', 8, 1);}

    int rc;
    uint16_t tab_reg[33];
    struct timeval response_timeout;
    response_timeout.tv_sec = 0;
    response_timeout.tv_usec = 20000;
    modbus_set_slave(ctx, oemCPar->ID);
    if (modbus_connect(ctx) == -1)
    {
     //   printf("Connexion failed: \n");
        modbus_free(ctx);
    }
    else
    {
        modbus_set_response_timeout(ctx, &response_timeout);

        if (rc == -1)
        {
            cpxDev->luUser =0;
        }
        else
        {
            cpxDev->luUser =1;
        }
        modbus_close(ctx);
        modbus_free(ctx);
    }

    return (0);
}

/****************************************************************************
function    : evro_int_evro_int_evro_4aoIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_4aoIosClose
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
)
{
    printf("EVRO 4AO Exit\n");
}

/****************************************************************************
function    : evro_int_evro_int_evro_4aoIosWrite
description : Simple device Write function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to write
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_4aoIosWrite
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
    strRtIoCpxDvc *cpxDev=(strRtIoCpxDvc *)pRtIoSplDvc->pvRtIoLevBack;
    strOemParam *oemCPar=(strOemParam *)cpxDev->pvOemParam;
    strRtIoChan*     pChannel;
    strDfIoSplDvc*   pStaticDef;
    uint16           nbChannel;
    uint16           nbIndex;
    uint16_t tab_reg[128];

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
            *pPhyData = *pLogData; /* Logic value = Physic Value */

            if((pChannel->pfnCnvCall) != 0) /* If there is a cnv */
                pChannel->pfnCnvCall( ISA_IO_DIR_OUTPUT, pPhyData, &iElecData);
            else
                iElecData = *pPhyData;

            /* Apply gain and offset  */
            if (pChannel->luCnvDiv != 0)
                iElecData = ((iElecData) * (uint16)(pChannel->luCnvMult)
                             / (uint16)(pChannel->luCnvDiv)) + (uint16)(pChannel->luCnvOfs);
            tab_reg[nbIndex]=iElecData;
            /* If the variable has changed, we print in the file the new value */
            if (okChange)
            {
                tab_reg[nbIndex]=iElecData;
                iCountChange++;
            }
        }
        pChannel++; /* Go to the next channel */
    }
    /* if at least one channel has changed */

    /*  pFile = fopen( sFileName, "at");
    printf( "%s\n", sNewMsg);
    fclose( pFile);
    */
    modbus_t *ctx;
    if (oemCPar->NCOM==1) {ctx = modbus_new_rtu("/dev/ttySAC0", 230400, 'N', 8, 1);}
    if (oemCPar->NCOM==2) {ctx = modbus_new_rtu("/dev/ttySAC1", 230400, 'N', 8, 1);}
    if (oemCPar->NCOM==3) {ctx = modbus_new_rtu("/dev/ttySAC2", 230400, 'N', 8, 1);}
    int rc;
    struct timeval response_timeout;
    response_timeout.tv_sec = 0;
    response_timeout.tv_usec = 20000;
    modbus_set_slave(ctx,  oemCPar->ID);
    if (modbus_connect(ctx) == -1)
    {
       // printf("Connexion failed: \n");
        modbus_free(ctx);
    }
    else
    {
        modbus_set_response_timeout(ctx, &response_timeout);
        rc  = modbus_write_registers(ctx, 40000, 4, tab_reg);

        if (rc == -1)
        {
            cpxDev->luUser =0;
        }
        else
        {
            cpxDev->luUser =1;
        };
        modbus_close(ctx);
        modbus_free(ctx);
    };
}

/****************************************************************************
function    : evro_int_evro_int_evro_4aoIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_4aoIosCtl
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
        break;
    }

}
/* eof ********************************************************************/

