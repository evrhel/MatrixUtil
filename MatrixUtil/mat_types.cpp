#include "mat_types.h"

#include "fmat_math.h"

#include <memory>
#ifdef USE_SIMD
#include <smmintrin.h>
#endif

using namespace mutil;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Matrix2
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

mutil::Matrix2::Matrix2() : Matrix2(1.0f) { }

mutil::Matrix2::Matrix2(float const diagonal)
{
	columns[0] = Vector2(diagonal, 0.0f);
	columns[1] = Vector2(0.0f, diagonal);
}

mutil::Matrix2::Matrix2(Vector2 const &column1, Vector2 const &column2)
{
	memcpy(&columns[0], &column1, sizeof(Vector2));
	memcpy(&columns[1], &column2, sizeof(Vector2));
}

mutil::Matrix2::Matrix2(IntMatrix2 const &mat)
{
	columns[0] = Vector2(mat.columns[0]);
	columns[1] = Vector2(mat.columns[1]);
}

mutil::Matrix2::Matrix2(Matrix3 const &mat)
{
	columns[0] = Vector2(mat.columns[0]);
	columns[1] = Vector2(mat.columns[1]);
}

mutil::Matrix2::Matrix2(Matrix4 const &mat)
{
	columns[0] = Vector2(mat.columns[0]);
	columns[1] = Vector2(mat.columns[1]);
}

Matrix2 &mutil::Matrix2::operator*=(Matrix2 const &other)
{
	Matrix2 result = operator*(*this, other);
	memcpy(&columns[0], &result.columns[0], sizeof(Vector2) * 2);
	return *this;
}

Matrix2 mutil::operator+(Matrix2 const &first, Matrix2 const &second)
{
	return Matrix2(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1]);
}

Matrix2 mutil::operator-(Matrix2 const &first, Matrix2 const &second)
{
	return Matrix2(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1]);
}

Matrix2 mutil::operator*(Matrix2 const &first, Matrix2 const &second)
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

Vector2 mutil::operator*(Matrix2 const &first, Vector2 const &second)
{
	return Vector2(
		first.columns[0].x * second.x + first.columns[1].x * second.y,
		first.columns[0].y * second.x + first.columns[1].y * second.y
	);
}

bool mutil::operator==(Matrix2 const &first, Matrix2 const &second)
{
	return first.columns[0] == second.columns[0] && first.columns[1] == second.columns[1];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Matrix3
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

mutil::Matrix3::Matrix3() : Matrix3(1.0f) { }

mutil::Matrix3::Matrix3(float const diagonal)
{
	columns[0] = Vector3(diagonal, 0.0f, 0.0f);
	columns[1] = Vector3(0.0f, diagonal, 0.0f);
	columns[2] = Vector3(0.0f, 0.0f, diagonal);
}

mutil::Matrix3::Matrix3(Vector3 const &column1, Vector3 const &column2, Vector3 const &column3)
{
	columns[0] = Vector3(column1);
	columns[1] = Vector3(column2);
	columns[2] = Vector3(column3);
}

mutil::Matrix3::Matrix3(IntMatrix3 const &mat)
{
	columns[0] = Vector3(mat.columns[0]);
	columns[1] = Vector3(mat.columns[1]);
	columns[2] = Vector3(mat.columns[2]);
}

mutil::Matrix3::Matrix3(Matrix2 const &mat)
{
	columns[0] = Vector3(mat.columns[0]);
	columns[1] = Vector3(mat.columns[1]);
	columns[2] = Vector3(0.0f, 0.0f, 1.0f);
}

mutil::Matrix3::Matrix3(Matrix4 const &mat)
{
	columns[0] = Vector3(mat.columns[0]);
	columns[1] = Vector3(mat.columns[1]);
	columns[2] = Vector3(mat.columns[2]);
}

Matrix3 &mutil::Matrix3::operator*=(Matrix3 const &other)
{
	Matrix3 result = operator*(*this, other);
	memcpy(&columns[0], &result.columns[0], sizeof(Vector3) * 3);
	return *this;
}

Matrix3 mutil::operator+(Matrix3 const &first, Matrix3 const &second)
{
	return Matrix3(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1], first.columns[2] + second.columns[2]);
}

Matrix3 mutil::operator-(Matrix3 const &first, Matrix3 const &second)
{
	return Matrix3(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1], first.columns[2] - second.columns[2]);
}

Matrix3 mutil::operator*(Matrix3 const &first, Matrix3 const &second)
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

Vector3 mutil::operator*(Matrix3 const &first, Vector3 const &second)
{
	return Vector3(
		first.columns[0].x * second.x + first.columns[1].x * second.y + first.columns[2].x * second.z,
		first.columns[0].y * second.x + first.columns[1].y * second.y + first.columns[2].y * second.z,
		first.columns[0].z * second.x + first.columns[1].z * second.y + first.columns[2].z * second.z
	);
}

bool mutil::operator==(Matrix3 const &first, Matrix3 const &second)
{
	return first.columns[0] == second.columns[0] && first.columns[1] == second.columns[1] && first.columns[2] == second.columns[2];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Matrix4
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

mutil::Matrix4::Matrix4() : Matrix4(1.0f) { }

mutil::Matrix4::Matrix4(float const diagonal)
{
	columns[0] = Vector4(diagonal, 0.0f, 0.0f, 0.0f);
	columns[1] = Vector4(0.0f, diagonal, 0.0f, 0.0f);
	columns[2] = Vector4(0.0f, 0.0f, diagonal, 0.0f);
	columns[3] = Vector4(0.0f, 0.0f, 0.0f, diagonal);
}

mutil::Matrix4::Matrix4(Vector4 const &column1, Vector4 const &column2, Vector4 const &column3, Vector4 const &column4)
{
	columns[0] = Vector4(column1);
	columns[1] = Vector4(column2);
	columns[2] = Vector4(column3);
	columns[3] = Vector4(column4);
}

mutil::Matrix4::Matrix4(IntMatrix4 const &mat)
{
	columns[0] = Vector4(mat.columns[0]);
	columns[1] = Vector4(mat.columns[1]);
	columns[2] = Vector4(mat.columns[2]);
	columns[3] = Vector4(mat.columns[3]);
}

mutil::Matrix4::Matrix4(Matrix3 const &mat)
{
	columns[0] = Vector4(mat.columns[0]);
	columns[1] = Vector4(mat.columns[1]);
	columns[2] = Vector4(mat.columns[2]);
	columns[3] = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
}

mutil::Matrix4::Matrix4(Matrix2 const &mat)
{
	columns[0] = Vector4(mat.columns[0]);
	columns[1] = Vector4(mat.columns[1]);
	columns[2] = Vector4(0.0f, 0.0f, 1.0f, 0.0f);
	columns[3] = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4 &mutil::Matrix4::operator*=(Matrix4 const &other)
{
	Matrix4 result = operator*(*this, other);
	memcpy(&columns[0], &result.columns[0], sizeof(Vector4) * 4);
	return *this;
}

Matrix4 mutil::operator +(Matrix4 const &first, Matrix4 const &second)
{
	return Matrix4(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1], first.columns[2] + second.columns[2], first.columns[3] + second.columns[3]);
}

Matrix4 mutil::operator -(Matrix4 const &first, Matrix4 const &second)
{
	return Matrix4(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1], first.columns[2] - second.columns[2], first.columns[3] - second.columns[3]);
}

Matrix4 mutil::operator*(Matrix4 const &first, Matrix4 const &second)
{
#ifdef USE_SIMD
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

Vector4 mutil::operator*(Matrix4 const &first, Vector4 const &second)
{
	return Vector4(
		first.columns[0].x * second.x + first.columns[1].x * second.y + first.columns[2].x * second.z + first.columns[3].x * second.w,
		first.columns[0].y * second.x + first.columns[1].y * second.y + first.columns[2].y * second.z + first.columns[3].y * second.w,
		first.columns[0].z * second.x + first.columns[1].z * second.y + first.columns[2].z * second.z + first.columns[3].z * second.w,
		first.columns[0].w * second.x + first.columns[1].w * second.y + first.columns[2].w * second.z + first.columns[3].w * second.w
	);
}

bool mutil::operator==(Matrix4 const &first, Matrix4 const &second)
{
	return first.columns[0] == second.columns[0] && first.columns[1] == second.columns[1] && first.columns[2] == second.columns[2] && first.columns[3] == second.columns[3];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IntMatrix2
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

mutil::IntMatrix2::IntMatrix2() : IntMatrix2(1) { }

mutil::IntMatrix2::IntMatrix2(int32_t diagonal)
{
	columns[0] = IntVector2(diagonal, 0.0f);
	columns[1] = IntVector2(0.0f, diagonal);
}

mutil::IntMatrix2::IntMatrix2(IntVector2 const &column1, IntVector2 const &column2)
{
	columns[0] = column1;
	columns[1] = column2;
}

mutil::IntMatrix2::IntMatrix2(Matrix2 const &mat)
{
	columns[0] = IntVector2(mat.columns[0]);
	columns[1] = IntVector2(mat.columns[1]);
}

mutil::IntMatrix2::IntMatrix2(IntMatrix3 const &mat)
{
	columns[0] = IntVector2(mat.columns[0]);
	columns[1] = IntVector2(mat.columns[1]);
}

mutil::IntMatrix2::IntMatrix2(IntMatrix4 const &mat)
{
	columns[0] = IntVector2(mat.columns[0]);
	columns[1] = IntVector2(mat.columns[1]);
}

inline IntMatrix2 &mutil::IntMatrix2::operator*=(IntMatrix2 const &other)
{
	IntMatrix2 result = operator*(*this, other);
	memcpy(&columns[0], &result.columns[0], sizeof(IntVector2) * 2);
	return *this;
}

IntMatrix2 mutil::operator+(IntMatrix2 const &first, IntMatrix2 const &second)
{
	return IntMatrix2(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1]);
}

IntMatrix2 mutil::operator-(IntMatrix2 const &first, IntMatrix2 const &second)
{
	return IntMatrix2(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1]);
}

IntMatrix2 mutil::operator*(IntMatrix2 const &first, IntMatrix2 const &second)
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

IntVector2 mutil::operator*(IntMatrix2 const &first, IntVector2 const &second)
{
	return IntVector2(
		first.columns[0].x * second.x + first.columns[1].x * second.y,
		first.columns[0].y * second.x + first.columns[1].y * second.y
	);
}

bool mutil::operator==(IntMatrix2 const &first, IntMatrix2 const &second)
{
	return first.columns[0] == second.columns[0] && first.columns[1] == second.columns[1];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IntMatrix3
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

mutil::IntMatrix3::IntMatrix3() : IntMatrix3(1) { }

mutil::IntMatrix3::IntMatrix3(int32_t diagonal)
{
	columns[0] = IntVector3(diagonal, 0.0f, 0.0f);
	columns[1] = IntVector3(0.0f, diagonal, 0.0f);
	columns[2] = IntVector3(0.0f, 0.0f, diagonal);
}

mutil::IntMatrix3::IntMatrix3(IntVector3 const &column1, IntVector3 const &column2, IntVector3 const &column3)
{
	columns[0] = column1;
	columns[1] = column2;
	columns[2] = column3;
}

mutil::IntMatrix3::IntMatrix3(Matrix3 const &mat)
{
	columns[0] = IntVector3(mat.columns[0]);
	columns[1] = IntVector3(mat.columns[1]);
	columns[2] = IntVector3(mat.columns[2]);
}

mutil::IntMatrix3::IntMatrix3(IntMatrix2 const &mat)
{
	columns[0] = IntVector3(mat.columns[0], 0);
	columns[1] = IntVector3(mat.columns[1], 0);
	columns[2] = IntVector3(0, 0, 1);
}

mutil::IntMatrix3::IntMatrix3(IntMatrix4 const &mat)
{
	columns[0] = IntVector3(mat.columns[0]);
	columns[1] = IntVector3(mat.columns[1]);
	columns[2] = IntVector3(mat.columns[2]);
}

IntMatrix3 &mutil::IntMatrix3::operator*=(IntMatrix3 const &other)
{
	IntMatrix3 result = operator*(*this, other);
	memcpy(&columns[0], &result.columns[0], sizeof(IntVector3) * 3);
	return *this;
}

IntMatrix3 mutil::operator+(IntMatrix3 const &first, IntMatrix3 const &second)
{
	return IntMatrix3(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1], first.columns[2] + second.columns[2]);
}

IntMatrix3 mutil::operator-(IntMatrix3 const &first, IntMatrix3 const &second)
{
	return IntMatrix3(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1], first.columns[2] - second.columns[2]);
}

IntMatrix3 mutil::operator*(IntMatrix3 const &first, IntMatrix3 const &second)
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

IntVector3 mutil::operator*(IntMatrix3 const &first, IntVector3 const &second)
{
	return IntVector3(
		first.columns[0].x * second.x + first.columns[1].x * second.y + first.columns[2].x * second.z,
		first.columns[0].y * second.x + first.columns[1].y * second.y + first.columns[2].y * second.z,
		first.columns[0].z * second.x + first.columns[1].z * second.y + first.columns[2].z * second.z
	);
}

bool mutil::operator==(IntMatrix3 const &first, IntMatrix3 const &second)
{
	return first.columns[0] == second.columns[0] && first.columns[1] == second.columns[1] && first.columns[2] == second.columns[2];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IntMatrix4
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

mutil::IntMatrix4::IntMatrix4() : IntMatrix4(1) { }

mutil::IntMatrix4::IntMatrix4(int32_t const diagonal)
{
	columns[0] = IntVector4(diagonal, 0.0f, 0.0f, 0.0f);
	columns[1] = IntVector4(0.0f, diagonal, 0.0f, 0.0f);
	columns[2] = IntVector4(0.0f, 0.0f, diagonal, 0.0f);
	columns[3] = IntVector4(0.0f, 0.0f, 0.0f, diagonal);
}

mutil::IntMatrix4::IntMatrix4(IntVector4 const &column1, IntVector4 const &column2, IntVector4 const &column3, IntVector4 const &column4)
{
	columns[0] = column1;
	columns[1] = column2;
	columns[2] = column3;
	columns[3] = column4;
}

mutil::IntMatrix4::IntMatrix4(Matrix4 const &mat)
{
	columns[0] = IntVector4(mat.columns[0]);
	columns[1] = IntVector4(mat.columns[1]);
	columns[2] = IntVector4(mat.columns[2]);
	columns[3] = IntVector4(mat.columns[3]);
}

mutil::IntMatrix4::IntMatrix4(IntMatrix3 const &mat)
{
	columns[0] = IntVector4(mat.columns[0]);
	columns[1] = IntVector4(mat.columns[1]);
	columns[2] = IntVector4(mat.columns[2]);
	columns[3] = IntVector4(0, 0, 0, 1);
}

mutil::IntMatrix4::IntMatrix4(IntMatrix2 const &mat)
{
	columns[0] = IntVector4(mat.columns[0]);
	columns[1] = IntVector4(mat.columns[1]);
	columns[2] = IntVector4(0, 0, 1, 0);
	columns[3] = IntVector4(0, 0, 0, 1);
}

IntMatrix4 &mutil::IntMatrix4::operator*=(IntMatrix4 const &other)
{
	IntMatrix4 result = operator*(*this, other);
	memcpy(&columns[0], &result.columns[0], sizeof(IntVector4) * 4);
	return *this;
}

IntMatrix4 mutil::operator +(IntMatrix4 const &first, IntMatrix4 const &second)
{
	return IntMatrix4(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1], first.columns[2] + second.columns[2], first.columns[3] + second.columns[3]);
}

IntMatrix4 mutil::operator -(IntMatrix4 const &first, IntMatrix4 const &second)
{
	return IntMatrix4(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1], first.columns[2] - second.columns[2], first.columns[3] - second.columns[3]);
}

IntMatrix4 mutil::operator*(IntMatrix4 const &first, IntMatrix4 const &second)
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

IntVector4 mutil::operator*(IntMatrix4 const &first, IntVector4 const &second)
{
	return IntVector4(
		first.columns[0].x * second.x + first.columns[1].x * second.y + first.columns[2].x * second.z + first.columns[3].x * second.w,
		first.columns[0].y * second.x + first.columns[1].y * second.y + first.columns[2].y * second.z + first.columns[3].y * second.w,
		first.columns[0].z * second.x + first.columns[1].z * second.y + first.columns[2].z * second.z + first.columns[3].z * second.w,
		first.columns[0].w * second.x + first.columns[1].w * second.y + first.columns[2].w * second.z + first.columns[3].w * second.w
	);
}

bool mutil::operator==(IntMatrix4 const &first, IntMatrix4 const &second)
{
	return first.columns[0] == second.columns[0] && first.columns[1] == second.columns[1] && first.columns[2] == second.columns[2] && first.columns[3] == second.columns[3];
}