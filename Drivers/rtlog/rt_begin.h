/**************************************************************************
File:               rt_begin.h
Author:             Alex
Creation date:      19/01/2006 - 16:29
POU name:           rt_begin
***************************************************************************/

#ifndef _RT_BEGIN_H /* nested Headers management */
#define _RT_BEGIN_H

/* function prototype */

void rt_beginUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _RT_BEGIN_H */

/* eof ********************************************************************/

