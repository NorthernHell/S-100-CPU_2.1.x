/**************************************************************************
File:               CBSample.c
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
#include <CBSample.h>


/* constants **************************************************************/
/* Macros definition to access data */
#undef IN1
#undef IN2
#undef QADD
#undef QSUB
#define IN1  (((strCBSampleFblInst*)VA_ADDRESS(pvBfData,FblInst->Va))->ldIn1)
#define IN2  (((strCBSampleFblInst*)VA_ADDRESS(pvBfData,FblInst->Va))->ldIn2)
#define QADD (((strCBSampleFblInst*)VA_ADDRESS(pvBfData,FblInst->Va))->ldQAdd)
#define QSUB (((strCBSampleFblInst*)VA_ADDRESS(pvBfData,FblInst->Va))->ldQSub)

/* types ******************************************************************/
/* Function block instance */
typedef struct
{
   /* INPUT */
   int32  ldIn1;
   int32  ldIn2;
   
   /* OUTPUT */
   int32  ldQAdd;
   int32  ldQSub;

   /* LOCAL */
   /* No local */
} strCBSampleFblInst;

/* static data ************************************************************/

/* exported data [NOT RECOMMENDED!] ***************************************/

/* imported data [NOT RECOMMENDED!] ***************************************/

/* callback services implemented in this file *****************************/

/* exported services ******************************************************/

/* imported services ******************************************************/

/* static services ********************************************************/



/****************************************************************************
function    : cbsampleFblClassInit
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
void cbsampleFblClassInit
   (
   uint16 huNbInst  /* Number of instances */ 
   )  
{
}

/****************************************************************************
function    : cbsampleFblClassExit
description : Exit of function block class
parameters  :
   (input) uint16 huNbInst : Number of instances. 
return value: None 
warning     : 
 - This function is called during kernel stop of the resource after exit
   of function block instances. It is aimed for function block proper exit,
   NONE OF THE KERNEL DATA ARE VALID ANYMORE.
****************************************************************************/
void cbsampleFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   ) 
{
}

/****************************************************************************
function    : cbsampleFblInstInit
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
void cbsampleFblInstInit
   (
   void*       pvBfData, /* In: Data */
   strParamVa* FblInst   /* In: Function block instance */ 
   )  
{
}

/****************************************************************************
function    : cbsampleFblInstExit
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
void cbsampleFblInstExit
   (
   void*       pvBfData,      /* In: Data */ 
   strParamVa* FblInst        /* In: Function block instance */ 
   ) 
{
}

/****************************************************************************
function    : cbsampleFblCall   
description : Body of 'C' function block
parameters  :
   (input) void* pvBfData :       Data. 
   (input) strParamVa* FblInst :  Function block instance. 
return value: None 
warning     : 
****************************************************************************/
void cbsampleFblCall
   (
   void*       pvBfData, /* In: Data */ 
   strParamVa* FblInst   /* In: Function block instance */ 
   )  
{
   QADD = IN1 + IN2;
   QSUB = IN1 - IN2;
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
