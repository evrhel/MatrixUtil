/*!
\file
Contains methods for performing floating-point math operations.
*/

#pragma once

#ifndef F_MATH_H
#define F_MATH_H

#include "settings.h"

#define _USE_MATH_DEFINES
#include <math.h>

namespace mutil
{
	/*!
	Converts an angle in degrees into radians.

	@param An angle in degrees.

	@return The same angle in radians.
	*/
	inline float radians(float degrees)
	{
		return degrees / 180 * M_PI;
	}

	/*!
	Converts an angle in radians into degrees.

	@param An angle in radians.

	@return The same angle in degrees.
	*/
	inline float degrees(float radians)
	{
		return radians / M_PI * 180;
	}
}

#endif