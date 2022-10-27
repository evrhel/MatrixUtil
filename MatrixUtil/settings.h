#pragma once

#define MUTIL_VERSION "1.2"

#if __amd64__ || __amd64 || __x86_64__ || __x86_64 || _M_X64 || _M_AMD64
#define MUTIL_X86 1
#elif __arm__ || __aarch64__ || _M_ARM
#define MUTIL_ARM 1
#endif

#ifndef MUTIL_NO_INTRINSICS
#if MUTIL_X86
#define MUTIL_USE_INTRINSICS 1
#elif MUTIL_ARM
#if __ARM_NEON__
#define MUTIL_USE_INTRINSICS 1
#endif
#endif
#endif
