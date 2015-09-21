/**************************************************************************
File:               setpriority_functions.h
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

#ifndef _SETPRIORITY_FUNCTIONS_H /* nested Headers management */
#define _SETPRIORITY_FUNCTIONS_H


/* function prototype */

int32 IsaSetPrio
	(
	typHANDLE ht,
	int32 priority
	);

int32 IsaGetPrio
	(
	typHANDLE ht
	);

#endif /* _SETPRIORITY_FUNCTIONS_H */

/* eof ********************************************************************/

