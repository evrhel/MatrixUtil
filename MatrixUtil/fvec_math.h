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
	constexpr float clamp(float val, float min, float max)
	{
		return val < min ? min : ((val > max) ? max : val);
	}

	inline float fract(float val)
	{
		return val - floorf(val);
	}

	// Vector2 operations

	/*!
	Returns the dot product of two Vector2's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	inline float dot(const Vector2 &first, const Vector2 &second)
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
	inline float length(const Vector2 &vec)
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
			vec.y < 0.0 ? -vec.y : vec.y
			);
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

	// Vector3 operations

	/*!
	Returns the dot product of two Vector3's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	inline float dot(const Vector3 &first, const Vector3 &second)
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
	inline Vector3 cross(const Vector3 &first, const Vector3 &second)
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
	inline float length(const Vector3 &vec)
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
			vec.z < 0.0 ? -vec.z : vec.z
			);
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

	// Vector4 operations

	/*!
	Returns the dot product of two Vector4's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	inline float dot(const Vector4 &first, const Vector4 &second)
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
	inline float length(const Vector4 &vec)
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
			vec.w < 0.0 ? -vec.w : vec.w
			);
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
}

#endif