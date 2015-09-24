/**************************************************************************
File:               evro_int_evro_int_evro_indicate_info.c
Author:             Umputun
Creation date:      21/07/2012 - 14:25
Device name:        evro_indicate_info
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_int_evro_int_evro_indicate_info.h>
#include "modbus/modbus.h"
/* OEM Parameters */

typedef struct _tag_strEvro_indicate_info
{
     int32  ID;   /* Node ID */     
   
} strOemParam;


/****************************************************************************
function    : evro_int_evro_int_evro_indicate_infoIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_int_evro_int_evro_indicate_infoIosOpen
(
//   strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */	
)
{    /*
     * Basically, for a complex device the driver can browse all
     * simple devices and perform corressponding initializations.
     * For a simple device it just initializes it.
     */
//    strOemParam* pOemParam;
//    pOemParam=(strOemParam*)(pvRtIoDvc->pvOemParam);
	strRtIoCpxDvc *cpxDev=(strRtIoCpxDvc *)pRtIoSplDvc->pvRtIoLevBack;
	strOemParam *oemCPar=(strOemParam *)cpxDev->pvOemParam;
    printf("EVRO indicate info init\n");
	modbus_t *ctx = modbus_new_rtu("/dev/ttySAC2", 115200, 'N', 8, 1);
    int rc;
    struct timeval response_timeout;
    response_timeout.tv_sec = 0;
    response_timeout.tv_usec = 20000;
    modbus_set_slave(ctx, oemCPar->ID);
    if (modbus_connect(ctx) == -1)
    {
        printf("Connexion failed: \n");
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
function    : evro_int_evro_int_evro_indicate_infoIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_indicate_infoIosClose
(
//   strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
   strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */	
)
{
    printf("EVRO indicate info Exit\n");

}

/****************************************************************************
function    : evro_int_evro_int_evro_indicate_infoIosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_indicate_infoIosRead
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
	strOemParam *oemCPar=(strOemParam *)cpxDev->pvOemParam;	
	
	
//    strOemParam* pOemParam;
//    pOemParam=(strOemParam*)(pRtIoSplDvc->pvOemParam);
    modbus_t *ctx = modbus_new_rtu("/dev/ttySAC2", 115200, 'N', 8, 1);
    uint16 tab_reg_2[32]; // for input bits
	uint16_t tab_reg[32]; // for input registers
    int rc;
    struct timeval response_timeout;
    response_timeout.tv_sec = 0;
    response_timeout.tv_usec = 20000;
    modbus_set_slave(ctx,  oemCPar->ID);
    if (modbus_connect(ctx) == -1)
    {
        printf("Connexion failed: \n");
        modbus_free(ctx);
    }
  else
    {
        modbus_set_response_timeout(ctx, &response_timeout);
        // rc= modbus_read_input_bits(ctx, 10000, 16, tab_reg); read from the input bits registers
		   rc= modbus_read_input_registers(ctx, 30031, 1, tab_reg); // read from  the input registers(bit mask)
								//for EVRO_modules adress=30000//
		if (rc == -1)
        {
            cpxDev->luUser =0;
        }
        else
        {
            cpxDev->luUser =1;
       
		//start data conversion for normal representation in the development environment
		tab_reg_2[0] = ((tab_reg[0] & 0x0001) > 0) ? 1: 0;
		tab_reg_2[1] = ((tab_reg[0] & 0x0002) > 0) ? 1: 0;
		tab_reg_2[2] = ((tab_reg[0] & 0x0004) > 0) ? 1: 0;
		tab_reg_2[3] = ((tab_reg[0] & 0x0008) > 0) ? 1: 0;
		tab_reg_2[4] = ((tab_reg[0] & 0x0010) > 0) ? 1: 0;
		tab_reg_2[5] = ((tab_reg[0] & 0x0020) > 0) ? 1: 0;
		tab_reg_2[6] = ((tab_reg[0] & 0x0040) > 0) ? 1: 0;
		tab_reg_2[7] = ((tab_reg[0] & 0x0080) > 0) ? 1: 0;
		tab_reg_2[8] = ((tab_reg[0] & 0x0100) > 0) ? 1: 0;
		tab_reg_2[9] = ((tab_reg[0] & 0x0200) > 0) ? 1: 0;
		tab_reg_2[10] = ((tab_reg[0] & 0x0400) > 0) ? 1: 0;
		tab_reg_2[11] = ((tab_reg[0] & 0x0800) > 0) ? 1: 0;
		tab_reg_2[12] = ((tab_reg[0] & 0x1000) > 0) ? 1: 0;
		tab_reg_2[13] = ((tab_reg[0] & 0x2000) > 0) ? 1: 0;
		tab_reg_2[14] = ((tab_reg[0] & 0x4000) > 0) ? 1: 0;
		tab_reg_2[15] = ((tab_reg[0] & 0x8000) > 0) ? 1: 0;
		//end data conversion for normal representation in the development environment
		}
        modbus_close(ctx);
        modbus_free(ctx);
    }
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
    for (nbIndex=0; nbIndex <  nbChannel ; nbIndex++)
    {
        pPhyData = (uchar*)(pChannel->pvKerPhyData);
        pLogData = (uchar*)(pChannel->pvKerData);
		//
		byElecData = tab_reg_2[nbIndex];
		//
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

/****************************************************************************
function    : evro_int_evro_int_evro_indicate_infoIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_indicate_infoIosCtl
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

