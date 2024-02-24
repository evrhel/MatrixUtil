#pragma once

#include "vec_types.h"

namespace mutil
{
	template <>
	class BasicVector<float, 4>
	{
	public:
		union
		{
			struct { float x, y, z, w; };
			struct { float r, g, b, a; };
			struct { float s, t, p, q; };
			float vec[4];
		};

		constexpr BasicVector();
		explicit constexpr BasicVector(float a);
		constexpr BasicVector(float x, float y, float z, float w);
		explicit constexpr BasicVector(const IntVector4 &vec);

		constexpr BasicVector(const Vector2 &xy, float z, float w);
		constexpr BasicVector(const Vector3 &xyz, float w);
		constexpr BasicVector(const Vector2 &xy, const Vector2 &zw);
		constexpr BasicVector(float x, const Vector3 &yzw);
		constexpr BasicVector(float x, float y, const Vector2 &zw);
		constexpr BasicVector(float x, const Vector2 &yz, float w);
		explicit constexpr BasicVector(const Vector2 &a);
		explicit constexpr BasicVector(const Vector3 &a);

		constexpr Vector4 &operator+=(const Vector4 &a);
		constexpr Vector4 &operator-=(const Vector4 &a);
		constexpr Vector4 &operator*=(const Vector4 &a);
		constexpr Vector4 &operator*=(float a);
		constexpr Vector4 &operator/=(const Vector4 &a);
		constexpr Vector4 &operator/=(float a);

		constexpr const float &operator[](size_t i) const;
		constexpr float &operator[](size_t i);

		MUTIL_FORCEINLINE float MUTIL_VECTORCALL length() const;
		MUTIL_FORCEINLINE float MUTIL_VECTORCALL lengthSq() const;
		MUTIL_FORCEINLINE Vector4 MUTIL_VECTORCALL normalized() const;
	};

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL dot(const Vector4 &a, const Vector4 &b);
	MUTIL_FORCEINLINE float MUTIL_VECTORCALL length(const Vector4 &a);
	MUTIL_FORCEINLINE float MUTIL_VECTORCALL lengthSq(const Vector4 &a);
	MUTIL_FORCEINLINE float MUTIL_VECTORCALL distance(const Vector4 &a, const Vector4 &b);
	MUTIL_FORCEINLINE Vector4 MUTIL_VECTORCALL normalize(const Vector4 &a);
	MUTIL_FORCEINLINE Vector4 MUTIL_VECTORCALL reflect(const Vector4 &a, const Vector4 &N);
}
