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
		explicit inline Vector2(const IntVector2 &ivec2);

		/*!
		Constructs a Vector2 with only the x and y components of
		the input vector.
		
		@param vec A vector.
		*/
		explicit inline Vector2(const Vector3 &vec);

		/*!
		Constructs a Vector2 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		explicit inline Vector2(const Vector4 &vec);

		inline Vector2 &operator +=(const Vector2 &first);
		inline Vector2 &operator -=(const Vector2 &first);
		inline Vector2 &operator *=(const Vector2 &first);
		inline Vector2 &operator /=(const Vector2 &first);
	};

	inline Vector2 operator +(const Vector2 &first, const Vector2 &second) { return Vector2(first.x + second.x, first.y + second.y); }
	inline Vector2 operator -(const Vector2 &first, const Vector2 &second) { return Vector2(first.x - second.x, first.y - second.y); }
	inline Vector2 operator *(const Vector2 &first, const Vector2 &second) { return Vector2(first.x * second.x, first.y * second.y); }
	inline Vector2 operator *(const Vector2 &first, const float &scalar) { return Vector2(first.x * scalar, first.y * scalar); }
	inline Vector2 operator /(const Vector2 &first, const Vector2 &second) { return Vector2(first.x / second.x, first.y / second.y); }
	inline Vector2 operator /(const Vector2 &first, const float &scalar) { return Vector2(first.x / scalar, first.y / scalar); }

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
		explicit inline Vector3(const float &scalar) : x(scalar), y(scalar), z(scalar) { }
		inline Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) { }
		explicit inline Vector3(const Vector2 &vec2, const float z);
		explicit inline Vector3(const IntVector3 &ivec3);

		/*!
		Constructs a Vector3 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit inline Vector3(const Vector2 &vec);

		/*!
		Constructs a Vector3 with only the x, y, and z components of
		the input vector.

		@param vec A vector.
		*/
		explicit inline Vector3(const Vector4 &vec);

		inline Vector3 &operator +=(const Vector3 &first);
		inline Vector3 &operator -=(const Vector3 &first);
		inline Vector3 &operator *=(const Vector3 &first);
		inline Vector3 &operator /=(const Vector3 &first);
	};

	inline Vector3 operator +(const Vector3 &first, const Vector3 &second) { return Vector3(first.x + second.x, first.y + second.y, first.z + second.z); }
	inline Vector3 operator -(const Vector3 &first, const Vector3 &second) { return Vector3(first.x - second.x, first.y - second.y, first.z - second.z); }
	inline Vector3 operator *(const Vector3 &first, const Vector3 &second) { return Vector3(first.x * second.x, first.y * second.y, first.z * second.z); }
	inline Vector3 operator *(const Vector3 &first, const float &scalar) { return Vector3(first.x * scalar, first.y * scalar, first.z * scalar); }
	inline Vector3 operator /(const Vector3 &first, const Vector3 &second) { return Vector3(first.x / second.x, first.y / second.y, first.z / second.z); }
	inline Vector3 operator /(const Vector3 &first, const float &scalar) { return Vector3(first.x / scalar, first.y / scalar, first.z / scalar); }

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
		explicit inline Vector4(const Vector2 &first, const Vector2 &second);
		explicit inline Vector4(const Vector3 &vec, const float w);
		explicit inline Vector4(const IntVector4 &vec);

		/*!
		Constructs a Vector4 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit inline Vector4(const Vector2 &vec);

		/*!
		Constructs a Vector4 with the x, y, and z components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit inline Vector4(const Vector3 &vec);

		inline Vector4 &operator +=(const Vector4 &first);
		inline Vector4 &operator -=(const Vector4 &first);
		inline Vector4 &operator *=(const Vector4 &first);
		inline Vector4 &operator /=(const Vector4 &first);
	};

	inline Vector4 operator +(const Vector4 &first, const Vector4 &second) { return Vector4(first.x + second.x, first.y + second.y, first.z + second.z, first.w + second.w); }
	inline Vector4 operator -(const Vector4 &first, const Vector4 &second) { return Vector4(first.x - second.x, first.y - second.y, first.z - second.z, first.w - second.w); }
	inline Vector4 operator *(const Vector4 &first, const Vector4 &second) { return Vector4(first.x * second.x, first.y * second.y, first.z * second.z, first.w * second.w); }
	inline Vector4 operator *(const Vector4 &first, const float &scalar) { return Vector4(first.x * scalar, first.y * scalar, first.z * scalar, first.w * scalar); }
	inline Vector4 operator /(const Vector4 &first, const Vector4 &second) { return Vector4(first.x / second.x, first.y / second.y, first.z / second.z, first.w / second.w); }
	inline Vector4 operator /(const Vector4 &first, const float &scalar) { return Vector4(first.x / scalar, first.y / scalar, first.z / scalar, first.w * scalar); }

	inline Vector4 operator -(const Vector4 &vec) { return Vector4(-vec.x, -vec.y, -vec.z, -vec.w); };
	inline bool operator ==(const Vector4 &first, const Vector4 &second) { return first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w; }
	inline bool operator !=(const Vector4 &first, const Vector4 &second) { return !operator==(first, second); }

	// 32-bit Integer Vectors

	class IntVector2
	{
	public:
		union
		{
			struct { int32_t x, y; };
			struct { int32_t r, g; };
			struct { int32_t s, t; };
		};

		inline IntVector2() : x(0), y(0) { }
		explicit inline IntVector2(const int32_t scalar) : x(scalar), y(scalar) { }
		inline IntVector2(const int32_t x, const int32_t y) : x(x), y(y) { }
		explicit inline IntVector2(const Vector2 &vec);

		/*!
		Constructs an IntVector2 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		explicit inline IntVector2(const IntVector3 &vec);

		/*!
		Constructs an IntVector2 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		explicit inline IntVector2(const IntVector4 &vec);

		inline IntVector2 &operator +=(const IntVector2 &first);
		inline IntVector2 &operator -=(const IntVector2 &first);
		inline IntVector2 &operator *=(const IntVector2 &first);
		inline IntVector2 &operator /=(const IntVector2 &first);
	};

	inline IntVector2 operator +(const IntVector2 &first, const IntVector2 &second) { return IntVector2(first.x + second.x, first.y + second.y); }
	inline IntVector2 operator -(const IntVector2 &first, const IntVector2 &second) { return IntVector2(first.x - second.x, first.y - second.y); }
	inline IntVector2 operator *(const IntVector2 &first, const IntVector2 &second) { return IntVector2(first.x * second.x, first.y * second.y); }
	inline IntVector2 operator *(const IntVector2 &first, const int32_t &scalar) { return IntVector2(first.x * scalar, first.y * scalar); }
	inline IntVector2 operator /(const IntVector2 &first, const IntVector2 &second) { return IntVector2(first.x / second.x, first.y / second.y); }
	inline IntVector2 operator /(const IntVector2 &first, const int32_t &scalar) { return IntVector2(first.x / scalar, first.y / scalar); }

	inline IntVector2 operator -(const IntVector2 &vec) { return IntVector2(-vec.x, -vec.y); };

	inline bool operator ==(const IntVector2 &first, const IntVector2 &second) { return first.x == second.x && first.y == second.y; }
	inline bool operator !=(const IntVector2 &first, const IntVector2 &second) { return !operator==(first, second); }

	class IntVector3
	{
	public:
		union
		{
			struct { int32_t x, y, z; };
			struct { int32_t r, g, b; };
			struct { int32_t s, t, b; };
		};

		inline IntVector3() : x(0), y(0), z(0) { }
		explicit inline IntVector3(const int32_t scalar) : x(scalar), y(scalar), z(scalar) { }
		inline IntVector3(const int32_t x, const int32_t y, const int32_t z) : x(x), y(y), z(z) { }
		explicit inline IntVector3(const IntVector2 &vec, const int32_t z);
		explicit inline IntVector3(const Vector3 &vec);

		/*!
		Constructs an IntVector3 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit inline IntVector3(const IntVector2 &vec);

		/*!
		Constructs an IntVector3 with only the x and y components of
		the input vector.

		@param vec A vector.
		*/
		explicit inline IntVector3(const IntVector4 &vec);

		inline IntVector3 &operator +=(const IntVector3 &first);
		inline IntVector3 &operator -=(const IntVector3 &first);
		inline IntVector3 &operator *=(const IntVector3 &first);
		inline IntVector3 &operator /=(const IntVector3 &first);
	};

	inline IntVector3 operator +(const IntVector3 &first, const IntVector3 &second) { return IntVector3(first.x + second.x, first.y + second.y, first.z + second.z); }
	inline IntVector3 operator -(const IntVector3 &first, const IntVector3 &second) { return IntVector3(first.x - second.x, first.y - second.y, first.z - second.z); }
	inline IntVector3 operator *(const IntVector3 &first, const IntVector3 &second) { return IntVector3(first.x * second.x, first.y * second.y, first.z * second.z); }
	inline IntVector3 operator *(const IntVector3 &first, const int32_t &scalar) { return IntVector3(first.x * scalar, first.y * scalar, first.z * scalar); }
	inline IntVector3 operator /(const IntVector3 &first, const IntVector3 &second) { return IntVector3(first.x / second.x, first.y / second.y, first.z / second.z); }
	inline IntVector3 operator /(const IntVector3 &first, const int32_t &scalar) { return IntVector3(first.x / scalar, first.y / scalar, first.z * scalar); }

	inline IntVector3 operator -(const IntVector3 &vec) { return IntVector3(-vec.x, -vec.y, -vec.z); };

	inline bool operator ==(const IntVector3 &first, const IntVector3 &second) { return first.x == second.x && first.y == second.y && first.z == second.z; }
	inline bool operator !=(const IntVector3 &first, const IntVector3 &second) { return !operator==(first, second); }

	class IntVector4
	{
	public:
		union
		{
			struct { int32_t x, y, z, w; };
			struct { int32_t r, g, b, a; };
			struct { int32_t s, t, p, q; };
		};

		inline IntVector4() : x(0), y(0), z(0), w(0) { }
		explicit inline IntVector4(const int32_t scalar) : x(scalar), y(scalar), z(scalar), w(scalar) { }
		inline IntVector4(const int32_t x, const int32_t y, const int32_t z, const int32_t w) : x(x), y(y), z(z), w(w) { }
		explicit inline IntVector4(const IntVector2 &first, const IntVector2 &second);
		explicit inline IntVector4(const IntVector3 &vec, const int32_t w);
		explicit inline IntVector4(const Vector4 &vec);

		/*!
		Constructs an IntVector4 with the x and y components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit inline IntVector4(const IntVector2 &vec);

		/*!
		Constructs an IntVector4 with the x, y, and z components of
		the input vector, and the rest zeroed.

		@param vec A vector.
		*/
		explicit inline IntVector4(const IntVector3 &vec);

		inline IntVector4 &operator +=(const IntVector4 &first);
		inline IntVector4 &operator -=(const IntVector4 &first);
		inline IntVector4 &operator *=(const IntVector4 &first);
		inline IntVector4 &operator /=(const IntVector4 &first);

	};

	inline IntVector4 operator +(const IntVector4 &first, const IntVector4 &second) { return IntVector4(first.x + second.x, first.y + second.y, first.z + second.z, first.w + second.w); }
	inline IntVector4 operator -(const IntVector4 &first, const IntVector4 &second) { return IntVector4(first.x - second.x, first.y - second.y, first.z - second.z, first.w - second.w); }
	inline IntVector4 operator *(const IntVector4 &first, const IntVector4 &second) { return IntVector4(first.x * second.x, first.y * second.y, first.z * second.z, first.w * second.w); }
	inline IntVector4 operator *(const IntVector4 &first, const int32_t &scalar) { return IntVector4(first.x * scalar, first.y * scalar, first.z * scalar, first.w * scalar); }
	inline IntVector4 operator /(const IntVector4 &first, const IntVector4 &second) { return IntVector4(first.x / second.x, first.y / second.y, first.z / second.z, first.w / second.w); }
	inline IntVector4 operator /(const IntVector4 &first, const int32_t &scalar) { return IntVector4(first.x / scalar, first.y / scalar, first.z * scalar, first.w / scalar); }

	inline IntVector4 operator -(IntVector4 const &vec) { return IntVector4(-vec.x, -vec.y, -vec.z, -vec.w); };

	inline bool operator ==(IntVector4 const &first, IntVector4 const &second) { return first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w; }
	inline bool operator !=(IntVector4 const &first, IntVector4 const &second) { return !operator==(first, second); }



	inline Vector2::Vector2(const IntVector2 &ivec2) : x((float)ivec2.x), y((float)ivec2.y) { }
	inline Vector2::Vector2(const Vector3 &vec) : x(vec.x), y(vec.y) { }
	inline Vector2::Vector2(const Vector4 &vec) : x(vec.x), y(vec.y) { }

	inline Vector2 &Vector2::operator +=(const Vector2 &first)
	{
		Vector2 result = operator+(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	inline Vector2 &Vector2::operator -=(const Vector2 &first)
	{
		Vector2 result = operator-(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	inline Vector2 &Vector2::operator *=(const Vector2 &first)
	{
		Vector2 result = operator*(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	inline Vector2 &Vector2::operator /=(const Vector2 &first)
	{
		Vector2 result = operator/(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	inline Vector3::Vector3(const Vector2 &vec2, const float z) : x(vec2.x), y(vec2.y), z(z) { }
	inline Vector3::Vector3(const IntVector3 &ivec3) : x((float)ivec3.x), y((float)ivec3.y), z((float)ivec3.z) { }
	inline Vector3::Vector3(const Vector2 &vec) : x(vec.x), y(vec.y), z(0.0f) { }
	inline Vector3::Vector3(const Vector4 &vec) : x(vec.x), y(vec.y), z(vec.z) { }

	inline Vector3 &Vector3::operator +=(const Vector3 &first)
	{
		Vector3 result = operator+(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	inline Vector3 &Vector3::operator -=(const Vector3 &first)
	{
		Vector3 result = operator-(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	inline Vector3 &Vector3::operator *=(const Vector3 &first)
	{
		Vector3 result = operator*(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	inline Vector3 &Vector3::operator /=(const Vector3 &first)
	{
		Vector3 result = operator/(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	inline Vector4::Vector4(const Vector2 &first, const Vector2 &second) : x(first.x), y(first.y), z(second.x), w(second.y) { }
	inline Vector4::Vector4(const Vector3 &vec, const float w) : x(vec.x), y(vec.y), z(vec.z), w(w) { }
	inline Vector4::Vector4(const IntVector4 &vec) : x((float)vec.x), y((float)vec.y), z((float)vec.z), w((float)vec.w) { }
	inline Vector4::Vector4(const Vector2 &vec) : x(vec.x), y(vec.y), z(0.0f), w(0.0f) { }
	inline Vector4::Vector4(const Vector3 &vec) : x(vec.x), y(vec.y), z(vec.z), w(0.0f) { }

	inline Vector4 &Vector4::operator +=(const Vector4 &first)
	{
		Vector4 result = operator+(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}

	inline Vector4 &Vector4::operator -=(const Vector4 &first)
	{
		Vector4 result = operator-(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}

	inline Vector4 &Vector4::operator *=(const Vector4 &first)
	{
		Vector4 result = operator*(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}

	inline Vector4 &Vector4::operator /=(const Vector4 &first)
	{
		Vector4 result = operator/(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}


	inline IntVector2::IntVector2(const Vector2 &vec) : x((int32_t)vec.x), y((int32_t)vec.y) { }
	inline IntVector2::IntVector2(const IntVector3 &vec) : x(vec.x), y(vec.y) { }
	inline IntVector2::IntVector2(const IntVector4 &vec) : x(vec.x), y(vec.y) { }

	inline IntVector2 &IntVector2::operator +=(const IntVector2 &first)
	{
		IntVector2 result = operator+(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	inline IntVector2 &IntVector2::operator -=(const IntVector2 &first)
	{
		IntVector2 result = operator-(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	inline IntVector2 &IntVector2::operator *=(const IntVector2 &first)
	{
		IntVector2 result = operator*(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	inline IntVector2 &IntVector2::operator /=(const IntVector2 &first)
	{
		IntVector2 result = operator/(*this, first);
		memcpy(this, &result, 2 * sizeof(float));
		return *this;
	}

	inline IntVector3::IntVector3(const IntVector2 &vec, const int32_t z) : x(vec.x), y(vec.y), z(z) { }
	inline IntVector3::IntVector3(const Vector3 &vec) : x((int32_t)vec.x), y((int32_t)vec.y), z((int32_t)vec.z) { }
	inline IntVector3::IntVector3(const IntVector2 &vec) : x(vec.x), y(vec.x), z(0) { }
	inline IntVector3::IntVector3(const IntVector4 &vec) : x(vec.x), y(vec.y), z(vec.z) { }

	inline IntVector3 &IntVector3::operator +=(const IntVector3 &first)
	{
		IntVector3 result = operator+(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	inline IntVector3 &IntVector3::operator -=(const IntVector3 &first)
	{
		IntVector3 result = operator-(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	inline IntVector3 &IntVector3::operator *=(const IntVector3 &first)
	{
		IntVector3 result = operator*(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	inline IntVector3 &IntVector3::operator /=(const IntVector3 &first)
	{
		IntVector3 result = operator/(*this, first);
		memcpy(this, &result, 3 * sizeof(float));
		return *this;
	}

	inline IntVector4::IntVector4(const IntVector2 &first, const IntVector2 &second) : x(first.x), y(first.y), z(second.x), w(second.y) { }
	inline IntVector4::IntVector4(const IntVector3 &vec, const int32_t w) : x(vec.x), y(vec.y), z(vec.z), w(w) { }
	inline IntVector4::IntVector4(const Vector4 &vec) : x((int32_t)vec.x), y((int32_t)vec.y), z((int32_t)vec.z), w((int32_t)vec.w) { }
	inline IntVector4::IntVector4(const IntVector2 &vec) : x(vec.x), y(vec.y), z(0), w(0) { }
	inline IntVector4::IntVector4(const IntVector3 &vec) : x(vec.x), y(vec.y), z(vec.z), w(0) { }

	inline IntVector4 &IntVector4::operator +=(const IntVector4 &first)
	{
		IntVector4 result = operator+(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}

	inline IntVector4 &IntVector4::operator -=(const IntVector4 &first)
	{
		IntVector4 result = operator-(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}

	inline IntVector4 &IntVector4::operator *=(const IntVector4 &first)
	{
		IntVector4 result = operator*(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}

	inline IntVector4 &IntVector4::operator /=(const IntVector4 &first)
	{
		IntVector4 result = operator/(*this, first);
		memcpy(this, &result, 4 * sizeof(float));
		return *this;
	}
}

#endif