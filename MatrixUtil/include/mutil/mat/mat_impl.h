#pragma once

#include "mat.h"

namespace mutil
{
	/////////////////////////////////////////////////////////////
	// BasicMatrix

	template <typename T, size_t N, size_t M>
	constexpr BasicMatrix<T, N, M> operator+(const BasicMatrix<T, N, M> &a, const BasicMatrix<T, N, M> &b)
	{
		BasicMatrix<T, N, M> result;
		for (size_t i = 0; i < N * M; i++)
			result[i] = a[i] + b[i];
		return result;
	}

	template <typename T, size_t N, size_t M>
	constexpr BasicMatrix<T, N, M> operator-(const BasicMatrix<T, N, M> &a, const BasicMatrix<T, N, M> &b)
	{
		BasicMatrix<T, N, M> result;
		for (size_t i = 0; i < N * M; i++)
			result[i] = a[i] - b[i];
		return result;
	}

	template <typename T, size_t N, size_t M, size_t P>
	constexpr BasicMatrix<T, N, P> operator*(const BasicMatrix<T, N, M> &a, const BasicMatrix<T, M, P> &b)
	{
		BasicMatrix<T, N, P> result;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < P; j++)
			{
				T sum = T(0);
				for (size_t k = 0; k < M; k++)
					sum += a.mat[i * M + k] * b.mat[k * P + j];
				result.mat[i * P + j] = sum;
			}
		}
		return result;
	}

	template <typename T, size_t N, size_t M>
	constexpr BasicVector<T, N> operator*(const BasicMatrix<T, N, M> &a, const BasicVector<T, M> &b)
	{
		BasicVector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			T sum = T(0);
			for (size_t j = 0; j < M; j++)
				sum += a.mat[i * M + j] * b[j];
			result[i] = sum;
		}
		return result;
	}

	template <typename T, size_t N, size_t M>
	constexpr BasicMatrix<T, N, M> operator*(const BasicMatrix<T, N, M> &a, T b)
	{
		BasicMatrix<T, N, M> result;
		for (size_t i = 0; i < N * M; i++)
			result[i] = a[i] * b;
		return result;
	}

	template <typename T, size_t N, size_t M>
	constexpr BasicMatrix<T, N, M> operator/(const BasicMatrix<T, N, M> &a, T b)
	{
		BasicMatrix<T, N, M> result;
		for (size_t i = 0; i < N * M; i++)
			result[i] = a[i] / b;
		return result;
	}

	template <typename T, size_t N, size_t M>
	constexpr bool operator==(const BasicMatrix<T, N, M> &a, const BasicMatrix<T, N, M> &b)
	{
		for (size_t i = 0; i < N * M; i++)
		{
			if (a[i] != b[i])
				return false;
		}
		return true;
	
	}

	template <typename T, size_t N, size_t M>
	constexpr bool operator!=(const BasicMatrix<T, N, M> &a, const BasicMatrix<T, N, M> &b)
	{
		for (size_t i = 0; i < N * M; i++)
		{
			if (a[i] != b[i])
				return true;
		}
		return false;
	}

	template <typename T, size_t N, size_t M>
	constexpr BasicMatrix<T, N, M> &BasicMatrix<T, N, M>::operator+=(const BasicMatrix<T, N, M> &a)
	{
		for (size_t i = 0; i < N * M; i++)
			mat[i] += a[i];
		return *this;
	}

	template <typename T, size_t N, size_t M>
	constexpr BasicMatrix<T, N, M> &BasicMatrix<T, N, M>::operator-=(const BasicMatrix<T, N, M> &a)
	{
		for (size_t i = 0; i < N * M; i++)
			mat[i] -= a[i];
		return *this;
	}

	template <typename T, size_t N, size_t M>
	constexpr BasicMatrix<T, N, M> &BasicMatrix<T, N, M>::operator*=(const BasicMatrix<T, N, M> &a)
	{
		*this = *this * a;
		return *this;
	}

	template <typename T, size_t N, size_t M>
	constexpr BasicMatrix<T, N, M> &BasicMatrix<T, N, M>::operator*=(T a)
	{
		for (size_t i = 0; i < N * M; i++)
			mat[i] *= a;
		return *this;
	}

	template <typename T, size_t N, size_t M>
	constexpr BasicMatrix<T, N, M> &BasicMatrix<T, N, M>::operator/=(T a)
	{
		for (size_t i = 0; i < N * M; i++)
			mat[i] /= a;
		return *this;
	}

    /////////////////////////////////////////////////////////////////
    // Matrix2

    constexpr Matrix2::BasicMatrix() : 
		_11(1.0f), _12(0.0f),
		_21(0.0f), _22(1.0f) {}

    constexpr Matrix2::BasicMatrix(float diag) :
        _11(diag), _12(0.0f),
        _21(0.0f), _22(diag) {}

    constexpr Matrix2::BasicMatrix(const Vector2 &col1, const Vector2 &col2) :
        _11(col1.x), _12(col2.x),
		_21(col1.y), _22(col2.y) {}

    constexpr Matrix2::BasicMatrix(float _11, float _12,
                    float _21, float _22) :
                        _11(_11), _12(_12),
                        _21(_21), _22(_22) {}

    constexpr Matrix2::BasicMatrix(const IntMatrix2 &a) :
        columns{Vector2(a.columns[0]), Vector2(a.columns[1])} {}

    constexpr Matrix2::BasicMatrix(const Matrix3 &a) :
        columns{Vector2(a.columns[0]), Vector2(a.columns[1])} {}

    constexpr Matrix2::BasicMatrix(const Matrix4 &a) :
        columns{Vector2(a.columns[0]), Vector2(a.columns[1])} {}

    constexpr Matrix2 operator+(const Matrix2 &a, const Matrix2 &b)
    {
        return Matrix2(a.columns[0] + b.columns[0], a.columns[1] + b.columns[1]);
    }

    constexpr Matrix2 operator-(const Matrix2 &a, const Matrix2 &b)
    {
        return Matrix2(a.columns[0] - b.columns[0], a.columns[1] - b.columns[1]);
    }

    constexpr Matrix2 operator*(const Matrix2 &a, const Matrix2 &b)
    {
        return Matrix2(
            a._11 * b._11 + a._12 * b._21, a._11 * b._12 + a._12 * b._22,
            a._21 * b._11 + a._22 * b._21, a._21 * b._12 + a._22 * b._22);
    }

    constexpr Vector2 operator*(const Matrix2 &a, const Vector2 &b)
    {
        return Vector2(
            a._11 * b.x + a._12 * b.y,
            a._21 * b.x + a._22 * b.y);
    }

    constexpr Matrix2 operator*(const Matrix2 &a, float b)
    {
        return Matrix2(
            a.columns[0] * b,
            a.columns[1] * b);
    }

    constexpr Matrix2 operator/(const Matrix2 &a, float b)
    {
        return Matrix2(
            a.columns[0] / b,
            a.columns[1] / b);
    }

    constexpr bool operator==(const Matrix2 &a, const Matrix2 &b)
    {
        return a.columns[0] == b.columns[0] && a.columns[1] == b.columns[1];
    }

    /////////////////////////////////////////////////////////////////
    // Matrix3

    constexpr Matrix3::BasicMatrix() : 
		_11(1.0f), _12(0.0f), _13(0.0f),
		_21(0.0f), _22(1.0f), _23(0.0f),
		_31(0.0f), _32(0.0f), _33(1.0f) {}

    constexpr Matrix3::BasicMatrix(float diag) :
        _11(diag), _12(0.0f), _13(0.0f),
        _21(0.0f), _22(diag), _23(0.0f),
        _31(0.0f), _32(0.0f), _33(diag) {}

    constexpr Matrix3::BasicMatrix(const Vector3 &col1, const Vector3 &col2, const Vector3 &col3) :
        _11(col1.x), _12(col2.x), _13(col3.x),
		_21(col1.y), _22(col2.y), _23(col3.y),
		_31(col1.z), _32(col2.z), _33(col3.z) {}

    constexpr Matrix3::BasicMatrix(float _11, float _12, float _13,
                    float _21, float _22, float _23,
                    float _31, float _32, float _33) :
                        _11(_11), _12(_12), _13(_13),
                        _21(_21), _22(_22), _23(_23),
                        _31(_31), _32(_32), _33(_33) {}

    constexpr Matrix3::BasicMatrix(const IntMatrix3 &mat) :
		_11((float)mat._11), _12((float)mat._12), _13((float)mat._13),
		_21((float)mat._21), _22((float)mat._22), _23((float)mat._23),
		_31((float)mat._31), _32((float)mat._32), _33((float)mat._33) {}

    constexpr Matrix3::BasicMatrix(const Matrix2 &mat) :
		_11(mat._11), _12(mat._12), _13(0.0f),
		_21(mat._21), _22(mat._22), _23(0.0f),
		_31(0.0f), _32(0.0f), _33(1.0f) {}

    constexpr Matrix3::BasicMatrix(const Matrix4 &mat) :
		_11(mat._11), _12(mat._12), _13(mat._13),
		_21(mat._21), _22(mat._22), _23(mat._23),
		_31(mat._31), _32(mat._32), _33(mat._33) {}

    constexpr Matrix3 operator+(const Matrix3 &a, const Matrix3 &b)
    {
        return Matrix3(a.columns[0] + b.columns[0], a.columns[1] + b.columns[1], a.columns[2] + b.columns[2]);
    }

    constexpr Matrix3 operator-(const Matrix3 &a, const Matrix3 &b)
    {
        return Matrix3(a.columns[0] - b.columns[0], a.columns[1] - b.columns[1], a.columns[2] - b.columns[2]);
    }

    constexpr Matrix3 operator*(const Matrix3 &a, const Matrix3 &b)
    {
        return Matrix3(
            a._11 * b._11 + a._12 * b._21 + a._13 * b._31,
            a._11 * b._12 + a._12 * b._22 + a._13 * b._32,
            a._11 * b._13 + a._12 * b._23 + a._13 * b._33,
            a._21 * b._11 + a._22 * b._21 + a._23 * b._31,
            a._21 * b._12 + a._22 * b._22 + a._23 * b._32,
            a._21 * b._13 + a._22 * b._23 + a._23 * b._33,
            a._31 * b._11 + a._32 * b._21 + a._33 * b._31,
            a._31 * b._12 + a._32 * b._22 + a._33 * b._32,
            a._31 * b._13 + a._32 * b._23 + a._33 * b._33);
    }

    constexpr Vector3 operator*(const Matrix3 &a, const Vector3 &b)
    {
        return Vector3(
            a.columns[0].x * b.x + a.columns[1].x * b.y + a.columns[2].x * b.z,
            a.columns[0].y * b.x + a.columns[1].y * b.y + a.columns[2].y * b.z,
            a.columns[0].z * b.x + a.columns[1].z * b.y + a.columns[2].z * b.z);
    }

    constexpr Matrix3 operator*(const Matrix3 &a, float b)
    {
        return Matrix3(
            a.columns[0] * b,
            a.columns[1] * b,
            a.columns[2] * b);
    }

    constexpr Matrix3 operator/(const Matrix3 &a, float b)
    {
        return Matrix3(
            a.columns[0] / b,
            a.columns[1] / b,
            a.columns[2] / b);
    }

    constexpr bool operator==(const Matrix3 &a, const Matrix3 &b)
    {
        return a.columns[0] == b.columns[0] && a.columns[1] == b.columns[1] && a.columns[2] == b.columns[2];
    }

    /////////////////////////////////////////////////////////////////
    // Matrix4

    constexpr Matrix4::BasicMatrix() : 
		_11(1.0f), _12(0.0f), _13(0.0f), _14(0.0f),
		_21(0.0f), _22(1.0f), _23(0.0f), _24(0.0f),
		_31(0.0f), _32(0.0f), _33(1.0f), _34(0.0f),
		_41(0.0f), _42(0.0f), _43(0.0f), _44(1.0f) {}

    constexpr Matrix4::BasicMatrix(float diag) :
        _11(diag), _12(0.0f), _13(0.0f), _14(0.0f),
        _21(0.0f), _22(diag), _23(0.0f), _24(0.0f),
        _31(0.0f), _32(0.0f), _33(diag), _34(0.0f),
        _41(0.0f), _42(0.0f), _43(0.0f), _44(diag) {}

    constexpr Matrix4::BasicMatrix(const Vector4 &col1, const Vector4 &col2,
    			const Vector4 &col3, const Vector4 &col4) :
		_11(col1.x), _12(col2.x), _13(col3.x), _14(col4.x),
		_21(col1.y), _22(col2.y), _23(col3.y), _24(col4.y),
		_31(col1.z), _32(col2.z), _33(col3.z), _34(col4.z),
		_41(col1.w), _42(col2.w), _43(col3.w), _44(col4.w) {}

    constexpr Matrix4::BasicMatrix(float _11, float _12, float _13, float _14,
                float _21, float _22, float _23, float _24,
                float _31, float _32, float _33, float _34,
                float _41, float _42, float _43, float _44) :
                    _11(_11), _12(_12), _13(_13), _14(_14),
                    _21(_21), _22(_22), _23(_23), _24(_24),
                    _31(_31), _32(_32), _33(_33), _34(_34),
                    _41(_41), _42(_42), _43(_43), _44(_44) {}

    constexpr Matrix4::BasicMatrix(const IntMatrix4 &a) :
		_11((float)a._11), _12((float)a._12), _13((float)a._13), _14((float)a._14),
		_21((float)a._21), _22((float)a._22), _23((float)a._23), _24((float)a._24),
		_31((float)a._31), _32((float)a._32), _33((float)a._33), _34((float)a._34),
		_41((float)a._41), _42((float)a._42), _43((float)a._43), _44((float)a._44) {}

    constexpr Matrix4::BasicMatrix(const Matrix2 &a) :
		_11(a._11), _12(a._12), _13(0.0f), _14(0.0f),
		_21(a._21), _22(a._22), _23(0.0f), _24(0.0f),
		_31(0.0f), _32(0.0f), _33(1.0f), _34(0.0f),
		_41(0.0f), _42(0.0f), _43(0.0f), _44(1.0f) {}

    constexpr Matrix4::BasicMatrix(const Matrix3 &a) :
		_11(a._11), _12(a._12), _13(a._13), _14(0.0f),
		_21(a._21), _22(a._22), _23(a._23), _24(0.0f),
		_31(a._31), _32(a._32), _33(a._33), _34(0.0f),
		_41(0.0f), _42(0.0f), _43(0.0f), _44(1.0f) {}

    constexpr Matrix4 operator+(const Matrix4 &a, const Matrix4 &b)
	{
		return Matrix4(a.columns[0] + b.columns[0], a.columns[1] + b.columns[1], a.columns[2] + b.columns[2], a.columns[3] + b.columns[3]);
	}

	constexpr Matrix4 operator-(const Matrix4 &a, const Matrix4 &b)
	{
		return Matrix4(a.columns[0] - b.columns[0], a.columns[1] - b.columns[1], a.columns[2] - b.columns[2], a.columns[3] - b.columns[3]);
	}

	inline Matrix4 MUTIL_VECTORCALL operator*(const Matrix4 &a, const Matrix4 &b)
	{
#if MUTIL_USE_SSE
		constexpr int MASK0 = 0xf1, MASK1 = 0xf2, MASK2 = 0xf4, MASK3 = 0xf8;

		__m128 rc0 = _mm_loadu_ps((float *)&b.columns[0]);
		__m128 rc1 = _mm_loadu_ps((float *)&b.columns[1]);
		__m128 rc2 = _mm_loadu_ps((float *)&b.columns[2]);
		__m128 rc3 = _mm_loadu_ps((float *)&b.columns[3]);

		__m128 lr0 = _mm_set_ps(a.columns[3].x, a.columns[2].x, a.columns[1].x, a.columns[0].x);
		__m128 lr1 = _mm_set_ps(a.columns[3].y, a.columns[2].y, a.columns[1].y, a.columns[0].y);
		__m128 lr2 = _mm_set_ps(a.columns[3].z, a.columns[2].z, a.columns[1].z, a.columns[0].z);
		__m128 lr3 = _mm_set_ps(a.columns[3].w, a.columns[2].w, a.columns[1].w, a.columns[0].w);

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
				(a.columns[0].x * b.columns[0].x) + (a.columns[1].x * b.columns[0].y) + (a.columns[2].x * b.columns[0].z) + (a.columns[3].x * b.columns[0].w),
				(a.columns[0].y * b.columns[0].x) + (a.columns[1].y * b.columns[0].y) + (a.columns[2].y * b.columns[0].z) + (a.columns[3].y * b.columns[0].w),
				(a.columns[0].z * b.columns[0].x) + (a.columns[1].z * b.columns[0].y) + (a.columns[2].z * b.columns[0].z) + (a.columns[3].z * b.columns[0].w),
				(a.columns[0].w * b.columns[0].x) + (a.columns[1].w * b.columns[0].y) + (a.columns[2].w * b.columns[0].z) + (a.columns[3].w * b.columns[0].w)),
			Vector4(
				(a.columns[0].x * b.columns[1].x) + (a.columns[1].x * b.columns[1].y) + (a.columns[2].x * b.columns[1].z) + (a.columns[3].x * b.columns[1].w),
				(a.columns[0].y * b.columns[1].x) + (a.columns[1].y * b.columns[1].y) + (a.columns[2].y * b.columns[1].z) + (a.columns[3].y * b.columns[1].w),
				(a.columns[0].z * b.columns[1].x) + (a.columns[1].z * b.columns[1].y) + (a.columns[2].z * b.columns[1].z) + (a.columns[3].z * b.columns[1].w),
				(a.columns[0].w * b.columns[1].x) + (a.columns[1].w * b.columns[1].y) + (a.columns[2].w * b.columns[1].z) + (a.columns[3].w * b.columns[1].w)),
			Vector4(
				(a.columns[0].x * b.columns[2].x) + (a.columns[1].x * b.columns[2].y) + (a.columns[2].x * b.columns[2].z) + (a.columns[3].x * b.columns[2].w),
				(a.columns[0].y * b.columns[2].x) + (a.columns[1].y * b.columns[2].y) + (a.columns[2].y * b.columns[2].z) + (a.columns[3].y * b.columns[2].w),
				(a.columns[0].z * b.columns[2].x) + (a.columns[1].z * b.columns[2].y) + (a.columns[2].z * b.columns[2].z) + (a.columns[3].z * b.columns[2].w),
				(a.columns[0].w * b.columns[2].x) + (a.columns[1].w * b.columns[2].y) + (a.columns[2].w * b.columns[2].z) + (a.columns[3].w * b.columns[2].w)),
			Vector4(
				(a.columns[0].x * b.columns[3].x) + (a.columns[1].x * b.columns[3].y) + (a.columns[2].x * b.columns[3].z) + (a.columns[3].x * b.columns[3].w),
				(a.columns[0].y * b.columns[3].x) + (a.columns[1].y * b.columns[3].y) + (a.columns[2].y * b.columns[3].z) + (a.columns[3].y * b.columns[3].w),
				(a.columns[0].z * b.columns[3].x) + (a.columns[1].z * b.columns[3].y) + (a.columns[2].z * b.columns[3].z) + (a.columns[3].z * b.columns[3].w),
				(a.columns[0].w * b.columns[3].x) + (a.columns[1].w * b.columns[3].y) + (a.columns[2].w * b.columns[3].z) + (a.columns[3].w * b.columns[3].w)));
#endif
	}

	constexpr Vector4 operator*(const Matrix4 &a, const Vector4 &b)
	{
		return Vector4(
			a.columns[0].x * b.x + a.columns[1].x * b.y + a.columns[2].x * b.z + a.columns[3].x * b.w,
			a.columns[0].y * b.x + a.columns[1].y * b.y + a.columns[2].y * b.z + a.columns[3].y * b.w,
			a.columns[0].z * b.x + a.columns[1].z * b.y + a.columns[2].z * b.z + a.columns[3].z * b.w,
			a.columns[0].w * b.x + a.columns[1].w * b.y + a.columns[2].w * b.z + a.columns[3].w * b.w);
	}

	constexpr Matrix4 operator*(const Matrix4 &a, float b)
	{
		return Matrix4(
			a.columns[0] * b,
			a.columns[1] * b,
			a.columns[2] * b,
			a.columns[3] * b);
	}

	constexpr Matrix4 operator/(const Matrix4 &a, float b)
	{
		return Matrix4(
			a.columns[0] / b,
			a.columns[1] / b,
			a.columns[2] / b,
			a.columns[3] / b);
	}

	constexpr bool operator==(const Matrix4 &a, const Matrix4 &b)
	{
		return a.columns[0] == b.columns[0] && a.columns[1] == b.columns[1] && a.columns[2] == b.columns[2] && a.columns[3] == b.columns[3];
	}

    /////////////////////////////////////////////////////////////////
    // IntMatrix2

    constexpr IntMatrix2::BasicMatrix() :
		_11(1), _12(0),
		_21(0), _22(1) {}
    
    constexpr IntMatrix2::BasicMatrix(int32_t diag) :
		_11(diag), _12(0),
		_21(0), _22(diag) {}

    constexpr IntMatrix2::BasicMatrix(const IntVector2 &col1, const IntVector2 &col2) :
		_11(col1.x), _12(col2.x),
		_21(col1.y), _22(col2.y) {}

    constexpr IntMatrix2::BasicMatrix(int32_t _11, int32_t _12, int32_t _21, int32_t _22) : _11(_11), _12(_12),
                                                                                              _21(_21), _22(_22) {}

    constexpr IntMatrix2::BasicMatrix(const Matrix2 &a) :
		_11((int32_t)a._11), _12((int32_t)a._12),
		_21((int32_t)a._21), _22((int32_t)a._22) {}

    constexpr IntMatrix2::BasicMatrix(const IntMatrix3 &a) :
		_11(a._11), _12(a._12),
		_21(a._21), _22(a._22) {}

    constexpr IntMatrix2::BasicMatrix(const IntMatrix4 &a) :
		_11(a._11), _12(a._12),
		_21(a._21), _22(a._22) {}

    constexpr IntMatrix2 operator+(const IntMatrix2 &a, const IntMatrix2 &b)
	{
		return IntMatrix2(a.columns[0] + b.columns[0], a.columns[1] + b.columns[1]);
	}

	constexpr IntMatrix2 operator-(const IntMatrix2 &a, const IntMatrix2 &b)
	{
		return IntMatrix2(a.columns[0] - b.columns[0], a.columns[1] - b.columns[1]);
	}

	constexpr IntMatrix2 operator*(const IntMatrix2 &a, const IntMatrix2 &b)
	{
		return IntMatrix2(
			a._11 * b._11 + a._12 * b._21, a._11 * b._12 + a._12 * b._22,
			a._21 * b._11 + a._22 * b._21, a._21 * b._21 + a._22 * b._22);
	}

	constexpr IntVector2 operator*(const IntMatrix2 &a, const IntVector2 &b)
	{
		return IntVector2(
			a.columns[0].x * b.x + a.columns[1].x * b.y,
			a.columns[0].y * b.x + a.columns[1].y * b.y);
	}

	constexpr IntMatrix2 operator*(const IntMatrix2 &a, int32_t b)
	{
		return IntMatrix2(
			a.columns[0] * b,
			a.columns[1] * b);
	}

	constexpr IntMatrix2 operator/(const IntMatrix2 &a, int32_t b)
	{
		return IntMatrix2(
			a.columns[0] / b,
			a.columns[1] / b);
	}

	constexpr bool operator==(const IntMatrix2 &a, const IntMatrix2 &b)
	{
		return a.columns[0] == b.columns[0] && a.columns[1] == b.columns[1];
	}

    /////////////////////////////////////////////////////////////////
    // IntMatrix3

    constexpr IntMatrix3::BasicMatrix() :
		_11(1), _12(0), _13(0),
		_21(0), _22(1), _23(0),
		_31(0), _32(0), _33(1) {}

    constexpr IntMatrix3::BasicMatrix(int32_t diag) :
		_11(diag), _12(0), _13(0),
		_21(0), _22(diag), _23(0),
		_31(0), _32(0), _33(diag) {}

    constexpr IntMatrix3::BasicMatrix(const IntVector3 &col1, const IntVector3 &col2, const IntVector3 &col3) :
		_11(col1.x), _12(col2.x), _13(col3.x),
		_21(col1.y), _22(col2.y), _23(col3.y),
		_31(col1.z), _32(col2.z), _33(col3.z) {}

    constexpr IntMatrix3::BasicMatrix(int32_t _11, int32_t _12, int32_t _13,
        int32_t _21, int32_t _22, int32_t _23,
        int32_t _31, int32_t _32, int32_t _33) :
                                            _11(_11), _12(_12), _13(_13),
                                            _21(_21), _22(_22), _23(_23),
                                            _31(_31), _32(_32), _33(_33) {}

    constexpr IntMatrix3::BasicMatrix(const Matrix3 &a) :
		_11((int32_t)a._11), _12((int32_t)a._12), _13((int32_t)a._13),
		_21((int32_t)a._21), _22((int32_t)a._22), _23((int32_t)a._23),
		_31((int32_t)a._31), _32((int32_t)a._32), _33((int32_t)a._33) {}

    constexpr IntMatrix3::BasicMatrix(const IntMatrix2 &a) :
		_11(a._11), _12(a._12), _13(0),
		_21(a._21), _22(a._22), _23(0),
		_31(0), _32(0), _33(1) {}

    constexpr IntMatrix3::BasicMatrix(const IntMatrix4 &a) :
		_11(a._11), _12(a._12), _13(a._13),
		_21(a._21), _22(a._22), _23(a._23),
		_31(a._31), _32(a._32), _33(a._33) {}

    constexpr IntMatrix3 operator+(const IntMatrix3 &a, const IntMatrix3 &b)
	{
		return IntMatrix3(a.columns[0] + b.columns[0], a.columns[1] + b.columns[1], a.columns[2] + b.columns[2]);
	}

	constexpr IntMatrix3 operator-(const IntMatrix3 &a, const IntMatrix3 &b)
	{
		return IntMatrix3(a.columns[0] - b.columns[0], a.columns[1] - b.columns[1], a.columns[2] - b.columns[2]);
	}

	constexpr IntMatrix3 operator*(const IntMatrix3 &a, const IntMatrix3 &b)
	{
		return IntMatrix3(
			a._11 * b._11 + a._12 * b._21 + a._13 * b._31,
			a._11 * b._12 + a._12 * b._22 + a._13 * b._32,
			a._11 * b._13 + a._12 * b._23 + a._13 * b._33,
			a._21 * b._11 + a._22 * b._21 + a._23 * b._31,
			a._21 * b._12 + a._22 * b._22 + a._23 * b._32,
			a._21 * b._13 + a._22 * b._23 + a._23 * b._33,
			a._31 * b._11 + a._32 * b._21 + a._33 * b._31,
			a._31 * b._12 + a._32 * b._22 + a._33 * b._32,
			a._31 * b._13 + a._32 * b._23 + a._33 * b._33);
	}

	inline IntVector3 operator*(const IntMatrix3 &a, const IntVector3 &b)
	{
		return IntVector3(
			a.columns[0].x * b.x + a.columns[1].x * b.y + a.columns[2].x * b.z,
			a.columns[0].y * b.x + a.columns[1].y * b.y + a.columns[2].y * b.z,
			a.columns[0].z * b.x + a.columns[1].z * b.y + a.columns[2].z * b.z);
	}

	constexpr IntMatrix3 operator*(const IntMatrix3 &a, int32_t b)
	{
		return IntMatrix3(
			a.columns[0] * b,
			a.columns[1] * b,
			a.columns[2] * b);
	}

	constexpr IntMatrix3 operator/(const IntMatrix3 &a, int32_t b)
	{
		return IntMatrix3(
			a.columns[0] / b,
			a.columns[1] / b,
			a.columns[2] / b);
	}

	constexpr bool operator==(const IntMatrix3 &a, const IntMatrix3 &b)
	{
		return a.columns[0] == b.columns[0] && a.columns[1] == b.columns[1] && a.columns[2] == b.columns[2];
	}

    /////////////////////////////////////////////////////////////////
    // IntMatrix4

    constexpr IntMatrix4::BasicMatrix() : 
		_11(1), _12(0), _13(0), _14(0),
		_21(0), _22(1), _23(0), _24(0),
		_31(0), _32(0), _33(1), _34(0),
		_41(0), _42(0), _43(0), _44(1) {}

    constexpr IntMatrix4::BasicMatrix(int32_t diag) :
		_11(diag), _12(0), _13(0), _14(0),
		_21(0), _22(diag), _23(0), _24(0),
		_31(0), _32(0), _33(diag), _34(0),
		_41(0), _42(0), _43(0), _44(diag) {}

    constexpr IntMatrix4::BasicMatrix(const IntVector4 &col1, const IntVector4 &col2,
            const IntVector4 &col3, const IntVector4 &col4) :
		_11(col1.x), _12(col2.x), _13(col3.x), _14(col4.x),
		_21(col1.y), _22(col2.y), _23(col3.y), _24(col4.y),
		_31(col1.z), _32(col2.z), _33(col3.z), _34(col4.z),
		_41(col1.w), _42(col2.w), _43(col3.w), _44(col4.w) {}

    constexpr IntMatrix4::BasicMatrix(int32_t _11, int32_t _12, int32_t _13, int32_t _14, int32_t _21,
        int32_t _22, int32_t _23, int32_t _24,
        int32_t _31, int32_t _32, int32_t _33, int32_t _34,
        int32_t _41, int32_t _42, int32_t _43, int32_t _44) :   _11(_11), _12(_12), _13(_13), _14(_14),
                                                                _21(_21), _22(_22), _23(_23), _24(_24),
                                                                _31(_31), _32(_32), _33(_33), _34(_34),
                                                                _41(_41), _42(_42), _43(_43), _44(_44) {}

    constexpr IntMatrix4::BasicMatrix(const Matrix4 &a) :
		_11((int32_t)a._11), _12((int32_t)a._12), _13((int32_t)a._13), _14((int32_t)a._14),
		_21((int32_t)a._21), _22((int32_t)a._22), _23((int32_t)a._23), _24((int32_t)a._24),
		_31((int32_t)a._31), _32((int32_t)a._32), _33((int32_t)a._33), _34((int32_t)a._34),
		_41((int32_t)a._41), _42((int32_t)a._42), _43((int32_t)a._43), _44((int32_t)a._44) {}

    constexpr IntMatrix4::BasicMatrix(const IntMatrix2 &a) :
		_11(a._11), _12(a._12), _13(0), _14(0),
		_21(a._21), _22(a._22), _23(0), _24(0),
		_31(0), _32(0), _33(1), _34(0),
		_41(0), _42(0), _43(0), _44(1) {}

    constexpr IntMatrix4::BasicMatrix(const IntMatrix3 &a) :
		_11(a._11), _12(a._12), _13(a._13), _14(0),
		_21(a._21), _22(a._22), _23(a._23), _24(0),
		_31(a._31), _32(a._32), _33(a._33), _34(0),
		_41(0), _42(0), _43(0), _44(1) {}

    constexpr IntMatrix4 operator+(const IntMatrix4 &a, const IntMatrix4 &b)
	{
		return IntMatrix4(a.columns[0] + b.columns[0], a.columns[1] + b.columns[1],
            a.columns[2] + b.columns[2], a.columns[3] + b.columns[3]);
	}

	constexpr IntMatrix4 operator-(const IntMatrix4 &a, const IntMatrix4 &b)
	{
		return IntMatrix4(a.columns[0] - b.columns[0], a.columns[1] - b.columns[1],
            a.columns[2] - b.columns[2], a.columns[3] - b.columns[3]);
	}

	constexpr IntMatrix4 operator*(const IntMatrix4 &a, const IntMatrix4 &b)
	{
		return IntMatrix4(
			IntVector4(
				(a.columns[0].x * b.columns[0].x) + (a.columns[1].x * b.columns[0].y) + (a.columns[2].x * b.columns[0].z) + (a.columns[3].x * b.columns[0].w),
				(a.columns[0].y * b.columns[0].x) + (a.columns[1].y * b.columns[0].y) + (a.columns[2].y * b.columns[0].z) + (a.columns[3].y * b.columns[0].w),
				(a.columns[0].z * b.columns[0].x) + (a.columns[1].z * b.columns[0].y) + (a.columns[2].z * b.columns[0].z) + (a.columns[3].z * b.columns[0].w),
				(a.columns[0].w * b.columns[0].x) + (a.columns[1].w * b.columns[0].y) + (a.columns[2].w * b.columns[0].z) + (a.columns[3].w * b.columns[0].w)),
			IntVector4(
				(a.columns[0].x * b.columns[1].x) + (a.columns[1].x * b.columns[1].y) + (a.columns[2].x * b.columns[1].z) + (a.columns[3].x * b.columns[1].w),
				(a.columns[0].y * b.columns[1].x) + (a.columns[1].y * b.columns[1].y) + (a.columns[2].y * b.columns[1].z) + (a.columns[3].y * b.columns[1].w),
				(a.columns[0].z * b.columns[1].x) + (a.columns[1].z * b.columns[1].y) + (a.columns[2].z * b.columns[1].z) + (a.columns[3].z * b.columns[1].w),
				(a.columns[0].w * b.columns[1].x) + (a.columns[1].w * b.columns[1].y) + (a.columns[2].w * b.columns[1].z) + (a.columns[3].w * b.columns[1].w)),
			IntVector4(
				(a.columns[0].x * b.columns[2].x) + (a.columns[1].x * b.columns[2].y) + (a.columns[2].x * b.columns[2].z) + (a.columns[3].x * b.columns[2].w),
				(a.columns[0].y * b.columns[2].x) + (a.columns[1].y * b.columns[2].y) + (a.columns[2].y * b.columns[2].z) + (a.columns[3].y * b.columns[2].w),
				(a.columns[0].z * b.columns[2].x) + (a.columns[1].z * b.columns[2].y) + (a.columns[2].z * b.columns[2].z) + (a.columns[3].z * b.columns[2].w),
				(a.columns[0].w * b.columns[2].x) + (a.columns[1].w * b.columns[2].y) + (a.columns[2].w * b.columns[2].z) + (a.columns[3].w * b.columns[2].w)),
			IntVector4(
				(a.columns[0].x * b.columns[3].x) + (a.columns[1].x * b.columns[3].y) + (a.columns[2].x * b.columns[3].z) + (a.columns[3].x * b.columns[3].w),
				(a.columns[0].y * b.columns[3].x) + (a.columns[1].y * b.columns[3].y) + (a.columns[2].y * b.columns[3].z) + (a.columns[3].y * b.columns[3].w),
				(a.columns[0].z * b.columns[3].x) + (a.columns[1].z * b.columns[3].y) + (a.columns[2].z * b.columns[3].z) + (a.columns[3].z * b.columns[3].w),
				(a.columns[0].w * b.columns[3].x) + (a.columns[1].w * b.columns[3].y) + (a.columns[2].w * b.columns[3].z) + (a.columns[3].w * b.columns[3].w)));
	}

	constexpr IntVector4 operator*(const IntMatrix4 &a, const IntVector4 &b)
	{
		return IntVector4(
			a.columns[0].x * b.x + a.columns[1].x * b.y + a.columns[2].x * b.z + a.columns[3].x * b.w,
			a.columns[0].y * b.x + a.columns[1].y * b.y + a.columns[2].y * b.z + a.columns[3].y * b.w,
			a.columns[0].z * b.x + a.columns[1].z * b.y + a.columns[2].z * b.z + a.columns[3].z * b.w,
			a.columns[0].w * b.x + a.columns[1].w * b.y + a.columns[2].w * b.z + a.columns[3].w * b.w);
	}

	constexpr IntMatrix4 operator*(const IntMatrix4 &a, int32_t b)
	{
		return IntMatrix4(
			a.columns[0] * b,
			a.columns[1] * b,
			a.columns[2] * b,
			a.columns[3] * b);
	}

	constexpr IntMatrix4 operator/(const IntMatrix4 &a, int32_t b)
	{
		return IntMatrix4(
			a.columns[0] / b,
			a.columns[1] / b,
			a.columns[2] / b,
			a.columns[3] / b);
	}

	constexpr bool operator==(const IntMatrix4 &a, const IntMatrix4 &b)
	{
		return a.columns[0] == b.columns[0] && a.columns[1] == b.columns[1] && a.columns[2] == b.columns[2] && a.columns[3] == b.columns[3];
	}
}
