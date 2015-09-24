/**************************************************************************
File:               dsys0df2.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      21-august-1997 
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Extended Global definitions

***************************************************************************
Modifications: (who / date / description)
---4.02 Released---
EDS/16-Sep-1999/ 'C' conversion funct integration
   Added i/o direction macro and cnv fct proto typedef
EDS/28-Oct-1999/
   Added some task ids, init param, and limits for unavailable slave num
   Added new spc(mib,isxs)
   Renamed etcp msgq ==> ipc msgq + some new ipc msgq
   Raised max space, semaphore and message queue numbers
   Added ISAIXSDLL default define
   Removed semicolon at end of ISA_DO_ALIGN macro
   Added Basic macros
EDS/15-Nov-1999/
   Corrected format MIN-MAX constants. No more in hexa, now in decimal.
EDS/06-Dec-1999/
   Reamed ISA_SPC_ETCPDXS ==> ISA_SPC_NWLMISINFO to homogenize.
EDS/10-Jan-2000/
   Added definitions relative to simulator

---4.03 Released---
EDS/14-Apr-2000/ Build number add-on
   Modified ISA_STRVERS. Now version number is replaced by a build number
    specific to each components. ISA_STRVERS should no more be used.
JFO/15-Jun-2000/
   Added ISA_TIMEDIFF, macro to calculate time difference. Algorithm changes
    depending of ITGTDEF_NOMODULOCLK define.
EDS/27-Jul-2000/
   Made comments of luParam field in strRdccModulId more accurate
JFO/05-Sept-2000/
   Added ISA_ISUPPER, ISA_ISLOWER, ISA_TOUPPER, ISA_TOLOWER macro to manage
    lower case and upper case.
JFO/10-Oct-2000/
   Added strSysGmt structure for Greenwich Meridian Time.
JFO/04-Dec-2000/
   Added ISA_SPC_HDTSMM space used for Data Server memory manager.
JFO/19-Dec-2000/
   BUG 0889: Added ISA_BSEM_TSKSTARTSYNC for synchronization of task launching.

---4.10 Released---
EDS/05-Oct-2001/ Variables locking 
   Added new space ISA_SPC_RESVARLOCK
   Added macro for access to lock flag of variables BFLCK_XXX
   Added macro for conditional assignation if define set ISA_DO_ASSGNCHK

---4.11 Released---
VMO/12-Mar-2002/ Hot restart 
   Added ISAIXLDLLSYM macro to export symbol table services.
   Added 'C' function blocks SubFunc typedef
   
---4.12 Released---
VMO/12-June-2002/ SFC function block
   Update TARGET_RDCCVERS to managed SFC function block
   Added new space ISA_SPC_SFCFBL

---4.13 Released---
JFO/04-Jul-2001/ Improve download.
   Add ISA_RESNBR to manage number of resources.
   Add ISA_CNXNBR to manage number of connections.
COL/22-Nov-2001/ Error report.
   Added errors
   Added ISA_SPC_WNGSH
   Added ISA_MSEM_WNGSH
   Added structure contain header of share error modul
   Added structure contain the warning description
VMO/26-Mar-2002/ IOs online modification
   Update TARGET_RDCCVERS for management of IO's MDF
FG/20-Aug-2002/
   Added ISA_TIME_WRAP, strSysRtc

---4.20 Released---
GM1/20-Jul-2003/
   Update TARGET_RDCCVERS for IXL download functions

---5.00 Released---
OL/02-Feb-2005/ New data type
   Add TIC code for INT, LINT, USINT, USINT, UDINT, ULINT, LREAL and DATE.

FT/4-Aug-2005/RFS-4468
   Two memory spaces added for retain variables write on a change only.
  
---5.00.001 Released---
OLA/03-Nov-2005/ RFS 2553: SFC FB cannot share is local variables with its childs.
   Update TARGET_RDCCVERS to ISA_RDCC_SFC_CHILD_GSTART
  
---Vantage 100.00.001 Released---
ED/18-Dec-2006
   Enhanced online change support for retained variables.
  
---Vantage 100.00.600 Released---
FT/19-Oct-2007
   New macros for the Lock Flag Byte which now reserves 2 bits for binding.
  
---5.22 Released---
FT/11-Dec-2008/ RFS-7307
   New ISA_MAX_FLOAT_DIGIT constant.

***************************************************************************/

#ifndef _DSYS0DF2_H  /* nested Headers management */
#define _DSYS0DF2_H 

/* constants **************************************************************/
/*------------------------------------------------------------------------*/
/* Dynamic configuration constants                                        */
/*------------------------------------------------------------------------*/
/****************** DOXYGEN RUNTIME CONFIGURATION OPTION **********************/
/*! \addtogroup   Runtime Runtime Configuration Options
* \addtogroup     AppParams Isa Startup Parameters
* \ingroup        Runtime
*******************************************************************************
* \b   Option \b name: 	   [APP] NOETCP
* \n\b Description: 	      Disables ETCP task.
* \n\b Possible \b values: 0-1
* \n\b Default \b Value:   0
*/
/******************************************************************************/
#define ETCP_CFG_NO_ETCP               "NOETCP"
#define ETCP_DEF_CFG_NO_ETCP            0

/****************** DOXYGEN RUNTIME CONFIGURATION OPTION **********************/
/*! \addtogroup   Runtime Runtime Configuration Options
* \addtogroup     AppParams Isa Startup Parameters
* \ingroup        Runtime
*******************************************************************************
* \b   Option \b name: 	   [APP] NImplCPOByPass
* \n\b Description: 	      Initializes custom module for conversion function blocks.
* \n\b Possible \b values: 0-1
* \n\b Default \b Value:   0
*/
/******************************************************************************/
#define KER_PARAM_CUSTOM_MOD              "NImplCPOByPass"
#define KER_DEF_PARAM_CUSTOM_MOD          0

/****************** DOXYGEN RUNTIME CONFIGURATION OPTION **********************/
/*! \addtogroup   Runtime Runtime Configuration Options
* \addtogroup     AppParams Isa Startup Parameters
* \ingroup        Runtime
*******************************************************************************
* \b   Option \b name: 	   [APP] IosSimul
* \n\b Description: 	      Enables I/O simulation.
* \n\b Possible \b values: 0-1
* \n\b Default \b Value:   0
*/
/******************************************************************************/
#define KER_PARAM_IO_SIMUL              "IosSimul"
#define KER_DEF_PARAM_IO_SIMUL          0

/****************** DOXYGEN RUNTIME CONFIGURATION OPTION **********************/
/*! \addtogroup   Runtime Runtime Configuration Options
* \addtogroup     AppParams Isa Startup Parameters
* \ingroup        Runtime
*******************************************************************************
* \b   Option \b name: 	   [APP] s
* \n\b Description: 	      Get number of resource to start
* \n\b Possible \b values: 0-4294967295
* \n\b Default \b Value:   1
*/
/******************************************************************************/
#define KER_PARAM_SLAVE_NB              "s"
#define KER_DEF_PARAM_SLAVE_NB          ISA_DF_SLAVENUM

/****************** DOXYGEN RUNTIME CONFIGURATION OPTION **********************/
/*! \addtogroup   Runtime Runtime Configuration Options
* \addtogroup     AppParams Isa Startup Parameters
* \ingroup        Runtime
*******************************************************************************
* \b   Option \b name: 	   [APP] SpareTimeForCom
* \n\b Description: 	      Cycle spare time for working on Communication
* \n\b Possible \b values: 0-4294967295
* \n\b Default \b Value:   500
*/
/******************************************************************************/
#define KER_PARAM_SPARE_TIME_FOR_COM      "SpareTimeForCom"
#define KER_DEF_PARAM_SPARE_TIME_FOR_COM  ISA_KER_DEFAULT_TIMEFORCOM

/****************** DOXYGEN RUNTIME CONFIGURATION OPTION **********************/
/*! \addtogroup   Runtime Runtime Configuration Options
* \addtogroup     AppParams Isa Startup Parameters
* \ingroup        Runtime
*******************************************************************************
* \b   Option \b name: 	   [APP] RtnRead
* \n\b Description: 	      Reads retain values when resource is started.
* \n\b Possible \b values: 0-1
* \n\b Default \b Value:   1
*/
/******************************************************************************/
#define KER_PARAM_READ_RETAIN              "RtnRead"
#define KER_DEF_PARAM_READ_RETAIN          ISA_RTNREAD_DEFAULT

/****************** DOXYGEN RUNTIME CONFIGURATION OPTION **********************/
/*! \addtogroup   Runtime Runtime Configuration Options
* \addtogroup     AppParams Isa Startup Parameters
* \ingroup        Runtime
*******************************************************************************
* \b   Option \b name: 	   [APP] ?
* \n\b Description: 	      Displays application usage information.
* \n\b Possible \b values: 0-1
* \n\b Default \b Value:   0
*/
/******************************************************************************/
#define KER_PARAM_USAGE             "?"
#define KER_DEF_PARAM_USAGE         0

/****************** DOXYGEN RUNTIME CONFIGURATION OPTION **********************/
/*! \addtogroup   Runtime Runtime Configuration Options
* \addtogroup     AppParams Isa Startup Parameters
* \ingroup        Runtime
*******************************************************************************
* \b   Option \b name: 	   [APP] stgMode
* \n\b Description: 	      Configuration manager starting mode. 
*                          (1 for automatic restauration)
* \n\b Possible \b values: 1
* \n\b Default \b Value:   1
*/
/******************************************************************************/
#define KER_PARAM_CFG_START_MODE       "stgMode"
#define KER_DEF_PARAM_CFG_START_MODE   ISA_KERSTGMODE_DEFAULT

/****************** DOXYGEN RUNTIME CONFIGURATION OPTION **********************/
/*! \addtogroup   Runtime Runtime Configuration Options
* \addtogroup     AppParams Isa Startup Parameters
* \ingroup        Runtime
*******************************************************************************
* \b   Option \b name: 	   [APP] stgMode
* \n\b Description: 	      Resource backup location type for restoration. 
*                          1: Load from hard support (disk,...)
* \n\b Possible \b values: 1 (Load from hard support)
* \n\b Default \b Value:   1
*/
/******************************************************************************/
#define KER_PARAM_BACKUP_TYPE       "bkupType"
#define KER_DEF_PARAM_BACKUP_TYPE   ISA_BKUP_DEFAULT

/****************** DOXYGEN RUNTIME CONFIGURATION OPTION **********************/
/*! \addtogroup   Runtime Runtime Configuration Options
* \addtogroup     AppParams Isa Startup Parameters
* \ingroup        Runtime
*******************************************************************************
* \b   Option \b name: 	   [APP] PrjPath
* \n\b Description: 	      Set project path
* \n\b Possible \b values: String
* \n\b Default \b Value:   0
*/
/******************************************************************************/
#define SYS_PARAM_PRJ_PATH       "PrjPath"
#define SYS_DEF_PARAM_PRJ_PATH   0

/****************** DOXYGEN RUNTIME CONFIGURATION OPTION **********************/
/*! \addtogroup   Runtime Runtime Configuration Options
* \addtogroup     AppParams Isa Startup Parameters
* \ingroup        Runtime
*******************************************************************************
* \b   Option \b name: 	   [APP] WngPeriod
* \n\b Description: 	      Get the warning period. The value of this parameter 
*                          is in milliseconds
* \n\b Possible \b values: 0 - 4294967295
* \n\b Default \b Value:   60000
*/
/******************************************************************************/
#define SYS_PARAM_WNG_PERIOD      "WngPeriod"
#define SYS_DEF_PARAM_WNG_PERIOD   60000

/****************** DOXYGEN RUNTIME CONFIGURATION OPTION **********************/
/*! \addtogroup   Runtime Runtime Configuration Options
* \addtogroup     AppParams Isa Startup Parameters
* \ingroup        Runtime
*******************************************************************************
* \b   Option \b name: 	   [APP] P
* \n\b Description: 	      Identifies the primary kernel of a Failover system
* \n\b Possible \b values: 0-1
* \n\b Default \b Value:   0
*/
/******************************************************************************/
#define KER_PARAM_PRIMARY_KERNEL       "PR"
#define KER_DEF_PARAM_PRIMARY_KERNEL   0

/****************** DOXYGEN RUNTIME CONFIGURATION OPTION **********************/
/*! \addtogroup   Runtime Runtime Configuration Options
* \addtogroup     AppParams Isa Startup Parameters
* \ingroup        Runtime
*******************************************************************************
* \b   Option \b name: 	   [APP] S
* \n\b Description: 	      Identifies the secondary kernel of a Failover system
* \n\b Possible \b values: 0-1
* \n\b Default \b Value:   0
*/
/******************************************************************************/
#define KER_PARAM_SECONDARY_KERNEL     "SE"
#define KER_DEF_PARAM_SECONDARY_KERNEL 0

/****************** DOXYGEN RUNTIME CONFIGURATION OPTION **********************/
/*! \addtogroup   Runtime Runtime Configuration Options
* \addtogroup     AppParams Isa Startup Parameters
* \ingroup        Runtime
*******************************************************************************
* \b   Option \b name: 	   [APP] FailoverDatalinkTcpBasePort
* \n\b Description: 	      Base TCP port to use for the failover TCP datalink.
*                          Each resource will add its resource number to this
*                          value.
* \n\b Possible \b values: 0-4294967295
* \n\b Default \b Value:   1
*/
/******************************************************************************/
#define KER_PARAM_FAILOVER_DATALINK_TCP_BASE_PORT     "FailoverDatalinkTcpBasePort"
#define KER_DEF_PARAM_FAILOVER_DATALINK_TCP_BASE_PORT 6004

/****************** DOXYGEN RUNTIME CONFIGURATION OPTION **********************/
/*! \addtogroup   Runtime Runtime Configuration Options
* \addtogroup     AppParams Isa Startup Parameters
* \ingroup        Runtime
*******************************************************************************
* \b   Option \b name: 	   [APP] FailoverHeartBeatPort
* \n\b Description: 	      Socket UDP port number to use for the heartbeat.
* \n\b Possible \b values: 0-65535
* \n\b Default \b Value:   6003
*/
/******************************************************************************/
#define CMG_PARAM_FAILOVER_HEARTBEAT_PORT     "FailoverHeartBeatPort"
#define CMG_DEF_PARAM_FAILOVER_HEARTBEAT_PORT 6003

/* IEC61850 configuration files names */
#ifdef ITGTDEF_IEC61850_SRV_SCO
#define ISA_IEC61850_SRV_CFG_FILE "isagraf.cid"
#endif
#ifdef ITGTDEF_IEC61850_SRV_TMW
#define ISA_IEC61850_SRV_CFG_FILE "isagraf.icd"
#endif
#define ISA_IEC61850_SRV_REF_FILE "ISPADDR"

/* Product version in help command line */
#define ISA_STRVERS "\nISaGRAF Pro\n"

/* The purpose of this macro definition is to indicate that variable is unused intentionally */
#define ISA_UNUSED(x) (void)(x)

/* Errors */
#define ISA_RC_DSYS_NBROFERR  0x02050001UL /* Invalid number of errors */
#define ISA_RC_DSYS_SEMCREATE 0x02050002UL /* Semaphore can be created */
#define ISA_RC_DSYS_SEMOPEN   0x02050003UL /* Open semaphore failed */
#define ISA_RC_DSYS_SEMTAKE   0x02050004UL /* Take semaphore failed */
#define ISA_RC_DSYS_SPCCREATE 0x02050005UL /* Space cannot be created */
#define ISA_RC_DSYS_SPCDELETE 0x02050006UL /* Space cannot be deleted */
#define ISA_RC_DSYS_SPCLINK   0x02050007UL /* Link to space failed */
#define ISA_RC_DSYS_SPCUNLINK 0x02050008UL /* Unlink to space failed */
#define ISA_RC_DSYS_WNGSET    0x02050009UL /* Set error if the space failed */
#define ISA_RC_DSYS_SPCEMPTY  0x0205000AUL /* Warning stack is empty */

/* RDCC information */
#define ISA_RDCC_LREAL              8
#define ISA_RDCC_NEW_DATA_TYPES     10
#define ISA_RDCC_SFC_CHILD_GSTART   11
#define ISA_RDCC_CST_INIT_VAL_MDF   12

/* Target versions */
#define ISA_TARGET_MAJOR_VERSION	5
#define ISA_TARGET_MINOR_VERSION	41

#define ISA_MAIN_YEARSTR "2014"
#define ISA_MAIN_BUILDNUMSTR "5.41.24_(01/21/2014)"

/* Determine this target's RDCC */
#define TARGET_RDCCVERS ISA_RDCC_CST_INIT_VAL_MDF /* RFS8362 */

/* Unavailable slave numbers (Ored values:..||..) */
#define ISA_ISUNAVISLAVENUM(huSlaveNum)           \
   (  ((huSlaveNum) == 0)                         \
    ||(  ((huSlaveNum) >= ISA_LOWLIM_TASK_ID)     \
       &&((huSlaveNum) <= ISA_HIGHLIM_TASK_ID) ) )

/* Default slave number */
#define ISA_DF_SLAVENUM    1 

/* Starting (ker-cmg) mode (bits field) */
#define ISA_STGMODE_AUTORESTORE 0x0001 /* Automatic restoration */
				       
/* Arguments management for startup configuration */
#define ISA_ARG_GET_INFO     1
#define ISA_ARG_GET_INT32    2
#define ISA_ARG_GET_UINT32   3
#define ISA_ARG_GET_INT16    4
#define ISA_ARG_GET_UINT16   5
#define ISA_ARG_GET_STRING   6

/* Tasks Identifier */
#define ISA_HIGHLIM_TASK_ID  4095
#define ISA_CMG_TASK_ID      4095
#define ISA_IXD_TASK_ID      4094
#define ISA_ETCP_TASK_ID     4093
#define ISA_RSI_TASK_ID      4092
#define ISA_COM_TASK_ID      4091
#define ISA_ECAT_TASK_ID     4090
#define ISA_HBT_TASK_ID      4089
#define ISA_CO_TASK_ID       4088
#define ISA_IEC61850_TASK_ID 4087

#define ISA_WBDBG_TASK_ID    4065
#define ISA_WBDIP_TASK_ID    4064
#define ISA_OPCSRV_TASK_ID   4063
#define ISA_CTLPNL_TASK_ID   4062
#define ISA_HDTS_TASK_ID     4061
#define ISA_DF_TASK_ID       4001
#define ISA_LOWLIM_TASK_ID   4001

/* System Layer initialization parameter */
#define ISA_SYS_PINIT_KERNEL    1
#define ISA_SYS_PINIT_IXLCLIENT 2
#define ISA_SYS_PINIT_CMG       3
#define ISA_SYS_PINIT_IXD       4
#define ISA_SYS_PINIT_ETCP      5
#define ISA_SYS_PINIT_RSI       6
#define ISA_SYS_PINIT_HDTS      7
#define ISA_SYS_PINIT_COM       8
#define ISA_SYS_PINIT_ECAT      9
#define ISA_SYS_PINIT_HBT       10

/* Variables types */
#define ISA_TYPBOOL          1     /* Boolean */
#define ISA_TYPSINT          2     /* Sint */
#define ISA_TYPDINT          3     /* Double Integer */
#define ISA_TYPTIME          4     /* Time */
#define ISA_TYPREAL          5     /* Real */
#define ISA_TYPSTRING        6     /* String Message */
#define ISA_TYPBLOCK         7     /* Memory Block of data (structs) */
#define ISA_TYPUSINT         8     /* USINT */
#define ISA_TYPINT           9     /* INT */
#define ISA_TYPUINT         10     /* UINT */
#define ISA_TYPUDINT        11     /* UDINT */
#define ISA_TYPLINT         12     /* LINT */
#define ISA_TYPULINT        13     /* ULINT */
#define ISA_TYPDATE         14     /* DATE */
#define ISA_TYPLREAL        15     /* LREAL */

#ifdef _ISA3 /* Do NOT define _ISA3. _ISA3 is used only by ICS Triplex
                to build ISA3 libraries used by the Workbench */

#define ISA_TYPSTEP         254    /* Isagraf3 step */
#define ISA_TYPTRANSITION   253    /* Isagraf3 transition */
#endif

/* Definitions relative to simulator */
#define ISA_TGTNAME_SIMUL     "SIMULATOR"
#define ISA_TGTNAME_NT        "NT-TARGET"
#define ISA_TGTNAME_NT_L      "NT-TARGET_L"
#define ISA_TGTNAME_WIN32     "WIN32-TGT"       /* For ISaGRAF v5 */
#define ISA_TGTNAME_WIN32_L   "WIN32-TGT_L"     /* For ISaGRAF v5 */
#define ISA_TGTNAME_WINDOWS   "WINDOWS-TGT"     /* For ISaGRAF v5.2x */
#define ISA_TGTNAME_WINDOWS_L "WINDOWS-TGT_L"   /* For ISaGRAF v5.2x */
#define ISA_TGTNAME_WIN530_M  "WINDOWS-V530-M"  /* For ISaGRAF v5.30 */
#define ISA_TGTNAME_WIN530_L  "WINDOWS-V530-L"  /* For ISaGRAF v5.30 */
#define ISA_TGTNAME_WIN540_M  "WINDOWS-V540-M"  /* For ISaGRAF v5.40 */
#define ISA_TGTNAME_WIN540_L  "WINDOWS-V540-L"  /* For ISaGRAF v5.40 */
#define ISA_TGTNAME_WIN541_M  "WINDOWS-V541-M"  /* For ISaGRAF v5.41 */
#define ISA_TGTNAME_WIN541_L  "WINDOWS-V541-L"  /* For ISaGRAF v5.41 */

/* I/O Variables direction */
#define ISA_IO_DIR_INPUT   0  /* Input variable */
#define ISA_IO_DIR_OUTPUT  1  /* Ouput variable */

/* Maximum length of component name (for warning) */
#define ISA_SYS_MAXLNCMPTNM  8

/* Import/Export Header function prototype */
/* No Definitions */
#ifndef ISASYSDLL
#define ISASYSDLL 
#endif
#ifndef ISAIXLDLL
#define ISAIXLDLL
#endif
#ifndef ISAIXSDLL
#define ISAIXSDLL 
#endif
#ifndef ISAAFBDLL
#define ISAAFBDLL
#endif
#ifndef ISASERDLL
#define ISASERDLL
#endif
#ifndef ISANDTDLL
#define ISANDTDLL
#endif
#ifndef ISAMCDLL
#define ISAMCDLL
#endif
#ifndef ISAMBDLL
#define ISAMBDLL
#endif
#ifndef ISASAFEDLL
#define ISASAFEDLL
#endif

/* Define new macro to export symbol table services if needed */
#ifdef ITGTDEF_HOTRESTART
#define ISAIXLDLLSYM ISAIXLDLL
#ifndef ITGTDEF_KERSYM
#error ("Hot Restart need ITGTDEF_KERSYM macro to be defined")
#endif
#else
/* #define ISAIXLDLLSYM */
#define ISAIXLDLLSYM ISAIXLDLL  /* always define because needed by IxlMgr */
#endif

/* Register Storage class */
#ifdef ITGTDEF_USEREGISTER
#define ISA_VARINREG register
#else
#define ISA_VARINREG 
#endif 

/* Memory alignment */
#define ISA_DO_ALIGN(luSize) (((((luSize)+ISA_ALIGN)-1) /ISA_ALIGN)*ISA_ALIGN)

/* 'C' and IO Functions name max length and case management*/ /* RFS8347 */
#define _FCTNMMLN 51

/* String variables manipulation */ /* RFS 7741 */
#define _STRVAADD(va)   ((uchar*)KVA_ADDRESS((va)))
#define _STRTBOFFS(va)  (_MAXLEN(KVA_ADDRESS(va)) + 3)
#define _MAXLEN(pt)     (*(uchar*)(pt))
#define _CURLEN(pt)     (*(((uchar*)(pt))+1))
#define _BUFADD(pt)     (((char*)(pt))+2)
#ifdef ITGTDEF_VARLOCK
#define _STRVAADD_REFRESH(va) ((uchar*)KVA_ADDRESS_REFRESH((va)))
#endif

/* Access to Variables addresses and values */
#ifndef ITGTDEF_SEGMENT
#define VA_ADDRESS(BfData,va) (&((uchar*)(BfData))[(va)])
#else
#define VA_ADDRESS(BfData,va) ( ((uchar**)(BfData))[(va)>>ISA_SEGMT_MSB] \
						  + ((va) & ISA_SEGMT_MSK) )
#ifdef ITGTDEF_HOTRESTART
#error ("Hot Restart feature is not implemented for segmented systems")
#endif
#endif
#define BF_BOOL(BfData,va)    ( *(uchar*)  (VA_ADDRESS ((BfData),(va))) ) 
#define BF_SINT(BfData,va)    ( *(char*)   (VA_ADDRESS ((BfData),(va))) ) 
#define BF_DINT(BfData,va)    ( *(int32*)  (VA_ADDRESS ((BfData),(va))) ) 
#define BF_REAL(BfData,va)    ( *(float*)  (VA_ADDRESS ((BfData),(va))) ) 
#define BF_TIME(BfData,va)    ( *(uint32*) (VA_ADDRESS ((BfData),(va))) ) 
#define BF_INT(BfData,va)     ( *(int16*)  (VA_ADDRESS ((BfData),(va))) ) 
#define BF_LINT(BfData,va)    ( *(int64*)  (VA_ADDRESS ((BfData),(va))) ) 
#define BF_USINT(BfData,va)   ( *(uchar*)  (VA_ADDRESS ((BfData),(va))) ) 
#define BF_UINT(BfData,va)    ( *(uint16*) (VA_ADDRESS ((BfData),(va))) ) 
#define BF_UDINT(BfData,va)   ( *(uint32*) (VA_ADDRESS ((BfData),(va))) ) 
#define BF_ULINT(BfData,va)   ( *(uint64*) (VA_ADDRESS ((BfData),(va))) ) 
#define BF_LREAL(BfData,va)   ( *(real64*) (VA_ADDRESS ((BfData),(va))) ) 
#define BF_DATE(BfData,va)    ( *(date*)   (VA_ADDRESS ((BfData),(va))) ) 

/* Lock flag bytes */
/* There is one lock flag byte for every variable */
/* If a variable is 4 bytes long, there is 4 indentical lock flag bytes for this variable */
/* Bit 0 of the lock flag byte indicate that the variable is bounded and consuming */
/* Bit 1 of the lock flag byte indicate that the variable is bounded and producing */
/* Bit 2-7 of the lock flag byte indicate that the variable is locked (1) or unlocked (0) */
#ifdef ITGTDEF_VARLOCK

#define VALCK_ADDRESS(BfVarLock,va) ((uchar*)(BfVarLock) + (va))

#define ISA_LOCKFLAG_CONS_MASK      0x01
#define ISA_LOCKFLAG_PROD_MASK      0x02
#define ISA_LOCKFLAG_BIND_MASK      0x03

#define ISA_LOCKFLAG_PROD_MASK_16   0x0101
#define ISA_LOCKFLAG_CONS_MASK_16   0x0202
#define ISA_LOCKFLAG_BIND_MASK_16   0x0303

#define ISA_LOCKFLAG_PROD_MASK_32   0x01010101UL
#define ISA_LOCKFLAG_CONS_MASK_32   0x02020202UL
#define ISA_LOCKFLAG_BIND_MASK_32   0x03030303UL

   #define ISA_LOCKFLAG_PROD_MASK_64   0x0101010101010101ULL
   #define ISA_LOCKFLAG_CONS_MASK_64   0x0202020202020202ULL
   #define ISA_LOCKFLAG_BIND_MASK_64   0x0303030303030303ULL

/* Test to determine if a variable is locked */
#define BFLCK_BOOL(BfVarLock,va)    (( *(uchar*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uchar)~ISA_LOCKFLAG_BIND_MASK)
#define BFLCK_SINT(BfVarLock,va)    (( *(uchar*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uchar)~ISA_LOCKFLAG_BIND_MASK)
#define BFLCK_DINT(BfVarLock,va)    (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)~ISA_LOCKFLAG_BIND_MASK_32)
#define BFLCK_REAL(BfVarLock,va)    (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)~ISA_LOCKFLAG_BIND_MASK_32)
#define BFLCK_TIME(BfVarLock,va)    (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)~ISA_LOCKFLAG_BIND_MASK_32)
#define BFLCK_STRING(BfVarLock,va)  (( *(uchar*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uchar)~ISA_LOCKFLAG_BIND_MASK)
#define BFLCK_INT(BfVarLock,va)     (( *(uint16*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint16)~ISA_LOCKFLAG_BIND_MASK_16)
#define BFLCK_USINT(BfVarLock,va)   (( *(uchar*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uchar)~ISA_LOCKFLAG_BIND_MASK)
#define BFLCK_UINT(BfVarLock,va)    (( *(uint16*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint16)~ISA_LOCKFLAG_BIND_MASK_16)
#define BFLCK_UDINT(BfVarLock,va)   (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)~ISA_LOCKFLAG_BIND_MASK_32)
#define BFLCK_DATE(BfVarLock,va)    (( *(date*)   (VALCK_ADDRESS ((BfVarLock),(va)))) & (date)~ISA_LOCKFLAG_BIND_MASK_32)
#ifdef ITGTDEF_INT64
   #define BFLCK_LINT(BfVarLock,va)    (( *(uint64*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint64)~ISA_LOCKFLAG_BIND_MASK_64)
   #define BFLCK_ULINT(BfVarLock,va)   (( *(uint64*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint64)~ISA_LOCKFLAG_BIND_MASK_64)
   #define BFLCK_LREAL(BfVarLock,va)   (( *(uint64*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint64)~ISA_LOCKFLAG_BIND_MASK_64)
#else  /* ITGTDEF_INT64 */
   #define BFLCK_LREAL(BfVarLock,va)   (  (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)~ISA_LOCKFLAG_BIND_MASK_32) && \
                                          (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va + sizeof(uint32))))) & (uint32)~ISA_LOCKFLAG_BIND_MASK_32) )
#endif /* ITGTDEF_INT64 */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
#ifdef ISA_TMM_L
#define BFLCK_VA(BfVarLock,va)      (( *(uint32*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)~ISA_LOCKFLAG_BIND_MASK_32)
#else
#define BFLCK_VA(BfVarLock,va)      (( *(uint16*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint16)~ISA_LOCKFLAG_BIND_MASK_16)
#endif
#endif

/* Test to determine if a variable is a consumer binding */
#define VACNS_ADDRESS(BfVarLock,va) ((uchar*)(BfVarLock) + (va))
#define BFCNS_BOOL(BfVarLock,va)    (( *(uchar*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uchar)ISA_LOCKFLAG_CONS_MASK)
#define BFCNS_SINT(BfVarLock,va)    (( *(uchar*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uchar)ISA_LOCKFLAG_CONS_MASK)
#define BFCNS_DINT(BfVarLock,va)    (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)ISA_LOCKFLAG_CONS_MASK_32)
#define BFCNS_REAL(BfVarLock,va)    (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)ISA_LOCKFLAG_CONS_MASK_32)
#define BFCNS_TIME(BfVarLock,va)    (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)ISA_LOCKFLAG_CONS_MASK_32)
#define BFCNS_STRING(BfVarLock,va)  (( *(uchar*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uchar)ISA_LOCKFLAG_CONS_MASK)
#define BFCNS_INT(BfVarLock,va)     (( *(uint16*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint16)ISA_LOCKFLAG_CONS_MASK_16)
#define BFCNS_USINT(BfVarLock,va)   (( *(uchar*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uchar)ISA_LOCKFLAG_CONS_MASK)
#define BFCNS_UINT(BfVarLock,va)    (( *(uint16*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint16)ISA_LOCKFLAG_CONS_MASK_16)
#define BFCNS_UDINT(BfVarLock,va)   (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)ISA_LOCKFLAG_CONS_MASK_32)
#define BFCNS_DATE(BfVarLock,va)    (( *(date*)   (VALCK_ADDRESS ((BfVarLock),(va)))) & (date)ISA_LOCKFLAG_CONS_MASK_32)
#ifdef ITGTDEF_INT64
   #define BFCNS_LINT(BfVarLock,va)    (( *(uint64*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint64)ISA_LOCKFLAG_CONS_MASK_32)
   #define BFCNS_ULINT(BfVarLock,va)   (( *(uint64*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint64)ISA_LOCKFLAG_CONS_MASK_32)
   #define BFCNS_LREAL(BfVarLock,va)   (( *(uint64*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint64)ISA_LOCKFLAG_CONS_MASK_32)
#else  /* ITGTDEF_INT64 */
   #define BFCNS_LREAL(BfVarLock,va)   (  (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)ISA_LOCKFLAG_CONS_MASK_32) && \
                                          (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va + sizeof(uint32))))) & (uint32)ISA_LOCKFLAG_CONS_MASK_32) )
#endif /* ITGTDEF_INT64 */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
#ifdef ISA_TMM_L
#define BFCNS_VA(BfVarLock,va)      (( *(uint32*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)ISA_LOCKFLAG_CONS_MASK_32)
#else
#define BFCNS_VA(BfVarLock,va)      (( *(uint16*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint16)ISA_LOCKFLAG_CONS_MASK_16)
#endif
#endif

/* Test to determine if a variable is a producer binding */
#define VAPRD_ADDRESS(BfVarLock,va) ((uchar*)(BfVarLock) + (va))
#define BFPRD_BOOL(BfVarLock,va)    (( *(uchar*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uchar)ISA_LOCKFLAG_PROD_MASK)
#define BFPRD_SINT(BfVarLock,va)    (( *(uchar*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uchar)ISA_LOCKFLAG_PROD_MASK)
#define BFPRD_DINT(BfVarLock,va)    (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)ISA_LOCKFLAG_PROD_MASK_32)
#define BFPRD_REAL(BfVarLock,va)    (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)ISA_LOCKFLAG_PROD_MASK_32)
#define BFPRD_TIME(BfVarLock,va)    (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)ISA_LOCKFLAG_PROD_MASK_32)
#define BFPRD_STRING(BfVarLock,va)  (( *(uchar*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uchar)ISA_LOCKFLAG_PROD_MASK)
#define BFPRD_INT(BfVarLock,va)     (( *(uint16*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint16)ISA_LOCKFLAG_PROD_MASK_16)
#define BFPRD_USINT(BfVarLock,va)   (( *(uchar*)  (VALCK_ADDRESS ((BfVarLock),(va)))) & (uchar)ISA_LOCKFLAG_PROD_MASK)
#define BFPRD_UINT(BfVarLock,va)    (( *(uint16*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint16)ISA_LOCKFLAG_PROD_MASK_16)
#define BFPRD_UDINT(BfVarLock,va)   (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)ISA_LOCKFLAG_PROD_MASK_32)
#define BFPRD_DATE(BfVarLock,va)    (( *(date*)   (VALCK_ADDRESS ((BfVarLock),(va)))) & (date)ISA_LOCKFLAG_PROD_MASK_32)
#ifdef ITGTDEF_INT64
   #define BFPRD_LINT(BfVarLock,va)    (( *(uint64*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint64)ISA_LOCKFLAG_PROD_MASK_64)
   #define BFPRD_ULINT(BfVarLock,va)   (( *(uint64*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint64)ISA_LOCKFLAG_PROD_MASK_64)
   #define BFPRD_LREAL(BfVarLock,va)   (( *(uint64*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint64)ISA_LOCKFLAG_PROD_MASK_64)
#else  /* ITGTDEF_INT64 */
   #define BFPRD_LREAL(BfVarLock,va)   (  (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va)))) & (uint32)ISA_LOCKFLAG_PROD_MASK_32) && \
                                          (( *(uint32*) (VALCK_ADDRESS ((BfVarLock),(va + sizeof(uint32))))) & (uint32)ISA_LOCKFLAG_PROD_MASK_32) )
#endif /* ITGTDEF_INT64 */

/* This is a bit in the VA that indicates an access in the binding refreshed space instead of the data space */
#define ISA_IXL_ACCESS_REFRESH_DATA 0x80000000UL
#endif

/* Assignation with conditional test when define set */
#ifndef ITGTDEF_VARLOCK
/*#define ISA_DO_ASSGNCHK(a,b,c) ((a) = (b))*/
#define ISA_DO_ASSGNCHK_REFRESH(a,b,c) 
#else
/*#define ISA_DO_ASSGNCHK(a,b,c) { if( !(c) ) {(a) = (b);} }*/

/* This new macro is used to update the binding refreshed variables */
/* if the value is locked and the LSB is not set to indicate a consumer */
/* a is the source, b is the destination, c is the consumer boolean value */
#define ISA_DO_ASSGNCHK_REFRESH(a,b,c) { if( !(c) ) {(a) = (b);} }
#endif

/*
 * Memory spaces 
 */
#define ISA_SPC_RESCODE    0x01    /* Resource Code */
#define ISA_SPC_RESDATA    0x02    /* Resource Data */
#define ISA_SPC_RESCONF    0x03    /* Resource Configuration */
#define ISA_SPC_RESLINK    0x04    /* Resource Blocks Links */
/*#define ISA_SPC_RESEZS     0x05  */ /* Resource Embedded ziped source */
/*#define ISA_SPC_RESSYM     0x06  */ /* Resource Symbols */
/*#define ISA_SPC_RESUDAT    0x07  */ /* Resource User Data */
#define ISA_SPC_SRV        0x08    /* Server module */
#define ISA_SPC_ISXLDRV    0x09    /* IXL-ISXL Drv Registry */
#define ISA_SPC_ISXLCNX    0x0A    /* IXL-ISXL Connection management */
#define ISA_SPC_KVBHSDDTA  0x0B    /* KVB-HSD Bound Data */
#define ISA_SPC_KVBHSDINF  0x0C    /* KVB-HSD Binding Info */
#define ISA_SPC_IXDNWCONF  0x0D    /* IXD Network Configuration */
#define ISA_SPC_IXDRECVMNG 0x0E    /* IXD Data Reception Management */
#define ISA_SPC_NWLMISINFO 0x0F    /* Network drivers miscellaneous info */
#define ISA_SPC_ETCPNCRB   0x10    /* ETCP Non Converted Recep Buf(primary) */
#define ISA_SPC_KVBETCPIVS 0x11    /* KVB-ETCP Imported Variables Space */
                                   /* (recep buf(secondary) & struct mngmt) */
#define ISA_SPC_KVBETCPEVS 0x12    /* KVB-ETCP Exported Variables Space */
                                   /* (emission buf & struct mngmt) */
#define ISA_SPC_CMGINFO    0x13    /* Configuration manager data */
#define ISA_SPC_RESSYMBIN  0x14    /* Resource symbols in binary format */
#define ISA_SPC_RESMDF     0x15    /* Resource delta(s) for on line modif */
#define ISA_SPC_ISXSDRV    0x16    /* IXS-ISXS Drv Registry */
#define ISA_SPC_ISXSCNX    0x17    /* IXS-ISXS Connection management */
#define ISA_SPC_MIBUSR     0x18    /* MIB-IXL client user space */
#define ISA_SPC_HDTSMM     0x19    /* DS memory management (space implem) */
#define ISA_SPC_RESVARLOCK 0x1A    /* Resource lock flags of variables */
#define ISA_SPC_HOTRESTART 0x1B    /* Hot restart backup space */
#define ISA_SPC_SFCFBL     0x1C    /* SFC function block space */
#define ISA_SPC_WNGSH      0x1D    /* Warning share module */
#define ISA_SPC_RESVARREFRESH 0x1E /* Same as resource data but only updated by consumer bindings or when variable is locked */
#define ISA_SPC_BINDDATAX  0x1F    /* New data space used to store binding data instead of using kernel private data (binding online change) */
#define ISA_SPC_BINDDATAY  0x20    /* New data space used to store binding data instead of using kernel private data (binding online change) */
#ifdef ITGTDEF_ENH_ONLINE_CHANGE /* RFS8262 */
#define ISA_SPC_RETAIN_XA     0x21 /* Retain var. temporary space A (set X) */
#define ISA_SPC_RETAIN_XB     0x22 /* Retain var. temporary space B (set X) */
#else
#define ISA_SPC_RETAIN_A   0x21    /* Retain var. temporary space A */
#define ISA_SPC_RETAIN_B   0x22    /* Retain var. temporary space B */
#endif
#define ISA_SPC_RESSYMBIN_DTA  0x23 /* Resource symbols in binary format used by DTA_SRV (RFS 3314) */
#define ISA_SPC_IPLTABLE       0x24 /* IPL Function table. Used for Binary searche of IPL Functions */
#define ISA_SPC_COMINFO        0x25 /* Communication manager data */
#define ISA_SPC_ECAT_INSHMEM   0x26 /* Space created for ethercat inputs */
#define ISA_SPC_ECAT_OUTSHMEM  0x27 /* Space created for ethercat outputs */
#define ISA_SPC_ECAT_STATSHMEM 0x28 /* Space created for ethercat status */
#define ISA_SPC_RETAIN_YA      0x29 /* Retain var. temporary space A (set Y) RFS8262 */
#define ISA_SPC_RETAIN_YB      0x30 /* Retain var. temporary space B (set Y) RFS8262 */
#define ISA_SPC_SRV61850       0x31 /* Server 61850 entities managed by the IEC61850 server */
#if defined(ITGTDEF_RT_OPTIMIZE_CODE) && (defined(ISA_TMM_L) || defined (ITGTDEF_OPT_CODE_MED_AS_LRG))
#define ISA_SPC_RESMDFOPT     0x32 /* Space for optimized delta(s) for on line modif */
#endif /* defined(ITGTDEF_RT_OPTIMIZE_CODE) && (defined(ISA_TMM_L) || defined (ITGTDEF_OPT_CODE_MED_AS_LRG)) */
#define ISA_SPC_OPTPOU        0x33 /* Optimized Code space */
#define ISA_SPC_ISACOM_DRV    0x34 /* Space for IsaCom drivers */
#define ISA_MAXSPCNUM         0x35 /* Maximum space number */

#define ISA_SPC_RESCODE_SAVE  0x00000001UL
#define ISA_SPC_RESMDF_SAVE   0x00000002UL
#define ISA_SPC_RESSYM_SAVE   0x00000004UL
/*#define ISA_SPC_RESEZS_SAVE   0x00000008UL  */
/*#define ISA_SPC_RESUDAT_SAVE  0x00000010UL  */
#define ISA_SPC_RESALLSAVE    (ISA_SPC_RESCODE_SAVE | ISA_SPC_RESMDF_SAVE)

/*
 * Data in sequential access: DSA
 */
#define ISA_DSA_RESSYM      0x01    /* Resource ascii Symbols */
#define ISA_DSA_RESUDAT     0x02    /* Resource User Data */
#define ISA_DSA_RESEZS      0x03    /* Resource Embedded ziped source */
#define ISA_DSA_RESSYM_PREP 0x04    /* Used to cleanup before dload of symtable in on-line download (no DSA created) */

/*
 * Semaphores 
 */
/* Binary semaphore state */
#define ISA_BSEM_BUSY        0x00  /* Already taken, no more available */
#define ISA_BSEM_FREE        0x01  /* Ready to be taken */

/* Semaphore Numbers */
#define ISA_MSEM_KVBHSD         0x01 /* KVB-HSD DTA/INF spc access */
#define ISA_MSEM_KVBETCPIVS     0x02 /* KVB-ETCP Imported vars spc access */
#define ISA_MSEM_KVBETCPEVS     0x03 /* KVB-ETCP Exported vars spc access */
#define ISA_BSEM_TSKSTARTSYNC   0x04 /* Synchronization of task launching */
#define ISA_MSEM_WNGSH          0x05 /* Warning share module */
#define ISA_MSEM_IXLAPI         0x06 /* IXL API Semaphore */
#define ISA_MSEM_LOCK_CPU       0x07 /* Lock the CPU for multi-thread access to global data */
#define ISA_BSEM_ECAT_INSHMEM   0x08 /* Ethercat input shared memory access */
#define ISA_BSEM_ECAT_OUTSHMEM  0x09 /* Ethercat output shared memory access */
#define ISA_BSEM_ECAT_STATSHMEM 0x0A /* Ethercat status shared memory access */
#define ISA_BSEM_CO             0x0B /* CANopen stack synchronization     */
#define ISA_MSEM_SRV61850       0x0C /* Access to SRV61850 table */
#define ISA_BSEM_MBSER_DUPD     0x0D /* Modbus Serial - Data update */
#define ISA_BSEM_MBTCP_DUPD     0x0E /* Modbus TCP - Data update */
#define ISA_BSEM_MBSLAVE_DUPD   0x0F /* Modbus Slave - Data update */
#ifndef ISA_MAXSEMNUM                /* Could be defined in dsys0def.h */
#define ISA_MAXSEMNUM           0x20 /* Maximum semaphore number */
#endif
/*
 * Message queues
 */
/* priority of message in msgQ*/
#define ISA_MSG_PRINORMAL    0     /* Insert at the end of the queue */
#define ISA_MSG_PRIURGENT    1     /* Insert at the tail of the queue */

/* Message queue numbers */
#define ISA_MSGQ_KSRVCNXSTD     0x01  /* Kernel Server Connection */
#define ISA_MSGQ_ISXL_HSDCTSSTD 0x02  /* ISXL HSD Client To Server Standard */
#define ISA_MSGQ_ISXL_HSDSTCSTD 0x03  /* ISXL HSD Server To Client Standard */
#define ISA_MSGQ_ISXL_HSDCTSNTF 0x04  /* ISXL HSD Client To Server Notified */
#define ISA_MSGQ_ISXL_HSDSTCNTF 0x05  /* ISXL HSD Server To Client Notified */
#define ISA_MSGQ_IPCCNXSTD      0x06  /* IPC Connection */
#define ISA_MSGQ_ISXL_IPCCTSSTD 0x07  /* ISXL IPC Client To Server Standard */
#define ISA_MSGQ_ISXL_IPCSTCSTD 0x08  /* ISXL IPC Server To Client Standard */
#define ISA_MSGQ_ISXL_IPCSTCNTF 0x09  /* ISXL IPC Server To Client Notified */
#define ISA_MSGQ_ISXS_IPCCTSSTD 0x0A  /* ISXS IPC Client To Server Standard */
#define ISA_MSGQ_ISXS_IPCSTCSTD 0x0B  /* ISXS IPC Server To Client Standard */
#define ISA_MSGQ_ISXS_IPCSTCNTF 0x0C  /* ISXS IPC Server To Client Notified */
#define ISA_MAXMSGQNUM          0x20  /* Maximum message queue number */


/* specific value for time out */
#define ISA_NOWAIT           0     /* no time out */
#define ISA_WAITFOREVER      0xFFFFFFFFUL /* wait forever */

/* Basic Type Sizeof */
#define ISA_VASIZE    (sizeof (typVa))
#define ISA_IXLVASIZE (sizeof (typIxlVa))
#define ISA_PVSIZE    (sizeof (void*))
#define ISA_LUSIZE    (sizeof (uint32))
#define ISA_HUSIZE    (sizeof (uint16))
#define ISA_CUSIZE    (sizeof (uchar))
#define ISA_LDSIZE    (sizeof (int32))
#define ISA_HDSIZE    (sizeof (int16))
#define ISA_CSIZE     (sizeof (char))
#define ISA_FSIZE     (sizeof (float))
#define ISA_QDSIZE    (sizeof (int64))
#define ISA_QUSIZE    (sizeof (uint64))
#define ISA_RSIZE     (sizeof (real64))

/* Basic Values */
#ifndef _VXW_
#ifndef TRUE
#define TRUE      1
#endif
#ifndef FALSE
#define FALSE     0
#endif
#endif
#define BAD_RET   (-1)
#define GOOD_RET  (0)

#define ISA_MAX_SINT     127
#define ISA_MIN_SINT     (-128)
#define ISA_MAX_DINT     2147483647L
#define ISA_MIN_DINT     (-2147483647L - 1)/* -2147483648L -> compil warning */
#define ISA_MAX_REAL     (3.4E+38)
#define ISA_MIN_REAL     -ISA_MAX_REAL
#define ISA_POS_ZERO_REAL (1.18E-38)
#define ISA_NEG_ZERO_REAL -ISA_POS_ZERO_REAL
#define ISA_MAX_TIME     86399999UL     /* 24h - 1ms in ms unit */
#define ISA_MODULO_TIME  86400000UL     /* 24h in ms unit */
#define ISA_TIME_WRAP    0xFFFFFFFFUL   /* Wrap around value for values returned by dsysTimeRead() */
#define ISA_TIME_DAY_IN_SECONDS 86400UL  /* One day is 60s * 60min * 24h = 86400 seconds */
#define ISA_DATE_INVALID -1
#define ISA_DATE_MAX     0xFFFFFFFFUL   /* Max date representation number in 32 bits */
#define ISA_DATE_MAX_F   4294967295.0   /* Max date representation number in floating points */


#define ISA_MAX_INT8     127
#define ISA_MIN_INT8   (-128)
#define ISA_MAX_UINT8    0xff
#define ISA_MAX_INT16    32767
#define ISA_MIN_INT16  (-32767 - 1)                /* -32768 -> compil warning */
#define ISA_MAX_UINT16   0xffff                    /* 65535 */
#define ISA_MAX_INT32    2147483647L
#define ISA_MIN_INT32  (-2147483647L - 1)       /* -2147483648L -> compil warning */
#define ISA_MAX_UINT32   0xffffffffUL             /* 4294967295 */
#define ISA_MAX_INT64    9223372036854775807LL
#define ISA_MIN_INT64  (-9223372036854775807LL - 1)
#define ISA_MAX_UINT64   0xffffffffffffffffULL     /* 18446744073709551615 */
#define ISA_MAX_DOUBLE   1.7976931348623158e+308
#define ISA_MIN_DOUBLE  -ISA_MAX_DOUBLE

#define ISA_MAX_FLOAT_DIGIT   255

#define ISA_MAX_INT     ISA_MAX_INT16
#define ISA_MIN_INT     ISA_MIN_INT16
#define ISA_MAX_LINT    ISA_MAX_INT64
#define ISA_MIN_LINT    ISA_MIN_INT64
#define ISA_MAX_USINT   ISA_MAX_UINT8
#define ISA_MAX_UINT    ISA_MAX_UINT16
#define ISA_MAX_UDINT   ISA_MAX_UINT32
#define ISA_MAX_ULINT   ISA_MAX_UINT64
#define ISA_MAX_LREAL   ISA_MAX_DOUBLE
#define ISA_MIN_LREAL   ISA_MIN_DOUBLE

/*
 * Basic macros 
 */
#define ISA_GETMAX(x,y)   ( ((x) > (y)) ? (x) : (y) )
#define ISA_GETMIN(x,y)   ( ((x) < (y)) ? (x) : (y) )

/* Functions name case management */ 
#define ISA_ISUPPER(c)    ( ((c) >= 'A') && ((c) <= 'Z') )
#define ISA_ISLOWER(c)    ( ((c) >= 'a') && ((c) <= 'z') )
#define ISA_TOUPPER(c)    ( ISA_ISLOWER(c) ? (((c) - 'a') + 'A') : (c))
#define ISA_TOLOWER(c)    ( ISA_ISUPPER(c) ? (((c) - 'A') + 'a') : (c))

/* Time difference */
#ifndef ITGTDEF_NOMODULOCLK /* Default uses 24h modulo clock */
#define ISA_TIMEDIFF(BeginDate, EndDate) ( ((ISA_MODULO_TIME+(EndDate))-(BeginDate))\
					  % ISA_MODULO_TIME )
#else                       /* Specific to full 32 bit clock (no 24h modulo) */
/*#define ISA_TIMEDIFF(BeginDate, EndDate) ((EndDate) - (BeginDate))*/
/* Manage wrap-around of the time base */
#define ISA_TIMEDIFF(BeginDate, EndDate) ((EndDate) >= (BeginDate) ? (EndDate) - (BeginDate) : (ISA_TIME_WRAP-(BeginDate))+(EndDate)+1)
#endif

#define _ETCP_COMM_OVERHEAD     64

/* IXL com buffer size */
#ifndef ISA_IXL_BUFCTSSZ
/* RFS 4248 #define ISA_IXL_BUFCTSSZ  512   Client to server */
#define ISA_IXL_BUFCTSSZ  16384  /* Client to server */
#endif

#ifndef ISA_IXL_BUFSTCSZ
/* RFS 4248 #define ISA_IXL_BUFSTCSZ  1024  Server to client */
#define ISA_IXL_BUFSTCSZ  32768  /* Server to client */
#endif

/*
 * Number of connections to one configuration
 * The workbench uses two connections for each resource and four connections
 * for the configuration manager.
 * Each remote IXL connection take one more connection.
 */
#ifndef ISA_CNXNBR
#define ISA_CNXNBR                      ((ISA_RESNBR * 2) + 4 + 4)
#endif

#ifdef ITGTDEF_FAILOVER
#define _IXL_SEND_BUF_SIZE      (ISA_GETMIN(ISA_IXL_BUFSTCSZ, ISA_IXL_BUFCTSSZ) - _ETCP_COMM_OVERHEAD)
#define _TCP_BUF_SIZE           65535

/* Possible bitfield values for the ISA_SYSVA_FAILOVER_ERROR_CODE system variable */
#define ISA_SYSVA_FAILOVER_ERROR_CODE_NO_ERROR              0x00000000U
#define ISA_SYSVA_FAILOVER_ERROR_CODE_HEARTBEAT_FAILURE     0x00000001U
#define ISA_SYSVA_FAILOVER_ERROR_CODE_DATALINK_FAILURE      0x00000002U
#define ISA_SYSVA_FAILOVER_ERROR_CODE_SYSTEM_INFO_MISMATCH  0x00000004U
#define ISA_SYSVA_FAILOVER_ERROR_CODE_CAPABILITIES_MISMATCH 0x00000008U
#endif /* ITGTDEF_FAILOVER */

/* Default string size */
#define NSize  15

/* types ******************************************************************/

/* Isagraf target memory model type */
#ifndef ISA_TMM_L

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     IsaSys
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ISA_TMM_M
* \n\b Usage:   Enables the medium memory model target.
*/
/******************************************************************************/
#define ISA_TMM_M
#endif

#ifdef ISA_TMM_M
/* set medium target memory model */ 
typedef uint16 typVa;
#endif

#ifdef ISA_TMM_L
/* set large target memory model */ 
typedef uint32 typVa;
#endif

/* VA from IXL is always uint32 */
typedef uint32 typIxlVa;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Functions call parameter passing */
typedef struct
{
   typVa  Va;         /*!< Variable address */
   uint16 huType;     /*!< Variable type */
   uint16 huReserved; /*!< Reserved */
} strParamVa;

/* Ipl generic function type */
typedef void (*typPFnIplFct)();

/* 'C' function type */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
typedef void (*typPFnUsfCall) (void*, strParamVa*, uint16, strParamVa*, void*);
#else
typedef void (*typPFnUsfCall) (void*, strParamVa*, uint16, strParamVa*);
#endif

/* 'C' function blocks function types */
typedef void (*typPFnFblClassInit) (uint16);
typedef void (*typPFnFblClassExit) (uint16);
typedef void (*typPFnFblInstInit) (void*, strParamVa*);
typedef void (*typPFnFblInstExit) (void*, strParamVa*);
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
typedef void (*typPFnFblCall) (void*, strParamVa*, void*);
#else
typedef void (*typPFnFblCall) (void*, strParamVa*);
#endif

/* 'C' function blocks SubFunc type */
#define ISA_FBLSUB_HOTBKPSTART  1
#define ISA_FBLSUB_HOTBKPSTOP   2
#define ISA_FBLSUB_HOTRSTSTART  3
#define ISA_FBLSUB_HOTRSTSTOP   4
typedef void (*typPFnFblSubFunc) (void*, strParamVa*, uchar);

/* 'C' function blocks function types */
typedef typSTATUS (*typPFnCnvCall) (uchar, void*, void*);

/* Arguments management for startup configuration, Extraction fct */
typedef int32 (*typPFnParamExtract)
   (
   uchar    cuSelector,       /* In: Select the operation to do */
   const char*    psComponent,      /* In: Component's name */
   const char*    psParamName,      /* In: Parameter's name */
   void*    pvBuffer,         /* Out: Buffer where store data */
   uint32   luLnOfBuffer,     /* In: Length of the buffer */
   uint32   luDfValue,        /* In: Default value */
   uchar    cuIndex           /* In: Index of the data to get */
   );

/**************************** DOXYGEN STRUCTURE ***************************/
#ifdef ITGTDEF_ENABLE_IPL_SEARCH
typedef struct 
{
   typPFnIplFct   pfnIplFct;
   char           cFctName[ISA_IPL_MAX_FCT_LEN];
} strIplFct;
#endif

/**************************** DOXYGEN STRUCTURE ***************************/
/* Resouce downloaded code & conf (RDCC) common identification header */
typedef struct
{
   char     psTgtName[16];/*!< Name of target */
   uint32   luRdccVers;   /*!< Version of format of rdcc */
   uint32   luRDtaBaseCrc;/*!< CRC of resource */
   uint32   luModulCrc;   /*!< CRC of module */
   uint32   luParam;      /*!< Extra param (PouNum,...) */
   uint32   luModulSize;  /*!< Size of module */
   uint32   luDataSize;   /*!< Size of useful data */
   uint32   luPCRNameOfs; /*!< Offset to Project/Config/resource name */
   uint32   luModNameOfs; /*!< Offset to Module name */
   uint32   luDataOfs;    /*!< Offset to useful data */
   uint32   luModulCmpDate; /*!< Compilation date of module */
   uint32   luModulCmpVers; /*!< Compilation version of module */
   uint32   luModulUsVers;  /*!< User specified version number */
} strRdccModulId;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Greenwich Meridian Time */
typedef struct
{
   uchar          cuMonthDay;    /*!< Day of the month */
   uchar          cuMonth;       /*!< Month */
   uint16         huYear;        /*!< Year */
   uchar          cuHour;        /*!< Hour */
   uchar          cuMinute;      /*!< Minute */
   uchar          cuSecond;      /*!< Second */
   uchar          cuWeekDay;     /*!< Day of the week */
} strSysGmt;

/**************************** DOXYGEN STRUCTURE ***************************/
/* RTC UTC time */
typedef struct
{
   int32          lSec;          /*!< Seconds */
   int16          hMsec;         /*!< Milliseconds */
} strSysRtc;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Header of share error modul*/
typedef struct _s_SysWngShHdr
{
   uint32 luWngPeriod;           /*!< Warning period */
   uint32 luMaxItemNbr;          /*!< Max number of items */
   int32  ldWriteItem;           /*!< Index of the item to be write */
   int32  ldReadItem;            /*!< Index of the item to be read */
} strSysWngShHdr;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Structure containing the warning description */
typedef struct _s_SysWngShItem
{
   int32     ldError;            /*!< Error number */
   uint32    luArg;              /*!< Argument of the error */
   uint16    huTaskId;           /*!< Task identifier */
   strSysGmt TimeStamp;          /*!< Time stamp of the error */
   uint32    luTime;             /*!< Time of the error */
   char      tcCompName[12];     /*!< Component name */
} strSysWngShItem;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uchar cuIsStarting;           /*!< Flag to determine is a thead is currently starting */
   uchar cuIsRunning;            /*!< Flag to determine is a thead is currently running */
} strThrParams;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   char tcDownloadIP[16];                    /*!< Usual ETCP IP parameter for download/debug */

   /* All parameters below are extended from the usual ETCP */

   char tcFailoverPrimaryIP[16];             /*!< Failover primary IP */
   char tcFailoverSecondaryIP[16];           /*!< Failover secondary IP */

   char tcFailoverDatalinkPrimaryIP[16];     /*!< IP address to use for the data link */
   char tcFailoverDatalinkSecondaryIP[16];   /*!< IP address to use for the data link */

   uchar cuFailoverIsEnabled;                /*!< Bool flag to activate (or not) the failover */

   uint32 luFailoverHeartbeatTimeoutMs;      /*!< Heartbeat timeout of the failover */
   uint32 luFailoverHeartbeatDeactivationTimeMs;/*!< Heartbeat deactivation time when heartbeat link is bad */
#ifdef ITGTDEF_FAILOVER_SERIAL_HEARTBEAT
   char tcFailoverHeartbeatPort[16];         /*!< Serial port: COM1, COM2 etc ... */
   uint32 luFailoverHeartbeatBaudRate;       /*!< Port speed: 1200, 2400, 9600 etc ... */
   char cFailoverHeartbeatParity;            /*!< Parity: N, E, O */
   uint16 huFailoverHeartbeatStopBits;       /*!< 1, 2 */
   char tcFailoverHeartbeatFlowControl[16];  /*!< ON, OFF */
#endif
} strEtcpExtendedOem;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Information on kernel task */
typedef struct _s_CmgTskKer
{
   uint16         huTskNum;      /*!< Task number */
   typTSK_ID      TskId;         /*!< System task information */
   struct _s_CmgTskKer* pNext;   /*!< Naxt task in the list */
}strCmgTskKer;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Information on miscellaneous task */
typedef struct _s_CmgTskMis
{
   uint16         huTskNum;      /*!< Task number */
   typTSK_ID      TskId;         /*!< System task information */
   struct _s_CmgTskMis* pNext;   /*!< Next task in the list */
}strCmgTskMis;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Header of configuration manager space */
typedef struct
{
#ifdef ITGTDEF_FAILOVER
   uchar             cuFailoverIsActiveKernel;     /*!< TRUE if the kernel is ACTIVE in a FAILOVER system */
   uchar             cuFailoverIsPrimaryKernel;    /*!< TRUE if this is the primary kernel of a Failover system */
   uchar             cuFailoverTwoActivesDetected; /*!< TRUE if the active kernel detected another active kernel through the data link of a Failover system */
   uint32            luLastHeartbeatSyncTimeMs;    /*!< Last standby heartbeat sync time for statistics */
   strEtcpExtendedOem  EtcpExtendedOem;              /*!< Communication parameters */
#endif
   uchar          cuSimul;       /*!< TRUE if simulation */
   uchar          cuDebug;       /*!< TRUE if debug */

   /* Start mode */
   uint16         huStgMode;     /*!< Starting mode */

   /* Kernel task */
   uint16         huTskKerNbr;   /*!< Max nbr of kernel tasks on one config */
   strCmgTskKer*  pTskKerRun;    /*!< List of running kernel task */
   strCmgTskKer*  pTskKerFree;   /*!< List of free place for new kernel task */

   /* Miscellaneous task */
   uint16         huTskMisNbr;   /*!< Max nbr of other tasks on one config */
   strCmgTskMis*  pTskMisRun;    /*!< List of running miscellaneous task */
   strCmgTskMis*  pTskMisFree;   /*!< List of free place for new other task */

   /* Array to store number */
   uint16         huArraySize;   /*!< Maximum number that can be stored */
   uint16*        phuArrayNum;   /*!< Array to store number */

   /* Buffer */
   uchar*         pcuBuffer;     /*!< Buffer */
   uint32         luBufferLn;    /*!< Buffer length */

   /* IEC 61850 server control */
#ifdef ITGTDEF_IEC61850_SRV
   uchar          bSrv61850Enable;/*!< SRV61850 enable flag */
#endif
} strCmgHeader;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uchar    cuCancelCycle;       /*!< Flag to cancel the loop execution */
   typVa    VaRetSub;            /*!< Returned VA */
   strParamVa TbParamVa[ISA_FCALL_MAXPARAM]; /*!< Arrays of parameters */
#ifndef ITGTDEF_SEGMENT
   void*    BfData;              /*!< pointer on Kernel Resource Data KRD */
#else
   void**   BfData;              /*!< pointer on Kernel Resource Data KRD */
#endif
#ifdef ITGTDEF_VARLOCK
   void*    BfVarLock;           /*!< Pointer on lock flags of resource variables */
   void*    BfVarRefresh;        /*!< Pointer on kernel refreshed data when variable is locked */
#endif
#ifdef ITGTDEF_CHECK_CALL_STACK
   uint32   luCallStackDepth;    /*!< Calling stack counter */
#endif
#ifdef ITGTDEF_CHECK_LOOP
   uint32   luJumpCount;         /*!< Counter to detect infinite loop */
#endif
#ifdef ITGTDEF_DBG
   typVa    FblInstPushed;       /*!< Fbl instance VA for Push/Pop */ /*RFS8537*/
#endif
#ifdef ITGTDEF_CHECK_LOOP
   uint32   luLastMilliTime;     /*!< Timestamp of the beginning of the cycle */ /*RFS8469*/
#endif
} strCallContext; /*RFS8500*/

/* data *******************************************************************/

/* exported services from module          *********************************/

/* exported services from module          *********************************/
  
/* include ****************************************************************/

#endif   /* nested Headers management */
/* eof ********************************************************************/


