/**************************************************************************
File:               dker0def.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      24-October-1997
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Kernel core definitions

***************************************************************************
Modifications: (who / date / description)
---4.02 Released---
EDS/13-Jan-2000/ Enhancement of the way com requests are polled
   Added defs for cycle time completion management.

---4.03 Released---
EDS/03-Apr-2000/ SFC Breakpoints addon
   Added miscellaneous data block
   Moved breakpoint defs to bkp header file
   Added sfc step/trans extra status defs
EDS/25-Aug-2000/ Allow adding of variables in MDF
   Added ppvMdfCodeBlks to strKsys for code of on line modified pous

---4.10 Released---
EDS/05-Oct-2001/ Variables locking 
   Added identifiers of space to strKsys and global BF_VARLOCK
   Added macro for access to lock flag of variables KBFLCK_XXX

---4.11 Released---
VMO/13-Mar-2002/ Hot restart
   Added HotRestart data in strKsys declaration

---4.12 Released---
VMO/12-June-2002/ SFC function block
   Added SFC function blocks data in strKsys declaration

---4.13 Released---
VMO/13-Nov-2002/ Error report
   Added ISA_RC_DKER_XXX error
GM1/26-Nov-2002/ Step By Step debugging
   Added Stepping states.

---5.00 Released---
OL/02-Feb-2005/ New data type
   Add TIC code for INT, LINT, USINT, USINT, UDINT, ULINT, LREAL and DATE.

---Vantage Released---
FT/25-Jan-2007/ New functions for password protection
   MonoTask now has password protection capability

---5.31 Released---
OO/20-Sept-2012/ RFS 8359
   Added space ID and address for the space to store MDF for the
   optimized code

***************************************************************************/
#ifndef _DKER0DEF_H   /* nested Headers management */
#define _DKER0DEF_H

#ifdef ITGTDEF_FAILOVER
#include "dixl0def.h"
#endif

/* constants **************************************************************/

/* Kernel Errno */
#define ISA_RC_DKER_INIT_PRIV_BLOCK 0x22010001UL
#define ISA_RC_DKER_INIT_ALLOC      0x22010002UL
#define ISA_RC_DKER_INIT_STD_C      0x22010003UL
#define ISA_RC_DKER_INIT_USR_C      0x22010004UL
#define ISA_RC_DKER_INIT_STD_FBL    0x22010005UL
#define ISA_RC_DKER_INIT_USR_FBL    0x22010006UL
#define ISA_RC_DKER_INIT_CONV_C     0x22010007UL
#define ISA_RC_DKER_INIT_IOS        0x22010008UL
#define ISA_RC_DKER_INIT_KVB        0x22010009UL
#define ISA_RC_DKER_INIT_DBG        0x2201000BUL

#define ISA_RC_DKER_KVB_CONSUME     0x1201000AUL

#define DATE_DAY_ONLY(x) (x - (x % ISA_TIME_DAY_IN_SECONDS)) /* Keep day part of type DATE. Remove hours. */
#define DATE_TIME_ONLY(x) (x % ISA_TIME_DAY_IN_SECONDS)      /* Keep time part of type DATE. Remove days. */

/* Kernel Access to Variables addresses and values */
#define BF_UDINT(BfData,va)  ( *(uint32*) (VA_ADDRESS ((BfData),(va))) ) 
#define BF_VA(BfData,va)     ( *(typVa*)  (VA_ADDRESS ((BfData),(va))) ) 

#define KVA_ADDRESS(va)   ( VA_ADDRESS (BF_DATA,(va)) )
#define KBF_BOOL(va)      ( BF_BOOL  (BF_DATA,(va)) ) 
#define KBF_SINT(va)      ( BF_SINT  (BF_DATA,(va)) ) 
#define KBF_DINT(va)      ( BF_DINT  (BF_DATA,(va)) ) 
#define KBF_REAL(va)      ( BF_REAL  (BF_DATA,(va)) ) 
#define KBF_TIME(va)      ( BF_TIME  (BF_DATA,(va)) ) 
#define KBF_UDINT(va)     ( BF_UDINT (BF_DATA,(va)) ) 
#define KBF_INT(va)       ( BF_INT   (BF_DATA,(va)) ) 
#define KBF_USINT(va)     ( BF_USINT (BF_DATA,(va)) ) 
#define KBF_UINT(va)      ( BF_UINT  (BF_DATA,(va)) ) 
#define KBF_LINT(va)      ( BF_LINT  (BF_DATA,(va)) ) 
#define KBF_ULINT(va)     ( BF_ULINT (BF_DATA,(va)) ) 
#define KBF_LREAL(va)     ( BF_LREAL (BF_DATA,(va)) ) 
#define KBF_DATE(va)      ( BF_DATE  (BF_DATA,(va)) ) 
#define KBF_VA(va)        ( BF_VA    (BF_DATA,(va)) ) 

/* Kernel Access to lock flag of variables */
#ifdef ITGTDEF_VARLOCK
#define KVALCK_ADDRESS(va) ( VALCK_ADDRESS (BF_VARLOCK,(va)) )
#define KBFLCK_BOOL(va)    ( BFLCK_BOOL   (BF_VARLOCK,(va)) )  
#define KBFLCK_SINT(va)    ( BFLCK_SINT   (BF_VARLOCK,(va)) )  
#define KBFLCK_DINT(va)    ( BFLCK_DINT   (BF_VARLOCK,(va)) )  
#define KBFLCK_REAL(va)    ( BFLCK_REAL   (BF_VARLOCK,(va)) )  
#define KBFLCK_TIME(va)    ( BFLCK_TIME   (BF_VARLOCK,(va)) )  
#define KBFLCK_STRING(va)  ( BFLCK_STRING (BF_VARLOCK,(va)) )  
#define KBFLCK_INT(va)     ( BFLCK_INT    (BF_VARLOCK,(va)) )  
#define KBFLCK_USINT(va)   ( BFLCK_USINT  (BF_VARLOCK,(va)) )  
#define KBFLCK_UINT(va)    ( BFLCK_UINT   (BF_VARLOCK,(va)) )  
#define KBFLCK_UDINT(va)   ( BFLCK_UDINT  (BF_VARLOCK,(va)) )  
#define KBFLCK_LINT(va)    ( BFLCK_LINT   (BF_VARLOCK,(va)) )  
#define KBFLCK_ULINT(va)   ( BFLCK_ULINT  (BF_VARLOCK,(va)) )  
#define KBFLCK_LREAL(va)   ( BFLCK_LREAL  (BF_VARLOCK,(va)) )  
#define KBFLCK_DATE(va)    ( BFLCK_DATE   (BF_VARLOCK,(va)) )  
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
#define KBFLCK_VA(va)      ( BFLCK_VA     (BF_VARLOCK,(va)) )  
#endif

#define KVACNS_ADDRESS(va) ( VACNS_ADDRESS (BF_VARLOCK,(va)) )
#define KBFCNS_BOOL(va)    ( BFCNS_BOOL   (BF_VARLOCK,(va)) )  
#define KBFCNS_SINT(va)    ( BFCNS_SINT   (BF_VARLOCK,(va)) )  
#define KBFCNS_DINT(va)    ( BFCNS_DINT   (BF_VARLOCK,(va)) )  
#define KBFCNS_REAL(va)    ( BFCNS_REAL   (BF_VARLOCK,(va)) )  
#define KBFCNS_TIME(va)    ( BFCNS_TIME   (BF_VARLOCK,(va)) )  
#define KBFCNS_STRING(va)  ( BFCNS_STRING (BF_VARLOCK,(va)) )  
#define KBFCNS_INT(va)     ( BFCNS_INT    (BF_VARLOCK,(va)) )  
#define KBFCNS_USINT(va)   ( BFCNS_USINT  (BF_VARLOCK,(va)) )  
#define KBFCNS_UINT(va)    ( BFCNS_UINT   (BF_VARLOCK,(va)) )  
#define KBFCNS_UDINT(va)   ( BFCNS_UDINT  (BF_VARLOCK,(va)) )  
#define KBFCNS_LINT(va)    ( BFCNS_LINT   (BF_VARLOCK,(va)) )  
#define KBFCNS_ULINT(va)   ( BFCNS_ULINT  (BF_VARLOCK,(va)) )  
#define KBFCNS_LREAL(va)   ( BFCNS_LREAL  (BF_VARLOCK,(va)) )  
#define KBFCNS_DATE(va)    ( BFCNS_DATE   (BF_VARLOCK,(va)) )  
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
#define KBFCNS_VA(va)      ( BFCNS_VA     (BF_VARLOCK,(va)) )  
#endif

#define KVA_ADDRESS_REFRESH(va) ( VA_ADDRESS (BF_VARREFRESH,(va)) )
#define KBF_BOOL_REFRESH(va)    ( BF_BOOL  (BF_VARREFRESH,(va)) ) 
#define KBF_SINT_REFRESH(va)    ( BF_SINT  (BF_VARREFRESH,(va)) ) 
#define KBF_DINT_REFRESH(va)    ( BF_DINT  (BF_VARREFRESH,(va)) ) 
#define KBF_REAL_REFRESH(va)    ( BF_REAL  (BF_VARREFRESH,(va)) ) 
#define KBF_TIME_REFRESH(va)    ( BF_TIME  (BF_VARREFRESH,(va)) ) 
#define KBF_UDINT_REFRESH(va)   ( BF_UDINT (BF_VARREFRESH,(va)) ) 
#define KBF_INT_REFRESH(va)     ( BF_INT   (BF_VARREFRESH,(va)) ) 
#define KBF_USINT_REFRESH(va)   ( BF_USINT (BF_VARREFRESH,(va)) ) 
#define KBF_UINT_REFRESH(va)    ( BF_UINT  (BF_VARREFRESH,(va)) ) 
#define KBF_LINT_REFRESH(va)    ( BF_LINT  (BF_VARREFRESH,(va)) ) 
#define KBF_ULINT_REFRESH(va)   ( BF_ULINT (BF_VARREFRESH,(va)) ) 
#define KBF_LREAL_REFRESH(va)   ( BF_LREAL (BF_VARREFRESH,(va)) ) 
#define KBF_DATE_REFRESH(va)    ( BF_DATE  (BF_VARREFRESH,(va)) ) 
#define KBF_VA_REFRESH(va)      ( BF_VA    (BF_VARREFRESH,(va)) ) 

#endif

/* Resource backup location type for restoration */
#define ISA_BKUP_LOAD     1 /* Load from hard support (disk,...) */

/* Default resource backup location type for restoration */
#define ISA_BKUP_DEFAULT  ISA_BKUP_LOAD 

/* Default cycle spare time for working on Communication */
#define ISA_KER_DEFAULT_TIMEFORCOM     500 

/* Cycle time completion management */
#define ISA_KTCY_MINLOOPSLEEP   ISA_LOOP_SLEEP
#define ISA_KTCY_MAXLOOPSLEEP   250
#define ISA_KTCY_MINNOTIDLE     1000


/* Kernel Variable Binding */
#define ISA_KVB_MAXDRVREG   10 /* Max number of registered Drivers */

/* Retain parameters */
#define ISA_RTNREAD_DEFAULT 1 /* Not zero = read retain when start */

/* Kernel state */
#define ISA_NORES        1    /* No resource loaded */
#define ISA_RESLOADING   2    /* Resource is being loaded */
#define ISA_RESRESTORING 3    /* Resource is being restored */
#define ISA_RESLOADED    4    /* Resource loaded */
#define ISA_RESSTARTED   5    /* Resource started */
#define ISA_SHUTDOWN     6    /* Kernel shut down */

/* Resource mode */
#define ISA_RESMODE_NORES  0    /* No Resource available */
#define ISA_RESMODE_STORED 1    /* Stored resource available NOT USED (CMG) */
#define ISA_RESMODE_READY  2    /* Ready to run */
#define ISA_RESMODE_RT     3    /* Run in Real time */ 
#define ISA_RESMODE_CC     4    /* Run in Cycle by cycle */
#define ISA_RESMODE_BK     5    /* Run with Breakpoint encountered */
#define ISA_RESMODE_STP    7    /* Resource is stopped in stepping mode */
#define ISA_RESMODE_RES1   8    /* Reserved */
#define ISA_RESMODE_RES2   9    /* Reserved */
#define ISA_RESMODE_RES3   10   /* Reserved */

#define ISA_RESMODE_RS    -1    /* Fatal error */
#define ISA_RESMODE_STP_ERR -2  /* Resource is stopped in stepping mode after exception */
#define ISA_RESMODE_STP_ERR_DIV0  -3 /* Resource is stopped in stepping mode after division by zero exception */
#define ISA_RESMODE_STP_ERR_BOUND -4 /* Resource is stopped in stepping mode after bound check exception */
#define ISA_RESMODE_STP_ERR_MAX   -4 /* maximum negative value for stepping errors */

/* Pou status */
#define ISA_PST_INACTIVE        0x00   /* Inactive */
#define ISA_PST_ACTIVE          0x01   /* Active   */
#define ISA_PST_FROZEN          0x02   /* Frozen   */
#ifdef ITGTDEF_SFC_PROG_ACT_GROUPING
#define ISA_PST_CHILD_LASTCYCLE 0x03   /* Used to allow the child to terminate its cycle before dying. */
#endif
/* Pou levels */
#define ISA_MAXPLEVEL  19 /* Max level hierarchy of a Pou (0=higher level) */

/* Type of code format */
#define ISA_RESCODETYPE_TIC 1   /* Code TIC */
#define ISA_RESCODETYPE_SCC 2   /* Code C   */

/* Type of code to execute */
#define ISA_TICEXEC_CYCLIC     1  /* Cyclic programs */
#define ISA_TICEXEC_SFCTRS     2  /* Sfc transition */
#define ISA_TICEXEC_SFCSTP_P1  3  /* Sfc step P1 action */
#define ISA_TICEXEC_SFCSTP_N   4  /* Sfc step N  action */
#define ISA_TICEXEC_SFCSTP_P0  5  /* Sfc step P0 action */
#ifdef ITGTDEF_INTERRUPT
#define ISA_TICEXEC_IRQ        6  /* IRQ programs */
#endif

/* Sfc step/trans extra status bit field */
#define ISA_STPSTAT_BKPBEG   0x01  /* Sfc step with bkp on activation */
#define ISA_STPSTAT_BKPEND   0x02  /* Sfc step with bkp on deactivation */
#define ISA_TRASTAT_BKP      0x04  /* Sfc transition with bkp */

/* Kernel core functions inlining mark */
#ifndef KERINLINE
#define KERINLINE 
#endif

/* Number of block for kernel private resource data */ /*RFS8406*/
#define KPVRD_KPVRDPTRS_BLKNBR         0
#define KPVRD_BLKSEQPTRS_BLKNBR        1
#define KPVRD_PDF_BLKNBR               2
#define KPVRD_EXMTRS_BLKNBR            3
#define KPVRD_CLRTRS_BLKNBR            4
#define KPVRD_EXMRPACTCU_BLKNBR        5
#define KPVRD_EXMRPACTLS_BLKNBR        6
#define KPVRD_ACT_BLKNBR               7
#define KPVRD_KIOMNG_BLKNBR            8
#define KPVRD_RTIODVC_BLKNBR           9
#define KPVRD_RTIOCHAN_BLKNBR         10
#define KPVRD_KVB_BLKNBR              11
#define KPVRD_USFMNG_BLKNBR           12
#define KPVRD_FBLMNG_BLKNBR           13
#define KPVRD_CNVMNG_BLKNBR           14
#define KPVRD_MISDTA_BLKNBR           15
#define KPVRD_DBGDTA_BLKNBR           16
#define KPVRD_BKPSTPVA_BLKNBR         17 /* Backup of Step va            <----- added for ITGTDEF_ENH_ONLINE_CHANGE */
#define KPVRD_BKPTRSVA_BLKNBR         18 /* Backup of trans va           <----- added for ITGTDEF_ENH_ONLINE_CHANGE */
#define KPVRD_BKPSFCFBSTATE_BLKNBR    19 /* Backup of SFC FB state       <----- added for ITGTDEF_ENH_ONLINE_CHANGE_PHASE2 */

/* Number of block for kernel private resource data */
#define KPVRD_BLKNBR 20 

#ifdef ITGTDEF_FAILOVER
#define FAILOVER_KERSTATE_IDLE            0  /* The kernel is active */
#define FAILOVER_KERSTATE_WAIT_FOR_SYNC   1  /* The kernel is standby and waiting for sync data */
#define FAILOVER_KERSTATE_EXEC_TIC        2  /* The kernel is standby and can execute TIC */
#define FAILOVER_KERSTATE_WAIT_FOR_CRC    3  /* The kernel is standby and waiting for the CRC */
#define FAILOVER_KERSTATE_WRITE_IOS       4  /* The kernel is standby and can write IOs */
#endif

/* Execution steps of the kernel */
#define KERSTEP_INIT                      0
#define KERSTEP_EXEC_TIC                  1
#define KERSTEP_WRITE_IOS                 2

#define NB_WRITTEN_VARS                   50 /* The quantity of variables written by ixlWrite that can be synchronized through data link */

/* types ******************************************************************/
/**************************** DOXYGEN STRUCTURE ***************************/
#ifdef ITGTDEF_FAILOVER
typedef struct
{
   uint16         huSlaveNum;
   typSEM_ID      IxlMutexId;                   /*!< Mutex for accessing IXL API from kernel and download thread */
   typSPC_ID      CmgConfSpcId;                 /*!< Handle to the data space of the CMG */
   strCmgHeader*  pCmgConf;                     /*!< Pointer to the data space of the CMG */
   strRdccModulId* pRdcc;                       /*!< Pointer to the RDCC structure of the resource */
   uint32         luRDtaBaseCrc;             

   uchar          cuIsCommParamsLoaded;
   uchar          cuIsIxlInit;
   uchar          cuIsCmgConnected;
   uchar          cuIsCmgDialogStarted;
   uchar          cuIsResConnected;
   uchar          cuIsResDialogStarted;
#ifndef ITGTDEF_MONOTASK
   uchar          cuIsIxdConnected;              /* RFS 8572 */
   uchar          cuIsIxdDialogStarted;          /* RFS 8572 */
#endif
   typIxlCnxId    IxlCmgCnxId;
   typIxlCnxId    IxlResCnxId;
#ifndef ITGTDEF_MONOTASK
   typIxlCnxId    IxlIxdCnxId;                   /* RFS 8572 */
#endif

   uint32         luCommTimeoutMs;
   typIxlId       IxlId;
   char           tcParamETCP[81];

   typTHR_HDL     ThrReconnect;
   strThrParams   ReconnectThrParams;
   typTHR_HDL     ThrDownload;
   strThrParams   DownloadThrParams;

   uint32         luPathLen;
   char           tcResConfPath[ISA_PRJPATH_SIZE];
   char           tcResCodePath[ISA_PRJPATH_SIZE];
   char           tcResMdfPath[ISA_PRJPATH_SIZE];
   char           tcIxdNwConfPath[ISA_PRJPATH_SIZE];
   char           tcResSymTblPath[ISA_PRJPATH_SIZE];
   char           tcResPrjBakPath[ISA_PRJPATH_SIZE];
#ifdef ITGTDEF_FAILOVER_TCP_DATALINK
   uchar          tcTxDataBuffer[ISA_GETMAX(_IXL_SEND_BUF_SIZE, _TCP_BUF_SIZE)];
   uchar          tcRxDataBuffer[_TCP_BUF_SIZE];
#else
   uchar          tcTxDataBuffer[_IXL_SEND_BUF_SIZE];
#endif /* ITGTDEF_FAILOVER_TCP_DATALINK */
} strResFailover;
#endif /* ITGTDEF_FAILOVER */

/* Kernel core system module */
typedef struct 
{
   uint16      huSlaveNum;       /*!< Slave number */
#ifdef ITGTDEF_FAILOVER
   uchar          cuDoNotWriteOutputs;          /*!< TRUE if corrupted data was received from the active */
   uchar          cuFailoverStandbyState;       /*!< Execution state of the execution loop of the standby VM */
   uchar          cuFailoverFullDataResync;     /*!< TRUE if the whole data needs to be resynced */
   uint32         luFailoverLastDataSyncTimeMs; /*!< Time consumed by the last data sync */
#ifdef ISA_SYSVA_FO_DATASYNCCNT
   uint32         luFailoverFullDataSyncCounter;/*!< Count the quantity of full resync that has been performed on the failover system */
#endif /*ISA_SYSVA_FO_DATASYNCCNT*/
#endif   /* #ifdef ITGTDEF_FAILOVER */
   uchar       cuKerState;       /*!< Kernel state */

   typSPC_ID   ConfId;           /*!< Resource configuration module */
   void*       pvConfAdd;        /*!< Resource configuration address */
   uint32      luConfSize;       /*!< Resource configuration size */

   typSPC_ID   LinkId;           /*!< Resource blocks links module */
   void*       pvLinkAdd;        /*!< Resource blocks links address */
   uint32      luLinkSize;       /*!< Resource blocks links size */

   typSPC_ID   CodeId;           /*!< Resource code module */
   void**      ppvCodeBlks;      /*!< segmented module; 1st pou is at index 1 */
   uint16      huCodeBlkNbr;     /*!< Number of blocks */
#ifdef ITGTDEF_ENH_ONLINE_CHANGE
   uint16      huMaxCodeBlkNbr;  /*!< Max number of blocks */
#endif
   uint32*     pluCodeSizes;     /*!< Blocks sizes; 1st pou is at index 1 */

   void**      ppvMdfCodeBlks;   /*!< Code of on line modified pous */
#if defined(ITGTDEF_ENH_ONLINE_CHANGE) && defined(ITGTDEF_SFCFUNCTIONS) && defined (ITGTDEF_SFCFBL)
   void**      ppvMdfCodeBlksBkp;/*!< Code of on line modified pous for pre-realize check */
#endif
                                    
   typSPC_ID   DataId;           /*!< Resource data module */
#ifndef ITGTDEF_SEGMENT                 
   void*       pvDataAdd;        /*!< Non segmented module */
   uint32      luDataSize;       /*!< Non segmented module size */
#else                               
   void**      ppvDataBlks;      /*!< Segmented module        */
   uint16      huDataBlkNbr;     /*!< Number of blocks        */
   uint32*     pluDataSizes;     /*!< Blocks sizes            */
#endif

#ifdef ITGTDEF_VARLOCK
   typSPC_ID   VarLockId;        /*!< Resource lock flag of vars module */
   void*       pvVarLockAdd;     /*!< Resource lock flag module address */
   uint32      luVarLockSize;    /*!< Resource lock flag module size */

   void*       pvVarLockVaList;  /*!< List of locked VAs */
   uint32      luVarLockVaListNbElem; /*!< Current size of list */
   uint32      luVarLockVaListNbElemMax; /*!< Max size of list */

   typSPC_ID   VarRefreshId;     /*!< Resource refreshed vars when locked */
   void*       pvVarRefreshAdd;  /*!< Resource refreshed vars module address */
   uint32      luVarRefreshSize; /*!< Resource refreshed vars module size */
#endif

   /* Optional DSA modules */
   uint32      luEzsSize;        /*!< Resource embedded ziped source */
   uint32      luSymSize;        /*!< Resource symbols */
   uint32      luUdatSize;       /*!< Resource user data */

   /* Server */
   typSPC_ID   SrvId;            /*!< Server module */
   void*       pvSrvAdd;         /*!< Server module address */

   /* On line modif */
#ifdef ITGTDEF_MODIF
   typSPC_ID   MdfId;            /*!< Delta(s) for on line modif module */
   void*       pvMdfAdd;         /*!< Delta(s) for on line modif module address */
   uchar       cuMdfWaitForSymTable;/*!< flag to wait for the symbol table */
   uint32      luRDtaBaseCrcBeforeOnLineChange;/*!< CRC before on line modif */ 
#endif

   /* Hot restart */
#ifdef ITGTDEF_HOTRESTART
   typSPC_ID   BackupId;         /*!< Resource Hot Restart backup module */
   void*       pvBackupAdd;      /*!< Resource Hot Restart backup module address */
   uint32      luBkpSpcSize;     /*!< Resource Hot Restart backup module size */
#endif

   /* Kernel symbol management */
#ifdef ITGTDEF_KERSYM
   typSPC_ID   KerSymId;         /*!< Symbol table module */
   void*       pvKerSymAdd;      /*!< Symbol table module address */
   uint32      luKerSymSize;     /*!< Symbol table module size */

   typVa       FirstSysVa;       /*!< First system variable address */
   typVa       LastSysVa;        /*!< Last system variable address */
   typVa       FirstStepVa;      /*!< First step variable address */
   typVa       LastStepVa;       /*!< Last step variable address */
   uint32      luSizeOfStep;     /*!< Size of a step */
   uint32      luStepNbr;        /*!< Quantity of steps */
   typVa       FirstTrsVa;       /*!< First transition variable address */
   typVa       LastTrsVa;        /*!< Last transition variable address */
   typVa       FirstUserVa;      /*!< First user variable address */
   typVa       LastUserVa;       /*!< Last user variable address */
   uint32      luUserDataSize;   /*!< User data size */
#endif

   /* SFC function block */
   /* RFS6522 BEGIN */
#ifdef ITGTDEF_SFCFUNCTIONS
#ifdef ITGTDEF_SFCFBL
   typSPC_ID   SfcFblId;         /*!< SFC function block space */
   void*       pvSfcFblAdd;      /*!< Pointer on SFC function block space */
   uint32      luSfcFblSpcSize;  /*!< Size of the SFC function block space */
#endif
#endif /* ITGTDEF_SFCFUNCTIONS */

#if defined(ITGTDEF_MODIF) && (defined(ITGTDEF_RT_OPTIMIZE_CODE) && (defined(ISA_TMM_L) || defined (ITGTDEF_OPT_CODE_MED_AS_LRG)))
   typSPC_ID   OptimMdfId;       /*!< Space for optimized delta(s) for on line modif module */
   void*       pvOptimMdfAdd;    /*!< Optimized delta(s) for on line modif module address */
#endif /* defined(ITGTDEF_MODIF) defined(defined(ITGTDEF_RT_OPTIMIZE_CODE) && (defined(ISA_TMM_L) || defined (ITGTDEF_OPT_CODE_MED_AS_LRG))) */

#if defined(ITGTDEF_RT_OPTIMIZE_CODE) && (defined(ISA_TMM_L) || defined (ITGTDEF_OPT_CODE_MED_AS_LRG))
   uint32*     pluOptimPouCrc;   /*!< Actual CRC of optimized POUs (POU 0 is dummy) */
#endif /* defined(ITGTDEF_RT_OPTIMIZE_CODE) && (defined(ISA_TMM_L) || defined (ITGTDEF_OPT_CODE_MED_AS_LRG)) */

#ifdef ITGTDEF_OPT_CODE_MED_AS_LRG
   typSPC_ID   OptPouSpcId;      /*!< Optimized code space ID */
   void*       pvOptPouSpc;      /*!< Pointer to optimized code space */
   void**      ppvOptCodeBlks;   /*!< Optimized TIC code */
   uint32*     pluOptCodeSizes;  /*!< Size of each POU */
#endif
} strKsys;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Kernel resource private data blocks table */
typedef struct
{                                             
   void*  pvKpvRDPtrsBlkAdd;     /*!< Block add of pointers to kpvrd */
   uint32 luKpvRDPtrsBlkSz;      /*!< Block size */
   void*  pvBlkSeqPtrsBlkAdd;    /*!< Cyclic/fct pgms, blck of tic seq, addresses */
   uint32 luBlkSeqPtrsBlkSz;     /*!< Block size */
#ifdef ITGTDEF_ENH_ONLINE_CHANGE
   void*  pvBkpStpVaBlkAdd;      /*!< Block addr of step va backup */
   uint32 luBkpStpVaBlkSz;       /*!< Block size of step va backup */
   void*  pvBkpTrsVaBlkAdd;      /*!< Block addr of trans va backup */
   uint32 luBkpTrsVaBlkSz;       /*!< Block size of trans va backup */
   void*  pvBkpSfcFbStateBlkAdd; /*!< Block addr of SFC FB state backup */
   uint32 luBkpSfcFbStateBlkSz;  /*!< Block size of SFC FB state backup */
#endif

   void*  pvPdfBlkAdd;           /*!< Block addr of POUs definitions */
   uint32 luPdfBlkSz;            /*!< Block size of POUs definitions */
   void*  pvExmTrsBlkAdd;        /*!< Block addr of transition examination management */
   uint32 luExmTrsBlkSz;         /*!< Block size of transition examination management */
   void*  pvClrTrsBlkAdd;        /*!< Block addr of transition clearing management */
   uint32 luClrTrsBlkSz;         /*!< Block size of rep act curr cycle exam mngmt */
   void*  pvExmRpActCuBlkAdd;    /*!< Block addr of rep act curr cycle exam mngmt */
   uint32 luExmRpActCuBlkSz;     /*!< Block size of rep act curr cycle exam mngmt */
   void*  pvExmRpActLsBlkAdd;    /*!< Block addr of rep act last cycle exam mngmt */
   uint32 luExmRpActLsBlkSz;     /*!< Block size of rep act last cycle exam mngmt */
   void*  pvActBlkAdd;           /*!< Block addr of actions execution management */
   uint32 luActBlkSz;            /*!< Block size of actions execution management */
   void*  pvKIoMngBlkAdd;        /*!< Block addr of ker info to manage IOs */
   uint32 luKIoMngBlkSz;         /*!< Block size of ker info to manage IOs */
   void*  pvRtIoDvcBlkAdd;       /*!< Block addr of IO devices run time structures */
   uint32 luRtIoDvcBlkSz;        /*!< Block size of IO devices run time structures */
   void*  pvRtIoChanBlkAdd;      /*!< Block addr of IO channels run time structures */
   uint32 luRtIoChanBlkSz;       /*!< Block size of IO channels run time structures */
   void*  pvKvbBlkAdd;           /*!< Binding mngmt addr: Kernel own mngmt + Driver ones */
   uint32 luKvbBlkSz;            /*!< Binding mngmt size: Kernel own mngmt + Driver ones */
#ifdef ITGTDEF_BINDIMPROVE2
   typSPC_ID BindSpaceId;        /*!< Binding module */

   void*  pvKvbBlkAddX;          /*!< Binding X module space */
   uint32 luKvbBlkSzX;           /*!< Pointer to the binding X module space */
   typSPC_ID BindSpaceIdX;       /*!< Size of the binding X module space */

   void*  pvKvbBlkAddY;          /*!< Binding Y module space */
   uint32 luKvbBlkSzY;           /*!< Pointer to the binding Y module space */
   typSPC_ID BindSpaceIdY;       /*!< Size of the binding Y module space */

   uchar  cuKvbCurSpaceIsY;      /*!< determine if the Y space is currently used */
   uchar  cuKvbNewSpaceIsY;      /*!< determine if the Y space is the new space */
#endif
   void*  pvUsfMngBlkAdd;        /*!< Block addr of pointers to usf fcts */
   uint32 luUsfMngBlkSz;         /*!< Block size of pointers to usf fcts */
   void*  pvFblMngBlkAdd;        /*!< Block addr of pointers to fblCall fcts */
   uint32 luFblMngBlkSz;         /*!< Block size of pointers to fblCall fcts */
   void*  pvCnvMngBlkAdd;        /*!< Block addr of pointers to cnv fcts */
   uint32 luCnvMngBlkSz;         /*!< Block size of pointers to cnv fcts */
   void*  pvMisDtaBlkAdd;        /*!< Block addr of miscellaneous data */
   uint32 luMisDtaBlkSz;         /*!< Block size of miscellaneous data */
   void*  pvDbgDtaBlkAdd;        /*!< Block addr for step by step debugging */
   uint32 luDbgDtaBlkSz;         /*!< Block size for step by step debugging */
} strKpvrd;

#ifdef ITGTDEF_ENH_ONLINE_CHANGE
typedef struct 
{
   uint32 luNbUsedEntries;       /*!< Number of strSfcFbStepBackup entries used */
} strSfcFbStepBackupHdr;

typedef struct
{
   /* Class number of the POU (PouVa) */
   /* VA of the instance (InstVa) */
   /* State of each step (from strSteInfo) */
   uchar    cuActive;      /*!< Zero if the step is inactive */
   uchar    cuInstStatus;  /*!< Instance status - Active, inactive or frozen */
   typVa    InstVa;        /*!< VA of the instance */
   typVa    PouVa;         /*!< Pou variable the step/transition belongs to */
   typVa    StepVa;        /*!< Step variable */
   uint32   luTimerInfo;   /*!< Step activation date OR activity duration */
} strSfcFbStepBackup;
#endif

#ifdef ITGTDEF_FAILOVER_WRITE_SYNC
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typIxlVa Va;            /*!< VA of the variable */
   uchar    cuVaType;      /*!< Type of the variable */
   uint32   luNbrOfElmt;   /*!< Quantity of element in the array */
}strWrittenVars;
#endif /*ITGTDEF_FAILOVER_WRITE_SYNC*/

/* data *******************************************************************/
#ifndef ITGTDEF_NO_GLOBALS /*globals dynamically allocated*/

extern strKsys  KSYS;   /* Kernel core system module */

#ifndef ITGTDEF_SEGMENT /* Non segmented systems */
extern void* BF_DATA;
#else /* Segmented systems */
extern void** BF_DATA; /* Pointer on kernel resource data (KRD) */
#endif

#ifdef ITGTDEF_VARLOCK
extern void* BF_VARLOCK; /* Pointer on lock flags of resource variables */
extern void* BF_VARREFRESH; /* Pointer on kernel refreshed data when var is locked */
#endif

#endif  /*Any new global must also be declared in globals struct*/


/* exported services from module   ???    *********************************/

#endif  /* nested Headers management */
/* eof ********************************************************************/
