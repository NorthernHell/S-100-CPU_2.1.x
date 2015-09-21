/**************************************************************************
File:               dsys0soc.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      19-October-2000
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Socket abstraction layer definitions.
                    File for Linux.

***************************************************************************
Modifications: (who / date / description)
  
***************************************************************************/
#ifndef _DSYS0SOC_H /* nested Headers management */
#define _DSYS0SOC_H

/*
 * TO DO:
 * Include here header files corresponding
 * to sockets management under your system
 */
//#include <netinet/in.h>

/* constants **************************************************************/
#ifdef LSB3
#define FIONBIO		0x5421
#endif

/* Default value for max number of pending connection */
#define ISA_SOC_DEFAULT_CNX      SOMAXCONN

/* Socket option */
#define ISA_SOC_OPT_BLOCKING     1
#define ISA_SOC_OPT_SNDBUF       2
#define ISA_SOC_OPT_RCVBUF       3
#define ISA_SOC_OPT_NODELAY      4
#define ISA_SOC_OPT_KEEPALIVE    5
#define ISA_SOC_OPT_LINGER       6
#define ISA_SOC_OPT_DONTLINGER   7

/* Blocking option parameter */
#define ISA_SOC_BLOCKING         0 
#define ISA_SOC_NONBLOCKING      1 

/* No delay option parameter */ 
#define ISA_SOC_NODELAY          0 
#define ISA_SOC_PACKET           1 

/* Keep alive option parameter */ 
#define ISA_SOC_KEEPALIVE_ON     0
#define ISA_SOC_KEEPALIVE_OFF    1 

/*
 * TO DO:
 * Adapt the following macros to your system
 */
/* Macro definition */
#define ISA_SOC_ISINVALID(pSocket)  ((*pSocket) == ACE_INVALID_HANDLE)
#define ISA_SOC_RESETID(pSocket)    ((*pSocket) = ACE_INVALID_HANDLE)
#define ISA_SOC_CPYID(pSocketDest, pSocketSrc) ((*pSocketDest) = (*pSocketSrc))

#define ISA_SOC_SETPORT(pSocket,Port) ((pSocket)->sin_port = (ACE_HTONS(Port)))
#define ISA_SOC_ADDCMP(pAdd1, pAdd2) ((pAdd1)->sin_addr.s_addr == \
                                      (pAdd2)->sin_addr.s_addr)
#define ISA_SOC_ADDCPY(pAddDest, pAddSrc) dsysMemCpy(pAddDest, pAddSrc, \
                                                     sizeof(typSOC_ADD))
 
/* types ******************************************************************/

/*
 * TO DO:
 * Adapt the following typedef to your system
 */
//typedef ACE_HANDLE typSOC_ID;
//typedef struct sockaddr_in typSOC_ADD;

/* data *******************************************************************/

/* exported services from module dsys0soc.c *******************************/
extern typSTATUS dsysSocInit(void);

extern void dsysSocExit(void);

extern typSTATUS dsysSocCreate
   (
   typSOC_ID*     pSocId,        /* Out: Socket identifier */
   uchar          cuBlocking     /* In: Blocking option */
   );

extern typSTATUS dsysSocCreateUDP
   (
   typSOC_ID*     pSocId,        /* Out: Socket identifier */
   uchar          cuBlocking     /* In: Blocking option */
   );

extern void dsysSocClose
   (
   typSOC_ID*     pSocId,        /* In: Socket identifier */
   uchar          cuShutdown     /* In: TRUE if shutdown is required */
   );

extern typSTATUS dsysSocBind
   (
   typSOC_ID*     pSocId,        /* In: Socket identifier */
   typSOC_ADD*    pSocAdd        /* In: Socket address */
   );

extern typSTATUS dsysSocListen
   (
   typSOC_ID*     pSocId,        /* In: Socket identifier */
   int32          ldNbrCnx       /* In: Max nbr of pending connections */
   );

extern int32 dsysSocAccept
   (
   typSOC_ID*     pSocId,        /* In: Socket identifier */
   typSOC_ID*     pSocAccepted,  /* Out: New socket identifier */
   typSOC_ADD*    pSocAdd        /* Out: Socket address */
   );

extern typSTATUS dsysSocAddressSet
   (
   char*          psIpAddress,   /* In: IP address */
   uint16         huPort,        /* In: Port */
   typSOC_ADD*    pSocAdd        /* Out: Socket address */
   );

extern typSTATUS dsysSocAddressGet
   (
   typSOC_ADD*    pSocAdd,       /* In: Socket address */
   char*          psIpAddress,   /* Out: IP address */
   uint16         huIpAddSz,     /* In: Size of IP address buffer */
   uint16*        phuPort        /* Out: Port */
   );

extern int32 dsysSocConnect
   (
   typSOC_ID*     pSocId,        /* In: Socket identifier */
   typSOC_ADD*    pSocAdd        /* In: Socket address */
   );

extern int32 dsysSocCheckConnect
   (
   typSOC_ID*     pSocId,        /* In: Socket identifier */
   uint32         luTimeOut      /* In: Time Out */
   );

extern int32 dsysSocReceive
   (
   typSOC_ID*     pSocId,        /* In: Socket identifier */
   void*          pvDest,        /* Out: Location to store data */
   int32          ldBytesNbr     /* In: Number of bytes to receive */
   );

extern int32 dsysSocReceiveFrom
   (
   typSOC_ID*     pSocId,        /* In: Socket identifier */
   void*          pvBuff,        /* Out:Location to store data */
   int32          ldBuffLen,     /* In: Length of buffer */
   typSOC_ADD*    pSocAdd        /* Out:Source address of received data */
   );

extern int32 dsysSocCheckReceive
   (
   typSOC_ID*     pSocId,        /* In: Socket identifier */
   uint32         luTimeOut      /* In: Time Out */
   );

extern int32 dsysSocSend
   (
   typSOC_ID*     pSocId,        /* In: Socket identifier */
   void*          pvSrc,         /* In: Location to get data */
   int32          ldBytesNbr     /* In: Number of byes to send */
   );

extern int32 dsysSocSendTo
   (
   typSOC_ID*     pSocId,        /* In: Socket UDP identifier */
   void*          pvBuff,        /* In: Pointer to data to send */
   int32          ldBuffLen,     /* In: Length of data to send */
   typSOC_ADD*    pSocAdd        /* In: Address to send data to */ 
   );

extern typSTATUS dsysSocOptionSet
   (
   typSOC_ID*     pSocId,        /* In: Socket identifier */
   int32          ldOption,      /* In: Option */
   int32          ldParam        /* In: Option value */
   );

extern typSTATUS dsysSocGetHostIp
   (
   char*          psIpAddress,   /* Out: IP address string */
   uint32*        pluIpAddress   /* Out: IP address */
   );

#endif  /* nested Headers management */
/* eof ********************************************************************/
