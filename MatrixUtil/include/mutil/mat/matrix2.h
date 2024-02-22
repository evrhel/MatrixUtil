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
		explicit constexpr BasicMatrix(float diagonal);
		explicit constexpr BasicMatrix(const Vector2 &col1, const Vector2 &col2);
		explicit constexpr BasicMatrix(float _11, float _12, float _21, float _22);
		explicit constexpr BasicMatrix(const IntMatrix2 &mat);
		explicit constexpr BasicMatrix(const Matrix3 &mat);
		explicit constexpr BasicMatrix(const Matrix4 &mat);

		constexpr const float &operator[](size_t index) const { return mat[index]; }
		constexpr float &operator[](size_t index) { return mat[index]; }

		constexpr float determinant() const;
		constexpr Matrix2 transpose() const;
		constexpr Matrix2 inverse() const;
	};

	constexpr Matrix2 operator+(const Matrix2 &first, const Matrix2 &second);
	constexpr Matrix2 operator-(const Matrix2 &first, const Matrix2 &second);
	constexpr Matrix2 operator*(const Matrix2 &first, const Matrix2 &second);
	constexpr Vector2 operator*(const Matrix2 &first, const Vector2 &second);
	constexpr Matrix2 operator*(const Matrix2 &first, float second);
	constexpr Matrix2 operator/(const Matrix2 &first, float second);
	constexpr bool operator==(const Matrix2 &first, const Matrix2 &second);
}
