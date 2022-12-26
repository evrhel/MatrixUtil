/*!
\file
Contains methods for performing operations on floating-point vectors.
*/

#pragma once

#ifndef FVEC_MATH_H
#define FVEC_MATH_H

#include "settings.h"
#include "vec_types.h"

#include <cmath>
#include "f_math.h"

#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
#include <smmintrin.h>
#elif MUTIL_ARM
#include <arm_neon.h>
#endif
#endif

namespace mutil
{
	// Vector2 operations

	/*!
	Returns the dot product of two Vector2's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	inline float dot(const Vector2 &first, const Vector2 &second)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
		constexpr int MASK = 0x31;
		return _mm_cvtss_f32(_mm_dp_ps(_mm_loadu_ps((float *)&first), _mm_loadu_ps((float *)&second), MASK));
#elif MUTIL_ARM
		float32x2_t a, b;

		a = vld1_f32((float32_t *)&first);
		b = vld1_f32((float32_t *)&second);

		a = vmul_f32(a, b);
		a = vpadd_f32(a, a);

		return vget_lane_f32(a, 0);
#endif
#else
		return (first.x * second.x) + (first.y * second.y);
#endif
	}

	/*!
	Returns the length of a Vector2.

	@param vec The vector to get the length of.

	@return The length.
	*/
	inline float length(const Vector2 &vec)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
		float result = dot(vec, vec);
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&result)));
		return result;
#elif MUTIL_ARM
		float32_t result = dot(vec, vec);
		float32x2_t a = vsqrt_f32(vld1_f32(&result));
		return vget_lane_f32(a, 0);
#endif
#else
		return sqrtf(dot(vec, vec));
#endif
	}

	inline float lengthSq(const Vector2 &vec)
	{
		return dot(vec, vec);
	}

	/*!
	Finds the distance between two Vector2's.

	@param first The first vector.
	@param second The second vector.

	@return The distance between the two vectors.
	*/
	inline float distance(const Vector2 &first, const Vector2 &second)
	{
		return length(second - first);
	}

	/*!
	Normalizes a Vector2, making its length 1. This function does not
	guarantee that the length is exactly 1, as this function uses a fast
	approximation. For a higher-precision result, use normalizeExact.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	inline Vector2 normalize(const Vector2 &vec)
	{
		return vec * fastInverseSqrt(dot(vec, vec));
	}

	/*
	Normalizes a Vector2, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	inline Vector2 normalizeExact(const Vector2 &vec)
	{
		return vec * inverseSqrt(dot(vec, vec));
	}

	inline float Vector2::length() const
	{
		return mutil::length(*this);
	}

	inline float Vector2::lengthSq() const
	{
		return mutil::lengthSq(*this);
	}

	inline Vector2 Vector2::normalized() const
	{
		return mutil::normalize(*this);
	}

	/*!
	Reflects a Vector2 over a normal, returning the reflected vector.

	@param vec The vector to reflect.
	@param normal The normal vector to reflect over.

	@return The reflected vector.
	*/
	inline Vector2 reflect(const Vector2 &vec, const Vector2 &normal)
	{
		return (normal * (2.0f * dot(normal, vec))) - vec;
	}

	/*!
	Converts a Vector2 containing angles in degrees to radians.

	@param A Vector2 containing angles in degrees.

	@return The same vector in radians.
	*/
	constexpr Vector2 radians(const Vector2 &vec)
	{
		return Vector2(radians(vec.x), radians(vec.y));
	}

	/*!
	Converts a Vector2 containing angles in radians to degrees.

	@param A Vector2 containing angles in radians.

	@return The same vector in degrees.
	*/
	constexpr Vector2 degrees(const Vector2 &vec)
	{
		return Vector2(degrees(vec.x), degrees(vec.y));
	}

	/*!
	Returns a Vector2 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	constexpr Vector2 abs(const Vector2 &vec)
	{
		return Vector2(
			vec.x < 0.0 ? -vec.x : vec.x,
			vec.y < 0.0 ? -vec.y : vec.y);
	}

	constexpr Vector2 &absthis(Vector2 &vec)
	{
		vec.x = vec.x < 0.0 ? -vec.x : vec.x;
		vec.y = vec.y < 0.0 ? -vec.y : vec.y;
		return vec;
	}

	constexpr Vector2 clamp(const Vector2 &val, float min, float max)
	{
		Vector2 result;
		for (size_t i = 0; i < 2; i++)
			result[i] = clamp(val[i], min, max);
		return result;
	}

	constexpr Vector2 clamp(const Vector2 &val, const Vector2 &min, const Vector2 &max)
	{
		Vector2 result;
		for (size_t i = 0; i < 2; i++)
			result[i] = clamp(val[i], min[i], max[i]);
		return result;
	}

	inline Vector2 fract(const Vector2 &val)
	{
		return Vector2(fract(val.x), fract(val.y));
	}

	inline Vector2 mod(const Vector2 &a, float b)
	{
		return Vector2(fmodf(a.x, b), fmodf(a.y, b));
	}

	inline Vector2 mod(const Vector2 &a, const Vector2 &b)
	{
		return Vector2(fmodf(a.x, b.x), fmodf(a.y, b.y));
	}

	inline Vector2 sin(const Vector2 &v)
	{
		return Vector2(sinf(v.x), sinf(v.y));
	}

	inline Vector2 cos(const Vector2 &v)
	{
		return Vector2(cosf(v.x), cosf(v.y));
	}

	inline Vector2 tan(const Vector2 &v)
	{
		return Vector2(tanf(v.x), tanf(v.y));
	}

	inline Vector2 asin(const Vector2 &v)
	{
		return Vector2(asinf(v.x), asinf(v.y));
	}

	inline Vector2 acos(const Vector2 &v)
	{
		return Vector2(acosf(v.x), acosf(v.y));
	}

	inline Vector2 atan(const Vector2 &v)
	{
		return Vector2(atanf(v.x), atanf(v.y));
	}

	constexpr Vector2 lerp(const Vector2 &a, const Vector2 &b, float t)
	{
		return a + t * (b - a);
	}

	constexpr Vector2 lerp(const Vector2 &a, const Vector2 &b, const Vector2 &t)
	{
		return Vector2(lerp(a.x, b.x, t.x), lerp(a.y, b.y, t.y));
	}

	constexpr Vector2 smoothstep(const Vector2 &a, const Vector2 &b, float x)
	{
		return Vector2(
			smoothstep(a.x, b.x, x),
			smoothstep(a.y, b.y, x));
	}

	constexpr Vector2 smoothstep(const Vector2 &a, const Vector2 &b, const Vector2 &x)
	{
		return Vector2(
			smoothstep(a.x, b.x, x.x),
			smoothstep(a.y, b.y, x.y));
	}

	constexpr Vector2 smootherstep(const Vector2 &a, const Vector2 &b, float x)
	{
		return Vector2(
			smootherstep(a.x, b.x, x),
			smootherstep(a.y, b.y, x));
	}

	constexpr Vector2 smootherstep(const Vector2 &a, const Vector2 &b, const Vector2 &x)
	{
		return Vector2(
			smootherstep(a.x, b.x, x.x),
			smootherstep(a.y, b.y, x.y));
	}

	// Vector3 operations

	/*!
	Returns the dot product of two Vector3's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	inline float dot(const Vector3 &first, const Vector3 &second)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
		constexpr int MASK = 0x71;
		return _mm_cvtss_f32(_mm_dp_ps(_mm_loadu_ps((float *)&first), _mm_loadu_ps((float *)&second), MASK));
#elif MUTIL_ARM
		Vector4 va(first, 0.0f);
		Vector4 vb(second, 0.0f);

		float32x4_t vaq = vld1q_f32((float *)&va);
		float32x4_t vbq = vld1q_f32((float *)&vb);

		float32x4_t vab = vmulq_f32(vaq, vbq);
		float32x2_t vab2 = vpadd_f32(vget_low_f32(vab), vget_high_f32(vab));

		return vget_lane_f32(vab2, 0) + vget_lane_f32(vab2, 1);
#endif
#else
		return (first.x * second.x) + (first.y * second.y) + (first.z * second.z);
#endif
	}

	/*!
	Returns the cross product of two Vector3's.

	@param The first vector.
	@param The second vector.

	@return The result of the cross product.
	*/
	inline Vector3 cross(const Vector3 &first, const Vector3 &second)
	{
		return Vector3(
			(first.y * second.z - second.y * first.z),
			(first.z * second.x - second.z * first.x),
			(first.x * second.y - second.x * first.y));
	}

	/*!
	Returns the length of a Vector3.

	@param vec The vector to get the length of.

	@return The length.
	*/
	inline float length(const Vector3 &vec)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
		float result = dot(vec, vec);
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&result)));
		return result;
#elif MUTIL_ARM
		float32_t result = dot(vec, vec);
		float32x2_t a = vsqrt_f32(vld1_f32(&result));
		return vget_lane_f32(a, 0);
#endif
#else
		return sqrtf(dot(vec, vec));
#endif
	}

	inline float lengthSq(const Vector3 &vec)
	{
		return dot(vec, vec);
	}

	/*!
	Finds the distance between two Vector3's.

	@param first The first vector.
	@param second The second vector.

	@return The distance between the two vectors.
	*/
	inline float distance(const Vector3 &first, const Vector3 &second)
	{
		return length(second - first);
	}

	/*!
	Normalizes a Vector3, making its length 1. This function does not
	guarantee that the length is exactly 1, as this function uses a fast
	approximation. For a higher-precision result, use normalizeExact.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	inline Vector3 normalize(const Vector3 &vec)
	{
		return vec * fastInverseSqrt(dot(vec, vec));
	}

	/*
	Normalizes a Vector3, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	inline Vector3 normalizeExact(const Vector3 &vec)
	{
		return vec * inverseSqrt(dot(vec, vec));
	}

	inline Vector3 &normalizethis(Vector3 &vec)
	{
		const float dotinvsqrt = fastInverseSqrt(dot(vec, vec));
		vec.x *= dotinvsqrt;
		vec.y *= dotinvsqrt;
		vec.z *= dotinvsqrt;
		return vec;
	}

	inline Vector3 &normalizethisExact(Vector3 &vec)
	{
		const float dotinvsqrt = inverseSqrt(dot(vec, vec));
		vec.x *= dotinvsqrt;
		vec.y *= dotinvsqrt;
		vec.z *= dotinvsqrt;
		return vec;
	}

	inline float Vector3::length() const
	{
		return mutil::length(*this);
	}

	inline float Vector3::lengthSq() const
	{
		return mutil::lengthSq(*this);
	}

	inline Vector3 Vector3::normalized() const
	{
		return mutil::normalize(*this);
	}

	/*!
	Reflects a Vector3 over a normal, returning the reflected vector.

	@param vec The vector to reflect.
	@param normal The normal vector to reflect over.

	@return The reflected vector.
	*/
	inline Vector3 reflect(const Vector3 &vec, const Vector3 &normal)
	{
		return (normal * (2.0f * dot(normal, vec))) - vec;
	}

	inline Vector3 &refractthis(Vector3 &vec, const Vector3 &normal)
	{
		const float twotimesdot = 2.0f * dot(normal, vec);
		vec.x = normal.x * twotimesdot - vec.x;
		vec.y = normal.y * twotimesdot - vec.y;
		vec.z = normal.z * twotimesdot - vec.z;
		return vec;
	}

	/*!
	Refracts a Vector3 and returns the resultant vector.

	@param vec The vector to refract.
	@param normal The normal of the refracting surface.
	@param index The ratio between two indicies of refraction.
	*/
	inline Vector3 refract(const Vector3 &vec, const Vector3 &normal, float ratio)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
		float sqrtresult = 1 - (ratio * ratio) * dot(cross(normal, vec), cross(normal, vec));
		_mm_store_ss(&sqrtresult, _mm_sqrt_ss(_mm_load_ss(&sqrtresult)));
		return ((cross(normal, cross(-normal, vec))) * ratio) - (normal * sqrtresult);
#elif MUTIL_ARM
		float32_t sqrtresult = 1 - (ratio * ratio) * dot(cross(normal, vec), cross(normal, vec));
		sqrtresult = vget_lane_f32(vsqrt_f32(vld1_f32(&sqrtresult)), 0);
		return ((cross(normal, cross(-normal, vec))) * ratio) - (normal * sqrtresult);
#endif
#else
		return ((cross(normal, cross(-normal, vec))) * ratio) - (normal * sqrtf(1 - (ratio * ratio) * dot(cross(normal, vec), cross(normal, vec))));
#endif
	}

	/*!
	Converts a Vector3 containing angles in degrees to radians.

	@param A Vector3 containing angles in degrees.

	@return The same vector in radians.
	*/
	inline Vector3 radians(const Vector3 &vec)
	{
		return Vector3(radians(vec.x), radians(vec.y), radians(vec.z));
	}

	inline Vector3 &radiansthis(Vector3 &vec)
	{
		vec.x = radians(vec.x);
		vec.y = radians(vec.y);
		vec.z = radians(vec.z);
		return vec;
	}

	/*!
	Converts a Vector3 containing angles in radians to degrees.

	@param A Vector3 containing angles in radians.

	@return The same vector in degrees.
	*/
	inline Vector3 degrees(const Vector3 &vec)
	{
		return Vector3(degrees(vec.x), degrees(vec.y), degrees(vec.z));
	}

	/*!
	Returns a Vector3 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	inline Vector3 abs(const Vector3 &vec)
	{
		return Vector3(
			vec.x < 0.0 ? -vec.x : vec.x,
			vec.y < 0.0 ? -vec.y : vec.y,
			vec.z < 0.0 ? -vec.z : vec.z);
	}

	constexpr Vector3 clamp(const Vector3 &val, float min, float max)
	{
		Vector3 result;
		for (size_t i = 0; i < 3; i++)
			result[i] = clamp(val[i], min, max);
		return result;
	}

	inline Vector3 fract(const Vector3 &val)
	{
		return Vector3(fract(val.x), fract(val.y), fract(val.z));
	}

	constexpr Vector3 clamp(const Vector3 &val, const Vector3 &min, const Vector3 &max)
	{
		Vector3 result;
		for (size_t i = 0; i < 3; i++)
			result[i] = clamp(val[i], min[i], max[i]);
		return result;
	}

	constexpr Vector3 lerp(const Vector3 &a, const Vector3 &b, float t)
	{
		return a + t * (b - a);
	}

	constexpr Vector3 lerp(const Vector3 &a, const Vector3 &b, const Vector3 &t)
	{
		return Vector3(lerp(a.x, b.x, t.x), lerp(a.y, b.y, t.y), lerp(a.z, b.z, t.z));
	}

	constexpr Vector3 smoothstep(const Vector3 &a, const Vector3 &b, float x)
	{
		return Vector3(
			smoothstep(a.x, b.x, x),
			smoothstep(a.y, b.y, x),
			smoothstep(a.z, b.z, x));
	}

	constexpr Vector3 smoothstep(const Vector3 &a, const Vector3 &b, const Vector3 &x)
	{
		return Vector3(
			smoothstep(a.x, b.x, x.x),
			smoothstep(a.y, b.y, x.y),
			smoothstep(a.z, b.z, x.z));
	}

	constexpr Vector3 smootherstep(const Vector3 &a, const Vector3 &b, float x)
	{
		return Vector3(
			smootherstep(a.x, b.x, x),
			smootherstep(a.y, b.y, x),
			smootherstep(a.z, b.z, x));
	}

	constexpr Vector3 smootherstep(const Vector3 &a, const Vector3 &b, const Vector3 &x)
	{
		return Vector3(
			smootherstep(a.x, b.x, x.x),
			smootherstep(a.y, b.y, x.y),
			smootherstep(a.z, b.z, x.z));
	}

	// Vector4 operations

	/*!
	Returns the dot product of two Vector4's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	inline float dot(const Vector4 &first, const Vector4 &second)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
		constexpr int MASK = 0xf1;
		return _mm_cvtss_f32(_mm_dp_ps(_mm_loadu_ps((float *)&first), _mm_loadu_ps((float *)&second), MASK));
#elif MUTIL_ARM
		float32x4_t vaq = vld1q_f32((float *)&first);
		float32x4_t vbq = vld1q_f32((float *)&second);

		float32x4_t vab = vmulq_f32(vaq, vbq);

		float32x2_t vab1 = vget_low_f32(vab);
		float32x2_t vab2 = vget_high_f32(vab);

		float32x2_t vab3 = vpadd_f32(vab1, vab2);

		return vget_lane_f32(vab3, 0) + vget_lane_f32(vab3, 1);
#endif
#else
		return (first.x * second.x) + (first.y * second.y) + (first.z * second.z) + (first.w * second.w);
#endif
	}

	/*!
	Returns the length of a Vector4.

	@param vec The vector to get the length of.

	@return The length.
	*/
	inline float length(const Vector4 &vec)
	{
#if MUTIL_USE_INTRINSICS
#if MUTL_X86
		float result = dot(vec, vec);
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&result)));
		return result;
#elif MUTIL_ARM
		float32_t result = dot(vec, vec);
		float32x2_t a = vsqrt_f32(vld1_f32(&result));
		return vget_lane_f32(a, 0);
#endif
#else
		return sqrtf(dot(vec, vec));
#endif
	}

	inline float lengthSq(const Vector4 &vec)
	{
		return dot(vec, vec);
	}

	/*!
	Finds the distance between two Vector4's.

	@param first The first vector.
	@param second The second vector.

	@return The distance between the two vectors.
	*/
	inline float distance(const Vector4 &first, const Vector4 &second)
	{
		return length(second - first);
	}

	/*!
	Normalizes a Vector4, making its length 1. This function does not
	guarantee that the length is exactly 1, as this function uses a fast
	approximation. For a higher-precision result, use normalizeExact.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	inline Vector4 normalize(const Vector4 &vec)
	{
		return vec * fastInverseSqrt(dot(vec, vec));
	}

	/*!
	Normalizes a Vector4, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	inline Vector4 normalizeExact(const Vector4 &vec)
	{
		return vec * inverseSqrt(dot(vec, vec));
	}

	inline float Vector4::length() const
	{
		return mutil::length(*this);
	}

	inline float Vector4::lengthSq() const
	{
		return mutil::lengthSq(*this);
	}

	inline Vector4 Vector4::normalized() const
	{
		return mutil::normalize(*this);
	}

	/*!
	Reflects a Vector4 over a normal, returning the reflected vector.

	@param vec The vector to reflect.
	@param normal The normal vector to reflect over.

	@return The reflected vector.
	*/
	inline Vector4 reflect(const Vector4 &vec, const Vector4 &normal)
	{
		return (normal * (2.0f * dot(normal, vec))) - vec;
	}

	/*!
	Converts a Vector4 containing angles in degrees to radians.

	@param A Vector4 containing angles in degrees.

	@return The same vector in radians.
	*/
	inline Vector4 radians(const Vector4 &vec)
	{
		return Vector4(radians(vec.x), radians(vec.y), radians(vec.z), radians(vec.w));
	}

	/*!
	Converts a Vector4 containing angles in radians to degrees.

	@param A Vector4 containing angles in radians.

	@return The same vector in degrees.
	*/
	inline Vector4 degrees(const Vector4 &vec)
	{
		return Vector4(degrees(vec.x), degrees(vec.y), degrees(vec.z), degrees(vec.w));
	}

	/*!
	Returns a Vector4 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	inline Vector4 abs(const Vector4 &vec)
	{
		return Vector4(
			vec.x < 0.0 ? -vec.x : vec.x,
			vec.y < 0.0 ? -vec.y : vec.y,
			vec.z < 0.0 ? -vec.z : vec.z,
			vec.w < 0.0 ? -vec.w : vec.w);
	}

	constexpr Vector4 clamp(const Vector4 &val, float min, float max)
	{
		Vector4 result;
		for (size_t i = 0; i < 4; i++)
			result[i] = clamp(val[i], min, max);
		return result;
	}

	constexpr Vector4 clamp(const Vector4 &val, const Vector4 &min, const Vector4 &max)
	{
		Vector4 result;
		for (size_t i = 0; i < 4; i++)
			result[i] = clamp(val[i], min[i], max[i]);
		return result;
	}

	constexpr Vector4 lerp(const Vector4 &a, const Vector4 &b, float t)
	{
		return a + t * (b - a);
	}

	constexpr Vector4 lerp(const Vector4 &a, const Vector4 &b, const Vector4 &t)
	{
		return Vector4(lerp(a.x, b.x, t.x), lerp(a.y, b.y, t.y), lerp(a.z, b.z, t.z), lerp(a.w, b.w, t.w));
	}

	constexpr Vector4 smoothstep(const Vector4 &a, const Vector4 &b, float x)
	{
		return Vector4(
			smoothstep(a.x, b.x, x),
			smoothstep(a.y, b.y, x),
			smoothstep(a.z, b.z, x),
			smoothstep(a.w, b.w, x));
	}

	constexpr Vector4 smoothstep(const Vector4 &a, const Vector4 &b, const Vector4 &x)
	{
		return Vector4(
			smoothstep(a.x, b.x, x.x),
			smoothstep(a.y, b.y, x.y),
			smoothstep(a.z, b.z, x.z),
			smoothstep(a.w, b.w, x.w));
	}

	constexpr Vector4 smootherstep(const Vector4 &a, const Vector4 &b, float x)
	{
		return Vector4(
			smootherstep(a.x, b.x, x),
			smootherstep(a.y, b.y, x),
			smootherstep(a.z, b.z, x),
			smootherstep(a.w, b.w, x));
	}

	constexpr Vector4 smootherstep(const Vector4 &a, const Vector4 &b, const Vector4 &x)
	{
		return Vector4(
			smootherstep(a.x, b.x, x.x),
			smootherstep(a.y, b.y, x.y),
			smootherstep(a.z, b.z, x.z),
			smootherstep(a.w, b.w, x.w));
	}
}

#endif