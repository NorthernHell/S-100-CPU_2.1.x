/**************************************************************************
File:               evro_int_evro_int_evro_8ai.c
Author:             Umputun
Creation date:      21/07/2012 - 14:25
Device name:        EVRO_8AI
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_int_evro_int_evro_8ai.h>
#include "modbus/modbus.h"
/* OEM Parameters */

typedef struct _tag_strEvro_8ai
{
    int32  ID;   /* Node ID */
    int32  Filter_1;
    int32  Filter_2;
    int32  Filter_3;
    int32  Filter_4;
    int32  Filter_5;
    int32  Filter_6;
    int32  Filter_7;
    int32  Filter_8;
    int32  Filter_9;
    int32  Filter_10;
    int32  Filter_11;
    int32  Filter_12;
    int32  Filter_13;
    int32  Filter_14;
    int32  Filter_15;
    int32  Filter_16;
    int32  Filter_17;
    int32  Filter_18;
    int32  Filter_19;
    int32  Filter_20;
    int32  Filter_21;
    int32  Filter_22;
    int32  Filter_23;
    int32  Filter_24;
    int32  Filter_25;
    int32  Filter_26;
    int32  Filter_27;
    int32  Filter_28;
    int32  Filter_29;
    int32  Filter_30;
    int32  Filter_31;
    int32  Filter_32;
} strOemParam;


/****************************************************************************
function    : evro_int_evro_int_evro_8aiIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_int_evro_int_evro_8aiIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
)
{
    strOemParam* pOemParam;
    pOemParam=(strOemParam*)(pvRtIoDvc->pvOemParam);
    /*
     * Basically, for a complex device the driver can browse all
     * simple devices and perform corressponding initializations.
     * For a simple device it just initializes it.
     */
    printf("EVRO 8AI init\n");
    modbus_t *ctx = modbus_new_rtu("/dev/ttySAC2", 115200, 'N', 8, 1);
    int rc;
    uint16_t tab_reg[33];
    struct timeval response_timeout;
    response_timeout.tv_sec = 0;
    response_timeout.tv_usec = 20000;
    modbus_set_slave(ctx, pOemParam->ID);
    if (modbus_connect(ctx) == -1)
    {
        printf("Connexion failed: \n");
        modbus_free(ctx);
    }
    else
    {
        modbus_set_response_timeout(ctx, &response_timeout);
        //
        tab_reg[0]=pOemParam->Filter_1;
        tab_reg[1]=pOemParam->Filter_2;
        tab_reg[2]=pOemParam->Filter_3;
        tab_reg[3]=pOemParam->Filter_4;
        tab_reg[4]=pOemParam->Filter_5;
        tab_reg[5]=pOemParam->Filter_6;
        tab_reg[6]=pOemParam->Filter_7;
        tab_reg[7]=pOemParam->Filter_8;
        tab_reg[8]=pOemParam->Filter_9;
        tab_reg[9]=pOemParam->Filter_10;
        tab_reg[10]=pOemParam->Filter_11;
        tab_reg[11]=pOemParam->Filter_12;
        tab_reg[12]=pOemParam->Filter_13;
        tab_reg[13]=pOemParam->Filter_14;
        tab_reg[14]=pOemParam->Filter_15;
        tab_reg[15]=pOemParam->Filter_16;
        tab_reg[16]=pOemParam->Filter_17;
        tab_reg[17]=pOemParam->Filter_18;
        tab_reg[18]=pOemParam->Filter_19;
        tab_reg[19]=pOemParam->Filter_20;
        tab_reg[20]=pOemParam->Filter_21;
        tab_reg[21]=pOemParam->Filter_22;
        tab_reg[22]=pOemParam->Filter_23;
        tab_reg[23]=pOemParam->Filter_24;
        tab_reg[24]=pOemParam->Filter_25;
        tab_reg[25]=pOemParam->Filter_26;
        tab_reg[26]=pOemParam->Filter_27;
        tab_reg[27]=pOemParam->Filter_28;
        tab_reg[28]=pOemParam->Filter_29;
        tab_reg[29]=pOemParam->Filter_30;
        tab_reg[30]=pOemParam->Filter_31;
        tab_reg[31]=pOemParam->Filter_32;
        //
        rc = modbus_write_registers(ctx, 10, 32,tab_reg);
        if (rc == -1)
        {
            rc = modbus_write_registers(ctx, 10, 32,tab_reg);
        };
        if (rc == -1)
        {
            rc = modbus_write_registers(ctx, 10, 32,tab_reg);
        };
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
    };
    return (0);
}

/****************************************************************************
function    : evro_int_evro_int_evro_8aiIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_8aiIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{
    printf("EVRO 8AI Exit\n");
}

/****************************************************************************
function    : evro_int_evro_int_evro_8aiIosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_8aiIosRead
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
    modbus_t *ctx = modbus_new_rtu("/dev/ttySAC2", 115200, 'N', 8, 1);
    uint16_t tab_reg[10];
    int rc;
    strOemParam* pOemParam;
    pOemParam=(strOemParam*)(pRtIoSplDvc->pvOemParam);
    struct timeval response_timeout;
    response_timeout.tv_sec = 0;
    response_timeout.tv_usec = 20000;
    modbus_set_slave(ctx, pOemParam->ID);
    if (modbus_connect(ctx) == -1)
    {
        printf("Connexion failed: \n");
        modbus_free(ctx);
    }
    else
    {
        modbus_set_response_timeout(ctx, &response_timeout);
        rc  = modbus_read_registers(ctx, 1, 9, tab_reg);
        if (rc == -1)
        {
            rc  = modbus_read_registers(ctx, 1, 9, tab_reg);
        };
        if (rc == -1)
        {
            rc  = modbus_read_registers(ctx, 1, 9, tab_reg);
        };
        if (rc == -1)
        {
            pRtIoSplDvc->luUser=0;
        }
        else
        {
            pRtIoSplDvc->luUser=1;
        };
        modbus_close(ctx);
        modbus_free(ctx);
    };
    //
    strRtIoChan*        pChannel;
    strDfIoSplDvc*      pStaticDef;
    uint16              nbChannel;
    uint16              nbIndex;

    int16*              pPhyData;   /* Physical value */
    int16*              pLogData;   /* Logical Value    */
    int16               fElecData;
    int16               fMult,fDiv,fOffset;
    pStaticDef =  pRtIoSplDvc->pDfIoSplDvc;
    nbChannel  =  pStaticDef->huNbChan;
    pChannel   =  pRtIoSplDvc->pRtIoChan;
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
        fMult   = *(int16 *)(&(pChannel->luCnvMult));
        fDiv    = *(int16 *)(&(pChannel->luCnvDiv ));
        fOffset = *(int16 *)(&(pChannel->luCnvOfs));
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
function    : evro_int_evro_int_evro_8aiIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_8aiIosCtl
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

