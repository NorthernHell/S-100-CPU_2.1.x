/**************************************************************************
File:               dker0blk.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      23-January-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Cyclic/Fct pgm Block of Tic sequence management  
                    function prototypes.

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#ifndef _DKER0BLK_H    /* nested Headers management */
#define _DKER0BLK_H



/* constants **************************************************************/

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module dker0blk.c *******************************/
extern uint32 blkSize
   (
   uint16 huNbBlk /* Number of blocks */  
   );

extern void blkInit
   (
   void*   pvBlkSeqPtrsBlkAdd, /*In: Pgms Block of Tic Seq addresses */ 
   uint16  huNbBlk             /*In: Number of blocks */ 
   ); 


extern void blkSet
   (
   uint16 huBlkNum,   /* In: Block Number */ 
   typVa* pBlkTicSeq  /* In: Block Tic Sequence */ 
   );

#ifdef ITGTDEF_OPT_CODE_MED_AS_LRG
extern KERINLINE uint32* blkGet
#else
extern KERINLINE typVa* blkGet
#endif /*ITGTDEF_OPT_CODE_MED_AS_LRG*/
   (
   uint16 huBlkNum    /* In: Block Number */ 
   );


#endif /* nested Headers management */
/* eof ********************************************************************/
