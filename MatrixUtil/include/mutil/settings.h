#pragma once

#if __amd64__ || __amd64 || __x86_64__ || __x86_64 || _M_X64 || _M_AMD64
#define MUTIL_X86_64 1
#elif __i386__ || __i386 || _M_IX86
#define MUTIL_IA32 1
#elif __arm64__ || __arm64 || _M_ARM64
#define MUTIL_ARM64 1
#elif __arm__ || __arm || _M_ARM
#define MUTIL_ARM 1
#endif

#if !MUTIL_NO_INTRINSICS
#if MUTIL_IA32 || MUTIL_X86_64
#if __SSE4_1__ || _M_IX86_FP >= 1
#define MUTIL_USE_SSE 1
#include <xmmintrin.h>
#include <emmintrin.h>
#include <immintrin.h>
#endif
#elif MUTIL_ARM || MUTIL_ARM64
#if __ARM_NEON__
#define MUTIL_USE_NEON 1
#include <arm_neon.h>
#endif
#endif
#endif

#if _WIN32
#define MUTIL_FORCEINLINE __forceinline
#define MUTIL_VECTORCALL __vectorcall
#define MUTIL_RESTRICT __restrict
#else
#define MUTIL_FORCEINLINE inline __attribute__((always_inline))
#define MUTIL_VECTORCALL
#define MUTIL_RESTRICT __restrict__
#endif

#include <cmath>
#include <cstdint>
#include <cstdlib>
