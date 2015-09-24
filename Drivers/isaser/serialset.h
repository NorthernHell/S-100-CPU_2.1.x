/**************************************************************************
File:               serialset.h
Author:             ICS Triplex ISaGRAF Inc
Creation date:      04/06/2007 - 08:57
POU name:           SERIAL_SET
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _SERIALSET_H /* nested Headers management */
#define _SERIALSET_H

/* function prototype */

ISASERDLL void isa_serial_setUsfCall
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

#endif /* _SERIALSET_H */

/* eof ********************************************************************/

