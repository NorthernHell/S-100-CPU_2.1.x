/**************************************************************************
File:               serialreceive.h
Author:             ICS Triplex ISaGRAF Inc
Creation date:      04/06/2007 - 08:57
POU name:           SERIAL_RECEIVE
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef _SERIALRECEIVE_H /* nested Headers management */
#define _SERIALRECEIVE_H

/* function prototype */

ISASERDLL void isa_serial_receiveUsfCall
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

#endif /* _SERIALRECEIVE_H */

/* eof ********************************************************************/

