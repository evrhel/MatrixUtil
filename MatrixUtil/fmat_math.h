/*!
\file
Contains methods for performing operations on floating-point matrices.
*/

#pragma once

#ifndef FMAT_MATH_H
#define FMAT_MATH_H

#include "settings.h"
#include "mat_types.h"

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
	Matrix2	MUTIL_EXPORT	inverse(Matrix2 const &mat2, bool *exists = nullptr);

	// Matrix3 operations

	/*!
	Calculates the inverse of a 3x3 matrix, if one exists.

	@param mat3 The matrix to invert.
	@param exists A pointer to a bool value.  Will be true if there is an inverse,
	or false otherwise.

	@return The inverted matrix, or the input matrix if no inverse exists.
	*/
	Matrix3 MUTIL_EXPORT	inverse(Matrix3 const &mat3, bool *exists = nullptr);

	// Matrix4 operations

	/*!
	Calculates the inverse of a 4x4 matrix, if one exists.

	@param mat4 The matrix to invert.
	@param exists A pointer to a bool value.  Will be true if there is an inverse,
	or false otherwise.

	@return The inverted matrix, or the input matrix if no inverse exists.
	*/
	Matrix4 MUTIL_EXPORT	inverse(Matrix4 const &mat4, bool *exists = nullptr);
}

#endif