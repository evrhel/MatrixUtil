/*!
\file
Contains classes for handling different types of matrices.
*/

#pragma once

#ifndef MAT_TYPES_H
#define MAT_TYPES_H

#include "settings.h"
#include "vec_types.h"

#include <memory>
#if defined(MUTIL_USE_INTRINSICS)
#if defined(MUTIL_X86)
#include <smmintrin.h>
#elif defined(MUTIL_ARM)
#endif
#endif

namespace mutil
{
	class Matrix2;
	class Matrix3;
	class Matrix4;

	class IntMatrix2;
	class IntMatrix3;
	class IntMatrix4;

	/*!
	Class wrapping a 2x2 matrix of floats.
	*/
	class Matrix2
	{
	public:
		/*!
		The matrix's columns.
		*/
		union
		{
			Vector2 columns[2];
			struct
			{
				float _11, _21;
				float _12, _22;
			};
			float mat[4];
		};

		/*!
		Constructs the identity matrix.
		*/
		constexpr Matrix2() : Matrix2(1.0f) {}

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit constexpr Matrix2(const float diagonal) : _11(diagonal), _12(0.0f),
														   _21(0.0f), _22(diagonal) {}

		/*!
		Constructs a matrix with two explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		*/
		explicit constexpr Matrix2(const Vector2 &column1, const Vector2 &column2) : _11(column1.x), _12(column2.x),
																					 _21(column1.y), _22(column2.y) {}

		explicit constexpr Matrix2(
			float _11, float _12,
			float _21, float _22) : _11(_11), _12(_12),
									_21(_21), _22(_22) {}

		/*!
		Constructs a matrix by casting it from a 32-bit integer matrix.

		@param mat2 The matrix to cast from.
		*/
		explicit constexpr Matrix2(const IntMatrix2 &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit constexpr Matrix2(const Matrix3 &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit constexpr Matrix2(const Matrix4 &mat);

		constexpr const float &operator[](size_t index) const
		{
			return mat[index];
		}

		constexpr float &operator[](size_t index)
		{
			return mat[index];
		}

		constexpr float determinant() const;
		constexpr Matrix2 transpose() const;
		constexpr Matrix2 inverse() const;
	};

	constexpr Matrix2 operator+(const Matrix2 &first, const Matrix2 &second)
	{
		return Matrix2(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1]);
	}

	constexpr Matrix2 operator-(const Matrix2 &first, const Matrix2 &second)
	{
		return Matrix2(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1]);
	}

	constexpr Matrix2 operator*(const Matrix2 &first, const Matrix2 &second)
	{
		return Matrix2(
			first._11 * second._11 + first._12 * second._21, first._11 * second._12 + first._12 * second._22,
			first._21 * second._11 + first._22 * second._21, first._21 * second._12 + first._22 * second._22);
	}

	constexpr Vector2 operator*(const Matrix2 &first, const Vector2 &second)
	{
		return Vector2(
			first._11 * second.x + first._12 * second.y,
			first._21 * second.x + first._22 * second.y);
	}

	constexpr Matrix2 operator*(const Matrix2 &first, float second)
	{
		return Matrix2(
			first.columns[0] * second,
			first.columns[1] * second);
	}

	constexpr Matrix2 operator/(const Matrix2 &first, float second)
	{
		return Matrix2(
			first.columns[0] / second,
			first.columns[1] / second);
	}

	constexpr bool operator==(const Matrix2 &first, const Matrix2 &second)
	{
		return first.columns[0] == second.columns[0] && first.columns[1] == second.columns[1];
	}

	/*!
	Class wrapping a 3x3 matrix of floats.
	*/
	class Matrix3
	{
	public:
		/*!
		The matrix's columns.
		*/
		union
		{
			Vector3 columns[3];
			struct
			{
				float _11, _21, _31;
				float _12, _22, _32;
				float _13, _23, _33;
			};
			float mat[9];
		};

		/*!
		Constructs the identity matrix.
		*/
		constexpr Matrix3() : Matrix3(1.0f) {}

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit constexpr Matrix3(const float diagonal) : _11(diagonal), _12(0.0f), _13(0.0f),
														   _21(0.0f), _22(diagonal), _23(0.0f),
														   _31(0.0f), _32(0.0f), _33(diagonal) {}

		/*!
		Constructs a matrix with three explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		@param column3 The third column.
		*/
		explicit constexpr Matrix3(const Vector3 &column1, const Vector3 &column2, const Vector3 &column3) : _11(column1.x), _12(column2.x), _13(column3.x),
																											 _21(column1.y), _22(column2.y), _23(column3.y),
																											 _31(column1.z), _32(column2.z), _33(column3.z) {}

		explicit constexpr Matrix3(
			float _11, float _12, float _13,
			float _21, float _22, float _23,
			float _31, float _32, float _33) : _11(_11), _12(_12), _13(_13),
											   _21(_21), _22(_22), _23(_23),
											   _31(_31), _32(_32), _33(_33) {}

		/*!
		Constructs a matrix by casting it from a 32-bit integer matrix.

		@param mat3 The matrix to cast from.
		*/
		explicit constexpr Matrix3(const IntMatrix3 &mat);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit constexpr Matrix3(const Matrix2 &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit constexpr Matrix3(const Matrix4 &mat);

		constexpr const float &operator[](size_t index) const
		{
			return mat[index];
		}

		constexpr float &operator[](size_t index)
		{
			return mat[index];
		}

		constexpr float determinant() const;
		constexpr Matrix3 transpose() const;
		constexpr Matrix3 inverse() const;
	};

	constexpr Matrix3 operator+(const Matrix3 &first, const Matrix3 &second)
	{
		return Matrix3(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1], first.columns[2] + second.columns[2]);
	}

	constexpr Matrix3 operator-(const Matrix3 &first, const Matrix3 &second)
	{
		return Matrix3(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1], first.columns[2] - second.columns[2]);
	}

	constexpr Matrix3 operator*(const Matrix3 &first, const Matrix3 &second)
	{
		return Matrix3(
			first._11 * second._11 + first._12 * second._21 + first._13 * second._31,
			first._11 * second._12 + first._12 * second._22 + first._13 * second._32,
			first._11 * second._13 + first._12 * second._23 + first._13 * second._33,
			first._21 * second._11 + first._22 * second._21 + first._23 * second._31,
			first._21 * second._12 + first._22 * second._22 + first._23 * second._32,
			first._21 * second._13 + first._22 * second._23 + first._23 * second._33,
			first._31 * second._11 + first._32 * second._21 + first._33 * second._31,
			first._31 * second._12 + first._32 * second._22 + first._33 * second._32,
			first._31 * second._13 + first._32 * second._23 + first._33 * second._33);
	}

	constexpr Vector3 operator*(const Matrix3 &first, const Vector3 &second)
	{
		return Vector3(
			first.columns[0].x * second.x + first.columns[1].x * second.y + first.columns[2].x * second.z,
			first.columns[0].y * second.x + first.columns[1].y * second.y + first.columns[2].y * second.z,
			first.columns[0].z * second.x + first.columns[1].z * second.y + first.columns[2].z * second.z);
	}

	constexpr Matrix3 operator*(const Matrix3 &first, float second)
	{
		return Matrix3(
			first.columns[0] * second,
			first.columns[1] * second,
			first.columns[2] * second);
	}

	constexpr Matrix3 operator/(const Matrix3 &first, float second)
	{
		return Matrix3(
			first.columns[0] / second,
			first.columns[1] / second,
			first.columns[2] / second);
	}

	constexpr bool operator==(const Matrix3 &first, const Matrix3 &second)
	{
		return first.columns[0] == second.columns[0] && first.columns[1] == second.columns[1] && first.columns[2] == second.columns[2];
	}

	/*!
	Class wrapping a 4x4 matrix of floats.
	*/
	class Matrix4
	{
	public:
		/*!
		The matrix's columns.
		*/
		union
		{
			Vector4 columns[4];
			struct
			{
				float _11, _21, _31, _41;
				float _12, _22, _32, _42;
				float _13, _23, _33, _43;
				float _14, _24, _34, _44;
			};
			float mat[16];
		};

		/*!
		Constructs the identity matrix.
		*/
		constexpr Matrix4() : Matrix4(1.0f) {}

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit constexpr Matrix4(const float diagonal) : _11(diagonal), _12(0.0f), _13(0.0f), _14(0.0f),
														   _21(0.0f), _22(diagonal), _23(0.0f), _24(0.0f),
														   _31(0.0f), _32(0.0f), _33(diagonal), _34(0.0f),
														   _41(0.0f), _42(0.0f), _43(0.0f), _44(diagonal) {}

		/*!
		Constructs a matrix with four explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		@param column3 The third column.
		@param column4 The fourth column.
		*/
		explicit constexpr Matrix4(const Vector4 &column1, const Vector4 &column2, const Vector4 &column3, const Vector4 &column4) : _11(column1.x), _12(column2.x), _13(column3.x), _14(column4.x),
																																	 _21(column1.y), _22(column2.y), _23(column3.y), _24(column4.y),
																																	 _31(column1.z), _32(column2.z), _33(column3.z), _34(column4.z),
																																	 _41(column1.w), _42(column2.w), _43(column3.w), _44(column4.w) {}

		explicit constexpr Matrix4(
			float _11, float _12, float _13, float _14,
			float _21, float _22, float _23, float _24,
			float _31, float _32, float _33, float _34,
			float _41, float _42, float _43, float _44) : _11(_11), _12(_12), _13(_13), _14(_14),
														  _21(_21), _22(_22), _23(_23), _24(_24),
														  _31(_31), _32(_32), _33(_33), _34(_34),
														  _41(_41), _42(_42), _43(_43), _44(_44) {}

		/*!
		Constructs a matrix by casting it from a 32-bit integer matrix.

		@param mat4 The matrix to cast from.
		*/
		explicit constexpr Matrix4(const IntMatrix4 &mat);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit constexpr Matrix4(const Matrix2 &mat);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit constexpr Matrix4(const Matrix3 &mat);

		constexpr const float &operator[](size_t index) const
		{
			return mat[index];
		}

		constexpr float &operator[](size_t index)
		{
			return mat[index];
		}

		constexpr float determinant() const;
		constexpr Matrix4 transpose() const;
		constexpr Matrix4 inverse() const;
	};

	constexpr Matrix4 operator+(const Matrix4 &first, const Matrix4 &second)
	{
		return Matrix4(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1], first.columns[2] + second.columns[2], first.columns[3] + second.columns[3]);
	}

	constexpr Matrix4 operator-(const Matrix4 &first, const Matrix4 &second)
	{
		return Matrix4(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1], first.columns[2] - second.columns[2], first.columns[3] - second.columns[3]);
	}

	inline Matrix4 operator*(const Matrix4 &first, const Matrix4 &second)
	{
#if defined(MUTIL_USE_INTRINSICS)
#if defined(MUTIL_X86)
		constexpr int MASK0 = 0xf1, MASK1 = 0xf2, MASK2 = 0xf4, MASK3 = 0xf8;

		__m128 rc0 = _mm_loadu_ps((float *)&second.columns[0]);
		__m128 rc1 = _mm_loadu_ps((float *)&second.columns[1]);
		__m128 rc2 = _mm_loadu_ps((float *)&second.columns[2]);
		__m128 rc3 = _mm_loadu_ps((float *)&second.columns[3]);

		__m128 lr0 = _mm_set_ps(first.columns[3].x, first.columns[2].x, first.columns[1].x, first.columns[0].x);
		__m128 lr1 = _mm_set_ps(first.columns[3].y, first.columns[2].y, first.columns[1].y, first.columns[0].y);
		__m128 lr2 = _mm_set_ps(first.columns[3].z, first.columns[2].z, first.columns[1].z, first.columns[0].z);
		__m128 lr3 = _mm_set_ps(first.columns[3].w, first.columns[2].w, first.columns[1].w, first.columns[0].w);

		__m128 resultReg0, resultReg1, resultReg2, resultReg3;
		__m128 tempReg0, tempReg1, tempReg2, tempReg3;

		tempReg0 = _mm_dp_ps(lr0, rc0, MASK0);
		tempReg1 = _mm_dp_ps(lr1, rc0, MASK1);
		tempReg2 = _mm_dp_ps(lr2, rc0, MASK2);
		tempReg3 = _mm_dp_ps(lr3, rc0, MASK3);

		tempReg0 = _mm_or_ps(tempReg0, tempReg1);
		tempReg2 = _mm_or_ps(tempReg2, tempReg3);
		resultReg0 = _mm_or_ps(tempReg0, tempReg2);

		tempReg0 = _mm_dp_ps(lr0, rc1, MASK0);
		tempReg1 = _mm_dp_ps(lr1, rc1, MASK1);
		tempReg2 = _mm_dp_ps(lr2, rc1, MASK2);
		tempReg3 = _mm_dp_ps(lr3, rc1, MASK3);

		tempReg0 = _mm_or_ps(tempReg0, tempReg1);
		tempReg2 = _mm_or_ps(tempReg2, tempReg3);
		resultReg1 = _mm_or_ps(tempReg0, tempReg2);

		tempReg0 = _mm_dp_ps(lr0, rc2, MASK0);
		tempReg1 = _mm_dp_ps(lr1, rc2, MASK1);
		tempReg2 = _mm_dp_ps(lr2, rc2, MASK2);
		tempReg3 = _mm_dp_ps(lr3, rc2, MASK3);

		tempReg0 = _mm_or_ps(tempReg0, tempReg1);
		tempReg2 = _mm_or_ps(tempReg2, tempReg3);
		resultReg2 = _mm_or_ps(tempReg0, tempReg2);

		tempReg0 = _mm_dp_ps(lr0, rc3, MASK0);
		tempReg1 = _mm_dp_ps(lr1, rc3, MASK1);
		tempReg2 = _mm_dp_ps(lr2, rc3, MASK2);
		tempReg3 = _mm_dp_ps(lr3, rc3, MASK3);

		tempReg0 = _mm_or_ps(tempReg0, tempReg1);
		tempReg2 = _mm_or_ps(tempReg2, tempReg3);
		resultReg3 = _mm_or_ps(tempReg0, tempReg2);

		Matrix4 mat;

		_mm_storeu_ps((float *)&mat.columns[0], resultReg0);
		_mm_storeu_ps((float *)&mat.columns[1], resultReg1);
		_mm_storeu_ps((float *)&mat.columns[2], resultReg2);
		_mm_storeu_ps((float *)&mat.columns[3], resultReg3);

		return mat;
#elif defined(MUTIL_ARM)
		return Matrix4(
			Vector4(
				(first.columns[0].x * second.columns[0].x) + (first.columns[1].x * second.columns[0].y) + (first.columns[2].x * second.columns[0].z) + (first.columns[3].x * second.columns[0].w),
				(first.columns[0].y * second.columns[0].x) + (first.columns[1].y * second.columns[0].y) + (first.columns[2].y * second.columns[0].z) + (first.columns[3].y * second.columns[0].w),
				(first.columns[0].z * second.columns[0].x) + (first.columns[1].z * second.columns[0].y) + (first.columns[2].z * second.columns[0].z) + (first.columns[3].z * second.columns[0].w),
				(first.columns[0].w * second.columns[0].x) + (first.columns[1].w * second.columns[0].y) + (first.columns[2].w * second.columns[0].z) + (first.columns[3].w * second.columns[0].w)),
			Vector4(
				(first.columns[0].x * second.columns[1].x) + (first.columns[1].x * second.columns[1].y) + (first.columns[2].x * second.columns[1].z) + (first.columns[3].x * second.columns[1].w),
				(first.columns[0].y * second.columns[1].x) + (first.columns[1].y * second.columns[1].y) + (first.columns[2].y * second.columns[1].z) + (first.columns[3].y * second.columns[1].w),
				(first.columns[0].z * second.columns[1].x) + (first.columns[1].z * second.columns[1].y) + (first.columns[2].z * second.columns[1].z) + (first.columns[3].z * second.columns[1].w),
				(first.columns[0].w * second.columns[1].x) + (first.columns[1].w * second.columns[1].y) + (first.columns[2].w * second.columns[1].z) + (first.columns[3].w * second.columns[1].w)),
			Vector4(
				(first.columns[0].x * second.columns[2].x) + (first.columns[1].x * second.columns[2].y) + (first.columns[2].x * second.columns[2].z) + (first.columns[3].x * second.columns[2].w),
				(first.columns[0].y * second.columns[2].x) + (first.columns[1].y * second.columns[2].y) + (first.columns[2].y * second.columns[2].z) + (first.columns[3].y * second.columns[2].w),
				(first.columns[0].z * second.columns[2].x) + (first.columns[1].z * second.columns[2].y) + (first.columns[2].z * second.columns[2].z) + (first.columns[3].z * second.columns[2].w),
				(first.columns[0].w * second.columns[2].x) + (first.columns[1].w * second.columns[2].y) + (first.columns[2].w * second.columns[2].z) + (first.columns[3].w * second.columns[2].w)),
			Vector4(
				(first.columns[0].x * second.columns[3].x) + (first.columns[1].x * second.columns[3].y) + (first.columns[2].x * second.columns[3].z) + (first.columns[3].x * second.columns[3].w),
				(first.columns[0].y * second.columns[3].x) + (first.columns[1].y * second.columns[3].y) + (first.columns[2].y * second.columns[3].z) + (first.columns[3].y * second.columns[3].w),
				(first.columns[0].z * second.columns[3].x) + (first.columns[1].z * second.columns[3].y) + (first.columns[2].z * second.columns[3].z) + (first.columns[3].z * second.columns[3].w),
				(first.columns[0].w * second.columns[3].x) + (first.columns[1].w * second.columns[3].y) + (first.columns[2].w * second.columns[3].z) + (first.columns[3].w * second.columns[3].w)));
#endif
#else
		return Matrix4(
			Vector4(
				(first.columns[0].x * second.columns[0].x) + (first.columns[1].x * second.columns[0].y) + (first.columns[2].x * second.columns[0].z) + (first.columns[3].x * second.columns[0].w),
				(first.columns[0].y * second.columns[0].x) + (first.columns[1].y * second.columns[0].y) + (first.columns[2].y * second.columns[0].z) + (first.columns[3].y * second.columns[0].w),
				(first.columns[0].z * second.columns[0].x) + (first.columns[1].z * second.columns[0].y) + (first.columns[2].z * second.columns[0].z) + (first.columns[3].z * second.columns[0].w),
				(first.columns[0].w * second.columns[0].x) + (first.columns[1].w * second.columns[0].y) + (first.columns[2].w * second.columns[0].z) + (first.columns[3].w * second.columns[0].w)),
			Vector4(
				(first.columns[0].x * second.columns[1].x) + (first.columns[1].x * second.columns[1].y) + (first.columns[2].x * second.columns[1].z) + (first.columns[3].x * second.columns[1].w),
				(first.columns[0].y * second.columns[1].x) + (first.columns[1].y * second.columns[1].y) + (first.columns[2].y * second.columns[1].z) + (first.columns[3].y * second.columns[1].w),
				(first.columns[0].z * second.columns[1].x) + (first.columns[1].z * second.columns[1].y) + (first.columns[2].z * second.columns[1].z) + (first.columns[3].z * second.columns[1].w),
				(first.columns[0].w * second.columns[1].x) + (first.columns[1].w * second.columns[1].y) + (first.columns[2].w * second.columns[1].z) + (first.columns[3].w * second.columns[1].w)),
			Vector4(
				(first.columns[0].x * second.columns[2].x) + (first.columns[1].x * second.columns[2].y) + (first.columns[2].x * second.columns[2].z) + (first.columns[3].x * second.columns[2].w),
				(first.columns[0].y * second.columns[2].x) + (first.columns[1].y * second.columns[2].y) + (first.columns[2].y * second.columns[2].z) + (first.columns[3].y * second.columns[2].w),
				(first.columns[0].z * second.columns[2].x) + (first.columns[1].z * second.columns[2].y) + (first.columns[2].z * second.columns[2].z) + (first.columns[3].z * second.columns[2].w),
				(first.columns[0].w * second.columns[2].x) + (first.columns[1].w * second.columns[2].y) + (first.columns[2].w * second.columns[2].z) + (first.columns[3].w * second.columns[2].w)),
			Vector4(
				(first.columns[0].x * second.columns[3].x) + (first.columns[1].x * second.columns[3].y) + (first.columns[2].x * second.columns[3].z) + (first.columns[3].x * second.columns[3].w),
				(first.columns[0].y * second.columns[3].x) + (first.columns[1].y * second.columns[3].y) + (first.columns[2].y * second.columns[3].z) + (first.columns[3].y * second.columns[3].w),
				(first.columns[0].z * second.columns[3].x) + (first.columns[1].z * second.columns[3].y) + (first.columns[2].z * second.columns[3].z) + (first.columns[3].z * second.columns[3].w),
				(first.columns[0].w * second.columns[3].x) + (first.columns[1].w * second.columns[3].y) + (first.columns[2].w * second.columns[3].z) + (first.columns[3].w * second.columns[3].w)));
#endif
	}

	constexpr Vector4 operator*(const Matrix4 &first, const Vector4 &second)
	{
		return Vector4(
			first.columns[0].x * second.x + first.columns[1].x * second.y + first.columns[2].x * second.z + first.columns[3].x * second.w,
			first.columns[0].y * second.x + first.columns[1].y * second.y + first.columns[2].y * second.z + first.columns[3].y * second.w,
			first.columns[0].z * second.x + first.columns[1].z * second.y + first.columns[2].z * second.z + first.columns[3].z * second.w,
			first.columns[0].w * second.x + first.columns[1].w * second.y + first.columns[2].w * second.z + first.columns[3].w * second.w);
	}

	constexpr Matrix4 operator*(const Matrix4 &first, float second)
	{
		return Matrix4(
			first.columns[0] * second,
			first.columns[1] * second,
			first.columns[2] * second,
			first.columns[3] * second);
	}

	constexpr Matrix4 operator/(const Matrix4 &first, float second)
	{
		return Matrix4(
			first.columns[0] / second,
			first.columns[1] / second,
			first.columns[2] / second,
			first.columns[3] / second);
	}

	constexpr bool operator==(const Matrix4 &first, const Matrix4 &second)
	{
		return first.columns[0] == second.columns[0] && first.columns[1] == second.columns[1] && first.columns[2] == second.columns[2] && first.columns[3] == second.columns[3];
	}

	/*!
	Class wrapping a 2x2 matrix of 32-bit integers.
	*/
	class IntMatrix2
	{
	public:
		/*!
		The matrix's columns.
		*/
		union
		{
			IntVector2 columns[2];
			struct
			{
				int32_t _11, _21;
				int32_t _12, _22;
			};
			int32_t mat[4];
		};

		/*!
		Constructs the identity matrix.
		*/
		constexpr IntMatrix2() : IntMatrix2(1) {}

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit constexpr IntMatrix2(const int32_t diagonal) : _11(diagonal), _12(0),
																_21(0), _22(diagonal) {}

		/*!
		Constructs a matrix with two explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		*/
		explicit constexpr IntMatrix2(const IntVector2 &column1, const IntVector2 &column2) : _11(column1.x), _12(column2.x),
																							  _21(column1.y), _22(column2.y) {}

		explicit constexpr IntMatrix2(
			int32_t _11, int32_t _12,
			int32_t _21, int32_t _22) : _11(_11), _12(_12),
										_21(_21), _22(_22) {}

		/*!
		Constructs a matrix by casting it from a floating point matrix.

		@param mat2 The matrix to cast from.
		*/
		explicit constexpr IntMatrix2(const Matrix2 &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit constexpr IntMatrix2(const IntMatrix3 &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit constexpr IntMatrix2(const IntMatrix4 &mat);

		constexpr const int32_t &operator[](size_t index) const
		{
			return mat[index];
		}

		constexpr int32_t &operator[](size_t index)
		{
			return mat[index];
		}
	};

	constexpr IntMatrix2 operator+(const IntMatrix2 &first, const IntMatrix2 &second)
	{
		return IntMatrix2(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1]);
	}

	constexpr IntMatrix2 operator-(const IntMatrix2 &first, const IntMatrix2 &second)
	{
		return IntMatrix2(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1]);
	}

	constexpr IntMatrix2 operator*(const IntMatrix2 &first, const IntMatrix2 &second)
	{
		return IntMatrix2(
			first._11 * second._11 + first._12 * second._21, first._11 * second._12 + first._12 * second._22,
			first._21 * second._11 + first._22 * second._21, first._21 * second._21 + first._22 * second._22);
	}

	constexpr IntVector2 operator*(const IntMatrix2 &first, const IntVector2 &second)
	{
		return IntVector2(
			first.columns[0].x * second.x + first.columns[1].x * second.y,
			first.columns[0].y * second.x + first.columns[1].y * second.y);
	}

	constexpr IntMatrix2 operator*(const IntMatrix2 &first, int32_t second)
	{
		return IntMatrix2(
			first.columns[0] * second,
			first.columns[1] * second);
	}

	constexpr IntMatrix2 operator/(const IntMatrix2 &first, int32_t second)
	{
		return IntMatrix2(
			first.columns[0] / second,
			first.columns[1] / second);
	}

	constexpr bool operator==(const IntMatrix2 &first, const IntMatrix2 &second)
	{
		return first.columns[0] == second.columns[0] && first.columns[1] == second.columns[1];
	}

	/*!
	Class wrapping a 3x3 matrix of 32-bit integers.
	*/
	class IntMatrix3
	{
	public:
		/*!
		The matrix's columns.
		*/
		union
		{
			IntVector3 columns[3];
			struct
			{
				int32_t _11, _21, _31;
				int32_t _12, _22, _32;
				int32_t _13, _23, _33;
			};
			int32_t mat[9];
		};

		/*!
		Constructs the identity matrix.
		*/
		constexpr IntMatrix3() : IntMatrix3(1) {}

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit constexpr IntMatrix3(const int32_t diagonal) : _11(diagonal), _12(0), _13(0),
																_21(0), _22(diagonal), _23(0),
																_31(0), _32(0), _33(diagonal) {}

		/*!
		Constructs a matrix with three explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		@param column3 The third column.
		*/
		explicit constexpr IntMatrix3(const IntVector3 &column1, const IntVector3 &column2, const IntVector3 &column3) : _11(column1.x), _12(column2.x), _13(column3.x),
																														 _21(column1.y), _22(column2.y), _23(column3.y),
																														 _31(column1.z), _32(column2.z), _33(column3.z) {}

		explicit constexpr IntMatrix3(
			int32_t _11, int32_t _12, int32_t _13,
			int32_t _21, int32_t _22, int32_t _23,
			int32_t _31, int32_t _32, int32_t _33) : _11(_11), _12(_12), _13(_13),
													 _21(_21), _22(_22), _23(_23),
													 _31(_31), _32(_32), _33(_33) {}

		/*!
		Constructs a matrix by casting it from a floating point matrix.

		@param mat3 The matrix to cast from.
		*/
		explicit constexpr IntMatrix3(const Matrix3 &mat);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit constexpr IntMatrix3(const IntMatrix2 &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit constexpr IntMatrix3(const IntMatrix4 &mat);

		constexpr const int32_t &operator[](size_t index) const
		{
			return mat[index];
		}

		constexpr int32_t &operator[](size_t index)
		{
			return mat[index];
		}
	};

	constexpr IntMatrix3 operator+(const IntMatrix3 &first, const IntMatrix3 &second)
	{
		return IntMatrix3(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1], first.columns[2] + second.columns[2]);
	}

	constexpr IntMatrix3 operator-(const IntMatrix3 &first, const IntMatrix3 &second)
	{
		return IntMatrix3(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1], first.columns[2] - second.columns[2]);
	}

	constexpr IntMatrix3 operator*(const IntMatrix3 &first, const IntMatrix3 &second)
	{
		return IntMatrix3(
			first._11 * second._11 + first._12 * second._21 + first._13 * second._31,
			first._11 * second._12 + first._12 * second._22 + first._13 * second._32,
			first._11 * second._13 + first._12 * second._23 + first._13 * second._33,
			first._21 * second._11 + first._22 * second._21 + first._23 * second._31,
			first._21 * second._12 + first._22 * second._22 + first._23 * second._32,
			first._21 * second._13 + first._22 * second._23 + first._23 * second._33,
			first._31 * second._11 + first._32 * second._21 + first._33 * second._31,
			first._31 * second._12 + first._32 * second._22 + first._33 * second._32,
			first._31 * second._13 + first._32 * second._23 + first._33 * second._33);
	}

	inline IntVector3 operator*(const IntMatrix3 &first, const IntVector3 &second)
	{
		return IntVector3(
			first.columns[0].x * second.x + first.columns[1].x * second.y + first.columns[2].x * second.z,
			first.columns[0].y * second.x + first.columns[1].y * second.y + first.columns[2].y * second.z,
			first.columns[0].z * second.x + first.columns[1].z * second.y + first.columns[2].z * second.z);
	}

	constexpr IntMatrix3 operator*(const IntMatrix3 &first, int32_t second)
	{
		return IntMatrix3(
			first.columns[0] * second,
			first.columns[1] * second,
			first.columns[2] * second);
	}

	constexpr IntMatrix3 operator/(const IntMatrix3 &first, int32_t second)
	{
		return IntMatrix3(
			first.columns[0] / second,
			first.columns[1] / second,
			first.columns[2] / second);
	}

	constexpr bool operator==(const IntMatrix3 &first, const IntMatrix3 &second)
	{
		return first.columns[0] == second.columns[0] && first.columns[1] == second.columns[1] && first.columns[2] == second.columns[2];
	}

	/*!
	Class wrapping a 4x4 matrix of 32-bit integers.
	*/
	class IntMatrix4
	{
	public:
		/*!
		The matrix's columns.
		*/
		union
		{
			IntVector4 columns[4];
			struct
			{
				int32_t _11, _21, _31, _41;
				int32_t _12, _22, _32, _42;
				int32_t _13, _23, _33, _43;
				int32_t _14, _24, _34, _44;
			};
			int32_t mat[16];
		};

		/*!
		Constructs the identity matrix.
		*/
		constexpr IntMatrix4() : IntMatrix4(1) {}

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit constexpr IntMatrix4(const int32_t diagonal) : _11(diagonal), _12(0), _13(0), _14(0),
																_21(0), _22(diagonal), _23(0), _24(0),
																_31(0), _32(0), _33(diagonal), _34(0),
																_41(0), _42(0), _43(0), _44(diagonal) {}

		/*!
		Constructs a matrix with four explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		@param column3 The third column.
		@param column4 The fourth column.
		*/
		explicit constexpr IntMatrix4(const IntVector4 &column1, const IntVector4 &column2, const IntVector4 &column3, const IntVector4 &column4) : _11(column1.x), _12(column2.x), _13(column3.x), _14(column4.x),
																																					_21(column1.y), _22(column2.y), _23(column3.y), _24(column4.y),
																																					_31(column1.z), _32(column2.z), _33(column3.z), _34(column4.z),
																																					_41(column1.w), _42(column2.w), _43(column3.w), _44(column4.w) {}

		explicit constexpr IntMatrix4(
			int32_t _11, int32_t _12, int32_t _13, int32_t _14,
			int32_t _21, int32_t _22, int32_t _23, int32_t _24,
			int32_t _31, int32_t _32, int32_t _33, int32_t _34,
			int32_t _41, int32_t _42, int32_t _43, int32_t _44) : _11(_11), _12(_12), _13(_13), _14(_14),
																  _21(_21), _22(_22), _23(_23), _24(_24),
																  _31(_31), _32(_32), _33(_33), _34(_34),
																  _41(_41), _42(_42), _43(_43), _44(_44) {}

		/*!
		Constructs a matrix by casting it from a floating point matrix.

		@param mat4 The matrix to cast from.
		*/
		explicit constexpr IntMatrix4(const Matrix4 &mat);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit constexpr IntMatrix4(const IntMatrix2 &mat);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit constexpr IntMatrix4(const IntMatrix3 &mat);

		constexpr const int32_t &operator[](size_t index) const
		{
			return mat[index];
		}

		constexpr int32_t &operator[](size_t index)
		{
			return mat[index];
		}
	};

	constexpr IntMatrix4 operator+(const IntMatrix4 &first, const IntMatrix4 &second)
	{
		return IntMatrix4(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1], first.columns[2] + second.columns[2], first.columns[3] + second.columns[3]);
	}

	constexpr IntMatrix4 operator-(const IntMatrix4 &first, const IntMatrix4 &second)
	{
		return IntMatrix4(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1], first.columns[2] - second.columns[2], first.columns[3] - second.columns[3]);
	}

	constexpr IntMatrix4 operator*(const IntMatrix4 &first, const IntMatrix4 &second)
	{
		return IntMatrix4(
			IntVector4(
				(first.columns[0].x * second.columns[0].x) + (first.columns[1].x * second.columns[0].y) + (first.columns[2].x * second.columns[0].z) + (first.columns[3].x * second.columns[0].w),
				(first.columns[0].y * second.columns[0].x) + (first.columns[1].y * second.columns[0].y) + (first.columns[2].y * second.columns[0].z) + (first.columns[3].y * second.columns[0].w),
				(first.columns[0].z * second.columns[0].x) + (first.columns[1].z * second.columns[0].y) + (first.columns[2].z * second.columns[0].z) + (first.columns[3].z * second.columns[0].w),
				(first.columns[0].w * second.columns[0].x) + (first.columns[1].w * second.columns[0].y) + (first.columns[2].w * second.columns[0].z) + (first.columns[3].w * second.columns[0].w)),
			IntVector4(
				(first.columns[0].x * second.columns[1].x) + (first.columns[1].x * second.columns[1].y) + (first.columns[2].x * second.columns[1].z) + (first.columns[3].x * second.columns[1].w),
				(first.columns[0].y * second.columns[1].x) + (first.columns[1].y * second.columns[1].y) + (first.columns[2].y * second.columns[1].z) + (first.columns[3].y * second.columns[1].w),
				(first.columns[0].z * second.columns[1].x) + (first.columns[1].z * second.columns[1].y) + (first.columns[2].z * second.columns[1].z) + (first.columns[3].z * second.columns[1].w),
				(first.columns[0].w * second.columns[1].x) + (first.columns[1].w * second.columns[1].y) + (first.columns[2].w * second.columns[1].z) + (first.columns[3].w * second.columns[1].w)),
			IntVector4(
				(first.columns[0].x * second.columns[2].x) + (first.columns[1].x * second.columns[2].y) + (first.columns[2].x * second.columns[2].z) + (first.columns[3].x * second.columns[2].w),
				(first.columns[0].y * second.columns[2].x) + (first.columns[1].y * second.columns[2].y) + (first.columns[2].y * second.columns[2].z) + (first.columns[3].y * second.columns[2].w),
				(first.columns[0].z * second.columns[2].x) + (first.columns[1].z * second.columns[2].y) + (first.columns[2].z * second.columns[2].z) + (first.columns[3].z * second.columns[2].w),
				(first.columns[0].w * second.columns[2].x) + (first.columns[1].w * second.columns[2].y) + (first.columns[2].w * second.columns[2].z) + (first.columns[3].w * second.columns[2].w)),
			IntVector4(
				(first.columns[0].x * second.columns[3].x) + (first.columns[1].x * second.columns[3].y) + (first.columns[2].x * second.columns[3].z) + (first.columns[3].x * second.columns[3].w),
				(first.columns[0].y * second.columns[3].x) + (first.columns[1].y * second.columns[3].y) + (first.columns[2].y * second.columns[3].z) + (first.columns[3].y * second.columns[3].w),
				(first.columns[0].z * second.columns[3].x) + (first.columns[1].z * second.columns[3].y) + (first.columns[2].z * second.columns[3].z) + (first.columns[3].z * second.columns[3].w),
				(first.columns[0].w * second.columns[3].x) + (first.columns[1].w * second.columns[3].y) + (first.columns[2].w * second.columns[3].z) + (first.columns[3].w * second.columns[3].w)));
	}

	constexpr IntVector4 operator*(const IntMatrix4 &first, const IntVector4 &second)
	{
		return IntVector4(
			first.columns[0].x * second.x + first.columns[1].x * second.y + first.columns[2].x * second.z + first.columns[3].x * second.w,
			first.columns[0].y * second.x + first.columns[1].y * second.y + first.columns[2].y * second.z + first.columns[3].y * second.w,
			first.columns[0].z * second.x + first.columns[1].z * second.y + first.columns[2].z * second.z + first.columns[3].z * second.w,
			first.columns[0].w * second.x + first.columns[1].w * second.y + first.columns[2].w * second.z + first.columns[3].w * second.w);
	}

	constexpr IntMatrix4 operator*(const IntMatrix4 &first, int32_t second)
	{
		return IntMatrix4(
			first.columns[0] * second,
			first.columns[1] * second,
			first.columns[2] * second,
			first.columns[3] * second);
	}

	constexpr IntMatrix4 operator/(const IntMatrix4 &first, int32_t second)
	{
		return IntMatrix4(
			first.columns[0] / second,
			first.columns[1] / second,
			first.columns[2] / second,
			first.columns[3] / second);
	}

	constexpr bool operator==(const IntMatrix4 &first, const IntMatrix4 &second)
	{
		return first.columns[0] == second.columns[0] && first.columns[1] == second.columns[1] && first.columns[2] == second.columns[2] && first.columns[3] == second.columns[3];
	}

	constexpr Matrix2::Matrix2(const IntMatrix2 &mat) : _11((float)mat._11), _12((float)mat._12),
														_21((float)mat._21), _22((float)mat._22) {}

	constexpr Matrix2::Matrix2(const Matrix3 &mat) : _11(mat._11), _12(mat._12),
													 _21(mat._21), _22(mat._22) {}

	constexpr Matrix2::Matrix2(const Matrix4 &mat) : _11(mat._11), _12(mat._12),
													 _21(mat._21), _22(mat._22) {}

	constexpr Matrix3::Matrix3(const IntMatrix3 &mat) : _11((float)mat._11), _12((float)mat._12), _13((float)mat._13),
														_21((float)mat._21), _22((float)mat._22), _23((float)mat._23),
														_31((float)mat._31), _32((float)mat._32), _33((float)mat._33) {}

	constexpr Matrix3::Matrix3(const Matrix2 &mat) : _11(mat._11), _12(mat._12), _13(0.0f),
													 _21(mat._21), _22(mat._22), _23(0.0f),
													 _31(0.0f), _32(0.0f), _33(1.0f) {}

	constexpr Matrix3::Matrix3(const Matrix4 &mat) : _11(mat._11), _12(mat._12), _13(mat._13),
													 _21(mat._21), _22(mat._22), _23(mat._23),
													 _31(mat._31), _32(mat._32), _33(mat._33) {}

	constexpr Matrix4::Matrix4(const IntMatrix4 &mat) : _11((float)mat._11), _12((float)mat._12), _13((float)mat._13), _14((float)mat._14),
														_21((float)mat._21), _22((float)mat._22), _23((float)mat._23), _24((float)mat._24),
														_31((float)mat._31), _32((float)mat._32), _33((float)mat._33), _34((float)mat._34),
														_41((float)mat._41), _42((float)mat._42), _43((float)mat._43), _44((float)mat._44) {}

	constexpr Matrix4::Matrix4(const Matrix2 &mat) : _11(mat._11), _12(mat._12), _13(0.0f), _14(0.0f),
													 _21(mat._21), _22(mat._22), _23(0.0f), _24(0.0f),
													 _31(0.0f), _32(0.0f), _33(1.0f), _34(0.0f),
													 _41(0.0f), _42(0.0f), _43(0.0f), _44(1.0f) {}

	constexpr Matrix4::Matrix4(const Matrix3 &mat) : _11(mat._11), _12(mat._12), _13(mat._13), _14(0.0f),
													 _21(mat._21), _22(mat._22), _23(mat._23), _24(0.0f),
													 _31(mat._31), _32(mat._32), _33(mat._33), _34(0.0f),
													 _41(0.0f), _42(0.0f), _43(0.0f), _44(1.0f) {}

	constexpr IntMatrix2::IntMatrix2(const Matrix2 &mat) : _11((int32_t)mat._11), _12((int32_t)mat._12),
														   _21((int32_t)mat._21), _22((int32_t)mat._22) {}

	constexpr IntMatrix2::IntMatrix2(const IntMatrix3 &mat) : _11(mat._11), _12(mat._12),
															  _21(mat._21), _22(mat._22) {}

	constexpr IntMatrix2::IntMatrix2(const IntMatrix4 &mat) : _11(mat._11), _12(mat._12),
															  _21(mat._21), _22(mat._22) {}

	constexpr IntMatrix3::IntMatrix3(const Matrix3 &mat) : _11((int32_t)mat._11), _12((int32_t)mat._12), _13((int32_t)mat._13),
														   _21((int32_t)mat._21), _22((int32_t)mat._22), _23((int32_t)mat._23),
														   _31((int32_t)mat._31), _32((int32_t)mat._32), _33((int32_t)mat._33) {}

	constexpr IntMatrix3::IntMatrix3(const IntMatrix2 &mat) : _11(mat._11), _12(mat._12), _13(0),
															  _21(mat._21), _22(mat._22), _23(0),
															  _31(0), _32(0), _33(1) {}

	constexpr IntMatrix3::IntMatrix3(const IntMatrix4 &mat) : _11(mat._11), _12(mat._12), _13(mat._13),
															  _21(mat._21), _22(mat._22), _23(mat._23),
															  _31(mat._31), _32(mat._32), _33(mat._33) {}

	constexpr IntMatrix4::IntMatrix4(const Matrix4 &mat) : _11((int32_t)mat._11), _12((int32_t)mat._12), _13((int32_t)mat._13), _14((int32_t)mat._14),
														   _21((int32_t)mat._21), _22((int32_t)mat._22), _23((int32_t)mat._23), _24((int32_t)mat._24),
														   _31((int32_t)mat._31), _32((int32_t)mat._32), _33((int32_t)mat._33), _34((int32_t)mat._34),
														   _41((int32_t)mat._41), _42((int32_t)mat._42), _43((int32_t)mat._43), _44((int32_t)mat._44) {}

	constexpr IntMatrix4::IntMatrix4(const IntMatrix2 &mat) : _11(mat._11), _12(mat._12), _13(0), _14(0),
															  _21(mat._21), _22(mat._22), _23(0), _24(0),
															  _31(0), _32(0), _33(1), _34(0),
															  _41(0), _42(0), _43(0), _44(1) {}

	constexpr IntMatrix4::IntMatrix4(const IntMatrix3 &mat) : _11(mat._11), _12(mat._12), _13(mat._13), _14(0),
															  _21(mat._21), _22(mat._22), _23(mat._23), _24(0),
															  _31(mat._31), _32(mat._32), _33(mat._33), _34(0),
															  _41(0), _42(0), _43(0), _44(1) {}
}

#endif