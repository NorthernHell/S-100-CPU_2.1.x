/**************************************************************************
File:               dfbl0cfb.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      11-December-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#ifndef _DFBL0CFB_H /* nested Headers management */
#define _DFBL0CFB_H


/* constants **************************************************************/

/* STATUS */
#define ISA_CFB_STAT_READY          0     /* Ready */
#define ISA_CFB_STAT_INPROGRESS     1     /* In progress */
#define ISA_CFB_STAT_BADID          2     /* Bad ID */
#define ISA_CFB_STAT_NOTREADY       3     /* Not ready */
#define ISA_CFB_STAT_CONNECTFAILED  4     /* Connect has failed */
#define ISA_CFB_STAT_BADPARTNER     5     /* Bad partner */
#define ISA_CFB_STAT_DLGFAILED      6     /* Dialog failed */
#define ISA_CFB_STAT_SNDFAILED      7     /* Send data failed */

/* CFB type */
#define ISA_CFB_TYPE_USEND_S        1     /* USEND_S FB */


/* Position of data */
#define ISA_CFB_MSG_POSDATA         12    /* Position of data */

/* types ******************************************************************/
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uchar       cuInit;           /*!< State of IXL initialization */
   uint16      huCfbConnectNbr;  /*!< Number of CFB CONNECT */
   uint16      huCurChannel;     /*!< Current channel */
   typIxlId    IxlId;            /*!< IXL identifier */
} strCfbHdr;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16         huResNum;      /*!< Remote resource number */
   uint16         huRemoteId;    /*!< Remote identifier */
   typIxlCnxId    IxlCnxId;      /*!< IXL connection identifier */
   struct _s_CfbCnx* pCfbCnx;    /*!< Pointer to CONNECT CFB instance */
} strCfbMng;


/* data *******************************************************************/

/* exported services from module dfbl0cfb.c *******************************/
extern void cfbCallbackActiv(void);

extern uint32 cfbMprConnect
   (
   uchar*  pcuBufferRcv,   /* Question */
   uchar*  pcuBufferSend,  /* Answer */
   uint32  luBufAnswMaxLn  /* Max length of answer */
   );

extern uint32 cfbMprDisconnect
   (
   uchar*  pcuBufferRcv,   /* Question */
   uchar*  pcuBufferSend,  /* Answer */
   uint32  luBufAnswMaxLn  /* Max length of answer */
   );

extern uint32 cfbMprDlg
   (
   uchar*  pcuBufferRcv,   /* Question */
   uchar*  pcuBufferSend,  /* Answer */
   uint32  luBufAnswMaxLn  /* Max length of answer */
   );

#endif  /* nested Headers management */
/* eof ********************************************************************/
