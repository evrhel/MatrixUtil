#include <mutil/mutil.h>
#include <string>
#include "test.h"

using namespace mutil;

static void testVector2Basic()
{
	Vector2 v1(1, 2);
	assertEquals(1.0f, v1.x);
	assertEquals(2.0f, v1.y);

	Vector2 v2;
	assertEquals(0.0f, v2.x);
	assertEquals(0.0f, v2.y);

	Vector2 v3(v1);
	assertEquals(1.0f, v3.x);
	assertEquals(2.0f, v3.y);

	Vector2 v4(IntVector2(1, 2));
	assertEquals(1.0f, v4.x);
	assertEquals(2.0f, v4.y);

	Vector2 v5(Vector3(1, 2, 3));
	assertEquals(1.0f, v5.x);
	assertEquals(2.0f, v5.y);

	Vector2 v6(Vector4(1, 2, 3, 4));
	assertEquals(1.0f, v6.x);
	assertEquals(2.0f, v6.y);
}

static void testVector2Dot()
{
	Vector2 v1(1, 2);
	Vector2 v2(3, 4);
	float d = dot(v1, v2);
	assertEquals(11.0f, d);

	v1 = Vector2(1, 2);
	v2 = Vector2(1, 2);
	d = dot(v1, v2);
	assertEquals(5.0f, d);
}

static void testVector2Length()
{
	Vector2 v(3, 4);
	float l = length(v);
	assertEquals(5.0f, l);

	v = Vector2(0, 0);
	l = length(v);
	assertEquals(0.0f, l);
}

static void testVector2LengthSq()
{
	Vector2 v(3, 4);
	float l = lengthSq(v);
	assertEquals(25.0f, l);

	v = Vector2(0, 0);
	l = lengthSq(v);
	assertEquals(0.0f, l);
}

static void testVector2Distance()
{
	Vector2 v1(1, 2);
	Vector2 v2(4, 6);
	float d = distance(v1, v2);
	assertEquals(5.0f, d);

	v1 = Vector2(1, 2);
	v2 = Vector2(1, 2);
	d = distance(v1, v2);
	assertEquals(0.0f, d);
}

static void testVector2Normalize()
{
	Vector2 v(3, 4);
	v = normalize(v);
	setEpsilon(0.01f);
	assertEquals(0.6f, v.x);
	assertEquals(0.8f, v.y);
}

static void testVector2Reflect()
{
	// TODO: Implement testVector2Reflect
}

Test getVector2Test(const std::string &test)
{
	if (test == "Vector2Basic")
		return &testVector2Basic;
	else if (test == "Vector2Dot")
		return &testVector2Dot;
	else if (test == "Vector2Length")
		return &testVector2Length;
	else if (test == "Vector2LengthSq")
		return &testVector2LengthSq;
	else if (test == "Vector2Distance")
		return &testVector2Distance;
	else if (test == "Vector2Normalize")
		return &testVector2Normalize;
	else if (test == "Vector2Reflect")
		return &testVector2Reflect;

	return nullptr;
}

