/**************************************************************************
File:               evro_int_evro_int_evro_6ai.c
Author:             Umputun
Creation date:      21/07/2012 - 14:25
Device name:        EVRO_6AI
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_int_evro_int_evro_6ai.h>
#include "modbus/modbus.h"
/* OEM Parameters */

typedef struct _tag_strEvro_6ai
{
    int32  ID;   /* Node ID */
    int32  NCOM;   /* COM port number */
} strOemParam;


/****************************************************************************
function    : evro_int_evro_int_evro_6aiIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_int_evro_int_evro_6aiIosOpen
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
    printf("EVRO 6AI init\n");
    modbus_t *ctx;
    if (oemCPar->NCOM==1) {ctx = modbus_new_rtu("/dev/ttySAC0", 230400, 'N', 8, 1);}
    if (oemCPar->NCOM==2) {ctx = modbus_new_rtu("/dev/ttySAC1", 230400, 'N', 8, 1);}
    if (oemCPar->NCOM==3) {ctx = modbus_new_rtu("/dev/ttySAC2", 230400, 'N', 8, 1);}
    int rc;
    struct timeval response_timeout;
    response_timeout.tv_sec = 0;
    response_timeout.tv_usec = 20000;
    modbus_set_slave(ctx, oemCPar->ID);
    if (modbus_connect(ctx) == -1)
    {
        //printf("Connexion failed: \n");
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
function    : evro_int_evro_int_evro_6aiIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_6aiIosClose
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
)
{
    printf("EVRO 6AI Exit\n");
}

/****************************************************************************
function    : evro_int_evro_int_evro_6aiIosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_6aiIosRead
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
    modbus_t *ctx;
    if (oemCPar->NCOM==1) {ctx = modbus_new_rtu("/dev/ttySAC0", 230400, 'N', 8, 1);}
    if (oemCPar->NCOM==2) {ctx = modbus_new_rtu("/dev/ttySAC1", 230400, 'N', 8, 1);}
    if (oemCPar->NCOM==3) {ctx = modbus_new_rtu("/dev/ttySAC2", 230400, 'N', 8, 1);}
    uint16_t tab_reg[32]; //data array
    int rc;
    struct timeval response_timeout;
    response_timeout.tv_sec = 0;
    response_timeout.tv_usec = 20000;
    modbus_set_slave(ctx,  oemCPar->ID);
    if (modbus_connect(ctx) == -1)
    {
        //printf("Connexion failed: \n");
        modbus_free(ctx);
    }
    else
    {
        modbus_set_response_timeout(ctx, &response_timeout);
        rc  = modbus_read_input_registers(ctx, 30019, 6, tab_reg);
        modbus_close(ctx);
        modbus_free(ctx);
        //For EVRO_modules adress=30000//
        if (rc == -1)
        {
            cpxDev->luUser =0;
        }
        else
        {
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
            cpxDev->luUser =1;
            /*  Update all channel */
            for( nbIndex = 0; nbIndex < nbChannel; nbIndex++)
            {
                pPhyData = (int16*)(pChannel->pvKerPhyData);
                pLogData = (int16*)(pChannel->pvKerData);

                fElecData=tab_reg[nbIndex];		// data array
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
    //


}

/****************************************************************************
function    : evro_int_evro_int_evro_6aiIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_6aiIosCtl
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

