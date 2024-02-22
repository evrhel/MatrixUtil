#pragma once

#include "vec_types.h"

namespace mutil
{
	template <>
    class BasicVector<float, 3>
	{
	public:
		union
		{
			struct { float x, y, z; };
			struct { float r, g, b; };
			struct { float s, t, p; };
			float vec[3];
		};

		constexpr BasicVector();
		explicit constexpr BasicVector(float a);
		constexpr BasicVector(float x, float y, float z);
		explicit constexpr BasicVector(const IntVector3 &a);

		constexpr BasicVector(const Vector2 &xy, float z);
		constexpr BasicVector(float x, const Vector2 &yz);
		explicit constexpr BasicVector(const Vector2 &xy);
		explicit constexpr BasicVector(const Vector4 &a);

		constexpr Vector3 &operator+=(const Vector3 &a);
		constexpr Vector3 &operator-=(const Vector3 &a);
		constexpr Vector3 &operator*=(const Vector3 &a);
		constexpr Vector3 &operator*=(float a);
		constexpr Vector3 &operator/=(const Vector3 &a);
		constexpr Vector3 &operator/=(float a);

		constexpr const float &operator[](size_t i) const;
		constexpr float &operator[](size_t i);

		MUTIL_FORCEINLINE float MUTIL_VECTORCALL length() const;
		MUTIL_FORCEINLINE float MUTIL_VECTORCALL lengthSq() const;
		MUTIL_FORCEINLINE Vector3 MUTIL_VECTORCALL normalized() const;
	};

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL dot(const Vector3 &a, const Vector3 &b);
	constexpr Vector3 cross(const Vector3 &a, const Vector3 &b);
	MUTIL_FORCEINLINE float MUTIL_VECTORCALL length(const Vector3 &a);
	MUTIL_FORCEINLINE float MUTIL_VECTORCALL lengthSq(const Vector3 &a);
	MUTIL_FORCEINLINE float MUTIL_VECTORCALL distance(const Vector3 &a, const Vector3 &b);
	MUTIL_FORCEINLINE Vector3 MUTIL_VECTORCALL normalize(const Vector3 &a);
	MUTIL_FORCEINLINE Vector3 MUTIL_VECTORCALL reflect(const Vector3 &a, const Vector3 &N);
}