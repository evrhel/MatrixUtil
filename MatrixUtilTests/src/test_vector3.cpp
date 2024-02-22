#include <mutil/mutil.h>
#include <string>
#include "test.h"

using namespace mutil;

static void testVector3Basic()
{
	Vector3 v1(1, 2, 3);
    assertEquals(1.0f, v1.x);
    assertEquals(2.0f, v1.y);
    assertEquals(3.0f, v1.z);

    Vector3 v2;
    assertEquals(0.0f, v2.x);
    assertEquals(0.0f, v2.y);
    assertEquals(0.0f, v2.z);

    Vector3 v3(v1);
    assertEquals(1.0f, v3.x);
    assertEquals(2.0f, v3.y);
    assertEquals(3.0f, v3.z);

    Vector3 v4(IntVector3(1, 2, 3));
    assertEquals(1.0f, v4.x);
    assertEquals(2.0f, v4.y);
    assertEquals(3.0f, v4.z);

    Vector3 v5(Vector2(1, 2));
    assertEquals(1.0f, v5.x);
    assertEquals(2.0f, v5.y);
    assertEquals(0.0f, v5.z);

    Vector3 v6(Vector4(1, 2, 3, 4));
    assertEquals(1.0f, v6.x);
    assertEquals(2.0f, v6.y);
    assertEquals(3.0f, v6.z);

    Vector3 v7(Vector2(1, 2), 3);
    assertEquals(1.0f, v7.x);
    assertEquals(2.0f, v7.y);
    assertEquals(3.0f, v7.z);

    Vector3 v8(1, Vector2(2, 3));
    assertEquals(1.0f, v8.x);
    assertEquals(2.0f, v8.y);
    assertEquals(3.0f, v8.z);
}

static void testVector3Dot()
{
    Vector3 v1(1, 2, 3);
    Vector3 v2(4, 5, 6);
    float d = dot(v1, v2);
    assertEquals(32.0f, d);

    v1 = Vector3(1, 2, 3);
    v2 = Vector3(1, 2, 3);
    d = dot(v1, v2);
    assertEquals(14.0f, d);
}

static void testVector3Cross()
{
    Vector3 v1(1, 2, 3);
    Vector3 v2(4, 5, 6);
    Vector3 v = cross(v1, v2);
    assertEquals(-3.0f, v.x);
    assertEquals(6.0f, v.y);
    assertEquals(-3.0f, v.z);

    v1 = Vector3(1, 2, 3);
    v2 = Vector3(1, 2, 3);
    v = cross(v1, v2);
    assertEquals(0.0f, v.x);
    assertEquals(0.0f, v.y);
    assertEquals(0.0f, v.z);

}

static void testVector3Length()
{
    Vector3 v(1, 2, 3);
    float l = length(v);
    assertEquals(3.74166f, l);

    v = Vector3(0, 0, 0);
    l = length(v);
    assertEquals(l, 0.0f);
}

static void testVector3LengthSq()
{
    Vector3 v(1, 2, 3);
    float l = lengthSq(v);
    assertEquals(14.0f, l);

    v = Vector3(0, 0, 0);
    l = lengthSq(v);
    assertEquals(0.0f, l);
}

static void testVector3Distance()
{
    Vector3 v1(1, 2, 3);
    Vector3 v2(4, 6, 8);
    float d = distance(v1, v2);
    assertEquals(7.07107f, d);

    v1 = Vector3(1, 2, 3);
    v2 = Vector3(1, 2, 3);
    d = distance(v1, v2);
    assertEquals(0.0f, d);
}

static void testVector3Normalize()
{
    Vector3 v(1, 2, 3);
    v = normalize(v);
    assertEquals(0.267261f, v.x);
    assertEquals(0.534522f, v.y);
    assertEquals(0.801784f, v.z);
}

static void testVector3Reflect()
{
	// TODO: Implement testVector3Reflect
}

Test getVector3Test(const std::string &test)
{
	if (test == "Vector3Basic")
		return &testVector3Basic;
	else if (test == "Vector3Dot")
		return &testVector3Dot;
    else if (test == "Vector3Cross")
        return &testVector3Cross;
	else if (test == "Vector3Length")
		return &testVector3Length;
	else if (test == "Vector3LengthSq")
		return &testVector3LengthSq;
	else if (test == "Vector3Distance")
		return &testVector3Distance;
	else if (test == "Vector3Normalize")
		return &testVector3Normalize;
	else if (test == "Vector3Reflect")
		return &testVector3Reflect;

	return nullptr;
}

