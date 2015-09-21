/**************************************************************************
File:               dusf0std.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      17-June-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Kernel Standard Functions library

***************************************************************************
Modifications: (who / date / description)

---5.00 Released---
OL/19-Apr-2005/ CurrentIsaDate()
   Add standard function usfCurrentIsaDate()

FG/25-Apr-2005/ SubDateDate()
   Add standard function usfSubDateDate()
***************************************************************************/
#ifndef _DUSF0STD_H /* nested Headers management */
#define _DUSF0STD_H

/* constants **************************************************************/

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module dusf0std.c *******************************/
extern typSTATUS usfStdInit
   (
   uint16 huSlaveNum          /*In: Resource number */
   );
extern void usfStdExit(void);
extern void usfStdCall
   (
   uint16      huUsfStdNum,   /*In: Library function number */ 
   strParamVa* InParam,       /*In: Input parameters */ 
   uchar       cuNbInParam,   /*In: Number of input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );
extern void usfLockCpu
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );
extern void usfUnlockCpu
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

/* exported services from module dusf0num.c *******************************/
extern void usfStdNumInit(void);
extern void usfStdNumExit(void);

extern void usfAndMask
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfOrMask
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfXorMask
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfNotMask
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfLimit
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfMax
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfMin
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfMod
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfSel
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfMux4
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfMux8
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfOdd
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfRand
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfRol
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfRor
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfShl
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfShr
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

/* exported services from module dusf0rea.c *******************************/
extern void usfAbs
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfExpt
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfLog
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfPow
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfSqrt
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfTrunc
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfACos
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfASin
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfATan
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfCos
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfSin
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfTan
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

/* exported services from module dusf0str.c *******************************/
extern void usfAscii 
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfChar 
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfDelete
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfInsert
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfFind
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfMLen
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfLeft
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfMid
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfReplace
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfRight
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfCurrentIsaDate
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

extern void usfSubDateDate
   (
   strParamVa* InParam,       /*In: Input parameters */ 
   strParamVa* OutParam       /*In: Output parameter */ 
   );

/* exported services from module dusf0fil.c *******************************/

#endif  /* nested Headers management */
/* eof ********************************************************************/
