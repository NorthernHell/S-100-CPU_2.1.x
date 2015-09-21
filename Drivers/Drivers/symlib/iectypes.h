/**************************************************************************
File:               iectypes.h
Author:             Levizi
Creation date:      01/09/2006 - 15:42
***************************************************************************/
#ifndef _IECTYPES_H /* nested Headers management */
#define _IECTYPES_H

#include <dsys0def.h>
#include <dixl0def.h>
#include <dsym0def.h>

#include <math.h>
#include <limits.h>

#if !defined HUGE
	#if (defined WINCE) || (defined _MSC_VER)
		#define HUGE		3.402823466e+38F
	#else 
		#define HUGE		3.40282347e+38F
	#endif
#endif    
 
#define MatrixMacro(matr, x, y, r1, r2) (matr[(x)*(r2)+(y)])
/* WARNING!
Definition of arrays is different in "C" or IEC
The index of the first element may be different from 0 in IEC
The declared array size supposes that first elemnt as index 0 in "C"
For example, if you declare in IEC:
	MyArray[2..10]
It will be in "C":
	MyArray[9]
And element [2] in IEC corresponds to element [0] in "C"

Three extra bytes are allocated for each STRING item
For example, if you declare in IEC:
	STRING(10)
It will be in "C":
	char[13]
*/


bool getVarInfoFromSYMTABLE(char *varname,char * vatype,int * numelem, int * vadr);

bool getStructInfoFromSYMTABLE(strSymType** pSymTypeId,char *varname,uint32 * numfields);
char *getStructFieldInfoFromSYMTABLE(strSymType* pSymType,int field,uchar *fieldtype,uint32 * fieldOffset);

#define IEC_TYPE_FAST_ARRAY_LREAL	1
#define IEC_TYPE_FAST_ARRAY_REAL	2
typedef struct _tag_strIecSt_handle
{
   uint64 	addrArray;
   char 	typeArray;
   int 		sizeArray;
   char  	_error;
} strIecSt_handle;
typedef strIecSt_handle * PstrIecSt_handle;

void getArrayInfoFromSYMTABLE(strIecSt_handle *,char *);

#define IEC_TYPE_FAST_MATRIX_LREAL	101
#define IEC_TYPE_FAST_MATRIX_REAL	102
typedef struct _tag_strIecMt_handle
{
   uint64 addrMatrix;
   char  typeMatrix;
   int dimensionOfMatrix1;
   int dimensionOfMatrix2;
   uchar _error;
} strIecMt_handle;
typedef strIecMt_handle * PstrIecMt_handle;

void getMatrixInfoFromSYMTABLE(strIecMt_handle *,char *);

typedef struct _tag_strIecFir_handle
{
   uint64 FirPtr;
   int Range;
   int DataCounter;
   uchar error;
} strIecFir_handle;
typedef strIecFir_handle * PstrIecFir_handle;

typedef struct _tag_strIecIir_handle
{
   uint64 IIrPtr;
   int Range;
   int DataCounter;
   uchar error;
} strIecIir_handle;
typedef strIecIir_handle * PstrIecIir_handle;


template <typename Type>
class RingArray
{
	Type *data;
	int   size;
	int & counter;
	int   first,last;
	
		void setupRingPointers()
		{
			last = counter % size;
			first = (counter < size) ? 0 : last;
		}

	public:
		RingArray(Type *array,int dim,int & fifocounter):
			data(array),size(dim),counter(fifocounter)
		{
			setupRingPointers();
		}

		void Add(Type point)
		{
			data[last]=point;
			counter++;
			setupRingPointers();
		}
		
		int First(){return first;}
		int Last(){return Prev(last);}
                int Size(){return counter < size ? counter : size;}
		int Next(int p)
		{
			return ++p % size;
		}
		
		int Prev(int p)
		{
			return --p >= 0 ? p : p + size;
		}
};

	
#endif /* _IECTYPES_H */

/* eof ********************************************************************/
