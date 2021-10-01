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

	MUTIL_CONSTEXPR float determinant(
		float _11, float _12,
		float _21, float _22)
	{
		return _11 * _22 - _12 * _21;
	}

	/*!
	Calculates the determinant of a 2x2 matrix.

	@param mat2 The matrix to find the determinant of.

	@return The determinant.
	*/
	MUTIL_CONSTEXPR float determinant(const Matrix2 &mat2)
	{
		return determinant(mat2._11, mat2._12, mat2._21, mat2._22);
	}

	/*
	Calculates the transpose of a 2x2 matrix.
	
	@param mat2 The matrix to transpose.

	@return The transpose.
	*/
	MUTIL_CONSTEXPR Matrix2 transpose(const Matrix2 &mat2)
	{
		return Matrix2(
			mat2._11, mat2._21,
			mat2._12, mat2._22
		);
	}

	MUTIL_CONSTEXPR Matrix2 cofactor(
		float _11, float _12,
		float _21, float _22
	)
	{
		return Matrix2(
			_22, -_21,
			-_21, _11
		);
	}

	MUTIL_CONSTEXPR Matrix2 cofactor(const Matrix2 &mat2)
	{
		return cofactor(
			mat2._11, mat2._12,
			mat2._21, mat2._22
		);
	}

	MUTIL_CONSTEXPR Matrix2 adjugate(
		float _11, float _12,
		float _21, float _22
	)
	{
		return transpose(cofactor(
			_11, _12,
			_21, _22
		));
	}

	/*
	Calculates the adjugate of a 2x2 matrix.

	@param mat2 The matrix to find the adjugate of.

	@return The adjugate matrix.
	*/
	MUTIL_CONSTEXPR Matrix2 adjugate(const Matrix2 &mat2)
	{
		return adjugate(
			mat2._11, mat2._12,
			mat2._21, mat2._22
		);
	}

	/*!
	Calculates the inverse of a 2x2 matrix.

	@param mat2 The matrix to invert.

	@return The inverse of the matrix. There is undefined behavior if the matrix does not have an inverse.
	*/
	MUTIL_CONSTEXPR Matrix2 inverse(const Matrix2 &mat2)
	{
		return adjugate(mat2) * (1.0f / determinant(mat2));
	}

	// Matrix3 operations

	MUTIL_CONSTEXPR float determinant(
		float _11, float _12, float _13,
		float _21, float _22, float _23,
		float _31, float _32, float _33)
	{
		return
			_11 * determinant(_22, _23, _32, _33) -
			_12 * determinant(_21, _23, _31, _33) +
			_13 * determinant(_21, _22, _31, _32);
	}

	/*!
	Calculates the determinant of a 3x3 matrix.

	@param mat3 The matrix to find the determinant of.

	@return The determinant.
	*/
	MUTIL_CONSTEXPR float determinant(const Matrix3 &mat3)
	{
		return determinant(
			mat3._11, mat3._12, mat3._13,
			mat3._21, mat3._22, mat3._23,
			mat3._31, mat3._32, mat3._33);
	}

	MUTIL_CONSTEXPR Matrix3 transpose(
		float _11, float _12, float _13,
		float _21, float _22, float _23,
		float _31, float _32, float _33)
	{
		return Matrix3(
			_11, _21, _31,
			_12, _22, _32,
			_13, _23, _33
		);
	}

	/*
	Calculates the transpose of a 3x3 matrix.

	@param mat3 The matrix to transpose.

	@return The transpose.
	*/
	MUTIL_CONSTEXPR Matrix3 transpose(const Matrix3 &mat3)
	{
		return transpose(
			mat3._11, mat3._21, mat3._31,
			mat3._12, mat3._22, mat3._32,
			mat3._13, mat3._23, mat3._33
		);
	}

	MUTIL_CONSTEXPR Matrix3 cofactor(
		float _11, float _12, float _13,
		float _21, float _22, float _23,
		float _31, float _32, float _33
	)
	{
		return Matrix3(
			// Row 1
			_11 * determinant(
				_22, _23,
				_32, _33),
			_12 * determinant(
				_21, _23,
				_31, _33
			),
			_13 * determinant(
				_21, _22,
				_31, _32
			),

			// Row 2
			_21 * determinant(
				_12, _13,
				_32, _33
			),
			_22 * determinant(
				_11, _13,
				_31, _33
			),
			_23 * determinant(
				_11, _12,
				_31, _32
			),

			// Row 3
			_31 * determinant(
				_12, _13,
				_22, _23
			),
			_32 * determinant(
				_11, _13,
				_21, _23
			),
			_33 * determinant(
				_11, _12,
				_21, _22
			)
		);
	}

	MUTIL_CONSTEXPR Matrix3 cofator(const Matrix3 &mat3)
	{
		return cofactor(
			mat3._11, mat3._12, mat3._13,
			mat3._21, mat3._22, mat3._23,
			mat3._31, mat3._32, mat3._33
		);
	}

	MUTIL_CONSTEXPR Matrix3 adjugate(
		float _11, float _12, float _13,
		float _21, float _22, float _23,
		float _31, float _32, float _33
	)
	{
		return transpose(cofactor(
			_11, _12, _13,
			_21, _22, _23,
			_31, _32, _33
		));
	}

	/*
	Calculates the adjugate of a 3x3 matrix.

	@param mat3 The matrix to find the adjugate of.
	
	@return The adjugate matrix.
	*/
	MUTIL_CONSTEXPR Matrix3 adjugate(const Matrix3 &mat3)
	{
		return adjugate(
			mat3._11, mat3._12, mat3._13,
			mat3._21, mat3._22, mat3._23,
			mat3._31, mat3._32, mat3._33
		);
	}

	/*!
	Calculates the inverse of a 3x3 matrix.

	@param mat3 The matrix to invert.

	@return The inverse of the matrix. There is undefined behavior if the matrix does not have an inverse.
	*/
	MUTIL_CONSTEXPR Matrix3 inverse(const Matrix3 &mat3)
	{
		return adjugate(mat3) * (1.0f / determinant(mat3));
	}

	// Matrix4 operations

	MUTIL_CONSTEXPR float determinant(
		float _11, float _12, float _13, float _14,
		float _21, float _22, float _23, float _24,
		float _31, float _32, float _33, float _34,
		float _41, float _42, float _43, float _44
	)
	{
		return
			_11 * determinant(_22, _32, _42, _23, _33, _43, _41, _24, _44) -
			_21 * determinant(_21, _32, _42, _31, _33, _43, _41, _34, _44) +
			_31 * determinant(_21, _22, _42, _31, _23, _43, _41, _24, _44) -
			_41 * determinant(_21, _22, _32, _31, _23, _33, _41, _24, _34);
	}

	/*!
	Calculates the determinant of a 4x4 matrix.

	@param mat4 The matrix to find the determinant of.

	@return The determinant.
	*/
	MUTIL_CONSTEXPR float determinant(const Matrix4 &mat4)
	{
		return determinant(
			mat4._11, mat4._12, mat4._13, mat4._14,
			mat4._21, mat4._22, mat4._23, mat4._24,
			mat4._31, mat4._32, mat4._33, mat4._34,
			mat4._41, mat4._42, mat4._43, mat4._44
		);
	}

	MUTIL_CONSTEXPR Matrix4 transpose(
		float _11, float _12, float _13, float _14,
		float _21, float _22, float _23, float _24,
		float _31, float _32, float _33, float _34,
		float _41, float _42, float _43, float _44
	)
	{
		return Matrix4(
			_11, _21, _31, _41,
			_12, _22, _32, _42,
			_13, _23, _33, _43,
			_14, _24, _34, _44
		);
	}

	/*
	Calculates the transpose of a 4x4 matrix.

	@param mat4 The matrix to transpose.

	@return The transpose.
	*/
	MUTIL_CONSTEXPR Matrix4 transpose(const Matrix4 &mat4)
	{
		return transpose(
			mat4._11, mat4._21, mat4._31, mat4._41,
			mat4._12, mat4._22, mat4._32, mat4._42,
			mat4._13, mat4._23, mat4._33, mat4._43,
			mat4._14, mat4._24, mat4._34, mat4._44
		);
	}

	MUTIL_CONSTEXPR Matrix4 cofactor(
		float _11, float _12, float _13, float _14,
		float _21, float _22, float _23, float _24,
		float _31, float _32, float _33, float _34,
		float _41, float _42, float _43, float _44
	)
	{
		return Matrix4(
			// Row 1
			_11 * determinant(
				_22, _23, _24,
				_32, _33, _34,
				_42, _43, _44
			),
			_12 * determinant(
				_21, _23, _24,
				_31, _33, _34,
				_41, _43, _44
			),
			_13 * determinant(
				_21, _22, _24,
				_31, _32, _34,
				_41, _42, _44
			),
			_14 * determinant(
				_21, _22, _23,
				_31, _32, _33,
				_41, _42, _43
			),

			// Row 2
			_21 * determinant(
				_12, _13, _14,
				_32, _33, _34,
				_42, _43, _44
			),
			_22 * determinant(
				_11, _13, _14,
				_31, _33, _34,
				_41, _43, _44
			),
			_23 * determinant(
				_11, _12, _14,
				_31, _32, _34,
				_41, _42, _44
			),
			_24 * determinant(
				_11, _12, _13,
				_31, _32, _33,
				_41, _42, _43
			),

			// Row 3
			_31 * determinant(
				_12, _13, _14,
				_22, _23, _24,
				_42, _43, _44
			),
			_32 * determinant(
				_11, _13, _14,
				_21, _23, _24,
				_41, _43, _44
			),
			_33 * determinant(
				_11, _12, _14,
				_21, _22, _24,
				_41, _42, _44
			),
			_34 * determinant(
				_11, _12, _13,
				_21, _22, _23,
				_41, _42, _43
			),

			// Row 4
			_41 * determinant(
				_12, _13, _14,
				_22, _23, _24,
				_32, _33, _34
			),
			_42 * determinant(
				_11, _13, _14,
				_21, _23, _24,
				_31, _33, _34
			),
			_43 * determinant(
				_11, _12, _14,
				_21, _22, _24,
				_31, _32, _34
			),
			_44 * determinant(
				_11, _12, _13,
				_21, _22, _23,
				_31, _32, _33
			)
		);
	}

	MUTIL_CONSTEXPR Matrix4 cofactor(const Matrix4 &mat4)
	{
		return cofactor(
			mat4._11, mat4._12, mat4._13, mat4._14,
			mat4._21, mat4._22, mat4._23, mat4._24,
			mat4._31, mat4._32, mat4._33, mat4._34,
			mat4._41, mat4._42, mat4._43, mat4._44
		);
	}

	MUTIL_CONSTEXPR Matrix4 adjugate(
		float _11, float _12, float _13, float _14,
		float _21, float _22, float _23, float _24,
		float _31, float _32, float _33, float _34,
		float _41, float _42, float _43, float _44
	)
	{
		return transpose(cofactor(
			_11, _12, _13, _14,
			_21, _22, _23, _24,
			_31, _32, _33, _34,
			_41, _42, _43, _44
		));
	}


	/*
	Calculates the adjugate of a 4x4 matrix.

	@param mat4 The matrix to find the adjugate of.

	@return The adjugate matrix.
	*/
	MUTIL_CONSTEXPR Matrix4 adjugate(const Matrix4 &mat4)
	{
		return adjugate(
			mat4._11, mat4._12, mat4._13, mat4._13,
			mat4._21, mat4._22, mat4._23, mat4._24,
			mat4._21, mat4._32, mat4._33, mat4._34,
			mat4._41, mat4._42, mat4._43, mat4._44
		);
	}

	/*!
	Calculates the inverse of a 4x4 matrix.

	@param mat4 The matrix to invert.

	@return The inverse of the matrix. There is undefined behavior if the matrix does not have an inverse.
	*/
	MUTIL_CONSTEXPR Matrix4 inverse(const Matrix4 &mat4)
	{
		return adjugate(mat4) * (1.0f / determinant(mat4));
	}
}

#endif