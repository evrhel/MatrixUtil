#pragma once

#include <cstdint>
#include <cstdlib>

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

		constexpr const T &operator[](size_t i) const
		{
			return vec[i];
		}

		constexpr T &operator[](size_t i)
		{
			return vec[i];
		}
	};

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
	constexpr BasicVector<T, N> abs(const BasicVector<T, N> &a);

	template <size_t N>
	MUTIL_FORCEINLINE BasicVector<float, N> MUTIL_VECTORCALL fract(const BasicVector<float, N> &a);

	template <size_t N>
	MUTIL_FORCEINLINE BasicVector<float, N> MUTIL_VECTORCALL mod(const BasicVector<float, N> &a, float b);

	template <size_t N>
	MUTIL_FORCEINLINE BasicVector<float, N> MUTIL_VECTORCALL mod(const BasicVector<float, N> &a, const BasicVector<float, N> &b);

	template <size_t N>
	constexpr BasicVector<int32_t, N> mod(const BasicVector<int32_t, N> &a, int32_t b);

	template <size_t N>
	constexpr BasicVector<int32_t, N> mod(const BasicVector<int32_t, N> &a, const BasicVector<int32_t, N> &b);

	template <typename T, size_t N>
	constexpr BasicVector<T, N> clamp(const BasicVector<T, N> &a, T min, T max);

	template <typename T, size_t N>
	constexpr BasicVector<T, N> clamp(const BasicVector<T, N> &a, const BasicVector<T, N> &min, const BasicVector<T, N> &max);

	template <size_t N>
	constexpr BasicVector<float, N> lerp(const BasicVector<float, N> &a, const BasicVector<float, N> &b, float t);

	template <size_t N>
	constexpr BasicVector<float, N> lerp(const BasicVector<float, N> &a, const BasicVector<float, N> &b, const BasicVector<float, N> &t);

	template <size_t N>
	constexpr BasicVector<float, N> smoothstep(const BasicVector<float, N> &a, const BasicVector<float, N> &b, float t);

	template <size_t N>
	constexpr BasicVector<float, N> smoothstep(const BasicVector<float, N> &a, const BasicVector<float, N> &b, const BasicVector<float, N> &t);

	template <size_t N>
	constexpr BasicVector<float, N> smootherstep(const BasicVector<float, N> &a, const BasicVector<float, N> &b, float t);

	template <size_t N>
	constexpr BasicVector<float, N> smootherstep(const BasicVector<float, N> &a, const BasicVector<float, N> &b, const BasicVector<float, N> &t);

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
}
