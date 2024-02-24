#pragma once

#include "mat_types.h"

namespace mutil
{
	template <>
    class BasicMatrix<float, 4, 4>
	{
	public:
		union
		{
			Vector4 columns[4];
			struct
			{
				float _11, _21, _31, _41;
				float _12, _22, _32, _42;
				float _13, _23, _33, _43;
				float _14, _24, _34, _44;
			};
			float mat[16];
		};

		constexpr BasicMatrix();
		explicit constexpr BasicMatrix(float diagonal);
		explicit constexpr BasicMatrix(const Vector4 &col1, const Vector4 &col2,
				const Vector4 &col3, const Vector4 &col4);
		explicit constexpr BasicMatrix(
			float _11, float _12, float _13, float _14,
			float _21, float _22, float _23, float _24,
			float _31, float _32, float _33, float _34,
			float _41, float _42, float _43, float _44);
		explicit constexpr BasicMatrix(const IntMatrix4 &a);
		explicit constexpr BasicMatrix(const Matrix2 &a);
		explicit constexpr BasicMatrix(const Matrix3 &a);

		constexpr const float &operator[](size_t i) const { return mat[i]; }
		constexpr float &operator[](size_t i) { return mat[i]; }

		constexpr float determinant() const;
		constexpr Matrix4 transpose() const;
		constexpr Matrix4 inverse() const;
	};

	constexpr Matrix4 operator+(const Matrix4 &a, const Matrix4 &b);
	constexpr Matrix4 operator-(const Matrix4 &a, const Matrix4 &b);
	inline Matrix4 MUTIL_VECTORCALL operator*(const Matrix4 &a, const Matrix4 &b);
	constexpr Vector4 operator*(const Matrix4 &a, const Vector4 &b);
	constexpr Matrix4 operator*(const Matrix4 &a, float b);
	constexpr Matrix4 operator/(const Matrix4 &a, float b);
	constexpr bool operator==(const Matrix4 &a, const Matrix4 &b);
}
