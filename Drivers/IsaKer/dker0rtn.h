/**************************************************************************
File:               dker0rtn.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      4-December-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Kernel retain management prototypes.

***************************************************************************
Modifications: (who / date / description)

---4.50 T6200 ---
OLA/22-Nov-2005/ RFS 5050: To prevent fragmentation, retain file will be
    deleted, at clean stored code command.

---100.00.001 Released---
ED/18-Dec-2006
   Vantage - Enhanced online change support for retained variables.
  
***************************************************************************/
#ifndef _DKER0RTN_H /* nested Headers management */
#define _DKER0RTN_H

#ifdef ITGTDEF_RETAIN

/* constants **************************************************************/

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module drtn0cus.c *******************************/
extern typSTATUS rtnCusInit
   (
   uint16        huSlaveNum,   /* Slave number */ 
   uchar         cuRtnReadArg, /* Non zero: read required in rtnCusRead() */ 
   strDefRtn*    pDefRtn,      /* Definition of retain variables */ 
   strDefRtnBlk* pRtnBlks      /* Description list of blks of retain data */ 
   );

extern void rtnCusExit
   (
   uint16 huSlaveNum  /* Slave number */ 
   );

extern void rtnCusRead
   (
   uchar cuRtnReadArg /* Non zero: read required */ 
   );

extern void rtnCusWrite(void);

extern void rtnCusClean(void);

#ifdef ITGTDEF_ENH_ONLINE_CHANGE
extern typSTATUS kerRtnMdfInit(void);
extern typSTATUS kerSetNewRtnMem(strDefRtn* pDefRtn);
extern uint32 kerComputeRtnSpcSize(strDefRtn* pDefRtn, strDefRtnBlk* pRtnBlks);
extern uint32 kerRtnSpcSize(void);
extern uint32 kerRtnSpcSizeInUse(void);
extern typSTATUS kerCreateNewRtnSpc(uint32 luCurRtnSize, uint32 luNewRtnSize);
#endif /* ITGTDEF_ENH_ONLINE_CHANGE */

#endif /* #ifdef ITGTDEF_RETAIN */
#endif  /* nested Headers management */
/* eof ********************************************************************/
