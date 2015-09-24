/**************************************************************************
File:               dker0bkp.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      15-March-2000 ---4.03 Released---
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Kernel sfc breakpoints management

***************************************************************************
Modifications: (who / date / description)


***************************************************************************/
#ifndef _DKER0BKP_H /* nested Headers management */
#define _DKER0BKP_H

/* constants **************************************************************/
/* Type of breakpoint */
#define ISA_BKP_STPBEG   1   /* Bkp on sfc step activation */
#define ISA_BKP_STPEND   2   /* Bkp on sfc step deactivation */
#define ISA_BKP_TRA      3   /* Bkp on sfc transition */

/* Return codes */
/* -1 reserved for BAD_RET */
#define ISA_BKP_RET_BADTYPE    -2 /* Unknown bkp type */
#define ISA_BKP_RET_ALREADYSET -3 /* A bkp is already set on step/trans */
#define ISA_BKP_RET_TOOMANYBKP -4 /* Max number of bkp is reached */

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module dker0bkp.c *******************************/
extern uint32 kerBkpSfcSize(void); /* Returns: Mem size for sfc bkp mngmt */

extern void kerBkpSfcInit
   (
   void* pvBkpSfcBlkAdd /* In: Memory block to manage sfc breakpoints */
   );

extern int16 kerBkpSfcSet
   (
   typVa StpTrsVa,    /* In: Va of step or transition to put bkp on */
   uchar cuBkpSfcType /* In: Type of sfc breakpoint to set */
   );                 /* Returns: 0 if successful, ret code < 0 if error */

extern void kerBkpSfcRemove
   (
   typVa StpTrsVa    /* In: Va of stp/tra to remove bkp from, 0=all sfc bkp */
   );

extern uchar kerBkpSfcBreak
   (
   typVa* TicBkp,    /* In: Breakpoint tic */
   strCallContext*   /* In: Context of the calling thread/task*/
   );                /* Returns: TRUE if tra bkp already met & recep is true */

#ifdef ITGTDEF_ENH_ONLINE_CHANGE
extern void kerBkpSfcBackup(void);

extern typSTATUS kerBkpSfcRestore
   (
   uint16 huNewPouNum,
   uint16 huOldPouNum,
   uchar cuIsFb
   );
#endif

#ifdef ITGTDEF_ENH_ONLINE_CHANGE
extern typSTATUS kerBkpSfcFbRestore
   (
   uint16 huNewPouNum,
   uint16 huOldPouNum
   );

extern void kerBkpResetCleanupFlag(void);
#endif

#endif  /* nested Headers management */
/* eof ********************************************************************/
