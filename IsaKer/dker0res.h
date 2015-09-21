/**************************************************************************
File:               dker0res.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      19-December-1997
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Resource Configuration module tables access 
                     structures definitions and functions prototype

***************************************************************************
Modifications: (who / date / description)
---4.02 Released---
EDS/03-Feb-2000/ BUG 0711: Init Bool table no more accessed with struct
   BUG 0711: Removed strInitBool structure definition and resDefInitBool()
    now returns typVa* instead.

---4.03 Released---
EDS/18-Jul-2000/ resModulChk() no more use cuIsSimul param
   Removed no more used cuIsSimul param
EDS/25-Aug-2000/ Allow adding of variables in MDF
   Added resDefRdccModulId(), resRdbCrcCheck() & resMdfInit protos
   Removed resDefPouModulId() proto
   Added structs for on line modif update module tables

---4.12 Released---
VMO/12-June-2002/ SFC function block
   Added structs strDefSfcFblDesc & strDefPouRelLk.
   Added member to strDefFbl for SFC function block.
   Added resDefSfcFblDesc(), resDefPouRelLink() protos

---4.13 Released---
VMO/26-Mar-2002/ IOs online modification
   Added management of channel's OEM parameters
   Added management of IO's MDF
GM/3-Oct-2002/ Step by step debugging
   Added structures for step by step.

---5.00 Released---
OL/02-Feb-2005/ New data type
   Add TIC code for INT, LINT, USINT, USINT, UDINT, ULINT, LREAL and DATE.

---100.00.001 Released---
ED/18-Dec-2006
   Vantage - Enhanced online change support for retained variables.

***************************************************************************/
#ifndef _DKER0RES_H    /* nested Headers management */
#define _DKER0RES_H



/* constants **************************************************************/

/* types ******************************************************************/
/*
 * RESOURCE CONFIGURATION MODULE TABLES
 */
/**************************** DOXYGEN STRUCTURE ***************************/
/* Resource Configuration Main table */
typedef struct
{
   uint32  luResBlksAlloc;    /*!< Resource blocks allocation info table */
   uint32  luDefRes;          /*!< Resource parameters */
   uint32  luDefUsf;          /*!< Used 'C' functions description */  
   uint32  luDefFbl;          /*!< Used 'C' function blocks description */
   uint32  luDefCnv;          /*!< Used 'C' conversions description */
   uint32  luDefVar;          /*!< Variables definitions table */
   uint32  luInitVar;         /*!< Variables initialization table */ 
   uint32  luDefKvbDrv;       /*!< Binding table */
   uint32  luDefIo;           /*!< IOs table */
   uint32  luDefHie;          /*!< Project hierarchy table */
   uint32  luDefProg;         /*!< Programs definition */
   uint32  luDefRtn;          /*!< Retained variables */
   uint32  luAdi;             /*!< ADI table */
   uint32  luInterrupt;       /*!< Interrupt table */
   uint32  luFbInstInputInit; /*!< Function block instance input initialization table */
} strMain;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Resource Blocks Allocation table */
typedef struct
{
   uint16  huPouNbr;       /*!< Number of Pou */
   uint16  huDtaBlksNbr;   /*!< Number of data blks > 1 only if segmented */
   uint16  huPouSzsOfs;    /*!< Offset to Pou sizes list */
   uint16  huDtaBlkSzsOfs; /*!< Offset to data blks sizes list */
} strResBlksAlloc;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Resource parameters */
typedef struct
{
   uint16  huMaxNbWng;      /*!< Max Number of stored Warning */
   uint16  huStartMode;     /*!< Starting mode */
   uint16  huCycTimeTrig;   /*!< Trigger cycle time */
   uint16  huSfcEvoGain;    /*!< SFC dynamic evolution: gain parameter */
   uint16  huSfcEvoOfs;     /*!< SFC dynamic evolution: offset parameter */
   uint16  huOemOfs;        /*!< Offset to OEM extension parameters */
   uint32  luMdfBufSze;     /*!< Size of buffer for on line modifications */
   uint16  huMicroCycTimeTrig;  /*!< Microseconds trigger cycle time */
	uint16  huCycTimeBase;       /*!< Trigger cycle time in micro or milliseconds */
#ifdef ITGTDEF_ENH_ONLINE_CHANGE
   uint32  luMaxNbPous;     /*!< Maximum total number of POUs that can be added during online changes */
   uint32  luSfcFbExtraSize;  /*!< Maximum space available to backup SFC function block data before realizing online change */
#endif
} strDefRes;

#ifdef ITGTDEF_FAILOVER
typedef struct
{
   uint32 luFailoverDatalinkTimeoutMs; /*!< Timeout of the FAILOVER data link */
} strResOemParams;
#endif

/* Resource used 'C' functions description */
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huNbUsfStd;       /*!< Number of used standard usf */
   uint16  huNbUsf;          /*!< Number of used usf */
   uint16  huUsfStdDescOfs;  /*!< Offset to description list of used std usf */
   uint16  huUsfDescOfs;     /*!< Offset to description list of used usf */
} strDefUsf;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huUsfNum;         /*!< Usf number (1-->N) */
   uint16  huUsfNameOfs;     /*!< Offset to usf name */
} strDefUsfDesc;

/* Resource used 'C' function blocks description */
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huNbFblStd;       /*!< Number of used standard fbl*/
   uint16  huNbFbl;          /*!< Number of used fbl */
   uint16  huFblStdDescOfs;  /*!< Offset to description list of used std fbl */
   uint16  huFblDescOfs;     /*!< Offset to description list of used fbl */
   uint16  huNbSfcFbl;       /*!< Number of SFC function block */
   uint16  huSfcFblDescOfs;  /*!< Offset to description list of SFC fbl */
} strDefFbl;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huFblStdNum;      /*!< Standard fbl number */
   uint16  huFblStdNbInst;   /*!< Number of instances */
   uint32  luFblStdInstOfs;  /*!< Offset to instances list */
} strDefFblStdDesc;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint32  luFblNameOfs;     /*!< Offset to fbl Name */
   uint16  huFblNum;         /*!< Fbl number (1-->N) */
   uint16  huFblNbInst;      /*!< Number of instances */
   uint32  luFblInstOfs;     /*!< Offset to instances list */
} strDefFblDesc;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huPouNum;         /*!< Number of the POU */
   uint16  huSfcDynFactor;   /*!< SFC class dynamic evolution factor */
   uint16  huInstNbr;        /*!< Number of instance */
   uint16  huReserved;       /*!< Reserved (RFS 5070: bit 0 set indicates SFC FB is a basic IEC 61499 FB) */
   uint32  luSfcFblOffset;   /*!< Offset to the SFC function block instance list */
} strDefSfcFblDesc;

/* Resource used 'C' conversions description */
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huNbCnv;          /*!< Number of used conversion */
   uint16  huCnvDescOfs;     /*!< Offset to description list of used conversion */
} strDefCnv;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huCnvNum;         /*!< Cnv number (1-->N) */
   uint16  huCnvNameOfs;     /*!< Offset to conversion name */
} strDefCnvDesc;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Resource variables definitions */
typedef struct
{
   typVa   FirstVa;     /*!< First data resource used Va */
   typVa   LastVaLimit; /*!< Boundary of Last data resource used Va  */
   typVa   BlkOfStpVa;  /*!< Va on beginning of steps info variables */
   typVa   BlkOfTrsVa;  /*!< Va on beginning of transitions variables */
   uint32  luNbStp;     /*!< Number of steps in resource */
   uint32  luNbTrs;     /*!< Number of transitions in resource */
   /* parameters for step by step debuging */
   uint32  luCallStackDeepness;  /*!< Deepeness of the call stack */
   typVa   POUStatusVa;          /*!< VA of POU status array */
   typVa   SteppingInfoVa;       /*!< VA of stepping info */
   uint32  luSizeOfPOUStatusVa;  /*!< size of POU status array */
   uint32  luSizeOfSteppingInfoVa; /*!< size of stepping info variable */

} strDefVar;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Resource variables initialization tables */
typedef struct
{
   uint32  luTbInitBool;     /*!< Table add of booleans to init */
   uint32  luTbInitSint;     /*!< Table add of Sint, USINT to init */
   uint32  luTbInit32bit;    /*!< Table add of Dint,Real,Time, DATE vars to init */
   uint32  luTbInitStr;      /*!< Table add of strings to init */
   uint32  luTbInitMLenStr;  /*!< Table add of strings to init with max len */
   uint32  luTbInitBlk;      /*!< Table add of block of data (struct) to init */
   uint32  luNbInitCstBool;  /*!< Number of boolean constants to init */
   uint32  luNbInitBool;     /*!< Number of total booleans to init */
   uint32  luNbInitCstSint;  /*!< Number of Sint constants to init */
   uint32  luNbInitSint;     /*!< Number of total Sint vars to init */
   uint32  luNbInitCst32bit; /*!< Number of Dint,Real,Time constants to init */
   uint32  luNbInit32bit;    /*!< Number of total Dint,Real,Time vars to init */
   uint32  luNbInitCstStr;   /*!< Number of string constants to init */
   uint32  luNbInitStr;      /*!< Number of total strings to init */
   uint32  luNbInitMLenStr;  /*!< Number of strings to init with max len */
   uint32  luNbInitCstBlk;   /*!< Number of blk of data csts (struct) to init */
   uint32  luNbInitBlk;      /*!< Number of total blk of data (struct) to init */
   /* Following members added for new data types, Rdcc = 9 : */
   uint32  luTbInit16bit;    /*!< Table add of INT, UINT to init */
   uint32  luNbInitCst16bit; /*!< Number of INT, UINT constants to init */
   uint32  luNbInit16bit;    /*!< Number of total INT, UINT vars to init */
   uint32  luTbInit64bit;    /*!< Table add of LINT, ULINT, LREAL to init */
   uint32  luNbInitCst64bit; /*!< Number of LINT, ULINT, LREAL constants to init */
   uint32  luNbInit64bit;    /*!< Number of total LINT, ULINT, LREAL vars to init  */
#ifdef ITGTDEF_ENH_ONLINE_CHANGE
   uint32  luTbInitBoolF;    /*!< Table add of booleans to init to FALSE */
   uint32  luNbInitCstBoolF; /*!< Number of boolean constants to init to FALSE */
   uint32  luNbInitBoolF;    /*!< Number of total booleans to init to FALSE */
#endif
} strInitVar;

/* Better to use pointer typeed access regarding alignment constraints.
   No compatibility pbm, table was not aligned: BUG 0711
typedef struct
{
   typVa   VaToSet;*/     /*!< Variable to set */
/*
} strInitBool;
*/

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typVa   VaToInit;     /*!< Variable to initialize */
   char    cSintVal;     /*!< Sint value */

} strInitSint;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typVa   VaToInit;    /*!< Variable to initialize */
   uint32  lu32bitVal;  /*!< 32bit value */
} strInit32bit;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typVa   VaToInit;    /*!< Variable to initialize */
   uint16  lu16bitVal;  /*!< 16bit value */
} strInit16bit;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typVa   VaToInit;    /*!< Variable to initialize */
   uint64  lu64bitVal;  /*!< 64bit value */
} strInit64bit;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typVa   VaToInit;    /*!< Variable to initialize */
   uchar   cuLen;       /*!< Number of characters of initial string */
} strInitStr;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typVa   VaToInit;    /*!< Variable to initialize */
   uint32  luNbElmt;    /*!< Number of elements for arrays (simple type=1) */
   uchar   cuMLen;      /*!< Max number of reserved char of str variable */
} strInitMLenStr;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typVa   VaToInit;    /*!< Variable to initialize */
   uint32  luBlkDtaSze; /*!< Block of data size */
   uint32  luBlkDtaOfs; /*!< Offset to block of data value */
   uint32  luNbOccur;   /*!< Number of occurrences >=1 (arrays) */
} strInitBlk;

/* Resource IOs tables */
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint32  luTbDefIoDrv;      /*!< Table add of drivers description */
   uint32  luTbDefIoCpxDvc;   /*!< Table add of complex devices description */
   uint32  luTbDefIoSplDvc;   /*!< Table add of simple devices description */
   uint32  luTbDefIoChan;     /*!< Table add of channels description */
   uint16  huNbVirtualDrv;    /*!< Number of driver in virtual */
   uint16  huNbLev1Dvc;       /*!< Number of level 1 devices */
   uint16  huNbSplDvcR;       /*!< Number of simple devices in read (input) */
   uint16  huNbSplDvcW;       /*!< Number of simple devices in write (output) */
} strDefIo;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huNbIoDrv;         /*!< Number of drivers */
   uint16  huDfIoDrvOfs;      /*!< Offset to the definition of drivers */
} strDfIoDrvH;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huNbIoCpxDvc;      /*!< Number of complex devices */
   uint16  huDfIoCpxDvcOfs;   /*!< Offset to the definition of complex devices */
} strDfIoCpxDvcH;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huNbIoSplDvc;      /*!< Number of simple devices */
   uint16  huDfIoSplDvcOfs;   /*!< Offset to the definition of simple devices */

} strDfIoSplDvcH;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typVa   NbIoVa;            /*!< Number of IO variables */
   uint16  huDfIoChanOfs;     /*!< Offset to the definition of channels */
   uint16  huDfIoChanOemOfs;  /*!< Offset to the OEM param of channels */
} strDfIoChanH;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint32  luChanOemOfs;   /*!< Offset to OEM param of first channel */
   uint16  huChanOemSize;  /*!< Size of OEM param */
   uint16  huReserved;     /*!< Reserved */
} strDfIoChanOemH;


/* Resource Project hierarchy table */
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huNbCycBfSfc; /*!< Number of cyclic programs to exec before SFC */
   uint16  huNbCycAfSfc; /*!< Number of cyclic programs to exec after SFC */
   uint16  huNbSfcMain;  /*!< Number of SFC main programs */
   uint16  huNbSfcChild; /*!< Number of SFC child programs */
   uint16  huNbFunct;    /*!< Number of Functions */
   uint16  huSfcHieOfs;  /*!< Offset to SFC hierachy list */
} strDefHie;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typVa   SfcPouVa;      /*!< Sfc POU variable */
   uint16  huSfcPouLevel; /*!< Sfc POU hierarchy level */
} strDefHieSfc;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Resource Programs definition */
typedef struct
{
   uint16  huType;         /*!< Pou type (Cyclics, SFC, ...) */
   uint16  huLevel;        /*!< Pou hierarchy level */
#ifdef ITGTDEF_INTERRUPT
   uint16  huIntrStatus;   /*!< Interrupt status */
#endif
} strDefProg;

/* Retained variables tables */
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint32  luRtnCrc;          /*!< Retain variables CRC */
   char    tcRtnMemDesc[128]; /*!< Memory description */
   typVa   NbRtnBlkVa;        /*!< Number of blocks in retain */
   uint16  huRtnBlkOfs;       /*!< Offset to blocks of data list */
} strDefRtn;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typVa  RtnBlkIdVa;   /*!< Identifier of block */
   typVa  RtnBlkVa;     /*!< Va of block of data in retain */
   typVa  RtnBlkSzeVa;  /*!< Size of block of data in retain */
} strDefRtnBlk;


/*
 * ON LINE MODIF UPDATE MODULE TABLES
 */
/**************************** DOXYGEN STRUCTURE ***************************/
/* Upd Main table */
typedef struct
{
   uint16 huMdfCptyIndex;  /*!< Compatibility index */
   uint16 huNbTbEntries;   /*!< Number of table entries */
   uint16 huTbUpdFblStd;   /*!< Table add of new standard function blocks */
   uint16 huTbUpdInitVar;  /*!< Table add of new variables to initialize */
   uint16 huTbUpdIoParam;  /*!< Table Mdf of IO parameters*/
#ifdef ITGTDEF_ENH_ONLINE_CHANGE
   uint16 huTbUpdRecipe;         /*!< Table containing a recipe to set the value of relocated data */
   uint16 huTbUpdModifiedSFC;    /*!< Table Mdf of Modified SFC programs */
   uint16 huTbUpdModifiedSFCFB;  /*!< Table Mdf of Modified SFC function blocks */
#endif
} strUpdMain;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Upd new standard function blocks description */
typedef struct
{
   uint16 huNbFblSIniCla;   /*!< Number of std fbl to initialize class */
   uint16 huFblSIniClaOfs;  /*!< Offset to description of classes to init */
   uint16 huNbFblSIniIns;   /*!< Number of std fbl to initialize instance */
   uint16 huFblSIniInsOfs;  /*!< Offset to description of instances to init */
} strUpdFblStd;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Upd IO parameters */
typedef struct
{
   uint16 huNbIoDrv;       /*!< Number of IO driver modified */
   uint16 huIoDrvOfs;      /*!< Offset to first driver modified */
   uint16 huNbIoCpxDvc;    /*!< Number of IO complex device modified */
   uint16 huIoCpxDvcOfs;   /*!< Offset to first complex device modified */
   uint16 huNbIoSplDvc;    /*!< Number of IO simple device modified */
   uint16 huIoSplDvcOfs;   /*!< Offset to first simple device modified */
} strUpdIoParam;

#ifdef ITGTDEF_ENH_ONLINE_CHANGE
/**************************** DOXYGEN STRUCTURE ***************************/
/* Upd recipe header */
typedef struct
{
   uint32   luNbEntries;      /*!< Number of entries in the recipe table */
} strUpdRecipe;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Upd recipe element */
typedef struct
{
   uint32   luSrcVa;          /*!< Address of the source */
   uint32   luDstVa;          /*!< Address of the destination */
   uint32   luSize;           /*!< Size of the data (non string) to be relocated */
   uchar    cuDstStrMaxSize;  /*!< Max size of the destination string */
   uchar    cuInitOnly;       /*!< TRUE to init Dst only */
} strUpdRecipeEntry;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Upd SFC restore header */
typedef struct
{
   uint32   luNbEntries;      /*!< Number of entries in the table (SFC programs to restore) */
} strUpdRestoreSFC;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Upd SFC restore element */
typedef struct
{
   uint16   huPrevPouNum;     /*!< Old POU number of the SFC program */
   uint16   huNewPouNum;      /*!< New POU number of the SFC program */
} strUpdRestoreSFCEntry;
#endif

#ifdef ITGTDEF_ENH_ONLINE_CHANGE
/**************************** DOXYGEN STRUCTURE ***************************/
/* Upd SFC FB restore header */
typedef struct
{
   uint16   huNbEntries;      /*!< Number of entries in the table (SFC function blocks to restore) */
   uint16   huClassOfs;       /*!< Offset to class list */
} strUpdRestoreSFCFB;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Upd SFC FB restore element */
typedef struct
{
   uint16   huPrevClassNum;   /*!< Old class number of the SFC function block */
   uint16   huNewClassNum;    /*!< New class number of the SFC function block */
   uint16   huNbInst;         /*!< Number of instances of the SFC function block */
   uint32   luInstOfs;        /*!< Offset to instances list */
} strUpdRestoreSFCFBEntry;
#endif

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16 huIndex;         /*!< Index of driver modified in __DEFIO_DRV */
   uint16 huReserved;      /*!< Reserved */
   uint32 luMdfType;       /*!< Online modification type to realize */
} strUpdIoDrv;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16 huIndex;         /*!< Index of complex dev modified in __DEFIO_CPXDVC */
   uint16 huReserved;      /*!< Reserved */
   uint32 luMdfType;       /*!< Online modification type to realize */
} strUpdIoCpxDvc;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16 huIndex;         /*!< Index of simple dev modified in __DEFIO_SPLDVC */
   uint16 huReserved;      /*!< Reserved */
   uint32 luMdfType;       /*!< Online modification type to realize */
} strUpdIoSplDvc;


/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16 huFblStdNum;     /*!< Standard fbl number to initialize class */
   uint16 huFblStdNbInst;  /*!< Number of instances */
} strUpdFblSIniCla;

typedef strDefFblStdDesc strUpdFblSIniIns; /*!< Std fbl to init instances */

/* Upd new variables initialization tables */
typedef strInitVar strUpdInitVar;
typedef strInitSint strUpdInitSint;
typedef strInit32bit strUpdInit32bit;
typedef strInit16bit strUpdInit16bit;
typedef strInit64bit strUpdInit64bit;
typedef strInitStr strUpdInitStr;
typedef strInitMLenStr strUpdInitMLenStr;
typedef strInitBlk strUpdInitBlk;


/*
 * POU MODULE TABLES
 */
/**************************** DOXYGEN STRUCTURE ***************************/
/* Pou Main table */
typedef struct
{
   uint32  luPouLk; /*!< SFC link table (0 if Cyclic Or Funct pgm) */
   uint32  luPouCd; /*!< Program Code table */
   uint32  luPouStepData;  /*!< POU stepping data */
   uint32  luPouRelLk;     /*!< SFC relative link table for SFC fbl */
} strPouMain;

/* Pou SFC Links table */
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typVa   FstTrsVa; /*!< First transition variable identifier */
   typVa   FstStpVa; /*!< First Step variable identifier */
   uint16  huNbTrs;  /*!< Number of transitions */
   uint16  huNbStp;  /*!< Number of steps */
   uint16  huStpLkOfs; /*!< Offset to stps links (successor/predecessor) */
   uint16  huTrsLkOfs; /*!< Offset to trss links (successor/predecessor) */
} strDefPouLk;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huPrevTrsOfs; /*!< Offset to step list of trs predecessors */
   uint16  huNextTrsOfs; /*!< Offset to step list of trs successors */
} strDefStpLk;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huPrevStpOfs; /*!< Offset to trs list of step predecessors */
   uint16  huNextStpOfs; /*!< Offset to trs list of step successors */
} strDefTrsLk;

/* Pou Code table */
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huStpCdOfs; /*!< Offset to steps code (Cyclic/Funct Pgm=One step) */
   uint16  huTrsCdOfs; /*!< Offset to transitions Code */
} strDefPouCd;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
#ifdef ITGTDEF_BIGPOUS
   uint32  huBegSeqOfs; /*!< Offset to Stp BEGIN, or CYCLIC/FCT, Tic sequence */
   uint32  huBegBlkSze; /*!< Size of Stp begin, or Cyc/Fct, block of Tic seq. */
   uint32  huRepSeqOfs; /*!< Offset to Stp REPETITIVE Tic sequence */
   uint32  huRepBlkSze; /*!< Size of Stp repetitive block of Tic seq. */
   uint32  huEndSeqOfs; /*!< Offset to Stp END Tic sequence */
   uint32  huEndBlkSze; /*!< Size of Stp end block of Tic seq. */
#else
   uint16  huBegSeqOfs; /*!< Offset to Stp BEGIN, or CYCLIC/FCT, Tic sequence */
   uint16  huBegBlkSze; /*!< Size of Stp begin, or Cyc/Fct, block of Tic seq. */
   uint16  huRepSeqOfs; /*!< Offset to Stp REPETITIVE Tic sequence */
   uint16  huRepBlkSze; /*!< Size of Stp repetitive block of Tic seq. */
   uint16  huEndSeqOfs; /*!< Offset to Stp END Tic sequence */
   uint16  huEndBlkSze; /*!< Size of Stp end block of Tic seq. */
#endif
} strDefStpCd;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
#ifdef ITGTDEF_BIGPOUS
   uint32 huTrsSeqOfs; /*!< Offset to Trs Tic sequence */
   uint32 huTrsBlkSze; /*!< Size of Trs block of Tic seq. */
#else
   uint16 huTrsSeqOfs; /*!< Offset to Trs Tic sequence */
   uint16 huTrsBlkSze; /*!< Size of Trs block of Tic seq. */
#endif
} strDefTrsCd;

/* Pou Stepping table */

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huStpDscOfs; /*!< Offset to steps description (Cyclic/Funct Pgm=One step) */
                        /*!< (points to a strDefStpStep structure) */
   uint16  huTrsDscOfs; /*!< Offset to transitions Description */
} strDefPouStep;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
#ifdef ITGTDEF_BIGPOUS
   uint32  huBegStpBlkOfs; /*!< Offset to step blocks for begin action or cyclic program*/
   uint32  huBegStpBlkNbr; /*!< Number of step blocks */
   uint32  huRepStpBlkOfs; /*!< Offset to step blocks for complex action */
   uint32  huRepStpBlkNbr; /*!< Number of step blocks */
   uint32  huEndStpBlkOfs; /*!< Offset to step blocks for end action */
   uint32  huEndStpBlkNbr; /*!< Number of step blocks */
#else
   uint16  huBegStpBlkOfs; /*!< Offset to step blocks for begin action or cyclic program*/
   uint16  huBegStpBlkNbr; /*!< Number of step blocks */
   uint16  huRepStpBlkOfs; /*!< Offset to step blocks for complex action */
   uint16  huRepStpBlkNbr; /*!< Number of step blocks */
   uint16  huEndStpBlkOfs; /*!< Offset to step blocks for end action */
   uint16  huEndStpBlkNbr; /*!< Number of step blocks */
#endif
} strDefStpStep;

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16  huStpBlkOfs; /*!< Offset to step blocks for transition */
   uint16  huStpBlkNbr; /*!< Number of step blocks */
} strDefTrsStep;

#define ISA_DBG_STEP_FLAG_BKP_SET (0x01)/* Break point was set */

/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct /* Step definition block */
{
#ifdef ITGTDEF_BIGPOUS
   uint32  huStpOfs;       /*!< Offset of the step in TIC code */ 
#else
   uint16  huStpOfs;       /*!< Offset of the step in TIC code */ 
#endif
   uchar   cuOperandNbr;   /*!< Number of operands */
   uchar   cuStepFlags;    /*!< Step flags used internaly by the target (ISA_DBG_STEP_FLAG_xxx) */
   typVa   TICCode;        /*!< Original TIC code */ 
}strDefStep;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Pou SFC Relative Links table for SFC function blocks */
typedef struct
{
   uint32  luFstTrsOfs; /*!< Offset to First transition variable identifier */
   uint32  luFstStpOfs; /*!< Offset to First Step variable identifier */
   uint16  huNbTrs;     /*!< Number of transitions */
   uint16  huNbStp;     /*!< Number of steps */
   uint16  huStpLkOfs;  /*!< Offset to stps links (successor/predecessor) */
   uint16  huTrsLkOfs;  /*!< Offset to trss links (successor/predecessor) */
} strDefPouRelLk;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Interrupt table header */
typedef struct  
{
   uchar cuNbEntries;            /*!< Number of entries in the table */
   uchar cuOffsetToFirstEntry;   /*!< Offset to the first entry */
} strInterruptHdr;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Interrupt table entries */
typedef struct  
{
   uchar  cuIntrNo;              /*!< Interrupt number */
   uint16 huIntrPouNum;          /*!< POU number of the program associated to the interrupt */
   typVa  IntrVa;                /*!< VA of the interrupt variable */
} strInterrupt;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Function block instance input init table header */
typedef struct
{
   uint32   luNbEntries;            /*!< Number of entries in the table */
   uchar    cuOffsetToFirstEntry;   /*!< Offset to the first entry */
} strFbInstInputInitHdr;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Function block instance input init table entries */
typedef struct
{
   typVa InstInputParamVa; /*!< Instance input Va */
   typVa ValueVa;          /*!< Value Va */
} strFbInstInputInit;

/* data *******************************************************************/

/* exported services from module dker0res.c *********************************/
extern void resDefInit(void* pvConfAdd); 
extern void resMdfInit(void* pvConfAdd);
extern strRdccModulId* resDefConfRdccModulId(void);
extern strRdccModulId* resDefRdccModulId
   (
   uchar*  pcuIsModified,
   uint32* pluRdbCrcOrigin,
   uint32* pluRdbCrcLatest
   );

extern char* resDefName(void);
extern uint16 resDefPouNbr(void);
extern uint16 resDefDtaBlkNbr(void);
extern uint32* resDefPouSizes(void);
extern uint32* resDefDtaSizes(void);
extern uchar resDefMaxNbWng(void);
extern uint16 resDefStartMode(void);
extern uint16 resDefCycTimeTrig(void);
#ifdef ITGTDEF_MICRO_CYC_TIME /* RFS 7891 */
extern uint16 resDefMicroCycTimeTrig(void);
extern uint16 resDefCycTimeBase(void);
#endif
extern uint16 resDefSfcEvoDynInfo(uint16*);
extern void* resDefResXParam(void);
extern uint32 resDefMdfBufSze(void);
extern uchar* resDefUsf(void);
extern uint16* resDefUsfStdDesc (uint16* phuNbUsfStd);
extern strDefUsfDesc* resDefUsfDesc (uint16* phuNbUsf);
extern uchar* resDefFbl(void);
extern strDefFblStdDesc* resDefFblStdDesc (uint16* phuNbFblStd);
extern strDefFblDesc* resDefFblDesc (uint16* phuNbFbl);
extern strDefSfcFblDesc* resDefSfcFblDesc (uint16* phuNbSfcFbl);
extern uchar* resDefCnv(void);
extern strDefCnvDesc* resDefCnvDesc (uint16* phuNbCnv);
extern uint32 resDefNbStep(void);
extern uint32 resDefNbTrans(void);
extern typVa resDefBlkOfStpVa(void);
extern typVa resDefBlkOfTrsVa(void);
extern typVa resDefFirstVa(void);
extern typVa resDefLastVaLimit(void);
extern strDefVar *resDefVarGet(void);
extern typVa* resDefInitBool
   (
   uint32* pluNbInitCstBool,
   uint32* pluNbInitBool
   );
#ifdef ITGTDEF_ENH_ONLINE_CHANGE
extern typVa* resDefInitBoolF
   (
   uint32* pluNbInitCstBoolF,
   uint32* pluNbInitBoolF
   );
#endif
extern strInitSint* resDefInitSint
   (
   uint32* pluNbInitCstSint,
   uint32* pluNbInitSint
   );

extern strInit32bit* resDefInit32bit
   (
   uint32* pluNbInitCst32bit, 
   uint32* pluNbInit32bit
   );

extern strInit16bit* resDefInit16bit
   (
   uint32* pluNbInitCst16bit, 
   uint32* pluNbInit16bit
   );

extern strInit64bit* resDefInit64bit
   (
   uint32* pluNbInitCst64bit, 
   uint32* pluNbInit64bit
   );

extern strInitStr* resDefInitStr
   (
   uint32* pluNbInitCstStr,
   uint32* pluNbInitStr
   );

extern strInitMLenStr* resDefInitMLenStr(uint32* pluNbInitMLenStr);

extern strInitBlk* resDefInitBlk
   (
   uint32* pluNbInitCstBlk,
   uint32* pluNbInitBlk
   );


extern void* resDefKvbDrv(void);
extern uint16 resDefIoNbVirtDrv(void);
extern uint16 resDefIoNbLev1Dvc(void);
extern uint16 resDefIoNbSplDvcR(void);
extern uint16 resDefIoNbSplDvcW(void);
extern uchar* resDefIoDrvH(void);
extern void* resDefIoDrv(uint16* phuNbIoDrv);
extern uchar* resDefIoCpxDvcH(void);
extern void* resDefIoCpxDvc(uint16* phuNbIoCpxDvc);
extern uchar* resDefIoSplDvcH(void);
extern void* resDefIoSplDvc(uint16* phuNbIoSplDvc);
extern void* resDefIoChan(typVa* pNbIoVa);
#ifdef ITGTDEF_IOCHANOEM
extern void* resDefIoChanOem(uint16 huIoSplDvcNb, uint16* phuChanOemSize);
#endif
extern strDefHieSfc* resDefHieSfc(void);
extern uint16 resDefHieNbProg(uchar cuType);
extern uchar resDefPouLevel(uint16 huPouNum);
extern strDefRtn* resDefRtn (void);
extern strDefRtnBlk* resDefRtnBlks(void);

extern strDefPouLk* resDefPouLink
   (
   uint16 huPouNum  /* In: Pou Number */ 
   );               /* Returns: */
                    /*  Prog Link table for SFC pou */
                    /*  Zero for Cyclic/Funct pou and SFC fbl pou or if pou doesn't exist */

extern strDefPouCd* resDefPouCode   
   (
   uint16 huPouNum  /* In: Pou Number */ 
   );               /* Returns: Prog Code table, Zero if pou doesn't exist */

extern strDefPouRelLk* resDefPouRelLink
   (
   uint16 huPouNum  /* In: Pou Number */ 
   );               /* Returns: */
                    /*  Prog Relative Link table for SFC sfc pou */
                    /*  Zero for non SFC fbl pou ans SFC pou or if pou doesn't exist */

extern uchar resRdbCrcCheck
   (
   uint32 luRdbCrc,   /* In: Resource data crc to check */
   uchar  cuDoNewAlso /* In: True check also with possible pending new crc */
   );                 /* Returns: TRUE if crc is valid, FALSE else */

extern typSTATUS resModulChk 
   (
   void*  pvModulAdd,     /* In: Module to check */
   uint32 luModulSz,      /* In: Size of module to check */
   char*  psModulNm,      /* In: Name of module to check */
   uchar  cuDoConfMatch   /* In: If true, test that conf matches */
   );                     /* Returns: 0 if successful, BAD_RET if error */

extern uint32 resCrcCalculate
   (
   void*   pvDataAdd,  /* In: Data to calculate crc from */ 
   uint32  luDataSze   /* In: Size of Data */ 
   );                  /* Returns: Calculated crc */

#ifdef ITGTDEF_BINDIMPROVE2
extern void resDefKvbDrvSet
   (
   void* pvConfAdd     /* In: Config table address */
   );
#endif

#ifdef ITGTDEF_NEW_ARRAY_AND_FB
extern void* resAdi(void);
extern strFbInstInputInit* resFbInstInputInit
   (
   uint32 *pluNbEntries /* Out: Number of entries in the instance input initialization table */ 
   );                   /* Returns: Pointer to the first element in the table */
#endif

#ifdef ITGTDEF_INTERRUPT
extern strInterrupt* resInterrupt
   (
   uchar *pcuNbEntries  /* Out: Number of entries in the interrupt table */ 
   );

extern uint16 resDefPouIntrStatus
   (
   uint16 huPouNum      /* In: POU number */
   );
#endif /* ITGTDEF_INTERRUPT */

#ifdef ITGTDEF_ENH_ONLINE_CHANGE
extern uint16 resDefMaxNbPous(void);
extern void *resDefGetConf(void);
extern uint32 resDefSfcFbBackupSize(void);
extern void resDefRtnSet(void* pvConfAdd); /* RFS8262 */
#endif

#endif /* nested Headers management */ 
/* eof ********************************************************************/
