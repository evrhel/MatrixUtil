/*!
\file
Contains methods for performing operations on floating-point vectors.
*/

#pragma once

#include "settings.h"

namespace mutil
{
	constexpr int32_t clamp(int32_t val, int32_t min, int32_t max)
	{
		return val < min ? min : ((val > max) ? max : val);
	}
}
