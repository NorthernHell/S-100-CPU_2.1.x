/**************************************************************************
File:               pid_evro.c
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      14-October-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:       Very simple example of a 'C' function block: compute the 
                    addition and subtraction of two double integers.

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#include <dsys0def.h>
#include <pid_evro.h>


/* constants **************************************************************/
/* Macros definition to access data */
#undef P
#undef SP
#undef Q

#define P  (((strpid_evroFblInst*)VA_ADDRESS(pvBfData,FblInst->Va))->ldp)
#define SP  (((strpid_evroFblInst*)VA_ADDRESS(pvBfData,FblInst->Va))->ldsp)
#define Q (((strpid_evroFblInst*)VA_ADDRESS(pvBfData,FblInst->Va))->ldq)


/* types ******************************************************************/
/* Function block instance */
typedef struct
{
   /* INPUT */
   float  ldp;
   float  ldsp;
   
   /* OUTPUT */
   float  ldq;


} strpid_evroFblInst;

/* static data ************************************************************/

/* exported data [NOT RECOMMENDED!] ***************************************/

/* imported data [NOT RECOMMENDED!] ***************************************/

/* callback services implemented in this file *****************************/

/* exported services ******************************************************/

/* imported services ******************************************************/

/* static services ********************************************************/



/****************************************************************************
function    : pid_evroFblClassInit
description : Initialization of function block class.
parameters  :
   (input) uint16 huNbInst : Number of instances. 
return value: None 
warning     : 
 - When used, it generaly leads to dangerous programmation structure.
 - This function is called during kernel initialization of the resource 
   before intialization of function block instances. It is aimed for the 
   function block proper init, NONE OF THE KERNEL DATA ARE VALID YET.
****************************************************************************/
void pid_evroFblClassInit
   (
   uint16 huNbInst  /* Number of instances */ 
   )  
{
}

/****************************************************************************
function    : pid_evroFblClassExit
description : Exit of function block class
parameters  :
   (input) uint16 huNbInst : Number of instances. 
return value: None 
warning     : 
 - This function is called during kernel stop of the resource after exit
   of function block instances. It is aimed for function block proper exit,
   NONE OF THE KERNEL DATA ARE VALID ANYMORE.
****************************************************************************/
void pid_evroFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   ) 
{
}

/****************************************************************************
function    : pid_evroFblInstInit
description : Initialization of function block instances
parameters  :
   (input) void* pvBfData :       Data.
   (input) strParamVa* FblInst :  Function block instance. 
return value: None
warning     : 
 - This function is called during kernel initialization of the resource, 
   after intialization of the function block class, and for each instance of  
   the function block. It is aimed for the function block proper init,
   NONE OF THE KERNEL DATA ARE VALID YET. Of course the instance has been
   allocated but input parameter values are not meaningful. Local/ouput 
   parameters are basically initialized here. 
 - According to the function block, instance Init/Exit may be useful or not
   (body with code or empty).When useful, to be seen by kernel, such
   information must have been filled in within the PLC designer tool.
   ==> This function will not be called if you forgot that !!!!!
   On the other hand, when not useful, registering with the PLC designer 
   tool, the function block as not needing instance Init/Exit call, will
   save memory on the target.
****************************************************************************/
void pid_evroFblInstInit
   (
   void*       pvBfData, /* In: Data */
   strParamVa* FblInst   /* In: Function block instance */ 
   )  
{
}

/****************************************************************************
function    : pid_evroFblInstExit
description : Exit of function block instances
parameters  :
   (input) void* pvBfData :       Data.
   (input) strParamVa* FblInst :  Function block instance. 
return value: None
warning     : 
 - This function is called during kernel stop of the resource, 
   before exit of the function block class, and for each instance of  
   the function block. It is aimed for the function block proper exit,
   NONE OF THE KERNEL DATA ARE VALID ANYMORE. Of course the instance is still
   allocated but input parameter values are not meaningful.
 - According to the function block, instance Init/Exit may be useful or not
   (body with code or empty).When useful, to be seen by kernel, such
   information must have been filled in within the PLC designer tool.
   => This function will not be called if you forgot that !!!!!
   On the other hand, when not useful, registering with the PLC designer 
   tool, the function block as not needing instance Init/Exit call, will
   save memory on the target.
****************************************************************************/
void pid_evroFblInstExit
   (
   void*       pvBfData,      /* In: Data */ 
   strParamVa* FblInst        /* In: Function block instance */ 
   ) 
{
}

/****************************************************************************
function    : pid_evroFblCall   
description : Body of 'C' function block
parameters  :
   (input) void* pvBfData :       Data. 
   (input) strParamVa* FblInst :  Function block instance. 
return value: None 
warning     : 
****************************************************************************/
void pid_evroFblCall
   (
   void*       pvBfData, /* In: Data */ 
   strParamVa* FblInst   /* In: Function block instance */ 
   )  
{
   Q = SP - P;

   /* 
    * Note that for more complex functions, 
    * when parameters are often referenced (IN1,IN2,Q...),
    * in order to improve performances, 
    * the following scheme may be used:
    *  - Copy of input/(output)/local params to stack variables
    *  - Proceed the function working on stack variables
    *  - Update output/local params from the corresponding stack variables
    *  The previous example becomes:
    * int32 ldIn1;
    * int32 ldIn2;
    * int32 ldQAdd;
    * int32 ldQSub;
    *    
    * ldIn1 = IN1;
    * ldIn2 = IN2;
    * ldQAdd = ldIn1 + ldIn2;
    * ldQSub = ldIn1 - ldIn2;
    * QADD = ldQAdd;
    * QSUB = ldQSub;
    */
}


/* eof ********************************************************************/
