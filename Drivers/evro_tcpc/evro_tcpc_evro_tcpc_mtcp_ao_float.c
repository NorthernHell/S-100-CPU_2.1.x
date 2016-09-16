/**************************************************************************
File:               evro_tcpc_evro_tcpc_mtcp_ao_float.c
Author:             Umputun
Creation date:      25/02/2013 - 16:08
Device name:        MTCP_ao_float
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_tcpc_evro_tcpc_mtcp_ao_float.h>
#include <modbus/modbus.h>
/* OEM Parameters */
typedef struct _tag_strMtcp_ao_float
{
    char   IP[16];
    int32  PORT;
    int32  Adress;
    int32  NR;
    int32	FUNCION;
    int32  TimeOutu;
    int32  TimeOutsec;
    int32  TimeOutTCP;
} strOemParam;
void *modbus_tcpcaof(void *ctx_void_ptr)
{
	modbus_t* ctx_2 = (modbus_t*)ctx_void_ptr;
	if (modbus_connect(ctx_2)==-1){
	struct timeval response_timeout;
	response_timeout.tv_sec = 0;
	response_timeout.tv_usec = 1;
	modbus_set_response_timeout(ctx_2, &response_timeout);	
	};				
}
/****************************************************************************
function    : evro_tcpc_evro_tcpc_mtcp_aiIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_tcpc_evro_tcpc_mtcp_ao_floatIosOpen
(
  strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
)
{
    printf("MB TCPC AO float init\n");
    return (0);
}

/****************************************************************************
function    : evro_tcpc_evro_tcpc_mtcp_aiIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_tcpc_evro_tcpc_mtcp_ao_floatIosClose
(
  strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
)
{
    printf("MB TCPC AO float Close\n");
    sleep(1);
}
/****************************************************************************
function    : evro_tcpc_evro_tcpc_mtcp_ao_floatIosWrite
description : Simple device Write function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to write
return value: None
warning     :
****************************************************************************/

void evro_tcpc_evro_tcpc_mtcp_ao_floatIosWrite
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
)
{
    strRtIoChan*     pChannel;
    strDfIoSplDvc*   pStaticDef;
    uint16           nbChannel;
    uint16           nbIndex;
    uint16_t tab_reg[128];

    float*           pPhyData;  /* Physical value */
    float*           pLogData;  /* Logic Value */
    float            iElecData; /* Electrical value */
    int              iCountChange =0, okChange;
    pStaticDef =  pRtIoSplDvc->pDfIoSplDvc;
    nbChannel  =  pStaticDef->huNbChan;
    pChannel   =  pRtIoSplDvc->pRtIoChan;
	strRtIoCpxDvc *cpxDev=(strRtIoCpxDvc *)pRtIoSplDvc->pvRtIoLevBack;
	strOemParam *oemCPar=(strOemParam *)cpxDev->pvOemParam;	
    /* Update all channel  */
    for( nbIndex = 0; nbIndex < nbChannel; nbIndex++)
    {
        /* update the channel if not locked  */
        if(!(pChannel->cuIsLocked))
        {
            pPhyData = (float*)(pChannel->pvKerPhyData);
            pLogData = (float*)(pChannel->pvKerData);
            okChange = 0;
            /* if value has changed or 1rst cycle */
            *pPhyData = *pLogData; /* Logic value = Physic Value */

            if((pChannel->pfnCnvCall) != 0) /* If there is a cnv */
                pChannel->pfnCnvCall( ISA_IO_DIR_OUTPUT, pPhyData, &iElecData);
            else
                iElecData = *pPhyData;

            /* Apply gain and offset  */
            if (pChannel->luCnvDiv != 0)
                iElecData = ((iElecData) * (float)(pChannel->luCnvMult)
                             / (float)(pChannel->luCnvDiv)) + (float)(pChannel->luCnvOfs);
           //tab_reg[nbIndex]=iElecData;
             
	unsigned int tmp = *((unsigned int*)(&iElecData));

             tab_reg[nbIndex*2]=(int16)tmp;
             tab_reg[nbIndex*2+1]=(int16)(tmp >> 16);

            /* If the variable has changed, we print in the file the new value */
            if (okChange)
            {
unsigned int tmp = *((unsigned int*)(&iElecData));

             tab_reg[nbIndex*2]=(int16)tmp;
             tab_reg[nbIndex*2+1]=(int16)(tmp >> 16);
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
    int modbus_connect_stat=0;
    uint32_t modbus_connect_index=oemCPar->TimeOutTCP;//TCP timeout TICKs newOEMparam !!!
    pthread_t threadmodbusTCPC;
    response_timeout.tv_sec = oemCPar->TimeOutsec;
    response_timeout.tv_usec = oemCPar->TimeOutu;
    ctx = modbus_new_tcp(oemCPar->IP, oemCPar->PORT); //connect
    modbus_set_response_timeout(ctx, &response_timeout);
    modbus_get_response_timeout(ctx, &response_timeout);
    pthread_create(&threadmodbusTCPC, NULL, modbus_tcpcaof, ctx);
    pthread_detach(threadmodbusTCPC);
    while (modbus_connect_index){
	modbus_connect_index--;
	if (pthread_kill(threadmodbusTCPC,0)!=0){
	modbus_connect_stat=1;
	break;	
	}
}
    if (modbus_connect_stat == 0)
    {
        //printf("Connexion failed: \n");
	pthread_cancel(threadmodbusTCPC);
        cpxDev->luUser =0;
	int soc = modbus_get_socket(ctx);
	close(soc);
        modbus_free(ctx);
    }
    else
    {
        modbus_set_response_timeout(ctx, &response_timeout);
        if (oemCPar->FUNCION!=6)
        {
            rc  = modbus_write_registers(ctx, oemCPar->Adress, oemCPar->NR, tab_reg);
        }
        else
        {
            int i;
            for (i=0; i<oemCPar->NR; i++)
            {
                rc =modbus_write_register(ctx, oemCPar->Adress+i,tab_reg[i]);
                if (rc==-1)
                {
                    break;
                }
            }
        }
		if (rc == -1)
        {
            cpxDev->luUser =0;
        }
        else
        {
            cpxDev->luUser =1;
        };			
        modbus_close(ctx);
        modbus_free(ctx);
    };
}

/****************************************************************************
function    : evro_tcpc_evro_tcpc_mtcp_ao_floatIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_tcpc_evro_tcpc_mtcp_ao_floatIosCtl
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
    float*        pPhyData;      /* Physical value */
    strRtIoChan*  pChannel;
    float         iElecData;     /* Electrical value */
    pChannel  =  pRtIoSplDvc->pRtIoChan;
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
            pChannel->pfnCnvCall( ISA_IO_DIR_OUTPUT, pPhyData, &iElecData);
        else
            iElecData = *pPhyData;
        /* Apply gain and offset  */
        if (pChannel->luCnvDiv != 0)
            iElecData = ((iElecData) * (float)(pChannel->luCnvMult)
                         / (float)(pChannel->luCnvDiv)) + (float)(pChannel->luCnvOfs);
        break;
    }


}
