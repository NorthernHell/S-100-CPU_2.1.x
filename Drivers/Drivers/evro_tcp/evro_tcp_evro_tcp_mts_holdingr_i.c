/**************************************************************************
File:               evro_tcp_evro_tcp_mts_holdingr_i.c
Author:             Umputun
Creation date:      16/02/2013 - 20:17
Device name:        MTS_HOLDINGR_I
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <evro_tcp_evro_tcp_mts_holdingr_i.h>
#include <modbus/modbus.h>
extern modbus_mapping_t *mb_mapping;
/* OEM Parameters */




/****************************************************************************
function    : evro_tcp_evro_tcp_mts_holdingr_iIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS evro_tcp_evro_tcp_mts_holdingr_iIosOpen
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to open */
)
{
    printf("MODBUS TCP SERVER holding_i INIT\n");
    return (0);
}

/****************************************************************************
function    : evro_tcp_evro_tcp_mts_holdingr_iIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoSplDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void evro_tcp_evro_tcp_mts_holdingr_iIosClose
(
    strRtIoSplDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{
    printf("MODBUS TCP SERVER holding_i CLOSE\n");

}

/****************************************************************************
function    : evro_tcp_evro_tcp_mts_holdingr_iIosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void evro_tcp_evro_tcp_mts_holdingr_iIosRead
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to read */
)
{
    uint16              nbIndex;

    /*  Update all channel */
    for( nbIndex = 0; nbIndex < pRtIoSplDvc->huNbChan; nbIndex++)
    {
        struct _s_RtIoChan *iochan=pRtIoSplDvc->pRtIoChan+nbIndex;
    
        *(float*)iochan->pvKerPhyData = mb_mapping->tab_registers[nbIndex];
        
        printf("value ch[%d] = %f\n",nbIndex,*(float*)iochan->pvKerPhyData);
                
        if (iochan->cuIsLocked == 0)
          if (iochan->pfnCnvCall == 0)
			       *(float*)iochan->pvKerData=(*(float*)iochan->pvKerPhyData * *(float*)(&(iochan->luCnvMult))) / *(float*)(&(iochan->luCnvDiv)) + *(float*)(&(iochan->luCnvOfs));
		      else
			       iochan->pfnCnvCall(ISA_IO_DIR_INPUT,(float*)iochan->pvKerPhyData,(float*)iochan->pvKerData);
    }
    printf("------------------------\n");
}


/****************************************************************************
function    : evro_tcp_evro_tcp_mts_holdingr_iIosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void evro_tcp_evro_tcp_mts_holdingr_iIosCtl
(
    uchar          cuSubFunct,   /* Sub function parameter */
    strRtIoSplDvc* pRtIoSplDvc,  /* Rt io struct of the spl dvc to control */
    uint16         huChanNum,    /* Channel number if any */
    void*          pvReserved    /* Reserved */
)
{

}
