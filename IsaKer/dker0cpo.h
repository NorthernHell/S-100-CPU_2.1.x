/**************************************************************************
File:               dker0cpo.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28-August-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Kernel management of 'C' POU: definitions

***************************************************************************
Modifications: (who / date / description)

---4.11 Released---
VMO/13-Mar-2002/ Hot restart
   Add ISA_CPO_FCTTYP_FBLSUBFUNC macro to manage user 'c' FB sub function
  
***************************************************************************/
#ifndef _DKER0CPO_H /* nested Headers management */
#define _DKER0CPO_H

/* constants **************************************************************/
#define ISA_CPO_FCTTYP_FBLCLASS 1
#define ISA_CPO_FCTTYP_FBLINST  2
#define ISA_CPO_FCTTYP_FBLCALL  3
#define ISA_CPO_FCTTYP_FBLSUBFUNC   4

/* types ******************************************************************/
/* 'C' POU usf extra parameters for custom module */
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uchar  cuIsNImpByPass; /*!< Not implemented usf by-pass flag */
   uchar  cuReserved;
   uint16 huReserved1;
   uint16 huReserved2;
   uint16 huReserved3;
} strUsfMngXParam; 

/**************************** DOXYGEN STRUCTURE ***************************/
/* 'C' POU fbl extra parameters for custom module */
typedef struct
{
   uchar  cuIsNImpByPass; /*!< Not implemented fbl by-pass flag */
   uchar  cuReserved;
   uint16 huReserved1;
   uint16 huReserved2;
   uint16 huReserved3;
} strFblMngXParam; 

/**************************** DOXYGEN STRUCTURE ***************************/
/* 'C' POU cnv extra parameters for custom module */
typedef struct
{
   uchar  cuIsNImpByPass; /*!< Not implemented cnv by-pass flag */
   uchar  cuReserved;
   uint16 huReserved1;
   uint16 huReserved2;
   uint16 huReserved3;
} strCnvMngXParam; 

/* data *******************************************************************/

/* exported services from module dcpo0cus.c *******************************/
extern void cpoCusUsfInit
   (
   strUsfMngXParam* pUsfMngXParam   /*In: Extra parameters */ 
   );

extern void cpoCusUsfExit
   (
   strUsfMngXParam* pUsfMngXParam   /*In: Extra parameters */ 
   );

extern typPFnIplFct cpoCusUsfFctAddGet
   (
   char*            psUsfName,      /*In: 'C' function name */
   strUsfMngXParam* pUsfMngXParam   /*In: Extra parameters */
   );

extern void cpoCusUsfFctAddRelease
   (
   char*            psUsfName,      /*In: 'C' function name */
   strUsfMngXParam* pUsfMngXParam,  /*In: Extra parameters */
   typPFnIplFct     pfnUsfFctAdd    /*In: 'C' function address */
   );
  
extern void cpoCusFblInit
   (
   strFblMngXParam* pFblMngXParam   /*In: Extra parameters */ 
   );

extern void cpoCusFblExit
   (
   strFblMngXParam* pFblMngXParam   /*In: Extra parameters */ 
   );

extern void cpoCusFblFctAddGet 
   (
   char*            psFblName,     /* In: C function block name */ 
   strFblMngXParam* pFblMngXParam, /* In: Extra parameters */ 
   char             cuFblFctType,  /* In: Type of the fbl fct to get */ 
   typPFnIplFct*    ppfnIplFct1,   /* Out: Fct1 (according fbl fct type) */ 
   typPFnIplFct*    ppfnIplFct2    /* Out: Fct2 (according fbl fct type) */ 
   );

extern void cpoCusFblFctAddRelease
   (
   char*            psFblName,     /* In: C function block name */ 
   strFblMngXParam* pFblMngXParam, /* In: Extra parameters */ 
   char             cuFblFctType,  /* In: Type of the fbl fct to release */ 
   typPFnIplFct     pfnIplFct1,    /* In: Fct1 (according fbl fct type) */ 
   typPFnIplFct     pfnIplFct2     /* In: Fct2 (according fbl fct type) */ 
   );

extern void cpoCusCnvInit
   (
   strCnvMngXParam* pCnvMngXParam   /*In: Extra parameters */ 
   );

extern void cpoCusCnvExit
   (
   strCnvMngXParam* pCnvMngXParam   /*In: Extra parameters */ 
   );

extern typPFnIplFct cpoCusCnvFctAddGet
   (
   char*            psCnvName,      /*In: 'C' conversion name */
   strCnvMngXParam* pCnvMngXParam   /*In: Extra parameters */
   );

extern void cpoCusCnvFctAddRelease
   (
   char*            psCnvName,      /*In: 'C' conversion name */
   strCnvMngXParam* pCnvMngXParam,  /*In: Extra parameters */
   typPFnIplFct     pfnCnvFctAdd    /*In: 'C' conversion fct address */
   );
  
#endif  /* nested Headers management */
/* eof ********************************************************************/
