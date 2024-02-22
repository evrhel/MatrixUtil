#pragma once

#include <cstdint>
#include <cstdlib>

#include "../settings.h"

namespace mutil
{
	template <typename T, size_t N>
	class BasicVector
	{
	public:
		T vec[N];

		constexpr BasicVector()
		{
			for (size_t i = 0; i < N; i++)
				vec[i] = T();
		}

		constexpr BasicVector(T a)
		{
			for (size_t i = 0; i < N; i++)
				vec[i] = a;
		}

		constexpr BasicVector(const BasicVector<T, N> &a)
		{
			for (size_t i = 0; i < N; i++)
				vec[i] = a.vec[i];
		}

		constexpr const T &operator[](size_t i) const { return vec[i]; }
		constexpr T &operator[](size_t i) { return vec[i]; }
	};

	template <size_t N>
	using Vector = BasicVector<float, N>;

	template <size_t N>
	using IntVector = BasicVector<int32_t, N>;

	using Vector2 = Vector<2>;
	using Vector3 = Vector<3>;
	using Vector4 = Vector<4>;

	using IntVector2 = IntVector<2>;
	using IntVector3 = IntVector<3>;
	using IntVector4 = IntVector<4>;

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator+(const BasicVector<T, N> &a, const BasicVector<T, N> &b);

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator-(const BasicVector<T, N> &a, const BasicVector<T, N> &b);

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator*(const BasicVector<T, N> &a, const BasicVector<T, N> &b);

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator*(const BasicVector<T, N> &a, T b);

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator*(T a, const BasicVector<T, N> &b);

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator/(const BasicVector<T, N> &a, const BasicVector<T, N> &b);

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator/(const BasicVector<T, N> &a, T b);

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator-(const BasicVector<T, N> &a);

	template <typename T, size_t N>
	constexpr bool operator==(const BasicVector<T, N> &a, const BasicVector<T, N> &b);

	template <typename T, size_t N>
	constexpr bool operator!=(const BasicVector<T, N> &a, const BasicVector<T, N> &b);

	template <typename T, size_t N>
	constexpr BasicVector<T, N> dot(const BasicVector<T, N> &a, const BasicVector<T, N> &b);

	template <size_t N>
	constexpr Vector<N> normalize(const Vector<N> &a);

	template <typename T, size_t N>
	constexpr BasicVector<T, N> abs(const BasicVector<T, N> &a);

	template <size_t N>
	MUTIL_FORCEINLINE Vector<N> MUTIL_VECTORCALL fract(const Vector<N> &a);

	template <size_t N>
	MUTIL_FORCEINLINE Vector<N> MUTIL_VECTORCALL mod(const Vector<N> &a, float b);

	template <size_t N>
	MUTIL_FORCEINLINE Vector<N> MUTIL_VECTORCALL mod(const Vector<N> &a, const Vector<N> &b);

	template <size_t N>
	constexpr IntVector<N> mod(const IntVector<N> &a, int32_t b);

	template <size_t N>
	constexpr IntVector<N> mod(const IntVector<N> &a, const IntVector<N> &b);

	template <typename T, size_t N>
	constexpr BasicVector<T, N> clamp(const BasicVector<T, N> &a, T min, T max);

	template <typename T, size_t N>
	constexpr BasicVector<T, N> clamp(const BasicVector<T, N> &a, const BasicVector<T, N> &min, const BasicVector<T, N> &max);

	template <size_t N>
	constexpr Vector<N> lerp(const Vector<N> &a, const Vector<N> &b, float t);

	template <size_t N>
	constexpr Vector<N> lerp(const Vector<N> &a, const Vector<N> &b, const Vector<N> &t);

	template <size_t N>
	constexpr Vector<N> smoothstep(const Vector<N> &a, const Vector<N> &b, float t);

	template <size_t N>
	constexpr Vector<N> smoothstep(const Vector<N> &a, const Vector<N> &b, const Vector<N> &t);

	template <size_t N>
	constexpr Vector<N> smootherstep(const Vector<N> &a, const Vector<N> &b, float t);

	template <size_t N>
	constexpr Vector<N> smootherstep(const Vector<N> &a, const Vector<N> &b, const Vector<N> &t);
}
