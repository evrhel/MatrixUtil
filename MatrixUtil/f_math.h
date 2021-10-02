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
	MUTIL_CONSTEXPR float radians(float degrees)
	{
		return degrees / 180 * (float)M_PI;
	}

	/*!
	Converts an angle in radians into degrees.

	@param An angle in radians.

	@return The same angle in degrees.
	*/
	MUTIL_CONSTEXPR float degrees(float radians)
	{
		return radians / (float)M_PI * 180;
	}

	/*
	Computes the absolute value of a floating-point value.

	@param value The value to calculate the absolute value of.

	@return The absolute value of value.
	*/
	MUTIL_CONSTEXPR float abs(float value)
	{
		return value < 0.0f ? -value : value;
	}
}

#endif