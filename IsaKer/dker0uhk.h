/**************************************************************************
File:               dker0uhk.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      23-October-1997
***************************************************************************
Attached documents: 

***************************************************************************
Description:        User Hook functions management

***************************************************************************
Modifications: (who / date / description)
---4.02 Released---
EDS/03-Dec-1999/ Kernel Hooks integration
   Added hooks defs and proto
  
***************************************************************************/
#ifndef _DKER0UHK_H  /* nested Headers management */
#define _DKER0UHK_H 


/* Hook functions *********************************************************/

/* Kernel start hook */
#ifndef ITGTDEF_KERHOOK_KERSTART
#define ISA_KERHOOK_KERSTART() 
#else
extern void kerHookKerStart(void);
#define ISA_KERHOOK_KERSTART() kerHookKerStart()
#endif

/* Kernel stop hook */
#ifndef ITGTDEF_KERHOOK_KERSTOP
#define ISA_KERHOOK_KERSTOP() 
#else
extern void kerHookKerStop(void);
#define ISA_KERHOOK_KERSTOP() kerHookKerStop()
#endif

/* Resource start hook */
#ifndef ITGTDEF_KERHOOK_RSTART
#define ISA_KERHOOK_RSTART() 0
#else
extern typSTATUS kerHookRStart(void);
#define ISA_KERHOOK_RSTART() kerHookRStart()
#endif

/* Resource stop hook */
#ifndef ITGTDEF_KERHOOK_RSTOP
#ifdef ITGTDEF_HOTRESTART
#define ISA_KERHOOK_RSTOP() kerSymExit()
#else
#define ISA_KERHOOK_RSTOP() 
#endif
#else
extern void kerHookRStop(void);
#define ISA_KERHOOK_RSTOP() kerHookRStop()
#endif

/* Beginning of cycle execution hook */
#ifndef ITGTDEF_KERHOOK_BEGCYCEXEC
#define ISA_KERHOOK_BEGCYCEXEC() 
#else
extern void kerHookBegCycExec(void);
#define ISA_KERHOOK_BEGCYCEXEC() kerHookBegCycExec()
#endif

/* Beginning of inputs hook */
#ifndef ITGTDEF_KERHOOK_BEGINP
#define ISA_KERHOOK_BEGINP() 
#else
extern void kerHookBegInp(void);
#define ISA_KERHOOK_BEGINP() kerHookBegInp()
#endif

/* End of inputs hook */
#ifndef ITGTDEF_KERHOOK_ENDINP
#define ISA_KERHOOK_ENDINP() 
#else
extern void kerHookEndInp(void);
#define ISA_KERHOOK_ENDINP() kerHookEndInp()
#endif

/* Beginning of outputs hook */
#ifndef ITGTDEF_KERHOOK_BEGOUT
#define ISA_KERHOOK_BEGOUT() 
#else
extern void kerHookBegOut(void);
#define ISA_KERHOOK_BEGOUT() kerHookBegOut()
#endif

/* End of outputs hook */
#ifndef ITGTDEF_KERHOOK_ENDOUT
#define ISA_KERHOOK_ENDOUT() 
#else
extern void kerHookEndOut(void);
#define ISA_KERHOOK_ENDOUT() kerHookEndOut()
#endif

/* No cycle execution hook */
#ifndef ITGTDEF_KERHOOK_NOCYCEXEC
#define ISA_KERHOOK_NOCYCEXEC() 
#else
extern void kerHookNoCycExec(void);
#define ISA_KERHOOK_NOCYCEXEC() kerHookNoCycExec()
#endif

/* End of cycle execution hook */
#ifndef ITGTDEF_KERHOOK_ENDCYCEXEC
#define ISA_KERHOOK_ENDCYCEXEC() 
#else
extern void kerHookEndCycExec(void);
#define ISA_KERHOOK_ENDCYCEXEC() kerHookEndCycExec()
#endif

/* On-line change saved hook */
#ifndef ITGTDEF_KERHOOK_ONLINECHANGESAVE
#define ISA_KERHOOK_ONLINECHANGESAVE() 
#else
extern void kerHookOnLineChangeSave(void);
#define ISA_KERHOOK_ONLINECHANGESAVE() kerHookOnLineChangeSave()
#endif

/* Failover diagnostics feature */
#ifndef ITGTDEF_FAILOVER
#define ISA_KERHOOK_FAILOVER_STARTUP()
#define ISA_KERHOOK_FAILOVER_SHUTDOWN()
#define ISA_KERHOOK_FAILOVER_SYNCDATA()
#define ISA_KERHOOK_FAILOVER_CHECKCRC()
#else
#define ISA_KERHOOK_FAILOVER_STARTUP() kerFailoverStartup()
#define ISA_KERHOOK_FAILOVER_SHUTDOWN() kerFailoverShutdown()
#define ISA_KERHOOK_FAILOVER_SYNCDATA() kerFailoverSyncData(cuStandbyIsAvailable)
#define ISA_KERHOOK_FAILOVER_CHECKCRC() kerFailoverCheckCRC()
#endif

#ifndef ITGTDEF_KERHOOK_BEGSCAN
#define ISA_KERHOOK_BEGSCAN();
#else
extern void kerHookBegScan(void);
#define ISA_KERHOOK_BEGSCAN() kerHookBegScan()
#endif


#endif   /* nested Headers management */
/* eof ********************************************************************/
