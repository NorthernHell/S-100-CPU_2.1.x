/**************************************************************************
File:               dkmp0pro.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      4-December-1997
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Kernel Server Message Processing:
                        MSGPROC: Function prototypes


***************************************************************************
Modifications: (who / date / description)
---4.01 Released---
JFO/02-Mar-1999/ MIB Implementation
EDS/27-May-1999/ Connections invalidation at resource stop
   Added pCnx param to kmpMprRead/Write() prototypes
   Added pcuStateEdge param to kmpCtlRStop() & kmpCtlRUnload() prototypes

---4.02 Released---
EDS/05-Jan-2000/ Get list of locked IO management
   Added kmpIosLockedListGet() prototype
EDS/13-Jan-2000/ Enhancement of the way com requests are polled
   Added kmpConnect() prototype

---4.03 Released---
EDS/03-Apr-2000/ SFC Breakpoints addon
   Added kmpBkpXxx() prototypes
EDS/20-Jun-2000/ Upload data add on
   Added kmpUploadData() prototype
EDS/25-Aug-2000/ Allow adding of variables in MDF
   Added kmpXxxRdbCrcXxx() prototypes
EDS/18-Nov-2000/ Mono task implementation
   Get struct from to dker0srv.h and put conditional (XX_IXLMIB XX_MONOTASK)
   Modified strSrvCnx => typSrvCnx
   Added kmpIxsRead() & kmpIxsWrite() prototypes
   Added ITGTDEF_IXLMIB

---4.11 Released---
VMO/13-Mar-2002/ Hot restart 
   Added kmpHotXxx() protos.

---4.12 Released---
VMO/12-June-2002/ SFC function block
   Added kmpTgtRdccGet() proto
GM/3-Oct-2002/ Step by step debugging
   Added kmpDbgxxx() proto


***************************************************************************/
#ifndef _DKMP0PRO_H   /* nested Headers management */
#define _DKMP0PRO_H   

#include <dsmp0srv.h> /* Nested header required */

/* constants **************************************************************/

/* types ******************************************************************/
/* Declaration of extra connection info */

#ifdef ITGTDEF_IXLMIB

/* Structure to store MIB information */
typedef struct
{
   uchar       cuSpcNum;      /* Client space number */
   typSPC_ID   SpcId;         /* Space identifier */
   void*       pvSpcAdd;      /* First address of space */
   uint32      luSpcSz;       /* Space size */
   uint32      luBaseOffset;  /* Base offset in client space */
   typIxlVa    VaBase;        /* Va of variable for base */
   uint32      luTotSize;     /* Total size reserved in client space */
} strKerSrvMibInfo;

#endif

/* Extra connection info */
/* Not implemented/used in mono-task implementation */
#ifndef ITGTDEF_MONOTASK

typedef struct
{
#ifdef ITGTDEF_IXLMIB
   strKerSrvMibInfo MibInfo; /* MIB information */
#endif
   uchar cuIsInvalid; /* Set if connection no more valid */
   uchar cuReserved;
} strKerSrvInfo;

#endif

/* data *******************************************************************/

/* exported services from module dker0mpr.c *******************************/
extern uint32 kmpCycleMsgProceed
   (
   uchar* pcuBufferRcv,    /*In:  Question */   
   uint32 luBufRcvLn,      /*In:  Length of question */
   uchar* pcuBufferSend,   /*Out: Answer */
   uint32 luBufAnswMaxLn,  /*In:  Max length of answer */ 
   uint32 luNumRequest,    /*In:  Current request Number in this cycle */
   uchar  cuLast,          /*In:  If TRUE, Previous request was last one  */
   uchar* pcuNextRequired, /*Out: Set if next request is required */
   typSrvCnx* pCnx         /*In:  Pointer to current connection */
   ); 

extern uint32 kmpWaitMsgProceed
   (
   uchar* pcuBufferRcv,    /*In:  Question */   
   uint32 luBufRcvLn,      /*In:  Length of question */
   uchar* pcuBufferSend,   /*Out: Answer */
   uint32 luBufAnswMaxLn,  /*In:  Max length of answer */ 
   uint32 luNumRequest,    /*In:  Current request Number in this cycle */
   uchar  cuLast,          /*In:  If TRUE, Previous request was last one  */
   uchar* pcuNextRequired, /*Out: Set if next request is required */
   typSrvCnx* pCnx         /*In:  Pointer to current connection */
   ); 

extern void kmpConnect
   (
   typSrvCnx*  pCnx  /*In: Pointer to current connection */ 
   );

extern void kmpDisconnect
   (
   typSrvCnx*  pCnx  /*In: Pointer to current connection */ 
   );

/* exported services from module dkmp0rwr.c *******************************/
extern uint32 kmpMprWrite 
   (
   uchar* pcuBufferRcv,    /* In:  Buffer where question is stored */
   uint32 luBufRcvLn,      /* In:  Size of the question */
   uchar* pcuBufferSend,   /* Out: Buffer to put the answer */
   uint32 luBufAnswMaxLn,  /* In:  Maximum length of answer */
   typSrvCnx* pCnx         /* In:  Pointer to current connection */
   );   /* Returns: Length of answer if succesful, 0 if  error */

extern uint32 kmpMprRead 
   (
   uchar* pcuBufferRcv,    /* In:  Buffer where question is stored */
   uchar* pcuBufferSend,   /* Out: Buffer to put the answer */
   uint32 luBufAnswMaxLn,  /* In:  Maximum length of answer */
   typSrvCnx* pCnx         /* In:  Pointer to current connection */
   );  /* Returns: Length of answer if succesful, 0 if  error */

#ifdef ITGTDEF_MONOTASK
extern uchar kmpIxsRead
   (
   strIxlVarDesc* pVarDesc,  /* Description of variables to read */
   uint16 huNbVar            /* Number of variables */
   );                        /* Returns: 0 if successful, ISA_RC_XX else */

extern uchar kmpIxsWrite
   (
   strIxlVarDesc* pVarDesc,  /* Description of variables to write */
   uint16 huNbVar            /* Number of variables */
   );                        /* Returns: 0 if successful, ISA_RC_XX else */
#endif

/* exported services from module dkmp0dwn.c *******************************/
extern uint32 kmpDwnPrepare
   (
   uchar* pcuBufferRcv,   /* Question */
   uchar* pcuBufferSend,  /* Answer */
   uint32 luBufAnswMaxLn  /* Max length of answer */
   );

extern uint32 kmpDwnConfPkTrans
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpDwnPouAlloc
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpDwnPouPkTrans
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpDwnLink
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpDwnAbort
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpDwnOpMdInit
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpDwnOpMdPkTrans
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpDwnMdfNewDlt
   (
   uchar*  pcuBufferRcv,   /* Question */
   uchar*  pcuBufferSend,  /* Answer */
   uint32  luBufAnswMaxLn  /* Max length of answer */
   );

extern uint32 kmpDwnMdfDltPkTrans
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpDwnMdfClean
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpDwnMdfRdbCrcAdd
   (
   uchar*  pcuBufferRcv,   /* In: Question */ 
   uchar*  pcuBufferSend   /* Out: Answer */ 
   );                      /* Returns: Answ length if successful, 0 if error */

extern uint32 kmpDwnMdfDltAccept
   (
   uchar*  pcuBufferRcv,    /* Question */ 
   uchar*  pcuBufferSend,   /* Answer */ 
   uint32  luBufAnswMaxLn   /* Max length of answer */ 
   );

/* exported services from module dkmp0ctl.c *******************************/
extern uint32 kmpCtlRStart
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpCtlRStop
   (
   uchar*  pcuBufferRcv,   /*In:  Question */ 
   uchar*  pcuBufferSend,  /*Out: Answer */ 
   uint32  luBufAnswMaxLn, /*In:  Max length of answer */
   uchar*  pcuStateEdge    /*Out: Set if state successfuly changed */ 
   );

extern uint32 kmpCtlRSave
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpCtlRRestore
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpCtlRUnload
   (
   uchar*  pcuBufferRcv,   /*In:  Question */ 
   uchar*  pcuBufferSend,  /*Out: Answer */ 
   uint32  luBufAnswMaxLn, /*In:  Max length of answer */
   uchar*  pcuStateEdge    /*Out: Set if state successfuly changed */ 
   );

extern uint32 kmpCtlShutDown
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpCtlKerStateGet
   (
   uchar* pcuBufferRcv,    /* Question */ 
   uchar* pcuBufferSend,   /* Answer */ 
   uint32 luBufAnswMaxLn   /* Max length of answer */ 
   );  

/* exported services from module dkmp0mis.c *******************************/
extern uint32 kmpResInfoGet
   (
   uchar   cuType,        /* Type of module to get info from (conf, pou, )*/
   uchar*  pcuBufferRcv,  /* Question */ 
   uchar*  pcuBufferSend, /* Answer */ 
   uint32  luBufAnswMaxLn /* Max length of answer */ 
   );

extern uint32 kmpResRdbCrcCheck
   (
   uchar*  pcuBufferRcv,   /* In: Question */ 
   uchar*  pcuBufferSend   /* Out: Answer */ 
   );                      /* Returns: Answ length if successful, 0 if error */

extern uint32 kmpUploadData
   (
   uchar*  pcuBufferRcv,   /* In: Question */ 
   uchar*  pcuBufferSend,  /* Out: Answer */ 
   uint32  luBufAnswMaxLn  /* In: Max length of answer */ 
   );                      /* Returns: Answ length if successful, 0 if error */

extern uint32 kmpTgtRdccGet
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpCapabilityGet
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpTgtGetIxlBufSz
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

/* exported services from module dkmp0ios.c *******************************/
extern uint32 kmpIosLock
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpIosUnlock
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpIosIsLocked
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpIosOutWrite /* OBSOLETE. Normal write now manages IOs. */
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpIosLockedListGet
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

#ifdef ITGTDEF_VARLOCK
extern uint32 kmpIosLockEnh
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpIosUnlockEnh
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );
#endif

/* exported services from module dkmp0mib.c *******************************/
extern uint32 kmpMibSpcSet
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn, /* Max length of answer */ 
   typSrvCnx* pCnx         /* Pointer to current connection */
   );

extern uint32 kmpMibSpcReset
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn, /* Max length of answer */ 
   typSrvCnx* pCnx         /* Pointer to current connection */
   );

extern uint32 kmpMibRefresh
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn, /* Max length of answer */ 
   typSrvCnx* pCnx         /* Pointer to current connection */
   );

extern void kmpMibDisconnect
   (
   typSrvCnx*  pCnx        /* Pointer to current connection */ 
   );

/* exported services from module dkmp0bkp.c *******************************/
extern uint32 kmpBkpSfcSet
   (
   uchar*  pcuBufferRcv,   /* In: Question */ 
   uchar*  pcuBufferSend,  /* Out: Answer */ 
   uint32  luBufAnswMaxLn  /* In: Max length of answer */ 
   );                      /* Returns: Answ length if successful, 0 if error */

extern uint32 kmpBkpSfcRemove
   (
   uchar*  pcuBufferRcv,   /* In: Question */ 
   uchar*  pcuBufferSend,  /* Out: Answer */ 
   uint32  luBufAnswMaxLn  /* In: Max length of answer */ 
   );                      /* Returns: Answ length if successful, 0 if error */

extern uint32 kmpBkpSfcForceTraClrng
   (
   uchar*  pcuBufferRcv,   /* In: Question */ 
   uchar*  pcuBufferSend,  /* Out: Answer */ 
   uint32  luBufAnswMaxLn  /* In: Max length of answer */ 
   );                      /* Returns: Answ length if successful, 0 if error */

/* exported services from module dkmp0hot.c *******************************/
extern uint32 kmpHotBackup
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpHotCheck
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpHotRealize
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpHotSave
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpHotLoad
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpHotDelete
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

/* exported services from module dkmp0dbg.c *******************************/
extern uint32 kmpDbgBkPSet
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpDbgBkPRemove
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpDbgBkPListGet
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpDbgExecute
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

extern uint32 kmpDbgCallStackGet
   (
   uchar*  pcuBufferRcv,   /* Question */ 
   uchar*  pcuBufferSend,  /* Answer */ 
   uint32  luBufAnswMaxLn  /* Max length of answer */ 
   );

#ifdef ITGTDEF_FAILOVER
/* exported services from module dkmp0dbg.c *******************************/
extern uint32 kmpFailoverSendSyncData
   (
   uchar    *pcuBufferRcv,    /* Question */
   uchar    *pcuBufferSend,   /* Answer */
   uint32   luBufAnswMaxLn    /* Max length of answer */ 
   );

extern uint32 kmpFailoverSendReceiveCrc
   (
   uchar*   pcuBufferRcv,     /* Question */
   uchar    *pcuBufferSend,   /* Answer */
   uint32   luBufAnswMaxLn    /* Max length of answer */ 
   );
#endif /* #ifdef ITGTDEF_FAILOVER */

#endif  /* nested Headers management */
/* eof ********************************************************************/
