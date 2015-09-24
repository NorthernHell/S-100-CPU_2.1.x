/**************************************************************************
File:               dsys0def.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      13-November-1998
***************************************************************************
Attached documents:

***************************************************************************
Description:        System definitions for LINUX:
                       - Large memory model.

***************************************************************************
Modifications: (who / date / description)
---4.02 Released---
JFO/28-Oct-1999/
   BUG 0557: Replaced dsysMemCpy by dsysMemMove for SMP_MSGPROC_MOVBLK.
EDS/01-Dec-1999/
   Now memory model must be explicitly defined.
EDS/06-Dec-1999/
   Detailed how to set ISA_LOOP_SLEEP and value changed from 11 to 20ms

---4.03 Released---
JFO/25-Jul-2000/
   Defined ITGTDEF_NOMODULOCLK, by default system clock is not modulo 24h
EDS/27-Jul-2000/
   Changed default value of ISA_ER_BASE from 0x00000001UL to 0xAAAA0000UL

---4.12 Released---
VMO/12-June-2002/ SFC function block
   Defined ITGTDEF_SFCFBL.

---4.13 Released---
COL/22-Nov-2001/ Error report.
   Defined ITGTDEF_WARNING and added error identifier structure.
VMO/26-Mar-2002/ IOs online modification
   Defined ITGTDEF_IOCHANOEM, channel's OEM parameters
VMO/12-June-2002/ SFC function block
   Defined ITGTDEF_SFCFBL.
FG/20-Aug-2002/
   Added typPRIO_ID and moved typedefs from dcmg0def.h

---5.00 Released---
OL/02-Feb-2005/ New data type
   Add TIC code for INT, LINT, USINT, USINT, UDINT, ULINT, LREAL and DATE.
OL/15-Mar-2005/ New data type
   WIN32-TGT_L target creation from NT-TARGET_L. Modify ISA_ALIGN=8.

---5.01 Released---
FT/24-Feb-2006/ RFS-5192
   Macro COPYQ had a bad character when endian type was MOTOROLA.

---5.22 Released---
FT/18-Dec-2008/ RFS-6874
   Macro SMP_HSD_COPYQ for 64 bits copy.

EN/16-Apr-2009/ RFS-7549
   Macro ITGTDEF_OPTIMIZED_TIC
EN/21-Apr-2009/ RFS-7569
   Macro ITGTDEF_TIC_OUTPUT

***************************************************************************/
#ifndef _DSYS0DEF_H  /* nested Headers management */
#define _DSYS0DEF_H

/* include here header required
 * for subsequent type in this file
 */
#ifndef __WATCOMC__

#include <ace/ACE.h>
#include <ace/OS.h>
#include <ace/Mem_Map.h>
#include <ace/SString.h>
#include <ace/Process.h>
#include <ace/Process_Semaphore.h>
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_fcntl.h"
#include "ace/OS_NS_stdlib.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_time.h"
#include "ace/OS_NS_sys_wait.h"
#include "ace/OS_NS_isa.h"
#include "ace/OS_NS_sys_stat.h"
#include "ace/OS_NS_time.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/OS_NS_sys_socket.h"
//#include "ace/OS.h"

/* FIORD Copyright */
#define FIORDCOPY "(C) Copyright FIORD Co., Ltd., 2006"


/* Maximum size of project's path */
#define ISA_PRJPATH_SIZE  260

#define NO_SV_SEM

#if !defined ACE_WIN32

	#define WINCEDRVDLL
	
    #if defined ACE_LNX

		#define DEVSHM 		"/dev/shm/"
		#ifdef NO_SV_SEM
		typedef ACE_Process_Semaphore Process_Semaphore;
		#else
		typedef ACE_SV_Semaphore_Complex Process_Semaphore;
		#endif

		#define NO_SEM_MUTEX	1
		#define SYS_DELAY_MLS	20
		#define SYS_HR_TIME		1
    #endif
    #if defined ACE_QNX6
		#define DEVSHM 		"/dev/shmem/"
		typedef ACE_Process_Semaphore Process_Semaphore;
		#define	NO_SEM_MUTEX
		#define NO_SV_SEM	1
		#define SYS_DELAY_MLS	20
		#define SYS_HR_TIME		1
    #endif

    #if defined ACE_QNX4
		#define DEVSHM 		"/"
		typedef ACE_Process_Semaphore Process_Semaphore;
		#define	NO_SEM_MUTEX
		#define NO_SV_SEM	1
		#define SYS_DELAY_MLS	20
		#define SYS_HR_TIME		1
    #endif

    #if defined ACE_NETBSD || ACE_FREEBSD
// you must start mount_mem_nbsd
		#define DEVSHM 		"/temp/"
		typedef ACE_SV_Semaphore_Complex Process_Semaphore;
		#define NO_SEM_MUTEX	1
		#undef  NO_SV_SEM
		#define SYS_DELAY_MLS	20
		#define IPCDELAY	100
		#define SYS_HR_TIME		1
    #endif
    #if defined ACE_SOLARIS
// you must start mount_mem_sol
		#define DEVSHM 		"/temp/"
		typedef ACE_SV_Semaphore_Complex Process_Semaphore;
		#define NO_SEM_MUTEX	1
		#undef  NO_SV_SEM
		#define SYS_DELAY_MLS	20
		#define SYS_HR_TIME		1
    #endif

#define ISAVMEXENAME    "IsaVM"
#define ETCPEXENAME     "ETCP"
#define RSIEXENAME      "IsaRSI"
#define SOCKET		ACE_HANDLE

#else // ACE_WIN32

typedef ACE_Process_Semaphore Process_Semaphore;
#define NO_RANDOM	1

#if !defined WINCE
	
	#define WINCEDRVDLL
	
	#define NO_SEM_MUTEX
	#define SYS_HR_TIME		1000
	#if defined  __BORLANDC__ && defined __TURBOC__ // TurboExplorer
		#define NOT_C99_COMPILER  1		// Borland bad compiler
	#endif

#else                                   // WINCE
	#undef NO_SEM_MUTEX
	#define IPCDELAY	100
	#define SIGTERM 9
	#define SYS_HR_TIME		1
	#define NOT_C99_COMPILER  1		// Visual bad compiler
#endif
#define NO_SV_SEM	1
#define HAS_ERRCODE 	1
#define SYS_DELAY_MLS	20
extern char  _tcISA_SYS_TMPPATH[ISA_PRJPATH_SIZE];       // windows temp directory
#define DEVSHM 		_tcISA_SYS_TMPPATH
#define ISAVMEXENAME    "IsaVM.exe"
#define ETCPEXENAME     "ETCP.exe"
#define RSIEXENAME      "IsaRSI.exe"

#endif

#define ACE_BAD_ADDR	(void *)0xffffffff

#if (!(defined ACE_WIN32) && (!defined WINCE))
typedef int 		ACE_PID_T;
#else
typedef ACE_Process* ACE_PID_T;
typedef PROCESS_INFORMATION PROCINFO;
#endif

typedef time_t 		ACE_TIME_T;

#else //WATCOMC

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
//#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>

#endif /* The END of __WATCOMC__ */

/* Basic Types */
typedef char            char_t;
typedef unsigned char   uchar;
typedef short           int16;
typedef unsigned short  uint16;
#if defined(__LP64__) || defined(_LP64)
typedef int             int32;
typedef unsigned int    uint32;
#else
typedef long            int32;
typedef unsigned long   uint32;
#endif /* defined(__LP64__) || defined(_LP64) */
#ifndef __WATCOMC__
  typedef ACE_TIME_T  date;
#else
  typedef time_t      date;
#endif

typedef int32  typSTATUS;
typedef uint32  typERRNO;
typedef struct timeval  psTime_t;

/******* ISaGRAF definitions *******/
#include <dsys0tgt.h>

/* constants **************************************************************/


/* Invalid Socket Address */
#define ISA_INADDR_NONE INADDR_NONE

/* STD Calls */
#define STDCALL

/* API for threads */
#define ISAAPI

/******* Feature definitions *******/

#define TARGET_OS       "LINUX"

/* RFS6522 BEGIN */
/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_SFCFUNCTIONS
* \n\b Usage:   Enables the call to SFC engine related functions
*/
/******************************************************************************/
#define ITGTDEF_SFCFUNCTIONS
/* RFS6522 END */

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_USF
* \n\b Usage:   Enables 'C' functions feature
*/
/******************************************************************************/
#define ITGTDEF_USF

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_FBLOCK
* \n\b Usage:   Enables 'C' function blocks feature 
*/
/******************************************************************************/
#define ITGTDEF_FBLOCK

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_CNV
* \n\b Usage:   Enables 'C' conversion functions for I/O channels
*/
/******************************************************************************/
#define ITGTDEF_CNV

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_RTIOCNVGAIN
* \n\b Usage:   Enables conversion of I/Os channel, gain, offset
*/
/******************************************************************************/
#define ITGTDEF_RTIOCNVGAIN

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_PRINTF
* \n\b Usage:   Enables display of target information in the standard output 
*               (warnings, errors, etc).
*/
/******************************************************************************/
#define ITGTDEF_PRINTF

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_THREAD
* \n\b Usage:   O.S is multithread, not multi-task
*/
/******************************************************************************/
#undef  ITGTDEF_THREAD

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_NO_GLOBALS
* \n\b Usage:   Do not declare global variables (required on multithread O/S 
*               when task global variables are known by all other tasks) ex. VxWorks
*/
/******************************************************************************/
#undef  ITGTDEF_NO_GLOBALS

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_SEGMENT
* \n\b Usage:   Enables segmented memory for kernel variable data
*/
/******************************************************************************/
#undef  ITGTDEF_SEGMENT

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_SFCEVOCHECK
* \n\b Usage:   Enables SFC behavior checking there is no dynamic overflow
*/
/******************************************************************************/
#define  ITGTDEF_SFCEVOCHECK
/* RFS6522 BEGIN */
#ifndef ITGTDEF_SFCFUNCTIONS 
#ifdef ITGTDEF_SFCEVOCHECK
#undef  ITGTDEF_SFCEVOCHECK
#error "You must define ITGTDEF_SFCFUNCTIONS in dsys0def.h before using ITGTDEF_SFCEVOCHECK"
#endif
#endif
/* RFS6522 END */
/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_USEREGISTER
* \n\b Usage:   Use "register" keyword to enhance performances
*/
/******************************************************************************/
#define ITGTDEF_USEREGISTER

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_IXLSYM
* \n\b Usage:   Enables symbols management with IXL API
*/
/******************************************************************************/
#define ITGTDEF_IXLSYM

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_NOMODULOCLK
* \n\b Usage:   Enables clock not modulo 24 hours. The macro is defined if the 
*               system clock, you are using for time management, is not reset 
*               every 24 hours. In the opposite, if the clock is reset every 24 
*               hours, the macro is undefined.
*/
/******************************************************************************/
#define ITGTDEF_NOMODULOCLK

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_SFCFBL
* \n\b Usage:   Enables SFC Function block features.
*/
/******************************************************************************/
#define ITGTDEF_SFCFBL
/* RFS6522 BEGIN */
#ifndef ITGTDEF_SFCFUNCTIONS
#ifdef ITGTDEF_SFCFBL
#error "You must define ITGTDEF_SFCFUNCTIONS in dsys0def.h before using ITGTDEF_SFCFBL "
#undef ITGTDEF_SFCFBL
#endif
#endif
/* RFS6522 END */

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_WARNING
* \n\b Usage:   Enables warning management
*/
/******************************************************************************/
#define ITGTDEF_WARNING

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_DBG
* \n\b Usage:   Enables step by step debugging
*/
/******************************************************************************/
#define ITGTDEF_DBG

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_KERSYM
* \n\b Usage:   Enables the Kernel symbol management (used with hot restart)
*/
/******************************************************************************/
#undef ITGTDEF_KERSYM

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_FBLOCK_SUBFUNC
* \n\b Usage:   On Hot Restart (Realize and backup functions), when 
*               ITGTGEF_FBLOCK_SUBFUNC is defined, C function block can be 
*               called before and after the command with ISA_FBLSUB_HOTBKPSTART 
*               and ISA_FBLSUB_HOTBKPSTOP parameter values passed to cuSubFunc 
*               parameter of FblSubFunc function.
*/
/******************************************************************************/
#define ITGTDEF_FBLOCK_SUBFUNC

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_NOSFC
* \n\b Usage:   Disable the use of SFC breakpoints
*/
/******************************************************************************/
#undef  ITGTDEF_NOSFC
/* RFS6522 BEGIN */
#ifndef ITGTDEF_SFCFUNCTIONS
#ifndef ITGTDEF_NOSFC
#error "You must define ITGTDEF_SFCFUNCTIONS in dsys0def.h before undefining ITGTDEF_NOSFC"
#undef ITGTDEF_NOSFC
#endif
#endif
/* RFS6522 END */

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_VARLOCK
* \n\b Usage:   Enables the possibility to lock variable with a user defined external tool
*/
/******************************************************************************/
#define ITGTDEF_VARLOCK

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_NOKERMAIN
* \n\b Usage:   Removes the main entry for the virtual machine. The divm0mai.c 
*               file must be included in the virtual machine project.
*/
/******************************************************************************/
#ifdef ITGTDEF_MONOTASK
#undef  ITGTDEF_NOKERMAIN
#else
#define ITGTDEF_NOKERMAIN
#endif

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_BINDIMPROVE
* \n\b Usage:   Enables target support for multiple binding producer groups.
*/
/******************************************************************************/
#define ITGTDEF_BINDIMPROVE

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_BINDIMPROVE2
* \n\b Usage:   Enables target support for multiple binding producer groups.
*/
/******************************************************************************/
#define ITGTDEF_BINDIMPROVE2

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_UINT64_TO_DOUBLE_CUSTOM
* \n\b Usage:   Enables unsigned int64 to double (not implemented by compiler).
*/
/******************************************************************************/
#define ITGTDEF_UINT64_TO_DOUBLE_CUSTOM

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_HSD
* \n\b Usage:   The Mono task can include or not the code of the HSD network driver
*/
/******************************************************************************/
#define ITGTDEF_HSD

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_IXLMIB
* \n\b Usage:   Internal (not public) to NT target
*/
/******************************************************************************/
#undef ITGTDEF_IXLMIB

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_TIC_OUTPUT
* \n\b Usage:   Enables target support for TIC Code from the family TIC_OUTPUT
*/
/******************************************************************************/
#undef ITGTDEF_TIC_OUTPUT

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_ENABLE_IPL_SEARCH
* \n\b Usage:   Enables fast access to User Function, Function Blocks, and
*               Conversion functions.
*/
/******************************************************************************/
#define ITGTDEF_ENABLE_IPL_SEARCH

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_ENABLE_IPL_RELEASE
* \n\b Usage:   Enable release of IPL Functions
*/
/******************************************************************************/
#undef ITGTDEF_ENABLE_IPL_RELEASE

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_HARD_REALTIME_CYCLE
* \n\b Usage:   New method to calculate the cycle time to consider the possible 
                clock drift
*/
/******************************************************************************/
#undef ITGTDEF_HARD_REALTIME_CYCLE

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_HOTRESTART
* \n\b Usage:   Enables the Hot restart feature
*/
/******************************************************************************/
#undef ITGTDEF_HOTRESTART

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_INCOHERENCY_CHECK
* \n\b Usage:   Allow to verify target file coherency before to start VMs
*/
/******************************************************************************/
#undef ITGTDEF_INCOHERENCY_CHECK

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_ISACOM
* \n\b Usage:   Support Isacom process
*/
/******************************************************************************/
#undef ITGTDEF_ISACOM

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_CHECK_CALL_STACK
* \n\b Usage:   Perform call stack validation during program execution
*/
/******************************************************************************/
#ifdef ISA_MAXCALLSTACKDEPTH
#if (ISA_MAXCALLSTACKDEPTH > 0)
#define ITGTDEF_CHECK_CALL_STACK
#endif
#endif /* ISA_MAXCALLSTACKDEPTH */

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_CHECK_LOOP
* \n\b Usage:   Check if control loop is stuck into an infinite loop
*/
/******************************************************************************/
#undef ITGTDEF_CHECK_LOOP

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_SOFT_WATCHDOG
* \n\b Usage:   Max time for a cycle
*/
/******************************************************************************/
#define ITGTDEF_SOFT_WATCHDOG    2000

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_ETHERCAT_MASTER
* \n\b Usage:   Support of Ethercat master process
*/
/******************************************************************************/
#undef ITGTDEF_ETHERCAT_MASTER

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_IEC61850_SRV
* \n\b Usage:   Enables IEC61850 implementation
*/
/******************************************************************************/
#undef ITGTDEF_IEC61850_SRV
#undef ITGTDEF_IEC61850_SRV_SCO
#undef ITGTDEF_IEC61850_SRV_TMW

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    DEBUG_SRV61850
* \n\b Usage:   Help debugging the IEC61850 server.
*/
/******************************************************************************/
#ifdef ITGTDEF_IEC61850_SRV
#define DEBUG_SRV61850
#endif

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_SFC_PROG_ACT_GROUPING
* \n\b Usage:   Grouping actions in SFC programs and bug fixes in the SFC engine
*/
/******************************************************************************/
#define ITGTDEF_SFC_PROG_ACT_GROUPING
#if (defined ITGTDEF_SFC_PROG_ACT_GROUPING) && (!defined ITGTDEF_SFCFUNCTIONS)
#error "You must define ITGTDEF_SFCFUNCTIONS in dsys0def.h before defining ITGTDEF_SFC_PROG_ACT_GROUPING"
#endif

/* RFS 8359 begin */
/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_RT_OPTIMIZE_CODE
* \n\b Usage:   Enables the TIC code run-time optimization
*/
/******************************************************************************/
#if !defined(__LP64__) && !defined(_LP64) && !defined(_MSC_VER)
#define ITGTDEF_RT_OPTIMIZE_CODE
#endif

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_OPTIMIZE_USF_FBL_CALL
* \n\b Usage:   Enables the optimization of standard funcs/FBs calling
*/
/******************************************************************************/
#define ITGTDEF_OPTIMIZE_USF_FBL_CALL

/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_OPTIMIZE_USF_FBL
* \n\b Usage:   Optimize standard functions and function blocks execution
*/
/******************************************************************************/
#define ITGTDEF_OPTIMIZE_USF_FBL
/* RFS 8359 end */

/* RFS 8458 begin */
/******************** DOXYGEN COMPILE-TIME CONDITIONAL *************************/
/*! \addtogroup   CompileConditional Compile-time Conditionals
* \addtogroup     TargetFeatures Target Features
* \ingroup        CompileConditional
*******************************************************************************
* \n\b Name:    ITGTDEF_OPT_CODE_MED_AS_LRG
* \n\b Usage:   Enables the TIC code run-time optimization by converting
*               medium model code (uint16) to the large model code (uint32)
*               and patching it
*/
/******************************************************************************/
#undef ITGTDEF_OPT_CODE_MED_AS_LRG
/* RFS 8458 end */

#ifdef ACE_BIG_ENDIAN
    #define MOTOROLA
#else
    #define INTEL
#endif

#ifndef TARGET_NAME
    #ifdef MOTOROLA
    #define TARGET_NAME     "ACE-TARGET_LBIG"
    #else
    #define TARGET_NAME     "ACE-TARGET_L"
    #endif
#endif

#define ISA_TMM_L
/******* Features verifications *******/

#if ((!defined INTEL) && (!defined MOTOROLA)) || \
    ((defined INTEL)  && (defined MOTOROLA) )
#error ("Please define INTEL or MOTOROLA Byte order model")
#endif

#if ((!defined ISA_TMM_M) && (!defined ISA_TMM_L)) || \
    ((defined ISA_TMM_M)  && (defined ISA_TMM_L) )
#error ("Please define Medium or Large memory model")
#endif

#ifdef ITGTDEF_BIGPOUS
#if (defined ISA_TMM_M) || (!defined ISA_TMM_L)
#undef ITGTDEF_BIGPOUS
#error ("Large POUs are only supported on the Large memory model.")
#endif
#endif

#ifdef ITGTDEF_FAILOVER
#undef ITGTDEF_EVAL_TIMER_WITH_CURRENT_TIME
#undef ITGTDEF_INTERRUPT
#undef ITGTDEF_FAILOVER_DEBUG             /* Debug traces of failover mechanism */
#undef ITGTDEF_FAILOVER_FORCE_CPU_RELEASE /* Force the release of the CPU control during failover */
#undef ITGTDEF_FAILOVER_SERIAL_HEARTBEAT  /* undef to use socket port instead of serial port */
#define ITGTDEF_FAILOVER_TCP_DATALINK     /* define to use TCP sockets for data link instead of IXL */
#define ITGTDEF_HOTRESTART                /* Required for failover */  
#define ITGTDEF_KERSYM                    /* Required for failover */
#define ITGTDEF_FAILOVER_WRITE_SYNC       /* Improved IXL write sync between active and standby */
#if (defined ITGTDEF_CURRENT_ISA_DATE)
#undef ITGTDEF_CURRENT_ISA_DATE
#error ("ITGTDEF_CURRENT_ISA_DATE may cause the failover to continuously synchronize at each cycle because of different time base between systems")
#endif
#ifdef ITGTDEF_NET_INSTANCES
#error ("Network instances feature (ITGTDEF_NET_INSTANCES) is not supported on a Failover system")
#endif
#ifdef ITGTDEF_KVB
#define ITGTDEF_FAILOVER_KVB              /* support of HSD and ETCP bindings */
#endif
#endif

#if (!defined ITGTDEF_MODIF) /* RFS8362 */
#undef ITGTDEF_ENH_ONLINE_CHANGE
#endif

#if defined(ITGTDEF_OPT_CODE_MED_AS_LRG) && !defined(ISA_TMM_M)
#error ("Run-time of TIC code optimization (ITGTDEF_OPT_CODE_MED_AS_LRG) is only supported on the Medium memory model (ISA_TMM_M).")
#endif
#if defined(ITGTDEF_OPT_CODE_MED_AS_LRG) && !defined(ITGTDEF_RT_OPTIMIZE_CODE)
#error ("ITGTDEF_RT_OPTIMIZE_CODE needs to be defined when ITGTDEF_OPT_CODE_MED_AS_LRG is defined");
#endif
#if defined(ITGTDEF_RT_OPTIMIZE_CODE) && defined(ITGTDEF_ABORT_CURRENT_CYCLE)
#error ("Defining ITGTDEF_ABORT_CURRENT_CYCLE with ITGTDEF_RT_OPTIMIZE_CODE needs special consideration; please properly review its usage.");
#endif

/* RFS8650 begin */
#ifdef ITGTDEF_OPT_CODE_MED_AS_LRG
#error ("Feature ITGTDEF_OPT_CODE_MED_AS_LRG is not yet supported")
#endif
/* RFS8650 end */

#ifdef ITGTDEF_IEC61850_SRV
#define ISA_RESTART_IEC61850        0x2255
#define ISA_STOP_IEC61850           0x2256
#endif

/***************************************************************************
  DEBUG
****************************************************************************/
/*#define ITGT_DBG*/
#define ITGT_TRACE_SYSSEM        0x00000001
#define ITGT_TRACE_SYSSPC        0x00000002
#define ITGT_TRACE_SYSMSQ        0x00000004
#define ITGT_TRACE_SYSTIM        0x00000008
#define ITGT_TRACE_SYSTSK        0x00000010
#define ITGT_TRACE_SYSRSI        0x00000020
#define ITGT_TRACE_SYSINI        0x00000040
#define ITGT_TRACE_SYSRTN        0x00000080

#define ITGT_TRACE_SYSSEMCREATE  0x00000100

#define WM_RESTART_TASK        (WM_USER+128)

/******* I/Os TIC Output Reference *******/
#define BOOL_IOREF(va,luOffset)
#define SINT_IOREF(va,luOffset)
#define DINT_IOREF(va,luOffset)
#define REAL_IOREF(va,luOffset)
#define TIME_IOREF(va,luOffset)
#define STRING_IOREF(va,luOffset)
#define INT_IOREF(va,luOffset)
#define LINT_IOREF(va,luOffset)
#define USINT_IOREF(va,luOffset)
#define UINT_IOREF(va,luOffset)
#define UDINT_IOREF(va,luOffset)
#define ULINT_IOREF(va,luOffset)
#define LREAL_IOREF(va,luOffset)
#define DATE_IOREF(va,luOffset)
#define BLOCK_IOREF(va,luOffset)

/******* System definitions *******/
/* System Layer Object types */
#define ISA_SYSOBJ_PATH         1
#define ISA_SYSOBJ_SPC          2
#define ISA_SYSOBJ_SEM          3
#define ISA_SYSOBJ_MSGQ         4
#define ISA_SYSOBJ_DSA          5

/* Unavailable slave numbers (Ored equality tests, note used here) */
#define ISA_SDEF_ISUNAVISLAVENUM(huSlaveNum)  FALSE

/* Default kernel starting mode */
#define ISA_KERSTGMODE_DEFAULT     ISA_STGMODE_AUTORESTORE

/* Default Conf Mnger starting mode */
#define ISA_CMGSTGMODE_DEFAULT     ISA_STGMODE_AUTORESTORE

/* Value of minimum time (ms) to relinquish cpu, usually 1 or 2 tick */
#define ISA_LOOP_SLEEP   1

/* Maximum number of target warnings queued */
#define ISA_SYS_MAXWNG   32

/* Maximum number of available channels for com Fct Blocks */
#define ISA_CFB_MAXCHAN  10

/* Errno Base of bad returned function */
#define ISA_ER_BASE      0x20000000UL

/* Maximum size of project's path */
#define ISA_PRJPATH_SIZE  260

/* Max Lenght of Function name */
#define ISA_IPL_MAX_FCT_LEN       128

/* Maximum size of device name */
#define MAX_DEVICE_NAME_LEN  256

/* Maximum lenght of IP address + 1 */
#define MAX_IP_ADDR_LEN     16

/* Size of name of a syst object (spc,...) */
#define ISA_SYSOBJ_NAMESIZE 12 

/* Definitions of a segment for segmented target */
#ifdef  ITGTDEF_SEGMENT           /* Example of a 16bits segmented system */
#error ("If the following line is ok, remove this line")
#define ISA_SEGMT_MSB     16      /* Most Significant Segment bit */
#define ISA_SEGMT_MSK     0xffff  /* Mask of one segment */
#endif

/* Bytes copy */
#define BT(a,i)     (((uchar*)(void *)(a))[(i)])
#define MOVS(d,s) {BT(d,0)=BT(s,0);BT(d,1)=BT(s,1);}
#define MOVL(d,s) {BT(d,0)=BT(s,0);BT(d,1)=BT(s,1);BT(d,2)=BT(s,2);BT(d,3)=BT(s,3);}
#define MOVQ(d,s) {BT(d,0)=BT(s,0);BT(d,1)=BT(s,1);BT(d,2)=BT(s,2);BT(d,3)=BT(s,3); \
                   BT(d,4)=BT(s,4);BT(d,5)=BT(s,5);BT(d,6)=BT(s,6);BT(d,7)=BT(s,7);}
					
#ifdef INTEL

#define COPYS(d,s) {BT(d,0)=BT(s,1);BT(d,1)=BT(s,0);}
#define COPYL(d,s) {BT(d,0)=BT(s,3);BT(d,1)=BT(s,2);BT(d,2)=BT(s,1);BT(d,3)=BT(s,0);}
#define COPYQ(d,s) {BT(d,0)=BT(s,7);BT(d,1)=BT(s,6);BT(d,2)=BT(s,5);BT(d,3)=BT(s,4); \
                    BT(d,4)=BT(s,3);BT(d,5)=BT(s,2);BT(d,6)=BT(s,1);BT(d,7)=BT(s,0);}
#else
#define COPYS(d,s) {BT(d,0)=BT(s,0);BT(d,1)=BT(s,1);}
#define COPYL(d,s) {BT(d,0)=BT(s,0);BT(d,1)=BT(s,1);BT(d,2)=BT(s,2);BT(d,3)=BT(s,3);}
#define COPYQ(d,s) {BT(d,0)=BT(s,0);BT(d,1)=BT(s,1);BT(d,2)=BT(s,2);BT(d,3)=BT(s,3); \
                    BT(d,4)=BT(s,4);BT(d,5)=BT(s,5);BT(d,6)=BT(s,6);BT(d,7)=BT(s,7);}
#endif

/*
 * Server Host System Driver bytes copy:
 *  Does not go out of a system;
 *  format is system dependent and must respect:
 *    xxx_COPYS     = Size of uint16   (ISA_HUSIZE)
 *    xxx_COPYL     = Size of uint32   (ISA_LUSIZE)
 *    Must respect system byte order format (little or big endian)
 *    Take into acount alignement pbms (if system has no alignment
 *      restriction you can simply make copy through pointer with cast
 */
#if (defined _ARM_) || (defined ARM_LINUX) || (defined MOTOROLA)
#define SMP_HSD_COPYS(d,s)      COPYS((d),(s))
#define SMP_HSD_COPYL(d,s)      COPYL((d),(s))
#define SMP_HSD_COPYQ(d,s)      COPYQ((d),(s)) 
#else
#define SMP_HSD_COPYS(d,s)      (*((uint16*)(d))) = (*((uint16*)(s)))
#define SMP_HSD_COPYL(d,s)      (*((uint32*)(d))) = (*((uint32*)(s)))
#define SMP_HSD_COPYQ(d,s)      (*((uint64*)(d))) = (*((uint64*)(s)))
#endif

/*
 * Server Message processing bytes copy:
 *  Goes out of a config system;
 *  Format is system independent and must respect:
 *    xxx_xxx8  = 1 byte
 *    xxx_xxx16 = 2 bytes
 *    xxx_xxx32 = 4 bytes
 *    xxx_xxx64 = 8 bytes
 *    xxx_xxxS  = Copy String:
 *                Copy of specified number of bytes.
 *                One byte per uchar whatever is the system.
 *                (a loop with xxx_xxx8 is always ok!)
 *                (in such specific case Length<==>NbBytes no conv required)
 *    xxx_xxxBLK= Block copy:
 *                Copy of specified number of bytes.
 *                x byte(s) per uchar according system
 *                (ex: x=4 for some DSP)
 *    No Alignment
 *    Big endian
 *    Buffer size must be expressed in sizeof(uchar)
 *     and is different from buffer nbr of bytes according
 *     the system (ex: Size=1; ByteNbr=4 on some DSP)
 */
#define SMP_MSGPROC_PUT8(pvBuf, luIdx, pcuVal)                          \
   ( ((uchar*)(pvBuf))[(luIdx)] = *(uchar*)(pcuVal) )

#define SMP_MSGPROC_PUT16(pvBuf, luIdx, phuVal)                         \
   COPYS( (&((uchar*)(pvBuf))[(luIdx)]) , (phuVal) )

#define SMP_MSGPROC_PUT32(pvBuf, luIdx, pluVal)                         \
   COPYL( (&((uchar*)(pvBuf))[(luIdx)]) , (pluVal) )

#define SMP_MSGPROC_PUT64(pvBuf, luIdx, pquVal)                         \
   COPYQ( (&((uchar*)(pvBuf))[(luIdx)]) , (pquVal) )

#if (defined ISA_TMM_L) || (!defined ISA_TMM_M)
#define SMP_MSGPROC_PUTVA(pvBuf, luIdx, pquVal)                         \
   COPYL( (&((uchar*)(pvBuf))[(luIdx)]) , (pquVal) )
#else
#define SMP_MSGPROC_PUTVA(pvBuf, luIdx, pquVal)                         \
   COPYS( (&((uchar*)(pvBuf))[(luIdx)]) , (pquVal) )
#endif

#define SMP_MSGPROC_GET8(pvBuf, luIdx, pcuRes)                          \
   ( *(uchar*)(pcuRes) = ((uchar*)(pvBuf))[(luIdx)] )

#define SMP_MSGPROC_GET16(pvBuf, luIdx, phuRes)                         \
   COPYS( (phuRes) , (&((uchar*)(pvBuf))[(luIdx)]) )

#define SMP_MSGPROC_GET32(pvBuf, luIdx, pluRes)                         \
   COPYL( (pluRes) , (&((uchar *)(pvBuf))[(luIdx)]) )

#define SMP_MSGPROC_GET64(pvBuf, luIdx, pquRes)                         \
   COPYQ( (pquRes) , (&((uchar*)(pvBuf))[(luIdx)]) )

#if (defined ISA_TMM_L) || (!defined ISA_TMM_M)
#define SMP_MSGPROC_GETVA(pvBuf, luIdx, pquRes)                         \
   COPYL( (pquRes) , (&((uchar*)(pvBuf))[(luIdx)]) )
#else
#define SMP_MSGPROC_GETVA(pvBuf, luIdx, pquRes)                         \
   COPYS( (pquRes) , (&((uchar*)(pvBuf))[(luIdx)]) )
#endif

#define SMP_MSGPROC_PUTS(pvBuf, luIdx, psStr, luByteNbr)                \
   (dsysMemCpy( &((uchar*)(pvBuf))[(luIdx)],(psStr),(luByteNbr) ))

#define SMP_MSGPROC_GETS(pvBuf, luIdx, psStr, luByteNbr)                \
   (dsysMemCpy( (psStr), &((uchar*)(pvBuf))[(luIdx)],(luByteNbr) ))

#define SMP_MSGPROC_CMPS(pvBuf, luIdx, psStr)                           \
   (dsysStrCmp( &((char*)(pvBuf))[(luIdx)], psStr )) // was char_t

#define SMP_MSGPROC_PUTBLK(pvBuf, luIdx, pvDta, luByteNbr)              \
   (dsysMemCpy( &((uchar*)(pvBuf))[(luIdx)],(pvDta),(luByteNbr) ))

#define SMP_MSGPROC_GETBLK(pvBuf, luIdx, pvDta, luByteNbr)              \
   (dsysMemCpy( (pvDta),&((uchar*)(pvBuf))[(luIdx)],(luByteNbr) ))

#define SMP_MSGPROC_MOVBLK(pvD, luIdxD, pvS, luIdxS, luByteNbr)         \
   (dsysMemMove( &((uchar*)(pvD))[(luIdxD)],&((uchar*)(pvS))[(luIdxS)],     \
                (luByteNbr) ))

#define SMP_MSGPROC_GETBUFSIZE(luIdxNbr)                                \
   ((uint32)(luIdxNbr))

#define SMP_MSGPROC_GETBUFBYTNBR(luSize)                                \
   ((uint32)(luSize))

/* To be used only if no other way */
#define SMP_MSGPROC_GETADD(pvBuf, luIdx)                                \
   ( (void*) (&((uchar*)(pvBuf))[(luIdx)]) )

/* Mirror target status string size */
#define ISA_CMG_MIRROR_STATUS_SIZE 16

/* Thread priorities */
#define ISA_THR_PRIO_INVALID        -1
#define ISA_THR_PRIO_LOW            0
#define ISA_THR_PRIO_NORMAL         1
#define ISA_THR_PRIO_HIGH           2

/* types ******************************************************************/

/* Thread (OS Specific) Types */
typedef ACE_THR_FUNC_RETURN       typTHRRTN;
typedef void*           typTHRPRM;
typedef ACE_hthread_t   typHANDLE;
typedef ACE_thread_t	typTHR_ID;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint32 u[2];
} typ64Bits;

#ifdef ITGTDEF_DOUBLE
   typedef double             real64;
#else
   #ifdef ITGTDEF_INT64
      typedef __int64         real64;
   #else
      typedef typ64Bits       real64;
   #endif
#endif /* ITGTDEF_DOUBLE */

#ifdef ITGTDEF_INT64
   /* native int64 support */
#ifndef __WATCOMC__
	   typedef long long          int64;
	   typedef unsigned long long uint64;
#else
	   typedef __int64            int64;
	   typedef unsigned __int64   uint64;
#endif

#else  /* ITGTDEF_INT64 */
   #ifdef ITGTDEF_DOUBLE
      typedef double          int64;
      typedef double          uint64;
   #else
      typedef typ64Bits       int64;
      typedef typ64Bits       uint64;
   #endif
#endif /* ITGTDEF_INT64 */

/**************************** DOXYGEN STRUCTURE ***************************/
/* Space identifier */
typedef struct
{
   void*    pvAddress;        /* pointer on Map File */
#ifndef __WATCOMC__
   ACE_Mem_Map * dShmId;           /* Identifier of the shared memory */
#endif
} typSPC_ID;

/* Semaphore identifier */
//NOTE: ACE version does not use this?
/*
typedef struct _s_SemHeader
{
   uint32      luMaxNbrSem;         // Number max of semaphore
   uchar       cuShmready;          // Shared memory ready flag
   uchar       cuReserved;
   uint16      huCountLink;         // number of linked task
   uint32      luFirstEntryOffset;  // Offset to the first entry
   int32       ldSemId;             // Semaphore identifier
} strSemHeader;

typedef struct _s_SemEntry
{
   uint16      huOwnerNum;    // Owner number
   uint16      huCount;       // Number of linked task
   uchar       cuSemNum;      // Semaphore Number
   uchar       cuDelFlag;     // Delete flag 
   uint16      huReserved;
   int32       ldSemId;       // Semaphore ID 
} strSemEntry;
*/

/*
union semun 
{
   int val;                    // value for SETVAL
   struct semid_ds *buf;       // buffer for IPC_STAT, IPC_SET
   unsigned short int *array;  // array for GETALL, SETALL
   struct seminfo *__buf;      // buffer for IPC_INFO
};
*/

typedef void* typSEM_ID;
 
/**************************** DOXYGEN STRUCTURE ***************************/
/* Message queue identifier */
typedef struct
{
   typSPC_ID   SpcId;                  /*!< Memory block identifier */
   struct _s_MsgQHeader* pMsgQHeader;  /*!< Address of header of message queue */
   typSEM_ID   SemIdMultiW;            /* Semaphore for writing */
   typSEM_ID   SemIdMultiR;            /* Semaphore for reading */
   typSEM_ID   SemIdRWAccess;          /* Read and write access */
   typSEM_ID   SemIdSpaceAck;          /* Place available */
   typSEM_ID   SemIdDataRdy;           /* Data ready to read */
} typMSG_Q_ID;

/* Data in sequential access (DSA) identifier */
typedef FILE* typDSA_ID;

/* Process identifier */
typedef int typPID;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Error identifier */
typedef struct
{
   uint16    huTaskId;     /*!< Task identifier */
   typSPC_ID SpcId;        /*!< Space identifier */
   typSEM_ID SemId;        /*!< Semaphore identifier */
   struct _s_SysWngShItem*     pFirstItem;     /*!< First item of the space */
   struct _s_SysWngShHdr*      pHeader;        /*!< Header of the space */
}typWNG_ID;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Notification Handler */
typedef struct
{
   int32 ldNtfHdlId;
} typNTFHDL_ID;

typedef void (*typPFN_NTFHDL) (uint32 luSignalCode);
typedef struct
{
   int32 ldNtfSgnId;
} typNTFSGN_ID;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Notification Handler */
typedef typTHRRTN (*typTHREAD_HDL)(typTHRPRM);
#ifdef ITGTDEF_INTERRUPT
#define IRQ_THREAD_FCT_NAME  dsysIrqThread
#define IRQ_THREAD_FCT_PROTO typTHRRTN dsysIrqThread(void* pvParam)
#endif

/* Thread Functions */
typedef typTHRRTN (STDCALL*typPFN_ThrdFnc)(typTHRPRM);
typedef typPFN_ThrdFnc typPfnThrdFnc;

/* Task identifier */
#ifndef __WATCOMC__
	typedef ACE_PID_T typTSK_ID;
#else
	typedef pid_t typTSK_ID;
#endif

/* Priority identifier */
typedef uint32 typPRIO_ID;

#include <ace/TTY_IO.h>

typedef struct
{
   ACE_TTY_IO*      dComDesc;
   uint32   luPauseTimeout;     /* Pause timeout */
} typRSICOM_ID;

//typedef int typSOC_ID;
typedef ACE_HANDLE typSOC_ID;
typedef struct sockaddr_in typSOC_ADD;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typSPC_ID   SpcIdCmg;      /*!< Identifier of memory block for CMG */
   void*       pvCmg;         /*!< Address of memory block for CMG */
} strCmgSys;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typPfnThrdFnc  pfnThrdFnc; /*!< Pointer to Thread Routine */
   void*          pvParam;    /*!< Pointer to the Parameter */
   typHANDLE      hThread;    /*!< Thread Handle */   
   uint32         luStackSize;/*!< Stack Size */
   uint16         huThreadId; /*!< Task identifier (Isagraf use) */
   typTHR_ID      luThreadId; /*!< Task identifier (OS use) */
   uchar          cuSemExit;  /*!< Exit Semaphore */
} typTHR_HDL;

/* Terminate current task in case of fatal error (OS dependant) */
#define END_TASK        exit(0)
#define END_THREAD      {  pthread_detach(pthread_self()); pthread_exit(NULL); }
#ifdef ACE_WIN32
	#define END_THREAD
#endif

/************************** THREAD MANAGEMENT BEGIN ************************/
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint32 luPrio;             /*!< Priority value of the interrupt thread */
} typTHR_PRIO;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   char           szName[9];  /*!< Name of the interrupt thread */
   typTHREAD_HDL  pfnThrdFnc; /*!< Pointer to the function to be executed by the interrupt thread */
   typTHR_PRIO    ThrPrio;    /*!< Priority of the interrupt thread */
   void*          pvParam;    /*!< Pointer to the parameters passed to the interrupt thread */
   uchar*         pbRun;      /*!< Pointer to the RUN variable monitored by the interrupt thread; Set it to FALSE to stop its execution */

   /* Specific to Linux IRQ example */
   typHANDLE      hThread;    /*!< Handle of the interrupt thread (Specific to Linux IRQ example) */
   typTHR_ID	  luThreadId;	
} typINTTHR_HDL;
/************************** THREAD MANAGEMENT END *************************/

/**************************** IRQ MANAGEMENT BEGIN ************************/
#ifdef ITGTDEF_INTERRUPT

#define MAX_NB_INTERRUPTS        4

/* Semaphore used for the user-interrupt implementation in Linux */
#define ISA_BSEM_TSKFIRSTIRQ  0x16  /* First of 32 IRQ semaphores */
#define ISA_BSEM_TSKLASTIRQ   0x35  /* Last of 32 IRQ semaphores */
#define ISA_MAXSEMNUM         0x36  /* Maximum semaphore number */

/* Implement atomic access protection on VA */
#define ISA_LOCK_CPU_INIT        
#define ISA_LOCK_CPU
#define ISA_UNLOCK_CPU
#endif /* ITGTDEF_INTERRUPT */

/******* ISaGRAF definitions *******/
#include <dsys0df2.h>

#ifdef ITGTDEF_INTERRUPT
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16      huIrqNum;      /*!< Number of the interrupt */
   uint32      luVa;          /*!< VA of control variable */
   /* Specific to Linux IRQ example */
   uchar       bRun;          /*!< Run flag to allow stopping the IRQ simulation thread */
   uint16      huPouNum;      /*!< POU number of the interrupt program */
}typIRQ_HDL;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Structure used to pass information */
/* to the trigger thread of user-interrupt threads */
typedef struct
{
   uchar       bRun;          /*!< Run flag to allow stopping the IRQ trigger thread */
   uint16      huSlaveNum;    /*!< Value of the associated resource number; 0 in the case of the IRQ trigger thread */
   void*       pvIrqMng;      /*!< Pointer to the interrupt management table */
}typIRQTRIG_PARAM;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Structure used to pass information */
/* to a thread executing an interrupt program */
typedef struct
{
   uchar       bRun;          /*!< Run status of the IRQ */
   uint16      huSlaveNum;    /*!< Resource number associated to this interrupt */
   uint16      huIrqNum;      /*!< Interrupt identifier */
   uint16      huPouNum;      /*!< POU number associated to this interrupt */
   uint32      luVa;          /*!< Variable address of the control structure associated to this interrupt */

   /* Function to execute the code */
   uint32  (*pfnExec)(
#ifdef ITGTDEF_OPT_CODE_MED_AS_LRG
      ISA_VARINREG uint32* mic,
#else
      ISA_VARINREG typVa* mic,
#endif
      typVa, typVa, uchar, strCallContext*);  /*!< Pointer to the execution function */ /*RFS8500*/

   /* Function to retrieve the code to execute */
#ifdef ITGTDEF_OPT_CODE_MED_AS_LRG
   uint32* (*pfnGetCode)(uint16);   /*!< Pointer to the function to retrieve the POU pointer */
#else
   typVa* (*pfnGetCode)(uint16);    /*!< Pointer to the function to retrieve the POU pointer */
#endif

#ifndef ITGTDEF_SEGMENT
   void*       pBfData;       /*!< Pointer to the data space associated to the interrupt */
#else
   void**      pBfData;       /*!< Pointer to the data space associated to the interrupt */
#endif

#ifdef ITGTDEF_VARLOCK
   void*       pBfVarLock;    /*!< Pointer to the locked variable state */ /*RFS8500*/
   void*       pBfVarRefresh; /*!< Pointer to the locked variable value */ /*RFS8500*/
#endif /*ITGTDEF_VARLOCK && ITGTDEF_THREAD*/

   /* Specific to Linux IRQ example */
   typSEM_ID   hSemaphore;    /*!< Semaphore of the typINTTHR_HDL task associated to the POU execution (Specific to Linux IRQ example) */
   uint32      luIrqPeriod;   /*!< Period for triggering interrupt simulation (Specific to Linux IRQ example) */
   uchar       bEnabled;      /*!< Determine if the interrupt should be executed or not (Specific to Linux IRQ example) */
}typIRQ_PARAM;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uchar          cuIsUsed;   /*!< Used entry */
   typIRQ_HDL     IrqHdl;     /*!< Interrupt POU */
   typINTTHR_HDL  ThrHdl;     /*!< Thread handler  */
   typIRQ_PARAM   IrqParam;   /*!< IRQ function parameters */
   uint16         huSlaveNum; /*!< Resource number */
   /* Specific to Linux IRQ example */
   typTHR_PRIO    TskPrio;    /*!< Threads priority (Specific to Linux IRQ example) */
   uint32         luLastExecTime; /*!< Last execution time of the interrupt (Specific to Linux IRQ example) */
} typIRQ_MNG;

#endif /* ITGTDEF_INTERRUPT */

/**************************** IRQ MANAGEMENT END *************************/

/**************************** DOXYGEN STRUCTURE ***************************/
/* Heartbeat on a serial port */
#ifdef ITGTDEF_FAILOVER
typedef struct
{
   uchar          cuRun;            /*!< Flag to stop/start the heartbeat thread */
   uchar          cuStopped;        /*!< Flag to determine if the heartbeat thread has stopped or not */
   strCmgHeader*  pCmgHdr;          /*!< Pointer to CMG data space to update active/standby status of the machine */
#ifdef ITGTDEF_FAILOVER_SERIAL_HEARTBEAT
   typRSICOM_ID   RsiComId;         /*!< Handle to the COM port used by the heartbeat thread */
#else
   typSOC_ID      SocketSndId;      /*!< Handle to the socket used by the heartbeat thread to send */
   typSOC_ADD     SocketSndAddress; /*!< Address for sending */
   typSOC_ID      SocketRcvId;      /*!< Handle to the socket used by the heartbeat thread to receive */
   typSOC_ADD     SocketRcvAddress; /*!< Address for receiving */
#endif
} typHBT_ID;
#endif

/* data *******************************************************************/

/* exported services from module   ???    *********************************/
#ifdef ITGT_DBG
#ifdef WINCE
extern __declspec( dllexport) void dsysPrintf(uint32 luLevel, char *psFormat, ...);
#else
extern void dsysPrintf(uint32 luLevel, char *psFormat, ...);
#endif
#endif

/* include ****************************************************************/
/******* ANSI Prototypes *******/
//#include <stdio.h>

/******* ISaGRAF definitions *******/
#include <dsys0pro.h>
#include <dfcr0def.h>
#ifdef ITGTDEF_NO_GLOBALS
#include <dsys0gbl.h>
#endif
#ifdef ITGT_DBG
#include <stdarg.h>
#endif

#endif   /* nested Headers management */
/* eof ********************************************************************/
