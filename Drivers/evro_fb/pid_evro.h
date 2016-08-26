/**************************************************************************
File:               pid_evro.h
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
#ifndef _pid_evro_H /* nested Headers management */
#define _pid_evro_H

/* constants **************************************************************/

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module pid_evro.c *******************************/
extern void pid_evroFblClassInit
   (
   uint16 huNbInst  /* Number of instances */ 
   );

extern void pid_evroFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );

extern void pid_evroFblInstInit
   (
   void*       pvBfData, /* In: Data */
   strParamVa* FblInst   /* In: Function block instance */ 
   );

extern void pid_evroFblInstExit
   (
   void*       pvBfData,      /* In: Data */ 
   strParamVa* FblInst        /* In: Function block instance */ 
   );

extern void pid_evroFblCall
   (
   void*       pvBfData, /* In: Data */ 
   strParamVa* FblInst   /* In: Function block instance */ 
   );


#endif  /* nested Headers management */
/* eof ********************************************************************/
