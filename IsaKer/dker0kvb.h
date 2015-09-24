/**************************************************************************
File:               dker0kvb.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      11-August-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#ifndef _DKER0KVB_H /* nested Headers management */
#define _DKER0KVB_H

#include <dkvb0def.h> /* Nested header required */

/* constants **************************************************************/

/* types ******************************************************************/

/*
 * Structure to register drivers. If this structure is different from 
 * strKvbDrvFctToReg, then kvbDrvRegister must change. 
 */
typedef strKvbDrvFctToReg strKerKvbDrvReg;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Information for one binding's driver */
typedef struct
{
   void* pvDrvBlkAdd;               /*!< Address of memory block allocated for this driver */
   void* pvDrvProd;                 /*!< Pointer to production tables for this driver */ 
   void* pvDrvCons;                 /*!< Pointer to consumption tables for this driver */ 
   strKerKvbDrvReg* pDrvReg;        /*!< Pointer to registered driver */
} strKerKvbDrvMng;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16         huSlaveNum;       /*!< Slave number */
   uint16         huNbrDrv;         /*!< Number of drivers */
   strDefKvbDrv*  pDefKvbDrv;       /*!< Pointer to KVB table */
   strKvbDrvInfo* pKvbDrvInfo;      /*!< Pointer to KVB table's drivers definition list */
   strKerKvbDrvMng* pKerKvbDrvMng;  /*!< Pointer to kernel's drivers management list */
   strKerKvbDrvReg* pKerKvbDrvRegList; /*!< Pointer to driver registration list (Not used) */
} strKerKvbHeader;

/* data *******************************************************************/

/* exported services from module dker0kvb.c *******************************/
extern uint32 kerKvbSize(void);
extern typSTATUS kerKvbInit
   (
   uint16   huSlaveNum,    /* In: Slave number */
   void*    pvKvbBlkAdd,   /* In: Memory block allocated for binding */
   uint32   luKvbBlkSz     /* In: Size of allocated memory block */
   );
extern void kerKvbExit(void);
extern void kerKvbProduce(void);
extern void kerKvbConsume(void);
extern int32 kerKvbCtl
   (
   uchar    cuSubFunc,        /* In: Sub-function to call */
   uint16   huResProdNum,     /* In: Resource producer identifier */
   typVa    Va                /* In: Kernel variable address */
   );
extern void kvbDrvsRegistration ( void );
extern void kvbDrvsUnregistration ( void );
extern typSTATUS kerKvbMdfInit ( void ); /* RFS 3317 */
#ifdef ITGTDEF_BINDIMPROVE2
extern void kerKvbMdfSetInfoSize
   (
   uint32 luInfoSize /* In: New value following an online change */
   );
extern uint32 kerKvbMdfKeepInfoSizeBeforeExit(void);
#endif
#ifdef ITGTDEF_FAILOVER_KVB
extern uint32 kerKvbUpdateFailoverCrcWithKvbValues
   (
   strKvbCons* pKvbHsdCons, 
   strKvbCons* pKvbEtcpCons
   );
#endif /* ITGTDEF_FAILOVER_KVB */
#endif  /* nested Headers management */
/* eof ********************************************************************/
