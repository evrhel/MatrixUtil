/*
\file
Contains methods to create special matricies such as projection lookAt matricies, projection
matrices, and transformation matrices.
*/

#pragma once

#ifndef FMAT_TRANSFORM_H
#define FMAT_TRANSFORM_H

#include "settings.h"
#include "fmat_math.h"
#include "vec_types.h"

namespace mutil
{
	/*!
	Returns a 4x4 matrix to look at a certain point.

	@param eye The eye to look from.
	@param at The point to look at.
	@param up The up vector of the eye.

	@return The look matrix.
	*/
	Matrix4	MUTIL_EXPORT	lookAt(Vector3 const &eye, Vector3 const &at, Vector3 const &up);

	/*!
	Returns a 4x4 orthographic projection matrix.

	@param left The left bound.
	@param right The right bound.
	@param bottom The bottom bound.
	@param top The top bound.
	@param zNear The near z clip plane.
	@param zFar The far z clip plane.

	@return The orthographic projection matrix.
	*/
	Matrix4	MUTIL_EXPORT	ortho(float const &left, float const &right, float const &bottom, float const &top, float const &zNear, float const &zFar);

	/*!
	Returns a 4x4 orthographic projection matrix.

	@param left The left bound.
	@param right The right bound.
	@param bottom The bottom bound.
	@param top The top bound.

	@return The orthographic projection matrix.
	*/
	Matrix4 MUTIL_EXPORT	ortho(float const &left, float const &right, float const &bottom, float const &top);

	/*!
	Returns a 4x4 perspective projection matrix.

	@param fov The field-of-view of the projection.
	@param aspect The aspect ratio.
	@param zNear The near z clip plane.
	@param zFar The far z clip plane.

	@return The perspective projection matrix.
	*/
	Matrix4	MUTIL_EXPORT	perspective(float const &fov, float const &aspect, float const &zNear, float const &zFar);

	/*!
	Rotates a 4x4 matrix and returns the new matrix.

	@param mat4 The matrix to rotate.
	@param angle The angle to rotate by, in radians.
	@param axis The axes to rotate on.

	@return A rotated version of the input matrix.
	*/
	Matrix4	MUTIL_EXPORT	rotate(Matrix4 const &mat4, float const angle, Vector3 const &axis);

	/*!
	Scales a 4x4 matrix and returns the new matrix.

	@param mat4 The matrix to scale.
	@param scale The magnitudes to scale each dimension by.

	@return A scaled version of the input matrix.
	*/
	Matrix4 MUTIL_EXPORT	scale(Matrix4 const &mat4, Vector3 const &scale);

	/*!
	Translates a 4x4 matrix and returns the new matrix.

	@param mat4 The matrix to translate.
	@param translation The amount to translate each dimension by.

	@return A translated version of the input matrix.
	*/
	Matrix4	MUTIL_EXPORT	translate(Matrix4 const &mat4, Vector3 const &translation);
}
#endif