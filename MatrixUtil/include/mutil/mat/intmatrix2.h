#pragma once

#include "mat_types.h"

namespace mutil
{
    class IntMatrix2
	{
	public:
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

		constexpr IntMatrix2() : IntMatrix2(1) {}
		explicit constexpr IntMatrix2(const int32_t diagonal) : _11(diagonal), _12(0),
																_21(0), _22(diagonal) {}
		explicit constexpr IntMatrix2(const IntVector2 &column1, const IntVector2 &column2) : _11(column1.x), _12(column2.x),
																							  _21(column1.y), _22(column2.y) {}

		explicit constexpr IntMatrix2(
			int32_t _11, int32_t _12,
			int32_t _21, int32_t _22) : _11(_11), _12(_12),
										_21(_21), _22(_22) {}
		explicit constexpr IntMatrix2(const Matrix2 &mat);
		explicit constexpr IntMatrix2(const IntMatrix3 &mat);
		explicit constexpr IntMatrix2(const IntMatrix4 &mat);

		constexpr const int32_t &operator[](size_t index) const { return mat[index]; }
		constexpr int32_t &operator[](size_t index) { return mat[index]; }
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

}
