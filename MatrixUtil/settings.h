#pragma once

#if __amd64__ || __amd64 || __x86_64__ || __x86_64 || _M_X64 || _M_AMD64
#define USE_SIMD
#endif

#define MUTIL_VECTORCALL __vectorcall
#define MUTIL_INLINE inline
#define MUTIL_FORCEINLINE __forceinline
#define MUTIL_CONSTEXPR constexpr
