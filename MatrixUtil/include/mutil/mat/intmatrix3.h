#pragma once

#include "mat_types.h"

namespace mutil
{
	template <>
    class BasicMatrix<int32_t, 3, 3>
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

		constexpr BasicMatrix();
		explicit constexpr BasicMatrix(int32_t diag);
		explicit constexpr BasicMatrix(const IntVector3 &col1, const IntVector3 &col2,
			const IntVector3 &col3);
		explicit constexpr BasicMatrix(
			int32_t _11, int32_t _12, int32_t _13,
			int32_t _21, int32_t _22, int32_t _23,
			int32_t _31, int32_t _32, int32_t _33);
		explicit constexpr BasicMatrix(const Matrix3 &a);
		explicit constexpr BasicMatrix(const IntMatrix2 &a);
		explicit constexpr BasicMatrix(const IntMatrix4 &a);

		constexpr const int32_t &operator[](size_t i) const { return mat[i]; }
		constexpr int32_t &operator[](size_t i) { return mat[i]; }
	};

	constexpr IntMatrix3 operator+(const IntMatrix3 &a, const IntMatrix3 &b);
	constexpr IntMatrix3 operator-(const IntMatrix3 &a, const IntMatrix3 &b);
	constexpr IntMatrix3 operator*(const IntMatrix3 &a, const IntMatrix3 &b);
	inline IntVector3 operator*(const IntMatrix3 &a, const IntVector3 &b);
	constexpr IntMatrix3 operator*(const IntMatrix3 &a, int32_t b);
	constexpr IntMatrix3 operator/(const IntMatrix3 &a, int32_t b);
	constexpr bool operator==(const IntMatrix3 &a, const IntMatrix3 &b);
}
