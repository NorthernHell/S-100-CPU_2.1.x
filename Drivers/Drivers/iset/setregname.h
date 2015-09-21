/**************************************************************************
File:               setregname.h
Author:             Lipovets
Creation date:      24/01/2008 - 19:46
POU name:           setRegName
***************************************************************************/

#ifndef _SETREGNAME_H /* nested Headers management */
#define _SETREGNAME_H

/* function prototype */

void setregnameUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _SETREGNAME_H */

/* eof ********************************************************************/

