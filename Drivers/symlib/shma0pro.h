#ifndef _SHMA_PRO_H
#define _SHMA_PRO_H

#include <dixl0def.h>
#include <shma0def.h>
#include <dsym0def.h>


/* Function prototype for shared memory access*/   

typSTATUS _shmaSymLoaded(strSymTabCnx*);



typSTATUS shmaSymLoad
	(strSymTabCnx*,
	 strIxlResInfo*,
	 char*
	);

typSTATUS  shmaSymUnload
   (
   strSymTabCnx*              /* In: Connection identifier */
   );

extern  typSTATUS shmaSymResInfo
   (
   strSymTabCnx*    pCnx,         /* In: Connection identifier */
   strIxlResInfo* pResInfo      /* Out: Resource information */
   );

extern  typSTATUS shmaSymDataSize
   (
   strSymTabCnx*    pCnx,         /* In: Connection identifier */
   typIxlVa*      pVaBase,       /* Out: First variable */
   uint32*        pluDataSize    /* Out: Size of data */
   );

extern typSTATUS shmaSymInfoFromName
   (
   strSymTabCnx*    pCnx,         /* In: Pointer to connection */
   strIxlVarDesc*  pVarDesc,    /* In/Out: Variable description */
   strSymVar**     pSymVar,
   strSymType**    pSymType
   );
   
extern  typSTATUS shmaSymInfoFromUA
   (
   strSymTabCnx*    pCnx,         /* In: Connection identifier */
   strIxlVarDesc  pVarDesc[],    /* In/Out: Variable description */
   uint16         huNbrOfVar     /* In: Nbr of var desc pointed to */
   );

extern  typSTATUS shmaSymInfoFromVA
   (
   strSymTabCnx*    pCnx,         /* In: Connection identifier */
   strIxlVarDesc  pVarDesc[],    /* In/Out: Variable description */
   uint16         huNbrOfVar     /* In: Nbr of var desc pointed to */
   );

extern  uint16 shmaSymNameFromVA
   (
   strSymTabCnx*    pCnx,         /* In: Connection identifier */ 
   typIxlVa       Va,            /* In: Variable address */
   char*          psBuffer,      /* Out: Buffer that receives name */
   uint16         huBufferSz     /* In: Size of buffer */
   );

extern  typSymVarId* ixlSymVarFromName
   (
   strSymTabCnx*    pCnx,         /* In: Connection identifier */
   char*          psName         /* In: Variable name */
   );

extern  typSymVarId* shmaSymVarFromUA
   (
   strSymTabCnx*    pCnx,         /* In: Connection identifier */
   uint16         huUserAdd      /* In: User address */
   );

extern  typSymVarId* shmaSymVarFromVA
   (
   strSymTabCnx*    pCnx,         /* In: Connection identifier */
   typIxlVa       Va             /* In: Variable address */
   );

extern  typSymVarId* shmaSymVarNext
   (
   strSymTabCnx*       pCnx,      /* In: Connection identifier */
   typSymVarId*   	 pSymVarId,  /* In: Variable identifier */
   uchar             cuOrder,    /* In: Order */
   char*             psPouName,  /* In: POU name */
   char*             psVarName   /* In: Variable name */
   );

extern  uint16 shmaSymVarName
   (
   strSymTabCnx*       pCnx,      /* In: Connection identifier */ 
   typSymVarId*   	 pSymVarId,  /* In: Variable identifier */
   typIxlVa			 pVa,
   char*             psBuffer,   /* Out: Buffer that receives name */
   uint16            huBufferSz  /* In: Buffer size */
   );

extern  uint16 shmaSymVarPouName
   (
   strSymTabCnx*      pCnx,      /* In: Connection identifier */ 
   typSymVarId*   	 pSymVarId,  /* In: Variable identifier */
   char*             psBuffer,   /* Out: Buffer that receives name */
   uint16            huBufferSz  /* In: Buffer size */
   );

extern  uchar shmaSymVarClass
   (
   strSymTabCnx*       pCnx,      /* In: Connection identifier */ 
   typSymVarId*   	 pSymVarId   /* In: Variable identifier */
   );

extern  uchar shmaSymVarStringLength
   (
   strSymTabCnx*       pCnx,      /* In: Connection identifier */ 
   typSymVarId*   	 pSymVarId   /* In: Variable identifier */
   );

extern  char shmaSymVarAttrIO
   (
   strSymTabCnx*       pCnx,      /* In: Connection identifier */ 
   typSymVarId*   	 pSymVarId   /* In: Variable identifier */
   );

extern char shmaSymAttrAccessFromVa
	(
	strSymTabCnx*    pCnx,         /* In: Pointer to connection */
   	typIxlVa  Va	
	);


extern  char shmaSymVarAttrAccess
   (
   strSymTabCnx*       pCnx,      /* In: Connection identifier */ 
   typSymVarId*   	 pSymVarId   /* In: Variable identifier */
   );

extern  char shmaSymVarAttrBinding
   (
   strSymTabCnx*       pCnx,      /* In: Connection identifier */ 
   typSymVarId*   	 pSymVarId   /* In: Variable identifier */
   );

extern  typSymTypeId* shmaSymTypeFromVar
   (
   strSymTabCnx*      pCnx,      /* In: Connection identifier */
   typSymVarId*   	 pSymVarId   /* In: Variable identifier */
   );

extern  typSTATUS shmaSymTypeDef
   (
   strSymTabCnx*      pCnx,      /* In: Connection identifier */
   typSymTypeId*  	 pSymTypeId, /* In: Type identifier */
   uchar*            pcuType,    /* Out: Type definition */
   uint16*           phuParam    /* Out: Param */
   );

extern  uint16 shmaSymTypeName
   (
   strSymTabCnx*       pCnx,      /* In: Connection identifier */
   typSymTypeId*  	 pSymTypeId, /* In: Type identifier */
   char*             psName,     /* Out: Name of the type */
   uint16            huNameSz    /* In: Size of buffer to store name */
   );

extern  typSTATUS shmaSymTypeDesc
   (
   strSymTabCnx*       pCnx,      /* In: Connection identifier */
   typSymTypeId*  	 pSymTypeId, /* In: Type identifier */
   uchar*            pcuVaType,  /* Out: Variable type identification */
   uint32*           pluSize     /* Out: Size of the var., 0 if unknown */
   );

extern  typSymTypeId* shmaSymTypeArrayInfo
   (
   strSymTabCnx*       pCnx,         /* In: Connection identifier */
   typSymTypeId*  	 pSymTypeId,    /* In: Type identifier */
   uchar             cuDim,         /* In: Dimension to get info about */
   uint32*           pluLimitLow,   /* Out: Low limit */
   uint32*           pluLimitHigh,  /* Out: High limit */
   uchar*            pcuLen         /* Out: Mainly for string */
   );

extern  typSymTypeId* shmaSymTypeStructInfo
   (
   strSymTabCnx*       pCnx,         /* In: Connection identifier */
   typSymTypeId*  	 pSymTypeId,    /* In: Type identifier */
   uint16            huFieldNum,    /* In: Field to get info about */
   char*             psName,        /* Out: Name of the field */
   uint16*           phuNameSz,     /* In: Size of buffer to store name */
                                    /* Out: Length of name */
   uint32*           pluFieldOfs,   /* Out: Field offset */
   uchar*            pcuLen         /* Out: Length if string */
   );

char shmaSymVarIsWired(strSymTabCnx*, typIxlVa);


uchar VarNameClass(char*);

#endif /*  _SHMA_PRO_H */
