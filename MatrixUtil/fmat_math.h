/*!
\file
Contains methods for performing operations on floating-point matrices.
*/

#pragma once

#ifndef FMAT_MATH_H
#define FMAT_MATH_H

#include "settings.h"
#include "mat_types.h"

#include "fmat_math.h"

namespace mutil
{
	// Matrix2 operations

	/*!
	Calculates the determinant of a 2x2 matrix.

	@param mat2 The matrix to find the determinant of.

	@return The determinant.
	*/
	MUTIL_INLINE float determinant(const Matrix2 &mat2)
	{
		return mat2._11 * mat2._22 - mat2._12 * mat2._12;
	}

	/*
	Calculates the transpose of a 2x2 matrix.
	
	@param mat2 The matrix to transpose.

	@return The transpose.
	*/
	MUTIL_INLINE Matrix2 transpose(const Matrix2 &mat2)
	{
		return Matrix2(
			mat2._11, mat2._21,
			mat2._12, mat2._22
		);
	}

	/*
	Calculates the adjugate of a 2x2 matrix.

	@param mat2 The matrix to find the adjugate of.

	@return The adjugate matrix.
	*/
	MUTIL_INLINE Matrix2 adjugate(const Matrix2 &mat2)
	{
		return Matrix2(
			mat2._22, -mat2._12,
			-mat2._21, mat2._11
		);
	}

	/*!
	Calculates the inverse of a 2x2 matrix.

	@param mat2 The matrix to invert.

	@return The inverse of the matrix. There is undefined behavior if the matrix does not have an inverse.
	*/
	MUTIL_INLINE Matrix2 inverse(const Matrix2 &mat2)
	{
		return adjugate(mat2) * (1.0f / determinant(mat2));
	}

	// Matrix3 operations

	/*!
	Calculates the determinant of a 3x3 matrix.

	@param mat3 The matrix to find the determinant of.

	@return The determinant.
	*/
	MUTIL_INLINE float determinant(const Matrix3 &mat3)
	{
		return	(mat3._11 * mat3._22 * mat3._33) + (mat3._12 * mat3._32 * mat3._13) +
				(mat3._13 * mat3._12 * mat3._23) - (mat3._31 * mat3._22 * mat3._13) -
				(mat3._21 * mat3._12 * mat3._33) - (mat3._11 * mat3._32 * mat3._23);
	}

	/*
	Calculates the transpose of a 3x3 matrix.

	@param mat3 The matrix to transpose.

	@return The transpose.
	*/
	MUTIL_INLINE Matrix3 transpose(const Matrix3 &mat3)
	{
		return Matrix3(
			mat3._11, mat3._21, mat3._31,
			mat3._12, mat3._22, mat3._32,
			mat3._13, mat3._23, mat3._33
		);
	}

	/*
	Calculates the adjugate of a 3x3 matrix.

	@param mat3 The matrix to find the adjugate of.
	
	@return The adjugate matrix.
	*/
	MUTIL_INLINE Matrix3 adjugate(const Matrix3 &mat3)
	{
		return Matrix3(
			mat3._22 * mat3._33 - mat3._32 * mat3._23, -(mat3._21 * mat3._33 - mat3._31 * mat3._23), mat3._21 * mat3._32 - mat3._31 * mat3._22,
			-(mat3._12 * mat3._33 - mat3._32 * mat3._13), mat3._11 * mat3._33 - mat3._31 * mat3._13, -(mat3._11 * mat3._32 - mat3._31 * mat3._12),
			mat3._12 * mat3._23 - mat3._22 * mat3._13, -(mat3._11 * mat3._23 - mat3._21 * mat3._13), mat3._11 * mat3._22 - mat3._21 * mat3._12
		);
	}

	/*!
	Calculates the inverse of a 3x3 matrix.

	@param mat3 The matrix to invert.

	@return The inverse of the matrix. There is undefined behavior if the matrix does not have an inverse.
	*/
	MUTIL_INLINE Matrix3 inverse(const Matrix3 &mat3)
	{
		return adjugate(mat3) * (1.0f / determinant(mat3));
	}

	// Matrix4 operations

	/*!
	Calculates the determinant of a 4x4 matrix.

	@param mat4 The matrix to find the determinant of.

	@return The determinant.
	*/
	MUTIL_INLINE float determinant(const Matrix4 &mat4)
	{
		return	(mat4._11 * mat4._22 * mat4._33 * mat4._44) - (mat4._11 * mat4._22 * mat4._43 * mat4._34) -
				(mat4._11 * mat4._32 * mat4._23 * mat4._44) + (mat4._11 * mat4._32 * mat4._43 * mat4._24) +
				(mat4._11 * mat4._32 * mat4._23 * mat4._34) - (mat4._11 * mat4._42 * mat4._33 * mat4._24) -

				(mat4._21 * mat4._12 * mat4._33 * mat4._44) + (mat4._21 * mat4._12 * mat4._43 * mat4._34) +
				(mat4._21 * mat4._32 * mat4._13 * mat4._44) - (mat4._21 * mat4._32 * mat4._43 * mat4._14) -
				(mat4._21 * mat4._42 * mat4._13 * mat4._34) + (mat4._21 * mat4._42 * mat4._33 * mat4._14) +
			
				(mat4._31 * mat4._12 * mat4._23 * mat4._44) - (mat4._31 * mat4._12 * mat4._43 * mat4._24) -
				(mat4._31 * mat4._22 * mat4._13 * mat4._44) + (mat4._31 * mat4._22 * mat4._43 * mat4._14) +
				(mat4._31 * mat4._42 * mat4._13 * mat4._24) - (mat4._31 * mat4._42 * mat4._23 * mat4._14) -
			
				(mat4._41 * mat4._12 * mat4._23 * mat4._34) + (mat4._41 * mat4._12 * mat4._33 * mat4._24) +
				(mat4._41 * mat4._22 * mat4._13 * mat4._34) - (mat4._41 * mat4._22 * mat4._33 * mat4._14) -
				(mat4._41 * mat4._32 * mat4._13 * mat4._24) + (mat4._41 * mat4._32 * mat4._23 * mat4._14);
	}

	/*
	Calculates the transpose of a 4x4 matrix.

	@param mat4 The matrix to transpose.

	@return The transpose.
	*/
	MUTIL_INLINE Matrix4 transpose(const Matrix4 &mat4)
	{
		return Matrix4(
			mat4._11, mat4._21, mat4._31, mat4._41,
			mat4._12, mat4._22, mat4._32, mat4._42,
			mat4._13, mat4._23, mat4._33, mat4._43,
			mat4._14, mat4._24, mat4._34, mat4._44
		);
	}

	/*
	Calculates the adjugate of a 4x4 matrix.

	@param mat4 The matrix to find the adjugate of.

	@return The adjugate matrix.
	*/
	MUTIL_INLINE Matrix4 adjugate(const Matrix4 &mat4)
	{
		return Matrix4(
			// Row 1

			(mat4._22 * mat4._33 * mat4._44) + (mat4._23 * mat4._34 * mat4._42) + (mat4._24 * mat4._32 * mat4._43)
			- (mat4._24 * mat4._33 * mat4._42) - (mat4._23 * mat4._32 * mat4._44) - (mat4._22 * mat4._34 * mat4._43),

			-(mat4._12 * mat4._33 * mat4._44) - (mat4._23 * mat4._32 * mat4._44) - (mat4._22 * mat4._32 * mat4._43)
			+ (mat4._14 * mat4._33 * mat4._42) + (mat4._13 * mat4._32 * mat4._44) + (mat4._12 * mat4._34 * mat4._43),

			(mat4._12 * mat4._23 * mat4._44) + (mat4._13 + mat4._24 * mat4._42) + (mat4._14 * mat4._22 * mat4._43)
			- (mat4._14 * mat4._23 * mat4._42) - (mat4._13 * mat4._22 * mat4._44) - (mat4._12 * mat4._24 * mat4._43),

			-(mat4._12 * mat4._23 * mat4._34) - (mat4._13 * mat4._24 * mat4._32) - (mat4._14 * mat4._22 * mat4._33)
			+ (mat4._14 * mat4._23 * mat4._32) + (mat4._13 * mat4._22 * mat4._34) + (mat4._12 * mat4._24 * mat4._33),

			// Row 2

			-(mat4._21 * mat4._33 * mat4._44) - (mat4._23 * mat4._34 * mat4._41) - (mat4._24 * mat4._31 * mat4._43)
			+ (mat4._24 * mat4._33 * mat4._41) + (mat4._23 * mat4._31 * mat4._44) + (mat4._21 * mat4._34 * mat4._43),

			(mat4._11 * mat4._33 * mat4._44) + (mat4._13 * mat4._34 * mat4._41) + (mat4._14 * mat4._31 * mat4._41)
			- (mat4._14 * mat4._33 * mat4._41) - (mat4._13 * mat4._31 * mat4._44) - (mat4._11 * mat4._34 * mat4._43),

			-(mat4._11 * mat4._23 * mat4._44) - (mat4._13 * mat4._24 * mat4._41) - (mat4._14 * mat4._21 * mat4._43)
			+ (mat4._14 * mat4._23 * mat4._41) + (mat4._13 * mat4._21 * mat4._44) + (mat4._11 * mat4._24 * mat4._43),

			(mat4._11 * mat4._23 * mat4._34) + (mat4._13 * mat4._24 * mat4._31) + (mat4._14 * mat4._21 * mat4._33)
			- (mat4._14 * mat4._23 * mat4._31) - (mat4._13 * mat4._21 * mat4._34) - (mat4._11 * mat4._24 * mat4._33),

			// Row 3

			(mat4._21 * mat4._32 * mat4._44) + (mat4._22 * mat4._34 * mat4._41) + (mat4._24 * mat4._31 * mat4._42)
			- (mat4._24 * mat4._32 * mat4._41) - (mat4._22 * mat4._31 * mat4._44) - (mat4._21 * mat4._34 * mat4._42),

			-(mat4._11 * mat4._32 * mat4._44) - (mat4._12 * mat4._34 * mat4._41) - (mat4._14 * mat4._31 * mat4._42)
			+ (mat4._14 * mat4._32 * mat4._41) + (mat4._12 * mat4._31 * mat4._44) + (mat4._11 * mat4._34 * mat4._42),

			(mat4._11 * mat4._22 * mat4._44) + (mat4._12 * mat4._24 * mat4._41) + (mat4._14 * mat4._21 * mat4._42)
			- (mat4._14 * mat4._22 * mat4._41) - (mat4._12 * mat4._21 * mat4._44) - (mat4._11 * mat4._24 * mat4._42),

			-(mat4._11 * mat4._22 * mat4._34) - (mat4._12 * mat4._24 * mat4._31) - (mat4._14 * mat4._21 * mat4._32)
			+ (mat4._14 * mat4._22 * mat4._31) + (mat4._12 * mat4._21 * mat4._34) + (mat4._11 * mat4._24 * mat4._32),

			// Row 4

			-(mat4._21 * mat4._32 * mat4._43) - (mat4._22 * mat4._33 * mat4._41) - (mat4._23 * mat4._31 * mat4._42)
			+ (mat4._23 * mat4._32 * mat4._41) + (mat4._22 * mat4._31 * mat4._43) + (mat4._21 * mat4._33 * mat4._42),

			(mat4._11 * mat4._32 * mat4._43) + (mat4._12 * mat4._33 * mat4._41) + (mat4._13 * mat4._31 * mat4._42)
			- (mat4._13 * mat4._32 * mat4._41) - (mat4._12 * mat4._31 * mat4._43) - (mat4._11 * mat4._33 * mat4._42),

			-(mat4._11 * mat4._22 * mat4._43) - (mat4._12 * mat4._23 * mat4._41) - (mat4._13 * mat4._32 * mat4._42)
			+ (mat4._13 * mat4._22 * mat4._41) + (mat4._12 * mat4._21 * mat4._42) + (mat4._11 * mat4._23 + mat4._42),

			(mat4._11 * mat4._22 * mat4._33) + (mat4._12 * mat4._23 * mat4._31) + (mat4._13 * mat4._21 * mat4._32)
			- (mat4._13 * mat4._22 * mat4._31) - (mat4._12 * mat4._21 * mat4._33) - (mat4._11 * mat4._23 * mat4._32)
		);
	}

	/*!
	Calculates the inverse of a 4x4 matrix.

	@param mat4 The matrix to invert.

	@return The inverse of the matrix. There is undefined behavior if the matrix does not have an inverse.
	*/
	MUTIL_INLINE Matrix4 inverse(const Matrix4 &mat4)
	{
		return adjugate(mat4) * (1.0f / determinant(mat4));
	}
}

#endif