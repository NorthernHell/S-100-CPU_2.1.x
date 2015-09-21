/**************************************************************************
File:               dfbl0sfc.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      12 June 2002

Copyright ICS Triplex ISaGRAF Inc. 2002
***************************************************************************
Attached documents: Instance of SFC function block
  
***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

---5.00.001 Released---
OLA/03-Nov-2005/ RFS 2553: SFC FB cannot share is local variables with its childs.
   Add evoSfcInstStartExt() and evoSfcInstReStartExt()
  
***************************************************************************/
#ifndef _DFBL0SFC_H /* nested Headers management */
#define _DFBL0SFC_H

#include <dker0ste.h>

/* constants **************************************************************/
#define ISA_SFC_FBL_DESC_RSRVD_BIT_IS_ECC   0x1   /* RFS 5070 */
#define ISA_SFC_FBL_MAX_LOOP_ECC            10    /* RFS 5070 */

/* types ******************************************************************/

/***********************************************************************************

   Structures used in SFC function block space

***********************************************************************************/
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16      huClassNbr;       /*!< Number of class */
   uint16      huReserved;       /*!< Reserved */
   uint32      luClassDefOfs;    /*!< Offset to class definition array */
   uint32      luInstActivOfs;   /*!< Offset to instance activity array */

} strSfcHdr;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16      huPouNum;         /*!< POU number */
   uint16      huInstNbr;        /*!< Number of instance */
   uint32      luInstSize;       /*!< Size of an instance */
   uint32      luInstOfs;        /*!< Offset to first instance */

} strSfcClassDef;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typVa       InstVa;           /*!< Instance VA in run time database */
   uint16      huPouNum;         /*!< Pou Num the instance refers to */
   uint16      huReserved;       /*!< Reserved */

   uint32      luExmTrsInitOfs;  /*!< Offset to examined transition */
   uint32      luClrTrsInitOfs;  /*!< Offset to cleared transition */
   uint32      luExmRepActCOfs;  /*!< Offset to repetitive action current cycle */
   uint32      luExmRepActLOfs;  /*!< Offset to repetitive action last cycle */
   
   uint32      luSfcChildOfs;    /*!< Offset to list of SFC child */

   uint32      luSteActOfs;      /*!< Offset to step action arrays */

} strSfcInstActiv;


/***********************************************************************************

   Structures used in Runtime database

***********************************************************************************/
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typVa*   pExmTrsInit;	      /*!< Transition examination management block */
   typVa*   pExmTrs;             /*!< Transition to examine */
   typVa*   pValTrs;             /*!< Valid transitions */
   typVa*   pClrTrsInit;         /*!< Transition clearing management block */
   typVa*   pClrTrs;             /*!< Clearable transitions */
   typVa*   pExmRepeatC;         /*!< Rep action current cycle examination block */
   typVa*   pExmRepeatL;         /*!< Rep action last cycle examination block */

   strSteAct*  pFreeAct;         /*!< Free action to execute */
   strSteAct*  pBegAct;          /*!< Begin action to execute */
   strSteAct*  pRepAct;          /*!< Repetitive action to execute */
   strSteAct*  pEndAct;          /*!< End action to execute */
      
   uchar    cuStatus;            /*!< Instance status - Active, inactive or frozen */
   uchar    cuReserved1;         /*!< Reserved (RFS 5070: bit 0 set indicates SFC FB is a basic IEC 61499 FB i.e. an ECC) */
   uchar    cuMaxLoopEcc;        /*!< Reserved (RFS 5070: counter for max loops in ECC) */
#ifdef ITGTDEF_ENH_ONLINE_CHANGE
   uchar    cuRestored;          /*!< Non zero if instance is restored during online change */
#else
   uchar    cuReserved3;         /*!< Reserved */
#endif

   uint32   luDynFactor;         /*!< SFC Dynamic factor */
   
   struct _s_SteInstInfo* pSteInstInfo; /*!< Steps array */
   uint32   luSteInstInfoNbr;    /*!< Number of steps */
   struct _s_TraInstInfo* pTraInstInfo; /*!< Transitions array */
   uint32   luTraInstInfoNbr;    /*!< Number of transitions */

   strSfcInstActiv* pInstActiv;
   typVa*           pChildSfcVa;

} strInstInfo;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct _s_SteInstInfo
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

   uint32* pluPrevTraListOfs; /*!< Offset to list of transition predecessors */
   uint32* pluNextTraListOfs; /*!< Offset to list of transition successors */

} strSteInstInfo;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct _s_TraInstInfo
{
   uchar  cuRecept;       /*!< Transition receptivity state */
   uchar  cuValid;        /*!< Transition validity state */
   uchar  cuMark;         /*!< Transition marker flag */
   uchar  cuXStatus;      /*!< Transition extra status info */
   typVa  PouVa;          /*!< Pou variable the transition belongs to */
   typVa* pTraTicSeq;     /*!< Transition receptivity TIC sequence */

   uint32* pluPrevSteListOfs; /*!< Offset to list of step predecessors */
   uint32* pluNextSteListOfs; /*!< Offset to list of step successors */

} strTraInstInfo;

/* data *******************************************************************/

/* exported services from module dfbs0evo.c *******************************/
extern void evoSfcInstStart
   (
   typVa   /* SFC function block instance VA */
   );

extern void evoSfcInstStartExt
   (
   typVa,      /* SFC function block instance VA */
   strParamVa*,/* function block instance's parameters list */
   uchar       /* Number of parameters */
   );

void evoSfcInstKill
   (
   typVa   /* SFC function block instance VA */
   );

void evoSfcInstFreeze
   (
   typVa   /* SFC function block instance VA */
   );

void evoSfcInstReStart
   (
   typVa   /* SFC function block instance VA */
   );

void evoSfcInstReStartExt
   (
   typVa,      /* SFC function block instance VA */
   strParamVa*,/* function block instance's parameters list */
   uchar       /* Number of parameters */
   );

uchar evoSfcInstStatusGet
   (
   typVa   /* SFC function block instance VA */
   );

typSTATUS evoSfcTrsUcc
   (
   typVa TrsVa  /* Transition variable to clear */
   );

#endif  /* nested Headers management */
/* eof ********************************************************************/
