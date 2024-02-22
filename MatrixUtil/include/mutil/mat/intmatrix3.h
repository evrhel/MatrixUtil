#pragma once

#include "mat_types.h"

namespace mutil
{
    class IntMatrix3
	{
	public:
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

		constexpr IntMatrix3() : IntMatrix3(1) {}
		explicit constexpr IntMatrix3(const int32_t diagonal) : _11(diagonal), _12(0), _13(0),
																_21(0), _22(diagonal), _23(0),
																_31(0), _32(0), _33(diagonal) {}
		explicit constexpr IntMatrix3(const IntVector3 &column1, const IntVector3 &column2, const IntVector3 &column3) : _11(column1.x), _12(column2.x), _13(column3.x),
																														 _21(column1.y), _22(column2.y), _23(column3.y),
																														 _31(column1.z), _32(column2.z), _33(column3.z) {}
		explicit constexpr IntMatrix3(
			int32_t _11, int32_t _12, int32_t _13,
			int32_t _21, int32_t _22, int32_t _23,
			int32_t _31, int32_t _32, int32_t _33) : _11(_11), _12(_12), _13(_13),
													 _21(_21), _22(_22), _23(_23),
													 _31(_31), _32(_32), _33(_33) {}
		explicit constexpr IntMatrix3(const Matrix3 &mat);
		explicit constexpr IntMatrix3(const IntMatrix2 &mat);
		explicit constexpr IntMatrix3(const IntMatrix4 &mat);

		constexpr const int32_t &operator[](size_t index) const { return mat[index]; }
		constexpr int32_t &operator[](size_t index) { return mat[index]; }
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
}
