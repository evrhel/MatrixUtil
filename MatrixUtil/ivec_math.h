/*!
\file
Contains methods for performing operations on floating-point vectors.
*/

#pragma once

#ifndef IVEC_MATH_H
#define IVEC_MATH_H

#include "settings.h"
#include "vec_types.h"

#include <cmath>
#include "f_math.h"

#if defined(USE_SIMD)
#include <smmintrin.h>
#endif

namespace mutil
{
	// IntVector2 operations

	/*!
	Returns the dot product of two IntVector2's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	MUTIL_INLINE uint32_t dot(const IntVector2 &first, const IntVector2 &second)
	{
		return (first.x * second.x) + (first.y * second.y);
	}

	/*!
	Returns the length of a IntVector2.

	@param vec The vector to get the length of.

	@return The length.
	*/
	MUTIL_INLINE uint32_t length(const IntVector2 &vec)
	{
#if defined(USE_SIMD)
		float result = (float)dot(vec, vec);
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&result)));
		return (uint32_t)result;
#else
		return (uint32_t)sqrtf((float)dot(vec, vec));
#endif
	}

	/*!
	Finds the distance between two IntVector2's.

	@param first The first vector.
	@param second The second vector.

	@return The distance between the two vectors.
	*/
	MUTIL_INLINE uint32_t distance(const IntVector2 &first, const IntVector2 &second)
	{
		return length(second - first);
	}

	/*!
	Normalizes a IntVector2, making its length 1. This function does not
	guarantee that the length is exactly 1, as this function uses a fast
	approximation. For a higher-precision result, use normalizeExact.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	MUTIL_INLINE IntVector2 normalize(const IntVector2 &vec)
	{
		return vec * fastInverseSqrt(dot(vec, vec));
	}

	/*
	Normalizes a IntVector2, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	MUTIL_INLINE IntVector2 normalizeExact(const IntVector2 &vec)
	{
		return vec * inverseSqrt(dot(vec, vec));
	}


	/*!
	Reflects a IntVector2 over a normal, returning the reflected vector.

	@param vec The vector to reflect.
	@param normal The normal vector to reflect over.

	@return The reflected vector.
	*/
	MUTIL_INLINE IntVector2 reflect(const IntVector2 &vec, const IntVector2 &normal)
	{
		return (normal * (2 * dot(normal, vec))) - vec;
	}

	/*!
	Converts a IntVector2 containing angles in degrees to radians.

	@param A IntVector2 containing angles in degrees.

	@return The same vector in radians.
	*/
	MUTIL_INLINE IntVector2 radians(const IntVector2 &vec)
	{
		return IntVector2(radians(vec.x), radians(vec.y));
	}

	/*!
	Converts a IntVector2 containing angles in radians to degrees.

	@param A IntVector2 containing angles in radians.

	@return The same vector in degrees.
	*/
	MUTIL_INLINE IntVector2 degrees(const IntVector2 &vec)
	{
		return IntVector2(degrees(vec.x), degrees(vec.y));
	}

	/*!
	Returns a IntVector2 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	MUTIL_CONSTEXPR IntVector2 abs(const IntVector2 &vec)
	{
		return IntVector2(
			vec.x < 0 ? -vec.x : vec.x,
			vec.y < 0 ? -vec.y : vec.y
		);
	}

	MUTIL_CONSTEXPR IntVector2 &absthis(IntVector2 &vec)
	{
		vec.x = vec.x < 0 ? -vec.x : vec.x;
		vec.y = vec.y < 0 ? -vec.y : vec.y;
		return vec;
	}

	// Vector3 operations

	/*!
	Returns the dot product of two IntVector3's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	MUTIL_INLINE uint32_t dot(const IntVector3 &first, const IntVector3 &second)
	{
		return (first.x * second.x) + (first.y * second.y) + (first.z * second.z);
	}

	/*!
	Returns the cross product of two IntVector3's.

	@param The first vector.
	@param The second vector.

	@return The result of the cross product.
	*/
	MUTIL_INLINE IntVector3 cross(const IntVector3 &first, const IntVector3 &second)
	{
		return IntVector3(
			(first.y * second.z - second.y * first.z),
			(first.z * second.x - second.z * first.x),
			(first.x * second.y - second.x * first.y)
		);
	}

	/*!
	Returns the length of a IntVector3.

	@param vec The vector to get the length of.

	@return The length.
	*/
	MUTIL_INLINE uint32_t length(const IntVector3 &vec)
	{
#if defined(USE_SIMD)
		float result = (float)dot(vec, vec);
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&result)));
		return (uint32_t)result;
#else
		return (uint32_t)sqrtf((float)dot(vec, vec));
#endif
	}

	/*!
	Finds the distance between two IntVector3's.

	@param first The first vector.
	@param second The second vector.

	@return The distance between the two vectors.
	*/
	MUTIL_INLINE uint32_t distance(const IntVector3 &first, const IntVector3 &second)
	{
		return length(second - first);
	}

	/*!
	Normalizes a IntVector3, making its length 1. This function does not
	guarantee that the length is exactly 1, as this function uses a fast
	approximation. For a higher-precision result, use normalizeExact.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	MUTIL_INLINE IntVector3 normalize(const IntVector3 &vec)
	{
		return vec * fastInverseSqrt(dot(vec, vec));
	}

	/*
	Normalizes a IntVector3, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	MUTIL_INLINE IntVector3 normalizeExact(const IntVector3 &vec)
	{
		return vec * inverseSqrt(dot(vec, vec));
	}

	MUTIL_INLINE IntVector3 &normalizethis(IntVector3 &vec)
	{
		const float dotinvsqrt = fastInverseSqrt(dot(vec, vec));
		vec.x *= dotinvsqrt;
		vec.y *= dotinvsqrt;
		vec.z *= dotinvsqrt;
		return vec;
	}

	MUTIL_INLINE IntVector3 &normalizethisExact(IntVector3 &vec)
	{
		const float dotinvsqrt = inverseSqrt(dot(vec, vec));
		vec.x *= dotinvsqrt;
		vec.y *= dotinvsqrt;
		vec.z *= dotinvsqrt;
		return vec;
	}

	/*!
	Reflects a IntVector3 over a normal, returning the reflected vector.

	@param vec The vector to reflect.
	@param normal The normal vector to reflect over.

	@return The reflected vector.
	*/
	MUTIL_INLINE IntVector3 reflect(const IntVector3 &vec, const IntVector3 &normal)
	{
		return (normal * (2 * dot(normal, vec))) - vec;
	}

	MUTIL_INLINE IntVector3 &refractthis(IntVector3 &vec, const IntVector3 &normal)
	{
		const float twotimesdot = 2 * dot(normal, vec);
		vec.x = normal.x * twotimesdot - vec.x;
		vec.y = normal.y * twotimesdot - vec.y;
		vec.z = normal.z * twotimesdot - vec.z;
		return vec;
	}

	/*!
	Converts a IntVector3 containing angles in degrees to radians.

	@param A IntVector3 containing angles in degrees.

	@return The same vector in radians.
	*/
	MUTIL_INLINE IntVector3 radians(const IntVector3 &vec)
	{
		return IntVector3(radians(vec.x), radians(vec.y), radians(vec.z));
	}

	MUTIL_INLINE IntVector3 &radiansthis(IntVector3 &vec)
	{
		vec.x = radians(vec.x);
		vec.y = radians(vec.y);
		vec.z = radians(vec.z);
		return vec;
	}

	/*!
	Converts a IntVector3 containing angles in radians to degrees.

	@param A IntVector3 containing angles in radians.

	@return The same vector in degrees.
	*/
	MUTIL_INLINE IntVector3 degrees(const IntVector3 &vec)
	{
		return IntVector3(degrees(vec.x), degrees(vec.y), degrees(vec.z));
	}

	/*!
	Returns a Vector3 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	MUTIL_INLINE IntVector3 abs(const IntVector3 &vec)
	{
		return IntVector3(
			vec.x < 0 ? -vec.x : vec.x,
			vec.y < 0 ? -vec.y : vec.y,
			vec.z < 0 ? -vec.z : vec.z
		);
	}

	// Vector4 operations

	/*!
	Returns the dot product of two IntVector4's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	MUTIL_INLINE uint32_t dot(const IntVector4 &first, const IntVector4 &second)
	{
		return (first.x * second.x) + (first.y * second.y) + (first.z * second.z) + (first.w * second.w);
	}

	/*!
	Returns the length of a IntVector4.

	@param vec The vector to get the length of.

	@return The length.
	*/
	MUTIL_INLINE uint32_t length(const IntVector4 &vec)
	{
#if defined(USE_SIMD)
		float result = (float)dot(vec, vec);
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&result)));
		return (uint32_t)result;
#else
		return (uint32_t)sqrtf((float)dot(vec, vec));
#endif
	}

	/*!
	Finds the distance between two IntVector4's.

	@param first The first vector.
	@param second The second vector.

	@return The distance between the two vectors.
	*/
	MUTIL_INLINE uint32_t distance(const IntVector4 &first, const IntVector4 &second)
	{
		return length(second - first);
	}

	/*!
	Normalizes a IntVector4, making its length 1. This function does not
	guarantee that the length is exactly 1, as this function uses a fast
	approximation. For a higher-precision result, use normalizeExact.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	MUTIL_INLINE IntVector4 normalize(const IntVector4 &vec)
	{
		return vec * fastInverseSqrt(dot(vec, vec));
	}

	/*!
	Normalizes a IntVector4, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	MUTIL_INLINE IntVector4 normalizeExact(const IntVector4 &vec)
	{
		return vec * inverseSqrt(dot(vec, vec));
	}

	/*!
	Reflects a IntVector4 over a normal, returning the reflected vector.

	@param vec The vector to reflect.
	@param normal The normal vector to reflect over.

	@return The reflected vector.
	*/
	MUTIL_INLINE IntVector4 reflect(const IntVector4 &vec, const IntVector4 &normal)
	{
		return (normal * (2 * dot(normal, vec))) - vec;
	}

	/*!
	Converts a IntVector4 containing angles in degrees to radians.

	@param A IntVector4 containing angles in degrees.

	@return The same vector in radians.
	*/
	MUTIL_INLINE IntVector4 radians(const IntVector4 &vec)
	{
		return IntVector4(radians(vec.x), radians(vec.y), radians(vec.z), radians(vec.w));
	}

	/*!
	Converts a IntVector4 containing angles in radians to degrees.

	@param A IntVector4 containing angles in radians.

	@return The same vector in degrees.
	*/
	MUTIL_INLINE IntVector4 degrees(const IntVector4 &vec)
	{
		return IntVector4(degrees(vec.x), degrees(vec.y), degrees(vec.z), degrees(vec.w));
	}

	/*!
	Returns a Vector4 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	MUTIL_INLINE IntVector4 abs(const IntVector4 &vec)
	{
		return IntVector4(
			vec.x < 0 ? -vec.x : vec.x,
			vec.y < 0 ? -vec.y : vec.y,
			vec.z < 0 ? -vec.z : vec.z,
			vec.w < 0 ? -vec.w : vec.w
		);
	}
}

#endif