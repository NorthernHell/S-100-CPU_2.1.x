/**************************************************************************
File:               dfbl0std.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      18-June-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Kernel Standard Function Blocks library

***************************************************************************
Modifications: (who / date / description)

---4.12 Released---
VMO/12-June-2002/ SFC function block
   Added SFCFblxxx prototypes.
  
***************************************************************************/
#ifndef _DFBL0STD_H /* nested Headers management */
#define _DFBL0STD_H

/* constants **************************************************************/

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module dfbl0std.c *******************************/
extern void fblStdInit(void);
extern void fblStdExit(void);
extern void fblStdClassInit
   (
   uint16 huFblStdClNum,   /* Library function block class number */ 
   uint32 luFblStdNbInst   /* Number of instance of this class */ 
   )  ;

extern void fblStdClassExit
   (
   uint16 huFblStdClNum,   /* Library function block class number */ 
   uint32 luFblStdNbInst   /* Number of instance of this class */ 
   );

extern typSTATUS fblStdInstInit
   (
   uint16      huFblStdClNum,   /*In: Library function block class number */ 
   strParamVa* FblInst          /*In: Instance of function block */ 
   );

extern typSTATUS fblStdInstExit
   (
   uint16      huFblStdClNum,   /*In: Library function block class number */ 
   strParamVa* FblInst          /*In: Instance of function block */ 
   );

extern void fblStdCall
   (
   uint16      huFblStdClNum,   /*In: Library function block class number */ 
   strParamVa* FblInst          /*In: Instance of function block */ 
   );

/* exported services from module dfbl0boo.c *******************************/
extern void SRFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void RSFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void RTrigFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void FTrigFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void SemaFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void TOnFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void TOfFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void TPFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void BlinkFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

/* exported services from module dfbl0num.c *******************************/
extern void CtUFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void CtDFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void CtUDFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void CmpFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void StackIntFblInstInit
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void StackIntFblInstExit
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void StackIntFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

/* exported services from module dfbl0rea.c *******************************/
extern void AverageFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void HysterFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void LimAlrmFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void IntegralFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void DerivateFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void SigGenFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

/* exported services from module dfbl0cfb.c *******************************/
extern void ConnectFblClassInit
   (
   uint32   luFblStdNbInst    /* Number of instance */
   );

extern void ConnectFblClassExit
   (
   uint32   luFblStdNbInst    /* Number of instance */
   );

extern void ConnectFblInstInit
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void ConnectFblInstExit
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void ConnectFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void USendSFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

extern void URcvSFblCall
   (
   strParamVa* FblInst  /*In: Instance of function block */ 
   );

/* exported services from module dfbs0ini.c *******************************/
extern typSTATUS SFCFblClassInit(void);
extern void SFCFblClassExit(void);

extern typSTATUS SFCFblInstInit
   (
   strParamVa* pFblInst          /*In: Instance of function block */ 
   );

extern typSTATUS SFCFblInstExit
   (
   strParamVa* pFblInst          /*In: Instance of function block */ 
   );

extern typSTATUS SFCFblMdfUpdate
   (
   uint16 huPouNum  /* In: Pou number */ 
   );

/* exported services from module dfbs0evo.c *******************************/
#ifdef ITGTDEF_INTERRUPT
extern uchar SFCFblCall
   (
   strParamVa* pFblInst,   /*In: Instance of function block */ 
   uchar* pcuCancelCycle,  /*In: Cancel rest of cycle */                              
   typVa* pVaRetSub        /*In: Return Va from sub program */
   );
#else
extern uchar SFCFblCall
   (
   strParamVa* pFblInst          /*In: Instance of function block */ 
   );
#endif /* ITGTDEF_INTERRUPT */

extern void SFCFblInstHotRestart
   (
   strParamVa* pFblInst,         /*In: Instance of function block */ 
   uchar       cuSubFunc
   );

#endif  /* nested Headers management */
/* eof ********************************************************************/
