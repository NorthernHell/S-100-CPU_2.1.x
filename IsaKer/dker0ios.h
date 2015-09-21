/**************************************************************************
File:               dker0ios.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      26-June-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Kernel core definitions for IOs management 

***************************************************************************
Modifications: (who / date / description)
---4.02 Released---
EDS/07-Jan-2000/ Get list of locked IO management
   Added kerIosRtIoChanBlkGet() proto.
EDS/10-Jan-2000/ Lock-Unlock of IO enhancement
   Added kerIosRtIoChanLock() & kerIosRtIoChanUnlock() protos.

---4.12 Released---
VMO/26-Mar-2002/ IOs online modification
   Added management of IO's MDF

***************************************************************************/
#ifndef _DKER0IOS_H /* nested Headers management */
#define _DKER0IOS_H

#include <dios0def.h> /* Nested header required */
#include <dker0res.h>
#include <dker0mdf.h>

/* constants **************************************************************/
/* Type of functions of an IO driver */
#define ISA_IO_FCTTYP_DRV       1  /* Driver Init/Exit fcts */
#define ISA_IO_FCTTYP_LEV1DVC   2  /* Level 1 devices Open/Close fcts */
#define ISA_IO_FCTTYP_SPLDVCR   3  /* Simple devices Read fct */
#define ISA_IO_FCTTYP_SPLDVCW   4  /* Simple devices Write fct */
#define ISA_IO_FCTTYP_SPLDVCCTL 5  /* Simple devices Control fct */
#ifdef ITGTDEF_MODIF
#define ISA_IO_FCTTYP_DRVMDF    6  /* Driver online modif fct */
#define ISA_IO_FCTTYP_CPXDVCMDF 7  /* Complex devices online modif fct */
#define ISA_IO_FCTTYP_SPLDVCMDF 8  /* Simple devices online modif fct */
#endif


/* types ******************************************************************/
/* Kernel IO extra parameters (custom part) */
typedef struct
{
   uchar  cuIsIoSimul; /* Simulation of IOs flag */
   uchar  cuReserved;
   uint16 huReserved1;
   uint16 huReserved2;
   uint16 huReserved3;
} strKIoXParam; 

/*
 * Kernel Io management block
 */
/* Drivers to Init/Exit */
typedef struct
{
   typPFnDrvIosInit  pfnDrvIosInit; /* Driver init fct */
   typPFnDrvIosExit  pfnDrvIosExit; /* Driver exit fct */
   strRtIoDrv*       pRtIoDrv;      /* Driver run time structure */
} strKIoMngDrv;

/* Level 1 devices to Open/Close */
typedef struct
{
   typPFnDvcIosOpen  pfnDvcIosOpen;  /* Device open fct */
   typPFnDvcIosClose pfnDvcIosClose; /* Device close fct */
   void*             pvRtIoDvc;      /* Dvc run time struct: Cpx or Spl */
} strKIoMngL1Dvc;

/* Simple devices to Read */
typedef struct
{
   typPFnSplDvcIosRead pfnSplDvcIosRead; /* Spl dvc read fct */
   strRtIoSplDvc*      pRtIoSplDvc;      /* Simple device run time struct */
} strKIoMngSDvcR;

/* Simple devices to Write */
typedef struct
{
   typPFnSplDvcIosWrite pfnSplDvcIosWrite; /* Spl dvc write fct */
   strRtIoSplDvc*       pRtIoSplDvc;       /* Simple device run time struct */
} strKIoMngSDvcW;

typedef struct
{
   strKIoXParam     KIoXParam;      /* IO extra parameters */
   strKIoMngDrv*    pKIoMngDrv;     /* Ptr to drivers to Init/Exit */
   uint16           huNbKIoMngDrv;  /* Number of them */
   strKIoMngL1Dvc*  pKIoMngL1Dvc;   /* Ptr to Lev 1 devices to Open/Close */
   uint16           huNbKIoMngL1Dvc;/* Number of them */
   strKIoMngSDvcR*  pKIoMngSDvcR;   /* Ptr to simple devices to read */ 
   uint16           huNbKIoMngSDvcR;/* Number of them */
   strKIoMngSDvcW*  pKIoMngSDvcW;   /* Ptr to simple devices to write */
   uint16           huNbKIoMngSDvcW;/* Number of them */
   strRtIoDrv*      pRtIoDrv;       /* Ptr to run time structs of drivers */
   uint16           huNbRtIoDrv;    /* Number of them */
   strRtIoCpxDvc*   pRtIoCpxDvc;    /* Ptr to run time structs of cpx dvces */
   uint16           huNbRtIoCpxDvc; /* Number of them */
   strRtIoSplDvc*   pRtIoSplDvc;    /* Ptr to run time structs of spl dvces */
   uint16           huNbRtIoSplDvc; /* Number of them */
   strRtIoChan*     pRtIoChan;      /* Ptr to run time structs of channels */
   typVa            NbIoVa;         /* Number of them */
} strKIoMngHeader;


/* data *******************************************************************/

/* exported services from module dker0ios.c *******************************/
extern uint32 kerIosSize
   (
   uchar cuBlkType  /* Block type */
   );

extern typSTATUS kerIosInit
   (
   void** ppvIosBlkAdd  /* Block addresses for IO management */ 
   );

extern void kerIosExit(void);  
extern void kerIosInput(void);
extern void kerIosOutput(void);
extern strRtIoChan* kerIosRtIoChanFromVa
   (
   typVa ChanVa  /* Va of the variable wired to the channel */ 
   );

extern strRtIoChan* kerIosRtIoChanBlkGet   
   (
   typVa* pNbTotIoVa  /* Out: Total number of RtIoChan structures */ 
   );                 /* Returns: Add of block of RtIoChan structures */

extern void kerIosRtIoChanLock
   (
   strRtIoChan* pRtIoChan,    /* In: Channel to lock */
   uchar        cuForceIosCtl /* In: Force call to IosCtl() if true */
   );

extern void kerIosRtIoChanUnlock
   (
   strRtIoChan* pRtIoChan,    /* In: Channel to unlock */
   uchar        cuForceIosCtl /* In: Force call to IosCtl() if true */
   );

extern strRtIoDrv*    RtIoDrvGet(void);
extern strRtIoCpxDvc* RtIoCpxDvcGet(void);
extern strRtIoSplDvc* RtIoSplDvcGet(void);

extern strDfIoChan*   kerIosDfUoChanFromVa
   (
   typVa        ChanVa        /* In: Channel connected va to search */ 
   );

extern typSTATUS     mdfMgtIoParam(uchar, strRdccModulId*, strRdccModulId*);
extern void          mdfIoParamProceed(strRdccModulId*, strRdccModulId*);
extern void			 kerIosMdfInit(void);

#ifdef ITGTDEF_FAILOVER
extern uint32 kerIosUpdateFailoverCrcWithIoValues
   (
   uchar cuInputsOnly
   );
#endif

/* exported services from module dios0cus.c *******************************/
extern typSTATUS iosCusInit
   (
   strRtIoDrv*   pRtIoDrv,    /*In: Run time io struct of first io driver */
   uint16        huNbRtIoDrv, /*In: Number of drivers */
   strKIoXParam* pKIoXParam   /*In: Extra parameters */
   );

extern void iosCusExit
   (
   strRtIoDrv*   pRtIoDrv,    /*In: Run time io struct of first io driver */
   uint16        huNbRtIoDrv, /*In: Number of drivers */
   strKIoXParam* pKIoXParam   /*In: Extra parameters */
   );

extern void iosCusFctAddGet
   (
   void*         pvRtIoObj,  /* In: Run time io struct of object */ 
   strKIoXParam* pKIoXParam, /* In: Extra parameters */ 
   uchar         cuIoFctType,/* In: Type of io functions to get */
   typPFnIplFct* ppfnIplFct1,/* Out: Function1 address (according IO obj) */ 
   typPFnIplFct* ppfnIplFct2 /* Out: Function2 address (according IO obj) */ 
   );

extern void iosCusFctAddRelease
   (
   void*         pvRtIoObj,  /* In: Run time io struct of object */ 
   strKIoXParam* pKIoXParam, /* In: Extra parameters */ 
   uchar         cuIoFctType,/* In: Type of io functions to get */
   typPFnIplFct  pfnIplFct1, /* In: Function1 address (according IO obj) */ 
   typPFnIplFct  pfnIplFct2  /* In: Function2 address (according IO obj) */ 
   );

#endif  /* nested Headers management */
/* eof ********************************************************************/
