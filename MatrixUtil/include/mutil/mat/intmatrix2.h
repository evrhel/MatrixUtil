#pragma once

#include "mat_types.h"

namespace mutil
{
	template <>
    class BasicMatrix<int32_t, 2, 2>
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

		constexpr BasicMatrix();
		explicit constexpr BasicMatrix(int32_t diag);
		explicit constexpr BasicMatrix(const IntVector2 &col1, const IntVector2 &col2);
		explicit constexpr BasicMatrix(int32_t _11, int32_t _12, int32_t _21, int32_t _22);
		explicit constexpr BasicMatrix(const Matrix2 &mat);
		explicit constexpr BasicMatrix(const IntMatrix3 &mat);
		explicit constexpr BasicMatrix(const IntMatrix4 &mat);

		constexpr const int32_t &operator[](size_t i) const { return mat[i]; }
		constexpr int32_t &operator[](size_t i) { return mat[i]; }
	};

	constexpr IntMatrix2 operator+(const IntMatrix2 &a, const IntMatrix2 &b);
	constexpr IntMatrix2 operator-(const IntMatrix2 &a, const IntMatrix2 &b);
	constexpr IntMatrix2 operator*(const IntMatrix2 &a, const IntMatrix2 &b);
	constexpr IntVector2 operator*(const IntMatrix2 &a, const IntVector2 &b);
	constexpr IntMatrix2 operator*(const IntMatrix2 &a, int32_t b);
	constexpr IntMatrix2 operator/(const IntMatrix2 &a, int32_t b);
	constexpr bool operator==(const IntMatrix2 &a, const IntMatrix2 &b);
}
