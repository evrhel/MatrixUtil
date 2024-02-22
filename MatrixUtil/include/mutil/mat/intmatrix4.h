#pragma once

#include "mat_types.h"

namespace mutil
{
    class IntMatrix4
	{
	public:
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

		constexpr IntMatrix4() : IntMatrix4(1) {}
		explicit constexpr IntMatrix4(const int32_t diagonal) : _11(diagonal), _12(0), _13(0), _14(0),
																_21(0), _22(diagonal), _23(0), _24(0),
																_31(0), _32(0), _33(diagonal), _34(0),
																_41(0), _42(0), _43(0), _44(diagonal) {}
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
		explicit constexpr IntMatrix4(const Matrix4 &mat);
		explicit constexpr IntMatrix4(const IntMatrix2 &mat);
		explicit constexpr IntMatrix4(const IntMatrix3 &mat);

		constexpr const int32_t &operator[](size_t index) const { return mat[index]; }
		constexpr int32_t &operator[](size_t index) { return mat[index]; }
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
