#pragma once

#include "vec_types.h"

namespace mutil
{
	template <>
	class BasicVector<int32_t, 4>
	{
	public:
		union
		{
			struct { int32_t x, y, z, w; };
			struct { int32_t r, g, b, a; };
			struct { int32_t s, t, p, q; };
			int32_t vec[4];
		};

		constexpr BasicVector();
		explicit constexpr BasicVector(int32_t a);
		constexpr BasicVector(int32_t x, int32_t y, int32_t z, int32_t w);
		explicit constexpr BasicVector(const Vector4 &a);

		constexpr BasicVector(const IntVector2 &xy, int32_t z, int32_t w);
		constexpr BasicVector(const IntVector3 &xyz, int32_t w);
		constexpr BasicVector(const IntVector2 &xy, const IntVector2 &zw);
		constexpr BasicVector(int32_t x, const IntVector3 &yzw);
		constexpr BasicVector(int32_t x, int32_t y, const IntVector2 &zw);
		constexpr BasicVector(int32_t x, const IntVector2 &yz, int32_t w);
		explicit constexpr BasicVector(const IntVector2 &a);
		explicit constexpr BasicVector(const IntVector3 &a);

		constexpr IntVector4 &operator+=(const IntVector4 &a);
		constexpr IntVector4 &operator-=(const IntVector4 &a);
		constexpr IntVector4 &operator*=(const IntVector4 &a);
		constexpr IntVector4 &operator*=(int32_t a);
		constexpr IntVector4 &operator/=(const IntVector4 &a);
		constexpr IntVector4 &operator/=(int32_t a);

		constexpr const int32_t &operator[](size_t i) const;
		constexpr int32_t &operator[](size_t i);
	};

	constexpr int32_t dot(const IntVector4 &a, const IntVector4 &b);
}
