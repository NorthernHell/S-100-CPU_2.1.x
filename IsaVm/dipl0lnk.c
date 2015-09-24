/**************************************************************************
File:               dipl0lnk.c
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      1-October-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        Package - Linkage management : STATIC Version

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#include <dsys0def.h>
#include "dipl0pro.h"
#include "Packages.h"

/* constants **************************************************************/
#define ISA_DECLARE_PACKNAME(PackName) /* Reserved for extensions */
#define ISA_DECLARE_HANDLE(MyFctName, IplFctAdd)      \
   {                                                  \
    if (dsysStrCmp((MyFctName), psFctName) == 0)      \
      return ((typPFnIplFct)(IplFctAdd));             \
   }                                                  

/* types ******************************************************************/

/* static data ************************************************************/
#ifndef ITGTDEF_NO_GLOBALS /*globals dynamically allocated*/
#ifdef ITGTDEF_ENABLE_IPL_SEARCH
/*************************** DOXYGEN GLOBAL VAR ***************************/
/** 
*  \b Description:            Head of list of IPL Function tables
*\n\b Variable \b type:       typSPC_ID
*\n\b Initialized \b in:      iplRStart()
*\n\b Initialized \b during:  Initialization of packages management
*\n\b Usage:                  Access to the list of function table 
*/
/**************************************************************************/
static typSPC_ID _spcIPLTABLE;

/*************************** DOXYGEN GLOBAL VAR ***************************/
/** 
*  \b Description:            Starting Address of IPL Function tables
*\n\b Variable \b type:       void*
*\n\b Initialized \b in:      iplRStart()
*\n\b Initialized \b during:  Initialization of packages management
*\n\b Usage:                  Access to the list of function table 
*/
/**************************************************************************/
static void* _pvIPLTABLEADD;

/*************************** DOXYGEN GLOBAL VAR ***************************/
/** 
*  \b Description:            Number of IPL Function in table
*\n\b Variable \b type:       uint32
*\n\b Initialized \b in:      iplRStart()
*\n\b Initialized \b during:  Initialization of packages management
*\n\b Usage:                  Calculate offsets in IPL Table. 
*/
/**************************************************************************/
static uint32 _luIPL_FCT_NUM;

#endif /* ITGTDEF_ENABLE_IPL_SEARCH */
#endif /*Any new global must also be declared in globals struct*/

/* exported data [NOT RECOMMENDED!] ***************************************/

/* imported data [NOT RECOMMENDED!] ***************************************/

/* callback services implemented in this file *****************************/

/* exported services ******************************************************/

/* imported services ******************************************************/

/* static services ********************************************************/
static typPFnIplFct _iplFctAddGet(char* psFctName);

#ifdef ITGTDEF_ENABLE_IPL_SEARCH
static strIplFct* _BinarySearch(char* psKeyName);
static typSTATUS _IplTableInsert(strIplFct*,typPFnIplFct,char*);
#endif

/****************************************************************************
function    : iplInit
description : Initialization of packages management. Called once at startup
parameters  : None
return value: None
warning     : NONE OF THE KERNEL DATA ARE VALID YET.
****************************************************************************/
void iplInit(void) 
{
}

/****************************************************************************
function    : iplExit
description : Exit of packages management. Free all previously engaged.
 system resources.  Called once at shutdown
parameters  : None
return value: None
warning     : NONE OF THE KERNEL DATA ARE VALID ANYMORE.
****************************************************************************/
void iplExit(void) 
{
}

/****************************************************************************
function    : iplRStart
description : Start of packages. Called once at resource start
parameters  :(input) uint32 luIplFctNum: Size of IPL Table.
             (input) uint16huSlaveNum: Resource number.
return value: None
warning     : NONE OF THE KERNEL DATA ARE VALID YET.
****************************************************************************/
void iplRStart
   (
   uint32 luIplFctNum,
   uint16 huSlaveNum
   ) 
{
#ifdef ITGTDEF_ENABLE_IPL_SEARCH
   /* initialize indexes */
   strIplFct *iplFirstAdd = 0;
   uint32 luIndex = 0;

   _luIPL_FCT_NUM = luIplFctNum;

   _pvIPLTABLEADD = dsysSpcCreate(&_spcIPLTABLE, huSlaveNum, ISA_SPC_IPLTABLE, luIplFctNum*sizeof(strIplFct));

   if ( _pvIPLTABLEADD != 0 )
   {
      iplFirstAdd = (strIplFct*) _pvIPLTABLEADD;
      for (luIndex=0;luIndex<luIplFctNum;iplFirstAdd++,luIndex++)
      {
         iplFirstAdd->cFctName[0] = '\0';
      }
   }
#endif

}

/****************************************************************************
function    : iplRStop
description : Exit of packages management. Free all previously engaged 
 system resources. Called once at resource stop
parameters  : None
return value: None
warning     : NONE OF THE KERNEL DATA ARE VALID ANYMORE.
****************************************************************************/
void iplRStop(void) 
{
#ifdef ITGTDEF_ENABLE_IPL_SEARCH
   dsysSpcDelete(&_spcIPLTABLE, _pvIPLTABLEADD);
#endif
}

/****************************************************************************
function    : iplFctAddGet
description : Get function address from its name.
parameters  :
   (input) char* psFctName : Function name to retrieve address from. 
return value: typPFnIplFct:  Function address if successful, zero else.
warning     : 
****************************************************************************/
typPFnIplFct iplFctAddGet
   (
   char* psFctName /*In: Function name to retrieve address from */ 
   )
{
#ifdef ITGTDEF_ENABLE_IPL_SEARCH
   typPFnIplFct pfnIplFct = 0;

   strIplFct* piplPtr = _BinarySearch(psFctName);
   if ( piplPtr != 0)
   {
      if ( dsysStrCmp(piplPtr->cFctName, psFctName) != 0 )
      {
         pfnIplFct = _iplFctAddGet(psFctName);
         if ( pfnIplFct != 0 )
            _IplTableInsert(piplPtr, pfnIplFct, psFctName);
      }
      else
      {
         pfnIplFct = (typPFnIplFct)(piplPtr->pfnIplFct);
      }
   }
   return (pfnIplFct);
#else
   return (_iplFctAddGet(psFctName));
#endif /* ITGTDEF_ENABLE_IPL_SEARCH */
}

/****************************************************************************
function    : iplFctAddRelease
description : Function previously retrieved is no more used, release 
 corresponding system resources.
parameters  :
   (input) char* psFctName :         Function name to release address from. 
   (input) typPFnIplFct pfnIplFct :  Function address
return value: None 
warning     : 
****************************************************************************/
void iplFctAddRelease
   (
   char*        psFctName, /* In: Function name to release address from */ 
   typPFnIplFct pfnIplFct  /* In: Function address */
   )  
{/* Nothing required */}

/****************************************************************************
function    : _iplFctAddGet
description : Get function address from its name.
parameters  :
   (input) char* psFctName : Function name to retrieve address from. 
return value: typPFnIplFct:  Function address if successful, zero else.
warning     : 
****************************************************************************/
static typPFnIplFct _iplFctAddGet
   (
   char* psFctName  /*In: Function name to retrieve address from */ 
   )  
{
   ISA_DECLARE_ALLPACKAGES
   return (0);
}

#ifdef ITGTDEF_ENABLE_IPL_SEARCH
/****************************************************************************
function    : _BinarySearch
*//*! \brief \b 
Description: Scan IPL Table to find specified function name
\param       (input) char* psKeyName: Name of the function to search for
\pre         These global variables and contexts are coherent:
               - None
\post        These global variables and contexts are modified:
               - None
\retval      Index of matching element if found.
\retval      Otherwise, Index of where the element can be inserted.
\retval      Zero, if IPL table is not initialized
\warning     None
****************************************************************************/
static strIplFct* _BinarySearch
   (
   char* psKeyName
   )
{
   strIplFct *iplFirst = 0;
   strIplFct *iplLast = 0;
   strIplFct *iplMid = 0;
   uint32 luMid = 0;
   char* pcFctName;

   if (_pvIPLTABLEADD != 0 )
   {
      iplFirst = (strIplFct*) _pvIPLTABLEADD;
      iplLast = ((strIplFct*)_pvIPLTABLEADD) + (_luIPL_FCT_NUM-1);
    
      while ( iplFirst <= iplLast )
      {
         luMid = (iplLast - iplFirst)/2;
         iplMid = iplFirst + luMid;

         pcFctName = &(iplMid->cFctName[0]);
         if ( dsysStrLexCmp(psKeyName, pcFctName) > 0 )
         {
            iplFirst = iplMid + 1;
         }
         else if ( dsysStrLexCmp(psKeyName, pcFctName) < 0)
         {
            iplLast = iplMid - 1;
         }
         else
         {
            /* Item Found */
            return iplMid;
         }
      }   
      return (iplFirst == _pvIPLTABLEADD ? (strIplFct*)_pvIPLTABLEADD : (iplFirst - 1));
   }
   else
   {
      /* IPL Table not initialized */
      return 0;
   }
}

/****************************************************************************
function    : _IplTableInsert
*//*! \brief \b 
Description: Insert function in IPL Table
\param       (input) strIplFct* piplFct: Address in IPL Table in which to 
             to insert the new element.
             (input) typPFnIplFct pfnIplFct: Function Address
             (input) char* psFctName: Name of Function to insert
\pre         These global variables and contexts are coherent:
               - None
\post        These global variables and contexts are modified:
               - None
\retval      0 if successful
\retval      Otherwise, BAD_RET
\warning     None
****************************************************************************/
static typSTATUS _IplTableInsert
   (
   strIplFct*     piplFct,
   typPFnIplFct   pfnIplFct,
   char*          psFctName 
   )
{
   typSTATUS   statRet = 0;   /* return status */
   strIplFct*  piplTmpPtr = 0;
   strIplFct*  piplIterator = 0;

   /* if element in table is empty, then insert */
   if ( dsysStrCmp(piplFct->cFctName,"") == 0 )
   {
      dsysMemCpy(piplFct->cFctName,psFctName,dsysStrLen(psFctName));
      piplFct->pfnIplFct = pfnIplFct;
   }
   else if (dsysStrLexCmp( psFctName,piplFct->cFctName) > 0)
   {
      piplIterator = (strIplFct*)_pvIPLTABLEADD;
      while ( piplIterator->pfnIplFct == 0 ) piplIterator++;

      if ( piplIterator != _pvIPLTABLEADD )
      {
         piplTmpPtr = piplIterator - 1;
      }
      else /* caution may not have enough space */
      {
         piplTmpPtr = piplIterator;
      }

      while ( piplTmpPtr != piplFct )
      {
         dsysMemCpy(piplTmpPtr->cFctName,piplIterator->cFctName,dsysStrLen(piplIterator->cFctName));
         dsysMemReset(piplIterator->cFctName, dsysStrLen(piplIterator->cFctName));
         piplTmpPtr->pfnIplFct = piplIterator->pfnIplFct;
         piplIterator->pfnIplFct = 0;
         piplTmpPtr++;
         piplIterator++;
      }
      dsysMemReset(piplFct->cFctName,dsysStrLen(piplFct->cFctName));
      dsysMemCpy(piplFct->cFctName,psFctName,dsysStrLen(psFctName));
      piplFct->pfnIplFct = pfnIplFct;
   }
   else
   {
      statRet = BAD_RET;
   }

   return statRet;
}
#endif /* ITGTDEF_ENABLE_IPL_SEARCH */   



/* eof ********************************************************************/

