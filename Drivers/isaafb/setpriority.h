/**************************************************************************
File:               setpriority.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      14/06/2007 - 14:45
POU name:           SET_PRIORITY
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _SETPRIORITY_H /* nested Headers management */
#define _SETPRIORITY_H

/* function prototype */

ISAAFBDLL void set_priorityUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uchar       cuNbInParam,  /* In: Number of input parameters */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* OutParam,     /* In: Output parameter */
   void*       pvAdi         /* In: Pointer to ADI table */
#else
   strParamVa* OutParam      /* In: Output parameter */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _SETPRIORITY_H */

/* eof ********************************************************************/

