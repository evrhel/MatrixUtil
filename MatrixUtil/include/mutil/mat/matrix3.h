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
		explicit constexpr BasicMatrix(const Vector3 &column1, const Vector3 &column2, const Vector3 &column3);
		explicit constexpr BasicMatrix(float _11, float _12, float _13, float _21, float _22, float _23, float _31, float _32, float _33);
		explicit constexpr BasicMatrix(const IntMatrix3 &mat);
		explicit constexpr BasicMatrix(const Matrix2 &mat);
		explicit constexpr BasicMatrix(const Matrix4 &mat);

		constexpr const float &operator[](size_t index) const { return mat[index]; }
		constexpr float &operator[](size_t index) { return mat[index]; }

		constexpr float determinant() const;
		constexpr Matrix3 transpose() const;
		constexpr Matrix3 inverse() const;
	};

	constexpr Matrix3 operator+(const Matrix3 &first, const Matrix3 &second);
	constexpr Matrix3 operator-(const Matrix3 &first, const Matrix3 &second);
	constexpr Matrix3 operator*(const Matrix3 &first, const Matrix3 &second);
	constexpr Vector3 operator*(const Matrix3 &first, const Vector3 &second);
	constexpr Matrix3 operator*(const Matrix3 &first, float second);
	constexpr Matrix3 operator/(const Matrix3 &first, float second);
	constexpr bool operator==(const Matrix3 &first, const Matrix3 &second);
}
