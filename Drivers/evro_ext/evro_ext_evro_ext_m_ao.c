/**************************************************************************
File:               evro_ext_evro_ext_m_ao.c
Author:             Umputun
Creation date:      19/07/2012 - 11:31
Device name:        M_AO
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_ext_evro_ext_m_ao.h>
#include "modbus/modbus.h"
/* OEM Parameters */

typedef struct _tag_strM_ao
{
    int32  ID;   /* Device address */
    int32  Adress;   /* address of the first register */
    int32  NR;   /* number of registers */
    int32  Func;
    int32  baud_rate;   /* Baud Rate */
    int32  NCOM;   /* COM port number */
    int32  Parity;   /* 0 - None 1-even 2-odd */
    int32  Stop_bits;   /* 1,2 stop bita */
    int32  TimeOutu;   /* timeout mcs */
    int32  TimeOutsec;   /* temeout s */
} strOemParam;

/****************************************************************************
Func    : evro_ext_evro_ext_m_aoIosOpen
description : Level 1 device Open Func
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_ext_evro_ext_m_aoIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
)
{
    /*
     * Basically, for a complex device the driver can browse all
     * simple devices and perform corressponding initializations.
     * For a simple device it just initializes it.
     */
    printf("AO Open\n");
    return (0);
}

/****************************************************************************
Func    : evro_ext_evro_ext_m_aoIosClose
description : Level 1 device Close Func
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_ext_evro_ext_m_aoIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{
    printf("AO Close\n");
}

/****************************************************************************
Func    : evro_ext_evro_ext_m_aoIosWrite
description : Simple device Write Func
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to write
return value: None
warning     :
****************************************************************************/

void evro_ext_evro_ext_m_aoIosWrite
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
    strOemParam* pOemParam;
    pOemParam=(strOemParam*)(pRtIoSplDvc->pvOemParam);
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
        pRtIoSplDvc->luUser=0;
        modbus_free(ctx);
    }
    else
    {
        pRtIoSplDvc->luUser=1;
        modbus_set_response_timeout(ctx, &response_timeout);
        if (pOemParam->Func==16)
        {
            rc = modbus_write_registers(ctx, pOemParam->Adress, pOemParam->NR, tab_reg);
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
        else
        {
            int i;
            for (i=0; i<pOemParam->NR; i++)
            {
                rc = modbus_write_register(ctx, pOemParam->Adress+i,tab_reg[i]);
                if (rc == -1)
                {
                    pRtIoSplDvc->luUser=0;
                    break;
                }
            }
            modbus_close(ctx);
            modbus_free(ctx);
        }
    }
}

/****************************************************************************
Func    : evro_ext_evro_ext_m_aoIosCtl
description : Simple device Control Func
parameters  :
   (input) uchar cuSubFunct :          Sub Func parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_ext_evro_ext_m_aoIosCtl
(
    uchar          cuSubFunct,   /* Sub Func parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
)
{
    /*
     * cuSubFunct parameter gives a Func code.
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

#ifdef ITGTDEF_MODIF
/****************************************************************************
Func    : evro_ext_evro_ext_IosMdf
description : This service is called by the VM to manage on line modification
   at driver level
parameters  :
   (input) uchar cuSubFunc:      Sub Func switch
   (input) strRtIoDrv* pRtIoDrv: Driver run time io struct
   (input) uint32 luMdfType:     On line modification types
   (input) void*  pvRtIoDvc:     Reserved for future extensions
return value: typSTATUS
warning     :
****************************************************************************/

typSTATUS evro_ext_evro_ext_IosMdf
(
    uchar          cuSubFunc,    /* Sub Func switch */
    strRtIoDrv*    pRtIoDrv,     /* Driver run time io struct */
    uint32         luMdfType,    /* On line modification types */
    void*          pvRtIoDvc     /* Reserved for future extensions */
)
{
    /*
         Parameters:

         · cuSubFunc
         This parameter is used to differentiate services:
         - ISA_MDF_IO_ACCEPT: the service must return 0 if it accepts the OLM
         - ISA_MDF_IO_GETREADY: the driver must be ready to accept the OLM
         - ISA_MDF_IO_DONE: the driver is notified that OLM is done

         · pRtIoDrv
         Run time structure of driver

         · luMdfType
         It defines the type of on line modification (bit fields)
         - ISA_IO_MDF_CPX_OEM: OEM parameters of complex device
         - ISA_IO_MDF_SPL_OEM: OEM parameters of some simple device
         - ISA_IO_MDF_CHAN_OEM: OEM parameters of some channels (NOT IMPLEMENTED YET)
         - ISA_IO_MDF_CHAN_PARAM: IO parameters of some channels
         - ISA_IO_MDF_CHAN_VAR: Wired IO variables of some channels

         · pvRtIoDvc
         Reserved for future extensions

         Return:
         If cuSubFunc is ISA_MDF_IO_ACCEPT:
         This Func will return 0 if the required on line modification is
         accepted, i.e. the driver could managed on line modification.
         This Func will return BAD_RET if the driver does not accept the
         required on line modification.
         Else it return 0.
     */

    return (0);

}

/****************************************************************************
Func    : evro_ext_evro_ext_m_aoIosMdf
description : This service is called by the VM to manage on line modification
   at simple device and channel level
parameters  :
   (input) uchar cuSubFunc:              Sub Func switch
   (input) strRtIoSplDvc* pRtIoSplDvc:   Simple device run time io struct
   (input) uint32 luMdfType:             On line modification types
   (input) strDfIoSplDvc* pDfIoSplDvc:   New simple device default struct
   (input) void* pvOemSplDvc:            New simple device OEM parameters
   (input) strDfIoChan* pDfIoChan:       New first channel default struct
   (input) void* pvOemChan:              New first channel OEM parameters
return value: typSTATUS
warning     :
****************************************************************************/

typSTATUS  evro_ext_evro_ext_m_aoIosMdf
(
    uchar          cuSubFunc,  /* Sub Func switch */
    strRtIoSplDvc* pRtIoSplDvc,/* Simple device run time io struct */
    uint32         luMdfType,  /* On line modification types */
    strDfIoSplDvc* pDfIoSplDvc,/* New simple device default struct */
    void*          pvOemSplDvc,/* New simple device OEM parameters */
    strDfIoChan*   pDfIoChan,  /* New first channel default struct */
    void*          pvOemChan   /* New first channel OEM parameters */
)
{
    /*
         Parameters:

         · cuSubFunc
         This parameter is used to differentiate services:
         - ISA_MDF_IO_ACCEPT: the service must return 0 if it accepts the OLM
         - ISA_MDF_IO_GETREADY: the driver must be ready to accept the OLM
         - ISA_MDF_IO_DONE: the driver is notified that OLM is done

         · pRtIoSplDvc
         Run time structure of simple device.

         · luMdfType
         It defines the type of on line modification (bit fields)
         - ISA_IO_MDF_SPL_OEM: OEM parameters of some simple device
         - ISA_IO_MDF_CHAN_OEM: OEM parameters of some channels (NOT IMPLEMENTED YET)
         - ISA_IO_MDF_CHAN_PARAM: IO parameters of some channels
         - ISA_IO_MDF_CHAN_VAR: Wired IO variables of some channels

         · pDfIoSplDvc
         New simple device default structure. Old one can be reached in runtime
         structure.
         It is null (0) is cuSubFunc is ISA_MDF_IO_DONE

         · pvOemSplDvc
         New simple device OEM parameters. Old one can be reached in runtime
         structure.
         It could be null (0) if luMdfType does not contain OEM parameters of
         simple device bit set.
         It is null (0) is cuSubFunc is ISA_MDF_IO_DONE

         · pDfIoChan
         New first channel default structure. Old one can be reached in runtime
         structure.
         It is null (0) is cuSubFunc is ISA_MDF_IO_DONE

         · pvOemChan
         New first channel OEM parameters. Old one can be reached in runtime
         structure.
         It could be null (0) if luMdfType does not contain OEM parameters of
         some channel bit set.
         It is null (0) is cuSubFunc is ISA_MDF_IO_DONE

         Return:
         If cuSubFunc is ISA_MDF_IO_ACCEPT:
         This Func will return 0 if the required on line modification is
         accepted, i.e. the driver could managed on line modification.
         This Func will return BAD_RET if the driver does not accept the
         required on line modification.
         Else it return 0.
     */

    return (0);

}
#endif

/* eof ********************************************************************/

