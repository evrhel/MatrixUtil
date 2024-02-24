#pragma once

#include "vec_types.h"

namespace mutil
{
	template <>
    class BasicVector<float, 2>
	{
	public:
		union
		{
			struct { float x, y; };
			struct { float r, g; };
			struct { float s, t; };
			float vec[2];
		};

		constexpr BasicVector();
		explicit constexpr BasicVector(float a);
		constexpr BasicVector(float x, float y);
		explicit constexpr BasicVector(const IntVector2 &a);
		explicit constexpr BasicVector(const Vector3 &a);
		explicit constexpr BasicVector(const Vector4 &a);

		constexpr Vector2 &operator+=(const Vector2 &a);
		constexpr Vector2 &operator-=(const Vector2 &a);
		constexpr Vector2 &operator*=(const Vector2 &a);
		constexpr Vector2 &operator*=(float a);
		constexpr Vector2 &operator/=(const Vector2 &a);
		constexpr Vector2 &operator/=(float a);

		constexpr const float &operator[](size_t i) const;
		constexpr float &operator[](size_t i);

		MUTIL_FORCEINLINE float MUTIL_VECTORCALL length() const;
		MUTIL_FORCEINLINE float MUTIL_VECTORCALL lengthSq() const;
		MUTIL_FORCEINLINE Vector2 MUTIL_VECTORCALL normalized() const;
	};

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL dot(const Vector2 &a, const Vector2 &b);
	MUTIL_FORCEINLINE float MUTIL_VECTORCALL length(const Vector2 &a);
	MUTIL_FORCEINLINE float MUTIL_VECTORCALL lengthSq(const Vector2 &a);
	MUTIL_FORCEINLINE float MUTIL_VECTORCALL distance(const Vector2 &a, const Vector2 &b);
	MUTIL_FORCEINLINE Vector2 MUTIL_VECTORCALL normalize(const Vector2 &a);
	MUTIL_FORCEINLINE Vector2 MUTIL_VECTORCALL reflect(const Vector2 &a, const Vector2 &N);
}