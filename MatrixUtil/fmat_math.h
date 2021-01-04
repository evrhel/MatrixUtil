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