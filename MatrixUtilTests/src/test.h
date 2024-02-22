#pragma once

#include <mutil/mutil.h>

#include <cstdlib>
#include <string>

using namespace mutil;

void setEpsilon(float epsilon);

bool equals(bool a, bool b);
bool equals(int a, int b);
bool equals(float a, float b);
bool equals(const Vector2 &a, const Vector2 &b);
bool equals(const Vector3 &a, const Vector3 &b);
bool equals(const Vector4 &a, const Vector4 &b);
bool equals(const IntVector2 &a, const IntVector2 &b);
bool equals(const IntVector3 &a, const IntVector3 &b);
bool equals(const IntVector4 &a, const IntVector4 &b);
bool equals(const Matrix2 &a, const Matrix2 &b);
bool equals(const Matrix3 &a, const Matrix3 &b);
bool equals(const Matrix4 &a, const Matrix4 &b);
bool equals(const IntMatrix2 &a, const IntMatrix2 &b);
bool equals(const IntMatrix3 &a, const IntMatrix3 &b);
bool equals(const IntMatrix4 &a, const IntMatrix4 &b);
bool equals(const Quaternion &a, const Quaternion &b);

std::string tostring(bool x);
std::string tostring(int x);
std::string tostring(float x);
std::string tostring(const Vector2 &v);
std::string tostring(const Vector3 &v);
std::string tostring(const Vector4 &v);
std::string tostring(const IntVector2 &v);
std::string tostring(const IntVector3 &v);
std::string tostring(const IntVector4 &v);
std::string tostring(const Matrix2 &m);
std::string tostring(const Matrix3 &m);
std::string tostring(const Matrix4 &m);
std::string tostring(const IntMatrix2 &m);
std::string tostring(const IntMatrix3 &m);
std::string tostring(const IntMatrix4 &m);
std::string tostring(const Quaternion &q);

void __die(const char *file, int line);
void __die_with(const char *file, int line, const std::string &expected, const std::string &actual);

#define die() __die(__FILE__, __LINE__)

#define assertEquals(expected, actual) \
	{ \
		if (!equals((expected), (actual))) \
			__die_with(__FILE__, __LINE__, tostring((expected)), tostring((actual))); \
	}

#define assertNotEquals(expected, actual) \
	{ \
		if (equals((expected), (actua)l)) \
			__die_with(__FILE__, __LINE__, tostring((expected)), tostring((actual))); \
	}

#define assertTrue(x) assertEquals(true, (x))
#define assertFalse(x) assertEquals(false, (x))

typedef void(*Test)();
