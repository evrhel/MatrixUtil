#pragma once

#include "vec_types.h"

namespace mutil
{
	template <>
	class BasicVector<int32_t, 2>
	{
	public:
		union
		{
			struct { int32_t x, y; };
			struct { int32_t r, g; };
			struct { int32_t s, t; };
			int32_t vec[2];
		};

		constexpr BasicVector();
		explicit constexpr BasicVector(const int32_t a);
		constexpr BasicVector(int32_t x, int32_t y);
		explicit constexpr BasicVector(const Vector2 &a);
		explicit constexpr BasicVector(const IntVector3 &a);
		explicit constexpr BasicVector(const IntVector4 &a);

		constexpr IntVector2 &operator+=(const IntVector2 &a);
		constexpr IntVector2 &operator-=(const IntVector2 &a);
		constexpr IntVector2 &operator*=(const IntVector2 &a);
		constexpr IntVector2 &operator*=(int32_t a);
		constexpr IntVector2 &operator/=(const IntVector2 &a);
		constexpr IntVector2 &operator/=(int32_t a);

		constexpr const int32_t &operator[](size_t i) const;
		constexpr int32_t &operator[](size_t i);
	};

	constexpr int32_t dot(const IntVector2 &a, const IntVector2 &b);
}
