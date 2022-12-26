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

#define MUTIL_PI (3.14159265358979323846f)
#define MUTIL_1_PI (1.0f / 3.14159265358979323846f)
#define MUTIL_2_PI (2.0f / 3.14159265358979323846f)
#define MUTIL_PI2 (3.14159265358979323846f / 2.0f)
#define MUTIL_PI4 (3.14159265358979323846f / 4.0f)
#define MUTIL_2PI (3.14159265358979323846f * 2.0f)
#define MUTIL_NAN (0.0f / 0.0f)

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

	constexpr float sgn(float x)
	{
		if (x < 0)
			return -1;
		if (x > 0)
			return 1;
		return 0;
	}

	inline float sqrt(float x)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
		float result;
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&x)));
		return result;
#elif MUTIL_ARM
		return vget_lane_f32(vsqrt_f32(vdup_n_f32(x)), 0);
#endif
#else
		return sqrtf(x);
#endif
	}

	inline float inverseSqrt(const float num)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
		float result;
		_mm_store_ss(&result, _mm_sqrt_ss(_mm_load_ss(&num)));
		return 1.0f / result;
#elif MUTIL_ARM
		return vget_lane_f32(vrecpe_f32(vsqrt_f32(vdup_n_f32(num))), 0);
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

	constexpr float abs(float x)
	{
		union
		{
			float f;
			int32_t i;
		} un = {x};
		un.i &= 0x7fffffff;
		return un.f;
	}

	constexpr float clamp(float val, float min, float max)
	{
		return val < min ? min : ((val > max) ? max : val);
	}

	inline float ceil(float x)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
#elif MUTIL_ARM
		float32x2_t result = vcvt_f32_s32(vcvt_s32_f32(vdup_n_f32(x)));
		return vget_lane_f32(result, 0) + (x > vget_lane_f32(result, 0));
#endif
#elif
		return ceilf(x);
#endif
	}

	inline float floor(float x)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
#elif MUTIL_ARM
		float32x2_t result = vcvt_f32_s32(vcvt_s32_f32(vdup_n_f32(x)));
		return vget_lane_f32(result, 0) - (x < vget_lane_f32(result, 0));
#endif
#elif
		return floorf(x);
#endif
	}

	inline float mod(float a, float b)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
#elif MUTIL_ARM
		float32x2_t result = vdup_n_f32(a);
		float32x2_t divisor = vdup_n_f32(b);
		float32x2_t quotient = vcvt_f32_s32(vcvt_s32_f32(vdiv_f32(result, divisor)));
		return vget_lane_f32(vsub_f32(result, vmul_f32(quotient, divisor)), 0);
#endif
#else
		return fmodf(a, b);
#endif
	}

	inline float fract(float val)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
#elif MUTIL_ARM
		float32x2_t result = vcvt_f32_s32(vcvt_s32_f32(vdup_n_f32(val)));
		return vget_lane_f32(vsub_f32(vdup_n_f32(val), result), 0);
#endif
#else
		return val - floor(val);
#endif
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

#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
#elif MUTIL_ARM

	// make vector from two floats
	inline float32x2_t __makev2(float x, float y)
	{
		float32x2_t result = vdup_n_f32(x);
		return vset_lane_f32(y, result, 1);
	}

	// return sin(x), cos(x), x [-pi, pi]
	inline float32x2_t __sincos_neon(float x)
	{
		constexpr float _n2fact = -1.0f / 2.0f;
		constexpr float _n3fact = -1.0f / 6.0f;
		constexpr float _4fact = 1.0f / 24.0f;
		constexpr float _5fact = 1.0f / 120.0f;
		constexpr float _n6fact = -1.0f / 720.0f;
		constexpr float _n7fact = -1.0f / 5040.0f;
		constexpr float _8fact = 1.0f / 40320.0f;
		constexpr float _9fact = 1.0f / 362880.0f;
		constexpr float _n10fact = -1.0f / 3628800.0f;
		constexpr float _n11fact = -1.0f / 39916800.0f;

		const float x2 = x * x;
		const float x3 = x2 * x;
		const float x4 = x2 * x2;
		const float x5 = x4 * x;
		const float x6 = x3 * x3;
		const float x7 = x6 * x;
		const float x8 = x4 * x4;
		const float x9 = x8 * x;
		const float x10 = x5 * x5;
		const float x11 = x10 * x;

		float32x2_t t1 = __makev2(x, 1.0f);
		t1 = vadd_f32(t1, __makev2(x3 * _n3fact, x2 * _n2fact));
		t1 = vadd_f32(t1, __makev2(x5 * _5fact, x4 * _4fact));
		t1 = vadd_f32(t1, __makev2(x7 * _n7fact, x6 * _n6fact));
		t1 = vadd_f32(t1, __makev2(x9 * _9fact, x8 * _8fact));
		t1 = vadd_f32(t1, __makev2(x11 * _n11fact, x10 * _n10fact));

		return t1;
	}

#endif
#endif

	// wrap x to [-pi, pi]
	inline float __wrapnpipi(float x)
	{
		x = mod(x, MUTIL_2PI);
		if (x > MUTIL_PI)
			x -= MUTIL_2PI;
		else if (x < -MUTIL_PI)
			x += MUTIL_2PI;
		return x;
	}

	inline float sin(float x)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
#elif MUTIL_ARM
		return vget_lane_f32(__sincos_neon(__wrapnpipi(x)), 0);
#endif
#else
		return sinf(x);
#endif
	}

	inline float cos(float x)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
#elif MUTIL_ARM
		return vget_lane_f32(__sincos_neon(__wrapnpipi(x)), 1);
#endif
#else
		return cosf(x);
#endif
	}

	inline float tan(float x)
	{
#if MUTIL_USE_INTRINSICS
#if MUTIL_X86
#elif MUTIL_ARM
		float32x2_t sc = __sincos_neon(__wrapnpipi(x));
		return vget_lane_f32(sc, 0) / vget_lane_f32(sc, 1);
#endif
#else
		return tanf(x);
#endif
	}

	inline float asin(float x)
	{
		constexpr float coeff1 = 1.0f / 6.0f;
		constexpr float coeff2 = 3.0f / 40.0f;
		constexpr float coeff3 = 5.0f / 112.0f;
		constexpr float coeff4 = 35.0f / 1152.0f;
		constexpr float coeff5 = 63.0f / 2816.0f;
		constexpr float coeff6 = 231.0f / 13312.0f;

		if (x < -1.0f || x > 1.0f)
			return MUTIL_NAN;
		if (x == -1.0f)
			return -MUTIL_PI2;
		if (x == 1.0f)
			return MUTIL_PI2;

		const float x3 = x * x * x;
		const float x5 = x3 * x * x;
		const float x7 = x5 * x * x;
		const float x9 = x7 * x * x;
		const float x11 = x9 * x * x;
		const float x13 = x11 * x * x;

		return x + (coeff1 * x3) + (coeff2 * x5) + (coeff3 * x7) + (coeff4 * x9) + (coeff5 * x11) + (coeff6 * x13);
	}

	inline float acos(float x)
	{
		constexpr float coeff1 = 1.0f / 6.0f;
		constexpr float coeff2 = 3.0f / 40.0f;
		constexpr float coeff3 = 5.0f / 112.0f;
		constexpr float coeff4 = 35.0f / 1152.0f;
		constexpr float coeff5 = 63.0f / 2816.0f;
		constexpr float coeff6 = 231.0f / 133312.0f;

		if (x < -1.0f || x > 1.0f)
			return MUTIL_NAN;
		if (x == -1.0f)
			return MUTIL_PI;
		if (x == 1.0f)
			return 0.0f;

		const float x3 = x * x * x;
		const float x5 = x3 * x * x;
		const float x7 = x5 * x * x;
		const float x9 = x7 * x * x;
		const float x11 = x9 * x * x;
		const float x13 = x11 * x * x;

		return MUTIL_PI2 - x - (coeff1 * x3) - (coeff2 * x5) - (coeff3 * x7) - (coeff4 * x9) - (coeff5 * x11) - (coeff6 * x13);
	}

	// accurate for (-inf, -1.1308)U(1.1308, inf)
	constexpr float __atan_inv_taylor(float x)
	{
		const float ix = 1.0f / x;
		const float ix3 = ix * ix * ix;
		const float ix5 = ix3 * ix * ix;
		const float ix7 = ix5 * ix * ix;
		const float ix9 = ix7 * ix * ix;
		const float ix11 = ix9 * ix * ix;
		const float ix13 = ix11 * ix * ix;

		float rhs = ix - (ix3 / 3) + (ix5 / 5) - (ix7 / 7) + (ix9 / 9) - (ix11 / 11) + (ix13 / 13);
		return MUTIL_PI2 * sgn(x) - rhs;
	}

	// https://www.ncbi.nlm.nih.gov/pmc/articles/PMC6928950/
	// accurate for (-1.1308, 1.1308)
	constexpr float __atan_fast_arctan(float x)
	{
		constexpr float b1 = 0.0443f;
		constexpr float b2 = 0.2410f;

		const float x2 = x * x;

		return x / (1.0f + (b1 * abs(x)) + (b2 * x2));
	}

	// fast atan approximation with a maximum error of 0.0063 at +-1.1308
	constexpr float atan(float x)
	{
		if (x < -1.1308f || x > 1.1308f)
			return __atan_inv_taylor(x);
		else
			return __atan_fast_arctan(x);
	}
}

#endif