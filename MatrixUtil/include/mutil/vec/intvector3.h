#pragma once

#include "vec_types.h"

namespace mutil
{
	template <>
	class BasicVector<int32_t, 3>
	{
	public:
		union
		{
			struct { int32_t x, y, z; };
			struct { int32_t r, g, b; };
			struct { int32_t s, t, p; };
			int32_t vec[3];
		};

		constexpr BasicVector();
		explicit constexpr BasicVector(const int32_t a);
		constexpr BasicVector(int32_t x, int32_t y, int32_t z);
		explicit constexpr BasicVector(const Vector3 &a);

		constexpr BasicVector(const IntVector2 &xy, int32_t z);
		constexpr BasicVector(int32_t x, const IntVector2 &yz);
		explicit constexpr BasicVector(const IntVector2 &a);
		explicit constexpr BasicVector(const IntVector4 &a);

		constexpr IntVector3 &operator+=(const IntVector3 &a);
		constexpr IntVector3 &operator-=(const IntVector3 &a);
		constexpr IntVector3 &operator*=(const IntVector3 &a);
		constexpr IntVector3 &operator*=(int32_t a);
		constexpr IntVector3 &operator/=(const IntVector3 &a);
		constexpr IntVector3 &operator/=(int32_t a);

		constexpr const int32_t &operator[](size_t i) const;
		constexpr int32_t &operator[](size_t i);
	};

	constexpr int32_t dot(const IntVector3 &a, const IntVector3 &b);
	constexpr IntVector3 cross(const IntVector3 &a, const IntVector3 &b);
}
