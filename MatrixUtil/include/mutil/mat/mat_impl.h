#pragma once

#include "../vec/vec.h"

#include "mat_types.h"

#include "matrix2.h"
#include "matrix3.h"
#include "matrix4.h"

#include "intmatrix2.h"
#include "intmatrix3.h"
#include "intmatrix4.h"

namespace mutil
{
    /////////////////////////////////////////////////////////////////
    // Matrix2

    constexpr Matrix2::BasicMatrix() : BasicMatrix(1.0f) {}

    explicit constexpr Matrix2::BasicMatrix(float diagonal)
    {
        columns[0] = Vector2(diagonal, 0.0f);
        columns[1] = Vector2(0.0f, diagonal);
    }

    explicit constexpr Matrix2::BasicMatrix(const Vector2 &col1, const Vector2 &col2)
    {
        columns[0] = col1;
        columns[1] = col2;
    }

    explicit constexpr Matrix2::BasicMatrix(float _11, float _12, float _21, float _22) : _11(_11), _12(_12),
                                                                                          _21(_21), _22(_22) {}
    explicit constexpr Matrix2::BasicMatrix(const IntMatrix2 &mat)
    {
        columns[0] = Vector2(mat.columns[0]);
        columns[1] = Vector2(mat.columns[1]);
    }

    explicit constexpr Matrix2::BasicMatrix(const Matrix3 &mat)
    {
        columns[0] = Vector2(mat.columns[0]);
        columns[1] = Vector2(mat.columns[1]);
    }

    explicit constexpr Matrix2::BasicMatrix(const Matrix4 &mat)
    {
        columns[0] = Vector2(mat.columns[0]);
        columns[1] = Vector2(mat.columns[1]);
    }

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

    /////////////////////////////////////////////////////////////////
    // Matrix3

    constexpr Matrix3::BasicMatrix() : BasicMatrix(1.0f) {}

    constexpr Matrix3::BasicMatrix(float diagonal)
    {
        columns[0] = Vector3(diagonal, 0.0f, 0.0f);
        columns[1] = Vector3(0.0f, diagonal, 0.0f);
        columns[2] = Vector3(0.0f, 0.0f, diagonal);
    }

    constexpr Matrix3::BasicMatrix(const Vector3 &col1, const Vector3 &col2, const Vector3 &col3)
    {
        columns[0] = col1;
        columns[1] = col2;
        columns[2] = col3;
    }

    constexpr Matrix3::BasicMatrix(float _11, float _12, float _13, float _21, float _22, float _23, float _31, float _32, float _33) : _11(_11), _12(_12), _13(_13),
                                                                                                                                        _21(_21), _22(_22), _23(_23),
                                                                                                                                        _31(_31), _32(_32), _33(_33) {}

    constexpr Matrix3::BasicMatrix(const IntMatrix3 &mat)
    {
        columns[0] = Vector3(mat.columns[0]);
        columns[1] = Vector3(mat.columns[1]);
        columns[2] = Vector3(mat.columns[2]);
    }

    constexpr Matrix3::BasicMatrix(const Matrix2 &mat)
    {
        columns[0] = Vector3(mat.columns[0], 0.0f);
        columns[1] = Vector3(mat.columns[1], 0.0f);
        columns[2] = Vector3(0.0f, 0.0f, 1.0f);
    }

    constexpr Matrix3::BasicMatrix(const Matrix4 &mat)
    {
        columns[0] = Vector3(mat.columns[0]);
        columns[1] = Vector3(mat.columns[1]);
        columns[2] = Vector3(mat.columns[2]);
    }

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

    /////////////////////////////////////////////////////////////////
    // Matrix4

    constexpr Matrix4::BasicMatrix() : BasicMatrix(1.0f) {}
    constexpr Matrix4::BasicMatrix(float diagonal)
    {
        columns[0] = Vector4(diagonal, 0.0f, 0.0f, 0.0f);
        columns[1] = Vector4(0.0f, diagonal, 0.0f, 0.0f);
        columns[2] = Vector4(0.0f, 0.0f, diagonal, 0.0f);
        columns[3] = Vector4(0.0f, 0.0f, 0.0f, diagonal);
    }

    constexpr Matrix4::BasicMatrix(const Vector4 &col1, const Vector4 &col2, const Vector4 &col3, const Vector4 &col4)
    {
        columns[0] = col1;
        columns[1] = col2;
        columns[2] = col3;
        columns[3] = col4;
    }

    constexpr Matrix4::BasicMatrix(float _11, float _12, float _13, float _14, float _21, float _22, float _23, float _24, float _31, float _32, float _33, float _34, float _41, float _42, float _43, float _44) : _11(_11), _12(_12), _13(_13), _14(_14),
                                                                                                                                                                                                                     _21(_21), _22(_22), _23(_23), _24(_24),
                                                                                                                                                                                                                     _31(_31), _32(_32), _33(_33), _34(_34),
                                                                                                                                                                                                                     _41(_41), _42(_42), _43(_43), _44(_44) {}

    constexpr Matrix4::BasicMatrix(const IntMatrix4 &mat)
    {
        columns[0] = Vector4(mat.columns[0]);
        columns[1] = Vector4(mat.columns[1]);
        columns[2] = Vector4(mat.columns[2]);
        columns[3] = Vector4(mat.columns[3]);
    }

    constexpr Matrix4::BasicMatrix(const Matrix2 &mat)
    {
        columns[0] = Vector4(mat.columns[0], 0.0f, 0.0f);
        columns[1] = Vector4(mat.columns[1], 0.0f, 0.0f);
        columns[2] = Vector4(0.0f, 0.0f, 1.0f, 0.0f);
        columns[3] = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
    }

    constexpr Matrix4::BasicMatrix(const Matrix3 &mat)
    {
        columns[0] = Vector4(mat.columns[0], 0.0f);
        columns[1] = Vector4(mat.columns[1], 0.0f);
        columns[2] = Vector4(mat.columns[2], 0.0f);
        columns[3] = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
    }

    constexpr Matrix4 operator+(const Matrix4 &first, const Matrix4 &second)
	{
		return Matrix4(first.columns[0] + second.columns[0], first.columns[1] + second.columns[1], first.columns[2] + second.columns[2], first.columns[3] + second.columns[3]);
	}

	constexpr Matrix4 operator-(const Matrix4 &first, const Matrix4 &second)
	{
		return Matrix4(first.columns[0] - second.columns[0], first.columns[1] - second.columns[1], first.columns[2] - second.columns[2], first.columns[3] - second.columns[3]);
	}

	inline Matrix4 MUTIL_VECTORCALL operator*(const Matrix4 &first, const Matrix4 &second)
	{
#if MUTIL_USE_SSE
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
}
