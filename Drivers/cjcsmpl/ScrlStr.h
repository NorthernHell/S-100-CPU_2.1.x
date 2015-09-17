/**************************************************************************
File:               ScrlStr.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      18-December-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        'C' function block sample: ScrollString
                      Scroll input string with specified number of 
                      characters

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#ifndef _SCRLSTR_H /* nested Headers management */
#define _SCRLSTR_H

/* constants **************************************************************/

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module ScrlStr.c ********************************/
extern void scrollstringFblClassInit
   (
   uint16 huNbInst  /* Number of instances */ 
   );

extern void scrollstringFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   );

extern void scrollstringFblInstInit
   (
   void*       pvBfData, /* In: Data */
   strParamVa* FblInst   /* In: Function block instance */ 
   );

extern void scrollstringFblInstExit
   (
   void*       pvBfData,      /* In: Data */ 
   strParamVa* FblInst        /* In: Function block instance */ 
   );

extern void scrollstringFblCall
   (
   void*       pvBfData, /* In: Data */ 
   strParamVa* FblInst   /* In: Function block instance */ 
   );

#endif  /* nested Headers management */
/* eof ********************************************************************/
