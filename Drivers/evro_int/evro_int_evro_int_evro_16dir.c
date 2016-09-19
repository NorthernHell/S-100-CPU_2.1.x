/**************************************************************************
File:               evro_int_evro_int_evro_16dir.c
Author:             Umputun
Creation date:      21/07/2012 - 14:25
Device name:        EVRO_16dIR
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_int_evro_int_evro_16dir.h>
#include "modbus/modbus.h"
/* OEM Parameters */

typedef struct _tag_strEvro_16dir
{
    int32  ID;   /* Node ID */
} strOemParam;


/****************************************************************************
function    : evro_int_evro_int_evro_16dirIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_int_evro_int_evro_16dirIosOpen
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
)
{
    /*
     * Basically, for a complex device the driver can browse all
     * simple devices and perform corressponding initializations.
     * For a simple device it just initializes it.
     */
    strRtIoCpxDvc *cpxDev=(strRtIoCpxDvc *)pRtIoSplDvc->pvRtIoLevBack;
    strOemParam *oemCPar=(strOemParam *)cpxDev->pvOemParam;
    printf("EVRO 16DICounter init\n");
    modbus_t *ctx = modbus_new_rtu("/dev/ttySAC2", 115200, 'N', 8, 1);
    int rc;
    struct timeval response_timeout;
    response_timeout.tv_sec = 0;
    response_timeout.tv_usec = 20000;
    modbus_set_slave(ctx, oemCPar->ID);
    if (modbus_connect(ctx) == -1)
    {
       // printf("Connexion failed: \n");
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
function    : evro_int_evro_int_evro_16dirIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_16dirIosClose
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
)
{
    printf("EVRO 16dIC Exit\n");
}

/****************************************************************************
function    : evro_int_evro_int_evro_16dirIosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_16dirIosRead
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
    strRtIoCpxDvc *cpxDev=(strRtIoCpxDvc *)pRtIoSplDvc->pvRtIoLevBack;
    strOemParam *oemCPar=(strOemParam *)cpxDev->pvOemParam;
    modbus_t *ctx = modbus_new_rtu("/dev/ttySAC2", 115200, 'N', 8, 1);
    uint16_t tab_reg_1[128];
    uint32 tab_counters[16];
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
        //Read counters
        rc  =modbus_read_registers(ctx, 40001, 32, tab_reg_1);//read from holding registers
        modbus_close(ctx);
        modbus_free(ctx);
        //For EVRO modules adress 40001
        if (rc == -1)
        {
            cpxDev->luUser =0;
        }
        else
        {
            //
            strRtIoChan*        pChannel;
            strDfIoSplDvc*      pStaticDef;
            uint16              nbChannel;
            uint16              nbIndex;

            uint32*              pPhyData;   /* Physical value */
            uint32*              pLogData;   /* Logical Value    */
            uint32               fElecData;
            float             fMult,fDiv,fOffset;
            pStaticDef =  pRtIoSplDvc->pDfIoSplDvc;
            nbChannel  =  pStaticDef->huNbChan;
            pChannel   =  pRtIoSplDvc->pRtIoChan;
            /*  Update all channel */
            cpxDev->luUser =1;
            //Convert Counters

            tab_counters[0]=(tab_reg_1[1]<<16)+tab_reg_1[0];
            tab_counters[1]=(tab_reg_1[3]<<16)+tab_reg_1[2];
            tab_counters[2]=(tab_reg_1[5]<<16)+tab_reg_1[4];
            tab_counters[3]=(tab_reg_1[7]<<16)+tab_reg_1[6];
            tab_counters[4]=(tab_reg_1[9]<<16)+tab_reg_1[8];
            tab_counters[5]=(tab_reg_1[11]<<16)+tab_reg_1[10];
            tab_counters[6]=(tab_reg_1[13]<<16)+tab_reg_1[12];
            tab_counters[7]=(tab_reg_1[15]<<16)+tab_reg_1[14];
            tab_counters[8]=(tab_reg_1[17]<<16)+tab_reg_1[16];
            tab_counters[9]=(tab_reg_1[19]<<16)+tab_reg_1[18];
            tab_counters[10]=(tab_reg_1[21]<<16)+tab_reg_1[20];
            tab_counters[11]=(tab_reg_1[23]<<16)+tab_reg_1[22];
            tab_counters[12]=(tab_reg_1[25]<<16)+tab_reg_1[24];
            tab_counters[13]=(tab_reg_1[27]<<16)+tab_reg_1[26];
            tab_counters[14]=(tab_reg_1[29]<<16)+tab_reg_1[28];
            tab_counters[15]=(tab_reg_1[31]<<16)+tab_reg_1[30];
            for( nbIndex = 0; nbIndex < 16; nbIndex++)
            {
                pPhyData = (uint32*)(pChannel->pvKerPhyData);
                pLogData = (uint32*)(pChannel->pvKerData);

                fElecData=tab_counters[nbIndex];
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

    }


}

/****************************************************************************
function    : evro_int_evro_int_evro_16dirIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_16dirIosCtl
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

