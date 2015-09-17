/**************************************************************************
File:               matrix_functions.h
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

#ifndef MATRIX_H
#define MATRIX_H

typedef enum
{
	MATRIX_NO_ERROR,
	MATRIX_ERROR_NOT_ENOUGH_MEMORY,
	MATRIX_ERROR_INVALID_TYPE,
	MATRIX_ERROR_TYPE_MISMATCH,
	MATRIX_ERROR_ROW_MISMATCH,
	MATRIX_ERROR_COL_MISMATCH,
	MATRIX_ERROR_DIMENSION_MISMATCH,
	MATRIX_ERROR_INDEX_OUT_OF_RANGE,
	MATRIX_ERROR_NOT_SQUARE,
   MATRIX_ERROR_MATH,
	MATRIX_ERROR_UNKNOWN_OPERATION

} MatrixError_en;


typedef enum
{
	MATRIX_TYPE_INTEGER,
	MATRIX_TYPE_FLOAT

} MatrixType_en;


typedef struct
{
	MatrixType_en	enType;
	int16	iElementSize;
	int32	lNbrRows;
	int32	lNbrCols;

} MatrixHeader_st, Matrix_st;

/* prototypes */

MatrixError_en matrix_new
	(
	Matrix_st **_pMatrix,
	int32 _lNbrRows,
	int32 _lNbrCols,
	MatrixType_en _enType
	);

MatrixError_en matrix_free
	(Matrix_st *_pMatrix
	);

MatrixError_en matrix_dup
	(
	Matrix_st **_pNewMatrix,
	Matrix_st *_pMatrix
	);

MatrixError_en matrix_copy
	(
	Matrix_st *_pDestMatrix,
	Matrix_st *_pSrceMatrix
	);

MatrixError_en matrix_copy_row
	(
	Matrix_st *_pDestMatrix,
	int32 _lDestIndex,
	Matrix_st *_pSrceMatrix,
	int32 _lSrceIndex
	);

MatrixError_en matrix_copy_col
	(
	Matrix_st *_pDestMatrix,
	int32 _lDestIndex,
	Matrix_st *_pSrceMatrix,
	int32 _lSrceIndex
	);

MatrixError_en matrix_put_integer
	(
	Matrix_st *_pMatrix,
	int32 _lRow,
	int32 _lCol,
	int32 _lValue
	);

MatrixError_en matrix_put_float
	(
	Matrix_st *_pMatrix,
	int32 _lRow,
	int32 _lCol,
	float _fValue
	);

int32 matrix_get_integer
	(
	Matrix_st *_pMatrix,
	int32 _lRow,
	int32 _lCol
	);

float matrix_get_float
	(
	Matrix_st *_pMatrix,
	int32 _lRow,
	int32 _lCol
	);

MatrixType_en matrix_get_type
	(
	Matrix_st *_pMatrix
	);

int32 matrix_get_rows
	(
	Matrix_st *_pMatrix
	);

int32 matrix_get_cols
	(
	Matrix_st *_pMatrix
	);

MatrixError_en matrix_transpose
	(
	Matrix_st *_pMatrix1,
	Matrix_st *_pMatrix2,
	Matrix_st **_pNewMatrix
	);

MatrixError_en matrix_invert
	(
	Matrix_st *_pMatrix1,
	Matrix_st *_pMatrix2,
	Matrix_st **_pNewMatrix
	);

MatrixError_en matrix_add
	(
	Matrix_st *_pMatrix_1,
	Matrix_st *_pMatrix_2,
	Matrix_st *_pMatrix_3,
	Matrix_st **_pMatrix_4
	);

MatrixError_en matrix_sub
	(
	Matrix_st *_pMatrix_1,
	Matrix_st *_pMatrix_2,
	Matrix_st *_pMatrix_3,
	Matrix_st **_pMatrix_4
	);

MatrixError_en matrix_multiply
	(
	Matrix_st *_pMatrix_1,
	Matrix_st *_pMatrix_2,
	Matrix_st *_pMatrix_3,
	Matrix_st **_pNewMatrix
	);

MatrixError_en matrix_scalar_integer
	(
	Matrix_st *_pMatrix_1,
	int32 _lValue,
	Matrix_st *_pMatrix_2,
	Matrix_st **_pMatrixResult
	);

MatrixError_en matrix_scalar_float
	(
	Matrix_st *_pMatrix_1,
	float _fValue,
	Matrix_st *_pMatrix_2,
	Matrix_st **_pMatrixResult
	);

MatrixError_en matrix_print
	(
	Matrix_st *_pMatrix
	);

#endif	 /* MATRIX_H */

/* eof ********************************************************************/

