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
	typedef class Vector2 Vector2;
	typedef class Vector3 Vector3;
	typedef class Vector4 Vector4;

	typedef class IntVector2 IntVector2;
	typedef class IntVector3 IntVector3;
	typedef class IntVector4 IntVector4;

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
			struct { float x, y; };
			struct { float r, g; };
			struct { float s, t; };
			float vec[2];
		};

		/*!
		Constructs a zeroed vector.
		*/
		MUTIL_CONSTEXPR Vector2() : x(0.0f), y(0.0f) { }

		/*!
		Constructs a vector filled with one value.

		@param scale The value to fill with.
		*/
		explicit MUTIL_CONSTEXPR Vector2(const float scalar) : x(scalar), y(scalar) { }

		/*!
		Constructs a vector with two explicit values.

		@param x The x value.
		@param y The y value.
		*/
		MUTIL_CONSTEXPR Vector2(const float x, const float y) : x(x), y(y) { }

		/*!
		Typecasts from an 32-bit integer vector.

		@param ivec2 The vector to cast from.
		*/
		explicit MUTIL_CONSTEXPR Vector2(const IntVector2 &ivec2);

		/*!
		Constructs a Vector2 with only the x and y components of
		the input vector.
		
		@param vec A vector.
		*/
		explicit MUTIL_CONSTEXPR Vector2(const Vector3 &vec);

		/*!
		Constructs a Vector2 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		explicit MUTIL_CONSTEXPR Vector2(const Vector4 &vec);

		MUTIL_CONSTEXPR Vector2 &operator +=(const Vector2 &first);
		MUTIL_CONSTEXPR Vector2 &operator -=(const Vector2 &first);
		MUTIL_CONSTEXPR Vector2 &operator *=(const Vector2 &first);
		MUTIL_CONSTEXPR Vector2 &operator /=(const Vector2 &first);

		MUTIL_CONSTEXPR const float &operator[](size_t index) const
		{
			return vec[index];
		}

		MUTIL_CONSTEXPR float &operator[](size_t index)
		{
			return vec[index];
		}
	};

	MUTIL_CONSTEXPR Vector2 operator +(const Vector2 &first, const Vector2 &second) { return Vector2(first.x + second.x, first.y + second.y); }
	MUTIL_CONSTEXPR Vector2 operator -(const Vector2 &first, const Vector2 &second) { return Vector2(first.x - second.x, first.y - second.y); }
	MUTIL_CONSTEXPR Vector2 operator *(const Vector2 &first, const Vector2 &second) { return Vector2(first.x * second.x, first.y * second.y); }
	MUTIL_CONSTEXPR Vector2 operator *(const Vector2 &first, const float &scalar) { return Vector2(first.x * scalar, first.y * scalar); }
	MUTIL_CONSTEXPR Vector2 operator /(const Vector2 &first, const Vector2 &second) { return Vector2(first.x / second.x, first.y / second.y); }
	MUTIL_CONSTEXPR Vector2 operator /(const Vector2 &first, const float &scalar) { return Vector2(first.x / scalar, first.y / scalar); }

	MUTIL_CONSTEXPR Vector2 operator -(Vector2 const &vec) { return Vector2(-vec.x, -vec.y); };

	MUTIL_CONSTEXPR bool operator ==(Vector2 const &first, Vector2 const &second) { return first.x == second.x && first.y == second.y; }
	MUTIL_CONSTEXPR bool operator !=(Vector2 const &first, Vector2 const &second) { return !operator==(first, second); }

	class Vector3
	{
	public:
		union
		{
			struct { float x, y, z; };
			struct { float r, g, b; };
			struct { float s, t, b; };
			float vec[3];
		};

		MUTIL_CONSTEXPR Vector3() : x(0.0f), y(0.0f), z(0.0f) { }
		explicit MUTIL_CONSTEXPR Vector3(const float &scalar) : x(scalar), y(scalar), z(scalar) { }
		MUTIL_CONSTEXPR Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) { }
		explicit MUTIL_CONSTEXPR Vector3(const Vector2 &vec2, const float z);
		explicit MUTIL_CONSTEXPR Vector3(const IntVector3 &ivec3);

		/*!
		Constructs a Vector3 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit MUTIL_CONSTEXPR Vector3(const Vector2 &vec);

		/*!
		Constructs a Vector3 with only the x, y, and z components of
		the input vector.

		@param vec A vector.
		*/
		explicit MUTIL_CONSTEXPR Vector3(const Vector4 &vec);

		MUTIL_CONSTEXPR Vector3 &operator +=(const Vector3 &first);
		MUTIL_CONSTEXPR Vector3 &operator -=(const Vector3 &first);
		MUTIL_CONSTEXPR Vector3 &operator *=(const Vector3 &first);
		MUTIL_CONSTEXPR Vector3 &operator /=(const Vector3 &first);

		MUTIL_CONSTEXPR const float &operator[](size_t index) const
		{
			return vec[index];
		}

		MUTIL_CONSTEXPR float &operator[](size_t index)
		{
			return vec[index];
		}
	};

	MUTIL_CONSTEXPR Vector3 operator +(const Vector3 &first, const Vector3 &second) { return Vector3(first.x + second.x, first.y + second.y, first.z + second.z); }
	MUTIL_CONSTEXPR Vector3 operator -(const Vector3 &first, const Vector3 &second) { return Vector3(first.x - second.x, first.y - second.y, first.z - second.z); }
	MUTIL_CONSTEXPR Vector3 operator *(const Vector3 &first, const Vector3 &second) { return Vector3(first.x * second.x, first.y * second.y, first.z * second.z); }
	MUTIL_CONSTEXPR Vector3 operator *(const Vector3 &first, const float &scalar) { return Vector3(first.x * scalar, first.y * scalar, first.z * scalar); }
	MUTIL_CONSTEXPR Vector3 operator /(const Vector3 &first, const Vector3 &second) { return Vector3(first.x / second.x, first.y / second.y, first.z / second.z); }
	MUTIL_CONSTEXPR Vector3 operator /(const Vector3 &first, const float &scalar) { return Vector3(first.x / scalar, first.y / scalar, first.z / scalar); }

	MUTIL_CONSTEXPR Vector3 operator -(const Vector3 &vec) { return Vector3(-vec.x, -vec.y, -vec.z); }

	MUTIL_CONSTEXPR bool operator ==(const Vector3 &first, const Vector3 &second) { return first.x == second.x && first.y == second.y && first.z == second.z; }
	MUTIL_CONSTEXPR bool operator !=(const Vector3 &first, const Vector3 &second) { return !operator==(first, second); }

	class Vector4
	{
	public:
		union
		{
			struct { float x, y, z, w; };
			struct { float r, g, b, a; };
			struct { float s, t, p, q; };
			float vec[4];
		};

		MUTIL_CONSTEXPR Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }
		explicit MUTIL_CONSTEXPR Vector4(const float scalar) : x(scalar), y(scalar), z(scalar), w(scalar) { }
		MUTIL_CONSTEXPR Vector4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) { }
		explicit MUTIL_CONSTEXPR Vector4(const Vector2 &first, const Vector2 &second);
		explicit MUTIL_CONSTEXPR Vector4(const Vector3 &vec, const float w);
		explicit MUTIL_CONSTEXPR Vector4(const IntVector4 &vec);

		/*!
		Constructs a Vector4 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit MUTIL_CONSTEXPR Vector4(const Vector2 &vec);

		/*!
		Constructs a Vector4 with the x, y, and z components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit MUTIL_CONSTEXPR Vector4(const Vector3 &vec);

		MUTIL_CONSTEXPR Vector4 &operator +=(const Vector4 &first);
		MUTIL_CONSTEXPR Vector4 &operator -=(const Vector4 &first);
		MUTIL_CONSTEXPR Vector4 &operator *=(const Vector4 &first);
		MUTIL_CONSTEXPR Vector4 &operator /=(const Vector4 &first);

		MUTIL_CONSTEXPR const float &operator[](size_t index) const
		{
			return vec[index];
		}

		MUTIL_CONSTEXPR float &operator[](size_t index)
		{
			return vec[index];
		}
	};

	MUTIL_CONSTEXPR Vector4 operator +(const Vector4 &first, const Vector4 &second) { return Vector4(first.x + second.x, first.y + second.y, first.z + second.z, first.w + second.w); }
	MUTIL_CONSTEXPR Vector4 operator -(const Vector4 &first, const Vector4 &second) { return Vector4(first.x - second.x, first.y - second.y, first.z - second.z, first.w - second.w); }
	MUTIL_CONSTEXPR Vector4 operator *(const Vector4 &first, const Vector4 &second) { return Vector4(first.x * second.x, first.y * second.y, first.z * second.z, first.w * second.w); }
	MUTIL_CONSTEXPR Vector4 operator *(const Vector4 &first, const float &scalar) { return Vector4(first.x * scalar, first.y * scalar, first.z * scalar, first.w * scalar); }
	MUTIL_CONSTEXPR Vector4 operator /(const Vector4 &first, const Vector4 &second) { return Vector4(first.x / second.x, first.y / second.y, first.z / second.z, first.w / second.w); }
	MUTIL_CONSTEXPR Vector4 operator /(const Vector4 &first, const float &scalar) { return Vector4(first.x / scalar, first.y / scalar, first.z / scalar, first.w * scalar); }

	MUTIL_CONSTEXPR Vector4 operator -(const Vector4 &vec) { return Vector4(-vec.x, -vec.y, -vec.z, -vec.w); };
	MUTIL_CONSTEXPR bool operator ==(const Vector4 &first, const Vector4 &second) { return first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w; }
	MUTIL_CONSTEXPR bool operator !=(const Vector4 &first, const Vector4 &second) { return !operator==(first, second); }

	// 32-bit Integer Vectors

	class IntVector2
	{
	public:
		union
		{
			struct { int32_t x, y; };
			struct { int32_t r, g; };
			struct { int32_t s, t; };
			int32_t vec[2];
		};

		MUTIL_CONSTEXPR IntVector2() : x(0), y(0) { }
		explicit MUTIL_CONSTEXPR IntVector2(const int32_t scalar) : x(scalar), y(scalar) { }
		MUTIL_CONSTEXPR IntVector2(const int32_t x, const int32_t y) : x(x), y(y) { }
		explicit MUTIL_CONSTEXPR IntVector2(const Vector2 &vec);

		/*!
		Constructs an IntVector2 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		explicit MUTIL_CONSTEXPR IntVector2(const IntVector3 &vec);

		/*!
		Constructs an IntVector2 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		explicit MUTIL_CONSTEXPR IntVector2(const IntVector4 &vec);

		MUTIL_CONSTEXPR IntVector2 &operator +=(const IntVector2 &first);
		MUTIL_CONSTEXPR IntVector2 &operator -=(const IntVector2 &first);
		MUTIL_CONSTEXPR IntVector2 &operator *=(const IntVector2 &first);
		MUTIL_CONSTEXPR IntVector2 &operator /=(const IntVector2 &first);

		MUTIL_CONSTEXPR const int32_t &operator[](size_t index) const
		{
			return vec[index];
		}

		MUTIL_CONSTEXPR int32_t &operator[](size_t index)
		{
			return vec[index];
		}
	};

	MUTIL_INLINE IntVector2 operator +(const IntVector2 &first, const IntVector2 &second) { return IntVector2(first.x + second.x, first.y + second.y); }
	MUTIL_INLINE IntVector2 operator -(const IntVector2 &first, const IntVector2 &second) { return IntVector2(first.x - second.x, first.y - second.y); }
	MUTIL_INLINE IntVector2 operator *(const IntVector2 &first, const IntVector2 &second) { return IntVector2(first.x * second.x, first.y * second.y); }
	MUTIL_INLINE IntVector2 operator *(const IntVector2 &first, const int32_t &scalar) { return IntVector2(first.x * scalar, first.y * scalar); }
	MUTIL_INLINE IntVector2 operator /(const IntVector2 &first, const IntVector2 &second) { return IntVector2(first.x / second.x, first.y / second.y); }
	MUTIL_INLINE IntVector2 operator /(const IntVector2 &first, const int32_t &scalar) { return IntVector2(first.x / scalar, first.y / scalar); }

	MUTIL_INLINE IntVector2 operator -(const IntVector2 &vec) { return IntVector2(-vec.x, -vec.y); };

	MUTIL_INLINE bool operator ==(const IntVector2 &first, const IntVector2 &second) { return first.x == second.x && first.y == second.y; }
	MUTIL_INLINE bool operator !=(const IntVector2 &first, const IntVector2 &second) { return !operator==(first, second); }

	class IntVector3
	{
	public:
		union
		{
			struct { int32_t x, y, z; };
			struct { int32_t r, g, b; };
			struct { int32_t s, t, b; };
			int32_t vec[3];
		};

		MUTIL_INLINE IntVector3() : x(0), y(0), z(0) { }
		explicit MUTIL_INLINE IntVector3(const int32_t scalar) : x(scalar), y(scalar), z(scalar) { }
		MUTIL_INLINE IntVector3(const int32_t x, const int32_t y, const int32_t z) : x(x), y(y), z(z) { }
		explicit MUTIL_INLINE IntVector3(const IntVector2 &vec, const int32_t z);
		explicit MUTIL_INLINE IntVector3(const Vector3 &vec);

		/*!
		Constructs an IntVector3 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit MUTIL_INLINE IntVector3(const IntVector2 &vec);

		/*!
		Constructs an IntVector3 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		explicit MUTIL_INLINE IntVector3(const IntVector4 &vec);

		MUTIL_INLINE IntVector3 &operator +=(const IntVector3 &first);
		MUTIL_INLINE IntVector3 &operator -=(const IntVector3 &first);
		MUTIL_INLINE IntVector3 &operator *=(const IntVector3 &first);
		MUTIL_INLINE IntVector3 &operator /=(const IntVector3 &first);

		MUTIL_INLINE const int32_t &operator[](size_t index) const
		{
			return vec[index];
		}

		MUTIL_INLINE int32_t &operator[](size_t index)
		{
			return vec[index];
		}
	};

	MUTIL_INLINE IntVector3 operator +(const IntVector3 &first, const IntVector3 &second) { return IntVector3(first.x + second.x, first.y + second.y, first.z + second.z); }
	MUTIL_INLINE IntVector3 operator -(const IntVector3 &first, const IntVector3 &second) { return IntVector3(first.x - second.x, first.y - second.y, first.z - second.z); }
	MUTIL_INLINE IntVector3 operator *(const IntVector3 &first, const IntVector3 &second) { return IntVector3(first.x * second.x, first.y * second.y, first.z * second.z); }
	MUTIL_INLINE IntVector3 operator *(const IntVector3 &first, const int32_t &scalar) { return IntVector3(first.x * scalar, first.y * scalar, first.z * scalar); }
	MUTIL_INLINE IntVector3 operator /(const IntVector3 &first, const IntVector3 &second) { return IntVector3(first.x / second.x, first.y / second.y, first.z / second.z); }
	MUTIL_INLINE IntVector3 operator /(const IntVector3 &first, const int32_t &scalar) { return IntVector3(first.x / scalar, first.y / scalar, first.z * scalar); }

	MUTIL_INLINE IntVector3 operator -(const IntVector3 &vec) { return IntVector3(-vec.x, -vec.y, -vec.z); };

	MUTIL_INLINE bool operator ==(const IntVector3 &first, const IntVector3 &second) { return first.x == second.x && first.y == second.y && first.z == second.z; }
	MUTIL_INLINE bool operator !=(const IntVector3 &first, const IntVector3 &second) { return !operator==(first, second); }

	class IntVector4
	{
	public:
		union
		{
			struct { int32_t x, y, z, w; };
			struct { int32_t r, g, b, a; };
			struct { int32_t s, t, p, q; };
			int32_t vec[4];
		};

		MUTIL_INLINE IntVector4() : x(0), y(0), z(0), w(0) { }
		explicit MUTIL_INLINE IntVector4(const int32_t scalar) : x(scalar), y(scalar), z(scalar), w(scalar) { }
		MUTIL_INLINE IntVector4(const int32_t x, const int32_t y, const int32_t z, const int32_t w) : x(x), y(y), z(z), w(w) { }
		explicit MUTIL_INLINE IntVector4(const IntVector2 &first, const IntVector2 &second);
		explicit MUTIL_INLINE IntVector4(const IntVector3 &vec, const int32_t w);
		explicit MUTIL_INLINE IntVector4(const Vector4 &vec);

		/*!
		Constructs an IntVector4 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit MUTIL_INLINE IntVector4(const IntVector2 &vec);

		/*!
		Constructs an IntVector4 with the x, y, and z components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit MUTIL_INLINE IntVector4(const IntVector3 &vec);

		MUTIL_INLINE IntVector4 &operator +=(const IntVector4 &first);
		MUTIL_INLINE IntVector4 &operator -=(const IntVector4 &first);
		MUTIL_INLINE IntVector4 &operator *=(const IntVector4 &first);
		MUTIL_INLINE IntVector4 &operator /=(const IntVector4 &first);

		MUTIL_INLINE const int32_t &operator[](size_t index) const
		{
			return vec[index];
		}

		MUTIL_INLINE int32_t &operator[](size_t index)
		{
			return vec[index];
		}
	};

	MUTIL_INLINE IntVector4 operator +(const IntVector4 &first, const IntVector4 &second) { return IntVector4(first.x + second.x, first.y + second.y, first.z + second.z, first.w + second.w); }
	MUTIL_INLINE IntVector4 operator -(const IntVector4 &first, const IntVector4 &second) { return IntVector4(first.x - second.x, first.y - second.y, first.z - second.z, first.w - second.w); }
	MUTIL_INLINE IntVector4 operator *(const IntVector4 &first, const IntVector4 &second) { return IntVector4(first.x * second.x, first.y * second.y, first.z * second.z, first.w * second.w); }
	MUTIL_INLINE IntVector4 operator *(const IntVector4 &first, const int32_t &scalar) { return IntVector4(first.x * scalar, first.y * scalar, first.z * scalar, first.w * scalar); }
	MUTIL_INLINE IntVector4 operator /(const IntVector4 &first, const IntVector4 &second) { return IntVector4(first.x / second.x, first.y / second.y, first.z / second.z, first.w / second.w); }
	MUTIL_INLINE IntVector4 operator /(const IntVector4 &first, const int32_t &scalar) { return IntVector4(first.x / scalar, first.y / scalar, first.z * scalar, first.w / scalar); }

	MUTIL_INLINE IntVector4 operator -(IntVector4 const &vec) { return IntVector4(-vec.x, -vec.y, -vec.z, -vec.w); };

	MUTIL_INLINE bool operator ==(IntVector4 const &first, IntVector4 const &second) { return first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w; }
	MUTIL_INLINE bool operator !=(IntVector4 const &first, IntVector4 const &second) { return !operator==(first, second); }



	MUTIL_INLINE Vector2::Vector2(const IntVector2 &ivec2) : x((float)ivec2.x), y((float)ivec2.y) { }
	MUTIL_INLINE Vector2::Vector2(const Vector3 &vec) : x(vec.x), y(vec.y) { }
	MUTIL_INLINE Vector2::Vector2(const Vector4 &vec) : x(vec.x), y(vec.y) { }

	MUTIL_INLINE Vector2 &Vector2::operator +=(const Vector2 &first)
	{
		Vector2 result = operator+(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE Vector2 &Vector2::operator -=(const Vector2 &first)
	{
		Vector2 result = operator-(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE Vector2 &Vector2::operator *=(const Vector2 &first)
	{
		Vector2 result = operator*(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE Vector2 &Vector2::operator /=(const Vector2 &first)
	{
		Vector2 result = operator/(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE Vector3::Vector3(const Vector2 &vec2, const float z) : x(vec2.x), y(vec2.y), z(z) { }
	MUTIL_INLINE Vector3::Vector3(const IntVector3 &ivec3) : x((float)ivec3.x), y((float)ivec3.y), z((float)ivec3.z) { }
	MUTIL_INLINE Vector3::Vector3(const Vector2 &vec) : x(vec.x), y(vec.y), z(0.0f) { }
	MUTIL_INLINE Vector3::Vector3(const Vector4 &vec) : x(vec.x), y(vec.y), z(vec.z) { }

	MUTIL_INLINE Vector3 &Vector3::operator +=(const Vector3 &first)
	{
		Vector3 result = operator+(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE Vector3 &Vector3::operator -=(const Vector3 &first)
	{
		Vector3 result = operator-(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE Vector3 &Vector3::operator *=(const Vector3 &first)
	{
		Vector3 result = operator*(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE Vector3 &Vector3::operator /=(const Vector3 &first)
	{
		Vector3 result = operator/(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE Vector4::Vector4(const Vector2 &first, const Vector2 &second) : x(first.x), y(first.y), z(second.x), w(second.y) { }
	MUTIL_INLINE Vector4::Vector4(const Vector3 &vec, const float w) : x(vec.x), y(vec.y), z(vec.z), w(w) { }
	MUTIL_INLINE Vector4::Vector4(const IntVector4 &vec) : x((float)vec.x), y((float)vec.y), z((float)vec.z), w((float)vec.w) { }
	MUTIL_INLINE Vector4::Vector4(const Vector2 &vec) : x(vec.x), y(vec.y), z(0.0f), w(0.0f) { }
	MUTIL_INLINE Vector4::Vector4(const Vector3 &vec) : x(vec.x), y(vec.y), z(vec.z), w(0.0f) { }

	MUTIL_INLINE Vector4 &Vector4::operator +=(const Vector4 &first)
	{
		Vector4 result = operator+(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE Vector4 &Vector4::operator -=(const Vector4 &first)
	{
		Vector4 result = operator-(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE Vector4 &Vector4::operator *=(const Vector4 &first)
	{
		Vector4 result = operator*(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE Vector4 &Vector4::operator /=(const Vector4 &first)
	{
		Vector4 result = operator/(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}


	MUTIL_INLINE IntVector2::IntVector2(const Vector2 &vec) : x((int32_t)vec.x), y((int32_t)vec.y) { }
	MUTIL_INLINE IntVector2::IntVector2(const IntVector3 &vec) : x(vec.x), y(vec.y) { }
	MUTIL_INLINE IntVector2::IntVector2(const IntVector4 &vec) : x(vec.x), y(vec.y) { }

	MUTIL_INLINE IntVector2 &IntVector2::operator +=(const IntVector2 &first)
	{
		IntVector2 result = operator+(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE IntVector2 &IntVector2::operator -=(const IntVector2 &first)
	{
		IntVector2 result = operator-(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE IntVector2 &IntVector2::operator *=(const IntVector2 &first)
	{
		IntVector2 result = operator*(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE IntVector2 &IntVector2::operator /=(const IntVector2 &first)
	{
		IntVector2 result = operator/(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE IntVector3::IntVector3(const IntVector2 &vec, const int32_t z) : x(vec.x), y(vec.y), z(z) { }
	MUTIL_INLINE IntVector3::IntVector3(const Vector3 &vec) : x((int32_t)vec.x), y((int32_t)vec.y), z((int32_t)vec.z) { }
	MUTIL_INLINE IntVector3::IntVector3(const IntVector2 &vec) : x(vec.x), y(vec.x), z(0) { }
	MUTIL_INLINE IntVector3::IntVector3(const IntVector4 &vec) : x(vec.x), y(vec.y), z(vec.z) { }

	MUTIL_INLINE IntVector3 &IntVector3::operator +=(const IntVector3 &first)
	{
		IntVector3 result = operator+(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE IntVector3 &IntVector3::operator -=(const IntVector3 &first)
	{
		IntVector3 result = operator-(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE IntVector3 &IntVector3::operator *=(const IntVector3 &first)
	{
		IntVector3 result = operator*(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE IntVector3 &IntVector3::operator /=(const IntVector3 &first)
	{
		IntVector3 result = operator/(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE IntVector4::IntVector4(const IntVector2 &first, const IntVector2 &second) : x(first.x), y(first.y), z(second.x), w(second.y) { }
	MUTIL_INLINE IntVector4::IntVector4(const IntVector3 &vec, const int32_t w) : x(vec.x), y(vec.y), z(vec.z), w(w) { }
	MUTIL_INLINE IntVector4::IntVector4(const Vector4 &vec) : x((int32_t)vec.x), y((int32_t)vec.y), z((int32_t)vec.z), w((int32_t)vec.w) { }
	MUTIL_INLINE IntVector4::IntVector4(const IntVector2 &vec) : x(vec.x), y(vec.y), z(0), w(0) { }
	MUTIL_INLINE IntVector4::IntVector4(const IntVector3 &vec) : x(vec.x), y(vec.y), z(vec.z), w(0) { }

	MUTIL_INLINE IntVector4 &IntVector4::operator +=(const IntVector4 &first)
	{
		IntVector4 result = operator+(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE IntVector4 &IntVector4::operator -=(const IntVector4 &first)
	{
		IntVector4 result = operator-(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE IntVector4 &IntVector4::operator *=(const IntVector4 &first)
	{
		IntVector4 result = operator*(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}

	MUTIL_INLINE IntVector4 &IntVector4::operator /=(const IntVector4 &first)
	{
		IntVector4 result = operator/(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}
}

#endif