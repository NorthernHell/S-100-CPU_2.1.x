/**************************************************************************
File:               dlnx0fcr.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      18-November-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Error File specific to system integrator extensions.
                    File for Linux.

Format description of defines:
#define ISA_EREXT_.............           ISA_ER_BASE + 0x1...
 Description:  
?....message....................................
?...............................................

- Only lines that begin by "?" can be extracted.
- Numbers start at 0x1000 (ISA_ER_MAXRESERVED) in hexa and uppercase.
- Column where ISA_ER_BASE + 0x1... is put & layout must not be changed.
- EXT can be replaced with the plateform name trigram
***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#ifndef _DLNX0FCR_H  /* nested Headers management */
#define _DLNX0FCR_H  


/* constants **************************************************************/
#define ISA_EREXT_MYERRNO                 ISA_ER_BASE + 0x1000
/* Description: My errno full comments if any.    
?My errno extractable comments.
*/





/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module   ???    *********************************/

#endif   /* nested Headers management */

/* eof ********************************************************************/
