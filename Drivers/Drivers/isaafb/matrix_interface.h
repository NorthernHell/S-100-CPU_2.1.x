/**************************************************************************
File:               matrix_interface.h
Author:             ICS Triplex ISaGRAF Inc.
Creation date:      28/05/2007 - 11:21
POU name:           MATRIX
***************************************************************************
Attached documents: 

***************************************************************************
Description:        

***************************************************************************
Modifications: (who / date / description)

***************************************************************************/

#ifndef MATRIX_INTERFACE_H
#define MATRIX_INTERFACE_H

/* User headers */
#include "matrix.h"
#include "matrix_functions.h"

typedef Matrix_st * (NewMatrix_td)(int32, int32, MatrixType_en);
NewMatrix_td _NewMatrix;

typedef MatrixError_en (FreeMatrix_td)(Matrix_st *);
FreeMatrix_td _FreeMatrix;

typedef Matrix_st * (DupMatrix_td)(Matrix_st *);
DupMatrix_td _DupMatrix;

typedef MatrixError_en (CopyMatrix_td)(Matrix_st *, Matrix_st *);
CopyMatrix_td _CopyMatrix;

typedef MatrixError_en (CopyRowMatrix_td)(Matrix_st *, int32, Matrix_st *, int32);
CopyRowMatrix_td _CopyRowMatrix;

typedef MatrixError_en (CopyColMatrix_td)(Matrix_st *, int32, Matrix_st *, int32);
CopyRowMatrix_td _CopyColMatrix;

typedef MatrixType_en (GetTypeMatrix_td)(Matrix_st *);
GetTypeMatrix_td _GetTypeMatrix;

typedef int32 (GetRowsMatrix_td)(Matrix_st *);
GetRowsMatrix_td _GetRowsMatrix;

typedef int32 (GetColsMatrix_td)(Matrix_st *);
GetColsMatrix_td _GetColsMatrix;

typedef MatrixError_en (PutIntegerMatrix_td)(Matrix_st *, int32, int32, int32);
PutIntegerMatrix_td _PutIntegerMatrix;

typedef int32 (GetIntegerMatrix_td)(Matrix_st *, int32, int32);
GetIntegerMatrix_td _GetIntegerMatrix;

typedef MatrixError_en (PutFloatMatrix_td)(Matrix_st *, int32, int32, float);
PutFloatMatrix_td _PutFloatMatrix;

typedef float (GetFloatMatrix_td)(Matrix_st *, int32, int32);
GetFloatMatrix_td _GetFloatMatrix;

typedef Matrix_st * (TransposeMatrix_td)(Matrix_st *, Matrix_st *);
TransposeMatrix_td _TransposeMatrix;

typedef Matrix_st * (InvertMatrix_td)(Matrix_st *, Matrix_st *);
InvertMatrix_td _InvertMatrix;

typedef Matrix_st * (AddMatrix_td)(Matrix_st *, Matrix_st *, Matrix_st *);
AddMatrix_td _AddMatrix;

typedef Matrix_st * (SubMatrix_td)(Matrix_st *, Matrix_st *, Matrix_st *);
SubMatrix_td _SubMatrix;

typedef Matrix_st * (MultiplyMatrix_td)(Matrix_st *, Matrix_st *, Matrix_st *);
MultiplyMatrix_td _MultiplyMatrix;

typedef Matrix_st * (IntegerScalarMatrix_td)(Matrix_st *, Matrix_st *, int32);
IntegerScalarMatrix_td _IntegerScalarMatrix;

typedef Matrix_st * (FloatScalarMatrix_td)(Matrix_st *, Matrix_st *, float);
FloatScalarMatrix_td _FloatScalarMatrix;

typedef MatrixError_en (PrintMatrix_td)(Matrix_st *);
PrintMatrix_td _PrintMatrix;

typedef int32 _ErrorResult_td;
extern _ErrorResult_td _MatrixErrorResult;


#endif /* MATRIX_INTERFACE_H */

/* eof ********************************************************************/

