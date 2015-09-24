/**************************************************************************
File:               dker0ste.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      2-February-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        SFC Engine: Steps management

***************************************************************************
Modifications: (who / date / description)
---4.03 Released---
EDS/03-Apr-2000/ SFC Breakpoints addon
   Added extra status info (replaces previous reserved filed)
   Added steXxxSeqReplace() fcts
   Added steXStatusXxx fcts
   By the way added steVaNNext() fct
EDS/04-May-2000/ No more external direct access to steXxx struct
   Added steTimeRefresh() fct
   Modified actInit(), now void pointer for block add (just more sense)

---4.11 Released---
VMO/13-Mar-2002/ Hot restart
   Added steClean() prototype 

---5.00.001 Released---
OLA/03-Nov-2005/ RFS 2553: SFC FB cannot share is local variables with its childs.
   Add steMark2()

***************************************************************************/
#ifndef _DKER0STE_H    /* nested Headers management */
#define _DKER0STE_H


/* constants **************************************************************/

/* types ******************************************************************/
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uchar  cuActive;       /*!< Step activity flag */
   uchar  cuMark;         /*!< Step marker flag */
   uint32 luTimerInfo;    /*!< Step activation date OR activity duration */
   uint32 luTimeInfo;     /*!< Step refreshed activity duration */
   typVa  PouVa;          /*!< Pou variable the step belongs to */
   uchar  cuLevel;        /*!< Pou level the step belongs to */
   uchar  cuXStatus;      /*!< Step extra status info */
   typVa* pBegTicSeq;     /*!< Begin action TIC sequence */
   typVa* pRepTicSeq;     /*!< Repetitve action TIC sequence */
   typVa* pEndTicSeq;     /*!< End action TIC sequence */
   typVa* pPrevTrsListVa; /*!< Step list of Va of transition predecessors */
   typVa* pNextTrsListVa; /*!< Step list of Va of transition successors */
} strSteInfo;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct _s_strSteAct
{
   struct _s_strSteAct* pActPrev; /*!< Previous action in list (RFS 3842) */        
   struct _s_strSteAct* pActNext; /*!< Next action in list */        
   typVa* pSteTicSeq;     /*!< TIC sequence */
   typVa  StepVa;         /*!< Step variable the action belongs to */
   typVa  PouVa;          /*!< Pou variable the action belongs to */
#ifdef ITGTDEF_SFC_PROG_ACT_GROUPING
   uchar  cuProgActDone;  /*!< TRUE if (SFC program) action was executed */
#endif
} strSteAct;

/* data *******************************************************************/

/* exported services from module dker0ste.c *******************************/
extern void* steInit
   (
   typVa  BlkOfSteVa, /* In: Va on beginning of steps variables */ 
   uint32 luNbSte     /* In: Number of steps */ 
   );

extern void steSet
   (
   uint32  luSteCnt,       /* In: Step count number */ 
   typVa*  pBegTicSeq,     /* In: Begin action TIC sequence */ 
   typVa*  pRepTicSeq,     /* In: Repetitve action TIC sequence */ 
   typVa*  pEndTicSeq,     /* In: End action TIC sequence */ 
   typVa*  pPrevTrsListVa, /* In: Step list of Va of transition predecessors */ 
   typVa*  pNextTrsListVa, /* In: Step list of Va of transition successors */ 
   typVa   PouVa,          /* In: Pou variable the step belongs to */ 
   uchar   cuLevel         /* In: Pou level the step belongs to */ 
   ); 

extern void steClean(void);
extern uint32 steElmtNumGet(typVa StepVa);
extern KERINLINE typVa steVaNNext(typVa StepVaStart, uint32 luNbElmtNext);
extern KERINLINE typVa stePouVaGet(typVa StepVa);
extern KERINLINE uchar stePLevelGet(typVa StepVa);
extern KERINLINE typVa* steBegSeqGet(typVa StepVa);
extern KERINLINE typVa* steRepSeqGet(typVa StepVa);
extern KERINLINE typVa* steEndSeqGet(typVa StepVa);
extern typVa* steBegSeqReplace(typVa StepVa, typVa* pNewBegTicSeq);
extern typVa* steEndSeqReplace(typVa StepVa, typVa* pNewEndTicSeq);
extern KERINLINE typVa* steNextTrsListVaGet(typVa StepVa);
extern KERINLINE typVa* stePrevTrsListVaGet(typVa StepVa);
extern void steMarkClear(void);
extern KERINLINE uchar steMark(typVa StepVa);
extern KERINLINE uchar steMark2(typVa StepVa);
extern KERINLINE uchar steActivate(typVa StepVa);
extern KERINLINE void steDeactivate(typVa StepVa);
extern KERINLINE uchar steActivityTest(typVa StepVa);
extern uint32 steTimeRead(typVa StepVa);
extern uint32 steTimeRefresh(typVa StepVa);
extern uchar steXStatusGet(typVa StepVa);
extern void steXStatusSet(typVa StepVa, uchar cuXStatus);
extern void steXStatusReset(typVa StepVa, uchar cuXStatus);

/* exported services from module dker0act.c *******************************/
extern uint32 actSize
   (
   uint32 luNbAct  /* Number of actions */ 
   );

extern void actInit
   (
   void*      pvActBlkAdd,    /*In: Actions execution management block */ 
   uint32     luNbAct,        /*In: Number of actions */ 
   uchar      cuMaxResPLevel  /*In: Max Pou level hierarchy of resource */ 
   );
 
extern KERINLINE void actBegPut
   (
   typVa StepVa
   );

extern KERINLINE void actRepPut
   (
   typVa StepVa
   );

extern KERINLINE void actEndPut
   (
   typVa StepVa
   );
#ifdef ITGTDEF_SFC_PROG_ACT_GROUPING
extern void actExec
   (
   uint16 huPouNum,
   uchar cuSfcPouLevel
   );

extern void actDeactiveExec
   (
   uint16 huPouNum,
   uchar cuSfcPouLevel
   );

extern void actResetLists(void);
#else
extern void actExec(void);
#endif

#endif /* nested Headers management */
/* eof ********************************************************************/
