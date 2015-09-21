/**************************************************************************
File:               dkvb0def.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      10-August-1998
***************************************************************************
Attached documents: 

***************************************************************************
Description:        
   Kernel Variables Binding Definition

***************************************************************************
Modifications: (who / date / description)

  
***************************************************************************/
#ifndef _DKVB0DEF_H /* nested Headers management */
#define _DKVB0DEF_H

/* constants **************************************************************/
#define ISA_KVB_LOCK         1
#define ISA_KVB_UNLOCK       2
#define ISA_KVB_NOUSEDFVAL   3
#define ISA_KVB_USEDFVAL     4
#define ISA_KVB_STATUS       5
#define ISA_KVB_VALIDITY     6

#define ISA_KVB_STATUS_LOCK         0x00000001
#define ISA_KVB_STATUS_USEDFVAL     0x00000002

#ifdef ITGTDEF_BINDIMPROVE
#define ISA_KVB_GET_PROD_VERSION(pProdTable) ((pProdTable != 0) ? ((((strKvbProd*)(pProdTable))->huGrpOffset != 0) ? ((((strKvbProd*)(pProdTable))->huGrpOffset == (sizeof(strKvbProd) - sizeof(uint32))) ? (0) : (((strKvbProd*)(pProdTable))->luProdVers)) : 0) : 0)
#define ISA_KVB_GET_CONS_VERSION(pConsTable) ((pConsTable != 0) ? ((((strKvbCons*)(pConsTable))->huGrpOffset != 0) ? ((((strKvbCons*)(pConsTable))->huGrpOffset == (sizeof(strKvbCons) - sizeof(uint32))) ? (0) : (((strKvbCons*)(pConsTable))->luConsVers)) : 0) : 0)
#define ISA_KVB_IS_LEGACY(TableVersion) (((TableVersion) > 0) ? 0 : 1)
#define ISA_KVB_IS_EXTRA_PROJECT(ProducerGroupId) (ProducerGroupId & 0x80000000UL)
#endif

/* types ******************************************************************/

/* Registration for binding drivers */
typedef struct
{
   char      psDriverName[32];
   uint32    (*pfnDrvSize)    ( char*, void*, void* ); 
   typSTATUS (*pfnDrvInit)    ( uint16, char*, void*, void*, void*, void* );
   void      (*pfnDrvExit)    ( void* );
   typSTATUS (*pfnDrvProduce) ( void*, uchar, uchar );
   typSTATUS (*pfnDrvConsume) ( void*, uchar, uchar );
   typSTATUS (*pfnDrvCtl)     ( uchar, void*, uint16, typVa, int32* );
} strKvbDrvFctToReg;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Binding: Main table */
typedef struct
{
   uint16   huNbrDrv;         /*!< Number of drivers */
   uint16   huDrvOffset;      /*!< Offset to drivers definition list */
} strDefKvbDrv;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Binding: Driver's information */
typedef struct
{
   uint32   luDrvNameOffset;  /*!< Offset to driver name */
   uint32   luKvbPOffset;     /*!< Offset to driver production */
   uint32   luKvbCOffset;     /*!< Offset to driver consumption */
} strKvbDrvInfo;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Binding production table */
typedef struct
{
   uint16   huNbrGrp;      /*!< Number of exported groups */
   uint16   huGrpOffset;   /*!< Offset to the exported group list */
   uint32   luVarOffset;   /*!< Offset to produced variables description */
   uint32   luOemOffset;   /*!< Offset to OEM parameters of the resource */
   uint32   luNbrVar;      /*!< Number of produced variables */
   uint32   luSizeProd;    /*!< Total size of common produced data */
#ifdef ITGTDEF_BINDIMPROVE
   uint32   luProdVers;    /*!< Version of the production table (1 for this version) */
#endif
} strKvbProd;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Binding production groupe */
typedef struct
{
   typVa    VaStatus;      /*!< Produced group error variable */
   uint32   luCrc;         /*!< CRC */
   uint32   luNbrVar;      /*!< Number of produced variable for this group */
   uint32   luSizeProd;    /*!< Size of produced data for this group */
   uint32   luVarOffset;   /*!< Offset to produced variables description */
   uint32   luOemOffset;   /*!< Offset to OEM parameters of this group */
#ifdef ITGTDEF_BINDIMPROVE
   uint32   luGroupId;     /*!< Group identifier */
#endif
#ifdef ITGTDEF_NET_INSTANCES
   uint32   luNetInstNameOffset; /*!< Offset to network instances to use to reach consumer */
#endif
} strKvbProdGrp;

#ifdef ITGTDEF_BINDIMPROVE
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   typVa    VaStatus;      /*!< Produced group error variable */
   uint32   luCrc;         /*!< CRC */
   uint32   luNbrVar;      /*!< Number of produced variable for this group */
   uint32   luSizeProd;    /*!< Size of produced data for this group */
   uint32   luVarOffset;   /*!< Offset to produced variables description */
   uint32   luOemOffset;   /*!< Offset to OEM parameters of this group */
} strKvbProdGrpLegacy;
#endif

/**************************** DOXYGEN STRUCTURE ***************************/
/* Binding production variable */
typedef struct
{
   typVa    Va;            /*!< Kernel variable address to produce */
   uint32   luVarPos;      /*!< Variable position in common buffer */
   uchar    cuTypeVar;     /*!< Kernel variable type */
   uchar    cuReserved;    /*!< Reserved */
   uint32   luVarSize;     /*!< Kernel variable size */
   uint32   luOemOffset;   /*!< Offset to OEM parameters of this variable */
} strKvbProdVar;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Binding consumption */
typedef struct
{
   uint16   huNbrGrp;      /*!< Number of bound producers */
   uint16   huGrpOffset;   /*!< Offset to the bound resource producer list */
   uint32   luVarOffset;   /*!< Offset to consumed variables description */
   uint32   luNbrVar;      /*!< Number of consumed variable for this resource */
   uint32   luSizeCons;    /*!< Total size of consumed data for this resource */
#ifdef ITGTDEF_BINDIMPROVE
   uint32   luConsVers;    /*!< Version of the consumption table (1 for this version) */
#endif
} strKvbCons;

/**************************** DOXYGEN STRUCTURE ***************************/
/* Binding consumption group */
typedef struct
{
   uint16   huSlaveNum;    /*!< Resource producer identifier */
   typVa    VaStatus;      /*!< Group consummation error variable */
   uint32   luCrc;         /*!< CRC */
   uint32   luNbrVar;      /*!< Number of consumed variable for this group */
   uint32   luSizeCons;    /*!< Size of consumed data for this group */
   uint32   luSizeProd;    /*!< Size of common producer buffer */
   uint32   luVarOffset;   /*!< Offset to consumed variables description */
   uint32   luOemOffset;   /*!< Offset to OEM parameters of this group */
#ifdef ITGTDEF_BINDIMPROVE
   uint32   luGroupId;     /*!< Group identifier */
#endif
#ifdef ITGTDEF_NET_INSTANCES
   uint32   luNetInstNameOffset; /*!< Offset to network instances to use to reach producer */
#endif
} strKvbConsGrp;

#ifdef ITGTDEF_BINDIMPROVE
/**************************** DOXYGEN STRUCTURE ***************************/
typedef struct
{
   uint16   huSlaveNum;    /*!< Resource producer identifier */
   typVa    VaStatus;      /*!< Group consummation error variable */
   uint32   luCrc;         /*!< CRC */
   uint32   luNbrVar;      /*!< Number of consumed variable for this group */
   uint32   luSizeCons;    /*!< Size of consumed data for this group */
   uint32   luSizeProd;    /*!< Size of common producer buffer */
   uint32   luVarOffset;   /*!< Offset to consumed variables description */
   uint32   luOemOffset;   /*!< Offset to OEM parameters of this group */
} strKvbConsGrpLegacy;
#endif

/**************************** DOXYGEN STRUCTURE ***************************/
/* Binding consumption variable */
typedef struct
{
   typVa    Va;            /*!< Kernel variable address to consume */
   uint32   luVarPosProd;  /*!< Variable position in common producer buffer */
   uchar    cuTypeVar;     /*!< Kernel variable type */
   uchar    cuUseDfVal;    /*!< Use default value */
   uint32   luVarSize;     /*!< Kernel variable size */
   uint16   huNbrConv;     /*!< Number of conversion items of this variable */
   uint32   luVarPosProdB; /*!< Variable position, in bytes number, in common producer buffer */
   uint32   luVarPosCons;  /*!< Variable position in consumer buffer */
   uint32   luConvOffset;  /*!< Offset to conversion items of this variable */
   uint32   luOemOffset;   /*!< Offset to OEM parameters of this variable */
   uint32   luDfValOffset; /*!< Offset to default value */
} strKvbConsVar;

/* data *******************************************************************/

/* exported services from module dker0kvb.c *******************************/
extern typSTATUS kvbDrvRegister
   (
   strKvbDrvFctToReg*   pDrvReg     /* In: Pointer to driver registration */
   );

#endif  /* nested Headers management */
/* eof ********************************************************************/
