/**************************************************************************
File:               dker0tra.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      2-February-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        SFC Engine: Transitions management

***************************************************************************
Modifications: (who / date / description)
---4.03 Released---
EDS/03-Apr-2000/ SFC Breakpoints addon
   Added extra status info (replaces previous reserved filed)
   Added traTicSeqReplace() fct
   Added traXStatusXxx() fcts
   By the way added traVaNNext() fct

***************************************************************************/
#ifndef _DKER0TRA_H    /* nested Headers management */
#define _DKER0TRA_H


/* constants **************************************************************/

/* types ******************************************************************/
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uchar  cuRecept;       /*!< Transition receptivity state */
   uchar  cuValid;        /*!< Transition validity state */
   uchar  cuMark;         /*!< Transition marker flag */
   uchar  cuXStatus;      /*!< Transition extra status info */
   typVa  PouVa;          /*!< Pou variable the transition belongs to */
   typVa* pTraTicSeq;     /*!< Transition receptivity TIC sequence */
   typVa* pPrevStpListVa; /*!< Transition list of Va of step predecessors */
   typVa* pNextStpListVa; /*!< Transition list of Va of step successors */
} strTraInfo;

/* data *******************************************************************/

/* exported services from module dker0tra.c *******************************/
extern void* traInit
   (
   typVa  BlkOfTraVa, /* In: Va on beginning of transitions variables */ 
   uint32 luNbTra     /* In: Number of transitions */ 
   ); 

extern void traSet
   (
   uint32  luTraCnt,       /*In: Transition count number */ 
   typVa*  pTraTicSeq,     /*In: Transition Tic Code Sequence */ 
   typVa*  pPrevStpListVa, /*In: Trs list of Va of stps predecessor */ 
   typVa*  pNextStpListVa, /*In: Trs list of Va of stps successor */
   typVa   PouVa           /*In: Pou variable the transition belongs to */
   );
 
extern uint32 traElmtNumGet(typVa TraVa);
extern KERINLINE typVa traVaNNext(typVa TraVaStart, uint32 luNbElmtNext);
extern KERINLINE typVa traPouVaGet(typVa TraVa);
extern KERINLINE typVa* traTicSeqGet(typVa TraVa);
extern typVa* traTicSeqReplace(typVa TraVa, typVa* pNewTraTicSeq);
extern KERINLINE typVa* traNextStpListVaGet(typVa TraVa);
extern KERINLINE typVa* traPrevStpListVaGet(typVa TraVa);
extern void traMarkClear(void);
extern KERINLINE uchar traMark(typVa TraVa);
extern uchar traXStatusGet(typVa TraVa);
extern void traXStatusSet(typVa TraVa, uchar cuXStatus);
extern void traXStatusReset(typVa TraVa, uchar cuXStatus);

#endif /* nested Headers management */
/* eof ********************************************************************/
