/**************************************************************************
File:               dker0pro.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      15-January-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Kernel Core Prototypes

***************************************************************************
Modifications: (who / date / description)
---4.02 Released---
EDS/16-Sep-1999/ 'C' conversion funct integration
   Replaced kerCnvGet() return type: typPFnIplFct ==> typPFnCnvCall
EDS/13-Jan-2000/ Enhancement of the way com requests are polled
   Added some proto from dker0tcy.c

---4.03 Released---
EDS/03-Apr-2000/ SFC Breakpoints addon
   Fct evoTrsUcc() now returns typSTATUS.
EDS/25-Aug-2000/ Allow adding of variables in MDF
   Added proto of kerStrTbMLenSet() 
   Modified proto kerMdfRVarSet() ==> kerMdfRVarCstSet()
   Added proto kerMdfRVarIniUpdate()
   Added proto kerMdfFblStdUpdate()
   Modified proto of pouMdfChk() & pouMdfInit()
   Now dker0res.h include becomes required

---4.10 Released---
JFO/30-Aug-2001/ BUG 1362: Floating conversions.
   Added kerStrStringToFloat() and kerStrFloatToString().

---4.11 Released---
VMO/13-Mar-2002/ Hot restart
   Added some proto for hot restart in dker0fbl.c and dker0evo.c.

---4.12 Released---
VMO/12-June-2002/ SFC function block
   Added tblBaseOfsAdd() proto

---4.22 Released---
FG/10-Jan-2005/ RFS 4017
   Online change does not support user C function block instance addition

---5.00 Released---
OL/02-Feb-2005/ New data type
   Add TIC code for INT, LINT, USINT, USINT, UDINT, ULINT, LREAL and DATE.

---Vantage Released---
FT/25-Jan-2007/ New functions for password protection
   MonoTask now has password protection capability

---5.21 Released---
FT/21-Oct-2008/ RFS-6695 
   New function kerStrIsNegative returns TRUE if the character '-' is found in the passed string.

***************************************************************************/
#ifndef _DKER0PRO_H    /* nested Headers management */
#define _DKER0PRO_H

#ifdef ITGTDEF_ENH_ONLINE_CHANGE
#include <dsys0def.h>
#include <dker0def.h>
#include <dker0res.h>
#include <dfbl0std.h>
#include <dfbl0sfc.h>
#else
#include <dker0res.h> /* Nested header required */
#endif
#ifdef ITGTDEF_MONOTASK
#include <dixs0def.h>
#else
#include <dixl0def.h>
#endif

/* constants **************************************************************/

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module dker0str.c *******************************/
extern void kerStrInit(void);
extern void kerStrTbMLenSet
   (
   uint32          luNbInitMLenStr,  /* In: Number of variables */
   strInitMLenStr* pTbInitMLenStr    /* In: Table of string max len values */
   );

extern void kerStrVaWrite 
   (
   typVa  VaDest,   /* In: Va of destination variable to be written */ 
   uint32 luElmt,   /* In: Element position (if array) */ 
   char*  pcBufSrc, /* In: Source buffer */ 
   uchar  cuLen,    /* In: Number of characters to copy */ 
   uchar  cuRefresh /* In: TRUE if the write is done in the binding refreshed space */
   );

extern void kerStrPtWrite   
   (
   uchar* pcuKStrDest,   /* Out: Kernel str var destination to be written */ 
   char*  pcBufSrc,      /* In: Source buffer */ 
   uchar  cuLen          /* In: Number of characters to copy */ 
   );

extern void kerStrCpyExt
   (
   typVa VaDest,    /* In: Va of destination variable to be written */ 
   typVa VaSrc,     /* In: Va of source variable to copy */ 
   uchar cuRefresh  /* In: TRUE if we want to update the binding refreshed value */
   );
   
extern void kerStrCpy 
   (
   typVa VaDest,   /* In: Va of destination variable to be written */ 
   typVa VaSrc     /* In: Va of source variable to copy */ 
   );

extern void kerStrCatExt
   (
   typVa VaAff,     /* In: Va of variable to be affected */ 
   typVa VaOp1,     /* In: Va of first operand */ 
   typVa VaOp2,     /* In: Va of second operand */ 
   uchar cuRefresh  /* In: TRUE if we want to update the binding refreshed value */
   );

extern void kerStrCat
   (
   typVa VaAff, /* In: Va of variable to be affected */ 
   typVa VaOp1, /* In: Va of first operand */ 
   typVa VaOp2  /* In: Va of second operand */ 
   );

extern uchar kerStrEqu
   (
   typVa VaOp1, /* In: Va of first operand */ 
   typVa VaOp2  /* In: Va of second operand */ 
   );           /* Returns: TRUE if equal, FALSE if not equal */

extern int16 kerStrLexCmp
   (
   typVa VaOp1, /* In: Va of first operand */ 
   typVa VaOp2  /* In: Va of second operand */ 
   );           /* Returns: */
                /*  Negative val: VaOp1 < VaOp2 */
                /*  Zero val:     VaOp1 = VaOp2 */
                /*  Positive val: VaOp1 > VaOp2 */

extern void kerStrDintToString
   (
   typVa VaDest,   /* In: Cast destination string variable */
   int32 ldValue,  /* In: Dint value to cast */
   uchar cuRefresh /* In: TRUE if the write is done in the binding refreshed space */
   );

#ifdef ITGTDEF_FLOAT 
extern void kerStrFloatToString
   (
   typVa VaDest,   /* In: Cast destination string variable */
   float fValue,   /* In: Float value to cast */
   uchar cuRefresh /* In: TRUE if the write is done in the binding refreshed space */
   );
#endif /* ITGTDEF_FLOAT */

extern void kerStrTimeToString
   (
   typVa  VaDest,   /* In: Cast destination string variable */
   uint32 luValue,  /* In: Time value to cast */
   uchar  cuRefresh /* In: TRUE if the write is done in the binding refreshed space */
   );

extern void kerStrDATEToString
   (
   typVa  VaDest,   /* In: Cast destination string variable */
   date   luValue,  /* In: DATE value */
   uchar  cuRefresh /* In: TRUE if the write is done in the binding refreshed space */
   );

extern void kerStrUDINTToString
   (
   typVa VaDest,   /* In: Cast destination string variable */
   uint32 ldValue, /* In: UDINT value to cast */
   uchar cuRefresh /* In: TRUE if the write is done in the binding refreshed space */
   );

#ifdef ITGTDEF_INT64
extern void kerStrLINTToString
   (
   typVa VaDest,   /* In: Cast destination string variable */
   int64 ldValue,  /* In: LINT value to cast */
   uchar cuRefresh /* In: TRUE if the write is done in the binding refreshed space */
   );

extern void kerStrULINTToString
   (
   typVa VaDest,   /* In: Cast destination string variable */
   uint64 ldValue, /* In: ULINT value to cast */
   uchar cuRefresh /* In: TRUE if the write is done in the binding refreshed space */
   );
#endif /* ITGTDEF_INT64 */

#ifdef ITGTDEF_DOUBLE
extern void kerStrLREALToString
   (
   typVa VaDest,   /* In: Cast destination string variable */
   real64 ldValue, /* In: LREAL value to cast */
   uchar cuRefresh /* In: TRUE if the write is done in the binding refreshed space */
   );
#endif /* ITGTDEF_DOUBLE */

extern uchar kerStrStringToBool
   (
   typVa  VaSrc   /* In: Source string variable to cast */
   );             /* Returns: TRUE if string = '1' or = 'TRUE' else FALSE */

extern int32 kerStrStringToDint
   (
   typVa  VaSrc   /* In: Source string variable to cast */
   );             /* Returns: Cast dint value */

extern uint32 kerStrStringToUDINT
   (
   typVa  VaSrc   /* In: Source string variable to cast */
   );             /* Returns: Cast dint value */

extern uchar kerStrIsNegative
   (
   typVa  VaSrc   /* In: Source string variable to test */
   );             /* Returns: TRUE if negative number */

#ifdef ITGTDEF_FLOAT 
extern float kerStrStringToFloat
   (
   typVa  VaSrc   /* In: Source string variable to cast */
   );             /* Returns: Cast float value */
#endif /* ITGTDEF_FLOAT */

extern date kerStrStringToDATE
   (
   typVa  VaSrc   /* In: Source string variable to cast */
   );             /* Returns: Cast dint value */

#ifdef ITGTDEF_INT64
extern int64 kerStrStringToLINT
   (
   typVa  VaSrc   /* In: Source string variable to cast */
   );             /* Returns: Cast LINT value */

extern uint64 kerStrStringToULINT
   (
   typVa  VaSrc   /* In: Source string variable to cast */
   );             /* Returns: Cast ULINT value */
#endif /* ITGTDEF_INT64 */

#ifdef ITGTDEF_STRING
uint32 kerStrStringToTime
   (
   typVa  VaSrc
   );
#endif

#ifdef ITGTDEF_DOUBLE
extern real64 kerStrStringToLREAL
   (
   typVa  VaSrc   /* In: Source string variable to cast */
   );             /* Returns: Cast LREAL value */
#endif /* ITGTDEF_DOUBLE */

#ifdef ITGTDEF_ENH_ONLINE_CHANGE
void kerRelocateString
   (
   uint32      luDestVa,  
   uint32      luSrcVa,  
   uint32      luDestSize,
   uchar       cuDestStrMaxSize
   );
#endif

/* exported services from module dker0var.c *******************************/
extern void kerRVarSet(void);
extern void kerMdfRVarCstSet
   (
   uchar*       pcuBase,    /* In: Base addr of tables */ 
   strInitVar*  pTbInitVar  /* In: InitVar table */ 
   );

extern void kerMdfRVarIniUpdate
   (
   uchar*         pcuBase,       /* In: Base addr of tables */
   strUpdInitVar* pTbUpdInitVar  /* In: InitVar for update table */
   );

#ifdef ITGTDEF_ENH_ONLINE_CHANGE
extern void kerMdfProcessRecipe
   (
   strUpdRecipe* pTbUpdRecipe
   );
#endif

extern typSTATUS kerLockInternalVar
   (
   typIxlVa IxlVa,
   uint32 luDataSize
   );

extern void kerUnlockAllLockedInternalVarsInList(void);

#ifdef ITGTDEF_NEW_ARRAY_AND_FB
extern void kerInstInputInit(void);
#endif

/* exported services from module dker0tcy.c *******************************/
extern void tcyInit
   (
   uint32 luCycTimeTrig /* Trigger cycle time */  
   );

extern void tcyExit(void);
#ifdef ITGTDEF_FAILOVER
extern void tcyBegin
   (
   uint32 *pluCycleDateFromRemote
   );
#else
extern void tcyBegin(void);
#endif
extern void tcyEnd(void);
extern uint32 tcyLeftTime(void);
extern uint16 tcyLoopSleepGet(void);
extern void tcyLoopSleepReset(void);

/* exported services from module dker0usf.c *******************************/
extern typSTATUS kerUsfStdInit
   (
   uint16 huSlaveNum /*In: Resource number */
   );
extern void kerUsfStdExit(void);
extern typSTATUS kerUsfInit   
   (
   void* pvUsfMngBlkAdd  /*In: Block add for 'C' functions management */
   );

extern void kerUsfExit(void);

extern void kerUsfCall
   (
   uint16      huUsfNum,      /*In: Library function number */ 
   strParamVa* InParam,       /*In: Input parameters */ 
   uint16      huNbInParam,   /*In: Number of input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

/* exported services from module dker0fbl.c *******************************/
extern typSTATUS kerFblStdInit(void); /* Returns: 0 if ok, BAD_RET if error */
extern void kerMdfFblStdUpdate
   (
   strUpdFblStd* pTbUpdFblStd  /* In: Table of standard fbl to update */
   );

extern void kerFblStdExit(void);

extern typSTATUS kerFblInit
   (
   void* pvFblMngBlkAdd  /* In: Block add for 'C' function blocks management*/
   );                    /* Returns:  0 if successful, BAD_RET if error */

extern void kerFblExit(void);
extern void kerFblCall
   (
   uint16      huFblNum,  /* In: Library function block number */ 
   strParamVa* FblInst    /* In: Function block instance */
   );

extern void kerFblSubFunc
   (
   uchar    cuSubFunc     /*In: Sub function */
   );  

extern typSTATUS kerCFblMdfInit(void); /* RFS 4017 */

/* exported services from module dker0cnv.c *******************************/
extern typSTATUS kerCnvInit   
   (
   void* pvCnvMngBlkAdd  /*In: Block add for 'C' conversions management */
   );

extern void kerCnvExit(void);
extern typPFnCnvCall kerCnvGet
   (
   uint16      huCnvNum      /*In: Library function number */ 
   );  

/* exported services from module dker0ini.c *******************************/
extern typSTATUS kerRInit 
   (
   uint16 huSlaveNum  /* Slave Number */
   );  

extern void kerRExit
   (
   uint16 huSlaveNum  /* Slave Number */
   );  

#ifdef ITGTDEF_BINDIMPROVE2
extern void* kerSwapKvbSpaces(void);

extern typSTATUS kerCreateNewKvbSpace
   (
   uint32 luCurBindSize, 
   uint32 luNewBindSize
   );
extern void kerDestroyKvbSpaces(void);
#endif

/* exported services from module dker0pou.c *******************************/
extern uchar pouInit
   (
   uint16 huNbPou  /* In: Number of pou */ 
   );              /* Returns: Maximum pou level hierarchy */

extern typSTATUS pouMdfChk
   (
   uint16      huPouNum,   /* In: Pou number */ 
   uchar*      pcuPouBase, /* In: Pou base addr */
   strPouMain* pPouMain    /* In: Pou main table */
   );                      /* Returns: 0 if successful, BAD_RET if error */

extern void pouMdfInit
   (
#if defined(ITGTDEF_ENH_ONLINE_CHANGE) && defined(ITGTDEF_SFCFUNCTIONS)
   uchar cuIsSfcFbUpd,     /* In: Is there a SFC function block update */
#endif
   uint16 huPouNum  /* In: Pou number */ 
   );

extern char* pouGetName
   (
   uint16 huPouNum  /* In: POU number */
   );

extern void* tblBaseOfsAdd
   (
   void*  pvBase,  /*In: Base address */ 
   uint32 luBlkOfs /*In: Offset to block */ 
   );

/* exported services from module dker0tic.c *******************************/
extern uchar resCodeTypeGet
   (
   typVa PouVa  /* Pou to get info from if any, else 0 */
   );

extern uint32 ticDec
   (
#ifdef ITGTDEF_OPT_CODE_MED_AS_LRG
   ISA_VARINREG uint32* mic,
#else
   ISA_VARINREG typVa* mic,  /* TIC Sequence */ 
#endif
   typVa PouVa,              /* Pou being executed */
   typVa SfcStpTrsVa,        /* Va of step or transition if Sfc */
   uchar cuCodeType,         /* Type of code to execute */
   strCallContext *pCallContext /* Context of the calling thread/task */
   );

extern void ticParamVaSet
   (
   typVa* mic,
   strCallContext* pCallContext /*RFS 8409*/
   );  

extern void ticCycleStart
   (
   void
   );
#ifdef ITGTDEF_FAILOVER
extern uint32 ticFailoverGetCRC(void);
extern void ticFailoverInitCRC(void);
extern void ticFailoverUpdateCRC
   (
   uchar *pcuData, 
   uint32 luDataSize
   );
extern void ticFailoverSetCRC
   (
   uint32 luFailoverCrc
   );
#endif

/* exported services from module dker0cas.c *******************************/
extern void ticCast
   (
   typVa  DestVa,     /* Cast destination variable */ 
   typVa  SrcVa,      /* Source variable to cast */ 
   uint16 huDestType, /* Type of destination variable */ 
   uint16 huSrcType   /* Type of source variable */ 
   );

#ifdef ITGTDEF_VARLOCK
extern void ticCastRefresh
   (
   typVa  DestVa,     /* Cast destination variable */ 
   typVa  SrcVa,      /* Source variable to cast */ 
   uint16 huDestType, /* Type of destination variable */ 
   uint16 huSrcType   /* Type of source variable */ 
   );
#endif

/* exported services from module dker0clt.c *******************************/
#ifdef ITGTDEF_FAILOVER
extern typSTATUS kerCltInit
   (
   uchar cuInitContextOnly
   );

extern typSTATUS kerCltExit(void);

extern typSTATUS kerCltDownloadRemote(void);

extern typSTATUS kerCltSyncDataStandby(void);

extern typSTATUS kerCltCompareCrcStandby
   (
   uchar *pcuMustSyncApplication,
   uchar *pcuMustSyncDataSpace
   );

extern typSTATUS kerCltWriteVariablesRemote
   (
   strIxlVarDesc *pVarDesc,
   uint16         huNbVar
   );

#ifdef ITGTDEF_MODIF
extern typSTATUS kerCltDwnMdfNewDltRemote
   (
   uchar cuDltType, 
   uint32 luDltSize
   );

extern typSTATUS kerCltDwnMdfDlkPkTransRemote
   (
   uint16 huDltId, 
   uint32 luPkByteNbr, 
   uint32 luPkOfsByteNbr, 
   void *pvData
   );

extern typSTATUS kerCltDwnMdfCleanRemote(void);

extern typSTATUS kerCltDwnMdfRdbCrcAddRemote
   (
   uint32 luRdbCrc
   );

extern typSTATUS kerCltDwnMdfDltAcceptRemote
   (
   uint32 luSaveOpt
   );
#endif /* ITGTDEF_MODIF */

extern typSTATUS kerCltCheckConnectionToRemoteKernel(void);

extern typSTATUS kerCltGetCommStatus(void);

extern uchar kerCltIsDataLinkUp(void);

extern uchar kerCltRemoteSystemMismatch(void);

extern uchar kerCltRemoteCapabilitiesMismatch(void);

extern typSTATUS kerCltStartStopRemoteHeartbeat(uchar cuIsStart);

#ifdef ITGTDEF_FAILOVER_TCP_DATALINK
extern void kerCltTcpCheckIncomingMessages(void);
#endif

#endif   /* #ifdef ITGTDEF_FAILOVER */

/* exported services from module dker0flx.c *******************************/
#ifdef ITGTDEF_FAILOVER
extern void kerFailoverProcessIncomingRequests(void);

extern typSTATUS kerFailoverStartup(void);

extern typSTATUS kerFailoverShutdown(void);
   
extern typSTATUS kerFailoverSyncData(uchar);

extern typSTATUS kerFailoverCheckCRC(void);

extern void kerFailoverInitCRC(void);

#endif   /* #ifdef ITGTDEF_FAILOVER */
#ifdef ITGTDEF_FAILOVER
extern void kerFailoverUpdateSystemVariables
   (
   uchar cuIsEnabled,
   uint32 luErrorCode,
   uchar cuIsPrimary,
   uchar cuIsActive,
   uint32 luDataSyncTimeMs,
   uint32 luHearbeatSyncTimeMs
#ifdef ISA_SYSVA_FO_DATASYNCCNT /*RFS8400*/
 , uint32 luFullDataSyncCounter
#endif
   );

#endif   /* #ifdef ITGTDEF_FAILOVER */

/* exported services from module dker0evo.c *******************************/
extern void evoInit
  (
  void** ppvSfcEvoBlkAdds, /*In: Block addresses for Sfc Evo management */ 
  uint32* pluSfcEvoNbElmt  /*In: Blocks number of elements */ 
  );

extern void evoCycleProceed(void);

/* RFS6522 BEGIN */
#ifdef ITGTDEF_SFCFUNCTIONS
extern typSTATUS evoSfcStart
   (
   uint16 huPouNum  
   );
  
extern typSTATUS evoSfcKill
   (
   uint16 huPouNum  
   );
  
extern typSTATUS evoSfcFreeze
   (
   uint16 huPouNum
   );

extern typSTATUS evoSfcReStart
   (
   uint16 huPouNum
   );

extern typSTATUS evoTrsUcc
   (
   typVa TrsVa  /* Transition variable to clear */
   );
  
extern typSTATUS evoTrsCc
   (
   typVa TrsVa  /* Transition variable to clear */ 
   );
 
extern void evoSteModifStart(void);

extern void evoSteModifStop(void);

extern void evoSteSetActif
   (
   typVa       StpVa,      /* In: Step to activate */
   void*       pvSteInfo   /* In: Step info to restore if any */
   );

extern typSTATUS kFblSfcInstsInitExit
   (
   uchar cuIsInit 
   );

#ifdef ITGTDEF_ENH_ONLINE_CHANGE

extern void kerEvoMdfProcessUpdModifSFC
   (
   strUpdRestoreSFC* pTbUpdRestoreSFC
   );

extern typSTATUS kerEvoMdfBackupSfcStates(void);

extern typSTATUS kerEvoMdfRestoreSfcStates
   (
   uint16 huNewPouNum,
   uint16 huOldPouNum
   );

extern uint16 kerEvoMdfGetPouNumOfBackupSfcState
   (
   uint32 luOffset,
   uchar cuIsStepOrTrans,
   uint32 *pluOrderFromFirst
   );

extern void kerSfcEngineRestart(void);
#endif /*ITGTDEF_ENH_ONLINE_CHANGE*/

#ifdef ITGTDEF_ENH_ONLINE_CHANGE
#ifdef ITGTDEF_SFCFBL
extern void kerEvoMdfProcessUpdModifSFCFB
   (
   strUpdRestoreSFCFB* pTbUpdRestoreSFCFB
   );

extern typSTATUS kerEvoMdfBackupSfcFbStates(void);

extern void kerGetBkpSfcFbStateBlk
   (
   void **ppvBkpSfcFbStateBlkAdd, 
   uint32 *pluBkpSfcFbStateBlkSz
   );

extern uint32 SFCFblSpcSizeGet(void);

extern void SFCFblSpaceInit
   (
   void* pvSpcAdd
   );

extern void SFCFblSteSetActif
   (
   strInstInfo *pInstInfo,
   strSfcFbStepBackup *pstrSfcFbStepBackup
   );

extern typVa getVaFromPtr
   (
   void* pvData
   );

extern void SFCFblModifStartFB
(
 strInstInfo *pInstInfo
 );

extern void SFCFblModifStopFB
(
 strInstInfo *pInstInfo
 );
#endif /*ITGTDEF_SFCFBL*/
#endif /*ITGTDEF_ENH_ONLINE_CHANGE*/
#endif /*ITGTDEF_SFCFUNCTIONS */
/*RFS6522 END */


#ifdef ITGTDEF_ENH_ONLINE_CHANGE
extern void kerEvoMdfInit(void);
#endif /*ITGTDEF_ENH_ONLINE_CHANGE*/

#ifdef ITGTDEF_MONOTASK
#ifdef ITGTDEF_CONF_PASSWORD
extern void pwdLoadPassword(void);

extern void pwdSavePassword
   (
   char *psNewPass
   );

extern uchar pwdIsTherePassword(void);

extern uchar pwdIsPasswordCorrect
   (
   char *psPassToCheck
   );

extern uchar pwdIsAccessGranted
   (
   typIxsCnxId IxsCnxId
   );

extern void pwdSetAccessGranted
   (
   typIxsCnxId IxsCnxId, 
   uchar cuGranted
   );
#endif
#endif

#ifdef ITGTDEF_FAILOVER
extern typSTATUS cmgHbtInit(void);

extern typSTATUS cmgHbtStart(void);

extern typSTATUS cmgHbtExit(void);

extern typHBT_ID *cmgGetHbtParams(void);

#endif /* #ifdef ITGTDEF_FAILOVER */

#ifdef ITGTDEF_INTERRUPT
/* exported services from module dker0irq.c *******************************/
extern typSTATUS kerIrqStartManager(void);

extern void kerIrqStopManager(void);
#endif

#if defined(ITGTDEF_RT_OPTIMIZE_CODE) && (defined(ISA_TMM_L) || defined (ITGTDEF_OPT_CODE_MED_AS_LRG))
/* exported services from module dker0opt.c *******************************/
extern typSTATUS kerOptInit(void);

extern typSTATUS kerOptExit(void);

extern typSTATUS kerOptParseCode(typVa* mic, uint32 luNbCodes, uint32* pluOptCode);

extern typSTATUS kerOptimizePou(uchar *pcuDtaBase, uint32* pluOptCode);

#ifdef ITGTDEF_OPT_CODE_MED_AS_LRG
extern typSTATUS kerOptConvertPouToLarge(uchar  *pcuDtaBase);
#endif /* ITGTDEF_OPT_CODE_MED_AS_LRG */

#endif /* defined(ITGTDEF_RT_OPTIMIZE_CODE) && (defined(ISA_TMM_L) || defined (ITGTDEF_OPT_CODE_MED_AS_LRG)) */

#endif /* Nested header management */
/* eof ********************************************************************/
