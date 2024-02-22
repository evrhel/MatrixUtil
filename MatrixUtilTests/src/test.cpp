#include "test.h"

static float _epsilon = 0.001f;

void setEpsilon(float epsilon) { _epsilon = epsilon; }

bool equals(bool a, bool b) { return a == b; }
bool equals(int a, int b) { return a == b; }
bool equals(float a, float b) { return fabs(a - b) <= _epsilon; }

bool equals(const Vector2 &a, const Vector2 &b)
{
	return equals(a.x, b.x) &&
		equals(a.y, b.y);
}

bool equals(const Vector3 &a, const Vector3 &b)
{
	return equals(a.x, b.x) &&
		equals(a.y, b.y) &&
		equals(a.z, b.z);
}

bool equals(const Vector4 &a, const Vector4 &b)
{
	return equals(a.x, b.x) &&
		equals(a.y, b.y) &&
		equals(a.z, b.z) &&
		equals(a.w, b.w);
}

bool equals(const IntVector2 &a, const IntVector2 &b)
{
	return equals(a.x, b.x) &&
		equals(a.y, b.y);
}

bool equals(const IntVector3 &a, const IntVector3 &b)
{
	return equals(a.x, b.x) &&
		equals(a.y, b.y) &&
		equals(a.z, b.z);
}

bool equals(const IntVector4 &a, const IntVector4 &b)
{
	return equals(a.x, b.x) &&
		equals(a.y, b.y) &&
		equals(a.z, b.z) &&
		equals(a.w, b.w);
}

bool equals(const Matrix2 &a, const Matrix2 &b)
{
	return equals(a.columns[0], b.columns[0]) &&
		equals(a.columns[1], b.columns[1]);
}

bool equals(const Matrix3 &a, const Matrix3 &b)
{
	return equals(a.columns[0], b.columns[0]) &&
		equals(a.columns[1], b.columns[1]) &&
		equals(a.columns[2], b.columns[2]);
}

bool equals(const Matrix4 &a, const Matrix4 &b)
{
	return equals(a.columns[0], b.columns[0]) &&
		equals(a.columns[1], b.columns[1]) &&
		equals(a.columns[2], b.columns[2]) &&
		equals(a.columns[3], b.columns[3]);
}

bool equals(const IntMatrix2 &a, const IntMatrix2 &b)
{
	return equals(a.columns[0], b.columns[0]) &&
		equals(a.columns[1], b.columns[1]);
}

bool equals(const IntMatrix3 &a, const IntMatrix3 &b)
{
	return equals(a.columns[0], b.columns[0]) &&
		equals(a.columns[1], b.columns[1]) &&
		equals(a.columns[2], b.columns[2]);
}

bool equals(const IntMatrix4 &a, const IntMatrix4 &b)
{
	return equals(a.columns[0], b.columns[0]) &&
		equals(a.columns[1], b.columns[1]) &&
		equals(a.columns[2], b.columns[2]) &&
		equals(a.columns[3], b.columns[3]);
}

bool equals(const Quaternion &a, const Quaternion &b)
{
	return equals(a.a, b.a) &&
		equals(a.i, b.i) &&
		equals(a.j, b.j) &&
		equals(a.k, b.k);
}

std::string tostring(int x) { return std::to_string(x); }
std::string tostring(float x) { return std::to_string(x); }

std::string tostring(const Vector2 &v)
{
	return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ")";
}

std::string tostring(const Vector3 &v)
{
	return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ", " + std::to_string(v.z) + ")";
}

std::string tostring(const Vector4 &v)
{
	return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ", " + std::to_string(v.z) + ", " + std::to_string(v.w) + ")";
}

std::string tostring(const IntVector2 &v)
{
	return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ")";
}

std::string tostring(const IntVector3 &v)
{
	return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ", " + std::to_string(v.z) + ")";
}

std::string tostring(const IntVector4 &v)
{
	return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ", " + std::to_string(v.z) + ", " + std::to_string(v.w) + ")";
}

std::string tostring(const Matrix2 &m)
{
	return "[" + tostring(m.columns[0]) + ", " + tostring(m.columns[1]) + "]";
}

std::string tostring(const Matrix3 &m)
{
	return "[" + tostring(m.columns[0]) + ", " + tostring(m.columns[1]) + ", " + tostring(m.columns[2]) + "]";

}

std::string tostring(const Matrix4 &m)
{
	return "[" + tostring(m.columns[0]) + ", " + tostring(m.columns[1]) + ", " + tostring(m.columns[2]) + ", " + tostring(m.columns[3]) + "]";
}

std::string tostring(const IntMatrix2 &m)
{
	return "[" + tostring(m.columns[0]) + ", " + tostring(m.columns[1]) + "]";
}

std::string tostring(const IntMatrix3 &m)
{
	return "[" + tostring(m.columns[0]) + ", " + tostring(m.columns[1]) + ", " + tostring(m.columns[2]) + "]";
}

std::string tostring(const IntMatrix4 &m)
{
	return "[" + tostring(m.columns[0]) + ", " + tostring(m.columns[1]) + ", " + tostring(m.columns[2]) + ", " + tostring(m.columns[3]) + "]";
}

std::string tostring(const Quaternion &q)
{
	return "(" + std::to_string(q.a) + ", " + std::to_string(q.i) + ", " + std::to_string(q.j) + ", " + std::to_string(q.k) + ")";
}

void __die(const char *file, int line)
{
	printf("Assertion failed: %s:%d\n", file, line);
	exit(1);
}


void __die_with(const char *file, int line, const std::string &expected, const std::string &actual)
{
	printf("Assertion failed: %s:%d\n", file, line);
	printf("Expected: %s\n", expected.c_str());
	printf("Actual: %s\n", actual.c_str());
	exit(1);
}
