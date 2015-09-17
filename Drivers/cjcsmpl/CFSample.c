/**************************************************************************
File:               CFSample.c
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      13-October-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:       Very simple example of a 'C' function: compute the 
                    addition of two double integers.

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#include <dsys0def.h>
#include <CFSample.h>


/* constants **************************************************************/
/* Macros definition to access data */
#undef  IN1
#undef  IN2
#undef  Q
#define IN1   BF_DINT(pvBfData, InParam[0].Va)  
#define IN2   BF_DINT(pvBfData, InParam[1].Va) 
#define Q     BF_DINT(pvBfData, OutParam->Va)  

/* types ******************************************************************/

/* static data ************************************************************/

/* exported data [NOT RECOMMENDED!] ***************************************/

/* imported data [NOT RECOMMENDED!] ***************************************/

/* callback services implemented in this file *****************************/

/* exported services ******************************************************/

/* imported services ******************************************************/

/* static services ********************************************************/



/****************************************************************************
function    : cfsampleUsfCall   
description : 'C' function body
parameters  :
   (input) void* pvBfData :        Data. 
   (input) strParamVa* InParam :   Input parameters. 
   (input) uchar cuNbInParam :     Number of input parameters. 
   (input) strParamVa* OutParam :  Output parameter. 
return value: None 
warning     : 
****************************************************************************/
void cfsampleUsfCall   
   (
   void*       pvBfData,     /* In: Data */ 
   strParamVa* InParam,      /* In: Input parameters */ 
   uchar       cuNbInParam,  /* In: Number of input parameters */ 
   strParamVa* OutParam      /* In: Output parameter */ 
   )  
{
   Q = IN1 + IN2;
   /* 
    * Note that for more complex functions, 
    * when parameters are often referenced (IN1,IN2,Q...),
    * in order to improve performances, 
    * the following scheme may be used:
    *  - Copy of input params to stack variables
    *  - Proceed the function working on stack variables
    *  - Copy output param from the corresponding stack variable
    *  The previous example becomes:
    * int32 ldIn1;
    * int32 ldIn2;
    * int32 ldQ;
    *    
    * ldIn1 = IN1;
    * ldIn2 = IN2;
    * ldQ = ldIn1 + ldIn2;
    * Q = ldQ;
    * NOTE that this exemple is not relevant as parameters
    * are not often referenced
    */
}

/* eof ********************************************************************/
