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
	class MUTIL_EXPORT Vector2
	{
	public:
		union
		{
			struct { float x, y; };
			struct { float r, g; };
			struct { float s, t; };
		};

		/*!
		Constructs a zeroed vector.
		*/
		inline Vector2() : x(0.0f), y(0.0f) { }

		/*!
		Constructs a vector filled with one value.

		@param scale The value to fill with.
		*/
		explicit inline Vector2(const float scalar) : x(scalar), y(scalar) { }

		/*!
		Constructs a vector with two explicit values.

		@param x The x value.
		@param y The y value.
		*/
		inline Vector2(const float x, const float y) : x(x), y(y) { }

		/*!
		Typecasts from an 32-bit integer vector.

		@param ivec2 The vector to cast from.
		*/
		explicit inline Vector2(const IntVector2 &ivec2) : x(ivec2.x), y(ivec2.y) { }

		/*!
		Constructs a Vector2 with only the x and y components of
		the input vector.
		
		@param vec A vector.
		*/
		explicit inline Vector2(const Vector3 &vec) : x(vec.x), y(vec.y) { }

		/*!
		Constructs a Vector2 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		explicit inline Vector2(const Vector4 &vec) : x(vec.x), y(vec.y) { }

		inline Vector2 &operator +=(const Vector2 &first)
		{
			Vector2 result = operator+(*this, first);
			memcpy(this, &result, 2 * sizeof(float));
			return *this;
		}

		inline Vector2 &operator -=(const Vector2 &first)
		{
			Vector2 result = operator-(*this, first);
			memcpy(this, &result, 2 * sizeof(float));
			return *this;
		}

		inline Vector2 &operator *=(const Vector2 &first)
		{
			Vector2 result = operator*(*this, first);
			memcpy(this, &result, 2 * sizeof(float));
			return *this;
		}

		inline Vector2 &operator /=(const Vector2 &first)
		{
			Vector2 result = operator/(*this, first);
			memcpy(this, &result, 2 * sizeof(float));
			return *this;
		}
	};

	inline Vector2 operator +(const Vector2 &first, const Vector2 &second) { return Vector2(first.x + second.x, first.y + second.y); }
	inline Vector2 operator -(const Vector2 &first, const Vector2 &second) { return Vector2(first.x - second.x, first.y - second.y); }
	inline Vector2 operator *(const Vector2 &first, const Vector2 &second) { return Vector2(first.x * second.x, first.y * second.y); }
	inline Vector2 operator *(const Vector2 &first, const float scalar) { return Vector2(first.x * scalar, first.y * scalar); }
	inline Vector2 operator *(const float scalar, const Vector2 &vec) { return Vector2(vec.x * scalar, vec.y * scalar); }
	inline Vector2 operator /(const Vector2 &first, const Vector2 &second) { return Vector2(first.x / second.x, first.y / second.y); }
	inline Vector2 operator /(const Vector2 &first, const float scalar) { return Vector2(first.x / scalar, first.y / scalar); }

	inline Vector2 operator -(Vector2 const &vec) { return Vector2(-vec.x, -vec.y); };

	inline bool operator ==(Vector2 const &first, Vector2 const &second) { return first.x == second.x && first.y == second.y; }
	inline bool operator !=(Vector2 const &first, Vector2 const &second) { return !operator==(first, second); }

	class Vector3
	{
	public:
		union
		{
			struct { float x, y, z; };
			struct { float r, g, b; };
			struct { float s, t, b; };
		};

		inline Vector3() : x(0.0f), y(0.0f), z(0.0f) { }
		explicit inline Vector3(const float scalar) : x(scalar), y(scalar), z(scalar) { }
		inline Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) { }
		explicit inline Vector3(const Vector2 &vec2, const float z) : x(vec2.x), y(vec2.y), z(z) { }
		explicit inline Vector3(const IntVector3 &ivec3) : x(ivec3.x), y(ivec3.y), z(ivec3.z) { }

		/*!
		Constructs a Vector3 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit inline Vector3(const Vector2 &vec) : x(vec.x), y(vec.y), z(0.0f) { }

		/*!
		Constructs a Vector3 with only the x, y, and z components of
		the input vector.

		@param vec A vector.
		*/
		explicit inline Vector3(const Vector4 &vec) : x(vec.x), y(vec.y), z(vec.z) { }

		inline Vector3 &operator +=(const Vector3 &first)
		{
			Vector3 result = operator+(*this, first);
			memcpy(this, &result, 3 * sizeof(float));
			return *this;
		}

		inline Vector3 &operator -=(const Vector3 &first)
		{
			Vector3 result = operator-(*this, first);
			memcpy(this, &result, 3 * sizeof(float));
			return *this;
		}

		inline Vector3 &operator *=(const Vector3 &first)
		{
			Vector3 result = operator*(*this, first);
			memcpy(this, &result, 3 * sizeof(float));
			return *this;
		}

		inline Vector3 &operator /=(const Vector3 &first)
		{
			Vector3 result = operator/(*this, first);
			memcpy(this, &result, 3 * sizeof(float));
			return *this;
		}
	};

	inline Vector3 operator +(const Vector3 &first, const Vector3 &second) { return Vector3(first.x + second.x, first.y + second.y, first.z + second.z); }
	inline Vector3 operator -(const Vector3 &first, const Vector3 &second) { return Vector3(first.x - second.x, first.y - second.y, first.z - second.z); }
	inline Vector3 operator *(const Vector3 &first, const Vector3 &second) { return Vector3(first.x * second.x, first.y * second.y, first.z * second.z); }
	inline Vector3 operator *(const Vector3 &first, const float scalar) { return Vector3(first.x * scalar, first.y * scalar, first.z * scalar); }
	inline Vector3 operator *(const float scalar, const Vector3 &vec) { return Vector3(vec.x * scalar, vec.y * scalar, vec.z * scalar); }
	inline Vector3 operator /(const Vector3 &first, const Vector3 &second) { return Vector3(first.x / second.x, first.y / second.y, first.z / second.z); }
	inline Vector3 operator /(const Vector3 &first, const float scalar) { return Vector3(first.x / scalar, first.y / scalar, first.z / scalar); }

	inline Vector3 operator -(const Vector3 &vec) { return Vector3(-vec.x, -vec.y, -vec.z); }

	inline bool operator ==(const Vector3 &first, const Vector3 &second) { return first.x == second.x && first.y == second.y && first.z == second.z; }
	inline bool operator !=(const Vector3 &first, const Vector3 &second) { return !operator==(first, second); }

	class Vector4
	{
	public:
		union
		{
			struct { float x, y, z, w; };
			struct { float r, g, b, a; };
			struct { float s, t, p, q; };
		};

		inline Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }
		explicit inline Vector4(const float scalar) : x(scalar), y(scalar), z(scalar), w(scalar) { }
		inline Vector4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) { }
		explicit inline Vector4(const Vector2 &first, const Vector2 &second) : x(first.x), y(first.y), z(second.x), w(second.y) { }
		explicit inline Vector4(const Vector3 &vec, const float w) : x(vec.x), y(vec.y), z(vec.z), w(w) { }
		explicit inline Vector4(const IntVector4 &vec) : x(vec.x), y(vec.y), z(vec.z), z(vec.w) { }

		/*!
		Constructs a Vector4 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit inline Vector4(const Vector2 &vec) : x(vec.x), y(vec.y), z(0.0f), w(0.0f) { }

		/*!
		Constructs a Vector4 with the x, y, and z components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit inline Vector4(const Vector3 &vec) : x(vec.x), y(vec.y), z(vec.z), w(0.0f) { }

		inline Vector4 &operator +=(const Vector4 &first)
		{
			Vector4 result = operator+(*this, first);
			memcpy(this, &result, 4 * sizeof(float));
			return *this;
		}

		inline Vector4 &operator -=(const Vector4 &first)
		{
			Vector4 result = operator-(*this, first);
			memcpy(this, &result, 4 * sizeof(float));
			return *this;
		}

		inline Vector4 &operator *=(const Vector4 &first)
		{
			Vector4 result = operator*(*this, first);
			memcpy(this, &result, 4 * sizeof(float));
			return *this;
		}

		inline Vector4 &operator /=(const Vector4 &first)
		{
			Vector4 result = operator/(*this, first);
			memcpy(this, &result, 4 * sizeof(float));
			return *this;
		}
	};

	inline Vector4 operator +(const Vector4 &first, const Vector4 &second) { return Vector4(first.x + second.x, first.y + second.y, first.z + second.z, first.w + second.w); }
	inline Vector4 operator -(const Vector4 &first, const Vector4 &second) { return Vector4(first.x - second.x, first.y - second.y, first.z - second.z, first.w - second.w); }
	inline Vector4 operator *(const Vector4 &first, const Vector4 &second) { return Vector4(first.x * second.x, first.y * second.y, first.z * second.z, first.w * second.w); }
	inline Vector4 operator *(const Vector4 &first, const float scalar) { return Vector4(first.x * scalar, first.y * scalar, first.z * scalar, first.w * scalar); }
	inline Vector4 operator /(Vector4 &first, Vector4 &second) { return Vector4(first.x / second.x, first.y / second.y, first.z / second.z, first.w / second.w); }
	inline Vector4 operator /(Vector4 &first, float scalar) { return Vector4(first.x / scalar, first.y / scalar, first.z / scalar, first.w * scalar); }

	inline Vector4 operator -(Vector4 const &vec) { return Vector4(-vec.x, -vec.y, -vec.z, -vec.w); };
	inline bool operator ==(Vector4 const &first, Vector4 const &second) { return first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w; }
	inline bool operator !=(Vector4 const &first, Vector4 const &second) { return !operator==(first, second); }

	// 32-bit Integer Vectors

	class MUTIL_EXPORT IntVector2
	{
	public:
		union
		{
			struct { int32_t x, y; };
			struct { int32_t r, g; };
			struct { int32_t s, t; };
		};

		IntVector2();
		explicit IntVector2(int32_t const scalar);
		IntVector2(int32_t const x, int32_t const y);
		explicit IntVector2(Vector2 const &vec2);

		/*!
		Constructs an IntVector2 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		IntVector2(IntVector3 const &vec);

		/*!
		Constructs an IntVector2 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		IntVector2(IntVector4 const &vec);

		inline IntVector2 &operator +=(IntVector2 const &first);
		inline IntVector2 &operator -=(IntVector2 const &first);
		inline IntVector2 &operator *=(IntVector2 const &first);
		inline IntVector2 &operator /=(IntVector2 const &first);
	};

	inline IntVector2 MUTIL_EXPORT operator +(IntVector2 const &first, IntVector2 const &second);
	inline IntVector2 MUTIL_EXPORT operator -(IntVector2 const &first, IntVector2 const &second);
	inline IntVector2 MUTIL_EXPORT operator *(IntVector2 const &first, IntVector2 const &second);
	inline IntVector2 MUTIL_EXPORT operator *(IntVector2 const &first, int32_t const &scalar);
	inline IntVector2 MUTIL_EXPORT operator *(int32_t const &scalar, IntVector2 const &vec);
	inline IntVector2 MUTIL_EXPORT operator /(IntVector2 const &first, IntVector2 const &second);
	inline IntVector2 MUTIL_EXPORT operator /(IntVector2 const &first, int32_t const &scalar);

	inline IntVector2 MUTIL_EXPORT operator -(IntVector2 const &vec);

	inline bool MUTIL_EXPORT operator ==(IntVector2 const &first, IntVector2 const &second);
	inline bool MUTIL_EXPORT operator !=(IntVector2 const &first, IntVector2 const &second);

	class MUTIL_EXPORT IntVector3
	{
	public:
		union
		{
			struct { int32_t x, y, z; };
			struct { int32_t r, g, b; };
			struct { int32_t s, t, b; };
		};

		IntVector3();
		explicit IntVector3(int32_t const scalar);
		IntVector3(int32_t const x, int32_t const y, int32_t const z);
		explicit IntVector3(IntVector2 const &vec2, int32_t const s);
		explicit IntVector3(Vector3 const &vec3);

		/*!
		Constructs an IntVector3 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		IntVector3(IntVector2 const &vec);

		/*!
		Constructs an IntVector3 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		IntVector3(IntVector4 const &vec);

		inline IntVector3 &operator +=(IntVector3 const &first);
		inline IntVector3 &operator -=(IntVector3 const &first);
		inline IntVector3 &operator *=(IntVector3 const &first);
		inline IntVector3 &operator /=(IntVector3 const &first);
	};

	inline IntVector3 MUTIL_EXPORT operator +(IntVector3 const &first, IntVector3 const &second);
	inline IntVector3 MUTIL_EXPORT operator -(IntVector3 const &first, IntVector3 const &second);
	inline IntVector3 MUTIL_EXPORT operator *(IntVector3 const &first, IntVector3 const &second);
	inline IntVector3 MUTIL_EXPORT operator *(IntVector3 const &first, int32_t const &scalar);
	inline IntVector3 MUTIL_EXPORT operator *(int32_t const &scalar, IntVector3 const &vec);
	inline IntVector3 MUTIL_EXPORT operator /(IntVector3 const &first, IntVector3 const &second);
	inline IntVector3 MUTIL_EXPORT operator /(IntVector3 const &first, int32_t const &scalar);

	inline IntVector3 MUTIL_EXPORT operator -(IntVector3 const &vec);

	inline bool MUTIL_EXPORT operator ==(IntVector3 const &first, IntVector3 const &second);
	inline bool MUTIL_EXPORT operator !=(IntVector3 const &first, IntVector3 const &second);

	class MUTIL_EXPORT IntVector4
	{
	public:
		union
		{
			struct { int32_t x, y, z, w; };
			struct { int32_t r, g, b, a; };
			struct { int32_t s, t, p, q; };
		};

		IntVector4();
		explicit IntVector4(int32_t const scalar);
		IntVector4(int32_t const x, int32_t const y, int32_t const z, int32_t const w);
		explicit IntVector4(IntVector2 const &first, IntVector2 const &second);
		explicit IntVector4(IntVector3 const &vec3, int32_t const w);
		explicit IntVector4(Vector4 const &vec4);

		/*!
		Constructs an IntVector4 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		IntVector4(IntVector2 const &vec);

		/*!
		Constructs an IntVector4 with the x, y, and z components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		IntVector4(IntVector3 const &vec);

		inline IntVector4 &operator +=(IntVector4 const &first);
		inline IntVector4 &operator -=(IntVector4 const &first);
		inline IntVector4 &operator *=(IntVector4 const &first);
		inline IntVector4 &operator /=(IntVector4 const &first);
	};

	inline IntVector4 MUTIL_EXPORT operator +(IntVector4 const &first, IntVector4 const &second);
	inline IntVector4 MUTIL_EXPORT operator -(IntVector4 const &first, IntVector4 const &second);
	inline IntVector4 MUTIL_EXPORT operator *(IntVector4 const &first, IntVector4 const &second);
	inline IntVector4 MUTIL_EXPORT operator *(IntVector4 const &first, int32_t const &scalar);
	inline IntVector4 MUTIL_EXPORT operator *(int32_t const &scalar, IntVector4 const &vec);
	inline IntVector4 MUTIL_EXPORT operator /(IntVector4 const &first, IntVector4 const &second);
	inline IntVector4 MUTIL_EXPORT operator /(IntVector4 const &first, int32_t const &scalar);

	inline IntVector4 MUTIL_EXPORT operator -(IntVector4 const &vec);

	inline bool MUTIL_EXPORT operator ==(IntVector4 const &first, IntVector4 const &second);
	inline bool MUTIL_EXPORT operator !=(IntVector4 const &first, IntVector4 const &second);
}

#endif