/**************************************************************************
File:               dker0mdf.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      21-October-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Kernel: On line modif management

***************************************************************************
Modifications: (who / date / description)
EDS/25-Aug-2000/ Allow adding of variables in MDF
   Added XXX_DLTTYP_YYY new delta types
   Added strMdfDltCrcH struct of header in delta of resource data CRC 
   Added mdfRdbCrcAdd() & mdfRdbCrcCheck() proto
   Added mdfRVarCstSet() proto

---4.12 Released---
VMO/26-Mar-2002/ IOs online modification
   Added ISA_MDF_IO_xxx new IOs MDF types

***************************************************************************/
#ifndef _DKER0MDF_H /* nested Headers management */
#define _DKER0MDF_H

/* constants **************************************************************/
/* Type of action for mdf loading */
#define ISA_MDF_CREATE    1
#define ISA_MDF_LOAD      2
#define ISA_MDF_PROMLINK  3

/* Type of delta(s) */
#define ISA_MDF_DLTTYP_POU 1
#define ISA_MDF_DLTTYP_CST 2
#define ISA_MDF_DLTTYP_CNF 3
#define ISA_MDF_DLTTYP_UPD 4
#define ISA_MDF_DLTTYP_CRC 5


/* types ******************************************************************/
/**************************** DOXYGEN STRUCTURE ***************************/
/* Delta header */
typedef struct _s_MdfDlt
{
   uchar  cuType;          /*!< Type of delta (pou,...) */
   uchar  cuUpdDone;       /*!< Update done for this delta */
   uchar  cuIsToRemove;    /*!< Set if delta needs to be removed during swap */
   uchar  cuReserved;
   uint16 huParam;         /*!< Delta extra parameter */
   uint16 huIdNum;         /*!< Delta Identifer */
   uint32 luDataSize;      /*!< Size of useful data in delta */
   uint32 luTotSize;       /*!< Total size of delta (include header+align) */
   struct _s_MdfDlt* pNxMdfDlt; /*!< Next delta */
} strMdfDlt;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Mdf Space header */
typedef struct
{
   void*       pvMdfSpcAdd;  /*!< Address of space, for virtual add mngmt */
   uint32      luDltHderSz;  /*!< Size of header of a delta */
   uint32      luFreeMemSz;  /*!< Amout of free memory in spc */
   uint16      huNbDltInUse; /*!< Number of delta already in use */
   uint16      huNbDltNxMdf; /*!< Number of delta for next realize mdf */
   void*       pvFreeMem;    /*!< Free memory address */
   strMdfDlt*  pLHInUse;     /*!< Head of list of delta(s) in use */
   strMdfDlt*  pLQInUse;     /*!< Queue of list of delta(s) in use */
   strMdfDlt*  pLHNxMdf;     /*!< Head of list of delta(s) for next modif */
   strMdfDlt*  pLQNxMdf;     /*!< Queue of list of delta(s) for next modif */
} strMdfHeader;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Delta of res data crc header */
typedef struct
{
   uint16 huNbRdbCrc;       /*!< Number of res data crc */
   uint16 huRdbCrcLstOfs;   /*!< Offset to list of res data crc */
   uint16 huReserved;       /*!< Reserved field */
   uint16 huDltCrcVers;     /*!< Version of format of delta of crc */
   char   tcDltCrcName[16]; /*!< Name of delta of crc */
} strMdfDltCrcH;

/* data *******************************************************************/

/* exported services from module dker0mdf.c *******************************/
extern typSTATUS mdfStartup
   (
   uint16 huSlaveNum  /* In: Slave number */ 
   );                 /* Returns: 0 if successful, BAD_RET if error */

extern void mdfExit
   (
   uint16 huSlaveNum  /* In: Slave number */ 
   );

extern uint32 mdfSpcSize
   (
   void* pvMdfSpcAdd  /* In: Addr of allocated space, 0 to just get size */ 
   );                 /* Returns: Size that mdf space must have */

extern typSTATUS mdfLoad
   (
   uchar cuActType,   /* In: Type of action: Create - Load */ 
   void* pvMdfSpcAdd  /* In: Mdf Space */ 
   );                 /* Returns: 0 if successful, BAD_RET if error */

extern void mdfUnload(void);
extern strRdccModulId* mdfRdccModulId(void); /* Returns: Addr of mdf module id */

extern uint16 mdfDltNew
   (
   uchar  cuDltType,  /* In: Type of delta */ 
   uint16 huDltParam, /* In: Delta extra param */ 
   uint32 luDataSize  /* In: Delta data size */ 
   );                 /* Returns: New delta identifier, zero if error */

extern void* mdfDltGet
   (
   uint16  huIdNum,   /* In: Delta identifier */ 
   uint32* luDataSize /* Out: Delta data size */ 
   );                 /* Returns: Delta data addr, zero if Id not found */

extern void mdfClean(void);

extern typSTATUS mdfRdbCrcAdd
   (
   uint32 luRdbCrc  /* In: Resource data crc to add */
   );               /* Returns: 0 if successful, BAD_RET if error */

extern uchar mdfRdbCrcCheck
   (
   uint32 luRdbCrc,   /* In: Resource data crc to check */
   uchar  cuDoNewAlso /* In: True check also with possible pending new crc */
   );                 /* Returns: TRUE if crc is valid, FALSE else */

extern typSTATUS mdfDltAccept(void); /* Returns: 0 if successful, BAD_RET if error */
extern void mdfRVarCstSet(void);
extern uint32 mdfSave(void); /* Returns: Mdf space part size to save (0 if no modif) */
extern uchar mdfIsDeltaAvi(void); /* Returns: TRUE if modif are in use, FALSE else */

#ifdef ITGTDEF_ENH_ONLINE_CHANGE
extern void mdfStrMLenSet(void);
#endif

#endif  /* nested Headers management */
/* eof ********************************************************************/
