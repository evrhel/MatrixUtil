#pragma once

#define MUTIL_VERSION_MAJOR 1
#define MUTIL_VERSION_MINOR 2
#define MUTIL_VERSION_REVISION 0
#define MUTIL_VERSION "1.2.0"

#if __amd64__ || __amd64 || __x86_64__ || __x86_64 || _M_X64 || _M_AMD64
#define MUTIL_X86 1
#elif __arm__ || __aarch64__ || _M_ARM
#define MUTIL_ARM 1
#endif

#if not MUTIL_NO_INTRINSICS
#if MUTIL_X86
#define MUTIL_USE_SSE 1
#elif MUTIL_ARM
#if __ARM_NEON__
#define MUTIL_USE_NEON 1
#endif
#endif
#endif
