/**************************************************************************
File:               dker0ldg.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      18-December-1997
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Kernel Resource loading basic fucntions Prototypes
                    and definitions

***************************************************************************
Modifications: (who / date / description)
---4.03 Released---
EDS/25-Aug-2000/ Allow adding of variables in MDF
   Added ldgPouMdfSet() & modified ldgPouGet() proto (to manage modified pous)

***************************************************************************/
#ifndef _DKER0LDG_H    /* nested Headers management */
#define _DKER0LDG_H



/* constants **************************************************************/
#define ISA_LDG_SPCCREATE    1
#define ISA_LDG_SPCLOAD      2

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module dker0ldg.c *******************************/
extern void ldgStartup(void);
extern void ldgExit(void);

extern typSTATUS ldgConfLoad 
   (
   uchar    cuActType,  /* Type of action */ 
   uint32   luSize      /* Spc size when creation*/ 
   );

extern void* ldgConfGet
   (
   uint32* pluSize  /*Out: Size of space */
   );

extern typSTATUS ldgPouLoad
   (
   uchar    cuActType  /* Type of action */
   );

extern void ldgPouMdfSet
   (
   uint16 huPouNum,   /* In: Pou number */ 
   void*  pvPouAddr   /* In: Pou module address */ 
   );

extern strRdccModulId* ldgPouGet
   (
   uint16  huPouNum,     /* In: Pou number */ 
   uint32* pluPouSize,   /* Out: Size of specified Pou module */
   uchar*  pcuIsModified /* Out: TRUE if it is a modified Pou */
   );                    /* Returns: Addr of Pou module if available, 0 else */

extern typSTATUS ldgMdfLoad
   (
   uchar cuActType  /* Type of Action */ 
   );

extern typSTATUS ldgMdfAccept
   (
   uint32 luSaveOpt  /* Save Options */ 
   );
extern typSTATUS ldgMdfSave(void);

extern typSTATUS ldgRLink
   (
   uint32 luSaveOpt  /* Save Options */ 
   );

extern typSTATUS ldgRSave
   (
   uint32 luSaveOpt  /* Save options */ 
   );

extern typSTATUS ldgOpMdInit
   (
   uchar   cuDsaType,   /* Type of Opt Module */ 
   uint32  luDsaSize    /* Size of Opt Module */
   );

extern uint32 ldgOpMdGet
   (
   uchar    cuDsaType   /* In:  Type of Opt Module */ 
   ); 

extern typSTATUS ldgRDtaLoad
   (
   uint16 huSlaveNum,   /* In: Slave Number */ 
   uint32* pluKpvRDSzs  /* In: Kernel Private data memory block sizes */ 
   );

extern typSTATUS ldgKpvRDGet
   (
   uint32* pluKpvRDSzs, /* In:  Kernel Private data memory block sizes */ 
   strKpvrd* pKpvRD     /* Out: Kernel Private data memory block addresses */ 
   );

extern void ldgKpvRDTbGet
   (
   uint32* pluKpvRDSzs, /* In:  Kernel Private data memory block sizes */ 
   void**  ppvKpvRDPtrs /* Out: Kernel Private data memory block addresses */ 
   );

extern void ldgRCleanUp(void);

extern void ldgPouMdfBackupRestore
   (
   uchar cuIsBackup
   );

#endif /* nested Headers management */ 
/* eof ********************************************************************/
