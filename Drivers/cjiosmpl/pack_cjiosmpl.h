/**************************************************************************
File:               CjIOSmpl.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      18-December-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Package declaration file.

***************************************************************************
Modifications: (who / date / description)
---4.02 Released---
EDS/20-Sep-1999/ 
   Corrected fct name case

***************************************************************************/
#ifndef _CJIOSMPL_H /* nested Headers management */
#define _CJIOSMPL_H

#include "Template.h"

/* constants **************************************************************/
#define ISA_DECLARE_PACK_CJIOSMPL                                               \
ISA_DECLARE_PACKNAME("CjIOSmpl")                                           \
ISA_DECLARE_HANDLE("cjiosmpl_drvnm_IosInit", cjiosmpl_drvnm_IosInit)       \
ISA_DECLARE_HANDLE("cjiosmpl_drvnm_IosExit", cjiosmpl_drvnm_IosExit)       \
ISA_DECLARE_HANDLE("cjiosmpl_drvnm_l1dvcnm_IosOpen", cjiosmpl_drvnm_l1dvcnm_IosOpen) \
ISA_DECLARE_HANDLE("cjiosmpl_drvnm_l1dvcnm_IosClose", cjiosmpl_drvnm_l1dvcnm_IosClose) \
ISA_DECLARE_HANDLE("cjiosmpl_drvnm_spldvcnm_IosRead", cjiosmpl_drvnm_spldvcnm_IosRead) \
ISA_DECLARE_HANDLE("cjiosmpl_drvnm_spldvcnm_IosWrite", cjiosmpl_drvnm_spldvcnm_IosWrite) \
ISA_DECLARE_HANDLE("cjiosmpl_drvnm_spldvcnm_IosCtl", cjiosmpl_drvnm_spldvcnm_IosCtl)

/* types ******************************************************************/

/* data *******************************************************************/




#endif  /* nested Headers management */
/* eof ********************************************************************/
