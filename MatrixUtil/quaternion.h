#pragma once

#include "vec_types.h"
#include "f_math.h"
#include "mat_types.h"

namespace mutil
{
	class Quaternion
	{
	public:
		union
		{
			struct { float x, y, z, w; };
		};

		constexpr Quaternion() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) { }
		constexpr Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }
	};

	constexpr Quaternion operator+(const Quaternion &a, const Quaternion &b) { return Quaternion(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }
	constexpr Quaternion operator-(const Quaternion &a, const Quaternion &b) { return Quaternion(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }
	constexpr Quaternion operator*(const Quaternion &a, float s) { return Quaternion(a.x * s, a.y * s, a.z * s, a.w * s); }
	constexpr Quaternion operator*(float s, const Quaternion &a) { return a * s; }
	constexpr Quaternion operator/(const Quaternion &a, float s) { return Quaternion(a.x / s, a.y / s, a.z / s, a.w / s); }

	constexpr Quaternion operator*(const Quaternion &a, const Quaternion &b)
	{
		return Quaternion(
			a.w * b.x + a.x + b.w + a.y * b.z - a.z * b.y,
			a.w * b.y + a.y * b.w + a.z * b.x - a.x * b.z,
			a.w * b.z + a.z * b.w + a.x * b.y - a.y * b.x,
			a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z
		);
	}

	/*!
	Inverts a quaternion (aka its conjugate).

	@param q The quaternion to invert.

	@return The inverted quaternion.
	*/
	constexpr Quaternion inverse(const Quaternion &q)
	{
		return Quaternion(-q.x, -q.y, -q.z, q.w);
	}

	/*!
	Converts a quaternion to a 4x4 rotation matrix.

	@param q The quaternion to convert.

	@return The resultant rotation matrix.
	*/
	constexpr Matrix4 torotation(const Quaternion &q)
	{
		const float x2 = q.x * q.x;
		const float y2 = q.y * q.y;
		const float z2 = q.z * q.z;
		const float xy = q.x * q.y;
		const float xz = q.x * q.z;
		const float yz = q.y * q.z;
		const float wx = q.w * q.x;
		const float wy = q.w * q.y;
		const float wz = q.w * q.z;

		return Matrix4(
			1.0f - 2.0f * (y2 + z2), 2.0f * (xy - wz), 2.0f * (xz + wy), 0.0f,
			2.0f * (xy + wz), 1.0f - 2.0f * (x2 + z2), 2.0f * (yz - wx), 0.0f,
			2.0f * (xz - wy), 2.0f * (yz + wx), 1.0f - 2.0f * (x2 + y2), 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}

	/*!
	Converts a quaternion to euler angles.

	@param q The quaternion to convert.
	
	@return The converted angles, in the form { pitch, yaw, roll }.
	*/
	inline Vector3 toeuler(const Quaternion &q)
	{
		const float sqx = q.x * q.x;
		const float sqw = q.w * q.w;
		const float sqy = q.y * q.y;
		const float sqz = q.z * q.z;

		const float unit = sqx + sqy + sqz + sqw;
		const float test = q.x * q.y + q.z * q.w;

		if (test > 0.499f * unit)
			return Vector3(2.0f * atan2f(q.x, q.w), (float)M_PI / 2.0f, 0.0f);

		if (test < -0.499f * unit)
			return Vector3(-2.0f * atan2f(q.x, q.w), -(float)M_PI / 2.0f, 0.0f);

		return Vector3(
			atan2f(2.0f * q.y * q.w - 2.0f * q.x * q.z, sqx - sqy - sqz + sqw),
			asinf(2.0f * test / unit),
			atan2f(2.0f * q.x * q.w - 2.0f * q.y * q.z, -sqx + sqy - sqz + sqw)
		);
	}

	/*!
	Converts euler angles to a quaternion.

	@param pitch The pitch.
	@param yaw The yaw.
	@param roll The roll.

	@return The converted quaternion.
	*/
	inline Quaternion fromeuler(float pitch, float yaw, float roll)
	{
		const float cy = cosf(yaw / 2.0f);
		const float sy = sinf(yaw / 2.0f);
		const float cp = cosf(pitch / 2.0f);
		const float sp = sinf(pitch / 2.0f);
		const float cr = cosf(roll / 2.0f);
		const float sr = sinf(roll / 2.0f);

		return Quaternion(
			cy * cp * sr - sy * sp * cr,
			sy * cp * sr + cy * sp * cr,
			sy * cp * cr - cy * sp * sr,
			cy * cp * cr + sy * sp * sr
		);
	}

	/*!
	Converts euler angles to a quaternion.

	@param euler Euler angles in the form { pitch, yaw, roll }.

	@return The converted quaternion.
	*/
	inline Quaternion fromeuler(const Vector3 &euler) { return fromeuler(euler.x, euler.y, euler.z); }

}