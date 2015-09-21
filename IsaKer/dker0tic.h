/**************************************************************************
File:               dker0tic.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      3-June-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        TIC code definitions

   _SYS_ : System functions  
   _TRS_ : End of block of code for an SFC transition
   _OUT_ : Refers to an output variable
   _USF_ : User function
   _STD_ : Standard C function or function block

***************************************************************************
Modifications: (who / date / description)

---4.12 Released---
VMO/12-June-2002/ SFC function block
   Added new TIC code for SFC function block : TIC_SEQ_A4B & TIC_SYS_PAXXX

---5.00 Released---
OL/02-Feb-2005/ New data type
   Add TIC code for INT, LINT, USINT, USINT, UDINT, ULINT, LREAL and DATE.

---5.00.001 Released---
OLA/03-Nov-2005/ RFS 2553: SFC FB cannot share is local variables with its childs.
   Add TIC_SYS_PAGSTART_EXT and TIC_SYS_PAGRST_EXT

***************************************************************************/
#ifndef _DKER0TIC_H /* nested Headers management */
#define _DKER0TIC_H


/* FCB : Tic not implemented in the Kernel */
#define TIC_PA6			0x900
#define TIC_VA_INCPVA	0x901
#define TIC_VA_INCVA	0x902

/* constants **************************************************************/

/* TIC Data type */

#define TIC_BOOL             0x01     /* boolean */
#define TIC_DINT             0x02     /* dint */
#define TIC_REAL             0x03     /* real */
#define TIC_TIME             0x04     /* time  */
#define TIC_STRING           0x05     /* string */
#define TIC_SINT             0x0b     /* sint */
#define TIC_NIL              0x06     /* nil */
#define TIC_FATHER           0x07     /* father sfc */
#define TIC_CHILD            0x08     /* child sfc */
#define TIC_SELF             0x0a     /* self */
#define TIC_NOT_TYPE         0x09     /* no type */
#define TIC_INT              0x0c
#define TIC_USINT            0x0d
#define TIC_UINT             0x0e
#define TIC_UDINT            0x0f
#define TIC_LINT             0x10
#define TIC_ULINT            0x11
#define TIC_DATE             0x12
#define TIC_LREAL            0x13

/* TIC Instruction codes */

/* Basic operations */
#define TIC_A1SI             0x0001   /* dint     a := - b */
#define TIC_A1SR             0x0002   /* real     a := - b */
#define TIC_A1NB             0x0003   /* boolean  a := not b */
#define TIC_A2MI             0x0004   /* dint     a := b * c */
#define TIC_A2MR             0x0005   /* real     a := b * c */
#define TIC_A2DI             0x0006   /* dint     a := b / c */
#define TIC_A2DR             0x0007   /* real     a := b / c */
#define TIC_A2AI             0x0008   /* dint     a := b + c */
#define TIC_A2AR             0x0009   /* real     a := b + c */
#define TIC_A2AT             0x000a   /* time     a := b + c */
#define TIC_A2AM             0x000b   /* string   a := b + c */
#define TIC_A2SI             0x000c   /* dint     a := b - c */
#define TIC_A2SR             0x000d   /* real     a := b - c */
#define TIC_A2ST             0x000e   /* time     a := b - c */
#define TIC_A2LTI            0x000f   /* dint     a := b < c */
#define TIC_A2LTR            0x0010   /* real     a := b < c */
#define TIC_A2LTT            0x0011   /* time     a := b < c */
#define TIC_A2LTM            0x0012   /* string   a := b < c */
#define TIC_A2GTI            0x0013   /* dint     a := b > c */
#define TIC_A2GTR            0x0014   /* real     a := b > c */
#define TIC_A2GTT            0x0015   /* time     a := b > c */
#define TIC_A2GTM            0x0016   /* string   a := b > c */
#define TIC_A2LEI            0x0017   /* dint     a := b <= c */
#define TIC_A2LER            0x0018   /* real     a := b <= c */
#define TIC_A2LET            0x0019   /* time     a := b <= c */
#define TIC_A2LEM            0x001a   /* string   a := b <= c */
#define TIC_A2GEI            0x001b   /* dint     a := b >= c */
#define TIC_A2GER            0x001c   /* real     a := b <= c */
#define TIC_A2GET            0x001d   /* time     a := b <= c */
#define TIC_A2GEM            0x001e   /* string   a := b <= c */
#define TIC_A2EQI            0x001f   /* dint     a := b == c */
#define TIC_A2EQR            0x0020   /* real     a := b == c */
#define TIC_A2EQT            0x0021   /* time     a := b == c */
#define TIC_A2EQM            0x0022   /* string   a := b == c */
#define TIC_A2EQB            0x0023   /* boolean  a := b == c */
#define TIC_A2NEI            0x0024   /* dint     a := b != c */
#define TIC_A2NER            0x0025   /* real     a := b != c */
#define TIC_A2NET            0x0026   /* time     a := b != c */
#define TIC_A2NEM            0x0027   /* string   a := b != c */
#define TIC_A2NEB            0x0028   /* boolean  a := b != c */
#define TIC_A2ORB            0x0029   /* boolean  a := b OR c */
#define TIC_A2ANB            0x002a   /* boolean  a := b AND c */
#define TIC_A2XOB            0x002b   /* boolean  a := b XOR c */
#define TIC_A3B              0x002c   /* boolean  a := b */
#define TIC_A3I              0x002d   /* dint     a := b */
#define TIC_A3R              0x002e   /* real     a := b */
#define TIC_A3T              0x002f   /* time     a := b */
#define TIC_A3M              0x0030   /* string   a := b */

/* IEC function call */
#define TIC_A4N              0x0031   /* nil (IEC FBL) call b */
#define TIC_A4B              0x0032   /* boolean  a := call b */ 
#define TIC_A4I              0x0033   /* dint     a := call b */
#define TIC_A4R              0x0034   /* real     a := call b */
#define TIC_A4T              0x0035   /* time     a := call b */
#define TIC_A4M              0x0036   /* string   a := call b */

/* Arrays */
#define TIC_A5B              0x0037   /* boolean  a := b [ c ] */
#define TIC_A5I              0x0038   /* dint     a := b [ c ] */ 
#define TIC_A5R              0x0039   /* real     a := b [ c ] */
#define TIC_A5T              0x003a   /* time     a := b [ c ] */
#define TIC_A5M              0x003b   /* string   a := b [ c ] */
#define TIC_A6B              0x003c   /* boolean  a [ b ] := c */
#define TIC_A6I              0x003d   /* dint     a [ b ] := c */
#define TIC_A6R              0x003e   /* real     a [ b ] := c */
#define TIC_A6T              0x003f   /* time     a [ b ] := c */
#define TIC_A6M              0x0040   /* string   a [ b ] := c */

/* Jumps */
#define TIC_C1B              0x0041   /* boolean  if a goto b */
#define TIC_C2B              0x0042   /* boolean  if not a goto b */
#define TIC_I1               0x0043   /* goto a */
#define TIC_I2               0x0044   /* return */

/* Functions call parameter passing: PushPar (param) */
#define TIC_P1C              0x0045   /* child param */
#define TIC_P1F              0x0046   /* father param */
#define TIC_P1B              0x0047   /* boolean param */
#define TIC_P1I              0x0048   /* dint param */
#define TIC_P1R              0x0049   /* real param */
#define TIC_P1T              0x004a   /* time  param */
#define TIC_P1M              0x004b   /* string param */

/* Labels */
#define TIC_L1               0x004c   /* label */

/* End of block of code for an SFC transitions */
#define TIC_TRS_A1NB         0x004d   /* boolean  a := not b */
#define TIC_TRS_A2LTI        0x004e   /* dint     a := b < c */
#define TIC_TRS_A2LTR        0x004f   /* real     a := b < c */
#define TIC_TRS_A2LTT        0x0050   /* time     a := b < c */
#define TIC_TRS_A2LTM        0x0051   /* string   a := b < c */
#define TIC_TRS_A2GTI        0x0052   /* dint     a := b > c */
#define TIC_TRS_A2GTR        0x0053   /* real     a := b > c */
#define TIC_TRS_A2GTT        0x0054   /* time     a := b > c */
#define TIC_TRS_A2GTM        0x0055   /* string   a := b > c */
#define TIC_TRS_A2LEI        0x0056   /* dint     a := b <= c */
#define TIC_TRS_A2LER        0x0057   /* real     a := b <= c */
#define TIC_TRS_A2LET        0x0058   /* time     a := b <= c */
#define TIC_TRS_A2LEM        0x0059   /* string   a := b <= c */
#define TIC_TRS_A2GEI        0x005a   /* dint     a := b >= c */
#define TIC_TRS_A2GER        0x005b   /* real     a := b <= c */
#define TIC_TRS_A2GET        0x005c   /* time     a := b <= c */
#define TIC_TRS_A2GEM        0x005d   /* string   a := b <= c */
#define TIC_TRS_A2EQI        0x005e   /* dint     a := b == c */
#define TIC_TRS_A2EQR        0x005f   /* real     a := b == c */
#define TIC_TRS_A2EQT        0x0060   /* time     a := b == c */
#define TIC_TRS_A2EQM        0x0061   /* string   a := b == c */
#define TIC_TRS_A2EQB        0x0062   /* boolean  a := b == c */
#define TIC_TRS_A2NEI        0x0063   /* dint     a := b != c */
#define TIC_TRS_A2NER        0x0064   /* real     a := b != c */
#define TIC_TRS_A2NET        0x0065   /* time     a := b != c */
#define TIC_TRS_A2NEM        0x0066   /* string   a := b != c */
#define TIC_TRS_A2NEB        0x0067   /* boolean  a := b != c */
#define TIC_TRS_A2ORB        0x0068   /* boolean  a := b OR c */
#define TIC_TRS_A2ANB        0x0069   /* boolean  a := b AND c */
#define TIC_TRS_A2XOB        0x006a   /* boolean  a := b XOR c */
#define TIC_TRS_A3B          0x006b   /* boolean  a := b */
#define TIC_TRS_A4B          0x006c   /* boolean  a := call b */ 
#define TIC_TRS_A5B          0x006d   /* boolean  a := b [ c ] */

/* Output variable assignation */
#define TIC_OUT_A1SI         0x006e   /* dint     a := - b */
#define TIC_OUT_A1SR         0x006f   /* real     a := - b */
#define TIC_OUT_A1NB         0x0070   /* boolean  a := not b */
#define TIC_OUT_A2MI         0x0071   /* dint     a := b * c */
#define TIC_OUT_A2MR         0x0072   /* real     a := b * c */
#define TIC_OUT_A2DI         0x0073   /* dint     a := b / c */
#define TIC_OUT_A2DR         0x0074   /* real     a := b / c */
#define TIC_OUT_A2AI         0x0075   /* dint     a := b + c */
#define TIC_OUT_A2AR         0x0076   /* real     a := b + c */
#define TIC_OUT_A2AM         0x0077   /* string   a := b + c */
#define TIC_OUT_A2SI         0x0078   /* dint     a := b - c */
#define TIC_OUT_A2SR         0x0079   /* real     a := b - c */
#define TIC_OUT_A2LTI        0x007a   /* dint     a := b < c */
#define TIC_OUT_A2LTR        0x007b   /* real     a := b < c */
#define TIC_OUT_A2LTM        0x007c   /* string   a := b < c */
#define TIC_OUT_A2LTT        0x007d   /* time     a := b < c */
#define TIC_OUT_A2GTI        0x007e   /* dint     a := b > c */
#define TIC_OUT_A2GTR        0x007f   /* real     a := b > c */
#define TIC_OUT_A2GTM        0x0080   /* string   a := b > c */
#define TIC_OUT_A2GTT        0x0081   /* time     a := b > c */
#define TIC_OUT_A2LEI        0x0082   /* dint     a := b <= c */
#define TIC_OUT_A2LER        0x0083   /* real     a := b <= c */
#define TIC_OUT_A2LEM        0x0084   /* string   a := b <= c */
#define TIC_OUT_A2LET        0x0085   /* time     a := b <= c */
#define TIC_OUT_A2GEI        0x0086   /* dint     a := b >= c */
#define TIC_OUT_A2GER        0x0087   /* real     a := b <= c */
#define TIC_OUT_A2GEM        0x0088   /* string   a := b <= c */
#define TIC_OUT_A2GET        0x0089   /* time     a := b <= c */
#define TIC_OUT_A2EQI        0x008a   /* dint     a := b == c */
#define TIC_OUT_A2EQR        0x008b   /* real     a := b == c */
#define TIC_OUT_A2EQM        0x008c   /* string   a := b == c */
#define TIC_OUT_A2EQB        0x008d   /* boolean  a := b == c */
#define TIC_OUT_A2EQT        0x008e   /* time     a := b == c */
#define TIC_OUT_A2NEI        0x008f   /* dint     a := b != c */
#define TIC_OUT_A2NER        0x0090   /* real     a := b != c */
#define TIC_OUT_A2NEM        0x0091   /* string   a := b != c */
#define TIC_OUT_A2NEB        0x0092   /* boolean  a := b != c */
#define TIC_OUT_A2NET        0x0093   /* time     a := b != c */
#define TIC_OUT_A2ORB        0x0094   /* boolean  a := b OR c */
#define TIC_OUT_A2ANB        0x0095   /* boolean  a := b AND c */
#define TIC_OUT_A2XOB        0x0096   /* boolean  a := b XOR c */
#define TIC_OUT_A3B          0x0097   /* boolean  a := b */
#define TIC_OUT_A3I          0x0098   /* dint     a := b */
#define TIC_OUT_A3R          0x0099   /* real     a := b */
#define TIC_OUT_A3M          0x009a   /* string   a := b */
#define TIC_OUT_A3T          0x009b   /* time     a := b */
#define TIC_OUT_A4B          0x009c   /* boolean  a := call b */ 
#define TIC_OUT_A4I          0x009d   /* dint     a := call b */
#define TIC_OUT_A4R          0x009e   /* real     a := call b */
#define TIC_OUT_A4M          0x009f   /* string   a := call b */
#define TIC_OUT_A4T          0x00a0   /* time     a := call b */
#define TIC_OUT_A5B          0x00a1   /* boolean  a := b [ c ] */
#define TIC_OUT_A5I          0x00a2   /* dint     a := b [ c ] */ 
#define TIC_OUT_A5R          0x00a3   /* real     a := b [ c ] */
#define TIC_OUT_A5M          0x00a4   /* string   a := b [ c ] */
#define TIC_OUT_A5T          0x00a5   /* time     a := b [ c ] */
#define TIC_OUT_A6B          0x00a6   /* boolean  a [ b ] := c */
#define TIC_OUT_A6I          0x00a7   /* dint     a [ b ] := c */
#define TIC_OUT_A6R          0x00a8   /* real     a [ b ] := c */
#define TIC_OUT_A6M          0x00a9   /* string   a [ b ] := c */

/*
 * IEC functions & function blocks calling parameter access 
 * GetPar (Where to assign value, Param number) 
 */
#define TIC_SYS_GPARB        0x00aa   /* boolean get param */
#define TIC_SYS_GPARI        0x00ab   /* dint get param */
#define TIC_SYS_GPARR        0x00ac   /* real get param */
#define TIC_SYS_GPART        0x00ad   /* time get param */
#define TIC_SYS_GPARM        0x00ae   /* string get param */

/*
 * IEC functions & function blocks return parameter put-in 
 * PutPar (Param number, Where to retrieve value to return) 
 * Param number = 0 for functions 
 */
#define TIC_SYS_PPARB        0x00af   /* boolean put param */
#define TIC_SYS_PPARI        0x00b0   /* dint put param */
#define TIC_SYS_PPARR        0x00b1   /* real put param */
#define TIC_SYS_PPART        0x00b2   /* time put param */
#define TIC_SYS_PPARM        0x00b3   /* string put param */
#define TIC_TRS_PPARB        0x00b4   /* boolean put param on SFC transition */
                                    
/*
 * 'C' Written Function Blocks output parameter access
 * GetParBlock (Where to assign value, Param Num, Blk Num, Instance Num)
 */
#define TIC_SYS_GPARBLKB     0x00b5   /* boolean get param */
#define TIC_SYS_GPARBLKI     0x00b6   /* dint get param */
#define TIC_SYS_GPARBLKR     0x00b7   /* real get param */
#define TIC_SYS_GPARBLKT     0x00b8   /* time get param */
#define TIC_SYS_GPARBLKM     0x00b9   /* string get param */
#define TIC_TRS_GPARBLKB     0x00ba   /* boolean get param on SFC transition */

/* Program activity control */
#define TIC_SYS_GSTART       0x00bb   /* start an sfc */        
#define TIC_SYS_GFREEZE      0x00bc   /* freeze an sfc */
#define TIC_SYS_GKILL        0x00bd   /* kill an sfc */
#define TIC_SYS_GRST         0x00be   /* restart an sfc */

/* Activity control timer  */
#define TIC_SYS_TSTART       0x00bf   /* start a timer  */
#define TIC_SYS_TSTOP        0x00c0   /* stop a timer */

/* System status functions */
#define TIC_SYS_GSTATUS      0x00c1   /* recup current status of an sfc */
#define TIC_SYS_SYSTEM       0x00c2   /* recup system parameters */
#define TIC_SYS_OPERATE      0x00c3   /* perform I/O operations */
#define TIC_SYS_FEDGE        0x00c4   /* test falling edge */
#define TIC_SYS_REDGE        0x00c5   /* test rising edge */
#define TIC_TRS_FEDGE        0x00c6   /* test falling edge on SFC transition */
#define TIC_TRS_REDGE        0x00c7   /* test rising edge on SFC transition */
#define TIC_OUT_GSTATUS      0x00c8   /* recup curr status of an sfc (out) */
#define TIC_OUT_SYSTEM       0x00c9   /* recup system parameters (out) */
#define TIC_OUT_OPERATE      0x00ca   /* perform I/O operations (out) */
#define TIC_OUT_FEDGE        0x00cb   /* test falling edge (out) */
#define TIC_OUT_REDGE        0x00cc   /* test rising edge (out) */

/* 
 * Cast conversion function
 * CNV (Where to assign result, destination type, source type)
 * The variable to convert has previously been pushed as a parameter
 */
#define TIC_SYS_CNV          0x00cd   /* convertion type src --> type dest */
#define TIC_TRS_CNV          0x00ce   /* convertion on an SFC transition */
#define TIC_OUT_CNV          0x00cf   /* convertion of an output variable */

/* Step activity request */
/* testActivity     (Where to assign result, Step Num) */
/* timeActivity     (Where to assign result, Step Num) */
#define TIC_SYS_TAC          0x00d0   /* test activity */
#define TIC_SYS_DAC          0x00d1   /* time activity */

/* User 'C' function call */           
#define TIC_USF_A4B          0x00d2   /* boolean  a := call b */  
#define TIC_USF_A4I          0x00d3   /* dint     a := call b */
#define TIC_USF_A4R          0x00d4   /* real     a := call b */
#define TIC_USF_A4M          0x00d5   /* string   a := call b */
#define TIC_USF_A4T          0x00d6   /* time     a := call b */
#define TIC_USF_TRS_A4B      0x00d7   /* boolean  a := call b on SFC trans */
#define TIC_USF_OUT_A4B      0x00d8   /* boolean  a := call b on output */ 
#define TIC_USF_OUT_A4I      0x00d9   /* dint     a := call b on output */
#define TIC_USF_OUT_A4R      0x00da   /* real     a := call b on output */
#define TIC_USF_OUT_A4M      0x00db   /* string   a := call b on output */
#define TIC_USF_OUT_A4T      0x00dc   /* time     a := call b on output */

/* Standard 'C' function call */           
#define TIC_STD_A4B          0x00dd   /* boolean  a := call b */  
#define TIC_STD_A4I          0x00de   /* dint     a := call b */
#define TIC_STD_A4R          0x00df   /* real     a := call b */
#define TIC_STD_A4M          0x00e0   /* string   a := call b */
#define TIC_STD_A4T          0x00e1   /* time     a := call b */
#define TIC_STD_TRS_A4B      0x00e2   /* boolean  a := call b on SFC trans */
#define TIC_STD_OUT_A4B      0x00e3   /* boolean  a := call b on output */ 
#define TIC_STD_OUT_A4I      0x00e4   /* dint     a := call b on output */
#define TIC_STD_OUT_A4R      0x00e5   /* real     a := call b on output */
#define TIC_STD_OUT_A4M      0x00e6   /* string   a := call b on output */
#define TIC_STD_OUT_A4T      0x00e7   /* time     a := call b on output */

/* 
 * User 'C' function block call 
 * a = Block Number
 * b = Instance Number
 */
#define TIC_FBL              0x00e8   /* nil      call a,b */

/* 
 * Standard function block call
 * a = Block Number
 * b = Instance Number
 */
#define TIC_STD_FBL          0x00e9   /* nil      call a,b */

/* End of a block of code (except for sfc's transition, see _TRS_) */
#define TIC_END_BLOCK        0x00ea

/* Specific Code for kernel own management (not genarated by Wbch) */
#define TIC_BKP_BEG          0x00f0   /* Breakpoint on step activation */
#define TIC_BKP_END          0x00f1   /* Breakpoint on step de-activation */
#define TIC_BKP_TRA          0x00f2   /* Breakpoint on transition */

/* 
 * Functions call parameter passing: PushPar (param)
 * Extension 1
 */
#define TIC_P1S              0x00f3   /* self param */

/* 
 * timer  operation 
 * Extension 1
 */
#define TIC_SYS_A3T          0x00f4   /* duplicate timer (value & activity) */

/* 
 * SINT type
 */
#define TIC_A1SS             0x00f5   /* sint     a := - b */
#define TIC_A2MS             0x00f6   /* sint     a := b * c */
#define TIC_A2DS             0x00f7   /* sint     a := b / c */
#define TIC_A2AS             0x00f8   /* sint     a := b + c */
#define TIC_A2SS             0x00f9   /* sint     a := b - c */
#define TIC_A2LTS            0x00fa   /* sint     a := b < c */
#define TIC_A2GTS            0x00fb   /* sint     a := b > c */
#define TIC_A2LES            0x00fc   /* sint     a := b <= c */
#define TIC_A2GES            0x00fd   /* sint     a := b >= c */
#define TIC_A2EQS            0x00fe   /* sint     a := b == c */
#define TIC_A2NES            0x00ff   /* sint     a := b != c */
#define TIC_A3S              0x0100   /* sint     a := b */

#define TIC_A4S              0x0101   /* sint     a := call b */

#define TIC_A5S              0x0102   /* sint     a := b [ c ] */ 
#define TIC_A6S              0x0103   /* sint     a [ b ] := c */
#define TIC_P1SINT           0x0104   /* sint param */
                        
#define TIC_TRS_A2LTS        0x0105   /* sint     a := b < c */
#define TIC_TRS_A2GTS        0x0106   /* sint     a := b > c */
#define TIC_TRS_A2LES        0x0107   /* sint     a := b <= c */
#define TIC_TRS_A2GES        0x0108   /* sint     a := b >= c */
#define TIC_TRS_A2EQS        0x0109   /* sint     a := b == c */
#define TIC_TRS_A2NES        0x010a   /* sint     a := b != c */
                        
#define TIC_OUT_A1SS         0x010b   /* sint     a := - b */
#define TIC_OUT_A2MS         0x010c   /* sint     a := b * c */
#define TIC_OUT_A2DS         0x010d   /* sint     a := b / c */
#define TIC_OUT_A2AS         0x010e   /* sint     a := b + c */
#define TIC_OUT_A2SS         0x010f   /* sint     a := b - c */
#define TIC_OUT_A2LTS        0x0110   /* sint     a := b < c */
#define TIC_OUT_A2GTS        0x0111   /* sint     a := b > c */
#define TIC_OUT_A2LES        0x0112   /* sint     a := b <= c */
#define TIC_OUT_A2GES        0x0113   /* sint     a := b >= c */
#define TIC_OUT_A2EQS        0x0114   /* sint     a := b == c */
#define TIC_OUT_A2NES        0x0115   /* sint     a := b != c */
#define TIC_OUT_A3S          0x0116   /* sint     a := b */
#define TIC_OUT_A4S          0x0117   /* sint     a := call b */
#define TIC_OUT_A5S          0x0118   /* sint     a := b [ c ] */ 
#define TIC_OUT_A6S          0x0119   /* sint     a [ b ] := c */
                        
                        
#define TIC_SYS_GPARS        0x011a   /* sint get param */
                        
#define TIC_SYS_PPARS        0x011b   /* sint put param */

#define TIC_SYS_GPARBLKS     0x011c   /* sint get param */

#define TIC_USF_A4S          0x011d   /* sint     a := call b */
#define TIC_USF_OUT_A4S      0x011e   /* sint     a := call b on output */

#define TIC_STD_A4S          0x011f   /* sint     a := call b */
#define TIC_STD_OUT_A4S      0x0120   /* sint     a := call b on output */

/* 
 * USINT type 
 */
#define TIC_A2MUSI            0x165    /* usint     a := b * c */
#define TIC_A2DUSI            0x166    /* usint     a := b / c */
#define TIC_A2AUSI            0x167    /* usint     a := b + c */
#define TIC_A2SUSI            0x168    /* usint     a := b - c */
#define TIC_A2LTUSI           0x169    /* usint     a := b < c */
#define TIC_A2GTUSI           0x16a    /* usint     a := b > c */
#define TIC_A2LEUSI           0x16b    /* usint     a := b <= c */
#define TIC_A2GEUSI           0x16c    /* usint     a := b >= c */
#define TIC_A2EQUSI           0x16d	   /* usint     a := b == c */
#define TIC_A2NEUSI           0x16e	   /* usint     a := b != c */
#define TIC_A3USI             0x16f    /* usint     a := b */

#define TIC_A4USI             0x170    /* usint     a := call b */

#define TIC_A5USI             0x171    /* usint     a := b [ c ] */ 
#define TIC_A6USI             0x172    /* usint     a [ b ] := c */
#define TIC_P1USI             0x173    /* usint param */
                        
#define TIC_TRS_A2LTUSI       0x174    /* usint     a := b < c */
#define TIC_TRS_A2GTUSI       0x175    /* usint     a := b > c */
#define TIC_TRS_A2LEUSI       0x176    /* usint     a := b <= c */
#define TIC_TRS_A2GEUSI       0x177    /* usint     a := b >= c */
#define TIC_TRS_A2EQUSI       0x178    /* usint     a := b == c */
#define TIC_TRS_A2NEUSI       0x179    /* usint     a := b != c */
                        
#define TIC_OUT_A2MUSI        0x17a    /* usint     a := b * c */
#define TIC_OUT_A2DUSI        0x17b    /* usint     a := b / c */
#define TIC_OUT_A2AUSI        0x17c    /* usint     a := b + c */
#define TIC_OUT_A2SUSI        0x17d    /* usint     a := b - c */
#define TIC_OUT_A2LTUSI       0x17e    /* usint     a := b < c */
#define TIC_OUT_A2GTUSI       0x17f    /* usint     a := b > c */
#define TIC_OUT_A2LEUSI       0x180    /* usint     a := b <= c */
#define TIC_OUT_A2GEUSI       0x181    /* usint     a := b >= c */
#define TIC_OUT_A2EQUSI       0x182    /* usint     a := b == c */
#define TIC_OUT_A2NEUSI       0x183    /* usint     a := b != c */
#define TIC_OUT_A3USI         0x184    /* usint     a := b */
#define TIC_OUT_A4USI         0x185    /* usint     a := call b */
#define TIC_OUT_A5USI         0x186    /* usint     a := b [ c ] */ 
#define TIC_OUT_A6USI         0x187    /* usint     a [ b ] := c */
                        
                        
#define TIC_SYS_GPARUSI       0x188   /* usint get param */
                        
#define TIC_SYS_PPARUSI       0x189   /* usint put param */

#define TIC_SYS_GPARBLKUSI    0x18a   /* usint get param */

#define TIC_USF_A4USI         0x18b   /* usint     a := call b */
#define TIC_USF_OUT_A4USI     0x18c   /* usint     a := call b on output */

#define TIC_STD_A4USI         0x18d   /* usint     a := call b */
#define TIC_STD_OUT_A4USI     0x18e   /* usint     a := call b on output */

/* 
 * INT type 
 */
#define TIC_A1SINT            0x18f    /* int     a := - b */
#define TIC_A2MINT            0x190    /* int     a := b * c */
#define TIC_A2DINT            0x191    /* int     a := b / c */
#define TIC_A2AINT            0x192    /* int     a := b + c */
#define TIC_A2SINT            0x193    /* int     a := b - c */
#define TIC_A2LTINT           0x194    /* int     a := b < c */
#define TIC_A2GTINT           0x195    /* int     a := b > c */
#define TIC_A2LEINT           0x196    /* int     a := b <= c */
#define TIC_A2GEINT           0x197    /* int     a := b >= c */
#define TIC_A2EQINT           0x198	  /* int     a := b == c */
#define TIC_A2NEINT           0x199	  /* int     a := b != c */
#define TIC_A3INT             0x19a    /* int     a := b */

#define TIC_A4INT             0x19b    /* int     a := call b */

#define TIC_A5INT             0x19c    /* int     a := b [ c ] */ 
#define TIC_A6INT             0x19d    /* int     a [ b ] := c */
#define TIC_P1INT             0x19e    /* int param */
                        
#define TIC_TRS_A2LTINT       0x19f    /* int     a := b < c */
#define TIC_TRS_A2GTINT       0x1a0    /* int     a := b > c */
#define TIC_TRS_A2LEINT       0x1a1    /* int     a := b <= c */
#define TIC_TRS_A2GEINT       0x1a2    /* int     a := b >= c */
#define TIC_TRS_A2EQINT       0x1a3    /* int     a := b == c */
#define TIC_TRS_A2NEINT       0x1a4    /* int     a := b != c */
                        
#define TIC_OUT_A1SINT        0x1a5    /* int     a := - b */
#define TIC_OUT_A2MINT        0x1a6    /* int     a := b * c */
#define TIC_OUT_A2DINT        0x1a7    /* int     a := b / c */
#define TIC_OUT_A2AINT        0x1a8    /* int     a := b + c */
#define TIC_OUT_A2SINT        0x1a9    /* int     a := b - c */
#define TIC_OUT_A2LTINT       0x1aa    /* int     a := b < c */
#define TIC_OUT_A2GTINT       0x1ab    /* int     a := b > c */
#define TIC_OUT_A2LEINT       0x1ac    /* int     a := b <= c */
#define TIC_OUT_A2GEINT       0x1ad    /* int     a := b >= c */
#define TIC_OUT_A2EQINT       0x1ae    /* int     a := b == c */
#define TIC_OUT_A2NEINT       0x1af    /* int     a := b != c */
#define TIC_OUT_A3INT         0x1b0    /* int     a := b */
#define TIC_OUT_A4INT         0x1b1    /* int     a := call b */
#define TIC_OUT_A5INT         0x1b2    /* int     a := b [ c ] */ 
#define TIC_OUT_A6INT         0x1b3    /* int     a [ b ] := c */
                        
                        
#define TIC_SYS_GPARINT       0x1b4   /* int get param */
                        
#define TIC_SYS_PPARINT       0x1b5   /* int put param */

#define TIC_SYS_GPARBLKINT    0x1b6   /* int get param */

#define TIC_USF_A4INT         0x1b7   /* int     a := call b */
#define TIC_USF_OUT_A4INT     0x1b8   /* int     a := call b on output */

#define TIC_STD_A4INT         0x1b9   /* int     a := call b */
#define TIC_STD_OUT_A4INT     0x1ba   /* int     a := call b on output */

/* 
 * UINT type 
 */
#define TIC_A2MUIN           0x1bb    /* uint     a := b * c */
#define TIC_A2DUIN           0x1bc    /* uint     a := b / c */
#define TIC_A2AUIN           0x1bd    /* uint     a := b + c */
#define TIC_A2SUIN           0x1be    /* uint     a := b - c */
#define TIC_A2LTUIN          0x1bf    /* uint     a := b < c */
#define TIC_A2GTUIN          0x1c0    /* uint     a := b > c */
#define TIC_A2LEUIN          0x1c1    /* uint     a := b <= c */
#define TIC_A2GEUIN          0x1c2    /* uint     a := b >= c */
#define TIC_A2EQUIN          0x1c3	  /* uint     a := b == c */
#define TIC_A2NEUIN          0x1c4	  /* uint     a := b != c */
#define TIC_A3UIN            0x1c5    /* uint     a := b */

#define TIC_A4UIN            0x1c6    /* uint     a := call b */

#define TIC_A5UIN            0x1c7    /* uint     a := b [ c ] */ 
#define TIC_A6UIN            0x1c8    /* uint     a [ b ] := c */
#define TIC_P1UIN            0x1c9    /* uint param */
                        
#define TIC_TRS_A2LTUIN      0x1ca    /* uint     a := b < c */
#define TIC_TRS_A2GTUIN      0x1cb    /* uint     a := b > c */
#define TIC_TRS_A2LEUIN      0x1cc    /* uint     a := b <= c */
#define TIC_TRS_A2GEUIN      0x1cd    /* uint     a := b >= c */
#define TIC_TRS_A2EQUIN      0x1ce    /* uint     a := b == c */
#define TIC_TRS_A2NEUIN      0x1cf    /* uint     a := b != c */
                        
#define TIC_OUT_A2MUIN       0x1d0    /* uint     a := b * c */
#define TIC_OUT_A2DUIN       0x1d1    /* uint     a := b / c */
#define TIC_OUT_A2AUIN       0x1d2    /* uint     a := b + c */
#define TIC_OUT_A2SUIN       0x1d3    /* uint     a := b - c */
#define TIC_OUT_A2LTUIN      0x1d4    /* uint     a := b < c */
#define TIC_OUT_A2GTUIN      0x1d5    /* uint     a := b > c */
#define TIC_OUT_A2LEUIN      0x1d6    /* uint     a := b <= c */
#define TIC_OUT_A2GEUIN      0x1d7    /* uint     a := b >= c */
#define TIC_OUT_A2EQUIN      0x1d8    /* uint     a := b == c */
#define TIC_OUT_A2NEUIN      0x1d9    /* uint     a := b != c */
#define TIC_OUT_A3UIN        0x1da    /* uint     a := b */
#define TIC_OUT_A4UIN        0x1db    /* uint     a := call b */
#define TIC_OUT_A5UIN        0x1dc    /* uint     a := b [ c ] */ 
#define TIC_OUT_A6UIN        0x1de    /* uint     a [ b ] := c */
                        
                        
#define TIC_SYS_GPARUIN       0x1df   /* uint get param */
                        
#define TIC_SYS_PPARUIN       0x1e0   /* uint put param */

#define TIC_SYS_GPARBLKUIN    0x1e1   /* uint get param */

#define TIC_USF_A4UIN         0x1e2   /* uint     a := call b */
#define TIC_USF_OUT_A4UIN     0x1e3   /* uint     a := call b on output */

#define TIC_STD_A4UIN         0x1e4   /* uint     a := call b */
#define TIC_STD_OUT_A4UIN     0x1e5   /* uint     a := call b on output */


/* 
 * UDINT type 
 */
#define TIC_A2MUDI            0x1e6    /* udint     a := b * c */
#define TIC_A2DUDI            0x1e7    /* udint     a := b / c */
#define TIC_A2AUDI            0x1e8    /* udint     a := b + c */
#define TIC_A2SUDI            0x1e9    /* udint     a := b - c */
#define TIC_A2LTUDI           0x1ea    /* udint     a := b < c */
#define TIC_A2GTUDI           0x1eb    /* udint     a := b > c */
#define TIC_A2LEUDI           0x1ec    /* udint     a := b <= c */
#define TIC_A2GEUDI           0x1ed    /* udint     a := b >= c */
#define TIC_A2EQUDI           0x1ee	  /* udint     a := b == c */
#define TIC_A2NEUDI           0x1ef	  /* udint     a := b != c */
#define TIC_A3UDI             0x1f0    /* udint     a := b */

#define TIC_A4UDI             0x1f1    /* udint     a := call b */

#define TIC_A5UDI             0x1f2    /* udint     a := b [ c ] */ 
#define TIC_A6UDI             0x1f3    /* udint     a [ b ] := c */
#define TIC_P1UDI             0x1f4    /* udint param */
                        
#define TIC_TRS_A2LTUDI       0x1f5    /* udint     a := b < c */
#define TIC_TRS_A2GTUDI       0x1f6    /* udint     a := b > c */
#define TIC_TRS_A2LEUDI       0x1f7    /* udint     a := b <= c */
#define TIC_TRS_A2GEUDI       0x1f8    /* udint     a := b >= c */
#define TIC_TRS_A2EQUDI       0x1f9    /* udint     a := b == c */
#define TIC_TRS_A2NEUDI       0x1fa    /* udint     a := b != c */
                        
#define TIC_OUT_A2MUDI        0x1fb    /* udint     a := b * c */
#define TIC_OUT_A2DUDI        0x1fc    /* udint     a := b / c */
#define TIC_OUT_A2AUDI        0x1fd    /* udint     a := b + c */
#define TIC_OUT_A2SUDI        0x1fe    /* udint     a := b - c */
#define TIC_OUT_A2LTUDI       0x1ff    /* udint     a := b < c */
#define TIC_OUT_A2GTUDI       0x200    /* udint     a := b > c */
#define TIC_OUT_A2LEUDI       0x201    /* udint     a := b <= c */
#define TIC_OUT_A2GEUDI       0x202    /* udint     a := b >= c */
#define TIC_OUT_A2EQUDI       0x203    /* udint     a := b == c */
#define TIC_OUT_A2NEUDI       0x204    /* udint     a := b != c */
#define TIC_OUT_A3UDI         0x205    /* udint     a := b */
#define TIC_OUT_A4UDI         0x206    /* udint     a := call b */
#define TIC_OUT_A5UDI         0x207    /* udint     a := b [ c ] */ 
#define TIC_OUT_A6UDI         0x208    /* udint     a [ b ] := c */
                        
                        
#define TIC_SYS_GPARUDI       0x209    /* udint get param */
                        
#define TIC_SYS_PPARUDI       0x20a    /* udint put param */

#define TIC_SYS_GPARBLKUDI    0x20b    /* udint get param */

#define TIC_USF_A4UDI         0x20c    /* udint     a := call b */
#define TIC_USF_OUT_A4UDI     0x20d    /* udint     a := call b on output */

#define TIC_STD_A4UDI         0x20e    /* udint     a := call b */
#define TIC_STD_OUT_A4UDI     0x20f    /* udint     a := call b on output */


/* 
 * LINT type 
 */
#define TIC_A1SLIN            0x210    /* lint     a := - b */
#define TIC_A2MLIN            0x211    /* lint     a := b * c */
#define TIC_A2DLIN            0x212    /* lint     a := b / c */
#define TIC_A2ALIN            0x213    /* lint     a := b + c */
#define TIC_A2SLIN            0x214    /* lint     a := b - c */
#define TIC_A2LTLIN           0x215    /* lint     a := b < c */
#define TIC_A2GTLIN           0x216    /* lint     a := b > c */
#define TIC_A2LELIN           0x217    /* lint     a := b <= c */
#define TIC_A2GELIN           0x218    /* lint     a := b >= c */
#define TIC_A2EQLIN           0x219	  /* lint     a := b == c */
#define TIC_A2NELIN           0x21a	  /* lint     a := b != c */
#define TIC_A3LIN             0x21b    /* lint     a := b */

#define TIC_A4LIN             0x21c    /* lint     a := call b */

#define TIC_A5LIN             0x21d    /* lint     a := b [ c ] */ 
#define TIC_A6LIN             0x21e    /* lint     a [ b ] := c */
#define TIC_P1LIN             0x21f    /* lint param */
                        
#define TIC_TRS_A2LTLIN       0x220    /* lint     a := b < c */
#define TIC_TRS_A2GTLIN       0x221    /* lint     a := b > c */
#define TIC_TRS_A2LELIN       0x222    /* lint     a := b <= c */
#define TIC_TRS_A2GELIN       0x223    /* lint     a := b >= c */
#define TIC_TRS_A2EQLIN       0x224    /* lint     a := b == c */
#define TIC_TRS_A2NELIN       0x225    /* lint     a := b != c */
                        
#define TIC_OUT_A1SLIN        0x226    /* lint     a := - b */
#define TIC_OUT_A2MLIN        0x227    /* lint     a := b * c */
#define TIC_OUT_A2DLIN        0x228    /* lint     a := b / c */
#define TIC_OUT_A2ALIN        0x229    /* lint     a := b + c */
#define TIC_OUT_A2SLIN        0x22a    /* lint     a := b - c */
#define TIC_OUT_A2LTLIN       0x22b    /* lint     a := b < c */
#define TIC_OUT_A2GTLIN       0x22c    /* lint     a := b > c */
#define TIC_OUT_A2LELIN       0x22d    /* lint     a := b <= c */
#define TIC_OUT_A2GELIN       0x22e    /* lint     a := b >= c */
#define TIC_OUT_A2EQLIN       0x22f    /* lint     a := b == c */
#define TIC_OUT_A2NELIN       0x230    /* lint     a := b != c */
#define TIC_OUT_A3LIN         0x231    /* lint     a := b */
#define TIC_OUT_A4LIN         0x232    /* lint     a := call b */
#define TIC_OUT_A5LIN         0x233    /* lint     a := b [ c ] */ 
#define TIC_OUT_A6LIN         0x234    /* lint     a [ b ] := c */
                        
                        
#define TIC_SYS_GPARLIN       0x235    /* lint get param */
                        
#define TIC_SYS_PPARLIN       0x236    /* lint put param */

#define TIC_SYS_GPARBLKLIN    0x237    /* lint get param */

#define TIC_USF_A4LIN         0x238    /* lint     a := call b */
#define TIC_USF_OUT_A4LIN     0x239    /* lint     a := call b on output */

#define TIC_STD_A4LIN         0x23a    /* lint     a := call b */
#define TIC_STD_OUT_A4LIN      0x23b    /* lint     a := call b on output */

/* 
 * ULINT type 
 */
#define TIC_A2MULI            0x23c    /* ulint     a := b * c */
#define TIC_A2DULI            0x23d    /* ulint     a := b / c */
#define TIC_A2AULI            0x23e    /* ulint     a := b + c */
#define TIC_A2SULI            0x23f    /* ulint     a := b - c */
#define TIC_A2LTULI           0x240    /* ulint     a := b < c */
#define TIC_A2GTULI           0x241    /* ulint     a := b > c */
#define TIC_A2LEULI           0x242    /* ulint     a := b <= c */
#define TIC_A2GEULI           0x243    /* ulint     a := b >= c */
#define TIC_A2EQULI           0x244	   /* ulint     a := b == c */
#define TIC_A2NEULI           0x245	   /* ulint     a := b != c */
#define TIC_A3ULI             0x246    /* ulint     a := b */

#define TIC_A4ULI             0x247    /* ulint     a := call b */
                        
#define TIC_A5ULI             0x248    /* ulint     a := b [ c ] */ 
#define TIC_A6ULI             0x249    /* ulint     a [ b ] := c */
#define TIC_P1ULI             0x24a    /* ulint param */
                        
#define TIC_TRS_A2LTULI       0x24b    /* ulint     a := b < c */
#define TIC_TRS_A2GTULI       0x24c    /* ulint     a := b > c */
#define TIC_TRS_A2LEULI       0x24d    /* ulint     a := b <= c */
#define TIC_TRS_A2GEULI       0x24e    /* ulint     a := b >= c */
#define TIC_TRS_A2EQULI       0x24f    /* ulint     a := b == c */
#define TIC_TRS_A2NEULI       0x250    /* ulint     a := b != c */
                        
#define TIC_OUT_A2MULI        0x251    /* ulint     a := b * c */
#define TIC_OUT_A2DULI        0x252    /* ulint     a := b / c */
#define TIC_OUT_A2AULI        0x253    /* ulint     a := b + c */
#define TIC_OUT_A2SULI        0x254    /* ulint     a := b - c */
#define TIC_OUT_A2LTULI       0x255    /* ulint     a := b < c */
#define TIC_OUT_A2GTULI       0x256    /* ulint     a := b > c */
#define TIC_OUT_A2LEULI       0x257    /* ulint     a := b <= c */
#define TIC_OUT_A2GEULI       0x258    /* ulint     a := b >= c */
#define TIC_OUT_A2EQULI       0x259    /* ulint     a := b == c */
#define TIC_OUT_A2NEULI       0x25a    /* ulint     a := b != c */
#define TIC_OUT_A3ULI         0x25b    /* ulint     a := b */
#define TIC_OUT_A4ULI         0x25c    /* ulint     a := call b */
#define TIC_OUT_A5ULI         0x25d    /* ulint     a := b [ c ] */ 
#define TIC_OUT_A6ULI         0x25e    /* ulint     a [ b ] := c */
                        
                        
#define TIC_SYS_GPARULI       0x25f    /* ulint get param */

#define TIC_SYS_PPARULI       0x260    /* ulint put param */

#define TIC_SYS_GPARBLKULI    0x261    /* ulint get param */

#define TIC_USF_A4ULI         0x262    /* ulint     a := call b */
#define TIC_USF_OUT_A4ULI     0x263    /* ulint     a := call b on output */

#define TIC_STD_A4ULI         0x264    /* ulint     a := call b */
#define TIC_STD_OUT_A4ULI     0x265    /* ulint     a := call b on output */

/* 
 * DATE type 
 */
#define TIC_A2LTDAT           0x266    /* date     a := b < c */
#define TIC_A2GTDAT           0x267    /* date     a := b > c */
#define TIC_A2LEDAT           0x268    /* date     a := b <= c */
#define TIC_A2GEDAT           0x269    /* date     a := b >= c */
#define TIC_A2EQDAT           0x26a	   /* date     a := b == c */
#define TIC_A2NEDAT           0x26b	   /* date     a := b != c */
#define TIC_A3DAT             0x26c    /* date     a := b */

#define TIC_A4DAT             0x26d    /* date     a := call b */
                        
#define TIC_A5DAT             0x26e    /* date     a := b [ c ] */ 
#define TIC_A6DAT             0x26f    /* date     a [ b ] := c */
#define TIC_P1DAT             0x270    /* date param */
                        
#define TIC_TRS_A2LTDAT       0x271    /* date     a := b < c */
#define TIC_TRS_A2GTDAT       0x272    /* date     a := b > c */
#define TIC_TRS_A2LEDAT       0x273    /* date     a := b <= c */
#define TIC_TRS_A2GEDAT       0x274    /* date     a := b >= c */
#define TIC_TRS_A2EQDAT       0x275    /* date     a := b == c */
#define TIC_TRS_A2NEDAT       0x276    /* date     a := b != c */
                        
#define TIC_OUT_A2LTDAT       0x277    /* date     a := b < c */
#define TIC_OUT_A2GTDAT       0x278    /* date     a := b > c */
#define TIC_OUT_A2LEDAT       0x279    /* date     a := b <= c */
#define TIC_OUT_A2GEDAT       0x27a    /* date     a := b >= c */
#define TIC_OUT_A2EQDAT       0x27b    /* date     a := b == c */
#define TIC_OUT_A2NEDAT       0x27c    /* date     a := b != c */
#define TIC_OUT_A3DAT         0x27d    /* date     a := b */
#define TIC_OUT_A4DAT         0x27e    /* date     a := call b */
#define TIC_OUT_A5DAT         0x27f    /* date     a := b [ c ] */ 
#define TIC_OUT_A6DAT         0x280    /* date     a [ b ] := c */
       
                 
#define TIC_SYS_GPARDAT       0x281    /* date get param */

#define TIC_SYS_PPARDAT       0x282    /* date put param */

#define TIC_SYS_GPARBLKDAT    0x283    /* date get param */

#define TIC_USF_A4DAT         0x284    /* date     a := call b */
#define TIC_USF_OUT_A4DAT     0x285    /* date     a := call b on output */

#define TIC_STD_A4DAT         0x286    /* date     a := call b */
#define TIC_STD_OUT_A4DAT     0x287    /* date     a := call b on output */

#define TIC_SYS_SUBDAT        0x288    /* substraction of two dates -> timer output */
#define TIC_OUT_SUBDAT        0x289

/* 
 * LREAL type 
 */
#define TIC_A1SLRE           0x28a   /* lreal     a := - b */
#define TIC_A2MLRE           0x28b   /* lreal     a := b * c */
#define TIC_A2DLRE           0x28c   /* lreal     a := b / c */
#define TIC_A2ALRE           0x28d   /* lreal     a := b + c */
#define TIC_A2SLRE           0x28e   /* lreal     a := b - c */
#define TIC_A2LTLRE          0x28f   /* lreal     a := b < c */
#define TIC_A2GTLRE          0x290   /* lreal     a := b > c */
#define TIC_A2LELRE          0x291   /* lreal     a := b <= c */
#define TIC_A2GELRE          0x292   /* lreal     a := b >= c */
#define TIC_A2EQLRE          0x293   /* lreal     a := b == c */
#define TIC_A2NELRE          0x294   /* lreal     a := b != c */
#define TIC_A3LRE            0x295   /* lreal     a := b */

#define TIC_A4LRE            0x296   /* lreal     a := call b */
                        
#define TIC_A5LRE            0x297   /* lreal     a := b [ c ] */ 
#define TIC_A6LRE            0x298   /* lreal     a [ b ] := c */
#define TIC_P1LRE            0x29a   /* lreal param */
                        
#define TIC_TRS_A2LTLRE      0x29b   /* lreal     a := b < c */
#define TIC_TRS_A2GTLRE      0x29c   /* lreal     a := b > c */
#define TIC_TRS_A2LELRE      0x29d   /* lreal     a := b <= c */
#define TIC_TRS_A2GELRE      0x29e   /* lreal     a := b >= c */
#define TIC_TRS_A2EQLRE      0x29f   /* lreal     a := b == c */
#define TIC_TRS_A2NELRE      0x2a0   /* lreal     a := b != c */
                        
#define TIC_OUT_A1SLRE       0x2a1   /* lreal     a := - b */
#define TIC_OUT_A2MLRE       0x2a2   /* lreal     a := b * c */
#define TIC_OUT_A2DLRE       0x2a3   /* lreal     a := b / c */
#define TIC_OUT_A2ALRE       0x2a4   /* lreal     a := b + c */
#define TIC_OUT_A2SLRE       0x2a5   /* lreal     a := b - c */
#define TIC_OUT_A2LTLRE      0x2a6   /* lreal     a := b < c */
#define TIC_OUT_A2GTLRE      0x2a7   /* lreal     a := b > c */
#define TIC_OUT_A2LELRE      0x2a8   /* lreal     a := b <= c */
#define TIC_OUT_A2GELRE      0x2a9   /* lreal     a := b >= c */
#define TIC_OUT_A2EQLRE      0x2aa   /* lreal     a := b == c */
#define TIC_OUT_A2NELRE      0x2ab   /* lreal     a := b != c */
#define TIC_OUT_A3LRE        0x2ac   /* lreal     a := b */
#define TIC_OUT_A4LRE        0x2ad   /* lreal     a := call b */
#define TIC_OUT_A5LRE        0x2ae   /* lreal     a := b [ c ] */ 
#define TIC_OUT_A6LRE        0x2af   /* lreal     a [ b ] := c */
                        
                        
#define TIC_SYS_GPARLRE      0x2b0   /* lreal get param */

#define TIC_SYS_PPARLRE      0x2b1   /*  put param */

#define TIC_SYS_GPARBLKLRE   0x2b2   /* lreal get param */

#define TIC_USF_A4LRE        0x2b3   /* lreal     a := call b */
#define TIC_USF_OUT_A4LRE    0x2b4   /* lreal     a := call b on output */

#define TIC_STD_A4LRE        0x2b5   /* lreal     a := call b */
#define TIC_STD_OUT_A4LRE    0x2b6   /* lreal     a := call b on output */

/* 
 * Basic operations 
 * Extension 1
 */
#define TIC_TRS_A6B          0x0121   /* boolean  a [ b ] := c on SFC trans */
#define TIC_OUT_A2AT         0x0122   /* time     a := b + c on output */
#define TIC_OUT_A2ST         0x0123   /* time     a := b - c on output */
#define TIC_OUT_A6T          0x0124   /* time     a [ b ] := c  on output */

/* Parameter reference */
#define TIC_A5               0x0125   /* parameter reference  a := &b [ c ] */
#define TIC_PA5              0x0126   /* param ref on 'ptr VA' a := &(*b[c]) */

/*
 * Functions call parameter passing: PushPar (param) 
 * Extension 2
 */
#define TIC_P1               0x0127   /* complex type (struct) param */
#define TIC_P2               0x0128   /* param of param, push value */

/*
 * IEC functions & function blocks calling parameter access 
 * GetPar (Where to assign value, Param number) 
 * Extension 1
 */
#define TIC_SYS_GPAR         0x0129   /* reference get param */

/* 
 * IEC functions & function blocks
 * Parameter processing: 'Pointer VA' 
 */
#define TIC_PA5B             0x012a   /* boolean  a := *b [ c ] */
#define TIC_PA5I             0x012b   /* dint     a := *b [ c ] */
#define TIC_PA5R             0x012c   /* real     a := *b [ c ] */
#define TIC_PA5T             0x012d   /* time     a := *b [ c ] */
#define TIC_PA5M             0x012e   /* string   a := *b [ c ] */
#define TIC_PA5S             0x012f   /* sint     a := *b [ c ] */
#define TIC_PA5USI			  0x2b7	  /* usint    a := *b [ c ] */
#define TIC_PA5INT			  0x2b8	  /* int      a := *b [ c ] */
#define TIC_PA5UIN			  0x2b9	  /* uint     a := *b [ c ] */
#define TIC_PA5UDI			  0x2ba	  /* udint    a := *b [ c ] */
#define TIC_PA5LIN			  0x2bb	  /* lint     a := *b [ c ] */
#define TIC_PA5ULI			  0x2bc	  /* ulint    a := *b [ c ] */
#define TIC_PA5DAT			  0x2bd	  /* date     a := *b [ c ] */
#define TIC_PA5LRE			  0x2be	  /* lreal    a := *b [ c ] */
                     
#define TIC_PA6B             0x0130   /* boolean  *a [ b ] := c */
#define TIC_PA6I             0x0131   /* dint     *a [ b ] := c */
#define TIC_PA6R             0x0132   /* real     *a [ b ] := c */
#define TIC_PA6T             0x0133   /* time     *a [ b ] := c */
#define TIC_PA6M             0x0134   /* string   *a [ b ] := c */
#define TIC_PA6S             0x0135   /* sint     *a [ b ] := c */
#define TIC_PA6USI			  0x2bf	  /* usint    *a [ b ] := c */
#define TIC_PA6INT			  0x2c0	  /* int      *a [ b ] := c */
#define TIC_PA6UIN			  0x2c1	  /* uint     *a [ b ] := c */
#define TIC_PA6UDI			  0x2c2	  /* udint    *a [ b ] := c */
#define TIC_PA6LIN           0x2c3    /* lint     *a [ b ] := c */
#define TIC_PA6ULI			  0x2c4	  /* ulint    *a [ b ] := c */
#define TIC_PA6DAT			  0x2c5	  /* date     *a [ b ] := c */
#define TIC_PA6LRE			  0x2c6	  /* lreal    *a [ b ] := c */
                     
#define TIC_OUT_PA5B         0x0136   /* boolean  a := *b [ c ] on output */
#define TIC_OUT_PA5I         0x0137   /* dint     a := *b [ c ] on output */
#define TIC_OUT_PA5R         0x0138   /* real     a := *b [ c ] on output */
#define TIC_OUT_PA5T         0x0139   /* time     a := *b [ c ] on output */
#define TIC_OUT_PA5M         0x013a   /* string   a := *b [ c ] on output */
#define TIC_OUT_PA5S         0x013b   /* sint     a := *b [ c ] on output */
#define TIC_OUT_PA5USI		  0x2c7	  /* usint    a := *b [ c ] on output */
#define TIC_OUT_PA5INT		  0x2c8	  /* int      a := *b [ c ] on output */
#define TIC_OUT_PA5UIN		  0x2c9	  /* uint     a := *b [ c ] on output  */
#define TIC_OUT_PA5UDI		  0x2ca	  /* udint    a := *b [ c ] on output  */
#define TIC_OUT_PA5LIN		  0x2cb	  /* lint     a := *b [ c ] on output  */
#define TIC_OUT_PA5ULI		  0x2cc	  /* ulint    a := *b [ c ] on output  */
#define TIC_OUT_PA5DAT		  0x2cd	  /* date     a := *b [ c ] on output */
#define TIC_OUT_PA5LRE		  0x2ce	  /* lreal     a := *b [ c ] on output */
                     
#define TIC_OUT_PA6B         0x013c   /* boolean  *a [ b ] := c on output */
#define TIC_OUT_PA6I         0x013d   /* dint     *a [ b ] := c on output */
#define TIC_OUT_PA6R         0x013e   /* real     *a [ b ] := c on output */
#define TIC_OUT_PA6T         0x013f   /* time     *a [ b ] := c on output */
#define TIC_OUT_PA6M         0x0140   /* string   *a [ b ] := c on output */
#define TIC_OUT_PA6S         0x0141   /* sint     *a [ b ] := c on output */
#define TIC_OUT_PA6USI		  0x2cf	  /* usint    *a [ b ] := c */
#define TIC_OUT_PA6INT		  0x2d0	  /* int      *a [ b ] := c */
#define TIC_OUT_PA6UIN		  0x2d1	  /* uint     *a [ b ] := c */
#define TIC_OUT_PA6UDI		  0x2d2	  /* udint    *a [ b ] := c */
#define TIC_OUT_PA6LIN		  0x2d3	  /* lint     *a [ b ] := c */
#define TIC_OUT_PA6ULI		  0x2d4	  /* ulint    *a [ b ] := c */
#define TIC_OUT_PA6DAT		  0x2d5	  /* date     *a [ b ] := c */
#define TIC_OUT_PA6LRE		  0x2d6	  /* lreal    *a [ b ] := c */
                     
#define TIC_TRS_PA5B         0x0142   /* boolean  a := *b [ c ] on SFC trans */
#define TIC_TRS_PA6B         0x0143   /* boolean  a := *b [ c ] on SFC trans */

/*
 * IEC functions & function blocks return parameter put-in 
 * PutPar (Param number, Where to retrieve value to return) 
 * Param number = 0 for functions 
 * Extension 1
 */
#define TIC_SYS_PPAR         0x0144   /* reference put param */

/* 
 * User 'C' function block call 
 * a = Block Number
 * Extension 1 (no more instance number)
 */
#define TIC_FBL_CALL         0x0145   /* nil      call a */

/* 
 * Standard function block call
 * a = Block Number
 * Extension 1 (no more instance number)
 */
#define TIC_STD_FBL_CALL     0x0146   /* nil      call a */

/* 
 * Bit Access 
 * c = bit number
 */
#define TIC_RBIT_SINT        0x0147   /* sint read bit  a   := b.c */
#define TIC_WBIT_SINT        0x0148   /* sint write bit a.c := b   */
#define TIC_RBIT_DINT        0x0149   /* dint read bit  a   := b.c */
#define TIC_WBIT_DINT        0x014a   /* dint write bit a.c := b   */
#define TIC_RBIT_USINT       0x2d7    /* usint read bit  a   := b.c */
#define TIC_WBIT_USINT       0x2d8    /* usint write bit a.c := b   */
#define TIC_RBIT_INT		     0x2d9    /* int read bit  a   := b.c */
#define TIC_WBIT_INT		     0x2da    /* int write bit a.c := b   */
#define TIC_RBIT_UINT		  0x2db    /* uint read bit  a   := b.c */
#define TIC_WBIT_UINT		  0x2dc    /* uint write bit a.c := b   */
#define TIC_RBIT_UDINT		  0x2dd    /* udint read bit  a   := b.c */
#define TIC_WBIT_UDINT		  0x2de    /* udint write bit a.c := b   */
#define TIC_RBIT_LINT		  0x2df    /* lint read bit  a   := b.c */
#define TIC_WBIT_LINT		  0x2e0    /* lint write bit a.c := b   */
#define TIC_RBIT_ULINT		  0x2e1    /* ulint read bit  a   := b.c */
#define TIC_WBIT_ULINT		  0x2e2    /* ulint write bit a.c := b   */
                           
#define TIC_OUT_RBIT_SINT    0x014b   /* sint read bit  a   := b.c on ouptut */
#define TIC_OUT_WBIT_SINT    0x014c   /* sint write bit a.c := b   on ouptut */
#define TIC_OUT_RBIT_DINT    0x014d   /* dint read bit  a   := b.c on ouptut */
#define TIC_OUT_WBIT_DINT    0x014e   /* dint write bit a.c := b   on ouptut */
#define TIC_OUT_RBIT_USINT   0x2e3    /* usint read bit  a   := b.c */
#define TIC_OUT_WBIT_USINT   0x2e4    /* usint write bit a.c := b   */
#define TIC_OUT_RBIT_INT	 0x2e5    /* int read bit  a   := b.c */
#define TIC_OUT_WBIT_INT	 0x2e6    /* int write bit a.c := b   */
#define TIC_OUT_RBIT_UINT	 0x2e7    /* uint read bit  a   := b.c */
#define TIC_OUT_WBIT_UINT	 0x2e8    /* uint write bit a.c := b   */
#define TIC_OUT_RBIT_UDINT	 0x2e9    /* udint read bit  a   := b.c */
#define TIC_OUT_WBIT_UDINT	 0x2ea    /* udint write bit a.c := b   */
#define TIC_OUT_RBIT_LINT	 0x2eb    /* lint read bit  a   := b.c */
#define TIC_OUT_WBIT_LINT	 0x2ec    /* lint write bit a.c := b   */
#define TIC_OUT_RBIT_ULINT	 0x2ed    /* ulint read bit  a   := b.c */
#define TIC_OUT_WBIT_ULINT	 0x2ee    /* ulint write bit a.c := b   */
	                           
/*                         
 * Memory block copy       
 * c = sizeof              
 */                        
#define TIC_MEM_CPY          0x014f   /* memcpy(a, b ,c)   */
#define TIC_MEM_CPYVAAFF     0x0150   /* memcpy(*a, b, c)  */
#define TIC_MEM_CPYVA        0x0151   /* memcpy(*a, *b, c) */

#define TIC_OUT_MEM_CPY      0x0152   /* memcpy(a, b ,c)   on ouptut */
#define TIC_OUT_MEM_CPYVAAFF 0x0153   /* memcpy(*a, b, c)  on ouptut */
#define TIC_OUT_MEM_CPYVA    0x0154   /* memcpy(*a, *b, c) on ouptut */

/* Boundary Check */
#define TIC_BNDCHK_DINT      0x0155   /* check that c belongs to [a b] */

/*
 * IEC SFC FB
 */
#define TIC_SEQ_A4B          0x015e   /* Call SFC function block */
#define TIC_SYS_PADAC        0x015f   /* time activity */
#define TIC_SYS_PAGSTART     0x0160   /* start an sfc child */        
#define TIC_SYS_PAGKILL      0x0161   /* kill an sfc child */
#define TIC_SYS_PAGFREEZE    0x0162   /* freeze an sfc child */
#define TIC_SYS_PAGRST       0x0163   /* restart an sfc child */
#define TIC_SYS_PAGSTATUS    0x0164   /* recup current status of an sfc child*/
#define TIC_SYS_PAGSTART_EXT 0x02ef   /* start an sfc child with input parameters */        
#define TIC_SYS_PAGRST_EXT   0x02f0   /* restart an sfc child with input parameters */

 /*
* Management of the call stack
*/
/* Push/pop for step by step debugging call stack */
#define TIC_CSTK_PUSH        0x0156   /* push entry in call stack */
#define TIC_CSTK_POP         0x0157   /* pop entry in call stack */

/*
* Management of long jump
*/
#define TIC_I1_LGPOS         0x0158   /* unconditional long positive jump */
#define TIC_I1_LGNEG         0x0159   /* unconditional long negative jump */
#define TIC_C1B_LGPOS        0x015a   /* if a goto b (long positive jump) */
#define TIC_C1B_LGNEG        0x015b   /* if a goto b (long negative jump) */
#define TIC_C2B_LGPOS        0x015c   /* if not a goto b (long positive jump) */
#define TIC_C2B_LGNEG        0x015d   /* if not a goto b (long negative jump) */

/* JIT codes */

#define TIC_JIT_NOP			0x0f01	/* empty code */
#define TIC_JIT_CALL			0x0f02	/* call jit code block */

/*
* New TIC Code added to optimize LD instructions
*/
#define TIC_A2GTS_EN       0x02f1      /* sint     if (i) a := b < c */
#define TIC_A2GTUSI_EN     0x02f2      /* usint    if (i) a := b < c */
#define TIC_A2GTINT_EN     0x02f3      /* int      if (i) a := b < c */
#define TIC_A2GTUIN_EN     0x02f4      /* uint     if (i) a := b < c */
#define TIC_A2GTI_EN       0x02f5      /* dint     if (i) a := b < c */
#define TIC_A2GTUDI_EN     0x02f6      /* udint    if (i) a := b < c */
#define TIC_A2GTLIN_EN     0x02f7      /* lint     if (i) a := b < c */
#define TIC_A2GTULI_EN     0x02f8      /* ulint    if (i) a := b < c */
#define TIC_A2GTDAT_EN     0x02f9      /* date     if (i) a := b < c */
#define TIC_A2GTT_EN       0x02fa      /* time     if (i) a := b < c */
#define TIC_A2GTM_EN       0x02fb      /* string   if (i) a := b < c */
#define TIC_A2GTR_EN       0x02fc      /* real     if (i) a := b < c */
#define TIC_A2GTLRE_EN     0x02fd      /* lreal    if (i) a := b < c */

#define TIC_A2GES_EN       0x02fe      /* sint     if (i) a := b <= c */
#define TIC_A2GEUSI_EN     0x02ff      /* usint    if (i) a := b <= c */
#define TIC_A2GEINT_EN     0x0300      /* int      if (i) a := b <= c */
#define TIC_A2GEUIN_EN     0x0301      /* uint     if (i) a := b <= c */
#define TIC_A2GEI_EN       0x0302      /* dint     if (i) a := b <= c */
#define TIC_A2GEUDI_EN     0x0303      /* udint    if (i) a := b <= c */
#define TIC_A2GELIN_EN     0x0304      /* lint     if (i) a := b <= c */
#define TIC_A2GEULI_EN     0x0305      /* ulint    if (i) a := b <= c */
#define TIC_A2GEDAT_EN     0x0306      /* date     if (i) a := b <= c */
#define TIC_A2GET_EN       0x0307      /* time     if (i) a := b <= c */
#define TIC_A2GEM_EN       0x0308      /* string   if (i) a := b <= c */
#define TIC_A2GER_EN       0x0309      /* real     if (i) a := b <= c */
#define TIC_A2GELRE_EN     0x030a      /* lreal    if (i) a := b <= c */

#define TIC_A2LTS_EN       0x030b      /* sint     if (i) a := b > c */
#define TIC_A2LTUSI_EN     0x030c      /* usint    if (i) a := b > c */
#define TIC_A2LTINT_EN     0x030d      /* int      if (i) a := b > c */
#define TIC_A2LTUIN_EN     0x030e      /* uint     if (i) a := b > c */
#define TIC_A2LTI_EN       0x030f      /* dint     if (i) a := b > c */
#define TIC_A2LTUDI_EN     0x0310      /* udint    if (i) a := b > c */
#define TIC_A2LTLIN_EN     0x0311      /* lint     if (i) a := b > c */
#define TIC_A2LTULI_EN     0x0312      /* ulint    if (i) a := b > c */
#define TIC_A2LTDAT_EN     0x0313      /* date     if (i) a := b > c */
#define TIC_A2LTT_EN       0x0314      /* time     if (i) a := b > c */
#define TIC_A2LTM_EN       0x0315      /* string   if (i) a := b > c */
#define TIC_A2LTR_EN       0x0316      /* real     if (i) a := b > c */
#define TIC_A2LTLRE_EN     0x0317      /* lreal    if (i) a := b > c */

#define TIC_A2LES_EN       0x0318      /* sint     if (i) a := b >= c */
#define TIC_A2LEUSI_EN     0x0319      /* usint    if (i) a := b >= c */
#define TIC_A2LEINT_EN     0x031a      /* int      if (i) a := b >= c */
#define TIC_A2LEUIN_EN     0x031b      /* uint     if (i) a := b >= c */
#define TIC_A2LEI_EN       0x031c      /* dint     if (i) a := b >= c */
#define TIC_A2LEUDI_EN     0x031d      /* udint    if (i) a := b >= c */
#define TIC_A2LELIN_EN     0x031e      /* lint     if (i) a := b >= c */
#define TIC_A2LEULI_EN     0x031f      /* ulint    if (i) a := b >= c */
#define TIC_A2LEDAT_EN     0x0320      /* date     if (i) a := b >= c */
#define TIC_A2LET_EN       0x0321      /* time     if (i) a := b >= c */
#define TIC_A2LEM_EN       0x0322      /* string   if (i) a := b >= c */
#define TIC_A2LER_EN       0x0323      /* real     if (i) a := b >= c */
#define TIC_A2LELRE_EN     0x0324      /* lreal    if (i) a := b >= c */
#define TIC_A2EQB_EN       0x0325      /* bool     if (i) a := b == c */

#define TIC_A2EQS_EN       0x0326      /* sint     if (i) a := b == c */
#define TIC_A2EQUSI_EN     0x0327      /* usint    if (i) a := b == c */
#define TIC_A2EQINT_EN     0x0328      /* int      if (i) a := b == c */
#define TIC_A2EQUIN_EN     0x0329      /* uint     if (i) a := b == c */
#define TIC_A2EQI_EN       0x032a      /* dint     if (i) a := b == c */
#define TIC_A2EQUDI_EN     0x032b      /* udint    if (i) a := b == c */
#define TIC_A2EQLIN_EN     0x032c      /* lint     if (i) a := b == c */
#define TIC_A2EQULI_EN     0x032d      /* ulint    if (i) a := b == c */
#define TIC_A2EQDAT_EN     0x032e      /* date     if (i) a := b == c */
#define TIC_A2EQT_EN       0x032f      /* time     if (i) a := b == c */
#define TIC_A2EQM_EN       0x0330      /* string   if (i) a := b == c */
#define TIC_A2EQR_EN       0x0331      /* real     if (i) a := b == c */
#define TIC_A2EQLRE_EN     0x0332      /* lreal    if (i) a := b == c */

#define TIC_A2NEB_EN       0x0333      /* bool     if (i) a := b != c */
#define TIC_A2NES_EN       0x0334      /* sint     if (i) a := b != c */
#define TIC_A2NEUSI_EN     0x0335      /* usint    if (i) a := b != c */
#define TIC_A2NEINT_EN     0x0336      /* int      if (i) a := b != c */
#define TIC_A2NEUIN_EN     0x0337      /* uint     if (i) a := b != c */
#define TIC_A2NEI_EN       0x0338      /* dint     if (i) a := b != c */
#define TIC_A2NEUDI_EN     0x0339      /* udint    if (i) a := b != c */
#define TIC_A2NELIN_EN     0x033a      /* lint     if (i) a := b != c */
#define TIC_A2NEULI_EN     0x033b      /* ulint    if (i) a := b != c */
#define TIC_A2NEDAT_EN     0x033c      /* date     if (i) a := b != c */
#define TIC_A2NET_EN       0x033d      /* time     if (i) a := b != c */
#define TIC_A2NEM_EN       0x033e      /* string   if (i) a := b != c */
#define TIC_A2NER_EN       0x033f      /* real     if (i) a := b != c */
#define TIC_A2NELRE_EN     0x0340      /* lreal    if (i) a := b != c */

#define TIC_A2AS_EN        0x0341      /* sint     if (i) a := b + c + d + ... */
#define TIC_A2AUSI_EN      0x0342      /* usint    if (i) a := b + c + d + ... */
#define TIC_A2AINT_EN      0x0343      /* int      if (i) a := b + c + d + ... */
#define TIC_A2AUIN_EN      0x0344      /* uint     if (i) a := b + c + d + ... */
#define TIC_A2AI_EN        0x0345      /* dint     if (i) a := b + c + d + ... */
#define TIC_A2AUDI_EN      0x0346      /* udint    if (i) a := b + c + d + ... */
#define TIC_A2ALIN_EN      0x0347      /* lint     if (i) a := b + c + d + ... */
#define TIC_A2AULI_EN      0x0348      /* ulint    if (i) a := b + c + d + ... */
#define TIC_A2AT_EN        0x034a      /* time     if (i) a := b + c + d + ... */
#define TIC_A2AM_EN        0x034b      /* string   if (i) a := b + c + d + ... */
#define TIC_A2AR_EN        0x034c      /* real     if (i) a := b + c + d + ... */
#define TIC_A2ALRE_EN      0x034d      /* lreal    if (i) a := b + c + d + ... */

#define TIC_A2MS_EN        0x034e      /* sint     if (i) a := b * c * d * ... */
#define TIC_A2MUSI_EN      0x034f      /* usint    if (i) a := b * c * d * ... */
#define TIC_A2MINT_EN      0x0350      /* int      if (i) a := b * c * d * ... */
#define TIC_A2MUIN_EN      0x0351      /* uint     if (i) a := b * c * d * ... */
#define TIC_A2MI_EN        0x0352      /* dint     if (i) a := b * c * d * ... */
#define TIC_A2MUDI_EN      0x0353      /* udint    if (i) a := b * c * d * ... */
#define TIC_A2MLIN_EN      0x0354      /* lint     if (i) a := b * c * d * ... */
#define TIC_A2MULI_EN      0x0355      /* ulint    if (i) a := b * c * d * ... */
#define TIC_A2MR_EN        0x0356      /* real     if (i) a := b * c * d * ... */
#define TIC_A2MLRE_EN      0x0357      /* lreal    if (i) a := b * c * d * ... */

#define TIC_A2SS_EN        0x0358      /* sint     if (i) a := b - c - d  ... */
#define TIC_A2SUSI_EN      0x0359      /* usint    if (i) a := b - c - d  ... */
#define TIC_A2SINT_EN      0x035a      /* int      if (i) a := b - c - d  ... */
#define TIC_A2SUIN_EN      0x035b      /* uint     if (i) a := b - c - d  ... */
#define TIC_A2SI_EN        0x035c      /* dint     if (i) a := b - c - d  ... */
#define TIC_A2SUDI_EN      0x035d      /* udint    if (i) a := b - c - d  ... */
#define TIC_A2SLIN_EN      0x035e      /* lint     if (i) a := b - c - d  ... */
#define TIC_A2SULI_EN      0x035f      /* ulint    if (i) a := b - c - d  ... */
#define TIC_A2ST_EN        0x0360      /* time     if (i) a := b - c - d  ... */
#define TIC_A2SR_EN        0x0361      /* real     if (i) a := b - c - d  ... */
#define TIC_A2SLRE_EN      0x0362      /* lreal    if (i) a := b - c - d  ... */

#define TIC_A2DS_EN        0x0363      /* sint     if (i) a := b / c / d  ... */
#define TIC_A2DUSI_EN      0x0364      /* usint    if (i) a := b / c / d  ... */
#define TIC_A2DINT_EN      0x0365      /* int      if (i) a := b / c / d  ... */
#define TIC_A2DUIN_EN      0x0366      /* uint     if (i) a := b / c / d  ... */
#define TIC_A2DI_EN        0x0367      /* dint     if (i) a := b / c / d  ... */
#define TIC_A2DUDI_EN      0x0368      /* udint    if (i) a := b / c / d  ... */
#define TIC_A2DLIN_EN      0x0369      /* lint     if (i) a := b / c / d  ... */
#define TIC_A2DULI_EN      0x036a      /* ulint    if (i) a := b / c / d  ... */
#define TIC_A2DR_EN        0x036b      /* real     if (i) a := b / c / d  ... */
#define TIC_A2DLRE_EN      0x036c      /* lreal    if (i) a := b / c / d  ... */

/* RFS 7583 BEGIN */
#define TIC_A3B_EN         0x036d      /* bool     if (i) a := b */
#define TIC_A3S_EN         0x036e      /* sint     if (i) a := b */
#define TIC_A3USI_EN       0x036f      /* usint    if (i) a := b */
#define TIC_A3INT_EN       0x0370      /* int      if (i) a := b */
#define TIC_A3UIN_EN       0x0371      /* uint     if (i) a := b */
#define TIC_A3I_EN         0x0372      /* dint     if (i) a := b */
#define TIC_A3UDI_EN       0x0373      /* udint    if (i) a := b */
#define TIC_A3LIN_EN       0x0374      /* lint     if (i) a := b */
#define TIC_A3ULI_EN       0x0375      /* ulint    if (i) a := b */
#define TIC_A3R_EN         0x0376      /* real     if (i) a := b */
#define TIC_A3LRE_EN       0x0377      /* lreal    if (i) a := b */
#define TIC_A3DAT_EN       0x0378      /* date     if (i) a := b */
#define TIC_A3T_EN         0x0379      /* time     if (i) a := b */
#define TIC_A3M_EN         0x037a      /* string   if (i) a := b */

#define TIC_A5B_EN         0x037b      /* bool     if (i) a := b [ c ] */
#define TIC_A5S_EN         0x037c      /* sint     if (i) a := b [ c ] */
#define TIC_A5USI_EN       0x037d      /* usint    if (i) a := b [ c ] */
#define TIC_A5INT_EN       0x037e      /* int      if (i) a := b [ c ] */
#define TIC_A5UIN_EN       0x037f      /* uint     if (i) a := b [ c ] */
#define TIC_A5I_EN         0x0380      /* dint     if (i) a := b [ c ] */
#define TIC_A5UDI_EN       0x0381      /* udint    if (i) a := b [ c ] */
#define TIC_A5LIN_EN       0x0382      /* lint     if (i) a := b [ c ] */
#define TIC_A5ULI_EN       0x0383      /* ulint    if (i) a := b [ c ] */
#define TIC_A5R_EN         0x0384      /* real     if (i) a := b [ c ] */
#define TIC_A5LRE_EN       0x0385      /* lreal    if (i) a := b [ c ] */
#define TIC_A5DAT_EN       0x0386      /* date     if (i) a := b [ c ] */
#define TIC_A5T_EN         0x0387      /* time     if (i) a := b [ c ] */
#define TIC_A5M_EN         0x0388      /* string   if (i) a := b [ c ] */


#define TIC_A6B_EN         0x0389      /* bool     if (i) a [ b ] := c */
#define TIC_A6S_EN         0x038a      /* sint     if (i) a [ b ] := c */
#define TIC_A6USI_EN       0x038b      /* usint    if (i) a [ b ] := c */
#define TIC_A6INT_EN       0x038c      /* int      if (i) a [ b ] := c */
#define TIC_A6UIN_EN       0x038d      /* uint     if (i) a [ b ] := c */
#define TIC_A6I_EN         0x038e      /* dint     if (i) a [ b ] := c */
#define TIC_A6UDI_EN       0x038f      /* udint    if (i) a [ b ] := c */
#define TIC_A6LIN_EN       0x0390      /* lint     if (i) a [ b ] := c */
#define TIC_A6ULI_EN       0x0391      /* ulint    if (i) a [ b ] := c */
#define TIC_A6R_EN         0x0392      /* real     if (i) a [ b ] := c */
#define TIC_A6LRE_EN       0x0393      /* lreal    if (i) a [ b ] := c */
#define TIC_A6DAT_EN       0x0394      /* date     if (i) a [ b ] := c */
#define TIC_A6T_EN         0x0395      /* time     if (i) a [ b ] := c */
#define TIC_A6M_EN         0x0396      /* string   if (i) a [ b ] := c */
/* RFS 7583 END */

#ifdef ITGTDEF_NEW_ARRAY_AND_FB
#define TIC_A3VA_PTR       0x0397      /* VA       *a := b                    */

#define TIC_A6VA           0x0398      /* VA       a [ b ] := c               */
#define TIC_A6VA_PTR_OFF   0x0399      /* VA       *((*a) [ b ]) := c         */

#define TIC_PA5B_PTR       0x039a      /* boolean  a := **b [ c ]             */
#define TIC_PA5I_PTR       0x039b      /* dint     a := **b [ c ]             */
#define TIC_PA5R_PTR       0x039c      /* real     a := **b [ c ]             */
#define TIC_PA5T_PTR       0x039d      /* time     a := **b [ c ]             */
#define TIC_PA5M_PTR       0x039e      /* string   a := **b [ c ]             */
#define TIC_PA5S_PTR       0x039f      /* sint     a := **b [ c ]             */
#define TIC_PA5USI_PTR     0x03a0      /* usint    a := **b [ c ]             */
#define TIC_PA5INT_PTR     0x03a1      /* int      a := **b [ c ]             */
#define TIC_PA5UIN_PTR     0x03a2      /* uint     a := **b [ c ]             */
#define TIC_PA5UDI_PTR     0x03a3      /* udint    a := **b [ c ]             */
#define TIC_PA5LIN_PTR     0x03a4      /* lint     a := **b [ c ]             */
#define TIC_PA5ULI_PTR     0x03a5      /* ulint    a := **b [ c ]             */
#define TIC_PA5DAT_PTR     0x03a6      /* date     a := **b [ c ]             */
#define TIC_PA5LRE_PTR     0x03a7      /* lreal    a := **b [ c ]             */
#define TIC_PA5VA_PTR      0x03a8      /* va       a := **b [ c ]             */

#define TIC_A3VA           0x03a9      /* va       a := b                     */

#define TIC_STD_FBL_PUSH_CALL          0x03aa   /* TIC_P1 + TIC_STD_FBL_CALL */
#define TIC_FBL_PUSH_CALL		         0x03ab	/* TIC_P1 + TIC_FBL_CALL */
#define TIC_A4B_PUSH_CALL		         0x03ac	/* TIC_P1 + TIC_A4B */
#define TIC_SEQ_A4B_PUSH_CALL		      0x03ad	/* TIC_P1 + TIC_SEQ_A4B */

#define TIC_STD_FBL_PUSH_PAR_CALL      0x03ae   /* TIC_P2 + TIC_STD_FBL_CALL */
#define TIC_FBL_PUSH_PAR_CALL		      0x03af	/* TIC_P2 + TIC_FBL_CALL */
#define TIC_A4B_PUSH_PAR_CALL		      0x03b0	/* TIC_P2 + TIC_A4B */
#define TIC_SEQ_A4B_PUSH_PAR_CALL		0x03b1	/* TIC_P2 + TIC_SEQ_A4B */

#endif

/* types ******************************************************************/

/* data *******************************************************************/

/* exported services from module   ???    *********************************/


#endif  /* nested Headers management */
/* eof ********************************************************************/
