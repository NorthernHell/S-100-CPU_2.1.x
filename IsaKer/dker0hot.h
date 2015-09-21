/**************************************************************************
File:               dker0hot.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      14 November 2001
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#ifndef _DKER0HOT_H /* nested Headers management */
#define _DKER0HOT_H

/* constants **************************************************************/
/* Space backup parameter */
#define ISA_HOTBKP_KEEP       0
#define ISA_HOTBKP_ERASE      1

/* Compatibility level of SFC needed */
#define ISA_HOTCHK_COMP_LOW   0
#define ISA_HOTCHK_COMP_MID   1
#define ISA_HOTCHK_COMP_HIGH  2

/* Restoration method */
#define ISA_HOTRST_UNSAFE     0
#define ISA_HOTRST_SAFE       1


/* types ******************************************************************/
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint32               luVersion;     /*!< Hot restart version */

   uint32               luTgtDefOfs;   /*!< Target definition offset */

   uint32               luDtaInfoOfs;  /*!< Data info definition offset */
   uint32               luDtaOfs;      /*!< Data definition offset */

   uint32               luSymHdrOfs;   /*!< Symbol header definition offset */
   uint32               luSymOfs;      /*!< Symbol definition offset */

   uint32               luPouOfs;      /*!< POU definition offset */
   uint32               luPouNbr;      /*!< POU quantity */
   uint32               luPouSize;     /*!< POU definition size */

} strHotHeader;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   char     tcTargetName[16];          /*!< Value of TARGET_NAME macro */
   char     cByteOrder;                /*!< Value of INTEL or MOTOROLA macro */
   uint32   luIsaLoopSleep;            /*!< Value of ISA_LOOP_SLEEP macro */
   uint32   luIsaAlign;                /*!< Value of ISA_ALIGN macro */

} strHotTgtDef;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typVa       FirstSysVa;             /*!< First system variable address */
   typVa       LastSysVa;              /*!< Last system variable address */
   typVa       FirstStepVa;            /*!< First step variable address */
   typVa       LastStepVa;             /*!< Last step variable address */
   uint32      luSizeOfStep;           /*!< Size of a step */
   uint32      luStepNbr;              /*!< Quantity of step */
   typVa       FirstTrsVa;             /*!< First transition variable address */
   typVa       LastTrsVa;              /*!< Last transition variable address */
   typVa       FirstUserVa;            /*!< First user variable address */
   typVa       LastUserVa;             /*!< Last user variable address */
   uint32      luUserDataSize;         /*!< User data size */

} strDataInfo;


/* data *******************************************************************/

/* exported services from module dker0hot.c *******************************/

extern typSTATUS  kerHotInit(void);
extern void       kerHotExit(void);

extern uchar      kerHotBackup
   (
   uchar cuFailover,
   uchar cuBkpTgtDef,
   uchar cuBkpDta,
   uchar cuBkpSym,
   uchar cuBkpPou
   );

extern uchar      kerHotCheck(uchar, uint32*);
extern uchar      kerHotRealize(uchar, uchar, uint32*);
extern uchar      kerHotSave(char*);
extern uchar      kerHotLoad(char*);
extern uchar      kerHotDelete(char*);
extern void       kerHotGetDataSizeAndOffset(uint32*, uint32*);

#endif  /* nested Headers management */
/* eof ********************************************************************/
