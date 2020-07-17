#include "vec_types.h"

#include <memory>

using namespace mutil;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vector2
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

mutil::Vector2::Vector2() : x(0.0f), y(0.0f) { }
mutil::Vector2::Vector2(float const scalar) : x(scalar), y(scalar) { }
mutil::Vector2::Vector2(float const x, float const y) : x(x), y(y) { }
mutil::Vector2::Vector2(IntVector2 const &ivec2) : x((int32_t)ivec2.x), y((int32_t)ivec2.y) { }
mutil::Vector2::Vector2(Vector3 const &vec) : x(vec.x), y(vec.y) { }
mutil::Vector2::Vector2(Vector4 const &vec) : x(vec.x), y(vec.y) { }

Vector2 &mutil::Vector2::operator+=(Vector2 const &first)
{
	Vector2 result = operator+(*this, first);
	memcpy(this, &result, 2 * sizeof(float));
	return *this;
}

Vector2 &mutil::Vector2::operator-=(Vector2 const &first)
{
	Vector2 result = operator-(*this, first);
	memcpy(this, &result, 2 * sizeof(float));
	return *this;
}

Vector2 &mutil::Vector2::operator*=(Vector2 const &first)
{
	Vector2 result = operator*(*this, first);
	memcpy(this, &result, 2 * sizeof(float));
	return *this;
}

Vector2 &mutil::Vector2::operator/=(Vector2 const &first)
{
	Vector2 result = operator/(*this, first);
	memcpy(this, &result, 2 * sizeof(float));
	return *this;
}

Vector2 mutil::operator +(Vector2 const &first, Vector2 const &second) { return Vector2(first.x + second.x, first.y + second.y); }
Vector2 mutil::operator -(Vector2 const &first, Vector2 const &second) { return Vector2(first.x - second.x, first.y - second.y); }
Vector2 mutil::operator *(Vector2 const &first, Vector2 const &second) { return Vector2(first.x * second.x, first.y * second.y); }
Vector2 mutil::operator *(Vector2 const &first, float const &scalar) { return Vector2(first.x * scalar, first.y * scalar); }
Vector2 mutil::operator *(float const &scalar, Vector2 const &vec) { return Vector2(vec.x * scalar, vec.y * scalar); }
Vector2 mutil::operator /(Vector2 const &first, Vector2 const &second) { return Vector2(first.x / second.x, first.y / second.y); }
Vector2 mutil::operator /(Vector2 const &first, float const &scalar) { return Vector2(first.x / scalar, first.y / scalar); }

Vector2 mutil::operator-(Vector2 const &vec) { return Vector2(-vec.x, -vec.y); };

bool mutil::operator ==(Vector2 const &first, Vector2 const &second) { return first.x == second.x && first.y == second.y; }
bool mutil::operator !=(Vector2 const &first, Vector2 const &second) { return !operator==(first, second); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vector3
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

mutil::Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) { }
mutil::Vector3::Vector3(float const scalar) : x(scalar), y(scalar), z(scalar) { }
mutil::Vector3::Vector3(float const x, float const y, float const z) : x(x), y(y), z(z) { }
mutil::Vector3::Vector3(Vector2 const &vec2, float z) : x(vec2.x), y(vec2.y), z(z) { };
mutil::Vector3::Vector3(IntVector3 const &ivec3) : x((int32_t)ivec3.x), y((int32_t)ivec3.y), z((int32_t)ivec3.z) { }
mutil::Vector3::Vector3(Vector2 const &vec) : x(vec.x), y(vec.y), z(0.0f) { }
mutil::Vector3::Vector3(Vector4 const &vec) : x(vec.x), y(vec.y), z(vec.z) { }

Vector3 &mutil::Vector3::operator+=(Vector3 const &first)
{
	Vector3 result = operator+(*this, first);
	memcpy(this, &result, 3 * sizeof(float));
	return *this;
}

Vector3 &mutil::Vector3::operator-=(Vector3 const &first)
{
	Vector3 result = operator-(*this, first);
	memcpy(this, &result, 3 * sizeof(float));
	return *this;
}

Vector3 &mutil::Vector3::operator*=(Vector3 const &first)
{
	Vector3 result = operator*(*this, first);
	memcpy(this, &result, 3 * sizeof(float));
	return *this;
}

Vector3 &mutil::Vector3::operator/=(Vector3 const &first)
{
	Vector3 result = operator/(*this, first);
	memcpy(this, &result, 3 * sizeof(float));
	return *this;
}

Vector3 mutil::operator +(Vector3 const &first, Vector3 const &second) { return Vector3(first.x + second.x, first.y + second.y, first.z + second.z); }
Vector3 mutil::operator -(Vector3 const &first, Vector3 const &second) { return Vector3(first.x - second.x, first.y - second.y, first.z - second.z); }
Vector3 mutil::operator *(Vector3 const &first, Vector3 const &second) { return Vector3(first.x * second.x, first.y * second.y, first.z * second.z); }
Vector3 mutil::operator *(Vector3 const &first, float const &scalar) { return Vector3(first.x * scalar, first.y * scalar, first.z * scalar); }
Vector3 mutil::operator *(float const &scalar, Vector3 const &vec) { return Vector3(vec.x * scalar, vec.y * scalar, vec.z * scalar); }
Vector3 mutil::operator /(Vector3 const &first, Vector3 const &second) { return Vector3(first.x / second.x, first.y / second.y, first.z / second.z); }
Vector3 mutil::operator /(Vector3 const &first, float const &scalar) { return Vector3(first.x / scalar, first.y / scalar, first.z / scalar); }

Vector3 mutil::operator-(Vector3 const &vec) { return Vector3(-vec.x, -vec.y, -vec.z); };

bool mutil::operator ==(Vector3 const &first, Vector3 const &second) { return first.x == second.x && first.y == second.y && first.z == second.z; }
bool mutil::operator !=(Vector3 const &first, Vector3 const &second) { return !operator==(first, second); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Vector4
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

mutil::Vector4::Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }
mutil::Vector4::Vector4(float const scalar) : x(scalar), y(scalar), z(scalar), w(scalar) { }
mutil::Vector4::Vector4(float const x, float const y, float const z, float const w) : x(x), y(y), z(z), w(w) { }
mutil::Vector4::Vector4(Vector2 const &first, Vector2 const &second) : x(first.x), y(first.y), z(second.x), w(second.y) { }
mutil::Vector4::Vector4(Vector3 const &vec3, float w) : x(vec3.x), y(vec3.y), z(vec3.z), w(w) { };
mutil::Vector4::Vector4(IntVector4 const &ivec4) : x((int32_t)ivec4.x), y((int32_t)ivec4.y), z((int32_t)ivec4.z), w((int32_t)ivec4.w) { }
mutil::Vector4::Vector4(Vector2 const &vec) : x(vec.x), y(vec.y), z(0.0f), w(0.0f) { }
mutil::Vector4::Vector4(Vector3 const &vec) : x(vec.x), y(vec.y), z(vec.z), w(0.0f) { }

Vector4 &mutil::Vector4::operator+=(Vector4 const &first)
{
	Vector4 result = operator+(*this, first);
	memcpy(this, &result, 4 * sizeof(float));
	return *this;
}

Vector4 &mutil::Vector4::operator-=(Vector4 const &first)
{
	Vector4 result = operator-(*this, first);
	memcpy(this, &result, 4 * sizeof(float));
	return *this;
}

Vector4 &mutil::Vector4::operator*=(Vector4 const &first)
{
	Vector4 result = operator*(*this, first);
	memcpy(this, &result, 4 * sizeof(float));
	return *this;
}

Vector4 &mutil::Vector4::operator/=(Vector4 const &first)
{
	Vector4 result = operator/(*this, first);
	memcpy(this, &result, 4 * sizeof(float));
	return *this;
}

Vector4 mutil::operator +(Vector4 const &first, Vector4 const &second) { return Vector4(first.x + second.x, first.y + second.y, first.z + second.z, first.w + second.w); }
Vector4 mutil::operator -(Vector4 const &first, Vector4 const &second) { return Vector4(first.x - second.x, first.y - second.y, first.z - second.z, first.w - second.w); }
Vector4 mutil::operator *(Vector4 const &first, Vector4 const &second) { return Vector4(first.x * second.x, first.y * second.y, first.z * second.z, first.w * second.w); }
Vector4 mutil::operator *(Vector4 const &first, float const &scalar) { return Vector4(first.x * scalar, first.y * scalar, first.z * scalar, first.w * scalar); }
Vector4 mutil::operator *(float const &scalar, Vector4 const &vec) { return Vector4(vec.x * scalar, vec.y * scalar, vec.z * scalar, vec.w * scalar); }
Vector4 mutil::operator /(Vector4 const &first, Vector4 const &second) { return Vector4(first.x / second.x, first.y / second.y, first.z / second.z, first.w / second.w); }
Vector4 mutil::operator /(Vector4 const &first, float const &scalar) { return Vector4(first.x / scalar, first.y / scalar, first.z / scalar, first.w * scalar); }

Vector4 mutil::operator-(Vector4 const &vec) { return Vector4(-vec.x, -vec.y, -vec.z, -vec.w); };

bool mutil::operator ==(Vector4 const &first, Vector4 const &second) { return first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w; }
bool mutil::operator !=(Vector4 const &first, Vector4 const &second) { return !operator==(first, second); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IntVector2
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

mutil::IntVector2::IntVector2() : x(0), y(0) { }
mutil::IntVector2::IntVector2(int32_t const scalar) : x(scalar), y(scalar) { }
mutil::IntVector2::IntVector2(int32_t const x, int32_t const y) : x(x), y(y) { }
mutil::IntVector2::IntVector2(Vector2 const &vec2) : x((int32_t)vec2.x), y((int32_t)vec2.y) { }
mutil::IntVector2::IntVector2(IntVector3 const &vec) : x(vec.x), y(vec.y) { }
mutil::IntVector2::IntVector2(IntVector4 const &vec) : x(vec.x), y(vec.y) { }

IntVector2 &mutil::IntVector2::operator+=(IntVector2 const &first)
{
	IntVector2 result = operator+(*this, first);
	memcpy(this, &result, 2 * sizeof(float));
	return *this;
}

IntVector2 &mutil::IntVector2::operator-=(IntVector2 const &first)
{
	IntVector2 result = operator-(*this, first);
	memcpy(this, &result, 2 * sizeof(float));
	return *this;
}

IntVector2 &mutil::IntVector2::operator*=(IntVector2 const &first)
{
	IntVector2 result = operator*(*this, first);
	memcpy(this, &result, 2 * sizeof(float));
	return *this;
}

IntVector2 &mutil::IntVector2::operator/=(IntVector2 const &first)
{
	IntVector2 result = operator/(*this, first);
	memcpy(this, &result, 2 * sizeof(float));
	return *this;
}

IntVector2 mutil::operator +(IntVector2 const &first, IntVector2 const &second) { return IntVector2(first.x + second.x, first.y + second.y); }
IntVector2 mutil::operator -(IntVector2 const &first, IntVector2 const &second) { return IntVector2(first.x - second.x, first.y - second.y); }
IntVector2 mutil::operator *(IntVector2 const &first, IntVector2 const &second) { return IntVector2(first.x * second.x, first.y * second.y); }
IntVector2 mutil::operator *(IntVector2 const &first, int32_t const &scalar) { return IntVector2(first.x * scalar, first.y * scalar); }
IntVector2 mutil::operator *(int32_t const &scalar, IntVector2 const &vec) { return IntVector2(vec.x * scalar, vec.y * scalar); }
IntVector2 mutil::operator /(IntVector2 const &first, IntVector2 const &second) { return IntVector2(first.x / second.x, first.y / second.y); }
IntVector2 mutil::operator /(IntVector2 const &first, int32_t const &scalar) { return IntVector2(first.x / scalar, first.y / scalar); }

IntVector2 mutil::operator-(IntVector2 const &vec) { return IntVector2(-vec.x, -vec.y); };

bool mutil::operator ==(IntVector2 const &first, IntVector2 const &second) { return first.x == second.x && first.y == second.y; }
bool mutil::operator !=(IntVector2 const &first, IntVector2 const &second) { return !operator==(first, second); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IntVector3
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

mutil::IntVector3::IntVector3() : x(0), y(0), z(0) { }
mutil::IntVector3::IntVector3(int32_t const scalar) : x(scalar), y(scalar), z(scalar) { }
mutil::IntVector3::IntVector3(int32_t const x, int32_t const y, int32_t const z) : x(x), y(y), z(z) { }
mutil::IntVector3::IntVector3(IntVector2 const &vec2, int32_t s) : x(vec2.x), y(vec2.y), z(z) { };
mutil::IntVector3::IntVector3(Vector3 const &vec3) : x((int32_t)vec3.x), y((int32_t)vec3.y), z((int32_t)vec3.z) { }
mutil::IntVector3::IntVector3(IntVector2 const &vec) : x(vec.x), y(vec.y), z(0.0f) { }
mutil::IntVector3::IntVector3(IntVector4 const &vec) : x(vec.x), y(vec.y), z(vec.z) { }

IntVector3 &mutil::IntVector3::operator+=(IntVector3 const &first)
{
	IntVector3 result = operator+(*this, first);
	memcpy(this, &result, 3 * sizeof(float));
	return *this;
}

IntVector3 &mutil::IntVector3::operator-=(IntVector3 const &first)
{
	IntVector3 result = operator-(*this, first);
	memcpy(this, &result, 3 * sizeof(float));
	return *this;
}

IntVector3 &mutil::IntVector3::operator*=(IntVector3 const &first)
{
	IntVector3 result = operator*(*this, first);
	memcpy(this, &result, 3 * sizeof(float));
	return *this;
}

IntVector3 &mutil::IntVector3::operator/=(IntVector3 const &first)
{
	IntVector3 result = operator/(*this, first);
	memcpy(this, &result, 3 * sizeof(float));
	return *this;
}

IntVector3 mutil::operator +(IntVector3 const &first, IntVector3 const &second) { return IntVector3(first.x + second.x, first.y + second.y, first.z + second.z); }
IntVector3 mutil::operator -(IntVector3 const &first, IntVector3 const &second) { return IntVector3(first.x - second.x, first.y - second.y, first.z - second.z); }
IntVector3 mutil::operator *(IntVector3 const &first, IntVector3 const &second) { return IntVector3(first.x * second.x, first.y * second.y, first.z * second.z); }
IntVector3 mutil::operator *(IntVector3 const &first, int32_t const &scalar) { return IntVector3(first.x * scalar, first.y * scalar, first.z * scalar); }
IntVector3 mutil::operator *(int32_t const &scalar, IntVector3 const &vec) { return IntVector3(vec.x * scalar, vec.y * scalar, vec.z * scalar); }
IntVector3 mutil::operator /(IntVector3 const &first, IntVector3 const &second) { return IntVector3(first.x / second.x, first.y / second.y, first.z / second.z); }
IntVector3 mutil::operator /(IntVector3 const &first, int32_t const &scalar) { return IntVector3(first.x / scalar, first.y / scalar, first.z * scalar); }

IntVector3 mutil::operator-(IntVector3 const &vec) { return IntVector3(-vec.x, -vec.y, -vec.z); };

bool mutil::operator ==(IntVector3 const &first, IntVector3 const &second) { return first.x == second.x && first.y == second.y && first.z == second.z; }
bool mutil::operator !=(IntVector3 const &first, IntVector3 const &second) { return !operator==(first, second); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IntVector4
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

mutil::IntVector4::IntVector4() : x(0), y(0), z(0), w(0) { }
mutil::IntVector4::IntVector4(int32_t const scalar) : x(scalar), y(scalar), z(scalar), w(scalar) { }
mutil::IntVector4::IntVector4(int32_t const x, int32_t const y, int32_t const z, int32_t const w) : x(x), y(y), z(z), w(w) { }
mutil::IntVector4::IntVector4(IntVector2 const &first, IntVector2 const &second) : x(first.x), y(first.y), z(second.x), w(second.y) { }
mutil::IntVector4::IntVector4(IntVector3 const &vec3, int32_t w) : x(vec3.x), y(vec3.y), z(vec3.z), w(w) { };
mutil::IntVector4::IntVector4(Vector4 const &vec4) : x((int32_t)vec4.x), y((int32_t)vec4.y), z((int32_t)vec4.z), w((int32_t)vec4.w) { }
mutil::IntVector4::IntVector4(IntVector2 const &vec) : x(vec.x), y(vec.y), z(0.0f), w(0.0f) { }
mutil::IntVector4::IntVector4(IntVector3 const &vec) : x(vec.x), y(vec.y), z(vec.z), w(0.0f) { }

IntVector4 &mutil::IntVector4::operator+=(IntVector4 const &first)
{
	IntVector4 result = operator+(*this, first);
	memcpy(this, &result, 4 * sizeof(float));
	return *this;
}

IntVector4 &mutil::IntVector4::operator-=(IntVector4 const &first)
{
	IntVector4 result = operator-(*this, first);
	memcpy(this, &result, 4 * sizeof(float));
	return *this;
}

IntVector4 &mutil::IntVector4::operator*=(IntVector4 const &first)
{
	IntVector4 result = operator*(*this, first);
	memcpy(this, &result, 4 * sizeof(float));
	return *this;
}

IntVector4 &mutil::IntVector4::operator/=(IntVector4 const &first)
{
	IntVector4 result = operator/(*this, first);
	memcpy(this, &result, 4 * sizeof(float));
	return *this;
}

IntVector4 mutil::operator +(IntVector4 const &first, IntVector4 const &second) { return IntVector4(first.x + second.x, first.y + second.y, first.z + second.z, first.w + second.w); }
IntVector4 mutil::operator -(IntVector4 const &first, IntVector4 const &second) { return IntVector4(first.x - second.x, first.y - second.y, first.z - second.z, first.w - second.w); }
IntVector4 mutil::operator *(IntVector4 const &first, IntVector4 const &second) { return IntVector4(first.x * second.x, first.y * second.y, first.z * second.z, first.w * second.w); }
IntVector4 mutil::operator *(IntVector4 const &first, int32_t const &scalar) { return IntVector4(first.x * scalar, first.y * scalar, first.z * scalar, first.w * scalar); }
IntVector4 mutil::operator *(int32_t const &scalar, IntVector4 const &vec) { return IntVector4(vec.x * scalar, vec.y * scalar, vec.z * scalar, vec.w * scalar); }
IntVector4 mutil::operator /(IntVector4 const &first, IntVector4 const &second) { return IntVector4(first.x / second.x, first.y / second.y, first.z / second.z, first.w / second.w); }
IntVector4 mutil::operator /(IntVector4 const &first, int32_t const &scalar) { return IntVector4(first.x / scalar, first.y / scalar, first.z * scalar, first.w / scalar); }

IntVector4 mutil::operator-(IntVector4 const &vec) { return IntVector4(-vec.x, -vec.y, -vec.z, -vec.w); };

bool mutil::operator ==(IntVector4 const &first, IntVector4 const &second) { return first.x == second.x && first.y == second.y && first.z == second.z && first.w == second.w; }
bool mutil::operator !=(IntVector4 const &first, IntVector4 const &second) { return !operator==(first, second); }