/**************************************************************************
File:               evro_tcp_evro_tcp_mts_holdingr_o.c
Author:             Umputun
Creation date:      16/02/2013 - 20:17
Device name:        MTS_HOLDINGR_O
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_tcp_evro_tcp_mts_holdingr_o.h>
#include <modbus/modbus.h>
extern modbus_mapping_t *mb_mapping;
/* OEM Parameters */




/****************************************************************************
function    : evro_tcp_evro_tcp_mts_holdingr_oIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_tcp_evro_tcp_mts_holdingr_oIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
)
{
    printf("MODBUS TCP SERVER holding_o INIT\n");
    pvRtIoDvc->luUser = 1;
    return (0);
}

/****************************************************************************
function    : evro_tcp_evro_tcp_mts_holdingr_oIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_tcp_evro_tcp_mts_holdingr_oIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{
    printf("MODBUS TCP SERVER holding_o CLOSE\n");

}

/****************************************************************************
function    : evro_tcp_evro_tcp_mts_holdingr_oIosWrite
description : Simple device Write function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to write
return value: None
warning     :
****************************************************************************/

void evro_tcp_evro_tcp_mts_holdingr_oIosWrite
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
)
{
    uint16           nbIndex;
    int              iCountChange =0;
    /* Update all channel  */
    for (nbIndex=0;nbIndex<pRtIoSplDvc->huNbChan;nbIndex++) /* loop for all input channels */
    {
      struct _s_RtIoChan *iochan=pRtIoSplDvc->pRtIoChan+nbIndex;

      if (iochan->cuIsLocked == 0)
      {
        if (iochan->pfnCnvCall == 0)
	       *(int32*)iochan->pvKerPhyData=(*(int32*)iochan->pvKerData * *(int32*)(&(iochan->luCnvMult))) / *(int32*)(&(iochan->luCnvDiv)) + *(int32*)(&(iochan->luCnvOfs));
        else
	       iochan->pfnCnvCall(ISA_IO_DIR_OUTPUT,(int32*)iochan->pvKerData,(int32*)iochan->pvKerPhyData);
		 // check change
      if(*(int32*)iochan->pvKerPhyData != *(int32*)(&(iochan->luUser)))
      { 
        mb_mapping->tab_registers[nbIndex] = *(int32*)iochan->pvKerPhyData;
        *(int32*)(&(iochan->luUser))=*(int32*)iochan->pvKerPhyData;
        iCountChange++;      
      }
      }
    }
}

/****************************************************************************
function    : evro_tcp_evro_tcp_mts_holdingr_oIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_tcp_evro_tcp_mts_holdingr_oIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
)
{
    int32*        pPhyData;      /* Physical value */
    strRtIoChan*  pChannel;
    int32         iElecData;     /* Electrical value */
    pChannel  =  pRtIoSplDvc->pRtIoChan;
    pChannel += huChanNum;
    pPhyData  = (int32*)(pChannel->pvKerPhyData);

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
            iElecData = ((iElecData) * (int32)(pChannel->luCnvMult)
                         / (int32)(pChannel->luCnvDiv)) + (int32)(pChannel->luCnvOfs);
////
        break;
    }


}
