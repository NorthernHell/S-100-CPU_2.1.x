/**************************************************************************
File:               fastlibinit.h
Author:             Alex
Creation date:      02/10/2007 - 20:48
POU name:           FastLibInit
***************************************************************************/

#ifndef _FASTLIBINIT_H /* nested Headers management */
#define _FASTLIBINIT_H

/* function prototype */

void fastlibinitUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
   strParamVa* OutParam      /* In: Output parameter */
   );

#endif /* _FASTLIBINIT_H */

/* eof ********************************************************************/

