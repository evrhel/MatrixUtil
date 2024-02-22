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
			Vector4 v4;
			float q[4];
		};

		constexpr Quaternion() : w(1.0f), x(0.0f), y(0.0f), z(0.0f) {}
		constexpr Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}
		constexpr Quaternion(float real, const Vector3 &imag) : real(real), imag(imag) {}

		constexpr Quaternion &operator+=(const Quaternion &a)
		{
			w += a.w;
			x += a.x;
			y += a.y;
			z += a.z;
			return *this;
		}

		constexpr Quaternion &operator-=(const Quaternion &a)
		{
			w -= a.w;
			x -= a.x;
			y -= a.y;
			z -= a.z;
			return *this;
		}

		constexpr Quaternion &operator*=(float a)
		{
			w *= a;
			x *= a;
			y *= a;
			z *= a;
			return *this;
		}

		constexpr Quaternion &operator/=(float a)
		{
			w /= a;
			x /= a;
			y /= a;
			z /= a;
			return *this;
		}

		constexpr Quaternion &operator*=(const Quaternion &a)
		{
			w = w * a.w - x * a.x - y * a.y - z * a.z;
			x = w * a.x + x * a.w + y * a.z - z * a.y;
			y = w * a.y + y * a.w + z * a.x - x * a.z;
			z = w * a.z + z * a.w + x * a.y - y * a.x;
			return *this;
		}

		constexpr float &operator[](size_t idx) { return q[idx]; }
		constexpr const float &operator[](size_t idx) const { return q[idx]; }

		inline float length() const;
		inline float lengthSq() const;
		inline Quaternion normalized() const;
		constexpr Quaternion conjugate() const;
		constexpr Quaternion inverse() const;
		constexpr Matrix4 torotation() const;
		constexpr Matrix3 torotation3() const;
		inline Vector3 toeuler() const;
	};

	constexpr Quaternion operator+(const Quaternion &a, const Quaternion &b) { return Quaternion(a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z); }
	constexpr Quaternion operator-(const Quaternion &a, const Quaternion &b) { return Quaternion(a.w - b.w, a.x - b.x, a.y - b.y, a.z - b.z); }
	constexpr Quaternion operator*(const Quaternion &a, float s) { return Quaternion(a.w * s, a.x * s, a.y * s, a.z * s); }
	constexpr Quaternion operator*(float s, const Quaternion &a) { return a * s; }
	constexpr Quaternion operator/(const Quaternion &a, float s) { return Quaternion(a.w / s, a.x / s, a.y / s, a.z / s); }

	constexpr Quaternion operator-(const Quaternion &a) { return Quaternion(-a.w, -a.x, -a.y, -a.z); }

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
		return length(q.v4);
	}

	inline float lengthSq(const Quaternion &q)
	{
		return lengthSq(q.v4);
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
	constexpr Matrix3 torotation3(const Quaternion &q)
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

	/*!
	Converts a quaternion to euler angles.

	@param q A unit quaternion to convert.

	@return The converted angles, with each element being the rotation
	around the respective axis.
	*/
	inline Vector3 toeuler(const Quaternion &q)
	{
		Vector3 euler;
		float a, b;

		a = 2.0f * (q.w * q.x + q.y * q.z);
		b = 1.0f - 2.0f * (q.x * q.x + q.y * q.y);
		euler.x = atan2f(a, b);

		float sinp = 2.0f * (q.w * q.y - q.z * q.x);
		if (fabsf(sinp) >= 1.0f)
			euler.y = sinp > 0 ? MUTIL_PI2 : -MUTIL_PI2;
		else
			euler.y = asinf(sinp);

		a = 2.0f * (q.w * q.z + q.z * q.y);
		b = 1.0f - 2.0f * (q.y * q.y + q.z * q.z);
		euler.z = atan2f(b, a);

		return euler;
	}

	/*!
	Converts euler angles to a quaternion. Applies the rotations in the
	xyz order.

	@param x x-axis rotation
	@param y y-axis rotation
	@param z z-axis rotation

	@return The converted quaternion.
	*/
	inline Quaternion fromeuler(float x, float y, float z)
	{
		Quaternion qx = rotateaxis(Vector3(1.0f, 0.0f, 0.0f), x);
		Quaternion qy = rotateaxis(Vector3(0.0f, 1.0f, 0.0f), y);
		Quaternion qz = rotateaxis(Vector3(0.0f, 0.0f, 1.0f), z);

		return qx * qy * qz;
	}

	/*!
	Converts euler angles to a quaternion. Applies the rotations in the
	xyz order.

	@param x x-axis rotation
	@param y y-axis rotation
	@param z z-axis rotation

	@return The converted quaternion.
	*/
	inline Quaternion fromeuler(const Vector3 &euler)
	{
		return fromeuler(euler.x, euler.y, euler.z);
	}

	inline float dot(const Quaternion &a, const Quaternion &b)
	{
		return dot(a.v4, b.v4);
	}

	constexpr Quaternion lerp(const Quaternion &a, const Quaternion &b, float t)
	{
		Vector4 l = lerp(a.v4, b.v4, t);
		return Quaternion(l.x, l.y, l.z, l.w);
	}

	/*!
	Spherical linear interpolation.

	@param a Quaternion to interpolate from.
	@param b Quaternion to interpolate to.
	@param t Number [0.0, 1.0] specifying the interpolation amount.
	*/
	inline Quaternion slerpNotShortest(const Quaternion &a, const Quaternion &b, float t)
	{
		const float theta = acosf(dot(a, b)) / 2; // half angle between a and b
		const float stheta = sinf(theta);
		const float l = sinf((1.0f - t) * theta);
		const float r = sinf(t * theta);

		return ((a * l) + (b * r)) / stheta;
	}

	/*!
	Spherical linear interpolation. Will always take the shortest path, to perform
	a normal interpolation, use slerpNotShortest.

	@param a Quaternion to interpolate from.
	@param b Quaternion to interpolate to.
	@param t Number [0.0, 1.0] specifying the interpolation amount.
	*/
	inline Quaternion slerp(const Quaternion &a, const Quaternion &b, float t)
	{
		return dot(a, b) > 0
				   ? slerpNotShortest(a, b, t)
				   : slerpNotShortest(a, -b, t);
	}

	/*!
	Normalized linear interpolation. Much faster than slerp and may give similar
	results when a and b are not far apart.

	@param a Quaternion to interpolate from.
	@param b Quaternion to interpolate to.
	@param t Number [0.0, 1.0] specifying the interpolation amount.
	*/
	inline Quaternion nlerp(const Quaternion &a, const Quaternion &b, float t)
	{
		return normalize(lerp(a, b, t));
	}

	inline Quaternion sqrt(const Quaternion &a)
	{
		const float mag = length(a);
		const float coeff1 = mutil::sqrt((mag + a.real) / 2.0f);
		const float coeff2 = mutil::sqrt((mag - a.real) / 2.0f);
		return Quaternion(coeff1, normalize(a.imag) * coeff2);
	}

	inline Quaternion exp(const Quaternion &a)
	{
		const float ea = expf(a.real);
		const float mag = length(a);

		const float cosmag = mutil::cos(mag);
		const float sinmag = mutil::sin(mag);

		return ea * Quaternion(cosmag, normalize(a.imag) * sinmag);
	}

	inline Quaternion log(const Quaternion &a)
	{
		const float mag = length(a);
		const float lnmag = logf(mag);
		return Quaternion(lnmag, normalize(a.imag) * acosf(a.real / lnmag));
	}

	/*!
	Geodesic distance.
	*/
	inline float geodistance(const Quaternion &a, const Quaternion &b)
	{
		const float d = dot(a, b);
		const float d2 = d * d;
		return acosf(2.0f * d2 - 1.0f);
	}

	inline float Quaternion::length() const
	{
		return mutil::length(*this);
	}

	inline float Quaternion::lengthSq() const
	{
		return mutil::lengthSq(*this);
	}

	inline Quaternion Quaternion::normalized() const
	{
		return mutil::normalize(*this);
	}

	constexpr Quaternion Quaternion::conjugate() const
	{
		return mutil::conjugate(*this);
	}

	constexpr Quaternion Quaternion::inverse() const
	{
		return mutil::inverse(*this);
	}

	constexpr Matrix4 Quaternion::torotation() const
	{
		return mutil::torotation(*this);
	}

	constexpr Matrix3 Quaternion::torotation3() const
	{
		return mutil::torotation3(*this);
	}

	inline Vector3 Quaternion::toeuler() const
	{
		return mutil::toeuler(*this);
	}
}