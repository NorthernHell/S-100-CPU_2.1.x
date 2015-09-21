/**************************************************************************
File:               dipl0pro.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      2-September-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Package - Linkage prototypes

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#ifndef _DIPL0PRO_H /* nested Headers management */
#define _DIPL0PRO_H

/* constants **************************************************************/

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module dipl0lnk.c *******************************/
extern void iplInit(void);
extern void iplExit(void);
extern void iplRStart
   (
   uint32 luIplTableSz,
   uint16 huSlaveNum
   );
extern void iplRStop(void);
extern typPFnIplFct iplFctAddGet
   (
   char* psFctName  /*In: Function name to retrieve address from */ 
   );

extern void iplFctAddRelease
   (
   char*        psFctName, /* In: Function name to release address from */ 
   typPFnIplFct pfnIplFct  /* In: Function address */
   ); 

#endif  /* nested Headers management */
/* eof ********************************************************************/
