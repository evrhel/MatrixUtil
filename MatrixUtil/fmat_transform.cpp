#include "fmat_transform.h"

#include <cmath>

#include "fvec_math.h"

using namespace mutil;

static inline Matrix4 createRotationMatrix(Vector3 const &angles);
static inline Matrix4 createScalingMatrix(Vector3 const &scale);
static inline Matrix4 createTranslationMatrix(Vector3 const &translation);

Matrix4 mutil::lookAt(Vector3 const &eye, const Vector3 &at, const Vector3 &up)
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

Matrix4	mutil::ortho(float const &left, float const &right, float const &bottom, float const &top, float const &zNear, float const &zFar)
{
	return Matrix4(
		Vector4(2.0f / (right - left), 0.0f, 0.0f, 0.0f),
		Vector4(0.0f, 2.0f / (top - bottom), 0.0f, 0.0f),
		Vector4(0.0f, 0.0f, -2.0f / (zFar - zNear), 0.0f),
		Vector4(-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(zFar + zNear) / (zFar - zNear), 1.0f)
	);
}

Matrix4 mutil::ortho(float const &left, float const &right, float const &bottom, float const &top)
{
	return Matrix4(
		Vector4(2.0f / (right - left), 0.0f, 0.0f, 0.0f),
		Vector4(0.0f, 2.0f / (top - bottom), 0.0f, 0.0f),
		Vector4(0.0f, 0.0f, 1.0f, 0.0f),
		Vector4(-(right + left) / (right - left), -(top + bottom) / (top - bottom), 0.0f, 1.0f)
	);
}

Matrix4	mutil::perspective(float const &fov, float const &aspect, float const &zNear, float const &zFar)
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

Matrix4	mutil::rotate(Matrix4 const &mat4, float const angle, Vector3 const &axis)
{
	float const c = cosf(angle);
	float const s = sinf(angle);

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

Matrix4 mutil::scale(Matrix4 const &mat4, Vector3 const &scale)
{
	Matrix4 result;
	result.columns[0] = mat4.columns[0] * scale.x;
	result.columns[1] = mat4.columns[1] * scale.y;
	result.columns[2] = mat4.columns[2] * scale.z;
	result.columns[3] = mat4.columns[3];
	return result;
	//return mat4 * createScalingMatrix(scale);
}

Matrix4	mutil::translate(Matrix4 const &mat4, Vector3 const &translation)
{
	Matrix4 result(mat4);
	result.columns[3] = mat4.columns[0] * translation.x + mat4.columns[1] * translation.y + mat4.columns[2] * translation.z + mat4.columns[3];
	return result;
//	return mat4 * createTranslationMatrix(translation);
}

inline Matrix4 createRotationMatrix(Vector3 const &angles)
{
	return Matrix4(
		Vector4(
			(cosf(angles.x) * cosf(angles.y) * cosf(angles.z)) - (sinf(angles.x) - sinf(angles.z)),
			(sinf(angles.x) * cosf(angles.y) * cosf(angles.z)) + (cosf(angles.x) * sinf(angles.z)),
			-sinf(angles.y) * cosf(angles.z), 0.0f
		),
		Vector4(
			(-cosf(angles.x) * cosf(angles.y) * sinf(angles.z)) - (sinf(angles.x) - cosf(angles.z)),
			(-sinf(angles.x) * cosf(angles.y) * sin(angles.z)) + (cosf(angles.x) * cosf(angles.z)),
			sinf(angles.y) * sinf(angles.z), 0.0f
		),
		Vector4(
			cosf(angles.x) * sinf(angles.y),
			sinf(angles.x) * sinf(angles.y),
			cosf(angles.y), 0.0f
		),
		Vector4(
			0.0f,
			0.0f,
			0.0f,
			1.0f
		)
	);
}

inline Matrix4 createScalingMatrix(Vector3 const &scale)
{
	return Matrix4(
		Vector4(scale.x, 0.0f, 0.0f, 0.0f),
		Vector4(0.0f, scale.y, 0.0f, 0.0f),
		Vector4(0.0f, 0.0f, scale.y, 0.0f),
		Vector4(0.0f, 0.0f, 0.0f, 1.0f)
	);
}

inline Matrix4 createTranslationMatrix(Vector3 const &translation)
{
	return Matrix4(
		Vector4(1.0f, 0.0f, 0.0f, 0.0f),
		Vector4(0.0f, 1.0f, 0.0f, 0.0f),
		Vector4(0.0f, 0.0f, 1.0f, 0.0f),
		Vector4(translation.x, translation.y, translation.z, 1.0f)
	);
}