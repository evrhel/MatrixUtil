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

#if defined(USE_SIMD)
#include <smmintrin.h>
#endif

namespace mutil
{
	MUTIL_INLINE float inverseSqrt(const float num)
	{
#if defined(USE_SIMD)
		float result;
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&num)));
		return 1.0f / result;
#else
		return 1.0f / sqrtf(num);
#endif
	}

	MUTIL_INLINE float fastInverseSqrt(const float num)
	{
#if defined(USE_SIMD)
		float result;
		_mm_store_ss(&result, _mm_rsqrt_ss(_mm_load_ss(&num)));
		return result;
#else
		const float x2 = num * 0.5f;
		const float threehalfs = 1.5f;

		union
		{
			float f;
			uint32_t i;
		} un;

		un.f = num;
		un.i = 0x5f3759df - (un.i >> 1);
		un.f *= threehalfs - (x2 * un.f * un.f);
		return un.f;
#endif
	}

	// Vector2 operations

	/*!
	Returns the dot product of two Vector2's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	MUTIL_INLINE float dot(const Vector2 &first, const Vector2 &second)
	{
#if defined(USE_SIMD)
		constexpr int MASK = 0x31;
		return _mm_cvtss_f32(_mm_dp_ps(_mm_loadu_ps((float *)&first), _mm_loadu_ps((float *)&second), MASK));
#else
		return (first.x * second.x) + (first.y * second.y);
#endif
	}

	/*!
	Returns the length of a Vector2.

	@param vec The vector to get the length of.

	@return The length.
	*/
	MUTIL_INLINE float length(const Vector2 &vec)
	{
#if defined(USE_SIMD)
		float result = dot(vec, vec);
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&result)));
		return result;
#else
		return sqrtf(dot(vec, vec));
#endif
	}

	/*!
	Finds the distance between two Vector2's.

	@param first The first vector.
	@param second The second vector.

	@return The distance between the two vectors.
	*/
	MUTIL_INLINE float distance(const Vector2 &first, const Vector2 &second)
	{
		return length(second - first);
	}

	/*!
	Normalizes a Vector2, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	MUTIL_INLINE Vector2 normalize(const Vector2 &vec)
	{
#if defined(NO_FAST_INVERSE_SQRT)
		return vec * inverseSqrt(dot(vec, vec));
#else
		return vec * fastInverseSqrt(dot(vec, vec));
#endif
	}


	/*!
	Reflects a Vector2 over a normal, returning the reflected vector.

	@param vec The vector to reflect.
	@param normal The normal vector to reflect over.

	@return The reflected vector.
	*/
	MUTIL_INLINE Vector2 reflect(const Vector2 &vec, const Vector2 &normal)
	{
		return (normal * (2.0f * dot(normal, vec))) - vec;
	}

	/*!
	Converts a Vector2 containing angles in degrees to radians.

	@param A Vector2 containing angles in degrees.

	@return The same vector in radians.
	*/
	MUTIL_INLINE Vector2 radians(const Vector2 &vec)
	{
		return Vector2(radians(vec.x), radians(vec.y));
	}

	/*!
	Converts a Vector2 containing angles in radians to degrees.

	@param A Vector2 containing angles in radians.

	@return The same vector in degrees.
	*/
	MUTIL_INLINE Vector2 degrees(const Vector2 &vec)
	{
		return Vector2(degrees(vec.x), degrees(vec.y));
	}


	/*!
	Returns a Vector2 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	MUTIL_INLINE Vector2 abs(const Vector2 &vec)
	{
		return Vector2(
			vec.x < 0.0 ? -vec.x : vec.x,
			vec.y < 0.0 ? -vec.y : vec.y
			);
	}

	// Vector3 operations

	/*!
	Returns the dot product of two Vector3's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	MUTIL_INLINE float dot(const Vector3 &first, const Vector3 &second)
	{
#if defined(USE_SIMD)
		constexpr int MASK = 0x71;
		return _mm_cvtss_f32(_mm_dp_ps(_mm_loadu_ps((float *)&first), _mm_loadu_ps((float *)&second), MASK));
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
	MUTIL_INLINE Vector3 cross(const Vector3 &first, const Vector3 &second)
	{
		return Vector3(
			(first.y * second.z - second.y * first.z),
			(first.z * second.x - second.z * first.x),
			(first.x * second.y - second.x * first.y)
		);
	}

	/*!
	Returns the length of a Vector3.

	@param vec The vector to get the length of.

	@return The length.
	*/
	MUTIL_INLINE float length(const Vector3 &vec)
	{
#if defined(USE_SIMD)
		float result = dot(vec, vec);
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&result)));
		return result;
#else
		return sqrtf(dot(vec, vec));
#endif
	}

	/*!
	Finds the distance between two Vector3's.

	@param first The first vector.
	@param second The second vector.

	@return The distance between the two vectors.
	*/
	MUTIL_INLINE float distance(const Vector3 &first, const Vector3 &second)
	{
		return length(second - first);
	}

	/*!
	Normalizes a Vector3, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	MUTIL_INLINE Vector3 normalize(const Vector3 &vec)
	{
#if defined(NO_FAST_INVERSE_SQRT)
		return vec * inverseSqrt(dot(vec, vec));
#else
		return vec * fastInverseSqrt(dot(vec, vec));
#endif
	}

	/*!
	Reflects a Vector3 over a normal, returning the reflected vector.

	@param vec The vector to reflect.
	@param normal The normal vector to reflect over.

	@return The reflected vector.
	*/
	MUTIL_INLINE Vector3 reflect(const Vector3 &vec, const Vector3 &normal)
	{
		return (normal * (2.0f * dot(normal, vec))) - vec;
	}

	/*!
	Refracts a Vector3 and returns the resultant vector.

	@param vec The vector to refract.
	@param normal The normal of the refracting surface.
	@param index The ratio between two indicies of refraction.
	*/
	MUTIL_INLINE Vector3 refract(const Vector3 &vec, const Vector3 &normal, const float ratio)
	{
#if defined(USE_SIMD)
		float sqrtresult = 1 - (ratio * ratio) * dot(cross(normal, vec), cross(normal, vec));
		_mm_store_ss(&sqrtresult, _mm_sqrt_ss(_mm_load_ss(&sqrtresult)));
		return ((cross(normal, cross(-normal, vec))) * ratio) - (normal * sqrtresult);
#else
		return ((cross(normal, cross(-normal, vec))) * ratio) - (normal * sqrtf(1 - (ratio * ratio) * dot(cross(normal, vec), cross(normal, vec))));
#endif
	}

	/*!
	Converts a Vector3 containing angles in degrees to radians.

	@param A Vector3 containing angles in degrees.

	@return The same vector in radians.
	*/
	MUTIL_INLINE Vector3 radians(const Vector3 &vec)
	{
		return Vector3(radians(vec.x), radians(vec.y), radians(vec.z));
	}

	/*!
	Converts a Vector3 containing angles in radians to degrees.

	@param A Vector3 containing angles in radians.

	@return The same vector in degrees.
	*/
	MUTIL_INLINE Vector3 degrees(const Vector3 &vec)
	{
		return Vector3(degrees(vec.x), degrees(vec.y), degrees(vec.z));
	}

	/*!
	Returns a Vector3 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	MUTIL_INLINE Vector3 abs(const Vector3 &vec)
	{
		return Vector3(
			vec.x < 0.0 ? -vec.x : vec.x,
			vec.y < 0.0 ? -vec.y : vec.y,
			vec.z < 0.0 ? -vec.z : vec.z
			);
	}

	// Vector4 operations

	/*!
	Returns the dot product of two Vector4's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	MUTIL_INLINE float dot(const Vector4 &first, const Vector4 &second)
	{
#if defined(USE_SIMD)
		constexpr int MASK = 0xf1;
		return _mm_cvtss_f32(_mm_dp_ps(_mm_loadu_ps((float *)&first), _mm_loadu_ps((float *)&second), MASK));
#else
		return (first.x * second.x) + (first.y * second.y) + (first.z * second.z) + (first.w * second.w);
#endif
	}

	/*!
	Returns the length of a Vector4.

	@param vec The vector to get the length of.

	@return The length.
	*/
	MUTIL_INLINE float length(const Vector4 &vec)
	{
#if defined(USE_SIMD)
		float result = dot(vec, vec);
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&result)));
		return result;
#else
		return sqrtf(dot(vec, vec));
#endif
	}

	/*!
	Finds the distance between two Vector4's.

	@param first The first vector.
	@param second The second vector.

	@return The distance between the two vectors.
	*/
	MUTIL_INLINE float distance(const Vector4 &first, const Vector4 &second)
	{
		return length(second - first);
	}

	/*!
	Normalizes a Vector4, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	MUTIL_INLINE Vector4 normalize(const Vector4 &vec)
	{
#if defined(NO_FAST_INVERSE_SQRT)
		return vec * inverseSqrt(dot(vec, vec));
#else
		return vec * fastInverseSqrt(dot(vec, vec));
#endif
	}

	/*!
	Reflects a Vector4 over a normal, returning the reflected vector.

	@param vec The vector to reflect.
	@param normal The normal vector to reflect over.

	@return The reflected vector.
	*/
	MUTIL_INLINE Vector4 reflect(const Vector4 &vec, const Vector4 &normal)
	{
		return (normal * (2.0f * dot(normal, vec))) - vec;
	}

	/*!
	Converts a Vector4 containing angles in degrees to radians.

	@param A Vector4 containing angles in degrees.

	@return The same vector in radians.
	*/
	MUTIL_INLINE Vector4 radians(const Vector4 &vec)
	{
		return Vector4(radians(vec.x), radians(vec.y), radians(vec.z), radians(vec.w));
	}

	/*!
	Converts a Vector3 containing angles in radians to degrees.

	@param A Vector3 containing angles in radians.

	@return The same vector in degrees.
	*/
	MUTIL_INLINE Vector4 degrees(const Vector4 &vec)
	{
		return Vector4(degrees(vec.x), degrees(vec.y), degrees(vec.z), degrees(vec.w));
	}

	/*!
	Returns a Vector4 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	MUTIL_INLINE Vector4 abs(const Vector4 &vec)
	{
		return Vector4(
			vec.x < 0.0 ? -vec.x : vec.x,
			vec.y < 0.0 ? -vec.y : vec.y,
			vec.z < 0.0 ? -vec.z : vec.z,
			vec.w < 0.0 ? -vec.w : vec.w
			);
	}
}

#endif