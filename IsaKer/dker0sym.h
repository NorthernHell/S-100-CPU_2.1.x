/**************************************************************************
File:               dker0sym.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      19 december 2001
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#ifndef _DKER0SYM_H /* nested Headers management */
#define _DKER0SYM_H

/* constants **************************************************************/

/* types ******************************************************************/
/*
typedef struct
{
   typSPC_ID   KerSymId;
   void*       pvKerSymAdd;

   typVa       FirstSysVa;
   typVa       LastSysVa;
   typVa       FirstStepVa;
   typVa       LastStepVa;
   uint32      luSizeOfStep;
   uint32      luStepNbr;
   typVa       FirstTrsVa;
   typVa       LastTrsVa;
   typVa       FirstUserVa;
   typVa       LastUserVa;
   uint32      luDataSize;

} strKerSym;
*/
/* data *******************************************************************/

/* exported services from module dker0sym.c *******************************/
extern typSTATUS kerSymInit(void);
extern void kerSymExit(void);

#endif  /* nested Headers management */
/* eof ********************************************************************/
