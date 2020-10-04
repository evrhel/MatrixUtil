#include "fvec_math.h"

#include <cmath>
#include <smmintrin.h>
#include "f_math.h"

using namespace mutil;

static inline float inverseSqrt(float num)
{
	return 1.0f / sqrtf(num);
}

// Vector2 operations

float mutil::dot(Vector2 const &first, Vector2 const &second)
{
	return (first.x * second.x) + (first.y * second.y);
}

float mutil::cross(Vector2 const &first, Vector2 const &second)
{
	return cross(Vector3(first, 0.0f), Vector3(second, 0.0f)).z;
}

float mutil::length(Vector2 const &vec)
{
	return sqrtf(vec.x * vec.x + vec.y * vec.y);
}

float mutil::distance(Vector2 const &first, Vector2 const &second)
{
	return length(second - first);
}

Vector2 mutil::normalize(Vector2 const &vec)
{
	return vec * inverseSqrt(dot(vec, vec));
}

Vector2 mutil::reflect(Vector2 const &vec, Vector2 const &normal)
{
	return 2.0f * dot(normal, vec) * normal - vec;
}

Vector2 mutil::radians(Vector2 const &vec)
{
	return Vector2(radians(vec.x), radians(vec.y));
}

Vector2 mutil::degrees(Vector2 const &vec)
{
	return Vector2(degrees(vec.x), degrees(vec.y));
}

Vector2 mutil::abs(Vector2 const &vec)
{
	return Vector2(fabsf(vec.x), fabsf(vec.y));
}

// Vector3 operations

float mutil::dot(Vector3 const &first, Vector3 const &second)
{
	return (first.x * second.x) + (first.y * second.y) + (first.z * second.z);
}

Vector3 mutil::cross(Vector3 const &first, Vector3 const &second)
{
	return Vector3(
		(first.y * second.z - second.y * first.z),
		(first.z * second.x - second.z * first.x),
		(first.x * second.y - second.x * first.y)
	);
}

float mutil::length(Vector3 const &vec)
{
	return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

float mutil::distance(Vector3 const &first, Vector3 const &second)
{
	return length(second - first);
}

Vector3 mutil::normalize(Vector3 const &vec)
{
	return vec * inverseSqrt(dot(vec, vec));
}

Vector3 mutil::reflect(Vector3 const &vec, Vector3 const &normal)
{
	return 2.0f * dot(normal, vec) * normal - vec;
}

Vector3 mutil::refract(Vector3 const &vec, Vector3 const &normal, float ratio)
{
	return (ratio * (cross(normal, cross(-normal, vec)))) - (normal * sqrtf(1 - (ratio * ratio) * dot(cross(normal, vec), cross(normal, vec))));
}

Vector3 mutil::radians(Vector3 const &vec)
{
	return Vector3(radians(vec.x), radians(vec.y), radians(vec.z));
}

Vector3 mutil::degrees(Vector3 const &vec)
{
	return Vector3(degrees(vec.x), degrees(vec.y), degrees(vec.z));
}

Vector3 MUTIL_EXPORT mutil::abs(Vector3 const &vec)
{
	return Vector3(fabsf(vec.x), fabsf(vec.y), fabs(vec.z));
}

// Vector4 operations

float mutil::dot(Vector4 const &first, Vector4 const &second)
{
#ifdef USE_SIMD
	//__m128 _mm_load_ps1 (float const* mem_addr)
	//__m128 _mm_dp_ps (__m128 a, __m128 b, const int imm8)
	static const int MASK = 0xf1;

	__m128 reg1 = _mm_loadu_ps((float *)&first);
	__m128 reg2 = _mm_loadu_ps((float *)&second);
	__m128 resultReg = _mm_dp_ps(reg1, reg2, MASK);
	return _mm_cvtss_f32(resultReg);
#else
	return (first.x * second.x) + (first.y * second.y) + (first.z * second.z) + (first.w * second.w);
#endif
}

float mutil::length(Vector4 const &vec)
{
	return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w);
}

float mutil::distance(Vector4 const &first, Vector4 const &second)
{
	return length(second - first);
}

Vector4 mutil::normalize(Vector4 const &vec)
{
	return vec * inverseSqrt(dot(vec, vec));
}

Vector4 mutil::reflect(Vector4 const &vec, Vector4 const &normal)
{
	return 2.0f * dot(normal, vec) * normal - vec;
}

Vector4 mutil::radians(Vector4 const &vec)
{
	return Vector4(radians(vec.x), radians(vec.y), radians(vec.z), degrees(vec.w));
}

Vector4 mutil::degrees(Vector4 const &vec)
{
	return Vector4(degrees(vec.x), degrees(vec.y), degrees(vec.z), degrees(vec.w));
}

Vector4 MUTIL_EXPORT mutil::abs(Vector4 const &vec)
{
	return Vector4(fabsf(vec.x), fabsf(vec.y), fabs(vec.z), fabs(vec.w));
}
