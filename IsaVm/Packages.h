/**************************************************************************
File:               PACKAGES.H
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      1-October-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Declaration of the list of packages 
                    integrated to the kernel

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#ifndef _PACKAGES_H /* nested Headers management */
#define _PACKAGES_H

#define ISA_DECLARE_COMPILE

/****** TO DO: Include here your packages declaration file ******/

#include "../Drivers/Drivers.h"

#if (defined ITGTDEF_ADVFUNCTIONS) && (defined ITGTDEF_SERIALFUNCTIONS)
	#define ISA_DECLARE_ALLPACKAGES \
		ISA_DECLARE_COMPILE \
        ISA_DECLARE_DRIVERS

#elif (defined ITGTDEF_ADVFUNCTIONS)
	#define	ISA_DECLARE_ALLPACKAGES \
	ISA_DECLARE_COMPILE \
         ISA_DECLARE_DRIVERS

#elif (defined ITGTDEF_SERIALFUNCTIONS)
	#define	ISA_DECLARE_ALLPACKAGES \
	ISA_DECLARE_COMPILE \
         ISA_DECLARE_DRIVERS
#else
	#define	ISA_DECLARE_ALLPACKAGES \
		ISA_DECLARE_COMPILE \
         ISA_DECLARE_DRIVERS
#endif



#endif
