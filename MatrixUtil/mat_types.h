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
#if defined(USE_SIMD)
#include <smmintrin.h>
#endif

namespace mutil
{
	typedef class Matrix2 Matrix2;
	typedef class Matrix3 Matrix3;
	typedef class Matrix4 Matrix4;

	typedef class IntMatrix2 IntMatrix2;
	typedef class IntMatrix3 IntMatrix3;
	typedef class IntMatrix4 IntMatrix4;

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
				float _11, _12;
				float _21, _22;
			};
			float mat[4];
		};

		/*!
		Constructs the identity matrix.
		*/
		MUTIL_INLINE Matrix2() : Matrix2(1.0f) { }

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit MUTIL_INLINE Matrix2(const float diagonal)
		{
			columns[0] = Vector2(diagonal, 0.0f);
			columns[1] = Vector2(0.0f, diagonal);
		}

		/*!
		Constructs a matrix with two explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		*/
		explicit MUTIL_INLINE Matrix2(const Vector2 &column1, const Vector2 &column2)
		{
			memcpy(&columns[0], &column1, sizeof(Vector2));
			memcpy(&columns[1], &column2, sizeof(Vector2));
		}

		/*!
		Constructs a matrix by casting it from a 32-bit integer matrix.

		@param mat2 The matrix to cast from.
		*/
		explicit MUTIL_INLINE Matrix2(const IntMatrix2 &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit MUTIL_INLINE Matrix2(const Matrix3 &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit MUTIL_INLINE Matrix2(const Matrix4 &mat);

		MUTIL_INLINE const float &operator [](size_t index) const
		{
			return mat[index];
		}

		MUTIL_INLINE float &operator [](size_t index)
		{
			return mat[index];
		}
	};

	MUTIL_INLINE Matrix2 operator +(const Matrix2 &first, const Matrix2 &second)
	{
		return Matrix2(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1]);
	}

	MUTIL_INLINE Matrix2 operator -(const Matrix2 &first, const Matrix2 &second)
	{
		return Matrix2(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1]);
	}

	MUTIL_INLINE Matrix2 operator *(const Matrix2 &first, const Matrix2 &second)
	{
		return Matrix2(
			Vector2(
				(first.columns[0].x * second.columns[0].x) + (first.columns[1].x * second.columns[0].y),
				(first.columns[0].y * second.columns[0].x) + (first.columns[1].y * second.columns[0].y)
			),
			Vector2(
				(first.columns[0].x * second.columns[1].x) + (first.columns[1].x * second.columns[1].y),
				(first.columns[0].y * second.columns[1].x) + (first.columns[1].y * second.columns[1].y)
			)
		);
	}

	MUTIL_INLINE Vector2 operator *(const Matrix2 &first, const Vector2 &second)
	{
		return Vector2(
			first.columns[0].x * second.x + first.columns[1].x * second.y,
			first.columns[0].y * second.x + first.columns[1].y * second.y
		);
	}

	MUTIL_INLINE bool operator ==(const Matrix2 &first, const Matrix2 &second)
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
				float _11, _12, _13;
				float _21, _22, _23;
				float _31, _32, _33;
			};
			float mat[9];
		};

		/*!
		Constructs the identity matrix.
		*/
		MUTIL_INLINE Matrix3() : Matrix3(1.0f) { }

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit MUTIL_INLINE Matrix3(const float diagonal)
		{
			columns[0] = Vector3(diagonal, 0.0f, 0.0f);
			columns[1] = Vector3(0.0f, diagonal, 0.0f);
			columns[2] = Vector3(0.0f, 0.0f, diagonal);
		}

		/*!
		Constructs a matrix with three explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		@param column3 The third column.
		*/
		explicit MUTIL_INLINE Matrix3(const Vector3 &column1, const Vector3 &column2, const Vector3 &column3)
		{
			columns[0] = Vector3(column1);
			columns[1] = Vector3(column2);
			columns[2] = Vector3(column3);
		}

		/*!
		Constructs a matrix by casting it from a 32-bit integer matrix.

		@param mat3 The matrix to cast from.
		*/
		explicit MUTIL_INLINE Matrix3(const IntMatrix3 &mat);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit MUTIL_INLINE Matrix3(const Matrix2 &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit MUTIL_INLINE Matrix3(const Matrix4 &mat);

		MUTIL_INLINE const float &operator [](size_t index) const
		{
			return mat[index];
		}

		MUTIL_INLINE float &operator [](size_t index)
		{
			return mat[index];
		}
	};

	MUTIL_INLINE Matrix3 operator +(const Matrix3 &first, const Matrix3 &second)
	{
		return Matrix3(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1], first.columns[2] + second.columns[2]);
	}

	MUTIL_INLINE Matrix3 operator -(const Matrix3 &first, const Matrix3 &second)
	{
		return Matrix3(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1], first.columns[2] - second.columns[2]);
	}

	MUTIL_INLINE Matrix3 operator *(const Matrix3 &first, const Matrix3 &second)
	{
		return Matrix3(
			Vector3(
				(first.columns[0].x * second.columns[0].x) + (first.columns[1].x * second.columns[0].y) + (first.columns[2].x * second.columns[0].z),
				(first.columns[0].y * second.columns[0].x) + (first.columns[1].y * second.columns[0].y) + (first.columns[2].y * second.columns[0].z),
				(first.columns[0].z * second.columns[0].x) + (first.columns[1].z * second.columns[0].y) + (first.columns[2].z * second.columns[0].z)
			),
			Vector3(
				(first.columns[0].x * second.columns[1].x) + (first.columns[1].x * second.columns[1].y) + (first.columns[2].x * second.columns[1].z),
				(first.columns[0].y * second.columns[1].x) + (first.columns[1].y * second.columns[1].y) + (first.columns[2].y * second.columns[1].z),
				(first.columns[0].z * second.columns[1].x) + (first.columns[1].z * second.columns[1].y) + (first.columns[2].z * second.columns[1].z)
			),
			Vector3(
				(first.columns[0].x * second.columns[2].x) + (first.columns[1].x * second.columns[2].y) + (first.columns[2].x * second.columns[2].z),
				(first.columns[0].y * second.columns[2].x) + (first.columns[1].y * second.columns[2].y) + (first.columns[2].y * second.columns[2].z),
				(first.columns[0].z * second.columns[2].x) + (first.columns[1].z * second.columns[2].y) + (first.columns[2].z * second.columns[2].z)
			)
		);
	}

	MUTIL_INLINE Vector3 operator *(const Matrix3 &first, const Vector3 &second)
	{
		return Vector3(
			first.columns[0].x * second.x + first.columns[1].x * second.y + first.columns[2].x * second.z,
			first.columns[0].y * second.x + first.columns[1].y * second.y + first.columns[2].y * second.z,
			first.columns[0].z * second.x + first.columns[1].z * second.y + first.columns[2].z * second.z
		);
	}

	MUTIL_INLINE bool operator ==(const Matrix3 &first, const Matrix3 &second)
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
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;
			};
			float mat[4];
		};

		/*!
		Constructs the identity matrix.
		*/
		MUTIL_INLINE Matrix4() : Matrix4(1.0f) { }

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit MUTIL_INLINE Matrix4(const float diagonal)
		{
			columns[0] = Vector4(diagonal, 0.0f, 0.0f, 0.0f);
			columns[1] = Vector4(0.0f, diagonal, 0.0f, 0.0f);
			columns[2] = Vector4(0.0f, 0.0f, diagonal, 0.0f);
			columns[3] = Vector4(0.0f, 0.0f, 0.0f, diagonal);
		}

		/*!
		Constructs a matrix with four explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		@param column3 The third column.
		@param column4 The fourth column.
		*/
		explicit MUTIL_INLINE Matrix4(const Vector4 &column1, const Vector4 &column2, const Vector4 &column3, const Vector4 &column4)
		{
			columns[0] = Vector4(column1);
			columns[1] = Vector4(column2);
			columns[2] = Vector4(column3);
			columns[3] = Vector4(column4);
		}

		/*!
		Constructs a matrix by casting it from a 32-bit integer matrix.

		@param mat4 The matrix to cast from.
		*/
		explicit MUTIL_INLINE Matrix4(const IntMatrix4 &mat);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit MUTIL_INLINE Matrix4(const Matrix2 &mat);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit MUTIL_INLINE Matrix4(const Matrix3 &mat);

		MUTIL_INLINE const float &operator [](size_t index) const
		{
			return mat[index];
		}

		MUTIL_INLINE float &operator [](size_t index)
		{
			return mat[index];
		}
	};

	MUTIL_INLINE Matrix4 operator +(const Matrix4 &first, const Matrix4 &second)
	{
		return Matrix4(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1], first.columns[2] + second.columns[2], first.columns[3] + second.columns[3]);
	}

	MUTIL_INLINE Matrix4 operator -(const Matrix4 &first, const Matrix4 &second)
	{
		return Matrix4(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1], first.columns[2] - second.columns[2], first.columns[3] - second.columns[3]);
	}

	MUTIL_INLINE Matrix4 operator *(const Matrix4 &first, const Matrix4 &second)
	{
#if defined(USE_SIMD)
		static const int MASK0 = 0xf1, MASK1 = 0xf2, MASK2 = 0xf4, MASK3 = 0xf8;

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
#else
		return Matrix4(
			Vector4(
				(first.columns[0].x * second.columns[0].x) + (first.columns[1].x * second.columns[0].y) + (first.columns[2].x * second.columns[0].z) + (first.columns[3].x * second.columns[0].w),
				(first.columns[0].y * second.columns[0].x) + (first.columns[1].y * second.columns[0].y) + (first.columns[2].y * second.columns[0].z) + (first.columns[3].y * second.columns[0].w),
				(first.columns[0].z * second.columns[0].x) + (first.columns[1].z * second.columns[0].y) + (first.columns[2].z * second.columns[0].z) + (first.columns[3].z * second.columns[0].w),
				(first.columns[0].w * second.columns[0].x) + (first.columns[1].w * second.columns[0].y) + (first.columns[2].w * second.columns[0].z) + (first.columns[3].w * second.columns[0].w)
			),
			Vector4(
				(first.columns[0].x * second.columns[1].x) + (first.columns[1].x * second.columns[1].y) + (first.columns[2].x * second.columns[1].z) + (first.columns[3].x * second.columns[1].w),
				(first.columns[0].y * second.columns[1].x) + (first.columns[1].y * second.columns[1].y) + (first.columns[2].y * second.columns[1].z) + (first.columns[3].y * second.columns[1].w),
				(first.columns[0].z * second.columns[1].x) + (first.columns[1].z * second.columns[1].y) + (first.columns[2].z * second.columns[1].z) + (first.columns[3].z * second.columns[1].w),
				(first.columns[0].w * second.columns[1].x) + (first.columns[1].w * second.columns[1].y) + (first.columns[2].w * second.columns[1].z) + (first.columns[3].w * second.columns[1].w)
			),
			Vector4(
				(first.columns[0].x * second.columns[2].x) + (first.columns[1].x * second.columns[2].y) + (first.columns[2].x * second.columns[2].z) + (first.columns[3].x * second.columns[2].w),
				(first.columns[0].y * second.columns[2].x) + (first.columns[1].y * second.columns[2].y) + (first.columns[2].y * second.columns[2].z) + (first.columns[3].y * second.columns[2].w),
				(first.columns[0].z * second.columns[2].x) + (first.columns[1].z * second.columns[2].y) + (first.columns[2].z * second.columns[2].z) + (first.columns[3].z * second.columns[2].w),
				(first.columns[0].w * second.columns[2].x) + (first.columns[1].w * second.columns[2].y) + (first.columns[2].w * second.columns[2].z) + (first.columns[3].w * second.columns[2].w)
			),
			Vector4(
				(first.columns[0].x * second.columns[3].x) + (first.columns[1].x * second.columns[3].y) + (first.columns[2].x * second.columns[3].z) + (first.columns[3].x * second.columns[3].w),
				(first.columns[0].y * second.columns[3].x) + (first.columns[1].y * second.columns[3].y) + (first.columns[2].y * second.columns[3].z) + (first.columns[3].y * second.columns[3].w),
				(first.columns[0].z * second.columns[3].x) + (first.columns[1].z * second.columns[3].y) + (first.columns[2].z * second.columns[3].z) + (first.columns[3].z * second.columns[3].w),
				(first.columns[0].w * second.columns[3].x) + (first.columns[1].w * second.columns[3].y) + (first.columns[2].w * second.columns[3].z) + (first.columns[3].w * second.columns[3].w)
			)
		);
#endif
	}

	MUTIL_INLINE Vector4 operator *(const Matrix4 &first, const Vector4 &second)
	{
		return Vector4(
			first.columns[0].x * second.x + first.columns[1].x * second.y + first.columns[2].x * second.z + first.columns[3].x * second.w,
			first.columns[0].y * second.x + first.columns[1].y * second.y + first.columns[2].y * second.z + first.columns[3].y * second.w,
			first.columns[0].z * second.x + first.columns[1].z * second.y + first.columns[2].z * second.z + first.columns[3].z * second.w,
			first.columns[0].w * second.x + first.columns[1].w * second.y + first.columns[2].w * second.z + first.columns[3].w * second.w
		);
	}

	MUTIL_INLINE bool operator ==(const Matrix4 &first, const Matrix4 &second)
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
				int32_t _11, _12;
				int32_t _21, _22;
			};
			int32_t mat[2];
		};

		/*!
		Constructs the identity matrix.
		*/
		MUTIL_INLINE IntMatrix2() : IntMatrix2(1) { }

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit MUTIL_INLINE IntMatrix2(const int32_t diagonal)
		{
			columns[0] = IntVector2(diagonal, 0);
			columns[1] = IntVector2(0, diagonal);
		}

		/*!
		Constructs a matrix with two explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		*/
		explicit MUTIL_INLINE IntMatrix2(const IntVector2 &column1, const IntVector2 &column2)
		{
			columns[0] = column1;
			columns[1] = column2;
		}

		/*!
		Constructs a matrix by casting it from a floating point matrix.

		@param mat2 The matrix to cast from.
		*/
		explicit MUTIL_INLINE IntMatrix2(const Matrix2 &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit MUTIL_INLINE IntMatrix2(const IntMatrix3 &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit MUTIL_INLINE IntMatrix2(const IntMatrix4 &mat);

		MUTIL_INLINE const int32_t &operator [](size_t index) const
		{
			return mat[index];
		}

		MUTIL_INLINE int32_t &operator [](size_t index)
		{
			return mat[index];
		}
	};

	MUTIL_INLINE IntMatrix2 operator +(const IntMatrix2 &first, const IntMatrix2 &second)
	{
		return IntMatrix2(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1]);
	}

	MUTIL_INLINE IntMatrix2 operator -(const IntMatrix2 &first, const IntMatrix2 &second)
	{
		return IntMatrix2(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1]);
	}

	MUTIL_INLINE IntMatrix2 operator *(const IntMatrix2 &first, const IntMatrix2 &second)
	{
		return IntMatrix2(
			IntVector2(
				(first.columns[0].x * second.columns[0].x) + (first.columns[1].x * second.columns[0].y),
				(first.columns[0].y * second.columns[0].x) + (first.columns[1].y * second.columns[0].y)
			),
			IntVector2(
				(first.columns[0].x * second.columns[1].x) + (first.columns[1].x * second.columns[1].y),
				(first.columns[0].y * second.columns[1].x) + (first.columns[1].y * second.columns[1].y)
			)
		);
	}

	MUTIL_INLINE IntVector2 operator *(const IntMatrix2 &first, const IntVector2 &second)
	{
		return IntVector2(
			first.columns[0].x * second.x + first.columns[1].x * second.y,
			first.columns[0].y * second.x + first.columns[1].y * second.y
		);
	}

	MUTIL_INLINE bool operator ==(const IntMatrix2 &first, const IntMatrix2 &second)
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
				int32_t _11, _12, _13;
				int32_t _21, _22, _23;
				int32_t _31, _32, _33;
			};
			int32_t mat[9];
		};

		/*!
		Constructs the identity matrix.
		*/
		MUTIL_INLINE IntMatrix3() : IntMatrix3(1) { }

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit MUTIL_INLINE IntMatrix3(const int32_t diagonal)
		{
			columns[0] = IntVector3(diagonal, 0, 0);
			columns[1] = IntVector3(0, diagonal, 0);
			columns[2] = IntVector3(0, 0, diagonal);
		}

		/*!
		Constructs a matrix with three explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		@param column3 The third column.
		*/
		explicit MUTIL_INLINE IntMatrix3(const IntVector3 &column1, const IntVector3 &column2, const IntVector3 &column3)
		{
			columns[0] = column1;
			columns[1] = column2;
			columns[2] = column3;
		}

		/*!
		Constructs a matrix by casting it from a floating point matrix.

		@param mat3 The matrix to cast from.
		*/
		explicit MUTIL_INLINE IntMatrix3(const Matrix3 &mat);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit MUTIL_INLINE IntMatrix3(const IntMatrix2 &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit MUTIL_INLINE IntMatrix3(const IntMatrix4 &mat);

		MUTIL_INLINE const int32_t &operator [](size_t index) const
		{
			return mat[index];
		}

		MUTIL_INLINE int32_t &operator [](size_t index)
		{
			return mat[index];
		}
	};

	MUTIL_INLINE IntMatrix3 operator +(const IntMatrix3 &first, const IntMatrix3 &second)
	{
		return IntMatrix3(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1], first.columns[2] + second.columns[2]);
	}

	MUTIL_INLINE IntMatrix3 operator -(const IntMatrix3 &first, const IntMatrix3 &second)
	{
		return IntMatrix3(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1], first.columns[2] - second.columns[2]);
	}

	MUTIL_INLINE IntMatrix3 operator *(const IntMatrix3 &first, const IntMatrix3 &second)
	{
		return IntMatrix3(
			IntVector3(
				(first.columns[0].x * second.columns[0].x) + (first.columns[1].x * second.columns[0].y) + (first.columns[2].x * second.columns[0].z),
				(first.columns[0].y * second.columns[0].x) + (first.columns[1].y * second.columns[0].y) + (first.columns[2].y * second.columns[0].z),
				(first.columns[0].z * second.columns[0].x) + (first.columns[1].z * second.columns[0].y) + (first.columns[2].z * second.columns[0].z)
			),
			IntVector3(
				(first.columns[0].x * second.columns[1].x) + (first.columns[1].x * second.columns[1].y) + (first.columns[2].x * second.columns[1].z),
				(first.columns[0].y * second.columns[1].x) + (first.columns[1].y * second.columns[1].y) + (first.columns[2].y * second.columns[1].z),
				(first.columns[0].z * second.columns[1].x) + (first.columns[1].z * second.columns[1].y) + (first.columns[2].z * second.columns[1].z)
			),
			IntVector3(
				(first.columns[0].x * second.columns[2].x) + (first.columns[1].x * second.columns[2].y) + (first.columns[2].x * second.columns[2].z),
				(first.columns[0].y * second.columns[2].x) + (first.columns[1].y * second.columns[2].y) + (first.columns[2].y * second.columns[2].z),
				(first.columns[0].z * second.columns[2].x) + (first.columns[1].z * second.columns[2].y) + (first.columns[2].z * second.columns[2].z)
			)
		);
	}

	MUTIL_INLINE IntVector3 operator *(const IntMatrix3 &first, const IntVector3 &second)
	{
		return IntVector3(
			first.columns[0].x * second.x + first.columns[1].x * second.y + first.columns[2].x * second.z,
			first.columns[0].y * second.x + first.columns[1].y * second.y + first.columns[2].y * second.z,
			first.columns[0].z * second.x + first.columns[1].z * second.y + first.columns[2].z * second.z
		);
	}

	MUTIL_INLINE bool operator ==(const IntMatrix3 &first, const IntMatrix3 &second)
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
				int32_t _11, _12, _13, _14;
				int32_t _21, _22, _23, _24;
				int32_t _31, _32, _33, _34;
				int32_t _41, _42, _43, _44;
			};
			int32_t mat[16];
		};

		/*!
		Constructs the identity matrix.
		*/
		MUTIL_INLINE IntMatrix4() : IntMatrix4(1) { }

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit MUTIL_INLINE IntMatrix4(const int32_t diagonal)
		{
			columns[0] = IntVector4(diagonal, 0, 0, 0);
			columns[1] = IntVector4(0, diagonal, 0, 0);
			columns[2] = IntVector4(0, 0, diagonal, 0);
			columns[3] = IntVector4(0, 0, 0, diagonal);
		}

		/*!
		Constructs a matrix with four explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		@param column3 The third column.
		@param column4 The fourth column.
		*/
		explicit MUTIL_INLINE IntMatrix4(const IntVector4 &column1, const IntVector4 &column2, const IntVector4 &column3, const IntVector4 &column4)
		{
			columns[0] = column1;
			columns[1] = column2;
			columns[2] = column3;
			columns[3] = column4;
		}

		/*!
		Constructs a matrix by casting it from a floating point matrix.

		@param mat4 The matrix to cast from.
		*/
		explicit MUTIL_INLINE IntMatrix4(const Matrix4 &mat);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit MUTIL_INLINE IntMatrix4(const IntMatrix2 &mat);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit MUTIL_INLINE IntMatrix4(const IntMatrix3 &mat);

		MUTIL_INLINE const int32_t &operator [](size_t index) const
		{
			return mat[index];
		}

		MUTIL_INLINE int32_t &operator [](size_t index)
		{
			return mat[index];
		}
	};

	MUTIL_INLINE IntMatrix4 operator +(const IntMatrix4 &first, const IntMatrix4 &second)
	{
		return IntMatrix4(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1], first.columns[2] + second.columns[2], first.columns[3] + second.columns[3]);
	}

	MUTIL_INLINE IntMatrix4 operator -(const IntMatrix4 &first, const IntMatrix4 &second)
	{
		return IntMatrix4(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1], first.columns[2] - second.columns[2], first.columns[3] - second.columns[3]);
	}

	MUTIL_INLINE IntMatrix4 operator *(const IntMatrix4 &first, const IntMatrix4 &second)
	{
		return IntMatrix4(
			IntVector4(
				(first.columns[0].x * second.columns[0].x) + (first.columns[1].x * second.columns[0].y) + (first.columns[2].x * second.columns[0].z) + (first.columns[3].x * second.columns[0].w),
				(first.columns[0].y * second.columns[0].x) + (first.columns[1].y * second.columns[0].y) + (first.columns[2].y * second.columns[0].z) + (first.columns[3].y * second.columns[0].w),
				(first.columns[0].z * second.columns[0].x) + (first.columns[1].z * second.columns[0].y) + (first.columns[2].z * second.columns[0].z) + (first.columns[3].z * second.columns[0].w),
				(first.columns[0].w * second.columns[0].x) + (first.columns[1].w * second.columns[0].y) + (first.columns[2].w * second.columns[0].z) + (first.columns[3].w * second.columns[0].w)
			),
			IntVector4(
				(first.columns[0].x * second.columns[1].x) + (first.columns[1].x * second.columns[1].y) + (first.columns[2].x * second.columns[1].z) + (first.columns[3].x * second.columns[1].w),
				(first.columns[0].y * second.columns[1].x) + (first.columns[1].y * second.columns[1].y) + (first.columns[2].y * second.columns[1].z) + (first.columns[3].y * second.columns[1].w),
				(first.columns[0].z * second.columns[1].x) + (first.columns[1].z * second.columns[1].y) + (first.columns[2].z * second.columns[1].z) + (first.columns[3].z * second.columns[1].w),
				(first.columns[0].w * second.columns[1].x) + (first.columns[1].w * second.columns[1].y) + (first.columns[2].w * second.columns[1].z) + (first.columns[3].w * second.columns[1].w)
			),
			IntVector4(
				(first.columns[0].x * second.columns[2].x) + (first.columns[1].x * second.columns[2].y) + (first.columns[2].x * second.columns[2].z) + (first.columns[3].x * second.columns[2].w),
				(first.columns[0].y * second.columns[2].x) + (first.columns[1].y * second.columns[2].y) + (first.columns[2].y * second.columns[2].z) + (first.columns[3].y * second.columns[2].w),
				(first.columns[0].z * second.columns[2].x) + (first.columns[1].z * second.columns[2].y) + (first.columns[2].z * second.columns[2].z) + (first.columns[3].z * second.columns[2].w),
				(first.columns[0].w * second.columns[2].x) + (first.columns[1].w * second.columns[2].y) + (first.columns[2].w * second.columns[2].z) + (first.columns[3].w * second.columns[2].w)
			),
			IntVector4(
				(first.columns[0].x * second.columns[3].x) + (first.columns[1].x * second.columns[3].y) + (first.columns[2].x * second.columns[3].z) + (first.columns[3].x * second.columns[3].w),
				(first.columns[0].y * second.columns[3].x) + (first.columns[1].y * second.columns[3].y) + (first.columns[2].y * second.columns[3].z) + (first.columns[3].y * second.columns[3].w),
				(first.columns[0].z * second.columns[3].x) + (first.columns[1].z * second.columns[3].y) + (first.columns[2].z * second.columns[3].z) + (first.columns[3].z * second.columns[3].w),
				(first.columns[0].w * second.columns[3].x) + (first.columns[1].w * second.columns[3].y) + (first.columns[2].w * second.columns[3].z) + (first.columns[3].w * second.columns[3].w)
			)
		);
	}

	MUTIL_INLINE IntVector4 operator *(const IntMatrix4 &first, const  IntVector4 &second)
	{
		return IntVector4(
			first.columns[0].x * second.x + first.columns[1].x * second.y + first.columns[2].x * second.z + first.columns[3].x * second.w,
			first.columns[0].y * second.x + first.columns[1].y * second.y + first.columns[2].y * second.z + first.columns[3].y * second.w,
			first.columns[0].z * second.x + first.columns[1].z * second.y + first.columns[2].z * second.z + first.columns[3].z * second.w,
			first.columns[0].w * second.x + first.columns[1].w * second.y + first.columns[2].w * second.z + first.columns[3].w * second.w
		);
	}

	MUTIL_INLINE bool operator ==(const IntMatrix4 &first, const IntMatrix4 &second)
	{
		return first.columns[0] == second.columns[0] && first.columns[1] == second.columns[1] && first.columns[2] == second.columns[2] && first.columns[3] == second.columns[3];
	}



	MUTIL_INLINE Matrix2::Matrix2(const IntMatrix2 &mat)
	{
		columns[0] = Vector2(mat.columns[0]);
		columns[1] = Vector2(mat.columns[1]);
	}

	MUTIL_INLINE Matrix2::Matrix2(const Matrix3 &mat)
	{
		columns[0] = Vector2(mat.columns[0]);
		columns[1] = Vector2(mat.columns[1]);
	}

	MUTIL_INLINE Matrix2::Matrix2(const Matrix4 &mat)
	{
		columns[0] = Vector2(mat.columns[0]);
		columns[1] = Vector2(mat.columns[1]);
	}


	MUTIL_INLINE Matrix3::Matrix3(const IntMatrix3 &mat)
	{
		columns[0] = Vector3(mat.columns[0]);
		columns[1] = Vector3(mat.columns[1]);
		columns[2] = Vector3(mat.columns[2]);
	}

	MUTIL_INLINE Matrix3::Matrix3(const Matrix2 &mat)
	{
		columns[0] = Vector3(mat.columns[0]);
		columns[1] = Vector3(mat.columns[1]);
		columns[2] = Vector3(0.0f, 0.0f, 1.0f);
	}

	MUTIL_INLINE Matrix3::Matrix3(const Matrix4 &mat)
	{
		columns[0] = Vector3(mat.columns[0]);
		columns[1] = Vector3(mat.columns[1]);
		columns[2] = Vector3(mat.columns[2]);
	}


	MUTIL_INLINE Matrix4::Matrix4(const IntMatrix4 &mat)
	{
		columns[0] = Vector4(mat.columns[0]);
		columns[1] = Vector4(mat.columns[1]);
		columns[2] = Vector4(mat.columns[2]);
		columns[3] = Vector4(mat.columns[3]);
	}

	MUTIL_INLINE Matrix4::Matrix4(const Matrix2 &mat)
	{
		columns[0] = Vector4(mat.columns[0]);
		columns[1] = Vector4(mat.columns[1]);
		columns[2] = Vector4(0.0f, 0.0f, 1.0f, 0.0f);
		columns[3] = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
	}

	MUTIL_INLINE Matrix4::Matrix4(const Matrix3 &mat)
	{
		columns[0] = Vector4(mat.columns[0]);
		columns[1] = Vector4(mat.columns[1]);
		columns[2] = Vector4(mat.columns[2]);
		columns[3] = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
	}


	MUTIL_INLINE IntMatrix2::IntMatrix2(const Matrix2 &mat)
	{
		columns[0] = IntVector2(mat.columns[0]);
		columns[1] = IntVector2(mat.columns[1]);
	}

	MUTIL_INLINE IntMatrix2::IntMatrix2(const IntMatrix3 &mat)
	{
		columns[0] = IntVector2(mat.columns[0]);
		columns[1] = IntVector2(mat.columns[1]);
	}

	MUTIL_INLINE IntMatrix2::IntMatrix2(const IntMatrix4 &mat)
	{
		columns[0] = IntVector2(mat.columns[0]);
		columns[1] = IntVector2(mat.columns[1]);
	}


	MUTIL_INLINE IntMatrix3::IntMatrix3(const Matrix3 &mat)
	{
		columns[0] = IntVector3(mat.columns[0]);
		columns[1] = IntVector3(mat.columns[1]);
		columns[2] = IntVector3(mat.columns[2]);
	}

	MUTIL_INLINE IntMatrix3::IntMatrix3(const IntMatrix2 &mat)
	{
		columns[0] = IntVector3(mat.columns[0], 0);
		columns[1] = IntVector3(mat.columns[1], 0);
		columns[2] = IntVector3(0, 0, 1);
	}

	MUTIL_INLINE IntMatrix3::IntMatrix3(const IntMatrix4 &mat)
	{
		columns[0] = IntVector3(mat.columns[0]);
		columns[1] = IntVector3(mat.columns[1]);
		columns[2] = IntVector3(mat.columns[2]);
	}


	MUTIL_INLINE IntMatrix4::IntMatrix4(const Matrix4 &mat)
	{
		columns[0] = IntVector4(mat.columns[0]);
		columns[1] = IntVector4(mat.columns[1]);
		columns[2] = IntVector4(mat.columns[2]);
		columns[3] = IntVector4(mat.columns[3]);
	}

	MUTIL_INLINE IntMatrix4::IntMatrix4(const IntMatrix2 &mat)
	{
		columns[0] = IntVector4(mat.columns[0]);
		columns[1] = IntVector4(mat.columns[1]);
		columns[2] = IntVector4(0, 0, 0, 0);
		columns[3] = IntVector4(0, 0, 0, 1);
	}

	MUTIL_INLINE IntMatrix4::IntMatrix4(const IntMatrix3 &mat)
	{
		columns[0] = IntVector4(mat.columns[0]);
		columns[1] = IntVector4(mat.columns[1]);
		columns[2] = IntVector4(0, 0, 1, 0);
		columns[3] = IntVector4(0, 0, 0, 1);
	}
}

#endif