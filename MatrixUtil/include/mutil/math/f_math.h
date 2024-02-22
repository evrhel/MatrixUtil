/*!
\file
Contains methods for performing floating-point math operations.
*/

#pragma once

#include "../settings.h"

#define MUTIL_INFINITY ((float)(1e+300 * 1e+300))
#define MUTIL_NEG_INFINITY (-MUTIL_INFINITY)
#define MUTIL_NAN (MUTIL_INFINITY * 0.0f)

#define MUTIL_PI (3.14159265358979323846f)
#define MUTIL_1_PI (1.0f / 3.14159265358979323846f)
#define MUTIL_2_PI (2.0f / 3.14159265358979323846f)
#define MUTIL_4_PI (4.0f / 3.14159265358979323846f)
#define MUTIL_PI2 (3.14159265358979323846f / 2.0f)
#define MUTIL_PI4 (3.14159265358979323846f / 4.0f)
#define MUTIL_2PI (3.14159265358979323846f * 2.0f)
#define MUTIL_3PI2 ((3.0f * 3.14159265358979323846f) / 2.0f)

#define MUTIL_D2R (MUTIL_PI / 180.0f)
#define MUTIL_R2D (180.0f / MUTIL_PI)

#define MUTIL_SQRT2 (1.41421356237309504880f)

#define MUTIL_E (2.71828182845904523536f)

namespace mutil
{
	/*!
	Converts an angle in degrees into radians.

	@param An angle in degrees.

	@return The same angle in radians.
	*/
	constexpr float radians(float degrees)
	{
		return degrees * MUTIL_D2R;
	}

	/*!
	Converts an angle in radians into degrees.

	@param An angle in radians.

	@return The same angle in degrees.
	*/
	constexpr float degrees(float radians)
	{
		return radians * MUTIL_R2D;
	}

	constexpr float sgn(float x)
	{
		if (x < 0)
			return -1;
		if (x > 0)
			return 1;
		return 0;
	}

	constexpr float min(float x, float y)
	{
		return x < y ? x : y;
	}

	constexpr float max(float x, float y)
	{
		return x > y ? x : y;
	}

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL sqrt(float x)
	{
#if MUTIL_USE_SSE
		return _mm_cvtss_f32(_mm_sqrt_ss(_mm_set_ss(x)));
#elif MUTIL_USE_NEON
		return vget_lane_f32(vsqrt_f32(vdup_n_f32(x)), 0);
#else
		return sqrtf(x);
#endif
	}

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL inverseSqrt(float num)
	{
#if MUTIL_USE_SSE
		return _mm_cvtss_f32(_mm_rcp_ss(_mm_sqrt_ss(_mm_set_ss(num))));
#elif MUTIL_USE_NEON
		return vget_lane_f32(vrecpe_f32(vsqrt_f32(vdup_n_f32(num))), 0);
#else
		return 1.0f / sqrtf(num);
#endif
	}

	inline float MUTIL_VECTORCALL fastInverseSqrt(float num)
	{
#if MUTIL_USE_SSE
		return _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ss(num)));
#elif MUTIL_USE_NEON
		float32x2_t vec = vdup_n_f32(num);
		float32x2_t result = vrsqrte_f32(vec);
		result = vmul_f32(vrsqrts_f32(vmul_f32(vec, result), result), result);
		return vget_lane_f32(result, 0);
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
		return x < 0 ? -x : x;
	}

	constexpr float clamp(float val, float min, float max)
	{
		return val < min ? min : ((val > max) ? max : val);
	}

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL ceil(float x)
	{
#if MUTIL_USE_SSE
		return _mm_cvtss_f32(_mm_round_ss(_mm_set_ss(0.0f), _mm_set_ss(x), _MM_FROUND_CEIL));
#elif MUTIL_USE_NEON
		float32x2_t result = vcvt_f32_s32(vcvt_s32_f32(vdup_n_f32(x)));
		return vget_lane_f32(result, 0) + (x > vget_lane_f32(result, 0));
#else
		return ceilf(x);
#endif
	}

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL floor(float x)
	{
#if MUTIL_USE_SSE
		return _mm_cvtss_f32(_mm_round_ss(_mm_set_ss(0.0f), _mm_set_ss(x), _MM_FROUND_FLOOR));
#elif MUTIL_USE_NEON
		float32x2_t result = vcvt_f32_s32(vcvt_s32_f32(vdup_n_f32(x)));
		return vget_lane_f32(result, 0) - (x < vget_lane_f32(result, 0));
#else
		return floorf(x);
#endif
	}

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL trunc(float x)
	{
		return x < 0 ? ceil(x) : floor(x);
	}

	inline float MUTIL_VECTORCALL mod(float a, float b)
	{
#if MUTIL_USE_SSE
		__m128 result = _mm_set_ss(a);
		__m128 divisor = _mm_set_ss(b);
		__m128 quotient = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_mul_ss(result, _mm_rcp_ss(divisor))));
		return _mm_cvtss_f32(_mm_sub_ss(result, _mm_mul_ss(quotient, divisor)));
#elif MUTIL_USE_NEON
		float32x2_t result = vdup_n_f32(a);
		float32x2_t divisor = vdup_n_f32(b);
		float32x2_t quotient = vcvt_f32_s32(vcvt_s32_f32(vdiv_f32(result, divisor)));
		return vget_lane_f32(vsub_f32(result, vmul_f32(quotient, divisor)), 0);
#else
		return a - trunc(a / b) * b;
#endif
	}

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL fract(float x)
	{
#if MUTIL_USE_SSE
		return _mm_cvtss_f32(_mm_round_ss(_mm_set_ss(0.0f), _mm_set_ss(x), _MM_FROUND_TO_NEAREST_INT));
#elif MUTIL_USE_NEON
		float32x2_t f = vcvt_f32_s32(vcvt_s32_f32(vdup_n_f32(x)));
		return vget_lane_f32(vsub_f32(vdup_n_f32(x), f), 0);
#else
		return x - floor(x);
#endif
	}

	MUTIL_FORCEINLINE float MUTIL_VECTORCALL round(float val)
	{
#if MUTIL_USE_SSE
		return _mm_cvtss_f32(_mm_round_ss(_mm_set_ss(0.0f), _mm_set_ss(val), _MM_FROUND_TO_NEAREST_INT));
#else
		return roundf(val);
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

	// utility
	namespace __1
	{
#if MUTIL_USE_SSE
#elif MUTIL_USE_NEON
		inline float32x2_t makev2(float x, float y)
		{
			float32x2_t result = vdup_n_f32(x);
			return vset_lane_f32(y, result, 1);
		}

		// return sin(x), cos(x), x [-pi, pi]
		inline float32x2_t sincos(float x)
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

			float32x2_t t1 = makev2(x, 1.0f);
			t1 = vadd_f32(t1, makev2(x3 * _n3fact, x2 * _n2fact));
			t1 = vadd_f32(t1, makev2(x5 * _5fact, x4 * _4fact));
			t1 = vadd_f32(t1, makev2(x7 * _n7fact, x6 * _n6fact));
			t1 = vadd_f32(t1, makev2(x9 * _9fact, x8 * _8fact));
			t1 = vadd_f32(t1, makev2(x11 * _n11fact, x10 * _n10fact));

			return t1;
		}
#endif

		MUTIL_FORCEINLINE uint32_t MUTIL_VECTORCALL f2i(float x)
		{
#if MUTIL_USE_SSE
			return _mm_cvtsi128_si32(_mm_castps_si128(_mm_set_ss(x)));
#else
			union
			{
				float f;
				uint32_t i;
			} u = {x};
			return u.i;
#endif
		}

		MUTIL_FORCEINLINE float MUTIL_VECTORCALL i2f(uint32_t x)
		{
#if MUTIL_USE_SSE
			return _mm_cvtss_f32(_mm_castsi128_ps(_mm_set1_epi32(x)));
#else
			union
			{
				uint32_t i;
				float f;
			} u = {x};
			return u.f;
#endif
		}

		// wrap x to [-pi, pi]
		MUTIL_FORCEINLINE float MUTIL_VECTORCALL wrapnpipi(float x)
		{
			x = mod(x, MUTIL_2PI);
			if (x > MUTIL_PI)
				x -= MUTIL_2PI;
			else if (x < -MUTIL_PI)
				x += MUTIL_2PI;
			return x;
		}

#if MUTIL_USE_SSE
		MUTIL_FORCEINLINE __m128 MUTIL_VECTORCALL cos_impl(__m128 x)
		{
			const __m128 pi2 = _mm_set_ss(MUTIL_PI * MUTIL_PI);
			__m128 x2 = _mm_mul_ss(x, x);
			__m128 lhs = _mm_add_ss(pi2, _mm_mul_ss(_mm_set_ss(-4.0f), x2));
			__m128 rhs = _mm_rcp_ss(_mm_add_ss(pi2, x2));
			return _mm_mul_ss(lhs, rhs);
		}

		MUTIL_FORCEINLINE __m128 MUTIL_VECTORCALL log2_impl(__m128 x)
		{
			constexpr float t1 = 0.584963f;
			constexpr float t2 = 0.961797f;
			constexpr float t3 = -0.320599f;
			constexpr float t4 = 0.142488f;

			constexpr float _1lhs23 = 1.0f / (1 << 23);

			__m128i i = _mm_castps_si128(x);
			__m128 M = _mm_cvtepi32_ps(_mm_and_si128(i, _mm_set1_epi32(0x7fffff)));
			__m128 E = _mm_cvtepi32_ps(_mm_add_epi32(_mm_srli_epi32(i, 23), _mm_set1_epi32(-127)));

			float a = _mm_cvtss_f32(_mm_add_ss(_mm_mul_ss(M, _mm_set_ss(_1lhs23)), _mm_set_ss(-0.5f)));
			float a2 = a * a;
			float a3 = a2 * a;

			const __m128 v1r = _mm_set_ps(t4, t3, t2, t1);
			__m128 v2r = _mm_set_ps(a3, a2, a, 1.0f);
			__m128 v = _mm_dp_ps(v1r, v2r, 0xf1);

			return _mm_add_ss(v, E);
		}
#elif MUTIL_USE_NEON
#else
		constexpr float cos_impl(float x)
		{
			constexpr float pi2 = MUTIL_PI * MUTIL_PI;
			const float x2 = x * x;
			float top = pi2 - 4.0f * x2;
			float bottom = pi2 + x2;
			return top / bottom;
		}
#endif
	};

	inline float MUTIL_VECTORCALL sin(float x)
	{
		// https://mooooo.ooo/chebyshev-sine-approximation/

		constexpr float c1 = -0.10132118f;
		constexpr float c2 = 0.0066208798f;
		constexpr float c3 = -0.00017350505f;
		constexpr float c4 = 0.0000025222919f;
		constexpr float c5 = -0.000000023317787f;
		constexpr float c6 = 0.00000000013291342f;

		constexpr float pimaj = 3.14159265358979323846f;
		constexpr float pimin = -0.00000008742278f;
		constexpr float npimajmpimin = -pimaj - pimin;
		constexpr float pimajpimin = pimaj + pimin;

		x = __1::wrapnpipi(x);

#if MUTIL_USE_SSE
		__m128 xr = _mm_set_ss(x);
		__m128 x2 = _mm_mul_ss(xr, xr);

		__m128 tmp0, tmp1;
		tmp0 = _mm_set_ss(c6);
		tmp1 = _mm_add_ss(_mm_mul_ss(tmp0, x2), _mm_set_ss(c5));
		tmp0 = _mm_add_ss(_mm_mul_ss(tmp1, x2), _mm_set_ss(c4));
		tmp1 = _mm_add_ss(_mm_mul_ss(tmp0, x2), _mm_set_ss(c3));
		tmp0 = _mm_add_ss(_mm_mul_ss(tmp1, x2), _mm_set_ss(c2));
		tmp1 = _mm_add_ss(_mm_mul_ss(tmp0, x2), _mm_set_ss(c1));

		__m128 a = _mm_add_ss(xr, _mm_set_ss(-MUTIL_PI - pimin));
		__m128 b = _mm_add_ss(xr, _mm_set_ss(MUTIL_PI + pimin));
		__m128 c = _mm_mul_ss(tmp1, xr);

		__m128 result = _mm_mul_ss(a, _mm_mul_ss(b, c));
		return _mm_cvtss_f32(result);
#elif MUIL_USE_NEON
#else
		const float x2 = x * x;
		float p11 = c6;
		float p9 = p11 * x2 + c5;
		float p7 = p9 * x2 + c4;
		float p5 = p7 * x2 + c3;
		float p3 = p5 * x2 + c2;
		float p1 = p3 * x2 + c1;
		return (x + npimajmpimin) * (x + pimajpimin) * p1 * x;
#endif
	}

	inline float MUTIL_VECTORCALL cos(float x)
	{
		return sin(x + MUTIL_PI2);
	}

	inline float MUTIL_VECTORCALL tan(float x)
	{
#if _MUTIL_USE_SSE
		return _mm_cvtss_f32(_mm_tan_ps(_mm_set_ss(x)));
#else
		return tanf(x);
#endif
	}

	inline float MUTIL_VECTORCALL asin(float x)
	{
		// https://developer.download.nvidia.com/cg/asin.html
#if MUTIL_USE_SSE
		__m128 negate = _mm_set_ss(x < 0);
		__m128 xr = _mm_set_ss(mutil::abs(x));

		__m128 ret = _mm_set_ss(-0.0187293f);
		ret = _mm_mul_ss(ret, xr);
		ret = _mm_add_ss(ret, _mm_set_ss(0.0742610f));
		ret = _mm_mul_ss(ret, xr);
		ret = _mm_add_ss(ret, _mm_set_ss(-0.2121144f));
		ret = _mm_mul_ss(ret, xr);
		ret = _mm_add_ss(ret, _mm_set_ss(1.5707288f));
		ret = _mm_sub_ss(_mm_set_ss(MUTIL_PI2), _mm_mul_ss(_mm_sqrt_ss(_mm_sub_ss(_mm_set_ss(1.0f), xr)), ret));
		ret = _mm_add_ss(ret, _mm_mul_ss(_mm_set_ss(-2.0f), _mm_mul_ss(negate, ret)));
		return _mm_cvtss_f32(ret);
#else
		float negate = x < 0;
		x = abs(x);
		float ret = -0.0187293f;
		ret *= x;
		ret += 0.0742610f;
		ret *= x;
		ret -= 0.2121144f;
		ret *= x;
		ret += 1.5707288f;
		ret = MUTIL_PI * 0.5f - mutil::sqrt(1.0f - x) * ret;
		return ret - 2.0f * negate * ret;
#endif
	}

	inline float MUTIL_VECTORCALL acos(float x)
	{
		// https://developer.download.nvidia.com/cg/acos.html

#if MUTIL_USE_SSE
		__m128 negate = _mm_set_ss(x < 0);
		__m128 xr = _mm_set_ss(mutil::abs(x));

		__m128 ret = _mm_set_ss(-0.0187293f);
		ret = _mm_mul_ss(ret, xr);
		ret = _mm_add_ss(ret, _mm_set_ss(0.0742610f));
		ret = _mm_mul_ss(ret, xr);
		ret = _mm_add_ss(ret, _mm_set_ss(-0.2121144f));
		ret = _mm_mul_ss(ret, xr);
		ret = _mm_add_ss(ret, _mm_set_ss(1.5707288f));
		ret = _mm_mul_ss(ret, _mm_sqrt_ss(_mm_sub_ss(_mm_set_ss(1.0f), xr)));
		ret = _mm_add_ss(ret, _mm_mul_ss(_mm_set_ss(-2.0f), _mm_mul_ss(negate, ret)));
		ret = _mm_add_ss(_mm_mul_ss(negate, _mm_set_ss(MUTIL_PI)), ret);
		return _mm_cvtss_f32(ret);
#else
		float negate = x < 0;
		x = mutil::abs(x);
		float ret = -0.0187293f;
		ret = ret * x;
		ret = ret + 0.0742610f;
		ret = ret * x;
		ret = ret - 0.2121144f;
		ret = ret * x;
		ret = ret + 1.5707288f;
		ret = ret * mutil::sqrt(1.0f - x);
		ret = ret - 2.0f * negate * ret;
		return negate * 3.14159265358979f + ret;
#endif
	}

	inline float MUTIL_VECTORCALL atan(float x)
	{
		// https://journalofinequalitiesandapplications.springeropen.com/articles/10.1186/s13660-018-1734-7

#if MUTIL_USE_SSE
		const __m128 pisq = _mm_set_ss(MUTIL_PI * MUTIL_PI);
		const __m128 twopi = _mm_set_ss(MUTIL_2PI);
		__m128 xr = _mm_set_ss(x);

		__m128 top = _mm_mul_ss(pisq, xr);

		__m128 tmp = _mm_mul_ss(twopi, xr);
		tmp = _mm_mul_ss(tmp, tmp);
		__m128 bottom = _mm_add_ss(_mm_set_ss(4.0f), _mm_sqrt_ss(_mm_add_ss(_mm_set_ss(32.0f), tmp)));

		__m128 result = _mm_mul_ss(top, _mm_rcp_ss(bottom));
		return _mm_cvtss_f32(result);
#else
		float r;
		float s = sgn(x);
		x = abs(x);

		if (x <= 1)
			r = MUTIL_PI4 * x - x * (x - 1) * (0.2447f + 0.0663f * x);
		else
			r = MUTIL_PI2 - (1.0f / x);

		return s * r;

		/*constexpr float pisq = MUTIL_PI * MUTIL_PI;
		const float pi2x = sqrt(MUTIL_2PI * x);
		return (pisq * x) / (4.0f + pi2x * pi2x);*/
#endif
	}

	inline float MUTIL_VECTORCALL log2(float x)
	{
#if MUTIL_USE_SSE
		return _mm_cvtss_f32(__1::log2_impl(_mm_set_ss(x)));
#else
		return log2f(x);
#endif
	}

	inline float MUTIL_VECTORCALL log(float x)
	{
#if MUTIL_USE_SSE
		constexpr float _log2e = 1.0f / 1.442695f;
		return _mm_cvtss_f32(_mm_mul_ss(__1::log2_impl(_mm_set_ss(x)), _mm_set_ss(_log2e)));
#else
		return logf(x);
#endif
	}

	inline float MUTIL_VECTORCALL log10(float x)
	{
#if MUTIL_USE_SSE
		constexpr float _log210 = 1.0f / 3.32192809f;
		return _mm_cvtss_f32(_mm_mul_ss(__1::log2_impl(_mm_set_ss(x)), _mm_set_ss(_log210)));
#else
		return log10f(x);
#endif
	}
}
