/**************************************************************************
File:               ScrlStr.c
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      14-October-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:       'C' function block sample: ScrollString
                      Scroll input string with specified number of 
                      characters
***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#include <dsys0def.h>
#include <string.h>
#include <ScrlStr.h>


/* constants **************************************************************/
/* Macros definition to access data */
#undef ENABLE
#undef STR_IN
#undef NBSTEP
#undef STR_OUT
#undef MEM_ENABLE
#undef MEM_STR
#define ENABLE     (((strScrStrFblInst*)VA_ADDRESS(pvBfData,FblInst->Va)) \
                    ->cuEnable)
#define STR_IN     (((strScrStrFblInst*)VA_ADDRESS(pvBfData,FblInst->Va)) \
                     ->tcStrIn)
#define NBSTEP     (((strScrStrFblInst*)VA_ADDRESS(pvBfData,FblInst->Va)) \
                     ->ldNbStep)
#define STR_OUT    (((strScrStrFblInst*)VA_ADDRESS(pvBfData,FblInst->Va)) \
                     ->tcStrOut)
#define MEM_ENABLE (((strScrStrFblInst*)VA_ADDRESS(pvBfData,FblInst->Va)) \
                     ->cuMemEnable)
/*
 * String variable manipulation:
 * A string is structured as following:
 *     [max len][cur len][..buffer..][\0(eos)]
 *  max len : Maximum string length (without eos) (1 byte)
 *  cur len : Current string length (without eos) (1 byte)
 *  buffer  : String buffer of max len.
 *            It contains current string value always with eos
 * Therefore a string variable is made of max len + 3 characters.
 * It is the programmer responsability to:
 *  - Check output string variables max len before update
 *  - Always add end of string (\0) at output string variables update.
 *  - Update output string variables cur len
 */
#define _MAXLEN(pt)      (*(uchar*)(pt))
#define _CURLEN(pt)      (*(((uchar*)(pt))+1))
#define _BUFADD(pt)      (((char*)(pt))+2)

/* types ******************************************************************/
/* Function block instance */
typedef struct
{
   /* INPUT */
   uchar cuEnable;     /* Enable scroll */
   char  tcStrIn[83];  /* Input string (max=80) */
   int32 ldNbStep;     /* Number of scrolling step */
   
   /* OUTPUT */
   char  tcStrOut[83]; /* Output string (max=80) */

   /* LOCAL */
   uchar cuMemEnable;  /* Memorisation of enable scroll */
} strScrStrFblInst;

/* static data ************************************************************/

/* exported data [NOT RECOMMENDED!] ***************************************/

/* imported data [NOT RECOMMENDED!] ***************************************/

/* callback services implemented in this file *****************************/

/* exported services ******************************************************/

/* imported services ******************************************************/

/* static services ********************************************************/



/****************************************************************************
function    : scrollstringFblClassInit
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
void scrollstringFblClassInit
   (
   uint16 huNbInst  /* Number of instances */ 
   )  
{
}

/****************************************************************************
function    : scrollstringFblClassExit
description : Exit of function block class
parameters  :
   (input) uint16 huNbInst : Number of instances. 
return value: None 
warning     : 
 - This function is called during kernel stop of the resource after exit
   of function block instances. It is aimed for function block proper exit,
   NONE OF THE KERNEL DATA ARE VALID ANYMORE.
****************************************************************************/
void scrollstringFblClassExit
   (
   uint16 huNbInst /* Number of instances */
   ) 
{
}

/****************************************************************************
function    : scrollstringFblInstInit
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
   allocated but input parameter values are not meaningful. Local/output 
   parameters are basically initialized here. 
 - According to the function block, instance Init/Exit may be useful or not
   (body with code or empty).When useful, to be seen by kernel, such
   information must have been filled in within the PLC designer tool.
   ==> This function will not be called if you forgot that !!!!!
   On the other hand, when not useful, registering with the PLC designer 
   tool, the function block as not needing instance Init/Exit call, will
   save memory on the target.
****************************************************************************/
void scrollstringFblInstInit
   (
   void*       pvBfData, /* In: Data */
   strParamVa* FblInst   /* In: Function block instance */ 
   )  
{
   /* Init output */
   strcpy(_BUFADD(STR_OUT), "SET ENABLE TO CHANGE STRING ");
   _CURLEN(STR_OUT) = strlen("SET ENABLE TO CHANGE STRING "); /* < 80 */

   /* Init local */
   MEM_ENABLE = FALSE;
}

/****************************************************************************
function    : scrollstringFblInstExit
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
void scrollstringFblInstExit
   (
   void*       pvBfData,      /* In: Data */ 
   strParamVa* FblInst        /* In: Function block instance */ 
   ) 
{
}

/****************************************************************************
function    : scrollstringFblCall   
description : Body of 'C' function block
parameters  :
   (input) void* pvBfData :       Data. 
   (input) strParamVa* FblInst :  Function block instance. 
return value: None 
warning     : 
****************************************************************************/
void scrollstringFblCall
   (
   void*       pvBfData, /* In: Data */ 
   strParamVa* FblInst   /* In: Function block instance */ 
   )  
{
   /* 
    * Note that in order to improve performances,
    * when parameters are often referenced,
    * the following scheme is used:
    *  - Copy of input/(output)/local params to stack variables
    *  - Proceed the function working on stack variables
    *  - Update output/local params from the corresponding stack variables
    */

   uchar  cuEnable;
   uchar* pcuStrIn;
   uchar  cuStrInCurLen;
   char*  psStrIn;
   int32  ldNbStep;
   uchar* pcuStrOut;
   uchar  cuStrOutMaxLen;
   uchar  cuStrOutCurLen;
   char*  psStrOut;
   
   char  tcBuff[80]; /* temporary buffer for scrolling */ 
   uchar cuLen; /* temporary length */

   cuEnable = ENABLE;
   pcuStrIn = (uchar*)STR_IN;
   cuStrInCurLen = _CURLEN(pcuStrIn);
   psStrIn = _BUFADD(pcuStrIn);
   ldNbStep = NBSTEP;
   pcuStrOut = (uchar*)STR_OUT;
   cuStrOutMaxLen = _MAXLEN(pcuStrOut);
   cuStrOutCurLen = _CURLEN(pcuStrOut);
   psStrOut = _BUFADD(pcuStrOut);

   if (cuEnable && !MEM_ENABLE) /* Detect rising edge */
   {
      /*
       * Copy input string to output one 
       */
      cuLen=(cuStrInCurLen > cuStrOutMaxLen) ? cuStrOutMaxLen : cuStrInCurLen;
      memcpy (psStrOut, psStrIn, cuLen); /* string discarded if to large */
      psStrOut[cuLen] = 0;        /* eos */
      _CURLEN(pcuStrOut) = cuLen; /* Update current length */
   }
   else if (cuEnable)
   {
      if ( (ldNbStep > 0) && (ldNbStep < (int32)cuStrOutCurLen) )
      /* Scroll string */
      {
         cuLen = (uchar)((int32)cuStrOutCurLen - ldNbStep);
         memcpy(tcBuff, &psStrOut[ldNbStep], cuLen);
         memcpy(&tcBuff[cuLen], psStrOut, ldNbStep);
         memcpy(psStrOut, tcBuff, cuStrOutCurLen);
         /* eos always at same place */
         /* Current length of output not changed */
      }
   }

   MEM_ENABLE = cuEnable; /* Rising edge memo */
}


/* eof ********************************************************************/
