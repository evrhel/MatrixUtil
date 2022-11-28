/*!
\file
Contains classes for handling different types of vectors.
*/

#pragma once

#ifndef FVEC_TYPES_H
#define FVEC_TYPES_H

#include <stdint.h>
#include <memory>

#include "settings.h"

namespace mutil
{
	class Vector2;
	class Vector3;
	class Vector4;

	class IntVector2;
	class IntVector3;
	class IntVector4;

	typedef Vector3 Vector;
	typedef IntVector3 IntVector;

	// Floating-point vectors

	/*!
	Class wrapping a two dimensional vector of floats.
	*/
	class Vector2
	{
	public:
		union
		{
			struct
			{
				float x, y;
			};
			struct
			{
				float r, g;
			};
			struct
			{
				float s, t;
			};
			float vec[2];
		};

		/*!
		Constructs a zeroed vector.
		*/
		constexpr Vector2() : x(0.0f), y(0.0f) {}

		/*!
		Constructs a vector filled with one value.

		@param scale The value to fill with.
		*/
		explicit constexpr Vector2(const float scalar) : x(scalar), y(scalar) {}

		/*!
		Constructs a vector with two explicit values.

		@param x The x value.
		@param y The y value.
		*/
		constexpr Vector2(const float x, const float y) : x(x), y(y) {}

		/*!
		Typecasts from an 32-bit integer vector.

		@param ivec2 The vector to cast from.
		*/
		explicit constexpr Vector2(const IntVector2 &ivec2);

		/*!
		Constructs a Vector2 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		explicit constexpr Vector2(const Vector3 &vec);

		/*!
		Constructs a Vector2 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		explicit constexpr Vector2(const Vector4 &vec);

		constexpr Vector2 &operator+=(const Vector2 &first);
		constexpr Vector2 &operator-=(const Vector2 &first);
		constexpr Vector2 &operator*=(const Vector2 &first);
		constexpr Vector2 &operator*=(float scalar);
		constexpr Vector2 &operator/=(const Vector2 &first);
		constexpr Vector2 &operator/=(float scalar);

		constexpr const float &operator[](size_t index) const
		{
			return vec[index];
		}

		constexpr float &operator[](size_t index)
		{
			return vec[index];
		}

		inline float length() const;
		inline float lengthSq() const;
		inline Vector2 normalized() const;
	};

	constexpr Vector2 operator+(const Vector2 &first, const Vector2 &second) { return Vector2(first.x + second.x, first.y + second.y); }
	constexpr Vector2 operator-(const Vector2 &first, const Vector2 &second) { return Vector2(first.x - second.x, first.y - second.y); }
	constexpr Vector2 operator*(const Vector2 &first, const Vector2 &second) { return Vector2(first.x * second.x, first.y * second.y); }
	constexpr Vector2 operator*(const Vector2 &first, float scalar) { return Vector2(first.x * scalar, first.y * scalar); }
	constexpr Vector2 operator*(float a, const Vector2 &b) { return b * a; }
	constexpr Vector2 operator/(const Vector2 &first, const Vector2 &second) { return Vector2(first.x / second.x, first.y / second.y); }
	constexpr Vector2 operator/(const Vector2 &first, float scalar) { return Vector2(first.x / scalar, first.y / scalar); }

	constexpr Vector2 operator-(Vector2 const &vec) { return Vector2(-vec.x, -vec.y); };

	constexpr bool operator==(const Vector2 &first, const Vector2 &second) { return first.x == second.x && first.y == second.y; }
	constexpr bool operator!=(const Vector2 &first, const Vector2 &second) { return !operator==(first, second); }

	class Vector3
	{
	public:
		union
		{
			struct
			{
				float x, y, z;
			};
			struct
			{
				float r, g, b;
			};
			struct
			{
				float s, t, p;
			};
			float vec[3];
		};

		constexpr Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
		explicit constexpr Vector3(const float &scalar) : x(scalar), y(scalar), z(scalar) {}
		constexpr Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) {}
		explicit constexpr Vector3(const IntVector3 &ivec3);

		constexpr Vector3(const Vector2 &xy, float z) : x(xy.x), y(xy.y), z(z) {}
		constexpr Vector3(float x, const Vector2 &yz) : x(x), y(yz.x), z(yz.y) {}

		/*!
		Constructs a Vector3 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit constexpr Vector3(const Vector2 &vec);

		/*!
		Constructs a Vector3 with only the x, y, and z components of
		the input vector.

		@param vec A vector.
		*/
		explicit constexpr Vector3(const Vector4 &vec);

		constexpr Vector3 &operator+=(const Vector3 &first);
		constexpr Vector3 &operator-=(const Vector3 &first);
		constexpr Vector3 &operator*=(const Vector3 &first);
		constexpr Vector3 &operator*=(float scalar);
		constexpr Vector3 &operator/=(const Vector3 &first);
		constexpr Vector3 &operator/=(float scalar);

		constexpr const float &operator[](size_t index) const
		{
			return vec[index];
		}

		constexpr float &operator[](size_t index)
		{
			return vec[index];
		}

		inline float length() const;
		inline float lengthSq() const;
		inline Vector3 normalized() const;
	};

	constexpr Vector3 operator+(const Vector3 &first, const Vector3 &second) { return Vector3(first.x + second.x, first.y + second.y, first.z + second.z); }
	constexpr Vector3 operator-(const Vector3 &first, const Vector3 &second) { return Vector3(first.x - second.x, first.y - second.y, first.z - second.z); }
	constexpr Vector3 operator*(const Vector3 &first, const Vector3 &second) { return Vector3(first.x * second.x, first.y * second.y, first.z * second.z); }
	constexpr Vector3 operator*(const Vector3 &first, float scalar) { return Vector3(first.x * scalar, first.y * scalar, first.z * scalar); }
	constexpr Vector3 operator*(float a, const Vector3 &b) { return b * a; }
	constexpr Vector3 operator/(const Vector3 &first, const Vector3 &second) { return Vector3(first.x / second.x, first.y / second.y, first.z / second.z); }
	constexpr Vector3 operator/(const Vector3 &first, float scalar) { return Vector3(first.x / scalar, first.y / scalar, first.z / scalar); }

	constexpr Vector3 operator-(const Vector3 &vec) { return Vector3(-vec.x, -vec.y, -vec.z); }

	constexpr bool operator==(const Vector3 &first, const Vector3 &second) { return first.x == second.x && first.y == second.y && first.z == second.z; }
	constexpr bool operator!=(const Vector3 &first, const Vector3 &second) { return !operator==(first, second); }

	class Vector4
	{
	public:
		union
		{
			struct
			{
				float x, y, z, w;
			};
			struct
			{
				float r, g, b, a;
			};
			struct
			{
				float s, t, p, q;
			};
			float vec[4];
		};

		constexpr Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
		explicit constexpr Vector4(const float scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}
		constexpr Vector4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) {}
		explicit constexpr Vector4(const IntVector4 &vec);

		constexpr Vector4(const Vector2 &xy, float z, float w) : x(xy.x), y(xy.y), z(z), w(w) {}
		constexpr Vector4(const Vector3 &xyz, float w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}
		constexpr Vector4(const Vector2 &xy, const Vector2 &zw) : x(xy.x), y(xy.y), z(zw.x), w(zw.y) {}
		constexpr Vector4(float x, const Vector3 &yzw) : x(x), y(yzw.x), z(yzw.y), w(yzw.z) {}
		constexpr Vector4(float x, float y, const Vector2 &zw) : x(x), y(y), z(zw.x), w(zw.y) {}
		constexpr Vector4(float x, const Vector2 &yz, float w) : x(x), y(yz.x), z(yz.y), w(w) {}

		/*!
		Constructs a Vector4 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit constexpr Vector4(const Vector2 &vec);

		/*!
		Constructs a Vector4 with the x, y, and z components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit constexpr Vector4(const Vector3 &vec);

		constexpr Vector4 &operator+=(const Vector4 &first);
		constexpr Vector4 &operator-=(const Vector4 &first);
		constexpr Vector4 &operator*=(const Vector4 &first);
		constexpr Vector4 &operator*=(float scalar);
		constexpr Vector4 &operator/=(const Vector4 &first);
		constexpr Vector4 &operator/=(float scalar);

		constexpr const float &operator[](size_t index) const
		{
			return vec[index];
		}

		constexpr float &operator[](size_t index)
		{
			return vec[index];
		}

		inline float length() const;
		inline float lengthSq() const;
		inline Vector4 normalized() const;
	};

	constexpr Vector4 operator+(const Vector4 &first, const Vector4 &second) { return Vector4(first.x + second.x, first.y + second.y, first.z + second.z, first.w + second.w); }
	constexpr Vector4 operator-(const Vector4 &first, const Vector4 &second) { return Vector4(first.x - second.x, first.y - second.y, first.z - second.z, first.w - second.w); }
	constexpr Vector4 operator*(const Vector4 &first, const Vector4 &second) { return Vector4(first.x * second.x, first.y * second.y, first.z * second.z, first.w * second.w); }
	constexpr Vector4 operator*(const Vector4 &first, float scalar) { return Vector4(first.x * scalar, first.y * scalar, first.z * scalar, first.w * scalar); }
	constexpr Vector4 operator*(float a, const Vector4 &b) { return b * a; }
	constexpr Vector4 operator/(const Vector4 &first, const Vector4 &second) { return Vector4(first.x / second.x, first.y / second.y, first.z / second.z, first.w / second.w); }
	constexpr Vector4 operator/(const Vector4 &first, float scalar) { return Vector4(first.x / scalar, first.y / scalar, first.z / scalar, first.w / scalar); }

	constexpr Vector4 operator-(const Vector4 &vec) { return Vector4(-vec.x, -vec.y, -vec.z, -vec.w); };
	constexpr bool operator==(const Vector4 &first, const Vector4 &second) { return first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w; }
	constexpr bool operator!=(const Vector4 &first, const Vector4 &second) { return !operator==(first, second); }

	// 32-bit Integer Vectors

	class IntVector2
	{
	public:
		union
		{
			struct
			{
				int32_t x, y;
			};
			struct
			{
				int32_t r, g;
			};
			struct
			{
				int32_t s, t;
			};
			int32_t vec[2];
		};

		constexpr IntVector2() : x(0), y(0) {}
		explicit constexpr IntVector2(const int32_t scalar) : x(scalar), y(scalar) {}
		constexpr IntVector2(const int32_t x, const int32_t y) : x(x), y(y) {}
		explicit constexpr IntVector2(const Vector2 &vec);

		/*!
		Constructs an IntVector2 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		explicit constexpr IntVector2(const IntVector3 &vec);

		/*!
		Constructs an IntVector2 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		explicit constexpr IntVector2(const IntVector4 &vec);

		constexpr IntVector2 &operator+=(const IntVector2 &first);
		constexpr IntVector2 &operator-=(const IntVector2 &first);
		constexpr IntVector2 &operator*=(const IntVector2 &first);
		constexpr IntVector2 &operator*=(int32_t first);
		constexpr IntVector2 &operator/=(const IntVector2 &first);
		constexpr IntVector2 &operator/=(int32_t first);

		constexpr const int32_t &operator[](size_t index) const
		{
			return vec[index];
		}

		constexpr int32_t &operator[](size_t index)
		{
			return vec[index];
		}
	};

	constexpr IntVector2 operator+(const IntVector2 &first, const IntVector2 &second) { return IntVector2(first.x + second.x, first.y + second.y); }
	constexpr IntVector2 operator-(const IntVector2 &first, const IntVector2 &second) { return IntVector2(first.x - second.x, first.y - second.y); }
	constexpr IntVector2 operator*(const IntVector2 &first, const IntVector2 &second) { return IntVector2(first.x * second.x, first.y * second.y); }
	constexpr IntVector2 operator*(const IntVector2 &first, const int32_t &scalar) { return IntVector2(first.x * scalar, first.y * scalar); }
	constexpr IntVector2 operator*(int32_t a, const IntVector2 &b) { return b * a; }
	constexpr IntVector2 operator/(const IntVector2 &first, const IntVector2 &second) { return IntVector2(first.x / second.x, first.y / second.y); }
	constexpr IntVector2 operator/(const IntVector2 &first, const int32_t &scalar) { return IntVector2(first.x / scalar, first.y / scalar); }

	constexpr IntVector2 operator-(const IntVector2 &vec) { return IntVector2(-vec.x, -vec.y); };

	constexpr bool operator==(const IntVector2 &first, const IntVector2 &second) { return first.x == second.x && first.y == second.y; }
	constexpr bool operator!=(const IntVector2 &first, const IntVector2 &second) { return !operator==(first, second); }

	class IntVector3
	{
	public:
		union
		{
			struct
			{
				int32_t x, y, z;
			};
			struct
			{
				int32_t r, g, b;
			};
			struct
			{
				int32_t s, t, p;
			};
			int32_t vec[3];
		};

		constexpr IntVector3() : x(0), y(0), z(0) {}
		explicit constexpr IntVector3(const int32_t scalar) : x(scalar), y(scalar), z(scalar) {}
		constexpr IntVector3(const int32_t x, const int32_t y, const int32_t z) : x(x), y(y), z(z) {}
		explicit constexpr IntVector3(const Vector3 &vec);

		constexpr IntVector3(const IntVector3 &xy, int32_t z) : x(xy.x), y(xy.y), z(z) {}
		constexpr IntVector3(int32_t x, const IntVector3 &yz) : x(x), y(yz.x), z(yz.y) {}

		/*!
		Constructs an IntVector3 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit constexpr IntVector3(const IntVector2 &vec);

		/*!
		Constructs an IntVector3 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		explicit constexpr IntVector3(const IntVector4 &vec);

		constexpr IntVector3 &operator+=(const IntVector3 &first);
		constexpr IntVector3 &operator-=(const IntVector3 &first);
		constexpr IntVector3 &operator*=(const IntVector3 &first);
		constexpr IntVector3 &operator*=(int32_t scalar);
		constexpr IntVector3 &operator/=(const IntVector3 &first);
		constexpr IntVector3 &operator/=(int32_t scalar);

		constexpr const int32_t &operator[](size_t index) const
		{
			return vec[index];
		}

		constexpr int32_t &operator[](size_t index)
		{
			return vec[index];
		}
	};

	constexpr IntVector3 operator+(const IntVector3 &first, const IntVector3 &second) { return IntVector3(first.x + second.x, first.y + second.y, first.z + second.z); }
	constexpr IntVector3 operator-(const IntVector3 &first, const IntVector3 &second) { return IntVector3(first.x - second.x, first.y - second.y, first.z - second.z); }
	constexpr IntVector3 operator*(const IntVector3 &first, const IntVector3 &second) { return IntVector3(first.x * second.x, first.y * second.y, first.z * second.z); }
	constexpr IntVector3 operator*(const IntVector3 &first, int32_t scalar) { return IntVector3(first.x * scalar, first.y * scalar, first.z * scalar); }
	constexpr IntVector3 operator*(int32_t a, const IntVector3 &b) { return b * a; }
	constexpr IntVector3 operator/(const IntVector3 &first, const IntVector3 &second) { return IntVector3(first.x / second.x, first.y / second.y, first.z / second.z); }
	constexpr IntVector3 operator/(const IntVector3 &first, int32_t scalar) { return IntVector3(first.x / scalar, first.y / scalar, first.z / scalar); }

	constexpr IntVector3 operator-(const IntVector3 &vec) { return IntVector3(-vec.x, -vec.y, -vec.z); };

	constexpr bool operator==(const IntVector3 &first, const IntVector3 &second) { return first.x == second.x && first.y == second.y && first.z == second.z; }
	constexpr bool operator!=(const IntVector3 &first, const IntVector3 &second) { return !operator==(first, second); }

	class IntVector4
	{
	public:
		union
		{
			struct
			{
				int32_t x, y, z, w;
			};
			struct
			{
				int32_t r, g, b, a;
			};
			struct
			{
				int32_t s, t, p, q;
			};
			int32_t vec[4];
		};

		constexpr IntVector4() : x(0), y(0), z(0), w(0) {}
		explicit constexpr IntVector4(const int32_t scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}
		constexpr IntVector4(const int32_t x, const int32_t y, const int32_t z, const int32_t w) : x(x), y(y), z(z), w(w) {}
		explicit constexpr IntVector4(const Vector4 &vec) : x((int32_t)vec.x), y((int32_t)vec.y), z((int32_t)vec.z), w((int32_t)vec.w) {}

		constexpr IntVector4(const IntVector2 &xy, int32_t z, int32_t w) : x(xy.x), y(xy.y), z(z), w(w) {}
		constexpr IntVector4(const IntVector3 &xyz, int32_t w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}
		constexpr IntVector4(const IntVector2 &xy, const IntVector2 &zw) : x(xy.x), y(xy.y), z(zw.x), w(zw.y) {}
		constexpr IntVector4(int32_t x, const IntVector3 &yzw) : x(x), y(yzw.x), z(yzw.y), w(yzw.z) {}
		constexpr IntVector4(int32_t x, int32_t y, const IntVector2 &zw) : x(x), y(y), z(zw.x), w(zw.y) {}
		constexpr IntVector4(int32_t x, const IntVector2 &yz, int32_t w) : x(x), y(yz.x), z(yz.y), w(w) {}

		/*!
		Constructs an IntVector4 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit constexpr IntVector4(const IntVector2 &vec);

		/*!
		Constructs an IntVector4 with the x, y, and z components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit constexpr IntVector4(const IntVector3 &vec);

		constexpr IntVector4 &operator+=(const IntVector4 &first);
		constexpr IntVector4 &operator-=(const IntVector4 &first);
		constexpr IntVector4 &operator*=(const IntVector4 &first);
		constexpr IntVector4 &operator*=(int32_t scalar);
		constexpr IntVector4 &operator/=(const IntVector4 &first);
		constexpr IntVector4 &operator/=(int32_t scalar);

		constexpr const int32_t &operator[](size_t index) const
		{
			return vec[index];
		}

		constexpr int32_t &operator[](size_t index)
		{
			return vec[index];
		}
	};

	constexpr IntVector4 operator+(const IntVector4 &first, const IntVector4 &second) { return IntVector4(first.x + second.x, first.y + second.y, first.z + second.z, first.w + second.w); }
	constexpr IntVector4 operator-(const IntVector4 &first, const IntVector4 &second) { return IntVector4(first.x - second.x, first.y - second.y, first.z - second.z, first.w - second.w); }
	constexpr IntVector4 operator*(const IntVector4 &first, const IntVector4 &second) { return IntVector4(first.x * second.x, first.y * second.y, first.z * second.z, first.w * second.w); }
	constexpr IntVector4 operator*(const IntVector4 &first, const int32_t &scalar) { return IntVector4(first.x * scalar, first.y * scalar, first.z * scalar, first.w * scalar); }
	constexpr IntVector4 operator*(int32_t a, const IntVector4 &b) { return b * a; }
	constexpr IntVector4 operator/(const IntVector4 &first, const IntVector4 &second) { return IntVector4(first.x / second.x, first.y / second.y, first.z / second.z, first.w / second.w); }
	constexpr IntVector4 operator/(const IntVector4 &first, const int32_t &scalar) { return IntVector4(first.x / scalar, first.y / scalar, first.z / scalar, first.w / scalar); }

	constexpr IntVector4 operator-(IntVector4 const &vec) { return IntVector4(-vec.x, -vec.y, -vec.z, -vec.w); };

	constexpr bool operator==(IntVector4 const &first, IntVector4 const &second) { return first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w; }
	constexpr bool operator!=(IntVector4 const &first, IntVector4 const &second) { return !operator==(first, second); }

	constexpr Vector2::Vector2(const IntVector2 &ivec2) : x((float)ivec2.x), y((float)ivec2.y) {}
	constexpr Vector2::Vector2(const Vector3 &vec) : x(vec.x), y(vec.y) {}
	constexpr Vector2::Vector2(const Vector4 &vec) : x(vec.x), y(vec.y) {}

	constexpr Vector2 &Vector2::operator+=(const Vector2 &first)
	{
		x += first.x;
		y += first.y;
		return *this;
	}

	constexpr Vector2 &Vector2::operator-=(const Vector2 &first)
	{
		x -= first.x;
		y -= first.y;
		return *this;
	}

	constexpr Vector2 &Vector2::operator*=(const Vector2 &first)
	{
		x *= first.x;
		y *= first.y;
		return *this;
	}

	constexpr Vector2 &Vector2::operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	constexpr Vector2 &Vector2::operator/=(const Vector2 &first)
	{
		x /= first.x;
		y /= first.y;
		return *this;
	}

	constexpr Vector2 &Vector2::operator/=(float scalar)
	{
		x /= scalar;
		y /= scalar;
		return *this;
	}

	constexpr Vector3::Vector3(const IntVector3 &ivec3) : x((float)ivec3.x), y((float)ivec3.y), z((float)ivec3.z) {}

	constexpr Vector3 &Vector3::operator+=(const Vector3 &first)
	{
		x += first.x;
		y += first.y;
		z += first.z;
		return *this;
	}

	constexpr Vector3 &Vector3::operator-=(const Vector3 &first)
	{
		x -= first.x;
		y -= first.y;
		z -= first.z;
		return *this;
	}

	constexpr Vector3 &Vector3::operator*=(const Vector3 &first)
	{
		x *= first.x;
		y *= first.y;
		z *= first.z;
		return *this;
	}

	constexpr Vector3 &Vector3::operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	constexpr Vector3 &Vector3::operator/=(const Vector3 &first)
	{
		x /= first.x;
		y /= first.y;
		z /= first.z;
		return *this;
	}

	constexpr Vector3 &Vector3::operator/=(float scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}

	constexpr Vector4::Vector4(const IntVector4 &vec) : x((float)vec.x), y((float)vec.y), z((float)vec.z), w((float)vec.w) {}

	constexpr Vector4 &Vector4::operator+=(const Vector4 &first)
	{
		x += first.x;
		y += first.y;
		z += first.z;
		w += first.w;
		return *this;
	}

	constexpr Vector4 &Vector4::operator-=(const Vector4 &first)
	{
		x -= first.x;
		y -= first.y;
		z -= first.z;
		w -= first.w;
		return *this;
	}

	constexpr Vector4 &Vector4::operator*=(const Vector4 &first)
	{
		x *= first.x;
		y *= first.y;
		z *= first.z;
		w *= first.w;
		return *this;
	}

	constexpr Vector4 &Vector4::operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		w *= scalar;
		return *this;
	}

	constexpr Vector4 &Vector4::operator/=(const Vector4 &first)
	{
		x /= first.x;
		y /= first.y;
		z /= first.z;
		w /= first.w;
		return *this;
	}

	constexpr Vector4 &Vector4::operator/=(float scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
		w /= scalar;
		return *this;
	}

	constexpr IntVector2::IntVector2(const Vector2 &vec) : x((int32_t)vec.x), y((int32_t)vec.y) {}
	constexpr IntVector2::IntVector2(const IntVector3 &vec) : x(vec.x), y(vec.y) {}
	constexpr IntVector2::IntVector2(const IntVector4 &vec) : x(vec.x), y(vec.y) {}

	constexpr IntVector2 &IntVector2::operator+=(const IntVector2 &first)
	{
		x += first.x;
		y += first.y;
		return *this;
	}

	constexpr IntVector2 &IntVector2::operator-=(const IntVector2 &first)
	{
		x -= first.x;
		y -= first.y;
		return *this;
	}

	constexpr IntVector2 &IntVector2::operator*=(const IntVector2 &first)
	{
		x *= first.x;
		y *= first.y;
		return *this;
	}

	inline constexpr IntVector2 &IntVector2::operator*=(int32_t scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	constexpr IntVector2 &IntVector2::operator/=(const IntVector2 &first)
	{
		x /= first.x;
		y /= first.y;
		return *this;
	}

	inline constexpr IntVector2 &IntVector2::operator/=(int32_t scalar)
	{
		x /= scalar;
		y /= scalar;
		return *this;
	}

	constexpr IntVector3::IntVector3(const Vector3 &vec) : x((int32_t)vec.x), y((int32_t)vec.y), z((int32_t)vec.z) {}
	constexpr IntVector3::IntVector3(const IntVector2 &vec) : x(vec.x), y(vec.x), z(0) {}
	constexpr IntVector3::IntVector3(const IntVector4 &vec) : x(vec.x), y(vec.y), z(vec.z) {}

	constexpr IntVector3 &IntVector3::operator+=(const IntVector3 &first)
	{
		x += first.x;
		y += first.y;
		z += first.z;
		return *this;
	}

	constexpr IntVector3 &IntVector3::operator-=(const IntVector3 &first)
	{
		x -= first.x;
		y -= first.y;
		z -= first.z;
		return *this;
	}

	constexpr IntVector3 &IntVector3::operator*=(const IntVector3 &first)
	{
		x *= first.x;
		y *= first.y;
		z *= first.z;
		return *this;
	}

	constexpr IntVector3 &IntVector3::operator*=(int32_t scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	constexpr IntVector3 &IntVector3::operator/=(const IntVector3 &first)
	{
		x /= first.x;
		y /= first.y;
		z /= first.z;
		return *this;
	}

	constexpr IntVector3 &IntVector3::operator/=(int32_t scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}

	constexpr IntVector4 &IntVector4::operator+=(const IntVector4 &first)
	{
		x += first.x;
		y += first.y;
		z += first.z;
		w += first.w;
		return *this;
	}

	constexpr IntVector4 &IntVector4::operator-=(const IntVector4 &first)
	{
		x -= first.x;
		y -= first.y;
		z -= first.z;
		w -= first.w;
		return *this;
	}

	constexpr IntVector4 &IntVector4::operator*=(const IntVector4 &first)
	{
		x *= first.x;
		y *= first.y;
		z *= first.z;
		w *= first.w;
		return *this;
	}

	constexpr IntVector4 &IntVector4::operator*=(int32_t scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		w *= scalar;
		return *this;
	}

	constexpr IntVector4 &IntVector4::operator/=(const IntVector4 &first)
	{
		x /= first.x;
		y /= first.y;
		z /= first.z;
		w /= first.w;
		return *this;
	}

	constexpr IntVector4 &IntVector4::operator/=(int32_t scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
		w /= scalar;
		return *this;
	}
}

#endif