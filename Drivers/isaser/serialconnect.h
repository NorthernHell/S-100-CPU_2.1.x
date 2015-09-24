/**************************************************************************
File:               serialconnect.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      04/06/2007 - 08:57
POU name:           SERIAL_CONNECT
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _SERIALCONNECT_H /* nested Headers management */
#define _SERIALCONNECT_H

/* function prototype */

ISASERDLL void isa_serial_connectUsfCall
   (
   void*       pvBfData,     /* In: Data */
   strParamVa* InParam,      /* In: Input parameters */
   uint16      huNbInParam,  /* In: Number of input parameters */
#ifdef ITGTDEF_NEW_ARRAY_AND_FB
   strParamVa* OutParam,     /* In: Output parameter */
   void*       pvAdi         /* In: Pointer to ADI table */
#else
   strParamVa* OutParam      /* In: Output parameter */
#endif /* ITGTDEF_NEW_ARRAY_AND_FB */
   );

#endif /* _SERIALCONNECT_H */

/* eof ********************************************************************/

