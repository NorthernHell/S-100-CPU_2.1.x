#ifndef _SHMA_DEF_H
#define _SHMA_DEF_H

#include <dsys0def.h>

#define ISA_SYM_WIRED 5
#define ISA_SYM_REG   6
#define ISA_SYM_SERVICE	7


typedef void typSymVarId;     /* Variable identifier */
typedef void typSymTypeId;    /* Type identifier */ 

typedef struct _strSymTabCnx
{
/* Symbol table */
	uint16 		huSlaveNum;
	void* 		pvSymAdd;
	typSPC_ID	SpcIdSym;
	uchar 		cuCnxValid;
} strSymTabCnx;

typedef struct _strShmaCnx
{
	uint16 		huSlaveNum;
	
	/* Data memory block */	
	void* 		pvDataBase;
	typSPC_ID	SpcId;

} strShmaCnx; 

#endif /* _SHMA_DEF_H  */


