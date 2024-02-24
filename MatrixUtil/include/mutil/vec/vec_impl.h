#pragma once

#include "vec.h"

namespace mutil
{
	/////////////////////////////////////////////////////////////////
	// BasicVector

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator+(const BasicVector<T, N> &a, const BasicVector<T, N> &b)
	{
		BasicVector<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = a[i] + b[i];
		return result;
	}

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator-(const BasicVector<T, N> &a, const BasicVector<T, N> &b)
	{
		BasicVector<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = a[i] - b[i];
		return result;
	}

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator*(const BasicVector<T, N> &a, const BasicVector<T, N> &b)
	{
		BasicVector<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = a[i] * b[i];
		return result;
	}

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator*(const BasicVector<T, N> &a, T b)
	{
		BasicVector<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = a[i] * b;
		return result;
	}

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator*(T a, const BasicVector<T, N> &b)
	{
		BasicVector<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = a * b[i];
		return result;
	}

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator/(const BasicVector<T, N> &a, const BasicVector<T, N> &b)
	{
		BasicVector<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = a[i] / b[i];
		return result;
	}

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator/(const BasicVector<T, N> &a, T b)
	{
		BasicVector<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = a[i] / b;
		return result;
	}

	template <typename T, size_t N>
	constexpr BasicVector<T, N> operator-(const BasicVector<T, N> &a)
	{
		BasicVector<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = -a[i];
		return result;
	}

	template <typename T, size_t N>
	constexpr bool operator==(const BasicVector<T, N> &a, const BasicVector<T, N> &b)
	{
		for (size_t i = 0; i < N; i++)
			if (a[i] != b[i])
				return false;
		return true;
	}

	template <typename T, size_t N>
	constexpr bool operator!=(const BasicVector<T, N> &a, const BasicVector<T, N> &b)
	{
		for (size_t i = 0; i < N; i++)
			if (a[i] != b[i])
				return true;
		return false;
	}

	template <typename T, size_t N>
	constexpr BasicVector<T, N> dot(const BasicVector<T, N> &a, const BasicVector<T, N> &b)
	{
		BasicVector<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = a[i] * b[i];
		return result;
	}

	template <size_t N>
	constexpr Vector<N> normalize(const Vector<N> &a)
	{
		return a / sqrtf(dot(a, a));
	}

	template <typename T, size_t N>
	constexpr BasicVector<T, N> abs(const BasicVector<T, N> &a)
	{
		BasicVector<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = a[i] < 0 ? -a[i] : a[i];
		return result;
	}

	template <size_t N>
	MUTIL_FORCEINLINE Vector<N> MUTIL_VECTORCALL fract(const Vector<N> &a)
	{
		Vector<N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = fract(a[i]);
		return result;
	}

	template <size_t N>
	MUTIL_FORCEINLINE Vector<N> MUTIL_VECTORCALL mod(const Vector<N> &a, float b)
	{
		Vector<N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = fmodf(a[i], b);
		return result;
	}

	template <size_t N>
	MUTIL_FORCEINLINE Vector<N> MUTIL_VECTORCALL mod(const Vector<N> &a, const Vector<N> &b)
	{
		Vector<N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = fmodf(a[i], b[i]);
		return result;
	}

	template <size_t N>
	constexpr IntVector<N> mod(const IntVector<N> &a, int32_t b)
	{
		IntVector<N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = a[i] % b;
		return result;
	}

	template <size_t N>
	constexpr IntVector<N> mod(const IntVector<N> &a, const IntVector<N> &b)
	{
		IntVector<N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = a[i] % b[i];
		return result;
	}

	template <typename T, size_t N>
	constexpr BasicVector<T, N> clamp(const BasicVector<T, N> &a, T min, T max)
	{
		BasicVector<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = clamp(a[i], min, max);
		return result;
	}

	template <typename T, size_t N>
	constexpr BasicVector<T, N> clamp(const BasicVector<T, N> &a, const BasicVector<T, N> &min, const BasicVector<T, N> &max)
	{
		BasicVector<T, N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = clamp(a[i], min[i], max[i]);
		return result;
	}

	template <size_t N>
	constexpr Vector<N> lerp(const Vector<N> &a, const Vector<N> &b, float t)
	{
		Vector<N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = lerp(a[i], b[i], t);
		return result;
	}

	template <size_t N>
	constexpr Vector<N> lerp(const Vector<N> &a, const Vector<N> &b, const Vector<N> &t)
	{
		Vector<N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = lerp(a[i], b[i], t[i]);
		return result;
	}

	template <size_t N>
	constexpr Vector<N> smoothstep(const Vector<N> &a, const Vector<N> &b, float t)
	{
		Vector<N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = smoothstep(a[i], b[i], t);
		return result;
	}

	template <size_t N>
	constexpr Vector<N> smoothstep(const Vector<N> &a, const Vector<N> &b, const Vector<N> &t)
	{
		Vector<N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = smoothstep(a[i], b[i], t[i]);
		return result;
	}

	template <size_t N>
	constexpr Vector<N> smootherstep(const Vector<N> &a, const Vector<N> &b, float t)
	{
		Vector<N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = smootherstep(a[i], b[i], t);
		return result;
	}

	template <size_t N>
	constexpr Vector<N> smootherstep(const Vector<N> &a, const Vector<N> &b, const Vector<N> &t)
	{
		Vector<N> result;
		for (size_t i = 0; i < N; i++)
			result[i] = smootherstep(a[i], b[i], t[i]);
		return result;
	}

	/////////////////////////////////////////////////////////////////
	// Vector2

	constexpr Vector2::BasicVector() : x(0), y(0) {}
	constexpr Vector2::BasicVector(float a) : x(a), y(a) {}
	constexpr Vector2::BasicVector(float x, float y) : x(x), y(y) {}
	constexpr Vector2::BasicVector(const IntVector2 &a) : x((float)a.x), y((float)a.y) {}
	constexpr Vector2::BasicVector(const Vector3 &a) : x(a.x), y(a.y) {}
	constexpr Vector2::BasicVector(const Vector4 &a) : x(a.x), y(a.y) {}

	constexpr Vector2 &Vector2::operator+=(const Vector2 &a)
	{
		x += a.x;
		y += a.y;
		return *this;
	}
	constexpr Vector2 &Vector2::operator-=(const Vector2 &a)
	{
		x -= a.x;
		y -= a.y;
		return *this;
	}
	constexpr Vector2 &Vector2::operator*=(const Vector2 &a)
	{
		x *= a.x;
		y *= a.y;
		return *this;
	}
	constexpr Vector2 &Vector2::operator*=(float a)
	{
		x *= a;
		y *= a;
		return *this;
	}
	constexpr Vector2 &Vector2::operator/=(const Vector2 &a)
	{
		x /= a.x;
		y /= a.y;
		return *this;
	}
	constexpr Vector2 &Vector2::operator/=(float a)
	{
		x /= a;
		y /= a;
		return *this;
	}

	constexpr const float &Vector2::operator[](size_t i) const { return (&x)[i]; }
	constexpr float &Vector2::operator[](size_t i) { return (&x)[i]; }

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL Vector2::length() const { return mutil::length(*this); }
	MUTIL_FORCEINLINE float MUTIL_VECTORCALL Vector2::lengthSq() const { return mutil::lengthSq(*this); }
	MUTIL_FORCEINLINE Vector2 MUTIL_VECTORCALL Vector2::normalized() const { return mutil::normalize(*this); }

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL dot(const Vector2 &first, const Vector2 &second)
	{
#if MUTIL_USE_SSE
		constexpr int MASK = 0x31;
		return _mm_cvtss_f32(_mm_dp_ps(_mm_loadu_ps((float *)&first), _mm_loadu_ps((float *)&second), MASK));
#elif MUTIL_USE_NEON
		float32x2_t a, b;

		a = vld1_f32((float32_t *)&first);
		b = vld1_f32((float32_t *)&second);

		a = vmul_f32(a, b);
		a = vpadd_f32(a, a);

		return vget_lane_f32(a, 0);
#else
		return (first.x * second.x) + (first.y * second.y);
#endif
	}

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL length(const Vector2 &vec)
	{
#if MUTIL_USE_SSE
		constexpr int MASK = 0x31;
		return _mm_cvtss_f32(_mm_sqrt_ss(_mm_dp_ps(_mm_loadu_ps((float *)&vec), _mm_loadu_ps((float *)&vec), MASK)));
#elif MUTIL_USE_NEON
		float32_t result = dot(vec, vec);
		float32x2_t a = vsqrt_f32(vld1_f32(&result));
		return vget_lane_f32(a, 0);
#else
		return sqrtf(dot(vec, vec));
#endif
	}

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL lengthSq(const Vector2 &a) { return dot(a, a); }
	MUTIL_FORCEINLINE float MUTIL_VECTORCALL distance(const Vector2 &a, const Vector2 &b) { return length(b - a); }
	MUTIL_FORCEINLINE Vector2 MUTIL_VECTORCALL normalize(const Vector2 &a) { return a * fastInverseSqrt(dot(a, a)); }
	MUTIL_FORCEINLINE Vector2 MUTIL_VECTORCALL reflect(const Vector2 &a, const Vector2 &N) { return (N * (2.0f * dot(N, a))) - a; }

	/////////////////////////////////////////////////////////////////
	// Vector3

	constexpr Vector3::BasicVector() : x(0), y(0), z(0) {}
	constexpr Vector3::BasicVector(float a) : x(a), y(a), z(a) {}
	constexpr Vector3::BasicVector(float x, float y, float z) : x(x), y(y), z(z) {}
	constexpr Vector3::BasicVector(const IntVector3 &a) : x((float)a.x), y((float)a.y), z((float)a.z) {}
	constexpr Vector3::BasicVector(const Vector2 &xy, float z) : x(xy.x), y(xy.y), z(z) {}
	constexpr Vector3::BasicVector(float x, const Vector2 &yz) : x(x), y(yz.x), z(yz.y) {}
	constexpr Vector3::BasicVector(const Vector2 &xy) : x(xy.x), y(xy.y), z(0) {}
	constexpr Vector3::BasicVector(const Vector4 &a) : x(a.x), y(a.y), z(a.z) {}

	constexpr Vector3 &Vector3::operator+=(const Vector3 &a)
	{
		x += a.x;
		y += a.y;
		z += a.z;
		return *this;
	}
	constexpr Vector3 &Vector3::operator-=(const Vector3 &a)
	{
		x -= a.x;
		y -= a.y;
		z -= a.z;
		return *this;
	}
	constexpr Vector3 &Vector3::operator*=(const Vector3 &a)
	{
		x *= a.x;
		y *= a.y;
		z *= a.z;
		return *this;
	}
	constexpr Vector3 &Vector3::operator*=(float a)
	{
		x *= a;
		y *= a;
		z *= a;
		return *this;
	}
	constexpr Vector3 &Vector3::operator/=(const Vector3 &a)
	{
		x /= a.x;
		y /= a.y;
		z /= a.z;
		return *this;
	}
	constexpr Vector3 &Vector3::operator/=(float a)
	{
		x /= a;
		y /= a;
		z /= a;
		return *this;
	}

	constexpr const float &Vector3::operator[](size_t i) const { return (&x)[i]; }
	constexpr float &Vector3::operator[](size_t i) { return (&x)[i]; }

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL Vector3::length() const { return mutil::length(*this); }
	MUTIL_FORCEINLINE float MUTIL_VECTORCALL Vector3::lengthSq() const { return mutil::lengthSq(*this); }
	MUTIL_FORCEINLINE Vector3 MUTIL_VECTORCALL Vector3::normalized() const { return mutil::normalize(*this); }

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL dot(const Vector3 &a, const Vector3 &b)
	{
#if MUTIL_USE_SSE
		constexpr int MASK = 0x71;
		return _mm_cvtss_f32(_mm_dp_ps(_mm_loadu_ps((float *)&a), _mm_loadu_ps((float *)&b), MASK));
#elif MUTIL_USE_NEON
		Vector4 va(a, 0.0f);
		Vector4 vb(b, 0.0f);

		float32x4_t vaq = vld1q_f32((float *)&va);
		float32x4_t vbq = vld1q_f32((float *)&vb);

		float32x4_t vab = vmulq_f32(vaq, vbq);
		float32x2_t vab2 = vpadd_f32(vget_low_f32(vab), vget_high_f32(vab));

		return vget_lane_f32(vab2, 0) + vget_lane_f32(vab2, 1);
#else
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
#endif
	}

	constexpr Vector3 cross(const Vector3 &a, const Vector3 &b)
	{
		return Vector3(
			(a.y * b.z - b.y * a.z),
			(a.z * b.x - b.z * a.x),
			(a.x * b.y - b.x * a.y));
	}

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL length(const Vector3 &a)
	{
#if MUTIL_USE_SSE
		constexpr int MASK = 0x71;
		return _mm_cvtss_f32(_mm_sqrt_ss(_mm_dp_ps(_mm_loadu_ps((float *)&a), _mm_loadu_ps((float *)&a), MASK)));
#elif MUTIL_USE_NEON
		float32_t result = dot(a, a);
		float32x2_t r = vsqrt_f32(vld1_f32(&result));
		return vget_lane_f32(r, 0);
#else
		return sqrtf(dot(a, a));
#endif
	}

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL lengthSq(const Vector3 &a) { return dot(a, a); }
	MUTIL_FORCEINLINE float MUTIL_VECTORCALL distance(const Vector3 &a, const Vector3 &b) { return length(b - a); }
	MUTIL_FORCEINLINE Vector3 MUTIL_VECTORCALL normalize(const Vector3 &a) { return a * fastInverseSqrt(dot(a, a)); }
	MUTIL_FORCEINLINE Vector3 MUTIL_VECTORCALL reflect(const Vector3 &a, const Vector3 &N) { return (N * (2.0f * dot(N, a))) - a; }

	MUTIL_FORCEINLINE Vector3 MUTIL_VECTORCALL refract(const Vector3 &a, const Vector3 &N, float ratio)
	{
#if MUTIL_USE_SSE
		float sqrtresult = 1 - (ratio * ratio) * dot(cross(N, a), cross(N, a));
		_mm_store_ss(&sqrtresult, _mm_sqrt_ss(_mm_load_ss(&sqrtresult)));
		return ((cross(N, cross(-N, a))) * ratio) - (N * sqrtresult);
#elif MUTIL_USE_ARM
		float32_t sqrtresult = 1 - (ratio * ratio) * dot(cross(N, a), cross(N, a));
		sqrtresult = vget_lane_f32(vsqrt_f32(vld1_f32(&sqrtresult)), 0);
		return ((cross(N, cross(-N, a))) * ratio) - (N * sqrtresult);
#else
		return ((cross(N, cross(-N, a))) * ratio) - (N * sqrtf(1 - (ratio * ratio) * dot(cross(N, a), cross(N, a))));
#endif
	}

	/////////////////////////////////////////////////////////////////
	// Vector4

	constexpr Vector4::BasicVector() : x(0), y(0), z(0), w(0) {}
	constexpr Vector4::BasicVector(float a) : x(a), y(a), z(a), w(a) {}
	constexpr Vector4::BasicVector(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
	constexpr Vector4::BasicVector(const IntVector4 &a) : x((float)a.x), y((float)a.y), z((float)a.z), w((float)a.w) {}
	constexpr Vector4::BasicVector(const Vector2 &xy, float z, float w) : x(xy.x), y(xy.y), z(z), w(w) {}
	constexpr Vector4::BasicVector(const Vector3 &xyz, float w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}
	constexpr Vector4::BasicVector(const Vector2 &xy, const Vector2 &zw) : x(xy.x), y(xy.y), z(zw.x), w(zw.y) {}
	constexpr Vector4::BasicVector(float x, const Vector3 &yzw) : x(x), y(yzw.x), z(yzw.y), w(yzw.z) {}
	constexpr Vector4::BasicVector(float x, float y, const Vector2 &zw) : x(x), y(y), z(zw.x), w(zw.y) {}
	constexpr Vector4::BasicVector(float x, const Vector2 &yz, float w) : x(x), y(yz.x), z(yz.y), w(w) {}
	constexpr Vector4::BasicVector(const Vector2 &a) : x(a.x), y(a.y), z(0), w(0) {}
	constexpr Vector4::BasicVector(const Vector3 &a) : x(a.x), y(a.y), z(a.z), w(0) {}

	constexpr Vector4 &Vector4::operator+=(const Vector4 &a)
	{
		x += a.x;
		y += a.y;
		z += a.z;
		w += a.w;
		return *this;
	}
	constexpr Vector4 &Vector4::operator-=(const Vector4 &a)
	{
		x -= a.x;
		y -= a.y;
		z -= a.z;
		w -= a.w;
		return *this;
	}
	constexpr Vector4 &Vector4::operator*=(const Vector4 &a)
	{
		x *= a.x;
		y *= a.y;
		z *= a.z;
		w *= a.w;
		return *this;
	}
	constexpr Vector4 &Vector4::operator*=(float a)
	{
		x *= a;
		y *= a;
		z *= a;
		w *= a;
		return *this;
	}
	constexpr Vector4 &Vector4::operator/=(const Vector4 &a)
	{
		x /= a.x;
		y /= a.y;
		z /= a.z;
		w /= a.w;
		return *this;
	}
	constexpr Vector4 &Vector4::operator/=(float a)
	{
		x /= a;
		y /= a;
		z /= a;
		w /= a;
		return *this;
	}

	constexpr const float &Vector4::operator[](size_t i) const { return (&x)[i]; }
	constexpr float &Vector4::operator[](size_t i) { return (&x)[i]; }

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL Vector4::length() const { return mutil::length(*this); }
	MUTIL_FORCEINLINE float MUTIL_VECTORCALL Vector4::lengthSq() const { return mutil::lengthSq(*this); }
	MUTIL_FORCEINLINE Vector4 MUTIL_VECTORCALL Vector4::normalized() const { return mutil::normalize(*this); }

	inline float MUTIL_VECTORCALL dot(const Vector4 &first, const Vector4 &second)
	{
#if MUTIL_USE_SSE
		constexpr int MASK = 0xf1;
		return _mm_cvtss_f32(_mm_dp_ps(_mm_loadu_ps((float *)&first), _mm_loadu_ps((float *)&second), MASK));
#elif MUTIL_USE_NEON
		float32x4_t vaq = vld1q_f32((float *)&first);
		float32x4_t vbq = vld1q_f32((float *)&second);

		float32x4_t vab = vmulq_f32(vaq, vbq);

		float32x2_t vab1 = vget_low_f32(vab);
		float32x2_t vab2 = vget_high_f32(vab);

		float32x2_t vab3 = vpadd_f32(vab1, vab2);

		return vget_lane_f32(vab3, 0) + vget_lane_f32(vab3, 1);
#else
		return (first.x * second.x) + (first.y * second.y) + (first.z * second.z) + (first.w * second.w);
#endif
	}

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL length(const Vector4 &vec)
	{
#if MUTIL_USE_SSE
		constexpr int MASK = 0xf1;
		return _mm_cvtss_f32(_mm_sqrt_ss(_mm_dp_ps(_mm_loadu_ps((float *)&vec), _mm_loadu_ps((float *)&vec), MASK)));
#elif MUTIL_USE_NEON
		float32_t result = dot(vec, vec);
		float32x2_t a = vsqrt_f32(vld1_f32(&result));
		return vget_lane_f32(a, 0);
#else
		return sqrtf(dot(vec, vec));
#endif
	}

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL lengthSq(const Vector4 &a) { return dot(a, a); }
	MUTIL_FORCEINLINE float MUTIL_VECTORCALL distance(const Vector4 &a, const Vector4 &b) { return length(b - a); }
	MUTIL_FORCEINLINE Vector4 MUTIL_VECTORCALL normalize(const Vector4 &a) { return a * fastInverseSqrt(dot(a, a)); }
	MUTIL_FORCEINLINE Vector4 MUTIL_VECTORCALL reflect(const Vector4 &a, const Vector4 &N) { return (N * (2.0f * dot(N, a))) - a; }

	/////////////////////////////////////////////////////////////////
	// IntVector2

	constexpr IntVector2::BasicVector() : x(0), y(0) {}
	constexpr IntVector2::BasicVector(int32_t a) : x(a), y(a) {}
	constexpr IntVector2::BasicVector(int32_t x, int32_t y) : x(x), y(y) {}
	constexpr IntVector2::BasicVector(const Vector2 &a) : x((int32_t)a.x), y((int32_t)a.y) {}
	constexpr IntVector2::BasicVector(const IntVector3 &a) : x(a.x), y(a.y) {}
	constexpr IntVector2::BasicVector(const IntVector4 &a) : x(a.x), y(a.y) {}

	constexpr IntVector2 &IntVector2::operator+=(const IntVector2 &a)
	{
		x += a.x;
		y += a.y;
		return *this;
	}
	constexpr IntVector2 &IntVector2::operator-=(const IntVector2 &a)
	{
		x -= a.x;
		y -= a.y;
		return *this;
	}
	constexpr IntVector2 &IntVector2::operator*=(const IntVector2 &a)
	{
		x *= a.x;
		y *= a.y;
		return *this;
	}
	constexpr IntVector2 &IntVector2::operator*=(int32_t a)
	{
		x *= a;
		y *= a;
		return *this;
	}
	constexpr IntVector2 &IntVector2::operator/=(const IntVector2 &a)
	{
		x /= a.x;
		y /= a.y;
		return *this;
	}
	constexpr IntVector2 &IntVector2::operator/=(int32_t a)
	{
		x /= a;
		y /= a;
		return *this;
	}

	constexpr const int32_t &IntVector2::operator[](size_t i) const { return (&x)[i]; }
	constexpr int32_t &IntVector2::operator[](size_t i) { return (&x)[i]; }

	constexpr int32_t dot(const IntVector2 &a, const IntVector2 &b)
	{
		return (a.x * b.x) + (a.y * b.y);
	}

	/////////////////////////////////////////////////////////////////
	// IntVector3

	constexpr IntVector3::BasicVector() : x(0), y(0), z(0) {}
	constexpr IntVector3::BasicVector(int32_t a) : x(a), y(a), z(a) {}
	constexpr IntVector3::BasicVector(int32_t x, int32_t y, int32_t z) : x(x), y(y), z(z) {}
	constexpr IntVector3::BasicVector(const Vector3 &a) : x((int32_t)a.x), y((int32_t)a.y), z((int32_t)a.z) {}
	constexpr IntVector3::BasicVector(const IntVector2 &xy, int32_t z) : x(xy.x), y(xy.y), z(z) {}
	constexpr IntVector3::BasicVector(const IntVector4 &a) : x(a.x), y(a.y), z(a.z) {}

	constexpr IntVector3 &IntVector3::operator+=(const IntVector3 &a)
	{
		x += a.x;
		y += a.y;
		z += a.z;
		return *this;
	}
	constexpr IntVector3 &IntVector3::operator-=(const IntVector3 &a)
	{
		x -= a.x;
		y -= a.y;
		z -= a.z;
		return *this;
	}
	constexpr IntVector3 &IntVector3::operator*=(const IntVector3 &a)
	{
		x *= a.x;
		y *= a.y;
		z *= a.z;
		return *this;
	}
	constexpr IntVector3 &IntVector3::operator*=(int32_t a)
	{
		x *= a;
		y *= a;
		z *= a;
		return *this;
	}
	constexpr IntVector3 &IntVector3::operator/=(const IntVector3 &a)
	{
		x /= a.x;
		y /= a.y;
		z /= a.z;
		return *this;
	}
	constexpr IntVector3 &IntVector3::operator/=(int32_t a)
	{
		x /= a;
		y /= a;
		z /= a;
		return *this;
	}

	constexpr const int32_t &IntVector3::operator[](size_t i) const { return (&x)[i]; }
	constexpr int32_t &IntVector3::operator[](size_t i) { return (&x)[i]; }

	constexpr int32_t dot(const IntVector3 &a, const IntVector3 &b)
	{
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	}

	constexpr IntVector3 cross(const IntVector3 &a, const IntVector3 &b)
	{
		return IntVector3(
			(a.y * b.z - b.y * a.z),
			(a.z * b.x - b.z * a.x),
			(a.x * b.y - b.x * a.y));
	}

	/////////////////////////////////////////////////////////////////
	// IntVector4

	constexpr IntVector4::BasicVector() : x(0), y(0), z(0), w(0) {}
	constexpr IntVector4::BasicVector(int32_t a) : x(a), y(a), z(a), w(a) {}
	constexpr IntVector4::BasicVector(int32_t x, int32_t y, int32_t z, int32_t w) : x(x), y(y), z(z), w(w) {}
	constexpr IntVector4::BasicVector(const Vector4 &a) : x((int32_t)a.x), y((int32_t)a.y), z((int32_t)a.z), w((int32_t)a.w) {}
	constexpr IntVector4::BasicVector(const IntVector2 &xy, int32_t z, int32_t w) : x(xy.x), y(xy.y), z(z), w(w) {}
	constexpr IntVector4::BasicVector(const IntVector3 &xyz, int32_t w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}
	constexpr IntVector4::BasicVector(const IntVector2 &xy, const IntVector2 &zw) : x(xy.x), y(xy.y), z(zw.x), w(zw.y) {}
	constexpr IntVector4::BasicVector(int32_t x, const IntVector3 &yzw) : x(x), y(yzw.x), z(yzw.y), w(yzw.z) {}
	constexpr IntVector4::BasicVector(int32_t x, int32_t y, const IntVector2 &zw) : x(x), y(y), z(zw.x), w(zw.y) {}
	constexpr IntVector4::BasicVector(int32_t x, const IntVector2 &yz, int32_t w) : x(x), y(yz.x), z(yz.y), w(w) {}
	constexpr IntVector4::BasicVector(const IntVector2 &a) : x(a.x), y(a.y), z(0), w(0) {}
	constexpr IntVector4::BasicVector(const IntVector3 &a) : x(a.x), y(a.y), z(a.z), w(0) {}

	constexpr IntVector4 &IntVector4::operator+=(const IntVector4 &a)
	{
		x += a.x;
		y += a.y;
		z += a.z;
		w += a.w;
		return *this;
	}
	constexpr IntVector4 &IntVector4::operator-=(const IntVector4 &a)
	{
		x -= a.x;
		y -= a.y;
		z -= a.z;
		w -= a.w;
		return *this;
	}
	constexpr IntVector4 &IntVector4::operator*=(const IntVector4 &a)
	{
		x *= a.x;
		y *= a.y;
		z *= a.z;
		w *= a.w;
		return *this;
	}
	constexpr IntVector4 &IntVector4::operator*=(int32_t a)
	{
		x *= a;
		y *= a;
		z *= a;
		w *= a;
		return *this;
	}
	constexpr IntVector4 &IntVector4::operator/=(const IntVector4 &a)
	{
		x /= a.x;
		y /= a.y;
		z /= a.z;
		w /= a.w;
		return *this;
	}
	constexpr IntVector4 &IntVector4::operator/=(int32_t a)
	{
		x /= a;
		y /= a;
		z /= a;
		w /= a;
		return *this;
	}

	constexpr const int32_t &IntVector4::operator[](size_t i) const { return (&x)[i]; }
	constexpr int32_t &IntVector4::operator[](size_t i) { return (&x)[i]; }

	constexpr int32_t dot(const IntVector4 &a, const IntVector4 &b)
	{
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
	}
}
