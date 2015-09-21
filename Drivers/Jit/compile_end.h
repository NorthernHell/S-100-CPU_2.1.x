/**************************************************************************
File:               compile_end.h
Author:             Alex
Creation date:      22/03/2007 - 16:22
POU name:           compile_end
***************************************************************************/

#ifndef _COMPILE_END_H /* nested Headers management */
#define _COMPILE_END_H

/* function prototype */

void compile_endUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _COMPILE_END_H */

/* eof ********************************************************************/

