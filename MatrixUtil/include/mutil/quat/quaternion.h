#pragma once

#include "../vec/vec.h"
#include "../mat/mat.h"

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
			Vector4 v4;
			float q[4];
		};

		constexpr Quaternion() : w(1.0f), x(0.0f), y(0.0f), z(0.0f) {}
		constexpr Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}
		constexpr Quaternion(float real, const Vector3 &imag) : w(real), x(imag.x), y(imag.y), z(imag.z) {}

		constexpr Vector3 imag() const { return Vector3(x, y, z); }

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
			Quaternion tmp = *this;
			w = tmp.w * a.w - tmp.x * a.x - tmp.y * a.y - tmp.z * a.z;
			x = tmp.w * a.x + tmp.x * a.w + tmp.y * a.z - tmp.z * a.y;
			y = tmp.w * a.y + tmp.y * a.w + tmp.z * a.x - tmp.x * a.z;
			z = tmp.w * a.z + tmp.z * a.w + tmp.x * a.y - tmp.y * a.x;
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

	constexpr Quaternion operator+(const Quaternion &a, const Quaternion &b);
	constexpr Quaternion operator-(const Quaternion &a, const Quaternion &b);
	constexpr Quaternion operator*(const Quaternion &a, float s);
	constexpr Quaternion operator*(float s, const Quaternion &a);
	constexpr Quaternion operator/(const Quaternion &a, float s);

	constexpr Quaternion operator-(const Quaternion &a);

	constexpr Quaternion operator*(const Quaternion &a, const Quaternion &b);

	constexpr Vector3 imag(const Quaternion &q);

	inline float length(const Quaternion &q);
	inline float lengthSq(const Quaternion &q);
	inline Quaternion normalize(const Quaternion &q);

	constexpr Quaternion conjugate(const Quaternion &q);
	constexpr Quaternion inverse(const Quaternion &q);

	constexpr Matrix4 torotation(const Quaternion &q);
	constexpr Matrix3 torotation3(const Quaternion &q);

	inline Quaternion rotateaxis(const Vector3 &axis, float angle);
	inline Vector3 rotatevector(const Quaternion &q, const Vector3 &p);

	inline Vector3 toeuler(const Quaternion &q);
	inline Quaternion fromeuler(float x, float y, float z);
	inline Quaternion fromeuler(const Vector3 &euler);

	inline float dot(const Quaternion &a, const Quaternion &b);

	constexpr Quaternion lerp(const Quaternion &a, const Quaternion &b, float t);
	inline Quaternion slerpNotShortest(const Quaternion &a, const Quaternion &b, float t);
	inline Quaternion slerp(const Quaternion &a, const Quaternion &b, float t);
	inline Quaternion nlerp(const Quaternion &a, const Quaternion &b, float t);

	inline Quaternion sqrt(const Quaternion &a);
	inline Quaternion exp(const Quaternion &a);
	inline Quaternion log(const Quaternion &a);

	inline float geodistance(const Quaternion &a, const Quaternion &b);
}