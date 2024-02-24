#pragma once

#include "mat_types.h"

namespace mutil
{
	template <>
    class BasicMatrix<float, 3, 3>
	{
	public:
		union
		{
			Vector3 columns[3];
			struct
			{
				float _11, _21, _31;
				float _12, _22, _32;
				float _13, _23, _33;
			};
			float mat[9];
		};

		constexpr BasicMatrix();
		explicit constexpr BasicMatrix(const float diagonal);
		explicit constexpr BasicMatrix(const Vector3 &col1, const Vector3 &col2, const Vector3 &col3);
		explicit constexpr BasicMatrix(float _11, float _12, float _13,
				float _21,float _22, float _23,
				float _31, float _32, float _33);
		explicit constexpr BasicMatrix(const IntMatrix3 &a);
		explicit constexpr BasicMatrix(const Matrix2 &a);
		explicit constexpr BasicMatrix(const Matrix4 &a);

		constexpr const float &operator[](size_t i) const { return mat[i]; }
		constexpr float &operator[](size_t i) { return mat[i]; }

		constexpr float determinant() const;
		constexpr Matrix3 transpose() const;
		constexpr Matrix3 inverse() const;
	};

	constexpr Matrix3 operator+(const Matrix3 &a, const Matrix3 &b);
	constexpr Matrix3 operator-(const Matrix3 &a, const Matrix3 &b);
	constexpr Matrix3 operator*(const Matrix3 &a, const Matrix3 &b);
	constexpr Vector3 operator*(const Matrix3 &a, const Vector3 &b);
	constexpr Matrix3 operator*(const Matrix3 &a, float b);
	constexpr Matrix3 operator/(const Matrix3 &a, float b);
	constexpr bool operator==(const Matrix3 &a, const Matrix3 &b);
}
