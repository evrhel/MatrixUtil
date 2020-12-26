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

#include <cmath>

#include "fvec_math.h"

namespace mutil
{
	/*!
	Returns a 4x4 matrix to look at a certain point.

	@param eye The eye to look from.
	@param at The point to look at.
	@param up The up vector of the eye.

	@return The look matrix.
	*/
	inline Matrix4 lookAt(const Vector3 &eye, const Vector3 &at, const Vector3 &up)
	{
		Vector3 const f = normalize(at - eye);
		Vector3 const r = normalize(cross(f, up));
		Vector3 const u = cross(r, f);

		return Matrix4(
			Vector4(r.x, u.x, -f.x, 0.0f),
			Vector4(r.y, u.y, -f.y, 0.0f),
			Vector4(r.z, u.z, -f.z, 0.0f),
			Vector4(-dot(r, eye), -dot(u, eye), dot(f, eye), 1.0f)
		);
	}

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
	inline Matrix4 ortho(float left, float right, float bottom, float top, float zNear, float zFar)
	{
		return Matrix4(
			Vector4(2.0f / (right - left), 0.0f, 0.0f, 0.0f),
			Vector4(0.0f, 2.0f / (top - bottom), 0.0f, 0.0f),
			Vector4(0.0f, 0.0f, -2.0f / (zFar - zNear), 0.0f),
			Vector4(-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(zFar + zNear) / (zFar - zNear), 1.0f)
		);
	}

	/*!
	Returns a 4x4 orthographic projection matrix.

	@param left The left bound.
	@param right The right bound.
	@param bottom The bottom bound.
	@param top The top bound.

	@return The orthographic projection matrix.
	*/
	inline Matrix4 ortho(float left, float right, float bottom, float top)
	{
		return Matrix4(
			Vector4(2.0f / (right - left), 0.0f, 0.0f, 0.0f),
			Vector4(0.0f, 2.0f / (top - bottom), 0.0f, 0.0f),
			Vector4(0.0f, 0.0f, 1.0f, 0.0f),
			Vector4(-(right + left) / (right - left), -(top + bottom) / (top - bottom), 0.0f, 1.0f)
		);
	}

	/*!
	Returns a 4x4 perspective projection matrix.

	@param fov The field-of-view of the projection.
	@param aspect The aspect ratio.
	@param zNear The near z clip plane.
	@param zFar The far z clip plane.

	@return The perspective projection matrix.
	*/
	inline Matrix4 perspective(const float fov, const float aspect, const float zNear, const float zFar)
	{
		float const tanHalfFOV = tanf(fov / 2.0f);
		Matrix4 result(0.0f);
		result.columns[0].x = 1.0f / (aspect * tanHalfFOV);
		result.columns[1].y = 1.0f / (tanHalfFOV);
		result.columns[2].z = -(zFar + zNear) / (zFar - zNear);
		result.columns[2].w = -1.0f;
		result.columns[3].z = -(2.0f * zFar * zNear) / (zFar - zNear);
		return result;
	}

	/*!
	Rotates a 4x4 matrix and returns the new matrix.

	@param mat4 The matrix to rotate.
	@param angle The angle to rotate by, in radians.
	@param axis The axes to rotate on.

	@return A rotated version of the input matrix.
	*/
	inline Matrix4 rotate(const Matrix4 &mat4, const float angle, const Vector3 &axis)
	{
		const float c = cosf(angle);
		const float s = sinf(angle);

		Vector3 a = normalize(axis);
		Vector3 t = (1 - c) * axis;

		Matrix4 rotation = Matrix4(
			Vector4(c + t.x * a.x, t.x * a.y + s * a.z, t.x * a.z - s * a.y, 0.0f),
			Vector4(t.y * a.x - s * a.z, c + t.y * a.y, t.x * a.z + s * a.x, 0.0f),
			Vector4(t.z * a.x + s * a.y, t.z * a.y - s * a.x, c + t.z * a.z, 0.0f),
			Vector4(0.0f, 0.0f, 0.0f, 1.0f)
		);

		Matrix4 result = Matrix4(
			mat4.columns[0] * rotation.columns[0].x + mat4.columns[1] * rotation.columns[0].y + mat4.columns[2] * rotation.columns[0].z,
			mat4.columns[0] * rotation.columns[1].x + mat4.columns[1] * rotation.columns[1].y + mat4.columns[2] * rotation.columns[1].z,
			mat4.columns[0] * rotation.columns[2].x + mat4.columns[1] * rotation.columns[2].y + mat4.columns[2] * rotation.columns[2].z,
			rotation.columns[3]
		);

		return result;
	}

	/*!
	Scales a 4x4 matrix and returns the new matrix.

	@param mat4 The matrix to scale.
	@param scale The magnitudes to scale each dimension by.

	@return A scaled version of the input matrix.
	*/
	inline Matrix4 scale(const Matrix4 &mat4, const Vector3 &scale)
	{
		Matrix4 result;
		result.columns[0] = mat4.columns[0] * scale.x;
		result.columns[1] = mat4.columns[1] * scale.y;
		result.columns[2] = mat4.columns[2] * scale.z;
		result.columns[3] = mat4.columns[3];
		return result;
	}

	/*!
	Translates a 4x4 matrix and returns the new matrix.

	@param mat4 The matrix to translate.
	@param translation The amount to translate each dimension by.

	@return A translated version of the input matrix.
	*/
	inline Matrix4 translate(Matrix4 const &mat4, Vector3 const &translation)
	{
		Matrix4 result(mat4);
		result.columns[3] = mat4.columns[0] * translation.x + mat4.columns[1] * translation.y + mat4.columns[2] * translation.z + mat4.columns[3];
		return result;
	}
}
#endif