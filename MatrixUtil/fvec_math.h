/*!
\file
Contains methods for performing operations on floating-point vectors.
*/

#pragma once

#ifndef FVEC_MATH_H
#define FVEC_MATH_H

#include "settings.h"
#include "vec_types.h"

namespace mutil
{
	// Vector2 operations
	
	/*!
	Returns the dot product of two Vector2's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	float MUTIL_EXPORT		dot(Vector2 const &first, Vector2 const &second);

	/*!
	Returns the cross product of two Vector2's.  This treats each Vector2 as if
	their z component is 0.  Since the cross product returns an orthogonal vector
	to the two inputs and the input vectors are only 2D, the z component is the
	only non-zero component.  Due to this, the z magnitude of the cross product
	is returned.

	@param first The first vector.
	@param second The second vector.

	@return The magnitude of the z component of the result of the cross product.
	*/
	float MUTIL_EXPORT		cross(Vector2 const &first, Vector2 const &second);

	/*!
	Returns the length of a Vector2.

	@param vec The vector to get the length of.

	@return The length.
	*/
	float MUTIL_EXPORT		length(Vector2 const &vec);

	/*!
	Finds the distance between two Vector2's.

	@param first The first vector.
	@param second The second vector.

	@return The distance between the two vectors.
	*/
	float MUTIL_EXPORT		distance(Vector2 const &first, Vector2 const &second);

	/*!
	Normalizes a Vector2, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	Vector2 MUTIL_EXPORT	normalize(Vector2 const &vec);

	/*!
	Reflects a Vector2 over a normal, returning the reflected vector.

	@param vec The vector to reflect.
	@param normal The normal vector to reflect over.

	@return The reflected vector.
	*/
	Vector2 MUTIL_EXPORT	reflect(Vector2 const &vec, Vector2 const &normal);

	/*!
	Converts a Vector2 containing angles in degrees to radians.

	@param A Vector2 containing angles in degrees.

	@return The same vector in radians.
	*/
	Vector2 MUTIL_EXPORT	radians(Vector2 const &vec);

	/*!
	Converts a Vector2 containing angles in radians to degrees.

	@param A Vector2 containing angles in radians.

	@return The same vector in degrees.
	*/
	Vector2 MUTIL_EXPORT	degrees(Vector2 const &vec);

	/*!
	Returns a Vector2 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	Vector2 MUTIL_EXPORT	abs(Vector2 const &vec);

	// Vector3 operations

	/*!
	Returns the dot product of two Vector3's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	float MUTIL_EXPORT		dot(Vector3 const &first, Vector3 const &second);

	/*!
	Returns the cross product of two Vector3's.

	@param The first vector.
	@param The second vector.

	@return The result of the cross product.
	*/
	Vector3 MUTIL_EXPORT	cross(Vector3 const &first, Vector3 const &second);

	/*!
	Returns the length of a Vector3.

	@param vec The vector to get the length of.

	@return The length.
	*/
	float MUTIL_EXPORT		length(Vector3 const &vec);

	/*!
	Finds the distance between two Vector3's.

	@param first The first vector.
	@param second The second vector.

	@return The distance between the two vectors.
	*/
	float MUTIL_EXPORT		distance(Vector3 const &first, Vector3 const &second);

	/*!
	Normalizes a Vector3, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	Vector3 MUTIL_EXPORT	normalize(Vector3 const &vec);

	/*!
	Reflects a Vector3 over a normal, returning the reflected vector.

	@param vec The vector to reflect.
	@param normal The normal vector to reflect over.

	@return The reflected vector.
	*/
	Vector3 MUTIL_EXPORT	reflect(Vector3 const &vec, Vector3 const &normal);

	/*!
	Refracts a Vector3 and returns the resultant vector.

	@param vec The vector to refract.
	@param normal The normal of the refracting surface.
	@param index The ratio between two indicies of refraction.
	*/
	Vector3 MUTIL_EXPORT	refract(Vector3 const &vec, Vector3 const &normal, float ratio);

	/*!
	Converts a Vector3 containing angles in degrees to radians.

	@param A Vector3 containing angles in degrees.

	@return The same vector in radians.
	*/
	Vector3 MUTIL_EXPORT	radians(Vector3 const &vec);

	/*!
	Converts a Vector3 containing angles in radians to degrees.

	@param A Vector3 containing angles in radians.

	@return The same vector in degrees.
	*/
	Vector3 MUTIL_EXPORT	degrees(Vector3 const &vec);

	/*!
	Returns a Vector3 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	Vector3 MUTIL_EXPORT	abs(Vector3 const &vec);

	// Vector4 operations

	/*!
	Returns the dot product of two Vector4's.

	@param first The first vector.
	@param second The second vector.

	@return The dot product.
	*/
	float MUTIL_EXPORT		dot(Vector4 const &first, Vector4 const &second);

	/*!
	Returns the length of a Vector4.

	@param vec The vector to get the length of.

	@return The length.
	*/
	float MUTIL_EXPORT		length(Vector4 const &vec);

	/*!
	Finds the distance between two Vector4's.

	@param first The first vector.
	@param second The second vector.

	@return The distance between the two vectors.
	*/
	float MUTIL_EXPORT		distance(Vector4 const &first, Vector4 const &second);

	/*!
	Normalizes a Vector4, making its length 1.

	@param vec The vector to normalize.

	@return The normalized vector.
	*/
	Vector4 MUTIL_EXPORT	normalize(Vector4 const &vec);

	/*!
	Reflects a Vector4 over a normal, returning the reflected vector.

	@param vec The vector to reflect.
	@param normal The normal vector to reflect over.

	@return The reflected vector.
	*/
	Vector4 MUTIL_EXPORT	reflect(Vector4 const &vec, Vector4 const &normal);

	/*!
	Converts a Vector4 containing angles in degrees to radians.

	@param A Vector4 containing angles in degrees.

	@return The same vector in radians.
	*/
	Vector4 MUTIL_EXPORT	radians(Vector4 const &vec);

	/*!
	Converts a Vector3 containing angles in radians to degrees.

	@param A Vector3 containing angles in radians.

	@return The same vector in degrees.
	*/
	Vector4 MUTIL_EXPORT	degrees(Vector4 const &vec);

	/*!
	Returns a Vector4 with each component being the absolute value of
	the input vector.

	@param The vector to take the absolute value of.

	@return The absolute value.
	*/
	Vector4 MUTIL_EXPORT	abs(Vector4 const &vec);
}

#endif