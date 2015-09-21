/**************************************************************************
File:               cprint_str.h
Author:             Alex
Creation date:      23/03/2007 - 19:26
POU name:           cprint_str
***************************************************************************/

#ifndef _CPRINT_STR_H /* nested Headers management */
#define _CPRINT_STR_H

/* function prototype */

void cprint_strUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _CPRINT_STR_H */

/* eof ********************************************************************/

