/**************************************************************************
File:               setsave.h
Author:             Lipovets
Creation date:      24/01/2008 - 19:46
POU name:           setSave
***************************************************************************/

#ifndef _SETSAVE_H /* nested Headers management */
#define _SETSAVE_H

/* function prototype */

void setsaveUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _SETSAVE_H */

/* eof ********************************************************************/

