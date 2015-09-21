/**************************************************************************
File:               dker0pdf.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      29-January-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        High level Programs management & definitions

***************************************************************************
Modifications: (who / date / description)
---4.03 Released---
EDS/25-Aug-2000/ Allow adding of variables in MDF
   Removed pdfModulIdXxx() proto and corresponding fields of strPdf

***************************************************************************/
#ifndef _DKER0PDF_H    /* nested Headers management */
#define _DKER0PDF_H



/* constants **************************************************************/

/* types ******************************************************************/
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uchar           cuStatus;     /*!< Pou Status */
   uchar           cuReserved;   /*!< Reserved */
   void*           pvReserved;   /*!< Reserved  */ 
   typVa           FstTrsVa;     /*!< First transition variable identifier */
   typVa           FstStpVa;     /*!< First Step variable identifier */
   uint16          huNbStp;      /*!< Number of steps */
} strPdf;

/* data *******************************************************************/

/* exported services from module dker0pdf.c *******************************/
extern uint32 pdfSize
   (
   uint16 huNbPou  /* Number of Pou to manage */
   );

extern void pdfInit
   (
   void*   pvPdfBlkAdd, /* In: Block address of POUs definitions */ 
   uint16  huNbPou      /* In: Number of Pou */ 
   );

extern void pdfSfcSet
   (
   uint16  huPouNum, /* Pou number */ 
   typVa   FstTrsVa, /* First transition variable identifier */ 
   typVa   FstStpVa, /* First Step variable identifier */ 
   uint16  huNbStp   /* Number of steps */ 
   );
  
extern KERINLINE void pdfSfcStatusSet
   (
   uint16 huPouNum,  /* Pou number */ 
   uchar  cuStatus   /* Status to set */ 
   );
  
extern KERINLINE uchar pdfSfcStatusGet
   (
   uint16 huPouNum   /* Pou number */ 
   );
  
extern KERINLINE typVa pdfSfcTrsInfoGet
   (
   uint16 huPouNum   /* Pou number */ 
   );
  
extern KERINLINE typVa pdfSfcStpInfoGet
   (
   uint16  huPouNum,  /*In: Pou number */ 
   uint16* phuNbStp   /*Out: Number of steps */ 
   );

#endif /* nested Headers management */
/* eof ********************************************************************/
