#pragma once

#include "mat_types.h"

namespace mutil
{
	template <>
    class BasicMatrix<float, 2, 2>
	{
	public:
		union
		{
			Vector2 columns[2];
			struct
			{
				float _11, _21;
				float _12, _22;
			};
			float mat[4];
		};

	
		constexpr BasicMatrix();
		explicit constexpr BasicMatrix(float diag);
		explicit constexpr BasicMatrix(const Vector2 &col1, const Vector2 &col2);
		explicit constexpr BasicMatrix(float _11, float _12, float _21, float _22);
		explicit constexpr BasicMatrix(const IntMatrix2 &a);
		explicit constexpr BasicMatrix(const Matrix3 &a);
		explicit constexpr BasicMatrix(const Matrix4 &a);

		constexpr const float &operator[](size_t i) const { return mat[i]; }
		constexpr float &operator[](size_t i) { return mat[i]; }

		constexpr float determinant() const;
		constexpr Matrix2 transpose() const;
		constexpr Matrix2 inverse() const;
	};

	constexpr Matrix2 operator+(const Matrix2 &a, const Matrix2 &b);
	constexpr Matrix2 operator-(const Matrix2 &a, const Matrix2 &b);
	constexpr Matrix2 operator*(const Matrix2 &a, const Matrix2 &b);
	constexpr Vector2 operator*(const Matrix2 &a, const Vector2 &b);
	constexpr Matrix2 operator*(const Matrix2 &a, float b);
	constexpr Matrix2 operator/(const Matrix2 &a, float b);
	constexpr bool operator==(const Matrix2 &a, const Matrix2 &b);
}
