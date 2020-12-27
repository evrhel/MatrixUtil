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
	inline float inverseSqrt(const float num)
	{
		return 1.0f / sqrtf(num);
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
		return (first.x * second.x) + (first.y * second.y);
	}

	/*!
	Returns the length of a Vector2.

	@param vec The vector to get the length of.

	@return The length.
	*/
	inline float length(const Vector2 &vec)
	{
		return sqrtf(vec.x * vec.x + vec.y * vec.y);
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
	Normalizes a Vector2, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	inline Vector2 normalize(const Vector2 &vec)
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
	inline Vector2 radians(const Vector2 &vec)
	{
		return Vector2(radians(vec.x), radians(vec.y));
	}

	/*!
	Converts a Vector2 containing angles in radians to degrees.

	@param A Vector2 containing angles in radians.

	@return The same vector in degrees.
	*/
	inline Vector2 degrees(const Vector2 &vec)
	{
		return Vector2(degrees(vec.x), degrees(vec.y));
	}


	/*!
	Returns a Vector2 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	inline Vector2 abs(const Vector2 &vec)
	{
		return Vector2(fabsf(vec.x), fabsf(vec.y));
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
		return (first.x * second.x) + (first.y * second.y) + (first.z * second.z);
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
		return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
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
	Normalizes a Vector3, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	inline Vector3 normalize(const Vector3 &vec)
	{
		return vec * inverseSqrt(dot(vec, vec));
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

	/*!
	Refracts a Vector3 and returns the resultant vector.

	@param vec The vector to refract.
	@param normal The normal of the refracting surface.
	@param index The ratio between two indicies of refraction.
	*/
	inline Vector3 refract(const Vector3 &vec, const Vector3 &normal, const float ratio)
	{
		return ((cross(normal, cross(-normal, vec))) * ratio) - (normal * sqrtf(1 - (ratio * ratio) * dot(cross(normal, vec), cross(normal, vec))));
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
		return Vector3(fabsf(vec.x), fabsf(vec.y), fabs(vec.z));
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
		//__m128 _mm_load_ps1 (float const* mem_addr)
		//__m128 _mm_dp_ps (__m128 a, __m128 b, const int imm8)
		static const int MASK = 0xf1;

		__m128 reg1 = _mm_loadu_ps((float *)&first);
		__m128 reg2 = _mm_loadu_ps((float *)&second);
		__m128 resultReg = _mm_dp_ps(reg1, reg2, MASK);
		return _mm_cvtss_f32(resultReg);
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
		return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w);
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
	Normalizes a Vector4, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	inline Vector4 normalize(const Vector4 &vec)
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
		return Vector4(radians(vec.x), radians(vec.y), radians(vec.z), degrees(vec.w));
	}

	/*!
	Converts a Vector3 containing angles in radians to degrees.

	@param A Vector3 containing angles in radians.

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
		return Vector4(fabsf(vec.x), fabsf(vec.y), fabs(vec.z), fabs(vec.w));
	}
}

#endif