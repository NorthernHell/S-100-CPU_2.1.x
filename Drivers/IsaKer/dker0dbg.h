/**************************************************************************
File:               dker0dbg.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      26-Nov-2002
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Kernel core definitions for IOs management 

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/
#ifndef _DKER0DBG_H /* nested Headers management */
#define _DKER0DBG_H

#include <dixl0def.h> /* Nested header required */
#include <dker0res.h> /* Nested header required */

/* constants **************************************************************/
#define ISA_DBG_MAX_NB_BKP 50 /* Maximum number of breakpoints*/

#define ISA_DBG_EXCEPT_NULL      0   /* no exception code */
#define ISA_DBG_EXCEPT_DIV0      1   /* Division by zero exception code */
#define ISA_DBG_EXCEPT_BOUND_CHK 2   /* bound check exception code */
#define ISA_DBG_EXCEPT_INV_TIC   3   /* invalid tic code exception code */
#define ISA_DBG_EXCEPT_UNDEF     255 /* undefined exception code */

/* types ******************************************************************/

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint32 luPouNum;                       /*!< POU number */
   uint32 luVaSfcStpTrs;                  /*!< Variable address for step or transition */
   uint32 luCodeType;                     /*!< Code type */
   uint32 luVaFbInst;                     /*!< Variable address of the function block */
   uint32 luStepID;                       /*!< Step identifier */
}strSteppingInfoVar;


/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16      huFlags;                   /*!< SA_DBG_POU_STATUS_FLAG_xxx flags */
   strDefStep  *pSteppingInfoTable;       /*!< Pointer to the Stepping info table*/
   uint32      luSteppingInfoTableSize;   /*!< Number of elements in the Stepping info table*/
   uint32      luBkpCnt;                  /*!< Number of breakpoints active */
}strPOUDbgStatus;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uchar             cuEnabled;           /*!< Whether steb by step is enabled */
   uint16            huNbPOU;             /*!< number of POU */
   uint16            huNbCyclicPOUBeforeSfc;/*!< number of Cyclic programs before SFC POU */
   uint16            huNbCyclicPOUAfterSfc; /*!< number of Cyclic programs executed efter SFC POU */
   uint16            huNbSfcMainPOU;      /*!< number main SFC POU */
	
   uint16            huNbBreakPoints;     /*!< number of currently installed breakpoints*/
   strIxlBkP         tBreakPointList[ISA_DBG_MAX_NB_BKP]; /*!< currently installed breakpoints table*/
	
   uint32            luMaxCallStackLevel; /*!< maximum call stack level*/
   uint32            luCurCallStackLevel; /*!< current call stack level*/
   strIxlStackInfo   *pCallStack;         /*!< call stack. NOTE: the actual size of the table is calculated from the configuration space*/
   strPOUDbgStatus   *pDebugPOUStatus;    /*!< array of entries containing the stepping state/info for each POU */
   
   uchar             cuStepping;          /*!< Whether the VM is stopped (stepping) */
   uchar             cuCancelCycle;       /*!< Whether the VM is stopped (stepping) */
   uchar             cuException;         /*!< Current exception code ISA_DBG_EXCEPT_xxx codes */
   uint32            luStepCallStackLevel;/*!< stack level of the function we are stepping over (for step over function only)*/
	/*!< set to 0xffffffff if not stepping over */
	
   /* debugger system variables */
   strSteppingInfoVar *pSteppingInfoVar;
   uint32            *pPouStatusVar;
   uint32            luNPouStatusVar;
	
}strKDbgMngHeader;

/* data *******************************************************************/

/* exported services from module dker0dbg.c *******************************/

extern uint32 kerDbgPrivateBlockSizeGet(void);

/* Debug Module Init */
extern typSTATUS kerDbgInit
   (
   void* pvDbgBlkAdd  /* Block addresses for IO management */ 
   );

/* Debug Module Exit */
extern void kerDbgExit(void);  

extern uchar kerDbgBkPSet(uint16 huPouNum,uint32 luStepId,uchar  cuSet);

extern uchar kerDbgExecute(uchar  cuDbgCmd);

extern strIxlStackInfo *kerDbgCallStackBlkGet(uint16 *phuNbTot, uchar  *pcuStackOvf);

extern strIxlBkP *kerDbgBkpBlkGet(uint16 *phuNbTot);

extern typSTATUS kerDbgPouInit(uint16 huPouNum);
   
extern char kerDbgOnStep
   (
   uint16   huPouNum,      /* In: Number of the POU */ 
   typVa*   mic,           /* TIC Sequence. NULL if end of POU */ 
   typVa    SfcStpTrsVa,   /* Va of step or transition if sfc */
   uchar    cuCodeType,    /* Type of code to execute */
   strParamVa* FblInst,    /* function block instance */
   uchar    cuException,   /* non zero if it is an exception that occured (div by zero and other)*/
                           /* ISA_DBG_EXCEPT_xxx codes */
   typVa* pTic             /* in/out: pointer to current tic code */ 
   );

extern void kerDbgCallStackPushPop(
   uchar    cuPush,        /* Whether to push or pop */
   uint16   huPouNum,      /* Program Number:1 to N. If 0, returns list for all POUs*/
   typVa    SfcStpTrsVa,   /* VA of SFC step or transition if any */
   uint32   luCodeType,    /* type of code being stepped (cyclic/P0 step/ )*/
   strParamVa *FblInst     /* VA of of the function block instance if any */
   );

extern void kerDbgCycleStart(void);

#ifdef ITGTDEF_ENH_ONLINE_CHANGE
extern void kerDbgMdfInit(void);
#endif

extern uchar kerDbgIsPouInDebug
   (
   uint16 huPouNum         /* POU number */
   );

#endif  /* nested Headers management */
/* eof ********************************************************************/
