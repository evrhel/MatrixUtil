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

#if defined(MUTIL_USE_INTRINSICS)
#if defined(MUTIL_X86)
#include <smmintrin.h>
#elif defined(MUTIL_ARM)
#endif
#endif

namespace mutil
{
	constexpr int32_t clamp(int32_t val, int32_t min, int32_t max)
	{
		return val < min ? min : ((val > max) ? max : val);
	}

	// IntVector2 operations

	/*!
	Returns the dot product of two IntVector2's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	inline int32_t dot(const IntVector2 &first, const IntVector2 &second)
	{
		return (first.x * second.x) + (first.y * second.y);
	}

	/*!
	Returns the length of a IntVector2.

	@param vec The vector to get the length of.

	@return The length.
	*/
	inline int32_t length(const IntVector2 &vec)
	{
#if defined(MUTIL_USE_INTRINSICS)
#if defined(MUTIL_X86)
		float result = (float)dot(vec, vec);
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&result)));
		return (int32_t)result;
#elif defined(MUTIL_ARM)
		return (int32_t)sqrtf((float)dot(vec, vec));
#endif
#else
		return (int32_t)sqrtf((float)dot(vec, vec));
#endif
	}

	/*!
	Finds the distance between two IntVector2's.

	@param first The first vector.
	@param second The second vector.

	@return The distance between the two vectors.
	*/
	inline int32_t distance(const IntVector2 &first, const IntVector2 &second)
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
	inline IntVector2 normalize(const IntVector2 &vec)
	{
		return IntVector2(normalize(Vector2(vec)));
	}

	/*
	Normalizes a IntVector2, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	inline IntVector2 normalizeExact(const IntVector2 &vec)
	{
		return IntVector2(normalizeExact(Vector2(vec)));
	}

	/*!
	Reflects a IntVector2 over a normal, returning the reflected vector.

	@param vec The vector to reflect.
	@param normal The normal vector to reflect over.

	@return The reflected vector.
	*/
	inline IntVector2 reflect(const IntVector2 &vec, const IntVector2 &normal)
	{
		return (normal * (2 * dot(normal, vec))) - vec;
	}

	/*!
	Converts a IntVector2 containing angles in degrees to radians.

	@param A IntVector2 containing angles in degrees.

	@return The same vector in radians.
	*/
	inline IntVector2 radians(const IntVector2 &vec)
	{
		return IntVector2((int32_t)radians((float)vec.x), (int32_t)radians((float)vec.y));
	}

	/*!
	Converts a IntVector2 containing angles in radians to degrees.

	@param A IntVector2 containing angles in radians.

	@return The same vector in degrees.
	*/
	inline IntVector2 degrees(const IntVector2 &vec)
	{
		return IntVector2((int32_t)degrees((float)vec.x), (int32_t)degrees((float)vec.y));
	}

	/*!
	Returns a IntVector2 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	constexpr IntVector2 abs(const IntVector2 &vec)
	{
		return IntVector2(
			vec.x < 0 ? -vec.x : vec.x,
			vec.y < 0 ? -vec.y : vec.y);
	}

	constexpr IntVector2 &absthis(IntVector2 &vec)
	{
		vec.x = vec.x < 0 ? -vec.x : vec.x;
		vec.y = vec.y < 0 ? -vec.y : vec.y;
		return vec;
	}

	constexpr IntVector2 clamp(const IntVector2 &val, int32_t min, int32_t max)
	{
		IntVector2 result;
		for (size_t i = 0; i < 2; i++)
			result[i] = clamp(val[i], min, max);
		return result;
	}

	constexpr IntVector2 clamp(const IntVector2 &val, const IntVector2 &min, const IntVector2 &max)
	{
		IntVector2 result;
		for (size_t i = 0; i < 2; i++)
			result[i] = clamp(val[i], min[i], max[i]);
		return result;
	}

	// Vector3 operations

	/*!
	Returns the dot product of two IntVector3's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	inline int32_t dot(const IntVector3 &first, const IntVector3 &second)
	{
		return (first.x * second.x) + (first.y * second.y) + (first.z * second.z);
	}

	/*!
	Returns the cross product of two IntVector3's.

	@param The first vector.
	@param The second vector.

	@return The result of the cross product.
	*/
	inline IntVector3 cross(const IntVector3 &first, const IntVector3 &second)
	{
		return IntVector3(
			(first.y * second.z - second.y * first.z),
			(first.z * second.x - second.z * first.x),
			(first.x * second.y - second.x * first.y));
	}

	/*!
	Returns the length of a IntVector3.

	@param vec The vector to get the length of.

	@return The length.
	*/
	inline int32_t length(const IntVector3 &vec)
	{
#if defined(MUTIL_USE_INTRINSICS)
#if defined(MUTIL_X86)
		float result = (float)dot(vec, vec);
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&result)));
		return (int32_t)result;
#elif defined(MUTIL_ARM)
		return (int32_t)sqrtf((float)dot(vec, vec));
#endif
#else
		return (int32_t)sqrtf((float)dot(vec, vec));
#endif
	}

	/*!
	Finds the distance between two IntVector3's.

	@param first The first vector.
	@param second The second vector.

	@return The distance between the two vectors.
	*/
	inline int32_t distance(const IntVector3 &first, const IntVector3 &second)
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
	inline IntVector3 normalize(const IntVector3 &vec)
	{
		return IntVector3(normalize(Vector3(vec)));
	}

	/*
	Normalizes a IntVector3, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	inline IntVector3 normalizeExact(const IntVector3 &vec)
	{
		return IntVector3(normalizeExact(Vector3(vec)));
	}

	inline IntVector3 &normalizethis(IntVector3 &vec)
	{
		Vector3 normalized = normalize(Vector3(vec));
		vec = IntVector3(normalized);
		return vec;
	}

	inline IntVector3 &normalizethisExact(IntVector3 &vec)
	{
		Vector3 normalized = normalizeExact(Vector3(vec));
		vec = IntVector3(normalized);
		return vec;
	}

	/*!
	Reflects a IntVector3 over a normal, returning the reflected vector.

	@param vec The vector to reflect.
	@param normal The normal vector to reflect over.

	@return The reflected vector.
	*/
	inline IntVector3 reflect(const IntVector3 &vec, const IntVector3 &normal)
	{
		return (normal * (2 * dot(normal, vec))) - vec;
	}

	inline IntVector3 &refractthis(IntVector3 &vec, const IntVector3 &normal)
	{
		const int32_t twotimesdot = 2 * dot(normal, vec);
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
	inline IntVector3 radians(const IntVector3 &vec)
	{
		return IntVector3((int32_t)radians((float)vec.x), (int32_t)radians((float)vec.y), (int32_t)radians((float)vec.z));
	}

	inline IntVector3 &radiansthis(IntVector3 &vec)
	{
		vec.x = (int32_t)radians((float)vec.x);
		vec.y = (int32_t)radians((float)vec.y);
		vec.z = (int32_t)radians((float)vec.z);
		return vec;
	}

	/*!
	Converts a IntVector3 containing angles in radians to degrees.

	@param A IntVector3 containing angles in radians.

	@return The same vector in degrees.
	*/
	inline IntVector3 degrees(const IntVector3 &vec)
	{
		return IntVector3((int32_t)degrees((float)vec.x), (int32_t)degrees((float)vec.y), (int32_t)degrees((float)vec.z));
	}

	/*!
	Returns a Vector3 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	inline IntVector3 abs(const IntVector3 &vec)
	{
		return IntVector3(
			vec.x < 0 ? -vec.x : vec.x,
			vec.y < 0 ? -vec.y : vec.y,
			vec.z < 0 ? -vec.z : vec.z);
	}

	constexpr IntVector3 clamp(const IntVector3 &val, int32_t min, int32_t max)
	{
		IntVector3 result;
		for (size_t i = 0; i < 3; i++)
			result[i] = clamp(val[i], min, max);
		return result;
	}

	constexpr IntVector3 clamp(const IntVector3 &val, const IntVector3 &min, const IntVector3 &max)
	{
		IntVector3 result;
		for (size_t i = 0; i < 3; i++)
			result[i] = clamp(val[i], min[i], max[i]);
		return result;
	}

	// Vector4 operations

	/*!
	Returns the dot product of two IntVector4's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	inline int32_t dot(const IntVector4 &first, const IntVector4 &second)
	{
		return (first.x * second.x) + (first.y * second.y) + (first.z * second.z) + (first.w * second.w);
	}

	/*!
	Returns the length of a IntVector4.

	@param vec The vector to get the length of.

	@return The length.
	*/
	inline int32_t length(const IntVector4 &vec)
	{
#if defined(MUTIL_USE_INTRINSICS)
#if defined(MUTIL_X86)
		float result = (float)dot(vec, vec);
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&result)));
		return (int32_t)result;
#elif defined(MUTIL_ARM)
		return (int32_t)sqrtf((float)dot(vec, vec));
#endif
#else
		return (int32_t)sqrtf((float)dot(vec, vec));
#endif
	}

	/*!
	Finds the distance between two IntVector4's.

	@param first The first vector.
	@param second The second vector.

	@return The distance between the two vectors.
	*/
	inline int32_t distance(const IntVector4 &first, const IntVector4 &second)
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
	inline IntVector4 normalize(const IntVector4 &vec)
	{
		return IntVector4(normalize(Vector4(vec)));
	}

	/*!
	Normalizes a IntVector4, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	inline IntVector4 normalizeExact(const IntVector4 &vec)
	{
		return IntVector4(normalize(Vector4(vec)));
	}

	/*!
	Reflects a IntVector4 over a normal, returning the reflected vector.

	@param vec The vector to reflect.
	@param normal The normal vector to reflect over.

	@return The reflected vector.
	*/
	inline IntVector4 reflect(const IntVector4 &vec, const IntVector4 &normal)
	{
		return (normal * (2 * dot(normal, vec))) - vec;
	}

	/*!
	Converts a IntVector4 containing angles in degrees to radians.

	@param A IntVector4 containing angles in degrees.

	@return The same vector in radians.
	*/
	inline IntVector4 radians(const IntVector4 &vec)
	{
		return IntVector4((int32_t)radians((float)vec.x), (int32_t)radians((float)vec.y), (int32_t)radians((float)vec.z), (int32_t)radians((float)vec.w));
	}

	/*!
	Converts a IntVector4 containing angles in radians to degrees.

	@param A IntVector4 containing angles in radians.

	@return The same vector in degrees.
	*/
	inline IntVector4 degrees(const IntVector4 &vec)
	{
		return IntVector4((int32_t)degrees((float)vec.x), (int32_t)degrees((float)vec.y), (int32_t)degrees((float)vec.z), (int32_t)degrees((float)vec.w));
	}

	/*!
	Returns a Vector4 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	inline IntVector4 abs(const IntVector4 &vec)
	{
		return IntVector4(
			vec.x < 0 ? -vec.x : vec.x,
			vec.y < 0 ? -vec.y : vec.y,
			vec.z < 0 ? -vec.z : vec.z,
			vec.w < 0 ? -vec.w : vec.w);
	}

	constexpr IntVector4 clamp(const IntVector4 &val, int32_t min, int32_t max)
	{
		IntVector4 result;
		for (size_t i = 0; i < 4; i++)
			result[i] = clamp(val[i], min, max);
		return result;
	}

	constexpr IntVector4 clamp(const IntVector4 &val, const IntVector4 &min, const IntVector4 &max)
	{
		IntVector4 result;
		for (size_t i = 0; i < 4; i++)
			result[i] = clamp(val[i], min[i], max[i]);
		return result;
	}
}

#endif