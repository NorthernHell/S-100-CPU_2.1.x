/**************************************************************************
File:               dlnx0pro.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      18-November-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        System extended function prototypes.
                    File for LINUX.

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#ifndef _DLNX0PRO_H  /* nested Headers management */
#define _DLNX0PRO_H  

/* constants **************************************************************/

#define ISA_PATHNAME_SIZE   ISA_PRJPATH_SIZE + ISA_SYSOBJ_NAMESIZE

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module dsys0ini.c *******************************/
extern typSTATUS XsysObjNameGet
   (
   uint16   huOwnerNum,    /* In: Owner number or 0 */
   uint16   huUserNum,     /* In: User number if any (0 else) */
   uchar    cuObjNum,      /* In: Object number */
   uchar    cuType,        /* In: Type */
   char*    psBuffer,      /* Out: Buffer */
   uint16   huBufferSize   /* In: Buffer size */
   );


/* exported services from module dsys0tim.c *******************************/
extern void LNXsysTimeInit(void);
extern void LNXsysTimeExit(void);

/* exported services from module dsys0sem.c *******************************/
extern typSTATUS XsysSemBCreate
   (
   typSEM_ID* pSemId,         /* Out: Semaphore identifier */
   char* name,                /* In:  Semaphore name */ 
   uchar cuInitValue          /* In:  Init value */
   );

extern typSTATUS XsysSemMCreate
   (
   typSEM_ID* pSemId,         /* Out: Semaphore identifier */
   char* name                /* In:  Semaphore name */ 
   );
extern typSTATUS XsysSemBOpen
   (
   typSEM_ID* pSemId,         /* Out: Semaphore identifier */
   char* name                /* In:  Semaphore name */ 
   );

extern typSTATUS XsysSemMOpen
   (
   typSEM_ID* pSemId,         /* Out: Semaphore identifier */
   char* name                /* In:  Semaphore name */ 
   );

extern typSTATUS XsysSemBClose
   (
   typSEM_ID* pSemId         /* Out: Semaphore identifier */
   );

extern typSTATUS XsysSemMClose
   (
   typSEM_ID* pSemId         /* Out: Semaphore identifier */
   );

extern typSTATUS XsysSemBDelete
   (
   typSEM_ID* pSemId         /* Out: Semaphore identifier */
   );

extern typSTATUS XsysSemMDelete
   (
   typSEM_ID* pSemId         /* Out: Semaphore identifier */
   );

extern typSTATUS XsysSemBGive
   (
   typSEM_ID* pSemId         /* Out: Semaphore identifier */
   );

extern typSTATUS XsysSemMGive
   (
   typSEM_ID* pSemId         /* Out: Semaphore identifier */
   );

extern typSTATUS XsysSemBTake
   (
   typSEM_ID* pSemId,         /* Out: Semaphore identifier */
   uint32         luTimeOut      /* In: Time out specification(ms):   */
                                 /*     ISA_WAITFOREVER=wait for ever */
                                 /*     ISA_NOWAIT=no wait            */
   );

extern typSTATUS XsysSemMTake
   (
   typSEM_ID* pSemId,         /* Out: Semaphore identifier */
   uint32         luTimeOut      /* In: Time out specification(ms):   */
                                 /*     ISA_WAITFOREVER=wait for ever */
                                 /*     ISA_NOWAIT=no wait            */
   );

/* exported services from module dsys0arg.c *******************************/
extern void XsysArgInit
   (
   int32 ldArgc,        /* In: Number of arguments */ 
   char* ppsArgv[]      /* In: Array of arguments */ 
   );

/* exported services from module dsys0spc.c *******************************/
extern void* LNXsysSpcCreate
   (
   typSPC_ID*  pSpcId,        /* Out: Pointer to space identifier */
   char*       psName,        /* In:  Name of space */
   uint32      luSize         /* In:  Size of the space to be allocated */
   );

extern void* LNXsysSpcLink
   (
   typSPC_ID*  pSpcId,        /* Out: Pointer to space identifier */
   char*       psName,        /* In:  Name of space */
   uint32*     pluSize        /* Out: Size of the space */
   );

extern typSTATUS LNXsysSpcUnlink
   (
   typSPC_ID*  pSpcId,        /* In:  Pointer to space identifier */
   void*       pvAddress      /* In:  Pointer to space */
   );

extern typSTATUS LNXsysSpcDelete
   (
   typSPC_ID*  pSpcId,        /* In:  Pointer to space identifier */
   void*       pvAddress      /* In:  Pointer to space */
   );

/* exported services from module dsys0wng.c *******************************/
extern void XsysWngInit
   (
   uchar cuMaxNbWng  /* Maximum number of queued warnings */
   );

#endif
/* eof ********************************************************************/
