/**************************************************************************
File:               dwng0def.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      25-November-1997
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Definition of Warnings

Format description of defines:
#define ISA_XXXWNG_..........                           0x....
 Description:  
? ...message..........................................
? ....................................................

- Only lines that begin by "?" can be exctracted.
- XXX refers to the type of application (task) that deals with the warning.
- The number is in hexadecimal and uppercase.
***************************************************************************
Modifications: (who / date / description)

---5.00 Released---
OL/02-Feb-2005/ New data type
   Add TIC code for INT, LINT, USINT, USINT, UDINT, ULINT, LREAL and DATE.
  
***************************************************************************/
#ifndef _DWNG0DEF_H  /* nested Headers management */
#define _DWNG0DEF_H 


/* constants **************************************************************/
/* MAX Number of reserved Warnings */
#define ISA_WNG_MAXRESERVED  0x8000U
/* Warning Commands */
#define ISA_WNG_ERRNO        0x01   /* Argument is an errno */

/**************************************************************************

         KERNEL WARNINGS

**************************************************************************/
#define ISA_KWNG_STARTUP                                0x0001
/* Description:
?Startup error.
*/

#define ISA_KWNG_SRVACC                                 0x0002
/* Description:
?Server communication exchange: Accept error.
*/

#define ISA_KWNG_RESTORE                                0x0003
/* Description:
?Resource Restore error.
*/

#define ISA_KWNG_RTNINIT                                0x0004
/* Description:
?Kernel Retain: Init error.
*/

#define ISA_KWNG_RTNMEM                                 0x0005
/* Description:
?Kernel Retain: Bad memory description.
*/

#define ISA_KWNG_RTNCRC                                 0x0006
/* Description:
?Kernel Retain: CRC error.
*/

#define ISA_KWNG_RTNREAD                                0x0007
/* Description:
?Kernel Retain: Read error.
*/

#define ISA_KWNG_RTNWRITE                               0x0008
/* Description:
?Kernel Retain: Write error.
*/

#define ISA_KWNG_DATAALLOC                              0x0009
/* Description:
?Resource Data Allocation error.
*/

#define ISA_KWNG_RSTART                                 0x000A
/* Description:
?Resource Start Report.
*/

#define ISA_KWNG_RSTOP                                  0x000B
/* Description:
?Resource Stop Report.
*/

#define ISA_KWNG_USFSTDCALL_NOTIMPLEM                   0x000C
/* Description:
?Standard function not implemented.
*/

#define ISA_KWNG_FBLSTDIINIT_NOTIMPLEM                  0x000D
/* Description:
?Standard function block instance init not implemented.
*/

#define ISA_KWNG_FBLSTDIEXIT_NOTIMPLEM                  0x000E
/* Description:
?Standard function block instance exit not implemented.
*/

#define ISA_KWNG_FBLSTDCALL_NOTIMPLEM                   0x000F
/* Description:
?Standard function block call not implemented.
*/

#define ISA_KWNG_USF_FCTNOTFOUND                        0x0010
/* Description:
?Function not implemented.
*/

#define ISA_KWNG_FBLIINIT_NOTIMPLEM                     0x0011
/* Description:
?Function block instance init required but not implemented.
*/

#define ISA_KWNG_FBLIEXIT_NOTIMPLEM                     0x0012
/* Description:
?Function block instance exit required but not implemented.
*/

#define ISA_KWNG_FBLCALL_NOTIMPLEM                      0x0013
/* Description:
?Function block call not implemented.
*/

#define ISA_KWNG_CNV_FCTNOTFOUND                        0x0014
/* Description:
?Function not implemented.
*/

#define ISA_KWNG_IOSINIT                                0x0015
/* Description:
?Kernel IOs: Init error.
*/

#define ISA_KWNG_IOSDRV_FCTNOTFOUND                     0x0016
/* Description:
?Kernel IOs: Driver Init/Exit fct(s) not found.
*/

#define ISA_KWNG_IOSDVC_FCTNOTFOUND                     0x0017
/* Description:
?Kernel IOs: Device Open/Close fct(s) not found.
*/

#define ISA_KWNG_IOSDVCR_FCTNOTFOUND                    0x0018
/* Description:
?Kernel IOs: Device Read fct not found.
*/

#define ISA_KWNG_IOSDVCW_FCTNOTFOUND                    0x0019
/* Description:
?Kernel IOs: Device Write fct not found.
*/

#define ISA_KWNG_IOSDVCCTL_FCTNOTFOUND                  0x001A
/* Description:
?Kernel IOs: Device Control fct not found.
*/

#define ISA_KWNG_IOSDRV_INITFAIL                        0x001B
/* Description:
?Kernel IOs: Driver Init fct failure.
*/

#define ISA_KWNG_IOSDVC_OPENFAIL                        0x001C
/* Description:
?Kernel IOs: Device Open fct failure.
*/

#define ISA_KWNG_KVBDRVNOTFOUND                         0x001D
/* Description:
?Kernel Binding: Driver not found.
*/

#define ISA_KWNG_KVBINIT                                0x001E
/* Description:
?Kernel Binding: Init error.
*/

#define ISA_KWNG_TICDEC                                 0x001F
/* Description:
?Kernel TIC: Unknown tic code.
*/

#define ISA_KWNG_TICCNV                                 0x0020
/* Description:
?Kernel TIC: Cast error.
*/

#define ISA_KWNG_TICBNDCHK                              0x0021
/* Description:
?Kernel TIC: Boundary check error.
*/

#define ISA_KWNG_TICSINTDIVZ                            0x0022
/* Description:
?Kernel TIC: SINT divided by zero.
*/

#define ISA_KWNG_TICDINTDIVZ                            0x0023
/* Description:
?Kernel TIC: DINT divided by zero.
*/

#define ISA_KWNG_TICREALDIVZ                            0x0024
/* Description:
?Kernel TIC: REAL divided by zero.
*/

#define ISA_KWNG_SFCEVO                                 0x0025
/* Description:
?Dynamic SFC behaviour: Behaviour processing error.
*/

#define ISA_KWNG_SFCACT                                 0x0026
/* Description:
?Dynamic SFC behaviour: Action Execution error.
*/

#define ISA_KWNG_TCYOVERFLOW                            0x0027
/* Description:
?Cycle Time Overflow.
*/

#define ISA_KWNG_SFCINIT                                0x0028
/* Description:
?Dynamic SFC behaviour: Initialisation error.
*/

#define ISA_KWNG_TICINTDIVZ                             0x0029
/* Description:
?Kernel TIC: INT divided by zero.
*/

#define ISA_KWNG_TICLINTDIVZ                            0x0030
/* Description:
?Kernel TIC: LINT divided by zero.
*/

#define ISA_KWNG_TICUSINTDIVZ                           0x0031
/* Description:
?Kernel TIC: USINT divided by zero.
*/

#define ISA_KWNG_TICUINTDIVZ                            0x0032
/* Description:
?Kernel TIC: UINT divided by zero.
*/

#define ISA_KWNG_TICUDINTDIVZ                           0x0033
/* Description:
?Kernel TIC: UDINT divided by zero.
*/

#define ISA_KWNG_TICULINTDIVZ                           0x0034
/* Description:
?Kernel TIC: ULINT divided by zero.
*/

#define ISA_KWNG_TICLREALDIVZ                           0x0035
/* Description:
?Kernel TIC: LREAL divided by zero.
*/

#define ISA_KWNG_TICCALLSTKOVERFLOW                     0x0036
/* Description:
?Kernel TIC: Call stack overflow.
*/

#define ISA_KWNG_TICSOFTWDOG                            0x0037
/* Description:
?Kernel TIC: Soft watch dog called.
*/

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module   ???    *********************************/

#endif   /* nested Headers management */

/* eof ********************************************************************/
