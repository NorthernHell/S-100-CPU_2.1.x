/**************************************************************************
File:               CFSample.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      18-December-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Very simple example of a 'C' function: compute the 
                    addition of two double integers.

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#ifndef _CFSAMPLE_H /* nested Headers management */
#define _CFSAMPLE_H

/* constants **************************************************************/

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module CFSample.c *******************************/
extern void cfsampleUsfCall   
   (
   void*       pvBfData,     /* In: Data */ 
   strParamVa* InParam,      /* In: Input parameters */ 
   uchar       cuNbInParam,  /* In: Number of input parameters */ 
   strParamVa* OutParam      /* In: Output parameter */ 
   );

#endif  /* nested Headers management */
/* eof ********************************************************************/
