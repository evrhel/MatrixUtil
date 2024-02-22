#include <mutil/mutil.h>
#include <string>
#include "test.h"

using namespace mutil;

static void testVector4Basic()
{
	Vector4 v1(1, 2, 3, 4);
    assertEquals(1.0f, v1.x);
    assertEquals(2.0f, v1.y);
    assertEquals(3.0f, v1.z);
    assertEquals(4.0f, v1.w);

    Vector4 v2;
    assertEquals(0.0f, v2.x);
    assertEquals(0.0f, v2.y);
    assertEquals(0.0f, v2.z);
    assertEquals(0.0f, v2.w);

    Vector4 v3(v1);
    assertEquals(1.0f, v3.x);
    assertEquals(2.0f, v3.y);
    assertEquals(3.0f, v3.z);
    assertEquals(4.0f, v3.w);

    Vector4 v4(IntVector4(1, 2, 3, 4));
    assertEquals(1.0f, v4.x);
    assertEquals(2.0f, v4.y);
    assertEquals(3.0f, v4.z);
    assertEquals(4.0f, v4.w);

    Vector4 v5(Vector2(1, 2), 3, 4);
    assertEquals(1.0f, v5.x);
    assertEquals(2.0f, v5.y);
    assertEquals(3.0f, v5.z);
    assertEquals(4.0f, v5.w);

    Vector4 v6(Vector3(1, 2, 3), 4);
    assertEquals(1.0f, v6.x);
    assertEquals(2.0f, v6.y);
    assertEquals(3.0f, v6.z);
    assertEquals(4.0f, v6.w);

    Vector4 v7(Vector2(1, 2), Vector2(3, 4));
    assertEquals(1.0f, v7.x);
    assertEquals(2.0f, v7.y);
    assertEquals(3.0f, v7.z);
    assertEquals(4.0f, v7.w);

    Vector4 v8(1, Vector3(2, 3, 4));
    assertEquals(1.0f, v8.x);
    assertEquals(2.0f, v8.y);
    assertEquals(3.0f, v8.z);
    assertEquals(4.0f, v8.w);

    Vector4 v9(1, 2, Vector2(3, 4));
    assertEquals(1.0f, v9.x);
    assertEquals(2.0f, v9.y);
    assertEquals(3.0f, v9.z);
    assertEquals(4.0f, v9.w);

    Vector4 v10(Vector2(1, 2));
    assertEquals(1.0f, v10.x);
    assertEquals(2.0f, v10.y);
    assertEquals(0.0f, v10.z);
    assertEquals(0.0f, v10.w);

    Vector4 v11(Vector3(1, 2, 3));
    assertEquals(1.0f, v11.x);
    assertEquals(2.0f, v11.y);
    assertEquals(3.0f, v11.z);
    assertEquals(0.0f, v11.w);
}

static void testVector4Dot()
{
    Vector4 v1(1, 2, 3, 4);
    Vector4 v2(5, 6, 7, 8);
    assertEquals(70.0f, dot(v1, v2));

    Vector4 v3(1, 2, 3, 4);
    Vector4 v4(1, 2, 3, 4);
    assertEquals(30.0f, dot(v3, v4));
}

static void testVector4Length()
{
    Vector4 v1(1, 2, 3, 4);
    float l = length(v1);
    assertEquals(5.47723f, l);

    Vector4 v2;
    l = length(v2);
    assertEquals(0.0f, l);
}

static void testVector4LengthSq()
{
    Vector4 v1(1, 2, 3, 4);
    float l = lengthSq(v1);
    assertEquals(30.0f, l);

    Vector4 v2;
    l = lengthSq(v2);
    assertEquals(0.0f, l);
}

static void testVector4Distance()
{
    Vector4 v1(1, 2, 3, 4);
    Vector4 v2(5, 6, 7, 8);
    float d = distance(v1, v2);
    assertEquals(8.0f, d);

    Vector4 v3(1, 2, 3, 4);
    Vector4 v4(1, 2, 3, 4);
    d = distance(v3, v4);
    assertEquals(0.0f, d);
}

static void testVector4Normalize()
{
    Vector4 v1(1, 2, 3, 4);
    Vector4 n = normalize(v1);
    assertEquals(0.18257f, n.x);
    assertEquals(0.36515f, n.y);
    assertEquals(0.54772f, n.z);
    assertEquals(0.73030f, n.w);
}

static void testVector4Reflect()
{
	// TODO: Implement testVector3Reflect
}

Test getVector4Test(const std::string &test)
{
	if (test == "Vector4Basic") return &testVector4Basic;
	if (test == "Vector4Dot") return &testVector4Dot;
	if (test == "Vector4Length") return &testVector4Length;
	if (test == "Vector4LengthSq") return &testVector4LengthSq;
	if (test == "Vector4Distance") return &testVector4Distance;
	if (test == "Vector4Normalize") return &testVector4Normalize;
	if (test == "Vector4Reflect") return &testVector4Reflect;

	return nullptr;
}

