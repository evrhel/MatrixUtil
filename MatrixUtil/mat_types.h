/*!
\file
Contains classes for handling different types of matrices.
*/

#pragma once

#ifndef MAT_TYPES_H
#define MAT_TYPES_H

#include "settings.h"
#include "vec_types.h"

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
	class MUTIL_EXPORT Matrix2
	{
	public:

		/*!
		The matrix's columns.
		*/
		Vector2 columns[2];

		/*!
		Constructs the identity matrix.
		*/
		Matrix2();

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit Matrix2(float const diagonal);

		/*!
		Constructs a matrix with two explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		*/
		explicit Matrix2(Vector2 const &column1, Vector2 const &column2);

		/*!
		Constructs a matrix by casting it from a 32-bit integer matrix.

		@param mat2 The matrix to cast from.
		*/
		explicit Matrix2(IntMatrix2 const &mat2);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit Matrix2(Matrix3 const &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit Matrix2(Matrix4 const &mat);

		inline Matrix2 &operator *=(Matrix2 const &other);
	};

	inline Matrix2 MUTIL_EXPORT operator +(Matrix2 const &first, Matrix2 const &second);
	inline Matrix2 MUTIL_EXPORT operator -(Matrix2 const &first, Matrix2 const &second);
	inline Matrix2 MUTIL_EXPORT operator *(Matrix2 const &first, Matrix2 const &second);
	inline Vector2 MUTIL_EXPORT operator *(Matrix2 const &first, Vector2 const &second);

	inline bool MUTIL_EXPORT operator ==(Matrix2 const &first, Matrix2 const &second);

	/*!
	Class wrapping a 3x3 matrix of floats.
	*/
	class MUTIL_EXPORT Matrix3
	{
	public:

		/*!
		The matrix's columns.
		*/
		Vector3 columns[3];

		/*!
		Constructs the identity matrix.
		*/
		Matrix3();

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit Matrix3(float const diagonal);

		/*!
		Constructs a matrix with three explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		@param column3 The third column.
		*/
		explicit Matrix3(Vector3 const &column1, Vector3 const &column2, Vector3 const &column3);

		/*!
		Constructs a matrix by casting it from a 32-bit integer matrix.

		@param mat3 The matrix to cast from.
		*/
		explicit Matrix3(IntMatrix3 const &mat3);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit Matrix3(Matrix2 const &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit Matrix3(Matrix4 const &mat);

		inline Matrix3 &operator *=(Matrix3 const &other);
	};

	inline Matrix3 MUTIL_EXPORT operator +(Matrix3 const &first, Matrix3 const &second);
	inline Matrix3 MUTIL_EXPORT operator -(Matrix3 const &first, Matrix3 const &second);
	inline Matrix3 MUTIL_EXPORT operator *(Matrix3 const &first, Matrix3 const &second);
	inline Vector3 MUTIL_EXPORT operator *(Matrix3 const &first, Vector3 const &second);

	inline bool MUTIL_EXPORT operator ==(Matrix3 const &first, Matrix3 const &second);

	/*!
	Class wrapping a 4x4 matrix of floats.
	*/
	class MUTIL_EXPORT Matrix4
	{
	public:

		/*!
		The matrix's columns.
		*/
		Vector4 columns[4];

		/*!
		Constructs the identity matrix.
		*/
		Matrix4();

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit Matrix4(float const diagonal);

		/*!
		Constructs a matrix with four explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		@param column3 The third column.
		@param column4 The fourth column.
		*/
		explicit Matrix4(Vector4 const &column1, Vector4 const &column2, Vector4 const &column3, Vector4 const &column4);

		/*!
		Constructs a matrix by casting it from a 32-bit integer matrix.

		@param mat4 The matrix to cast from.
		*/
		explicit Matrix4(IntMatrix4 const &mat4);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit Matrix4(Matrix2 const &mat);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit Matrix4(Matrix3 const &mat);

		inline Matrix4 &operator *=(Matrix4 const &other);
	};

	inline Matrix4 MUTIL_EXPORT operator +(Matrix4 const &first, Matrix4 const &second);
	inline Matrix4 MUTIL_EXPORT operator -(Matrix4 const &first, Matrix4 const &second);
	inline Matrix4 MUTIL_EXPORT operator *(Matrix4 const &first, Matrix4 const &second);
	inline Vector4 MUTIL_EXPORT operator *(Matrix4 const &first, Vector4 const &second);

	inline bool MUTIL_EXPORT operator ==(Matrix4 const &first, Matrix4 const &second);

	/*!
	Class wrapping a 2x2 matrix of 32-bit integers.
	*/
	class MUTIL_EXPORT IntMatrix2
	{
	public:

		/*!
		The matrix's columns.
		*/
		IntVector2 columns[2];

		/*!
		Constructs the identity matrix.
		*/
		IntMatrix2();

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit IntMatrix2(int32_t const diagonal);

		/*!
		Constructs a matrix with two explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		*/
		explicit IntMatrix2(IntVector2 const &column1, IntVector2 const &column2);

		/*!
		Constructs a matrix by casting it from a floating point matrix.

		@param mat2 The matrix to cast from.
		*/
		explicit IntMatrix2(Matrix2 const &mat2);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit IntMatrix2(IntMatrix3 const &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit IntMatrix2(IntMatrix4 const &mat);

		inline IntMatrix2 &operator *=(IntMatrix2 const &other);
	};

	inline IntMatrix2 MUTIL_EXPORT operator +(IntMatrix2 const &first, IntMatrix2 const &second);
	inline IntMatrix2 MUTIL_EXPORT operator -(IntMatrix2 const &first, IntMatrix2 const &second);
	inline IntMatrix2 MUTIL_EXPORT operator *(IntMatrix2 const &first, IntMatrix2 const &second);
	inline IntVector2 MUTIL_EXPORT operator *(IntMatrix2 const &first, IntVector2 const &second);

	inline bool MUTIL_EXPORT operator ==(IntMatrix2 const &first, IntMatrix2 const &second);

	/*!
	Class wrapping a 3x3 matrix of 32-bit integers.
	*/
	class MUTIL_EXPORT IntMatrix3
	{
	public:

		/*!
		The matrix's columns.
		*/
		IntVector3 columns[3];

		/*!
		Constructs the identity matrix.
		*/
		IntMatrix3();

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit IntMatrix3(int32_t const diagonal);

		/*!
		Constructs a matrix with three explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		@param column3 The third column.
		*/
		explicit IntMatrix3(IntVector3 const &column1, IntVector3 const &column2, IntVector3 const &column3);

		/*!
		Constructs a matrix by casting it from a floating point matrix.

		@param mat3 The matrix to cast from.
		*/
		explicit IntMatrix3(Matrix3 const &mat3);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit IntMatrix3(IntMatrix2 const &mat);

		/*!
		Constructs a matrix by filling this matrix with the upper-left portion
		of the input matrix.

		@param mat A matrix.
		*/
		explicit IntMatrix3(IntMatrix4 const &mat);

		inline IntMatrix3 &operator *=(IntMatrix3 const &other);
	};

	inline IntMatrix3 MUTIL_EXPORT operator +(IntMatrix3 const &first, IntMatrix3 const &second);
	inline IntMatrix3 MUTIL_EXPORT operator -(IntMatrix3 const &first, IntMatrix3 const &second);
	inline IntMatrix3 MUTIL_EXPORT operator *(IntMatrix3 const &first, IntMatrix3 const &second);
	inline IntVector3 MUTIL_EXPORT operator *(IntMatrix3 const &first, IntVector3 const &second);

	inline bool MUTIL_EXPORT operator ==(IntMatrix3 const &first, IntMatrix3 const &second);

	/*!
	Class wrapping a 4x4 matrix of 32-bit integers.
	*/
	class MUTIL_EXPORT IntMatrix4
	{
	public:

		/*!
		The matrix's columns.
		*/
		IntVector4 columns[4];

		/*!
		Constructs the identity matrix.
		*/
		IntMatrix4();

		/*!
		Constructs a matrix with a value along its diagnol, and all elements being
		0.

		@param The value of the diagnol.
		*/
		explicit IntMatrix4(int32_t const diagonal);

		/*!
		Constructs a matrix with four explicitly given columns.

		@param column1 The first column.
		@param column2 The second column.
		@param column3 The third column.
		@param column4 The fourth column.
		*/
		explicit IntMatrix4(IntVector4 const &column1, IntVector4 const &column2, IntVector4 const &column3, IntVector4 const &column4);

		/*!
		Constructs a matrix by casting it from a floating point matrix.

		@param mat4 The matrix to cast from.
		*/
		explicit IntMatrix4(Matrix4 const &mat4);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit IntMatrix4(IntMatrix2 const &mat);

		/*!
		Constructs a matrix by filling the upper left portion with input input matrix and
		sets the remaining diagnol to 1 and the rest of the values to 0.

		@param mat A matrix.
		*/
		explicit IntMatrix4(IntMatrix3 const &mat);

		inline IntMatrix4 &operator *=(IntMatrix4 const &other);
	};

	inline IntMatrix4 MUTIL_EXPORT operator +(IntMatrix4 const &first, IntMatrix4 const &second);
	inline IntMatrix4 MUTIL_EXPORT operator -(IntMatrix4 const &first, IntMatrix4 const &second);
	inline IntMatrix4 MUTIL_EXPORT operator *(IntMatrix4 const &first, IntMatrix4 const &second);
	inline IntVector4 MUTIL_EXPORT operator *(IntMatrix4 const &first, IntVector4 const &second);

	inline bool MUTIL_EXPORT operator ==(IntMatrix4 const &first, IntMatrix4 const &second);
}

#endif