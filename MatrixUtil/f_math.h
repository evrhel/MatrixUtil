/*!
\file
Contains methods for performing floating-point math operations.
*/

#pragma once

#ifndef F_MATH_H
#define F_MATH_H

#include "settings.h"

namespace mutil
{
	/*!
	Converts an angle in degrees into radians.

	@param An angle in degrees.

	@return The same angle in radians.
	*/
	float MUTIL_EXPORT radians(float const &degrees);

	/*!
	Converts an angle in radians into degrees.

	@param An angle in radians.

	@return The same angle in degrees.
	*/
	float MUTIL_EXPORT degrees(float const &radians);
}

#endif