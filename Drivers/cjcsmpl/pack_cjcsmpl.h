/**************************************************************************
File:               CjCSmpl.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      18-December-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Package declaration file.

***************************************************************************
Modifications: (who / date / description)
---4.02 Released---
EDS/20-Sep-1999/ 'C' conversion funct integration
   Integrated "bcd" conversion sample 

***************************************************************************/
#ifndef _CJCSMPL_H /* nested Headers management */
#define _CJCSMPL_H

#include "CBSample.h"
#include "CFSample.h"
#include "ScrlStr.h"

/* constants **************************************************************/
#define ISA_DECLARE_PACK_CJCSMPL                                                \
ISA_DECLARE_PACKNAME("CjCSmpl")                                            \
ISA_DECLARE_HANDLE("cfsampleUsfCall", cfsampleUsfCall)                     \
ISA_DECLARE_HANDLE("cbsampleFblClassInit", cbsampleFblClassInit)           \
ISA_DECLARE_HANDLE("cbsampleFblClassExit", cbsampleFblClassExit)           \
ISA_DECLARE_HANDLE("cbsampleFblInstInit", cbsampleFblInstInit)             \
ISA_DECLARE_HANDLE("cbsampleFblInstExit", cbsampleFblInstExit)             \
ISA_DECLARE_HANDLE("cbsampleFblCall", cbsampleFblCall)                     \
ISA_DECLARE_HANDLE("scrollstringFblClassInit", scrollstringFblClassInit)   \
ISA_DECLARE_HANDLE("scrollstringFblClassExit", scrollstringFblClassExit)   \
ISA_DECLARE_HANDLE("scrollstringFblInstInit", scrollstringFblInstInit)     \
ISA_DECLARE_HANDLE("scrollstringFblInstExit", scrollstringFblInstExit)     \
ISA_DECLARE_HANDLE("scrollstringFblCall", scrollstringFblCall)             

/* types ******************************************************************/

/* data *******************************************************************/


#endif  /* nested Headers management */
/* eof ********************************************************************/
