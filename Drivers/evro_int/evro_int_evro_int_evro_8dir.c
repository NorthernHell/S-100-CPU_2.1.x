/**************************************************************************
File:               evro_int_evro_int_evro_8dir.c
Author:             Umputun
Creation date:      21/07/2012 - 14:25
Device name:        EVRO_8DIR
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_int_evro_int_evro_8dir.h>
#include "modbus/modbus.h"
/* OEM Parameters */

typedef struct _tag_strEvro_8dir
{

    //int32  Counter_1;
    //int32  Counter_2;
    //int32  Counter_3;
    //int32  Counter_4;
    //int32  Counter_5;
    //int32  Counter_6;
    //int32  Counter_7;
    //int32  Counter_8;
    //int32  CCounter_1;   /* Capture Counter */
    //int32  CCounter_2;   /* Capture Counter */
    //int32  CCounter_3;   /* Capture Counter */
    //int32  CCounter_4;   /* Capture Counter */
    //int32  CCounter_5;   /* Capture Counter */
    //int32  CCounter_6;   /* Capture Counter */
    //int32  CCounter_7;   /* Capture Counter */
    //int32  CCounter_8;   /* Capture Counter */


    // int32  Counter_Capture;   /* Bit1 = 1 to Capture Counter1, Bit2 = 1 to */
    // int32  Counter_Mode;   /* 0=Disable, 1=Up Counting */
    // int32  Capture_Zero;   /* 0 = Disabled, bit1 = auto zero counter 1. */

} strOemParam;


/****************************************************************************
function    : evro_int_evro_int_evro_8dirIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_int_evro_int_evro_8dirIosOpen
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
    printf("EVRO 8DIC init\n");

    /*
    modbus_t *ctx = modbus_new_rtu("/dev/ttySAC2", 115200, 'N', 8, 1);
    int rc;
    uint16_t tab_reg[33];
    struct timeval response_timeout;
    response_timeout.tv_sec = 0;
    response_timeout.tv_usec = 20000;
    modbus_set_slave(ctx, pvRtIoDvc->luUser);
    if (modbus_connect(ctx) == -1)
    {
        printf("Connexion failed: \n");
        modbus_free(ctx);
    }
    else
    {
        modbus_set_response_timeout(ctx, &response_timeout);
        //
        tab_reg[0]=pOemParam->Counter_1;
        tab_reg[1]=tab_reg[0]%65535;
        tab_reg[0]=tab_reg[0]/65535;
        tab_reg[2]=pOemParam->Counter_2;
        tab_reg[3]=tab_reg[2]%65535;
        tab_reg[2]=tab_reg[2]/65535;
        tab_reg[4]=pOemParam->Counter_3;
        tab_reg[5]=tab_reg[4]%65535;
        tab_reg[4]=tab_reg[4]/65535;
        tab_reg[6]=pOemParam->Counter_4;
        tab_reg[7]=tab_reg[6]%65535;
        tab_reg[6]=tab_reg[6]/65535;
        tab_reg[8]=pOemParam->Counter_5;
        tab_reg[9]=tab_reg[8]%65535;
        tab_reg[8]=tab_reg[8]/65535;
        tab_reg[10]=pOemParam->Counter_6;
        tab_reg[11]=tab_reg[10]%65535;
        tab_reg[10]=tab_reg[10]/65535;
        tab_reg[12]=pOemParam->Counter_7;
        tab_reg[13]=tab_reg[12]%65535;
        tab_reg[12]=tab_reg[12]/65535;
        tab_reg[14]=pOemParam->Counter_8;
        tab_reg[15]=tab_reg[14]%65535;
        tab_reg[14]=tab_reg[14]/65535;
        //
        rc = modbus_write_registers(ctx, 40000, 16,tab_reg);
        if (rc == -1)
        {
            rc = modbus_write_registers(ctx, 40000, 16,tab_reg);
        };
        if (rc == -1)
        {
            rc = modbus_write_registers(ctx, 40000, 16,tab_reg);
        };
        if (rc == -1)
        {
            pvRtIoDvc->luUser=0;
        }
        else
        {
            pvRtIoDvc->luUser=1;
        };
        //
        tab_reg[0]=pOemParam->CCounter_1;
        tab_reg[1]=tab_reg[0]%65535;
        tab_reg[0]=tab_reg[0]/65535;
        tab_reg[2]=pOemParam->CCounter_2;
        tab_reg[3]=tab_reg[2]%65535;
        tab_reg[2]=tab_reg[2]/65535;
        tab_reg[4]=pOemParam->CCounter_3;
        tab_reg[5]=tab_reg[4]%65535;
        tab_reg[4]=tab_reg[4]/65535;
        tab_reg[6]=pOemParam->CCounter_4;
        tab_reg[7]=tab_reg[6]%65535;
        tab_reg[6]=tab_reg[6]/65535;
        tab_reg[8]=pOemParam->CCounter_5;
        tab_reg[9]=tab_reg[8]%65535;
        tab_reg[8]=tab_reg[8]/65535;
        tab_reg[10]=pOemParam->CCounter_6;
        tab_reg[11]=tab_reg[10]%65535;
        tab_reg[10]=tab_reg[10]/65535;
        tab_reg[12]=pOemParam->CCounter_7;
        tab_reg[13]=tab_reg[12]%65535;
        tab_reg[12]=tab_reg[12]/65535;
        tab_reg[14]=pOemParam->CCounter_8;
        tab_reg[15]=tab_reg[14]%65535;
        tab_reg[14]=tab_reg[14]/65535;
        //
        rc = modbus_write_registers(ctx, 40035, 16,tab_reg);
        if (rc == -1)
        {
            rc = modbus_write_registers(ctx, 40035, 16,tab_reg);
        };
        if (rc == -1)
        {
            rc = modbus_write_registers(ctx, 40035, 16,tab_reg);
        };
        if (rc == -1)
        {
            pvRtIoDvc->luUser=0;
        }
        else
        {
            pvRtIoDvc->luUser=1;
        };
    //Counter_Capture

    	tab_reg[0]=pOemParam->Counter_Capture;
        rc = modbus_write_register(ctx, 34,tab_reg[0]);
        if (rc == -1)
        {
            rc = modbus_write_register(ctx, 34,tab_reg[0]);
        };
        if (rc == -1)
        {
            rc = modbus_write_register(ctx, 34,tab_reg[0]);
        };
        if (rc == -1)
        {
            pvRtIoDvc->luUser=0;
        }
        else
        {
            pvRtIoDvc->luUser=1;
        };
    //
    //Counter_Mode
        tab_reg[0]=pOemParam->Counter_Mode;
        rc = modbus_write_register(ctx, 100,tab_reg[0]);
        if (rc == -1)
        {
            rc = modbus_write_register(ctx, 100,tab_reg[0]);
        };
        if (rc == -1)
        {
            rc = modbus_write_register(ctx, 100,tab_reg[0]);
        };
        if (rc == -1)
        {
            pvRtIoDvc->luUser=0;
        }
        else
        {
            pvRtIoDvc->luUser=1;
        };
    //
    //Capture_Zero
        tab_reg[0]=pOemParam->Capture_Zero;
        rc = modbus_write_register(ctx, 102,tab_reg[0]);
        if (rc == -1)
        {
            rc = modbus_write_register(ctx, 102,tab_reg[0]);
        };
        if (rc == -1)
        {
            rc = modbus_write_register(ctx, 102,tab_reg[0]);
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
    */
    return (0);
}

/****************************************************************************
function    : evro_int_evro_int_evro_8dirIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_8dirIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{
    printf("EVRO 8DIC Exit\n");
}

/****************************************************************************
function    : evro_int_evro_int_evro_8dirIosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_8dirIosRead
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
    uint16_t tab_reg[128];
    uint32 tab_counters[16];
    int rc;
    strOemParam* pOemParam;
    pOemParam=(strOemParam*)(pRtIoSplDvc->pvOemParam);
    struct timeval response_timeout;
    response_timeout.tv_sec = 0;
    response_timeout.tv_usec = 50000;
    modbus_set_slave(ctx, pRtIoSplDvc->luUser);
    if (modbus_connect(ctx) == -1)
    {
        printf("Connexion failed: \n");
        modbus_free(ctx);
    }
    else
    {
        modbus_set_response_timeout(ctx, &response_timeout);
        //Read counters
        rc  = modbus_read_registers(ctx, 40000, 32, tab_reg);
        if (rc == -1)
        {
            pRtIoSplDvc->luUser=0;
        }
        else
        {
            pRtIoSplDvc->luUser=1;
            //Convert Counters
            tab_counters[0]=tab_reg[1];
            tab_counters[0]=tab_counters[0]*65535;
            tab_counters[0]=tab_counters[0]+tab_reg[0];
            tab_counters[1]=tab_reg[3];
            tab_counters[1]=tab_counters[1]*65535;
            tab_counters[1]=tab_counters[1]+tab_reg[2];
            tab_counters[2]=tab_reg[5];
            tab_counters[2]=tab_counters[2]*65535;
            tab_counters[2]=tab_counters[2]+tab_reg[4];
            tab_counters[3]=tab_reg[7];
            tab_counters[3]=tab_counters[3]*65535;
            tab_counters[3]=tab_counters[3]+tab_reg[6];
            tab_counters[4]=tab_reg[9];
            tab_counters[4]=tab_counters[4]*65535;
            tab_counters[4]=tab_counters[4]+tab_reg[8];
            tab_counters[5]=tab_reg[11];
            tab_counters[5]=tab_counters[5]*65535;
            tab_counters[5]=tab_counters[5]+tab_reg[10];
            tab_counters[6]=tab_reg[13];
            tab_counters[6]=tab_counters[6]*65535;
            tab_counters[6]=tab_counters[6]+tab_reg[12];
            tab_counters[7]=tab_reg[15];
            tab_counters[7]=tab_counters[7]*65535;
            tab_counters[7]=tab_counters[7]+tab_reg[14];
            tab_counters[8]=tab_reg[17];
            tab_counters[8]=tab_counters[8]*65535;
            tab_counters[8]=tab_counters[8]+tab_reg[16];
            tab_counters[9]=tab_reg[19];
            tab_counters[9]=tab_counters[9]*65535;
            tab_counters[9]=tab_counters[9]+tab_reg[18];
            tab_counters[10]=tab_reg[21];
            tab_counters[10]=tab_counters[10]*65535;
            tab_counters[10]=tab_counters[10]+tab_reg[20];
            tab_counters[11]=tab_reg[23];
            tab_counters[11]=tab_counters[10]*65535;
            tab_counters[11]=tab_counters[10]+tab_reg[22];
            tab_counters[12]=tab_reg[25];
            tab_counters[12]=tab_counters[12]*65535;
            tab_counters[12]=tab_counters[12]+tab_reg[24];
            tab_counters[13]=tab_reg[27];
            tab_counters[13]=tab_counters[13]*65535;
            tab_counters[13]=tab_counters[13]+tab_reg[26];
            tab_counters[14]=tab_reg[29];
            tab_counters[14]=tab_counters[14]*65535;
            tab_counters[14]=tab_counters[14]+tab_reg[28];
            tab_counters[15]=tab_reg[31];
            tab_counters[15]=tab_counters[15]*65535;
            tab_counters[15]=tab_counters[15]+tab_reg[30];
        };
        modbus_close(ctx);
        modbus_free(ctx);
    };
    //
    strRtIoChan*        pChannel;
    strDfIoSplDvc*      pStaticDef;
    uint16              nbChannel;
    uint16              nbIndex;

    uint32*              pPhyData;   /* Physical value */
    uint32*              pLogData;   /* Logical Value    */
    uint32               fElecData;
    uint32             fMult,fDiv,fOffset;
    pStaticDef =  pRtIoSplDvc->pDfIoSplDvc;
    nbChannel  =  pStaticDef->huNbChan;
    pChannel   =  pRtIoSplDvc->pRtIoChan;
    /*  Update all channel */
    for( nbIndex = 0; nbIndex < nbChannel; nbIndex++)
    {
        pPhyData = (uint32*)(pChannel->pvKerPhyData);
        pLogData = (uint32*)(pChannel->pvKerData);

        fElecData=tab_counters[nbIndex];
        if((pChannel->pfnCnvCall) != 0) /* If there is a conversion */
        {
            pChannel->pfnCnvCall( ISA_IO_DIR_INPUT, &fElecData, &fElecData);
        }
        fMult   = *(uint32 *)(&(pChannel->luCnvMult));
        fDiv    = *(uint32 *)(&(pChannel->luCnvDiv ));
        fOffset = *(uint32 *)(&(pChannel->luCnvOfs));
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
function    : evro_int_evro_int_evro_8dirIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_8dirIosCtl
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

