#include "f_math.h"

#define _USE_MATH_DEFINES
#include <cmath>

float MUTIL_EXPORT mutil::radians(float const &degrees)
{
	return degrees / 180 * M_PI;
}

float MUTIL_EXPORT mutil::degrees(float const &radians)
{
	return radians / M_PI * 180;
}
