/**************************************************************************
File:               gethirestime.h
Author:             Lipovets
Creation date:      08/04/2008 - 19:07
POU name:           getHiResTime
***************************************************************************/

#ifndef _GETHIRESTIME_H /* nested Headers management */
#define _GETHIRESTIME_H

/* function prototype */

void gethirestimeUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _GETHIRESTIME_H */

/* eof ********************************************************************/

