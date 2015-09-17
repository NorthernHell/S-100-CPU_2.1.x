/**************************************************************************
File:               evro_tcpc_evro_tcpc_mtcp_do.c
Author:             Umputun
Creation date:      25/02/2013 - 16:08
Device name:        MTCP_DO
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_tcpc_evro_tcpc_mtcp_do.h>
#include <modbus/modbus.h>
/* OEM Parameters */
extern int modbus_tcp_dos;

typedef struct _tag_strMtcp_do
{
    char   IP[16];
    int32  PORT;
    int32  Adress;
    int32  NR;
    int32  TimeOutu;
    int32  TimeOutsec;
} strMtcp_do;


/****************************************************************************
function    : evro_tcpc_evro_tcpc_mtcp_doIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_tcpc_evro_tcpc_mtcp_doIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
)
{
    printf("MB TCPC DO init\n");
    return (0);
}

/****************************************************************************
function    : evro_tcpc_evro_tcpc_mtcp_doIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_tcpc_evro_tcpc_mtcp_doIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{

}

/****************************************************************************
function    : evro_tcpc_evro_tcpc_mtcp_doIosWrite
description : Simple device Write function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to write
return value: None
warning     :
****************************************************************************/

void evro_tcpc_evro_tcpc_mtcp_doIosWrite
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
    uint8_t            sNewMsg[150];
    int              okChange;      /* indicate one of the channel has changed */
    strMtcp_do* pOemParam;
    pOemParam=(strMtcp_do*)(pRtIoSplDvc->pvOemParam);
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

        if (byElecData) sNewMsg[nbIndex] = 1;
        else            sNewMsg[nbIndex] = 0;
        pChannel++;
    }
    sNewMsg[ nbChannel] = 0; /* null char at the end of the string */
    /* If one variable has changed, we print in the file the new values */
    modbus_t *ctx;
    int rc;
    struct timeval response_timeout;
    response_timeout.tv_sec = pOemParam->TimeOutsec;
    response_timeout.tv_usec = pOemParam->TimeOutu;
    ctx = modbus_new_tcp(pOemParam->IP, pOemParam->PORT); //connect
    if (modbus_connect(ctx) == -1)
    {
        printf("Connexion failed: \n");
        modbus_tcp_dos=0;
        modbus_free(ctx);
    }
    else
    {
        modbus_tcp_dos=1;
        modbus_set_response_timeout(ctx, &response_timeout);
        rc  = modbus_write_bits(ctx, pOemParam->Adress, pOemParam->NR, sNewMsg);
        modbus_close(ctx);
        modbus_free(ctx);
    }
}

/****************************************************************************
function    : evro_tcpc_evro_tcpc_mtcp_doIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_tcpc_evro_tcpc_mtcp_doIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
)
{
    float*         pPhyData;   /* Physical value */
    float          fElecData;  /* Electrical value */
    float          fmult, fdiv, foffset;
    strRtIoChan*   pChannel;
    pChannel  = pRtIoSplDvc->pRtIoChan;
    pChannel += huChanNum;
    pPhyData  = (float*)(pChannel->pvKerPhyData);

    switch( cuSubFunct)
    {
    case ISA_IO_CTL_CHANLOCK:
        break;
    case ISA_IO_CTL_CHANUNLOCK:
        break;
    case ISA_IO_CTL_CHANOUTFORCE:
        if((pChannel->pfnCnvCall) != 0) /* If there is a cnv */
            pChannel->pfnCnvCall( ISA_IO_DIR_OUTPUT, pPhyData, &fElecData);
        else
            fElecData = *pPhyData;
        /* Apply gain and offset */
        fmult   = *(float *)(&(pChannel->luCnvMult));
        fdiv    = *(float *)(&(pChannel->luCnvDiv ));
        foffset = *(float *)(&(pChannel->luCnvOfs));
        if (fdiv != 0.0)
        {
            fElecData = ((fElecData) * fmult  / fdiv) + foffset;
        }
        break;
    }
}