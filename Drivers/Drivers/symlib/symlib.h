#ifndef _SYMLIB_H
#define  _SYMLIB_H

#define ISAGRAF_5

#include "shma0def.h"
#include <shma0pro.h>

class SymLib
{
    private:
       	strIxlResInfo pResInfo;
		strSymTabCnx pCnx;

    public:

  	SymLib();
  	~SymLib();
	//return 0  = Ok ; -1 = error
	int getInfoFromName(strIxlVarDesc  *pVarDesc,   strSymVar** ppSymVar,strSymType** ppSymType);
	int getTypeDef(strSymType* pSymType,uchar *cuType,uint16 *param);
	int getArrayInfoFromType(strSymType* pSymType,uchar cuDim,uint32* pluLimitLow,uint32* pluLimitHigh,uchar* pcuLen);
	int getStructInfoFromType(strSymType* pSymType,uint32* numFilelds);
        char *getFieldStructInfoFromType(strSymType* pSymType,int fileldNum,uchar *fieldType,uint32 *fieldOffset);
  	int getInfoFromVA(strIxlVarDesc  *pVarDesc, uint16 huNbrOfVar);
  	int getNameFromVA(typIxlVa Va, char* psBuffer, uint16 huBufferSz);

	int isLoaded();
	//1 - loaded 0-error
	
	int cleanOldTable();

	uint32 VaBase;
	uint32 DataSize;

};

extern SymLib SymTab;

uchar IsEasyType(uchar vaType);         // 1 - if scalar type
uint32 getTypeSize(uchar type); 		// size of element

#endif
