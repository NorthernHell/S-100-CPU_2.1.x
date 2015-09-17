/**************************************************************************
File:               evro_ext_evro_ext_io8tcs.c
Author:             Umputun
Creation date:      19/07/2012 - 11:31
Device name:        IO8TCS
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_ext_evro_ext_io8tcs.h>
#include "modbus/modbus.h"
/* OEM Parameters */

typedef struct _tag_strIo8tcs
{
    int32  baud_rate;   /* Baud Rate */
    int32  NCOM;   /* COM port number */
    int32  ID;   /* Device address */
    int32  Parity;   /* 0 - None 1-even 2-odd */
    int32  Stop_bits;   /* 1,2 stop bita */
    int32  TimeOutu;   /* timeout mcs */
    int32  TimeOutsec;   /* temeout s */
    int32  TC_type;   /* typ termopary */
    int32  Line_Frequency;   /* Line Frequency */
    int32  CJC_Offset;   /* 100 = zero offset (0.0) */
    int32  Units_Type;   /* 1=°C, 2=°F */
} strOemParam;
/****************************************************************************
function    : evro_ext_evro_ext_io8tcsIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_ext_evro_ext_io8tcsIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
)
{
    /*
     * Basically, for a complex device the driver can browse all
     * simple devices and perform corressponding initializations.
     * For a simple device it just initializes it.
     */

    strOemParam* pOemParam;
    pOemParam=(strOemParam*)(pvRtIoDvc->pvOemParam);
    printf("IO8TCS init\n");
    modbus_t *ctx;
    int rc;
    struct timeval response_timeout;
    response_timeout.tv_sec = pOemParam->TimeOutsec;
    response_timeout.tv_usec = pOemParam->TimeOutu;
    if (pOemParam->NCOM==1)
    {
        if (pOemParam->Parity==0)
        {
            ctx = modbus_new_rtu("/dev/ttySAC0", pOemParam->baud_rate, 'N', 8, pOemParam->Stop_bits);
        };
        if (pOemParam->Parity==1)
        {
            ctx = modbus_new_rtu("/dev/ttySAC0", pOemParam->baud_rate, 'E', 8, pOemParam->Stop_bits);
        };
        if (pOemParam->Parity==2)
        {
            ctx = modbus_new_rtu("/dev/ttySAC0", pOemParam->baud_rate, 'O', 8, pOemParam->Stop_bits);
        };
    }
    if (pOemParam->NCOM==2)
    {
        if (pOemParam->Parity==0)
        {
            ctx = modbus_new_rtu("/dev/ttySAC1", pOemParam->baud_rate, 'N', 8, pOemParam->Stop_bits);
        };
        if (pOemParam->Parity==1)
        {
            ctx = modbus_new_rtu("/dev/ttySAC1", pOemParam->baud_rate, 'E', 8, pOemParam->Stop_bits);
        };
        if (pOemParam->Parity==2)
        {
            ctx = modbus_new_rtu("/dev/ttySAC1", pOemParam->baud_rate, 'O', 8, pOemParam->Stop_bits);
        };
    }
    modbus_set_slave(ctx, pOemParam->ID);
    if (modbus_connect(ctx) == -1)
    {
        printf("Connexion failed: \n");
        pvRtIoDvc->luUser=0;
        modbus_free(ctx);
    }
    else
    {
        modbus_set_response_timeout(ctx, &response_timeout);
        rc = modbus_write_register(ctx, 100, pOemParam->TC_type);
        if (rc == -1)
        {
            pvRtIoDvc->luUser=0;
        }
        else
        {
            pvRtIoDvc->luUser=1;
        };
        rc = modbus_write_register(ctx, 101, pOemParam->Line_Frequency);
        if (rc == -1)
        {
            pvRtIoDvc->luUser=0;
        }
        else
        {
            pvRtIoDvc->luUser=1;
        };
        rc = modbus_write_register(ctx, 102, pOemParam->CJC_Offset);
        if (rc == -1)
        {
            pvRtIoDvc->luUser=0;
        }
        else
        {
            pvRtIoDvc->luUser=1;
        };
        rc = modbus_write_register(ctx, 103, pOemParam->Units_Type);
        if (rc == -1)
        {
            pvRtIoDvc->luUser=0;
        }
        else
        {
            pvRtIoDvc->luUser=1;
        };
        modbus_close(ctx);
        modbus_free(ctx);
    }
    return (0);
}

/****************************************************************************
function    : evro_ext_evro_ext_io8tcsIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_ext_evro_ext_io8tcsIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{

}

/****************************************************************************
function    : evro_ext_evro_ext_io8tcsIosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void evro_ext_evro_ext_io8tcsIosRead
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
    //
    strRtIoChan*        pChannel;
    strDfIoSplDvc*      pStaticDef;
    uint16              nbChannel;
    uint16              nbIndex;

    int16*              pPhyData;   /* Physical value */
    int16*              pLogData;   /* Logical Value    */
    int16               fElecData;
    float               fMult,fDiv,fOffset;
    pStaticDef =  pRtIoSplDvc->pDfIoSplDvc;
    nbChannel  =  pStaticDef->huNbChan;
    pChannel   =  pRtIoSplDvc->pRtIoChan;
    //
    modbus_t *ctx;
    uint16_t tab_reg[32];
    int rc;
    strOemParam* pOemParam;
    pOemParam=(strOemParam*)(pRtIoSplDvc->pvOemParam);
    struct timeval response_timeout;
    response_timeout.tv_sec = pOemParam->TimeOutsec;
    response_timeout.tv_usec = pOemParam->TimeOutu;

    if (pOemParam->NCOM==1)
    {
        if (pOemParam->Parity==0)
        {
            ctx = modbus_new_rtu("/dev/ttySAC0", pOemParam->baud_rate, 'N', 8, pOemParam->Stop_bits);
        };
        if (pOemParam->Parity==1)
        {
            ctx = modbus_new_rtu("/dev/ttySAC0", pOemParam->baud_rate, 'E', 8, pOemParam->Stop_bits);
        };
        if (pOemParam->Parity==2)
        {
            ctx = modbus_new_rtu("/dev/ttySAC0", pOemParam->baud_rate, 'O', 8, pOemParam->Stop_bits);
        };
    }
    if (pOemParam->NCOM==2)
    {
        if (pOemParam->Parity==0)
        {
            ctx = modbus_new_rtu("/dev/ttySAC1", pOemParam->baud_rate, 'N', 8, pOemParam->Stop_bits);
        };
        if (pOemParam->Parity==1)
        {
            ctx = modbus_new_rtu("/dev/ttySAC1", pOemParam->baud_rate, 'E', 8, pOemParam->Stop_bits);
        };
        if (pOemParam->Parity==2)
        {
            ctx = modbus_new_rtu("/dev/ttySAC1", pOemParam->baud_rate, 'O', 8, pOemParam->Stop_bits);
        };
    }
    modbus_set_slave(ctx, pOemParam->ID);
    if (modbus_connect(ctx) == -1)
    {
        printf("Connexion failed: \n");
        pRtIoSplDvc->luUser=0;
        modbus_free(ctx);
    }
    else
    {
        modbus_set_response_timeout(ctx, &response_timeout);
        rc  = modbus_read_registers(ctx, 1, 9, tab_reg);
        if (rc == -1)
        {
            pRtIoSplDvc->luUser=0;
        }
        else
        {
            pRtIoSplDvc->luUser=1;
        }
        modbus_close(ctx);
        modbus_free(ctx);
    }

    /*  Update all channel */
    for( nbIndex = 0; nbIndex < nbChannel; nbIndex++)
    {
        pPhyData = (int16*)(pChannel->pvKerPhyData);
        pLogData = (int16*)(pChannel->pvKerData);

        fElecData=tab_reg[nbIndex];
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
function    : evro_ext_evro_ext_io8tcsIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_ext_evro_ext_io8tcsIosCtl
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

