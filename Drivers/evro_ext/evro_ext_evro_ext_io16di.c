/**************************************************************************
File:               evro_ext_evro_ext_io16di.c
Author:             Umputun
Creation date:      19/07/2012 - 11:31
Device name:        IO16DI
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_ext_evro_ext_io16di.h>
#include "modbus/modbus.h"
/* OEM Parameters */

typedef struct _tag_strIo16di
{
    int32  baud_rate;   /* Baud Rate */
    int32  NCOM;   /* COM port number */
    int32  ID;   /* Device address */
    int32  Parity;   /* 0 - None 1-even 2-odd */
    int32  Stop_bits;   /* 1,2 stop bita */
    int32  TimeOutu;   /* timeout mcs */
    int32  TimeOutsec;   /* temeout s */
    int32  Input_Filter;   /* 0 = Disable, >0 = Enable. (x10ms) */
} strOemParam;


/****************************************************************************
function    : evro_ext_evro_ext_IosInit
description : Driver Init function
parameters  :
   (input) strRtIoDrv* pRtIoDrv :  Run time io struct of the driver to init
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS  evro_ext_evro_ext_IosInit
(
    strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to init */
)
{
    /*
     * Basically, the driver can browse all
     * used devices and perform a global initialization
     */

    return (0);
}

/****************************************************************************
function    :  evro_ext_evro_ext_IosExit
description : Driver Exit function
parameters  :
   (input) strRtIoDrv* pRtIoDrv :  Run time io struct of the driver to exit
return value: None
warning     :
****************************************************************************/

void evro_ext_evro_ext_IosExit
(
    strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to exit */
)
{

}

/****************************************************************************
function    : evro_ext_evro_ext_io16diIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_ext_evro_ext_io16diIosOpen
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
    /*
     * Basically, for a complex device the driver can browse all
     * simple devices and perform corressponding initializations.
     * For a simple device it just initializes it.
     */
    printf("IO16DI init\n");
    modbus_t *ctx;
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
        modbus_write_register(ctx, 101, pOemParam->Input_Filter);
        pvRtIoDvc->luUser=1;
        modbus_close(ctx);
        modbus_free(ctx);
    }
    return (0);
}

/****************************************************************************
function    : evro_ext_evro_ext_io16diIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_ext_evro_ext_io16diIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{
    printf("IO16DI Close\n");
}

/****************************************************************************
function    : evro_ext_evro_ext_io16diIosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void evro_ext_evro_ext_io16diIosRead
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
    strRtIoCpxDvc *cpxDev=(strRtIoCpxDvc *)pRtIoSplDvc->pvRtIoLevBack; /*  cpxDev->luUser
	- это и будет поле комплексного, которое будет одинаково и доступно для всех простых
	в составе этого комплесного  */
    strOemParam* pOemParam;
    pOemParam=(strOemParam*)(pRtIoSplDvc->pvOemParam);
    modbus_t *ctx;
    uint8_t tab_reg[32];
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
        modbus_set_response_timeout(ctx, &response_timeout);
        rc= modbus_read_input_bits(ctx, 0, 16, tab_reg);
        if (rc == -1)
        {
            cpxDev->luUser =0;
            modbus_close(ctx);
            modbus_free(ctx);
        }
        else
        {
            ////////
            strRtIoChan*        pChannel;
            strDfIoSplDvc*      pStaticDef;
            uint16              nbChannel;
            uint16              nbIndex;

            uchar*              pPhyData;   /* Physical value            */
            uchar*              pLogData;   /* Logical Value               */
            uchar               byElecData; /* Electrical value ('1' or '0') */

            pStaticDef = pRtIoSplDvc->pDfIoSplDvc;
            nbChannel  = pStaticDef->huNbChan;
            pChannel   = pRtIoSplDvc->pRtIoChan;
            /* Update all channels */
            cpxDev->luUser =1;
            modbus_close(ctx);
            modbus_free(ctx);
            for (nbIndex=0; nbIndex <  nbChannel ; nbIndex++)
            {
                pPhyData = (uchar*)(pChannel->pvKerPhyData);
                pLogData = (uchar*)(pChannel->pvKerData);
                byElecData = tab_reg[nbIndex];
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

    }




}

/****************************************************************************
function    : evro_ext_evro_ext_io16diIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_ext_evro_ext_io16diIosCtl
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

