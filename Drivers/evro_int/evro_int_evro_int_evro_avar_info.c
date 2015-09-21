/**************************************************************************
File:               evro_int_evro_int_evro_avar_info.c
Author:             Umputun
Creation date:      21/07/2012 - 14:25
Device name:        EVRO_avar_info
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_int_evro_int_evro_avar_info.h>
#include "modbus/modbus.h"
/* OEM Parameters */

typedef struct _tag_strEvro_avar_info
{
        int32  ID;   /* Node ID */
} strOemParam;


/****************************************************************************
function    : evro_int_evro_int_evro_avar_infoIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_int_evro_int_evro_avar_infoIosOpen
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
	printf("EVRO avar_info init\n");
	modbus_t *ctx = modbus_new_rtu("/dev/ttySAC2", 115200, 'N', 8, 1);
    int rc;
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
function    : evro_int_evro_int_evro_avar_infoIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_avar_infoIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{
    printf("EVRO avar_info Exit\n");
}

/****************************************************************************
function    : evro_int_evro_int_evro_avar_infoIosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_avar_infoIosRead
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
	modbus_t *ctx = modbus_new_rtu("/dev/ttySAC2", 115200, 'N', 8, 1);
    uint16 tab_reg_2[32];// for individual error on the channel
	uint16_t tab_reg[32]; // for input registers
    int rc;
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
        // rc= modbus_read_input_bits(ctx, 10000, 16, tab_reg); read from the input bits registers
		   rc= modbus_read_input_registers(ctx, 30028, 2, tab_reg); // read from  the input registers(bit mask)
						//for EVRO_modules adress=30000//
		if (rc == -1)
        {
            cpxDev->luUser =0;
        }
        else
        {
            cpxDev->luUser =1;
        	//start data conversion for normal representation in the development environment
			
			tab_reg_2[0] = tab_reg[0] & 0x0003;
			tab_reg_2[1] = tab_reg[0]>>2 & 0x0003;
			tab_reg_2[2] = tab_reg[0]>>4 & 0x0003;
			tab_reg_2[3] = tab_reg[0]>>6 & 0x0003;
			tab_reg_2[4] = tab_reg[0]>>8 & 0x0003;			
			tab_reg_2[5] = tab_reg[0]>>10 & 0x0003;
			tab_reg_2[6] = tab_reg[0]>>12 & 0x0003;			
			tab_reg_2[7] = tab_reg[0]>>14 & 0x0003;
			tab_reg_2[8] = tab_reg[1] & 0x0003;
			tab_reg_2[9] = tab_reg[1]>>2 & 0x0003;
			tab_reg_2[10] = tab_reg[1]>>4 & 0x0003;
			tab_reg_2[11] = tab_reg[1]>>6 & 0x0003;
			tab_reg_2[12] = tab_reg[1]>>8 & 0x0003;			
			tab_reg_2[13] = tab_reg[1]>>10 & 0x0003;
			tab_reg_2[14] = tab_reg[1]>>12 & 0x0003;			
			tab_reg_2[15] = tab_reg[1]>>14 & 0x0003;
	
			//end data conversion for normal representation in the development environment
		};
        modbus_close(ctx);
        modbus_free(ctx);
    };
     //
    strRtIoChan*        pChannel;
    strDfIoSplDvc*      pStaticDef;
    uint16              nbChannel;
    uint16              nbIndex;
	
    uint16*              pPhyData;   /* Physical value */
    uint16*              pLogData;   /* Logical Value    */
    uint16               fElecData;
    uint16               fMult,fDiv,fOffset;
    pStaticDef =  pRtIoSplDvc->pDfIoSplDvc;
    nbChannel  =  pStaticDef->huNbChan;
    pChannel   =  pRtIoSplDvc->pRtIoChan;
    /*  Update all channel */
    for( nbIndex = 0; nbIndex < 16; nbIndex++)
    {
        pPhyData = (uint16*)(pChannel->pvKerPhyData);
        pLogData = (uint16*)(pChannel->pvKerData);

        fElecData=tab_reg_2[nbIndex];		// data array
        if((pChannel->pfnCnvCall) != 0) /* If there is a conversion */
        {
            pChannel->pfnCnvCall( ISA_IO_DIR_INPUT, &fElecData, &fElecData);
        }
        fMult   = *(uint16 *)(&(pChannel->luCnvMult));
        fDiv    = *(uint16 *)(&(pChannel->luCnvDiv ));
        fOffset = *(uint16 *)(&(pChannel->luCnvOfs));
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
function    : evro_int_evro_int_evro_avar_infoIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_int_evro_int_evro_avar_infoIosCtl
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

