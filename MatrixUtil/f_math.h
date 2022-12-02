/*!
\file
Contains methods for performing floating-point math operations.
*/

#pragma once

#ifndef F_MATH_H
#define F_MATH_H

#include "settings.h"

#include <math.h>

#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
#include <smmintrin.h>
#elif MUTIL_ARM
#include <arm_neon.h>
#endif
#endif

#define MUTIL_PI 3.14159265358979323846f
#define MUTIL_PI2 (3.14159265358979323846f / 2.0f)
#define MUTIL_PI4 (3.14159265358979323846f / 4.0f)
#define MUTIL_2PI (3.14159265358979323846f * 2.0f)

namespace mutil
{
	/*!
	Converts an angle in degrees into radians.

	@param An angle in degrees.

	@return The same angle in radians.
	*/
	constexpr float radians(float degrees)
	{
		return degrees / 180 * MUTIL_PI;
	}

	/*!
	Converts an angle in radians into degrees.

	@param An angle in radians.

	@return The same angle in degrees.
	*/
	constexpr float degrees(float radians)
	{
		return radians / MUTIL_PI * 180;
	}

	inline float inverseSqrt(const float num)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
		float result;
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&num)));
		return 1.0f / result;
#elif MUTIL_ARM
		float32x2_t vec = vdup_n_f32(num);
		float32x2_t sqrt = vsqrt_f32(vec);
		return 1.0f / vget_lane_f32(sqrt, 0);
#endif
#else
		return 1.0f / sqrtf(num);
#endif
	}

	inline float fastInverseSqrt(const float num)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
		float result;
		_mm_store_ss(&result, _mm_rsqrt_ss(_mm_load_ss(&num)));
		return result;
#elif MUTIL_ARM
		float32x2_t vec = vdup_n_f32(num);
		float32x2_t result = vrsqrte_f32(vec);
		result = vmul_f32(vrsqrts_f32(vmul_f32(vec, result), result), result);
		return vget_lane_f32(result, 0);
#endif
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

	constexpr float fract(float val)
	{
		constexpr long long LLMAX = 0x7fffffffffffffff;
		constexpr long long LLMIN = 0x8000000000000000;

		float floor = 0;
		if (val > LLMAX || val < LLMIN || val != val)
			floor = (float)((long long)val);
		else
		{
			floor = (float)((long long)val);
			if (floor != val && floor < 0)
				floor = floor - 1;
		}

		return val - floor;
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