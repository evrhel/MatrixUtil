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
#include "matrix.h"

#include <memory>


namespace mutil
{
	// Matrix2 operations

	MUTIL_INLINE float determinant(const Matrix2 &mat2)
	{
		return mat2._11 * mat2._22 - mat2._12 * mat2._12;
	}

	/*!
	Calculates the inverse of a 2x2 matrix, if one exists.

	@param mat2 The matrix to invert.
	@param exists A pointer to a bool value.  Will be true if there is an inverse,
	or false otherwise.

	@return The inverted matrix, or the input matrix if no inverse exists.
	*/
	MUTIL_INLINE Matrix2 inverse(const Matrix2 &mat2, bool *exists = nullptr)
	{
		matrix *mat = matrix::matrix_from_array((float *)&mat2, 2, 2);
		matrix *inv = matrix::matrix_invert(mat);
		delete mat;
		if (inv == NULL)
		{
			if (exists)
				*exists = false;
			delete inv;
			return mat2;
		}
		else
		{
			if (exists)
				*exists = true;
			Matrix2 result;
			inv->get_elements((float *)&result);
			delete inv;
			return result;
		}
	}

	// Matrix3 operations

	MUTIL_INLINE float determinant(const Matrix3 &mat3)
	{
		return	(mat3._11 * mat3._22 * mat3._33) + (mat3._12 * mat3._32 * mat3._13) +
				(mat3._13 * mat3._12 * mat3._23) - (mat3._31 * mat3._22 * mat3._13) -
				(mat3._21 * mat3._12 * mat3._33) - (mat3._11 * mat3._32 * mat3._23);
	}

	/*!
	Calculates the inverse of a 3x3 matrix, if one exists.

	@param mat3 The matrix to invert.
	@param exists A pointer to a bool value.  Will be true if there is an inverse,
	or false otherwise.

	@return The inverted matrix, or the input matrix if no inverse exists.
	*/
	MUTIL_INLINE Matrix3 inverse(const Matrix3 &mat3, bool *exists = nullptr)
	{
		matrix *mat = matrix::matrix_from_array((float *)&mat3, 3, 3);
		matrix *inv = matrix::matrix_invert(mat);
		delete mat;
		if (inv == NULL)
		{
			if (exists)
				*exists = false;
			delete inv;
			return mat3;
		}
		else
		{
			if (exists)
				*exists = true;
			Matrix3 result;
			inv->get_elements((float *)&result);
			delete inv;
			return result;
		}
	}

	// Matrix4 operations

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

	/*!
	Calculates the inverse of a 4x4 matrix, if one exists.

	@param mat4 The matrix to invert.
	@param exists A pointer to a bool value.  Will be true if there is an inverse,
	or false otherwise.

	@return The inverted matrix, or the input matrix if no inverse exists.
	*/
	MUTIL_INLINE Matrix4 inverse(const Matrix4 &mat4, bool *exists = nullptr)
	{
		matrix *mat = matrix::matrix_from_array((float *)&mat4, 4, 4);
		matrix *inv = matrix::matrix_invert(mat);
		delete mat;
		if (inv == NULL)
		{
			if (exists)
				*exists = false;
			delete inv;
			return mat4;
		}
		else
		{
			if (exists)
				*exists = true;
			Matrix4 result;
			inv->get_elements((float *)&result);
			delete inv;
			return result;
		}
	}

}

#endif