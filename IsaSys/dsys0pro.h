/**************************************************************************
File:               dsys0pro
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      03-December-2010
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Target system prototypes

***************************************************************************
Modifications: (who / date / description)

---4.03 Released---
JFO/10-Oct-2000/ 
   Added dsysDsaInfo(), dsysDsaLineGet(), dsysDsaCreate(), dsysDsaRead()
    and dsysDsaWrite().
JFO/31-Oct-2000/
   Added dsysTimeGmtRead().
EDS/21-Dec-2000/ Mono task implementation
   Prototypes of no more required interfaces (sem, msq, ntf) are conditioned  
    with ITGTDEF_MONOTASK

---4.10 Released---
JFO/30-Aug-2001/ BUG 1362: Floating conversions.
   Added dsysStrToFloat() and dsysFloatToStr().
EDS/05-Oct-2001/ Variables locking 
   Added dsysMemCpyChk()

---4.13 Released---
COL/22-Nov-2001/ Error report.
   Added dsysWngShCreate(), dsysWngShDelete(), dsysWngShOpen(), 
   dsysWngShClose(), dsysWngShSave(), dsysWngShLoad(), dsysWngShSet() and 
   dsysWngShGet().
FG/20-Aug-2002/
   Added dsysResTaskIdGet(), dsysPryGet(), dsysPrySelfSet(), dsysPryCmp()
   dsysArgIniFileNameGet(), dsysTimeReadRtc()

---5.00 Released---
OL/02-Feb-2005/ New data type
   Add TIC code for INT, LINT, USINT, USINT, UDINT, ULINT, LREAL and DATE.

---5.01 Released---
FT/17-Mar-2006/RFS-4118
   New function dsysFctErrnoSetNoWarn.

---5.21 Released---
FT/21-Feb-2008/ RFS-6542
   Remove all calls to the C library string and memory functions.

---5.22 Released---
FT/21-Dec-2008/ RFS-6874
   Merge HSD driver on mono resource targets.

***************************************************************************/
#ifndef _DSYS0PRO_H  /* nested Headers management */
#define _DSYS0PRO_H 

/* constants **************************************************************/

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module dsys0ini.c *******************************/
extern ISASYSDLL typSTATUS dsysInit
   (
   uchar    cuCallerType,  /* In: Calling process type  (Kernel,Ixl,..) */
   uint16   huOwner,       /* In: Calling process owner value (Slave num, */
                           /*     client num,..) */
   int32    ldArgc,        /* In: Number of arguments */
   char*    ppsArgv[]      /* In: Array of arguments */
   );
                                        
extern ISASYSDLL typSTATUS dsysExit
   (
   uchar   cuCallerType,   /* In: Calling process type */
   uint16  huOwner         /* In: Calling process owner value */
   ); 

extern ISASYSDLL uchar dsysLoopBreak
   (
   uchar    cuAutomaticReset     /* In: Reset break event if TRUE */
   );

extern ISASYSDLL uchar dsysLoopRestart
   (
   uchar    cuAutomaticReset     /* In: Reset restart event if TRUE */
   );

extern ISASYSDLL char* dsysPathNameGet
   (
   uint16   huOwnerNum,    /* In: Owner number */
   uchar    cuObjNum,      /* In: Object number */
   uchar    cuType         /* In: Type */
   );

extern ISASYSDLL typSTATUS dsysFileNameGet
   (
   uint16   huOwnerNum,    /* In: Owner number */
   uchar    cuObjNum,      /* In: Object number */
   uchar    cuType,        /* In: Type */
   char*    psName         /* Out:Object Name */
   );

extern ISASYSDLL typSTATUS dsysFilObjListGet
   (
   uint16   huResNbr,      /* In:  Number of element of the array */
   uint16*  phuList,       /* Out: List of resource number */
   uint16*  phuListSz,     /* Out: Number of resources */
   uchar    cuObjNum,      /* In:  Object Number */
   uchar    cuObjTyp       /* In:  Object Type */
   );

extern ISASYSDLL typSTATUS dsysResTaskIdGet
   (
   uint16    huResNum,        /* In: Resource number */
   typTSK_ID *pTskId          /* Out: Task id of the resource */
   );

extern ISASYSDLL typSTATUS dsysPryGet
   (
   typTSK_ID  *pTskId,        /* In: Task identifier */
   typPRIO_ID *pPrioId        /* Out: Priority identifier */
   );

extern ISASYSDLL typSTATUS dsysPrySelfSet
   (
   typPRIO_ID *pPrioId,       /* In: New priority */
   int16 hdPryDelta           /* In: Delta of new priority to be set */
   );

extern ISASYSDLL int16 dsysPryCmp
   (
   typPRIO_ID   *pPrioId1,   /* In: First priority */
   typPRIO_ID   *pPrioId2    /* In: Second priority */
   );

/* exported services from module dsys0arg.c *******************************/
extern ISASYSDLL int32 dsysArgGet
   (
   uchar    cuSelector,       /* In: Select the operation to do */
   const char*    psComponent,      /* In: Component's name */
   const char*    psParamName,      /* In: Parameter's name */
   void*    pvBuffer,         /* Out: Buffer where store data */
   uint32   luLnOfBuffer,     /* In: Length of the buffer */
   uint32	luDfValue,        /* In: Default value */
   uchar    cuIndex           /* In: Index of the data to get */
   );

extern ISASYSDLL void dsysArgOwnerNumSet
   (
   uint16   huOwnerNum        /* In: Owner number */
   );

extern ISASYSDLL char* dsysArgIniFileNameGet(void);

extern ISASYSDLL char** convertArgs
	(
	int argc,          /*In: Number of arguments*/
	ACE_TCHAR** argv  /*In: Array of arguments using ACE_TCHAR*/
	);

/* exported services from module dsys0spc.c *******************************/
extern ISASYSDLL void* dsysSpcCreate
   (
   typSPC_ID*  pSpcId,        /* Out: Pointer on space identifier */
   uint16      huOwnerNum,    /* In : Owner number */
   uchar       cuSpaceNum,    /* In : Space Number */
   uint32      luSize         /* In : Size of the space to be allocated   */
                              /*      If zero then an error occurs */
   );

extern ISASYSDLL typSTATUS dsysSpcDelete
   (
   typSPC_ID*  pSpcId,        /* In: Pointer on space identifier */
   void*       pvAddress      /* In: Pointer on space */
   );

extern ISASYSDLL void* dsysSpcLink
   (
   typSPC_ID*  pSpcId,        /* Out: Pointer on space identifier */
   uint16      huOwnerNum,    /* In:  Owner number */
   uchar       cuSpaceNum,    /* In:  Space number */
   uint32*     pluSize        /* Out: Size of the space */
   );

extern ISASYSDLL typSTATUS dsysSpcUnlink
   (
   typSPC_ID*  pSpcId,        /* In: Pointer on space identifier */
   void*       pvAddress      /* In: Pointer on space */
   );

extern ISASYSDLL typSTATUS dsysSpcSave 
   (
   uint16   huOwnerNum,          /* In : Owner number  */
   uchar    cuSpaceNum,          /* In : Space number */
   uint16   huBlockNbr,          /* In : Number of blocks */
   uint32   pluSize[],           /* In : Size of each segment */
   void*    ppvBlockAddress[]    /* In : Addresses of each block */
   );  

extern ISASYSDLL void* dsysSpcLoad
   (
   typSPC_ID*  pSpcId,              /* Out: Space identifier */
   uint16      huOwnerNum,          /* In : Owner number  */
   uchar       cuSpaceNum,          /* In : Space number */
   uint32      luSizeOffset,        /* In : Offset */
   uint32*     pluLoadedSpcSize     /* Out: Size of space */
   );  

extern ISASYSDLL uint32 dsysSpcRead
   (
   uint16      huOwnerNum,          /* In: Owner number  */
   uchar       cuSpaceNum,          /* In: Space number */
   uint32      luOffset,            /* In: Offset */
   uint32      luSize,              /* In: Size of data to read */
   void*       pvBuffer             /* Out: Buffer where to store data */
   ); 

extern ISASYSDLL typSTATUS dsysSpcBkupRemove
   (
   uint16   huOwnerNum,          /* In : Owner number  */
   uchar    cuSpaceNum           /* In : Space number */
   );

extern ISASYSDLL void* dsysMultiSpcCreate
   (
   typSPC_ID*  pSpcId,              /* Out: Space identifier */
   uint16      huOwnerNum,          /* In : Owner number */
   uchar       cuSpaceNum,          /* In : Space number */
   uint16      huBlockNbr,          /* In : Number of blocks */
   uint32      pluSize[],           /* In : Size of each block */
   void*       ppvBlockAddresses[]  /* Out: Address of each block */
   );  

extern ISASYSDLL typSTATUS dsysMultiSpcDelete
   (
   typSPC_ID*  pSpcId,              /* In : Space identifier */
   uint16      huBlockNbr,          /* In : Number of blocks */
   uint32      pluSize[],           /* In : Size of each block */
   void*       ppvBlockAddresses[]  /* In : Address of each block */
   );

extern ISASYSDLL void* dsysMultiSpcLoad
   (
   uint16      huOwnerNum,          /* In:  Owner number  */
   uchar       cuSpaceNum,          /* In:  Space number */
   uint16      huBlockNbr,          /* In:  Number of blocks */
   uint32      pluSize[],           /* In:  Size of each block */
   void*       ppvBlockAddresses[]  /* In:  Address of each block */
   );

/* exported services from module dsys0dsa.c *******************************/
extern ISASYSDLL typSTATUS dsysDsaCreate
   (
   typDSA_ID*     pDsaId,        /* Out: DSA identifier */
   char*          psName         /* In: Name of the DSA */
   );

extern ISASYSDLL uint32 dsysDsaOpen
   (
   typDSA_ID*     pDsaId,        /* Out: DSA identifier */
   char*          psName         /* In: Name of the DSA */
   );

extern ISASYSDLL void dsysDsaClose
   (
   typDSA_ID*     pDsaId         /* In: DSA identifier */
   );

extern ISASYSDLL int32 dsysDsaInfo
   (
   char*          psName,        /* In: Name of the DSA */
   strSysGmt*     pSysGmt        /* Out: Last modified date */
   );

extern ISASYSDLL typSTATUS dsysDsaRemove
   (
   char*          psName         /* In: Name of the DSA */
   );

extern ISASYSDLL typSTATUS dsysDsaCharGet
   (
   typDSA_ID*     pDsaId,        /* In: DSA identifier */
   char*          pcReadChar     /* Out: Read character */ 
   );

extern ISASYSDLL int32 dsysDsaLineGet
   (
   typDSA_ID*     pDsaId,        /* In: DSA identifier */ 
   char*          psBuffer,      /* Out: Buffer */ 
   uint16         huBufferSz     /* In: Size of buffer */ 
   );

extern ISASYSDLL void dsysDsaRewind
   (
   typDSA_ID*     pDsaId         /* In: DSA identifier */
   );

extern ISASYSDLL int32 dsysDsaRead
   (
   typDSA_ID*     pDsaId,        /* In: DSA identifier */
   void*          pvData,        /* Out: Place to store reading data */
   int32          ldSize         /* In: Size of the memory block */
   );

extern ISASYSDLL typSTATUS dsysDsaWrite
   (
   typDSA_ID*     pDsaId,        /* In: DSA identifier */
   void*          pvData,        /* In: Pointer to memory block to write */
   int32          ldSize         /* In: Size of the memory block */
   );

extern ISASYSDLL typSTATUS dsysDsaReadPckt
   (
   char*          psName,        /* In: Name of the DSA */
   uint32         luPkNbByteOfs, /* In: Offset where to store packet */
   uint32         luPkNbByte,    /* In: Packet number of byte to read */
   void*          pvPkData       /* Out: Where to put read data packet */
   );

extern ISASYSDLL typSTATUS dsysDsaWritePckt
   (
   char*          psName,        /* In: Name of the DSA */
   uint32         luPkNbByteOfs, /* In: Offset where to store packet */
   uint32         luPkNbByte,    /* In: Packet number of bytes to write */
   uint32         luTotNbByte,   /* In: Total number of bytes (if possible) */
   void*          pvPkData       /* In: Data packet */
   );

extern ISASYSDLL typSTATUS dsysDsaSeek
   (
   typDSA_ID*     pDsaId,        /* Out:DSA identifier */
   uint32         luPkNbByteOfs  /* In: Offset where to store packet */
   );

/* exported services from module dsys0tim.c *******************************/
extern ISASYSDLL void dsysTimeRead
   (
   uint32*        pluTime        /* Out: Time read in ms */ 
   );

extern ISASYSDLL void dsysTimeWait
   (
   uint32         luDelay        /* In: Duration in ms */ 
   );
#ifdef ITGTDEF_MICRO_CYC_TIME /* RFS 7891 */
extern ISASYSDLL void dsysMicroTimeRead
   (
	uint32*        pluTime        /* Out: Time read in us */ 
   );
extern ISASYSDLL void dsysMicroTimeWait
   (
   uint32         luDelay        /* In: Duration in us */ 
   );
#endif
extern ISASYSDLL void dsysTimeGmtRead
   (
   strSysGmt*     pSysGmt        /* Out: Greenwich Meridian Time */
   );

extern ISASYSDLL void dsysTimeLocalRead
   (
   strSysGmt*     pSysGmt        /* Out: Local Time */
   );

extern ISASYSDLL typSTATUS dsysTimeReadRtc
   (
   strSysRtc*     pSysRtc        /* Out: UTC time relative to 01/01/2000 00:00:00 in sec/msec */
   );
#ifndef __WATCOMC__
	extern ISASYSDLL void initHighResTimer(int iter=3);
#else
	extern ISASYSDLL void initHighResTimer(int iter);
#endif

	extern ISASYSDLL uint64 dsysGetHighResTimerMks();


/* exported services from module dsys0fcr.c *******************************/
extern ISASYSDLL void dsysFctErrnoSet
   (
   typERRNO FctErrno  /* In: Errno to set */
   );

extern ISASYSDLL void dsysFctErrnoSetNoWarn
   (
   typERRNO FctErrno  /* In: Errno to set */
   );

extern ISASYSDLL typERRNO dsysFctErrnoGet(void);
extern ISASYSDLL void dsysFctErrnoPrint
   (
   typERRNO FctErrno  /* In: Errno to display */
   ); 

/* Semaphores, Message Queues and Notification only for Multi-Task OR Mono-Task with HSD */
#if (!defined ITGTDEF_MONOTASK) || ((defined ITGTDEF_MONOTASK) && (defined ITGTDEF_HSD)) || (defined ITGTDEF_INTERRUPT)

/* exported services from module dsys0sem.c *******************************/
extern ISASYSDLL typSTATUS dsysSemBCreate
   (
   typSEM_ID*  pSemId,        /* Out: Semaphore identifier */
   uint16      huOwnerNum,    /* In:  Owner number */
   uchar       cuSemNum,      /* In:  Semaphore Number */
   uchar       cuInitValue    /* In:  Initiate value */
   );

extern ISASYSDLL typSTATUS dsysSemMCreate
   (
   typSEM_ID*  pSemId,        /* Out: Semaphore identifier */
   uint16      huOwnerNum,    /* In:  Owner number */
   uchar       cuSemNum       /* In:  Semaphore Number */
   );

extern ISASYSDLL typSTATUS dsysSemBDelete
   (
   typSEM_ID*     pSemId      /* In: Semaphore identifier */
   );

extern ISASYSDLL typSTATUS dsysSemMDelete
   (
   typSEM_ID*     pSemId      /* In: Semaphore identifier */
   );

extern ISASYSDLL typSTATUS dsysSemBOpen
   (
   typSEM_ID*  pSemId,        /* Out: Semaphore identifier */
   uint16      huOwnerNum,    /* In:  Owner number */
   uchar       cuSemNum       /* In:  Semaphore Number */
   );

extern ISASYSDLL typSTATUS dsysSemMOpen
   (
   typSEM_ID*  pSemId,           /* Out: Semaphore identifier */
   uint16      huOwnerNum,       /* In:  Owner number */
   uchar       cuSemNum          /* In:  Semaphore Number */
   );

extern ISASYSDLL typSTATUS dsysSemBClose
   (
   typSEM_ID*     pSemId      /* In: Semaphore identifier */
   );

extern ISASYSDLL typSTATUS dsysSemMClose
   (
   typSEM_ID*     pSemId      /* In: Semaphore identifier */
   );

extern ISASYSDLL typSTATUS dsysSemBGive
   (
   typSEM_ID*     pSemId      /* In: Semaphore identifier */
   );

extern ISASYSDLL typSTATUS dsysSemMGive
   (
   typSEM_ID*     pSemId      /* In: Semaphore identifier */
   );

extern ISASYSDLL typSTATUS dsysSemBTake
   (
   typSEM_ID*     pSemId,     /* In: Semaphore identifier */
   uint32         luTimeOut   /* In: Time out specification(ms):   */
                              /*     ISA_WAITFOREVER=wait for ever */
                              /*     ISA_NOWAIT=no wait            */
   );

extern ISASYSDLL typSTATUS dsysSemMTake
   (
   typSEM_ID*     pSemId,     /* In: Semaphore identifier */
   uint32         luTimeOut   /* In: Time out specification(ms):   */
                              /*     ISA_WAITFOREVER=wait for ever */
                              /*     ISA_NOWAIT=no wait            */
   );

/* exported services from module dsys0msq.c *******************************/
extern ISASYSDLL typSTATUS dsysMsgQCreate
   (
   typMSG_Q_ID*   pmqId,            /* Out: Message queue ID */
   uint16         huQOwnerNum,      /* In:  Owner number */
   uint16         huQUserNum,       /* In:  User number */
   uchar          cuQType,          /* In:  Type */
   uint32         luMaxMsgs,        /* In:  Max number of messages */
   uint32         luMaxMsgLength    /* In:  Max. message length */
   );

extern ISASYSDLL typSTATUS dsysMsgQDelete
   (
   typMSG_Q_ID*   pmqId             /* In: Message queue ID */
   );

extern ISASYSDLL typSTATUS dsysMsgQOpen
   (
   typMSG_Q_ID*   pmqId,            /* Out: Message queue ID */
   uint16         huQOwnerNum,      /* In:  Owner number */
   uint16         huQUserNum,       /* In:  User number */
   uchar          cuQType           /* In:  Type */
   );

extern ISASYSDLL typSTATUS dsysMsgQClose
   (
   typMSG_Q_ID*   pmqId             /* In: Message queue ID */
   );

extern ISASYSDLL typSTATUS dsysMsgQSend
   (
   typMSG_Q_ID*   pmqId,            /* In: Message queue ID */
   uchar*         pcuBuffer,        /* In: Message to send */
   uint32         luLength,         /* In: Length message to send */
   uint32         luTimeOut,        /* In: Max time before exit */
                                    /*     ISA_WAITFOREVER=wait for ever */
                                    /*     ISA_NOWAIT=no wait            */
   uchar          cuPriority        /* In: Message priority to send if exist */
   );
  
extern ISASYSDLL int32 dsysMsgQReceive
   (
   typMSG_Q_ID*   pmqId,            /* In:  Message queue ID */
   uchar*         pcuBuffer,        /* Out: Buffer where to get message */
   uint32         luLength,         /* In:  Max buffer length available */
   uint32         luTimeOut         /* In:  Max time before exit */
                                    /*      ISA_WAITFOREVER=wait for ever */
                                    /*      ISA_NOWAIT=no wait            */
   );

/* exported services from module dsys0ntf.c *******************************/
extern ISASYSDLL typPID dsysNotifPidSelf(void);
extern ISASYSDLL typSTATUS dsysNotifHdlInstall
   (
   typNTFHDL_ID*     pNtfHdlId,     /* Out: Notif handler identifier */
   typPFN_NTFHDL     PfnNtfHdl,     /* In : Handler routine */
   uint32            luSignalCode   /* In : Signal to intercept */
   );

extern ISASYSDLL void dsysNotifHdlUninstall
   (
   typNTFHDL_ID*  pNtfHdlId   /* In: Notif handler identifier */
   );

extern ISASYSDLL typSTATUS dsysNotifSignalOpen
   (
   typNTFSGN_ID*  pNtfSgnId,     /* Out: Notif signal identifier */
   typPID         Pid,           /* In : Process identifier of other task */
   uint32         luSignalCode   /* In : Signal code to send */
   );

extern ISASYSDLL void dsysNotifSignalClose
   (
   typNTFSGN_ID* pNtfSgnId    /* In: Notif signal identifier */
   );

extern ISASYSDLL typSTATUS dsysNotifSignal
   (
   typNTFSGN_ID*  pNtfSgnId   /* In: Notif signal identifier */
   );

#endif /* (!defined ITGTDEF_MONOTASK) || ((defined ITGTDEF_MONOTASK) && (defined ITGTDEF_HSD)) || (defined ITGTDEF_INTERRUPT) */

/* exported services from module dsys0wng.c *******************************/
extern ISASYSDLL void dsysWngNbModify
   (
   uchar cuMaxNbWng  /* Maximum number of queued warnings */ 
   );
  
extern ISASYSDLL void dsysWngSet   
   (
   uint16 huNum,     /* Warning Number */ 
   uint32 luArg      /* Argument Number */ 
   );

extern ISASYSDLL void dsysWngXSet   
   (
   uint16 huNum,     /* Warning Number */ 
   uint32 luArg,     /* Argument Number */ 
   uchar  cuCmd      /* Command */ 
   );

extern ISASYSDLL void dsysWngGet   
   (
   char**  ppsCmptNm,  /*Out: Component name */
   uint16* phuNum,     /*Out: Warning number */ 
   uint32* pluArg      /*Out: Argument number */ 
   ); 

extern ISASYSDLL typSTATUS dsysWngShCreate
   (
   uint16 huOwnerTaskId,   /* In: Task number */ 
   uint32 luErrorNbr       /* In: Number of error that can be stored */ 
   );

extern ISASYSDLL typSTATUS dsysWngShDelete(void);

extern ISASYSDLL typSTATUS dsysWngShOpen
   (
   uint16 huOwnerTaskId,   /* In: Task id, of owner of error module */ 
   uint16 huTaskId         /* In: Task number */ 
   );

extern ISASYSDLL typSTATUS dsysWngShClose(void);

extern ISASYSDLL typSTATUS dsysWngShSave(void);

extern ISASYSDLL typSTATUS dsysWngShLoad
   (
   uint16 huOwnerTaskId   /* In: Task number */ 
   );

extern ISASYSDLL typSTATUS dsysWngShSet
   (
   int32  ldError,         /* In: Error number to stored */ 
   uint32 luArg,           /* In: Argument of the error */ 
   const char*  psParam          /* In: Parameter */
   );

extern ISASYSDLL typSTATUS dsysWngShGet
   (
   strSysWngShItem*  pWngShItem,  /* Out: Array containing the wng desc */ 
   uint32            luArraySize, /* In:  Size of warning array */
   uint32*           pluNbrElem,  /* Out: Number of element in the array */
   uint32*           pluNbrTotal  /* Out: Total number of wng. remaining */ 
                                  /* in the stack */
   );

/* exported services from module dsys0lib.c *******************************/

extern ISASYSDLL uint16 dsysStrLen
   (
   const char* psString    /* In: Null terminated string to get length */
   );

extern ISASYSDLL void dsysStrCpy
   (
   char*       psDest,     /* Out: Destination string */
   const char* psSrc       /* In: String to copy */
   );

extern ISASYSDLL void dsysStrNCpy
   (
   char*       psDest,     /* Out: Destination string */
   const char* psSrc,      /* In: String to copy */
   uint16      huLnSrc     /* In: Length of string to copy */
   );

extern ISASYSDLL void dsysStrCat
   (
   char        *psDest,    /* In/Out: Destination string */
   const char  *psSrc      /* In: Source string */
   );

extern ISASYSDLL typSTATUS dsysStrCmp
   (
   const char* psString1,  /* In: Null terminated string */
   const char* psString2   /* In: Null terminated string */
   );

extern ISASYSDLL int16 dsysStrLexCmp
   (
   const char* psString1,  /* In: Null terminated string */
   const char* psString2   /* In: Null terminated string */
   );

extern ISASYSDLL typSTATUS dsysStrNCmp
   (
   const char* psString1, /* In: Null terminated string */
   const char* psString2, /* In: Null terminated string */
   uint32 huLength        /* In: Number of character to compare */
   );

extern ISASYSDLL int32 dsysStrToInt32
   (
   const char* psBuffer    /* In: String to convert */
   );

extern ISASYSDLL uint32 dsysStrToUint32
   (
   const char* psBuffer    /* In: String to convert */
   );

#ifdef ITGTDEF_INT64

extern ISASYSDLL int64 dsysStrToInt64
   (
   const char* psBuffer    /* In: String to convert */
   );

extern ISASYSDLL uint64 dsysStrToUint64
   (
   const char* psBuffer    /* In: String to convert */
   );

#endif /* ITGTDEF_INT64 */

extern ISASYSDLL void dsysMemCpy
   (
   void*          pvDest,     /* Out: Pointer on destination */
   const void*    pvSrc,      /* In: Pointer on source */
   uint32         luLength    /* In: Size of data to copy */
   );

extern ISASYSDLL void dsysMemMove
   (
   void*          pvDest,     /* Out: Pointer to destination */
   const void*    pvSrc,      /* In: Pointer to source */
   uint32         luSize      /* In: Size of data to copy */
   );

extern ISASYSDLL void dsysMemSet
   (
   void*          pvDest,     /* Out: Pointer on destination */
   uchar          cuValue,    /* In: Character to write */
   uint32         luLength    /* In: Size of data to fill */
   );

extern ISASYSDLL void dsysMemReset
   (
   void*          pvDest,     /* Out: Pointer on destination */
   uint32         luLength    /* In: Size of data to fill with zero */
   );

extern ISASYSDLL typSTATUS dsysMemCmp
   (
   const void*    pvBuffer1,  /* In: Pointer on buffer1 */
   const void*    pvBuffer2,  /* In: Pointer on buffer2 */
   uint32         luLength    /* In: Size of data to compare */
   );

extern ISASYSDLL void dsysMemCpyChk
   (
   void*          pvDest,     /* Out: Destination block */
   const void*    pvSrc,      /* In: Source block */
   const void*    pvCpyChk,   /* In: Block Info of bytes to copy: 0x00=Yes */
   uint32         luSize      /* In: Size of data */
   );

extern ISASYSDLL void dsysMemCpyChkNot
   (
   void*          pvDest,     /* Out: Destination block */
   const void*    pvSrc,      /* In: Source block */
   const void*    pvCpyChk,   /* In: Block Info of bytes to copy: 0x00=Yes */
   uint32         luSize      /* In: Size of data */
   );

extern ISASYSDLL void dsysMemCpyChkRefresh
   (
   void*          pvDest,     /* Out: Destination block */
   const void*    pvSrc,      /* In: Source block */
   const void*    pvCpyChk,   /* In: Block Info of bytes to copy: 0x00=Yes */
   uint32         luSize      /* In: Size of data */
   );

extern ISASYSDLL uint16 dsysStrPCpy
   (
   char*       psDest,     /* Out: Destination string */
   uint16      huDestSize, /* In: Size of destination */
   const char* psSrc,      /* In: String to copy */
   uint16      huNbrChar   /* In: Number of characters to copy (N) */
   );

extern ISASYSDLL typSTATUS dsysStrILeftCmp
   (
   const char* psString1,  /* In: Null terminated string */
   const char* psString2,  /* In: Null terminated string */
   char        cChar       /* In: Compare strings up to this character */
   );

extern ISASYSDLL uchar dsysInt32ToStr
   (
   int32    ldInt32,          /* In: Value to convert */ 
   char*    psBuffer,         /* Out: Destination string */ 
   uchar    cuBufferSize      /* In: Size of destination buffer */
   );

extern ISASYSDLL uchar dsysUInt32ToStr
   (
   uint32   luInt32,          /* In: Value to convert */ 
   char*    psBuffer,         /* Out: Destination string */ 
   uchar    cuBufferSize      /* In: Size of destination buffer */
   );

#ifdef ITGTDEF_INT64
extern ISASYSDLL uchar dsysInt64ToStr
   (
   int64    ldInt64,          /* In: Value to convert */ 
   char*    psBuffer,         /* Out: Destination string */ 
   uchar    cuBufferSize      /* In: Size of destination buffer */
   );

extern ISASYSDLL uchar dsysUInt64ToStr
   (
   uint64   luInt64,          /* In: Value to convert */ 
   char*    psBuffer,         /* Out: Destination string */ 
   uchar    cuBufferSize      /* In: Size of destination buffer */
   );
#endif /* ITGTDEF_INT64 */

#ifdef ITGTDEF_FLOAT
extern ISASYSDLL float dsysStrToFloat
   (
   const char* psBuffer    /* In: String to convert */
   );

extern ISASYSDLL uchar dsysFloatToStr
   (
   float    fFloat,           /* In: Value to convert */ 
   char*    psBuffer,         /* Out: Destination string */ 
   uchar    cuBufferSize      /* In: Size of destination buffer */
   );
#endif /* ITGTDEF_FLOAT */

#ifdef ITGTDEF_DOUBLE
extern ISASYSDLL real64 dsysStrToDouble
   (
   const char* psBuffer    /* In: String to convert */
   );

extern ISASYSDLL uchar dsysDoubleToStr
   (
   real64   lfDouble,         /* In: Value to convert */ 
   char*    psBuffer,         /* Out: Destination string */ 
   uchar    cuBufferSize      /* In: Size of destination buffer */
   );
#endif /* ITGTDEF_FLOAT */

extern ISASYSDLL uint32 dsysFileMsgGet
   (
   uint32   luNumber,         /* In: Number associated to the message */
   const char*    psFileName,       /* In: Name of the file where search message */
   char*    psBuffer,         /* Out: Buffer where store message */
   uint32   luBufferSize      /* In: Length of the buffer */
   );

extern ISASYSDLL typSTATUS dsysEncryptPassword8
   (
   char*       psPasswordToEncode, /* In: Configuration password to encode */ 
   char*       psPasswordEncoded   /* Out: Encoded configuration password */ 
   );

extern ISASYSDLL typSTATUS dsysDecryptPassword8
   (
   char*       psPasswordToDecode, /* In: Configuration password to decode (8 bytes) */ 
   char*       psPasswordDecoded   /* Out: Decoded configuration password */ 
   );

/* exported services from module dsys0irq.c *******************************/
#ifdef ITGTDEF_INTERRUPT
#ifndef ITGTDEF_SEGMENT
extern ISASYSDLL typSTATUS dsysIrqInstallHandler
   (
   typIRQ_MNG* pIrqMng,
   void*       BfData
   );

extern ISASYSDLL typSTATUS dsysIrqUninstallHandler
   (
   typIRQ_MNG* pIrqMng,
   void*       BfData
   );

extern ISASYSDLL typSTATUS dsysIrqHdlInit
   (
   typIRQ_MNG*    pIrqMng, 
   void*          BfData
   );
#else
extern ISASYSDLL typSTATUS dsysIrqInstallHandler
   (
   typIRQ_MNG* pIrqMng,
   void**      BfData
   );

extern ISASYSDLL typSTATUS dsysIrqUninstallHandler
   (
   typIRQ_MNG* pIrqMng,
   void**      BfData
   );

extern ISASYSDLL typSTATUS dsysIrqHdlInit
   (
   typIRQ_MNG*    pIrqMng, 
   void**         BfData
   );
#endif /* ITGTDEF_SEGMENT */

extern IRQ_THREAD_FCT_PROTO;

/* exported services from module dsys0tsk.c *******************************/
extern ISASYSDLL typSTATUS dsysIntThrCreate
   (
   typINTTHR_HDL *pThrHdl     /* In: Thread Param Structure */
   );

extern ISASYSDLL typSTATUS dsysIntThrExit
   (
   typINTTHR_HDL *pThrHdl     /* In: Thread ID */
   );

extern ISASYSDLL typSTATUS dsysIntThrCheckExit /*RFS8498*/
   (
   typINTTHR_HDL *pThrHdl     /* In: Thread ID */
   );

extern ISASYSDLL typSTATUS dsysIntThrSetPrio
   (
   typINTTHR_HDL* pThrHdl     /* In: Structure to get the Thread Handle */
   );
#endif /* ITGTDEF_INTERRUPT */

/* exported services from module dsys0tsk.c *******************************/
extern ISASYSDLL typSTATUS dsysTskCreate
   (
   typTSK_ID*  pTskId,     /* Out: Task identifier */
   ACE_TCHAR*       psTskName,  /* In: Name of task to start */
   ACE_TCHAR**      ppsArgv     /* In: Pointer to parameters list (0 terminator)*/
   );

extern ISASYSDLL typSTATUS dsysTskRestart
   (
   typTSK_ID*  pTskId      /* In:: Task identifier */
   );

extern ISASYSDLL typSTATUS dsysTskTerminate
   (
   typTSK_ID*  pTskId      /* In:: Task identifier */
   );

extern ISASYSDLL void dsysTskKill
   (
   typTSK_ID*  pTskId      /* In:: Task identifier */
   );

extern ISASYSDLL typSTATUS dsysTskStatus
   (
    typTSK_ID*  pTskId      /* In: Task identifier */
   );

extern ISASYSDLL typSTATUS dsysThrCreate
   (
    typTHR_HDL *pThrHdl        /* In: Thread handle */
   );

extern ISASYSDLL typSTATUS dsysThrExit
   (
   typTHR_HDL *pThrHdl        /* In: Thread handle */
   );

extern ISASYSDLL typSTATUS dsysPriSetThreadPrio
   (
   typTHR_HDL *pThrHdl,        /* In: Thread Structure */
   int32 ldThrPrio/* In: Priority */
   );

extern ISASYSDLL int32 dsysPriGetThreadPrio
   (
   typTHR_HDL*   pThrHdl       /* In: Thread Handle */
   );

/* exported services from module dsys0hbt.c *******************************/
#ifdef ITGTDEF_FAILOVER
extern typSTATUS dsysHbtCreate
   (
   typHBT_ID*  pHbtId
   );

extern typSTATUS dsysHbtDelete
   (
   typHBT_ID*  pHbtId
   );
   
extern typSTATUS dsysHbtRead
   (
   typHBT_ID*  pHbtId,
   int32       ldTimeoutMs,
   uint32*     pluLastHeartbeatSyncTimeMs
   );

extern typSTATUS dsysHbtWrite
   (
   typHBT_ID*  pHbtId
   );
#endif
#endif   /* nested Headers management */
   
/* eof ********************************************************************/
