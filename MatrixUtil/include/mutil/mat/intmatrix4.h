#pragma once

#include "mat_types.h"

namespace mutil
{
	template <>
    class BasicMatrix<int32_t, 4, 4>
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

		constexpr BasicMatrix();
		explicit constexpr BasicMatrix(int32_t diag);
		explicit constexpr BasicMatrix(const IntVector4 &col1, const IntVector4 &col2, const IntVector4 &col3, const IntVector4 &col4);
		explicit constexpr BasicMatrix(
			int32_t _11, int32_t _12, int32_t _13, int32_t _14,
			int32_t _21, int32_t _22, int32_t _23, int32_t _24,
			int32_t _31, int32_t _32, int32_t _33, int32_t _34,
			int32_t _41, int32_t _42, int32_t _43, int32_t _44);
		explicit constexpr BasicMatrix(const Matrix4 &a);
		explicit constexpr BasicMatrix(const IntMatrix2 &a);
		explicit constexpr BasicMatrix(const IntMatrix3 &a);

		constexpr const int32_t &operator[](size_t i) const { return mat[i]; }
		constexpr int32_t &operator[](size_t i) { return mat[i]; }
	};

	constexpr IntMatrix4 operator+(const IntMatrix4 &a, const IntMatrix4 &b);
	constexpr IntMatrix4 operator-(const IntMatrix4 &a, const IntMatrix4 &b);
	constexpr IntMatrix4 operator*(const IntMatrix4 &a, const IntMatrix4 &b);
	constexpr IntVector4 operator*(const IntMatrix4 &a, const IntVector4 &b);
	constexpr IntMatrix4 operator*(const IntMatrix4 &a, int32_t b);
	constexpr IntMatrix4 operator/(const IntMatrix4 &a, int32_t b);
	constexpr bool operator==(const IntMatrix4 &a, const IntMatrix4 &b);
}
