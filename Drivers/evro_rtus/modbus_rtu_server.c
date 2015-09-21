/**************************************************************************
File:               modbus_rtu_server.c
Author:             Umputun
Creation date:      20/02/2013 - 12:46
Device name:        MODBUS_RTU_SERVER
***************************************************************************/

#include <dsys0def.h>
#include <dios0def.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <modbus/modbus.h>
#include <modbus_rtu_server.h>
// link simpple dev
#include <modbus_rtu_inp_reg_.h>
#include <modbus_rtu_inp_bits_.h>
#include <modbus_rtu_holding_o_.h>
#include <modbus_rtu_holding_i_.h>
#include <modbus_rtu_coil_o_.h>
#include <modbus_rtu_coil_i_.h>
/* OEM Parameters of complex device */

typedef struct _tag_strModbus_rtu_server
{
    int32  SLAVE_ID;
    int32  COM_PORT;
    int32  BAUD_RATE;
    int32  PARITY;
    int32  STOP_BITS;
} strOemParam;


/* OEM Parameters of linked simple devices */

//   int socket_rtu;
modbus_t *ctx_rtu = NULL;
pthread_t threadmodbusRTU;
modbus_mapping_t *mb_mapping_rtu;
int modbus_rtu_rabota = 1;

void *modbus_rtu(void*)
{
    int rc;
    printf("MODBUS_RTU START\n");
    while(1)
    {

        uint8_t query[600];
        rc = modbus_receive(ctx_rtu, query);
        if (modbus_rtu_rabota == 0)
        {
            break;
        };
        if (rc >= 0)
        {
            // printf("Replying to request.\n");
            modbus_reply(ctx_rtu, query, rc, mb_mapping_rtu);
        };
    }
    printf("MODBUS_RTU STOP\n");
}



/****************************************************************************
function    : _evro_rtus_evro_rtusIosInit
description : Driver Init function
parameters  :
   (input) strRtIoDrv* pRtIoDrv :  Run time io struct of the driver to init
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS  _evro_rtus_evro_rtusIosInit
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
function    :  _evro_rtus_evro_rtusIosExit
description : Driver Exit function
parameters  :
   (input) strRtIoDrv* pRtIoDrv :  Run time io struct of the driver to exit
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusIosExit
(
    strRtIoDrv* pRtIoDrv /* Run time io struct of the driver to exit */
)
{

}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_serverIosOpen
description : Level 1 device Open function
parameters  :
   (input) strRtIoCpxDvc* pvRtIoDvc :  Run time io struct of the device to open
return value: typSTATUS :  0 if successful, BAD_RET if error
warning     : Returning with an error stops the kernel resource starting
****************************************************************************/

typSTATUS _evro_rtus_evro_rtusmodbus_rtu_serverIosOpen
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to open */
)
{
    /*
     * Basically, for a complex device the driver can browse all
     * simple devices and perform corressponding initializations.
     * For a simple device it just initializes it.
     */

    modbus_rtu_rabota = 1;
    int a = 1;
    strOemParam* pOemParam;
    pOemParam=(strOemParam*)(pvRtIoDvc->pvOemParam);
    printf("Waiting for Serial connection on COM ");
    if (pOemParam->COM_PORT==1)
    {
        if (pOemParam->PARITY==0)
        {
            ctx_rtu = modbus_new_rtu("/dev/ttySAC0", pOemParam->BAUD_RATE, 'N', 8, pOemParam->STOP_BITS);
        };
        if (pOemParam->PARITY==1)
        {
            ctx_rtu = modbus_new_rtu("/dev/ttySAC0", pOemParam->BAUD_RATE, 'E', 8, pOemParam->STOP_BITS);
        };
        if (pOemParam->PARITY==2)
        {
            ctx_rtu = modbus_new_rtu("/dev/ttySAC0", pOemParam->BAUD_RATE, 'O', 8, pOemParam->STOP_BITS);
        };
    };
    if (pOemParam->COM_PORT==2)
    {
        if (pOemParam->PARITY==0)
        {
            ctx_rtu = modbus_new_rtu("/dev/ttySAC1", pOemParam->BAUD_RATE, 'N', 8, pOemParam->STOP_BITS);
        };
        if (pOemParam->PARITY==1)
        {
            ctx_rtu = modbus_new_rtu("/dev/ttySAC1", pOemParam->BAUD_RATE, 'E', 8, pOemParam->STOP_BITS);
        };
        if (pOemParam->PARITY==2)
        {
            ctx_rtu = modbus_new_rtu("/dev/ttySAC1", pOemParam->BAUD_RATE, 'O', 8, pOemParam->STOP_BITS);
        };
    };
	   if (pOemParam->COM_PORT==3)
    {
        if (pOemParam->PARITY==0)
        {
            ctx_rtu = modbus_new_rtu("/dev/ttySAC2", pOemParam->BAUD_RATE, 'N', 8, pOemParam->STOP_BITS);
        };
        if (pOemParam->PARITY==1)
        {
            ctx_rtu = modbus_new_rtu("/dev/ttySAC2", pOemParam->BAUD_RATE, 'E', 8, pOemParam->STOP_BITS);
        };
        if (pOemParam->PARITY==2)
        {
            ctx_rtu = modbus_new_rtu("/dev/ttySAC2", pOemParam->BAUD_RATE, 'O', 8, pOemParam->STOP_BITS);
        };
    };

    modbus_set_slave(ctx_rtu, pOemParam->SLAVE_ID);
    modbus_connect(ctx_rtu);
    printf("Serial connection started!\n");
///
		struct timeval response_timeout;
		response_timeout.tv_sec = 0;
		response_timeout.tv_usec = 1;
modbus_set_byte_timeout(ctx_rtu, &response_timeout);
///
    mb_mapping_rtu = modbus_mapping_new(0xff, 0xff,0xff, 0xff);
    if (mb_mapping_rtu == NULL)
    {
        fprintf(stderr, "Failed to allocate the mapping: %s\n",
                modbus_strerror(errno));
        modbus_free(ctx_rtu);
        return -1;
    }
    pthread_create(&threadmodbusRTU, NULL, modbus_rtu, (void*)&a);
    pthread_detach(threadmodbusRTU);
    //////////
    strRtIoSplDvc* pRtIoSplDvc;
    pRtIoSplDvc = pvRtIoDvc->pRtIoSplDvc;
    //////////
    if (_evro_rtus_evro_rtusmodbus_rtu_inp_reg_IosOpen (pRtIoSplDvc) != 0)
    {
        printf("Error opening\n");
        return(BAD_RET);
    }
    pRtIoSplDvc = (strRtIoSplDvc*)(pRtIoSplDvc->pvDrvRtIoDvcNxt);
    if (_evro_rtus_evro_rtusmodbus_rtu_inp_bits_IosOpen(pRtIoSplDvc) != 0)
    {
        printf("Error opening\n");
        return(BAD_RET);
    }
    pRtIoSplDvc = (strRtIoSplDvc*)(pRtIoSplDvc->pvDrvRtIoDvcNxt);
    if (_evro_rtus_evro_rtusmodbus_rtu_holding_o_IosOpen(pRtIoSplDvc) != 0)
    {
        printf("Error opening\n");
        return(BAD_RET);
    }
    pRtIoSplDvc = (strRtIoSplDvc*)(pRtIoSplDvc->pvDrvRtIoDvcNxt);
    if (_evro_rtus_evro_rtusmodbus_rtu_holding_i_IosOpen(pRtIoSplDvc) != 0)
    {
        printf("Error opening\n");
        return(BAD_RET);
    }
    pRtIoSplDvc = (strRtIoSplDvc*)(pRtIoSplDvc->pvDrvRtIoDvcNxt);
    if (_evro_rtus_evro_rtusmodbus_rtu_coil_o_IosOpen(pRtIoSplDvc) != 0)
    {
        printf("Error opening\n");
        return(BAD_RET);
    }
    pRtIoSplDvc = (strRtIoSplDvc*)(pRtIoSplDvc->pvDrvRtIoDvcNxt);
    if (_evro_rtus_evro_rtusmodbus_rtu_coil_i_IosOpen(pRtIoSplDvc) != 0)
    {
        printf("Error opening\n");
        return(BAD_RET);
    }
    return (0);
}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_serverIosClose
description : Level 1 device Close function
parameters  :
   (input) strRtIoCpxDvc* pvRtIoDvc :  Run time io struct of the device to close
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_serverIosClose
(
    strRtIoCpxDvc* pvRtIoDvc /* Run time io struct of the device to close */
)
{
    strRtIoSplDvc* pRtIoSplDvc;
    pRtIoSplDvc = pvRtIoDvc->pRtIoSplDvc;
    _evro_rtus_evro_rtusmodbus_rtu_inp_reg_IosClose (pRtIoSplDvc);
    pRtIoSplDvc = (strRtIoSplDvc*)(pRtIoSplDvc->pvDrvRtIoDvcNxt);
    _evro_rtus_evro_rtusmodbus_rtu_inp_bits_IosClose(pRtIoSplDvc);
    pRtIoSplDvc = (strRtIoSplDvc*)(pRtIoSplDvc->pvDrvRtIoDvcNxt);
    _evro_rtus_evro_rtusmodbus_rtu_holding_o_IosClose(pRtIoSplDvc);
    pRtIoSplDvc = (strRtIoSplDvc*)(pRtIoSplDvc->pvDrvRtIoDvcNxt);
    _evro_rtus_evro_rtusmodbus_rtu_holding_i_IosClose(pRtIoSplDvc);
    pRtIoSplDvc = (strRtIoSplDvc*)(pRtIoSplDvc->pvDrvRtIoDvcNxt);
    _evro_rtus_evro_rtusmodbus_rtu_coil_o_IosClose(pRtIoSplDvc);
    pRtIoSplDvc = (strRtIoSplDvc*)(pRtIoSplDvc->pvDrvRtIoDvcNxt);
    _evro_rtus_evro_rtusmodbus_rtu_coil_i_IosClose(pRtIoSplDvc);
//
    //modbus_rtu_rabota = 0;
    modbus_mapping_free(mb_mapping_rtu);
    modbus_free(ctx_rtu);
    printf("MODBUS RTU SERVER FREE MEMORY\n");

    printf("MODBUS RTU SERVER EXIT\n");
    printf("MODBUS RTU SERVER POTOK EXIT\n");
    //pthread_cancel(threadmodbusRTU);
    printf("MODBUS RTU SERVER FREE CONECKT\n");
    sleep(3);
    /////////


}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_i_IosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_i_IosRead
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
    _evro_rtus_evro_rtusmodbus_rtu_coil_i_IosRead(pRtIoSplDvc);

}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_i_IosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_i_IosCtl
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

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_o_IosWrite
description : Simple device Write function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to write
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_o_IosWrite
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
)
{
    /*
     * pRtIoSplDvc parameter allows you to access to strRtIoChan structure
     *  of information for each channel.
     * If required you can then also get strDfIoChan structure.
     *
     * Typical implementation for each channel:
     * (variables refer to structure fields):
         - If not locked (cuIsLocked)
            - Update physical data (pvKerPhyData) with logical data (pvKerData)
            - If a conversion is required, convert the data
              The info is in channel structures in following fields:
                 cuCnvGainTyp != 0 ==> Gain/Offset to applied
                 pfnCnvCall != 0   ==> 'C' conversion to applied
            - Apply just computed electrical value to the actuator
     */

    /*
     * To improve performances:
     * - The number of locked channels is given to avoid testing each of them
     *   when no channels are locked or when all channels are locked.
     *
     * - When a channel is not locked (update required), the physical data can
     *   be used as a previous value and compared to the logical data.
     *   This allows to apply the electrical value to the actuator only in case
     *   of change detection. This is especially interesting in case of time
     *   consuming hardware access (remote I/Os, network, etc.).
     *   Then do not forget to update the physical data with the logical data
     */
    _evro_rtus_evro_rtusmodbus_rtu_coil_o_IosWrite(pRtIoSplDvc);
}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_o_IosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_coil_o_IosCtl
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
    _evro_rtus_evro_rtusmodbus_rtu_coil_o_IosCtl(cuSubFunct,pRtIoSplDvc,huChanNum,pvReserved);
}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_i_IosRead
description : Simple device Read function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to read
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_i_IosRead
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
    _evro_rtus_evro_rtusmodbus_rtu_holding_i_IosRead(pRtIoSplDvc);
}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_i_IosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_i_IosCtl
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

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_o_IosWrite
description : Simple device Write function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to write
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_o_IosWrite
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
)
{
    /*
     * pRtIoSplDvc parameter allows you to access to strRtIoChan structure
     *  of information for each channel.
     * If required you can then also get strDfIoChan structure.
     *
     * Typical implementation for each channel:
     * (variables refer to structure fields):
         - If not locked (cuIsLocked)
            - Update physical data (pvKerPhyData) with logical data (pvKerData)
            - If a conversion is required, convert the data
              The info is in channel structures in following fields:
                 cuCnvGainTyp != 0 ==> Gain/Offset to applied
                 pfnCnvCall != 0   ==> 'C' conversion to applied
            - Apply just computed electrical value to the actuator
     */

    /*
     * To improve performances:
     * - The number of locked channels is given to avoid testing each of them
     *   when no channels are locked or when all channels are locked.
     *
     * - When a channel is not locked (update required), the physical data can
     *   be used as a previous value and compared to the logical data.
     *   This allows to apply the electrical value to the actuator only in case
     *   of change detection. This is especially interesting in case of time
     *   consuming hardware access (remote I/Os, network, etc.).
     *   Then do not forget to update the physical data with the logical data
     */
    _evro_rtus_evro_rtusmodbus_rtu_holding_o_IosWrite(pRtIoSplDvc);
}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_o_IosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_holding_o_IosCtl
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
    _evro_rtus_evro_rtusmodbus_rtu_holding_o_IosCtl(cuSubFunct,pRtIoSplDvc,huChanNum,pvReserved);
}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_bits_IosWrite
description : Simple device Write function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to write
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_bits_IosWrite
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
)
{
    /*
     * pRtIoSplDvc parameter allows you to access to strRtIoChan structure
     *  of information for each channel.
     * If required you can then also get strDfIoChan structure.
     *
     * Typical implementation for each channel:
     * (variables refer to structure fields):
         - If not locked (cuIsLocked)
            - Update physical data (pvKerPhyData) with logical data (pvKerData)
            - If a conversion is required, convert the data
              The info is in channel structures in following fields:
                 cuCnvGainTyp != 0 ==> Gain/Offset to applied
                 pfnCnvCall != 0   ==> 'C' conversion to applied
            - Apply just computed electrical value to the actuator
     */

    /*
     * To improve performances:
     * - The number of locked channels is given to avoid testing each of them
     *   when no channels are locked or when all channels are locked.
     *
     * - When a channel is not locked (update required), the physical data can
     *   be used as a previous value and compared to the logical data.
     *   This allows to apply the electrical value to the actuator only in case
     *   of change detection. This is especially interesting in case of time
     *   consuming hardware access (remote I/Os, network, etc.).
     *   Then do not forget to update the physical data with the logical data
     */
    _evro_rtus_evro_rtusmodbus_rtu_inp_bits_IosWrite(pRtIoSplDvc);
}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_bits_IosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_bits_IosCtl
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
    _evro_rtus_evro_rtusmodbus_rtu_inp_bits_IosCtl(cuSubFunct,pRtIoSplDvc,huChanNum,pvReserved);
}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_reg_IosWrite
description : Simple device Write function
parameters  :
   (input) void* pvRtIoDvc :  Run time io struct of the device to write
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_reg_IosWrite
(
    strRtIoSplDvc* pRtIoSplDvc /* Run time io struct of the device to write */
)
{
    /*
     * pRtIoSplDvc parameter allows you to access to strRtIoChan structure
     *  of information for each channel.
     * If required you can then also get strDfIoChan structure.
     *
     * Typical implementation for each channel:
     * (variables refer to structure fields):
         - If not locked (cuIsLocked)
            - Update physical data (pvKerPhyData) with logical data (pvKerData)
            - If a conversion is required, convert the data
              The info is in channel structures in following fields:
                 cuCnvGainTyp != 0 ==> Gain/Offset to applied
                 pfnCnvCall != 0   ==> 'C' conversion to applied
            - Apply just computed electrical value to the actuator
     */

    /*
     * To improve performances:
     * - The number of locked channels is given to avoid testing each of them
     *   when no channels are locked or when all channels are locked.
     *
     * - When a channel is not locked (update required), the physical data can
     *   be used as a previous value and compared to the logical data.
     *   This allows to apply the electrical value to the actuator only in case
     *   of change detection. This is especially interesting in case of time
     *   consuming hardware access (remote I/Os, network, etc.).
     *   Then do not forget to update the physical data with the logical data
     */
    _evro_rtus_evro_rtusmodbus_rtu_inp_reg_IosWrite(pRtIoSplDvc);
}

/****************************************************************************
function    : _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_reg_IosCtl
description : Simple device Control function
parameters  :
   (input) uchar cuSubFunct :          Sub function parameter.
   (input) strRtIoSplDvc* pRtIoSplDvc: Rt io struct of the spl dvc to control.
   (input) uint16 huChanNum :          Channel number if any.
   (input) void* pvReserved :          Reserved.
return value: None
warning     :
****************************************************************************/

void _evro_rtus_evro_rtusmodbus_rtu_servermodbus_rtu_inp_reg_IosCtl
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
    _evro_rtus_evro_rtusmodbus_rtu_inp_reg_IosCtl(cuSubFunct,pRtIoSplDvc,huChanNum,pvReserved);
}
/* eof ********************************************************************/

