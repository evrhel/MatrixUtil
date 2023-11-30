/*!
\file
Contains methods for performing operations on floating-point vectors.
*/

#pragma once

#include "settings.h"
#include "vec_types.h"
#include "f_math.h"

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
	constexpr int32_t dot(const IntVector2 &first, const IntVector2 &second)
	{
		return (first.x * second.x) + (first.y * second.y);
	}

	constexpr int32_t lengthSq(const IntVector2 &vec)
	{
		return dot(vec, vec);
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
	constexpr int32_t dot(const IntVector3 &first, const IntVector3 &second)
	{
		return (first.x * second.x) + (first.y * second.y) + (first.z * second.z);
	}

	constexpr int32_t lengthSq(const IntVector3 &vec)
	{
		return dot(vec, vec);
	}

	/*!
	Returns the cross product of two IntVector3's.

	@param The first vector.
	@param The second vector.

	@return The result of the cross product.
	*/
	constexpr IntVector3 cross(const IntVector3 &first, const IntVector3 &second)
	{
		return IntVector3(
			(first.y * second.z - second.y * first.z),
			(first.z * second.x - second.z * first.x),
			(first.x * second.y - second.x * first.y));
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
	constexpr int32_t dot(const IntVector4 &first, const IntVector4 &second)
	{
		return (first.x * second.x) + (first.y * second.y) + (first.z * second.z) + (first.w * second.w);
	}

	constexpr int32_t lengthSq(const IntVector4 &vec)
	{
		return dot(vec, vec);
	}

	/*!
	Returns a Vector4 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	constexpr IntVector4 abs(const IntVector4 &vec)
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
