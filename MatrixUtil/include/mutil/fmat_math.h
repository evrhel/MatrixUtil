/*!
\file
Contains methods for performing operations on floating-point matrices.
*/

#pragma once

#ifndef FMAT_MATH_H
#define FMAT_MATH_H

#include "settings.h"
#include "fmat_math_defs.h"

namespace mutil
{
	// Matrix2 operations

	/*!
	Calculates the determinant of a 2x2 matrix.

	@param mat2 The matrix to find the determinant of.

	@return The determinant.
	*/
	constexpr float determinant(const Matrix2 &mat2)
	{
		return __determinant2x2(
			mat2._11, mat2._12,
			mat2._21, mat2._22
		);
	}

	/*
	Calculates the transpose of a 2x2 matrix.
	
	@param mat2 The matrix to transpose.

	@return The transpose.
	*/
	constexpr Matrix2 transpose(const Matrix2 &mat2)
	{
		return __transpose2x2(
			mat2._11, mat2._12,
			mat2._21, mat2._22
		);
	}

	/*
	Calculates the cofactors of a 2x2 matrix.

	@param mat2 The matrix to find the cofactors for.
	
	@return The cofactor matrix.
	*/
	constexpr Matrix2 cofactor(const Matrix2 &mat2)
	{
		return __cofactor2x2(
			mat2._11, mat2._12,
			mat2._21, mat2._22
		);
	}

	/*
	Calculates the adjugate of a 2x2 matrix.

	@param mat2 The matrix to find the adjugate of.

	@return The adjugate matrix.
	*/
	constexpr Matrix2 adjugate(const Matrix2 &mat2)
	{
		return __adjugate2x2(
			mat2._11, mat2._12,
			mat2._21, mat2._22
		);
	}

	/*!
	Calculates the inverse of a 2x2 matrix.

	@param mat2 The matrix to invert.

	@return The inverse of the matrix. There is undefined behavior if the matrix does not have an inverse.
	*/
	constexpr Matrix2 inverse(const Matrix2 &mat2)
	{
		return adjugate(mat2) * (1.0f / determinant(mat2));
	}

	constexpr Matrix2 clamp(const Matrix2 &val, float min, float max)
	{
		Matrix2 result;
		for (size_t i = 0; i < 4; i++)
			result[i] = clamp(val[i], min, max);
		return result;
	}

	constexpr Matrix2 clamp(const Matrix2 &val, const Matrix2 &min, const Matrix2 &max)
	{
		Matrix2 result;
		for (size_t i = 0; i < 4; i++)
			result[i] = clamp(val[i], min[i], max[i]);
		return result;
	}

	constexpr float Matrix2::determinant() const { return mutil::determinant(*this); }
	constexpr Matrix2 Matrix2::transpose() const { return mutil::transpose(*this); }
	constexpr Matrix2 Matrix2::inverse() const { return mutil::inverse(*this); };

	// Matrix3 operations

	/*!
	Calculates the determinant of a 3x3 matrix.

	@param mat3 The matrix to find the determinant of.

	@return The determinant.
	*/
	constexpr float determinant(const Matrix3 &mat3)
	{
		return __determinant3x3(
			mat3._11, mat3._12, mat3._13,
			mat3._21, mat3._22, mat3._23,
			mat3._31, mat3._32, mat3._33);
	}

	/*
	Calculates the transpose of a 3x3 matrix.

	@param mat3 The matrix to transpose.

	@return The transpose.
	*/
	constexpr Matrix3 transpose(const Matrix3 &mat3)
	{
		return __transpose3x3(
			mat3._11, mat3._12, mat3._13,
			mat3._21, mat3._22, mat3._23,
			mat3._31, mat3._32, mat3._33
		);
	}

	/*
	Calculates the cofactors of a 3x3 matrix.

	@param mat3 The matrix to find the cofactors for.

	@return The cofactor matrix.
	*/
	constexpr Matrix3 cofator(const Matrix3 &mat3)
	{
		return __cofactor3x3(
			mat3._11, mat3._12, mat3._13,
			mat3._21, mat3._22, mat3._23,
			mat3._31, mat3._32, mat3._33
		);
	}

	/*
	Calculates the adjugate of a 3x3 matrix.

	@param mat3 The matrix to find the adjugate of.
	
	@return The adjugate matrix.
	*/
	constexpr Matrix3 adjugate(const Matrix3 &mat3)
	{
		return __adjugate3x3(
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
	constexpr Matrix3 inverse(const Matrix3 &mat3)
	{
		return adjugate(mat3) * (1.0f / determinant(mat3));
	}

	constexpr Matrix3 clamp(const Matrix3 &val, float min, float max)
	{
		Matrix3 result;
		for (size_t i = 0; i < 9; i++)
			result[i] = clamp(val[i], min, max);
		return result;
	}

	constexpr Matrix3 clamp(const Matrix3 &val, const Matrix3 &min, const Matrix3 &max)
	{
		Matrix3 result;
		for (size_t i = 0; i < 9; i++)
			result[i] = clamp(val[i], min[i], max[i]);
		return result;
	}

	constexpr float Matrix3::determinant() const { return mutil::determinant(*this); }
	constexpr Matrix3 Matrix3::transpose() const { return mutil::transpose(*this); }
	constexpr Matrix3 Matrix3::inverse() const { return mutil::inverse(*this); };

	// Matrix4 operations

	/*!
	Calculates the determinant of a 4x4 matrix.

	@param mat4 The matrix to find the determinant of.

	@return The determinant.
	*/
	constexpr float determinant(const Matrix4 &mat4)
	{
		return __determinant4x4(
			mat4._11, mat4._12, mat4._13, mat4._14,
			mat4._21, mat4._22, mat4._23, mat4._24,
			mat4._31, mat4._32, mat4._33, mat4._34,
			mat4._41, mat4._42, mat4._43, mat4._44
		);
	}

	/*
	Calculates the transpose of a 4x4 matrix.

	@param mat4 The matrix to transpose.

	@return The transpose.
	*/
	constexpr Matrix4 transpose(const Matrix4 &mat4)
	{
		return __transpose4x4(
			mat4._11, mat4._12, mat4._13, mat4._14,
			mat4._21, mat4._22, mat4._23, mat4._24,
			mat4._31, mat4._32, mat4._33, mat4._34,
			mat4._41, mat4._42, mat4._43, mat4._44
		);
	}

	/*
	Calculates the cofactors of a 4x4 matrix.

	@param mat4 The matrix to find the cofactors for.

	@return The cofactor matrix.
	*/
	constexpr Matrix4 cofactor(const Matrix4 &mat4)
	{
		return __cofactor4x4(
			mat4._11, mat4._12, mat4._13, mat4._14,
			mat4._21, mat4._22, mat4._23, mat4._24,
			mat4._31, mat4._32, mat4._33, mat4._34,
			mat4._41, mat4._42, mat4._43, mat4._44
		);
	}

	/*
	Calculates the adjugate of a 4x4 matrix.

	@param mat4 The matrix to find the adjugate of.

	@return The adjugate matrix.
	*/
	constexpr Matrix4 adjugate(const Matrix4 &mat4)
	{
		return __adjugate4x4(
			mat4._11, mat4._12, mat4._13, mat4._14,
			mat4._21, mat4._22, mat4._23, mat4._24,
			mat4._31, mat4._32, mat4._33, mat4._34,
			mat4._41, mat4._42, mat4._43, mat4._44
		);
	}

	/*!
	Calculates the inverse of a 4x4 matrix.

	@param mat4 The matrix to invert.

	@return The inverse of the matrix. There is undefined behavior if the matrix does not have an inverse.
	*/
	constexpr Matrix4 inverse(const Matrix4 &mat4)
	{
		return adjugate(mat4) * (1.0f / determinant(mat4));
	}

	constexpr Matrix4 clamp(const Matrix4 &val, float min, float max)
	{
		Matrix4 result;
		for (size_t i = 0; i < 16; i++)
			result[i] = clamp(val[i], min, max);
		return result;
	}

	constexpr Matrix4 clamp(const Matrix4 &val, const Matrix4 &min, const Matrix4 &max)
	{
		Matrix4 result;
		for (size_t i = 0; i < 16; i++)
			result[i] = clamp(val[i], min[i], max[i]);
		return result;
	}

	constexpr float Matrix4::determinant() const { return mutil::determinant(*this); }
	constexpr Matrix4 Matrix4::transpose() const { return mutil::transpose(*this); }
	constexpr Matrix4 Matrix4::inverse() const { return mutil::inverse(*this); };
}

#endif