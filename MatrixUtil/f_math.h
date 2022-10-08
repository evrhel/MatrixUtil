/*!
\file
Contains methods for performing floating-point math operations.
*/

#pragma once

#ifndef F_MATH_H
#define F_MATH_H

#include "settings.h"

#define _USE_MATH_DEFINES
#include <math.h>

#if defined(USE_SIMD)
#include <smmintrin.h>
#endif

namespace mutil
{
	/*!
	Converts an angle in degrees into radians.

	@param An angle in degrees.

	@return The same angle in radians.
	*/
	constexpr float radians(float degrees)
	{
		return degrees / 180 * (float)M_PI;
	}

	/*!
	Converts an angle in radians into degrees.

	@param An angle in radians.

	@return The same angle in degrees.
	*/
	constexpr float degrees(float radians)
	{
		return radians / (float)M_PI * 180;
	}

	inline float inverseSqrt(const float num)
	{
#if defined(USE_SIMD)
		float result;
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&num)));
		return 1.0f / result;
#else
		return 1.0f / sqrtf(num);
#endif
	}

	inline float fastInverseSqrt(const float num)
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
			int32_t i;
		} un;

		un.f = num;
		un.i = 0x5f3759df - (un.i >> 1);
		un.f *= threehalfs - (x2 * un.f * un.f);
		return un.f;
#endif
	}

	constexpr float clamp(float val, float min, float max)
	{
		return val < min ? min : ((val > max) ? max : val);
	}

	inline float fract(float val)
	{
		return val - floorf(val);
	}

	constexpr float lerp(float a, float b, float t)
	{
		return a + t * (b - a);
	}

	/*!
	Smoothstep function. b must be strictly greater than a.

	@param a Left edge.
	@param b Right edge.
	@param x Value to compute smoothstep at. Value is clamped to [0.0, 1.0].
	*/
	constexpr float smoothstep(float a, float b, float x)
	{
		x = clamp((x - a) / (b - a), 0.0f, 1.0f);
		return x * x * (3.0f - 2.0f * x);
	}

	/*!
	Smootherstep function. b must be strictly greater than a.

	@param a Left edge.
	@param b Right edge.
	@param x Value to compute smootherstep at. Value is clamped to [0.0, 1.0].
	*/
	constexpr float smootherstep(float a, float b, float x)
	{
		x = clamp((x - a) / (b - a), 0.0f, 1.0f);
		return x * x * x * (x * (x * 6.0f - 15.0f) + 10.f);
	}
}

#endif