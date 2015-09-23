/**************************************************************************
File:               evro_ext_evro_ext_m_do.c
Author:             Umputun
Creation date:      19/07/2012 - 11:31
Device name:        M_DO
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_ext_evro_ext_m_do.h>
#include "modbus/modbus.h"
/* OEM Parameters */

typedef struct _tag_strM_do
{
    int32  baud_rate;   /* Baud Rate */
    int32  NCOM;   /* COM port number */
    int32  ID;   /* Device address */
    int32  Adress;   /* address of the first register */
    int32  NR;   /* number of registers */
    int32  Parity;   /* 0 - None 1-even 2-odd */
    int32  Stop_bits;   /* 1,2 stop bita */
    int32  TimeOutu;   /* timeout mcs */
    int32  TimeOutsec;   /* temeout s */
} strOemParam;


/****************************************************************************
function    : evro_ext_evro_ext_IosInit
description : Driver Init function
parameters  :
   (input) strRtIoDrv* pRtIoDrv :  Run time io struct of the driver to init
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/



/****************************************************************************
function    : evro_ext_evro_ext_m_doIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_ext_evro_ext_m_doIosOpen
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
)
{
    /*
     * Basically, for a complex device the driver can browse all
     * simple devices and perform corressponding initializations.
     * For a simple device it just initializes it.
     */
    printf("MB DO init\n");
    return (0);
}

/****************************************************************************
function    : evro_ext_evro_ext_m_doIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_ext_evro_ext_m_doIosClose
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
)
{
    printf("MB DO exit\n");
}

/****************************************************************************
function    : evro_ext_evro_ext_m_doIosWrite
description : Simple device Write function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to write
return value: None
warning     :
****************************************************************************/

void evro_ext_evro_ext_m_doIosWrite
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
    uchar*           pPhyData;      /* Physical value */
    uchar*           pLogData;      /* Logic Value */
    uchar            byElecData;    /* Electrical value ('1' or '0') */
    uint8_t            tab_reg[150];
    int              okChange;      /* indicate one of the channel has changed */
    pStaticDef =  pRtIoSplDvc->pDfIoSplDvc;
    nbChannel  =  pStaticDef->huNbChan;
    pChannel   =  pRtIoSplDvc->pRtIoChan;
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

        if (byElecData) tab_reg[nbIndex] = 1;
        else            tab_reg[nbIndex] = 0;
        pChannel++;
    }
    modbus_t *ctx;
    int rc;
    struct timeval response_timeout;
    response_timeout.tv_sec = oemCPar->TimeOutsec;
    response_timeout.tv_usec = oemCPar->TimeOutu;

    if (oemCPar->NCOM==1)
    {
        if (oemCPar->Parity==0)
        {
            ctx = modbus_new_rtu("/dev/ttySAC0", oemCPar->baud_rate, 'N', 8, oemCPar->Stop_bits);
        };
        if (oemCPar->Parity==1)
        {
            ctx = modbus_new_rtu("/dev/ttySAC0", oemCPar->baud_rate, 'E', 8, oemCPar->Stop_bits);
        };
        if (oemCPar->Parity==2)
        {
            ctx = modbus_new_rtu("/dev/ttySAC0", oemCPar->baud_rate, 'O', 8, oemCPar->Stop_bits);
        };
    }
    if (oemCPar->NCOM==2)
    {
        if (oemCPar->Parity==0)
        {
            ctx = modbus_new_rtu("/dev/ttySAC1", oemCPar->baud_rate, 'N', 8, oemCPar->Stop_bits);
        };
        if (oemCPar->Parity==1)
        {
            ctx = modbus_new_rtu("/dev/ttySAC1", oemCPar->baud_rate, 'E', 8, oemCPar->Stop_bits);
        };
        if (oemCPar->Parity==2)
        {
            ctx = modbus_new_rtu("/dev/ttySAC1", oemCPar->baud_rate, 'O', 8, oemCPar->Stop_bits);
        };
    }
    modbus_set_slave(ctx, oemCPar->ID);
    if (modbus_connect(ctx) == -1)
    {
        printf("Connexion failed: \n");
        modbus_free(ctx);
    }
    else
    {
        modbus_set_response_timeout(ctx, &response_timeout);
        rc = modbus_write_bits(ctx, oemCPar->Adress, oemCPar->NR, tab_reg);
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
}

/****************************************************************************
function    : evro_ext_evro_ext_m_doIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_ext_evro_ext_m_doIosCtl
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

/* eof ********************************************************************/

