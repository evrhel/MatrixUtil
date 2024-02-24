#pragma once

#include "../settings.h"

#define MUTIL_INTMAX ((int32_t)0x7fffffff)
#define MUTIL_INTMIN ((int32_t)0x80000000)

#define MUTIL_UINTMAX ((uint32_t)0xffffffff)
#define MUTIL_UINTMIN ((uint32_t)0x00000000)

namespace mutil
{
    constexpr int32_t clamp(int32_t val, int32_t min, int32_t max)
	{
		return val < min ? min : ((val > max) ? max : val);
	}

    constexpr int32_t min(int32_t a, int32_t b)
    {
        return a < b ? a : b;
    }

    constexpr int32_t max(int32_t a, int32_t b)
    {
        return a > b ? a : b;
    }

    constexpr int32_t abs(int32_t val)
    {
        return val < 0 ? -val : val;
    }

    constexpr int32_t sign(int32_t val)
    {
        return val < 0 ? -1 : (val > 0 ? 1 : 0);
    }
}
