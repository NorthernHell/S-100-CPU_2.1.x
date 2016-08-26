/**************************************************************************
File:               CBSample.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      18-December-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Very simple example of a 'C' function block: compute the 
                    addition and subtraction of two double integers.

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#ifndef _CBSAMPLE_H /* nested Headers management */
#define _CBSAMPLE_H

/* constants **************************************************************/

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module CBSample.c *******************************/
extern void cbsampleFblClassInit
   (
   uint16 huNbInst  /* Number of instances */ 
   );

extern void cbsampleFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );

extern void cbsampleFblInstInit
   (
   void*       pvBfData, /* In: Data */
   strParamVa* FblInst   /* In: Function block instance */ 
   );

extern void cbsampleFblInstExit
   (
   void*       pvBfData,      /* In: Data */ 
   strParamVa* FblInst        /* In: Function block instance */ 
   );

extern void cbsampleFblCall
   (
   void*       pvBfData, /* In: Data */ 
   strParamVa* FblInst   /* In: Function block instance */ 
   );


#endif  /* nested Headers management */
/* eof ********************************************************************/
