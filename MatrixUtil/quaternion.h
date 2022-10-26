#pragma once

#include "vec_types.h"
#include "f_math.h"
#include "fvec_math.h"
#include "mat_types.h"

namespace mutil
{
	class Quaternion
	{
	public:
		union
		{
			struct
			{
				float w, x, y, z;
			};
			struct
			{
				float a, i, j, k;
			};
			struct
			{
				float real;
				Vector3 imag;
			};
			float q[4];
		};

		constexpr Quaternion() : w(1.0f), x(0.0f), y(0.0f), z(0.0f) {}
		constexpr Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}
		constexpr Quaternion(float real, const Vector3 &imag) : real(real), imag(imag) {}

		constexpr float &operator[](size_t idx) { return q[idx]; }
		constexpr const float &operator[](size_t idx) const { return q[idx]; }
	};

	constexpr Quaternion operator+(const Quaternion &a, const Quaternion &b) { return Quaternion(a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z); }
	constexpr Quaternion operator-(const Quaternion &a, const Quaternion &b) { return Quaternion(a.w - b.w, a.x - b.x, a.y - b.y, a.z - b.z); }
	constexpr Quaternion operator*(const Quaternion &a, float s) { return Quaternion(a.w * s, a.x * s, a.y * s, a.z * s); }
	constexpr Quaternion operator*(float s, const Quaternion &a) { return a * s; }
	constexpr Quaternion operator/(const Quaternion &a, float s) { return Quaternion(a.w / s, a.x / s, a.y / s, a.z / s); }

	constexpr Quaternion operator*(const Quaternion &a, const Quaternion &b)
	{
		return Quaternion(
			a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
			a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
			a.w * b.y + a.y * b.w + a.z * b.x - a.x * b.z,
			a.w * b.z + a.z * b.w + a.x * b.y - a.y * b.x);
	}

	/*!
	Returns the length of a quaternion.

	@param q The quaternion to get the length of.

	@return The length of q.
	*/
	inline float length(const Quaternion &q)
	{
		return sqrtf(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
	}

	/*!
	Normalize the quaternion such that length(q) is 1.

	@param q The quaternion to normalize.

	@return The normalized quaternion.
	*/
	inline Quaternion normalize(const Quaternion &q)
	{
		float invsqrt = fastInverseSqrt(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
		return q * invsqrt;
	}

	/*!
	Returns conjugate of a quaternion.

	@param q The quaternion to conjugate.

	@return The conjugated quaternion.
	*/
	constexpr Quaternion conjugate(const Quaternion &q)
	{
		return Quaternion(q.w, -q.x, -q.y, -q.z);
	}

	constexpr Quaternion inverse(const Quaternion &q)
	{
		float lensq = q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z;
		return conjugate(q) / lensq;
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
		const float xw = q.x * q.w;
		const float yz = q.y * q.z;
		const float yw = q.y * q.w;
		const float zw = q.z * q.w;

		return Matrix4(
			1 - 2 * y2 - 2 * z2, 2 * xy - 2 * zw, 2 * xz + 2 * yw, 0,
			2 * xy + 2 * zw, 1 - 2 * x2 - 2 * z2, 2 * yz - 2 * xw, 0,
			2 * xz - 2 * yw, 2 * yz + 2 * xw, 1 - 2 * x2 - 2 * y2, 0,
			0, 0, 0, 1);
	}

	/*!
	Converts a quaternion to a 3x3 rotation matrix.

	@param q The quaternion to convert.

	@return The resultant rotation matrix.
	*/
	inline Matrix3 torotation3(const Quaternion &q)
	{
		const float x2 = q.x * q.x;
		const float y2 = q.y * q.y;
		const float z2 = q.z * q.z;

		const float xy = q.x * q.y;
		const float xz = q.x * q.z;
		const float xw = q.x * q.w;
		const float yz = q.y * q.z;
		const float yw = q.y * q.w;
		const float zw = q.z * q.w;

		return Matrix3(
			1 - 2 * y2 - 2 * z2, 2 * xy - 2 * zw, 2 * xz + 2 * yw,
			2 * xy + 2 * zw, 1 - 2 * x2 - 2 * z2, 2 * yz - 2 * xw,
			2 * xz - 2 * yw, 2 * yz + 2 * xw, 1 - 2 * x2 - 2 * y2);
	}

	/*!
	Converts a quaternion to euler angles.

	@param q A unit quaternion to convert.

	@return The converted angles, in the form { roll, pitch, yaw }.
	*/
	inline Vector3 toeuler(const Quaternion &q)
	{
		Vector3 euler;

		// roll
		const float tanRoll = (2 * q[0] * q[1] + q[2] * q[3]) / (1 - 2 * (q[1] * q[1] + q[2] * q[2]));
		euler.x = atanf(tanRoll);

		// pitch
		float sinPitch = 2 * (q[0] * q[2] - q[3] * q[1]);
		// if (sinPitch < 1 || sinPitch > 1)
		//	sinPitch = 1.0f - fract(sinPitch);
		if (sinPitch > 1.0f || sinPitch < 1.0f)
			sinPitch = 1 - fract(sinPitch);
		// sinPitch = (fract(sinPitch * 0.5f + 0.5f) - 0.5f) * 2.0f;
		euler.y = asinf(sinPitch);

		// yaw
		const float tanYaw = (2 * q[0] * q[3] + q[1] * q[2]) / (1 - 2 * (q[2] * q[2] + q[3] * q[3]));
		euler.z = atanf(tanYaw);

		return euler;
	}

	/*!
	Converts euler angles to a quaternion.

	@param roll The roll.
	@param pitch The pitch.
	@param yaw The yaw.

	@return The converted quaternion.
	*/
	inline Quaternion fromeuler(float roll, float pitch, float yaw)
	{
		const float cr = cosf(roll / 2);
		const float sr = sinf(roll / 2);
		const float cp = cosf(pitch / 2);
		const float sp = sinf(pitch / 2);
		const float cy = cosf(yaw / 2);
		const float sy = sinf(yaw / 2);

		Quaternion q;
		q.w = cr * cp * cy + sr * sp * sy;
		q.x = sr * cp * cy - cr * sp * sy;
		q.y = cr * sp * cy + sr * cp * sy;
		q.z = cr * cp * sy - sr * sp * cy;

		return q;
	}

	/*!
	Converts euler angles to a quaternion.

	@param euler Euler angles in the form { roll, pitch, yaw }.

	@return The converted quaternion.
	*/
	inline Quaternion fromeuler(const Vector3 &euler) { return fromeuler(euler.x, euler.y, euler.z); }

	/*!
	Returns a quaternion that represents a rotation of some angle around
	an axis.

	@param axis The axis to rotate around. Must be length 1.
	@param angle The angle to rotate by.

	@return A unit quaternion representing the rotation.
	*/
	inline Quaternion rotateaxis(const Vector3 &axis, float angle)
	{
		return Quaternion(
			cosf(angle / 2),
			sinf(angle / 2) * axis);
	}

	/*!
	Rotates a point using a quaternion.

	@param q A unit quaternion representing the rotation.
	@param p The point to rotate.

	@return The rotated point.
	*/
	inline Vector3 rotatevector(const Quaternion &q, const Vector3 &p)
	{
		// q * p * q'
		Quaternion r = q * Quaternion(0.0f, p) * conjugate(q);
		return r.imag;
	}

	inline float dot(const Quaternion &a, const Quaternion &b)
	{
		return dot((const Vector4 &)a, (const Vector4 &)b);
	}

	constexpr Quaternion lerp(const Quaternion &a, const Quaternion &b, float t)
	{
		Vector4 l = lerp(*(Vector4 *)&a, *(Vector4 *)&b, t);
		return Quaternion(l.x, l.y, l.z, l.w);
	}

	/*!
	Spherical linear interpolation.

	@param a Quaternion to interpolate from.
	@param b Quaternion to interpolate to.
	@param t Number [0.0, 1.0] specifying the interpolation amount.
	*/
	inline Quaternion slerp(const Quaternion &a, const Quaternion &b, float t)
	{
		const float theta = acosf(dot(a, b)) / 2; // half angle between a and b
		const float stheta = sinf(theta);
		const float l = sinf((1.0f - t) * theta);
		const float r = sinf(t * theta);

		return ((a * l) + (b * r)) / stheta;
	}
}