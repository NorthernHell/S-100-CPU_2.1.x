/**************************************************************************
File:               dker0mai.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      29-May-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Kernel Main Entry Points

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#ifndef _DKER0MAI_H /* nested Headers management */
#define _DKER0MAI_H

/* constants **************************************************************/

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module dker0mai.c *******************************/
extern uint16 dkerStartup
   (
   int32 ldArgc,    /* In: Number of arguments */ 
   char* ppsArgv[]  /* In: Array of arguments */ 
   );

extern void dkerExit
   (
   uint16 huSlaveNum  /* Kernel Slave number */
   );

extern typSTATUS dkerRRestore
   (
   uint16 huSlaveNum,   /* Slave number */
   uint16 huResLocation /* How to get resource */
   );

extern typSTATUS dkerRStart 
   (
   uint16 huSlaveNum  /* Kernel Slave number */
   );

extern void dkerRStop
   (
   uint16 huSlaveNum  /* Kernel Slave number */
   );

extern void dkerCycleSrvCom (void);
extern void dkerWaitSrvCom (void);
extern void dkerExec (void);

extern int dkerMain   
   (
   int32 ldArgc,    /* In: Number of arguments */ 
   char* ppsArgv[]  /* In: Array of arguments */ 
   );

#endif  /* nested Headers management */
/* eof ********************************************************************/
