#include <mutil/mutil.h>
#include <string>
#include "test.h"

static void testQuaternionBasic()
{
	Quaternion q;
    assertEquals(1.0f, q.a);
    assertEquals(0.0f, q.i);
    assertEquals(0.0f, q.j);
    assertEquals(0.0f, q.k);

    q = Quaternion(1, 2, 3, 4);
    assertEquals(1.0f, q.a);
    assertEquals(2.0f, q.i);
    assertEquals(3.0f, q.j);
    assertEquals(4.0f, q.k);

    q = Quaternion(1, Vector3(2, 3, 4));
    assertEquals(1.0f, q.a);
    assertEquals(2.0f, q.i);
    assertEquals(3.0f, q.j);
    assertEquals(4.0f, q.k);
}

static void testQuaternionAdd()
{
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(5, 6, 7, 8);

    Quaternion q = q1 + q2;
    assertEquals(6.0f, q.a);
    assertEquals(8.0f, q.i);
    assertEquals(10.0f, q.j);
    assertEquals(12.0f, q.k);

    q1 += q2;
    assertEquals(6.0f, q1.a);
    assertEquals(8.0f, q1.i);
    assertEquals(10.0f, q1.j);
    assertEquals(12.0f, q1.k);
}

static void testQuaternionSub()
{
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(4, 3, 2, 1);

    Quaternion q = q1 - q2;
    assertEquals(-3.0f, q.a);
    assertEquals(-1.0f, q.i);
    assertEquals(1.0f, q.j);
    assertEquals(3.0f, q.k);

    q1 -= q2;
    assertEquals(-3.0f, q1.a);
    assertEquals(-1.0f, q1.i);
    assertEquals(1.0f, q1.j);
    assertEquals(3.0f, q1.k);
}

static void testQuaternionMul()
{
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(5, 6, 7, 8);

    Quaternion q = q1 * q2;
    assertEquals(-60.0f, q.a);
    assertEquals(12.0f, q.i);
    assertEquals(30.0f, q.j);
    assertEquals(24.0f, q.k);

    q1 *= q2;
    assertEquals(-60.0f, q1.a);
    assertEquals(12.0f, q1.i);
    assertEquals(30.0f, q1.j);
    assertEquals(24.0f, q1.k);
}

static void testQuaternionMulScalar()
{
    Quaternion q1(1, 2, 3, 4);
    Quaternion q = q1 * 2;

    assertEquals(2.0f, q.a);
    assertEquals(4.0f, q.i);
    assertEquals(6.0f, q.j);
    assertEquals(8.0f, q.k);

    q1 *= 2;
    assertEquals(2.0f, q1.a);
    assertEquals(4.0f, q1.i);
    assertEquals(6.0f, q1.j);
    assertEquals(8.0f, q1.k);
}

static void testQuaternionDivScalar()
{
    Quaternion q1(2, 4, 6, 8);
    Quaternion q = q1 / 2;

    assertEquals(1.0f, q.a);
    assertEquals(2.0f, q.i);
    assertEquals(3.0f, q.j);
    assertEquals(4.0f, q.k);

    q1 /= 2;
    assertEquals(1.0f, q1.a);
    assertEquals(2.0f, q1.i);
    assertEquals(3.0f, q1.j);
    assertEquals(4.0f, q1.k);
}

static void testQuaternionLength()
{
    Quaternion q(1, 2, 3, 4);
    float l = length(q);
    assertEquals(5.47723f, l);
}

static void testQuaternionLengthSq()
{
    Quaternion q(1, 2, 3, 4);
    float l = lengthSq(q);
    assertEquals(30.0f, l);
}

static void testQuaternionNormalize()
{
    Quaternion q(1, 2, 3, 4);
    Quaternion n = normalize(q);
    assertEquals(0.18257f, n.a);
    assertEquals(0.36515f, n.i);
    assertEquals(0.54772f, n.j);
    assertEquals(0.73030f, n.k);
}

static void testQuaternionConjugate()
{
    Quaternion q(1, 2, 3, 4);
    Quaternion c = conjugate(q);
    assertEquals(1.0f, c.a);
    assertEquals(-2.0f, c.i);
    assertEquals(-3.0f, c.j);
    assertEquals(-4.0f, c.k);

    c = conjugate(c);
    assertEquals(1.0f, c.a);
    assertEquals(2.0f, c.i);
    assertEquals(3.0f, c.j);
    assertEquals(4.0f, c.k);
}

static void testQuaternionRotateAxis()
{
    Quaternion q = rotateaxis(Vector3(1, 0, 0), radians(90.0f));
    assertEquals(0.70711f, q.a);
    assertEquals(0.70711f, q.i);
    assertEquals(0.0f, q.j);
    assertEquals(0.0f, q.k);

    q = rotateaxis(Vector3(0, 1, 0), radians(90.0f));
    assertEquals(0.70711f, q.a);
    assertEquals(0.0f, q.i);
    assertEquals(0.70711f, q.j);
    assertEquals(0.0f, q.k);

    q = rotateaxis(Vector3(0, 0, 1), radians(90.0f)); 
    assertEquals(0.70711f, q.a);
    assertEquals(0.0f, q.i);
    assertEquals(0.0f, q.j);
    assertEquals(0.70711f, q.k);
}

Test getQuaternionTest(const std::string &test)
{
    if (test == "QuaternionBasic") return testQuaternionBasic;
    if (test == "QuaternionAdd") return testQuaternionAdd;
    if (test == "QuaternionSub") return testQuaternionSub;
    if (test == "QuaternionMul") return testQuaternionMul;
    if (test == "QuaternionMulScalar") return testQuaternionMulScalar;
    if (test == "QuaternionDivScalar") return testQuaternionDivScalar;
    if (test == "QuaternionLength") return testQuaternionLength;
    if (test == "QuaternionLengthSq") return testQuaternionLengthSq;
    if (test == "QuaternionNormalize") return testQuaternionNormalize;
    if (test == "QuaternionConjugate") return testQuaternionConjugate;
    if (test == "QuaternionRotateAxis") return testQuaternionRotateAxis;

	return nullptr;
}
