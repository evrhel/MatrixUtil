#include <mutil/mutil.h>
#include <string>
#include "test.h"

using namespace mutil;

static void testMatrix2Basic()
{
    Matrix2 m;
    assertEquals(m._11, 1.0f);
    assertEquals(m._12, 0.0f);
    assertEquals(m._21, 0.0f);
    assertEquals(m._22, 1.0f);

    m = Matrix2(2.0f);
    assertEquals(m._11, 2.0f);
    assertEquals(m._12, 0.0f);
    assertEquals(m._21, 0.0f);
    assertEquals(m._22, 2.0f);

    m = Matrix2(Vector2(1.0f, 2.0f), Vector2(3.0f, 4.0f));
    assertEquals(m._11, 1.0f);
    assertEquals(m._12, 3.0f);
    assertEquals(m._21, 2.0f);
    assertEquals(m._22, 4.0f);

    m = Matrix2(1.0f, 2.0f, 3.0f, 4.0f);
    assertEquals(m._11, 1.0f);
    assertEquals(m._12, 2.0f);
    assertEquals(m._21, 3.0f);
    assertEquals(m._22, 4.0f);

    m = Matrix2(IntMatrix2(1, 2, 3, 4));
    assertEquals(m._11, 1.0f);
    assertEquals(m._12, 2.0f);
    assertEquals(m._21, 3.0f);
    assertEquals(m._22, 4.0f);

    m = Matrix2(Matrix3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f));
    assertEquals(m._11, 1.0f);
    assertEquals(m._12, 2.0f);
    assertEquals(m._21, 4.0f);
    assertEquals(m._22, 5.0f);

    m = Matrix2(Matrix4(1.0f, 2.0f, 3.0f, 4.0f,
        5.0f, 6.0f, 7.0f, 8.0f,
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f));
    assertEquals(m._11, 1.0f);
    assertEquals(m._12, 2.0f);
    assertEquals(m._21, 5.0f);
    assertEquals(m._22, 6.0f);
}

static void testMatrix2Add()
{
    Matrix2 m1(1.0f, 2.0f, 3.0f, 4.0f);
    Matrix2 m2(5.0f, 6.0f, 7.0f, 8.0f);
    Matrix2 m = m1 + m2;
    assertEquals(m._11, 6.0f);
    assertEquals(m._12, 8.0f);
    assertEquals(m._21, 10.0f);
    assertEquals(m._22, 12.0f);
}

static void testMatrix2Sub()
{
    Matrix2 m1(1.0f, 2.0f, 3.0f, 4.0f);
    Matrix2 m2(8.0f, 7.0f, 6.0f, 5.0f);
    Matrix2 m = m1 - m2;
    assertEquals(m._11, -7.0f);
    assertEquals(m._12, -5.0f);
    assertEquals(m._21, -3.0f);
    assertEquals(m._22, -1.0f);
}

static void testMatrix2MulScalar()
{
    Matrix2 m(1.0f, 2.0f, 3.0f, 4.0f);
    m = m * 2.0f;
    assertEquals(m._11, 2.0f);
    assertEquals(m._12, 4.0f);
    assertEquals(m._21, 6.0f);
    assertEquals(m._22, 8.0f);
}

static void testMatrix2MulVector()
{
    Matrix2 m(1.0f, 2.0f, 3.0f, 4.0f);
    Vector2 v(5.0f, 6.0f);
    v = m * v;
    assertEquals(v.x, 17.0f);
    assertEquals(v.y, 39.0f);
}

static void testMatrix2MulMatrix()
{
    Matrix2 m1(1.0f, 2.0f, 3.0f, 4.0f);
    Matrix2 m2(5.0f, 6.0f, 7.0f, 8.0f);
    Matrix2 m = m1 * m2;
    assertEquals(m._11, 19.0f);
    assertEquals(m._12, 22.0f);
    assertEquals(m._21, 43.0f);
    assertEquals(m._22, 50.0f);
}

static void testMatrix2Determinant()
{
    Matrix2 m(1.0f, 2.0f, 3.0f, 4.0f);
    float det = determinant(m);
    assertEquals(det, -2.0f);

    m = Matrix2();
    det = determinant(m);
    assertEquals(det, 1.0f);
}

static void testMatrix2Transpose()
{
    Matrix2 m(1.0f, 2.0f, 3.0f, 4.0f);
    Matrix2 t = transpose(m);
    assertEquals(t._11, 1.0f);
    assertEquals(t._12, 3.0f);
    assertEquals(t._21, 2.0f);
    assertEquals(t._22, 4.0f);

    m = Matrix2();
    t = transpose(m);
    assertEquals(t._11, 1.0f);
    assertEquals(t._12, 0.0f);
    assertEquals(t._21, 0.0f);
    assertEquals(t._22, 1.0f);
}

static void testMatrix2Cofactor()
{
    Matrix2 m(1.0f, 2.0f, 3.0f, 4.0f);
    Matrix2 c = cofactor(m);
    assertEquals(c._11, 4.0f);
    assertEquals(c._12, -3.0f);
    assertEquals(c._21, -2.0f);
    assertEquals(c._22, 1.0f);

    m = Matrix2();
    c = cofactor(m);
    assertEquals(c._11, 1.0f);
    assertEquals(c._12, 0.0f);
    assertEquals(c._21, 0.0f);
    assertEquals(c._22, 1.0f);
}

static void testMatrix2Adjugate()
{
    Matrix2 m(1.0f, 2.0f, 3.0f, 4.0f);
    Matrix2 a = adjugate(m);
    assertEquals(a._11, 4.0f);
    assertEquals(a._12, -2.0f);
    assertEquals(a._21, -3.0f);
    assertEquals(a._22, 1.0f);

    m = Matrix2();
    a = adjugate(m);
    assertEquals(a._11, 1.0f);
    assertEquals(a._12, 0.0f);
    assertEquals(a._21, 0.0f);
    assertEquals(a._22, 1.0f);
}

static void testMatrix2Inverse()
{
    Matrix2 m(1.0f, 2.0f, 3.0f, 4.0f);
    Matrix2 i = inverse(m);
    assertEquals(i._11, -2.0f);
    assertEquals(i._12, 1.0f);
    assertEquals(i._21, 1.5f);
    assertEquals(i._22, -0.5f);

    m = Matrix2();
    i = inverse(m);
    assertEquals(i._11, 1.0f);
    assertEquals(i._12, 0.0f);
    assertEquals(i._21, 0.0f);
    assertEquals(i._22, 1.0f);
}

static void testMatrix2Clamp()
{
    Matrix2 m(1.0f, 2.0f, 3.0f, 4.0f);
    m = clamp(m, 2.0f, 3.0f);
    assertEquals(m._11, 2.0f);
    assertEquals(m._12, 2.0f);
    assertEquals(m._21, 3.0f);
    assertEquals(m._22, 3.0f);

    Matrix2 min(1.0f, 1.0f, 1.0f, 1.0f);
    Matrix2 max(2.0f, 2.0f, 2.0f, 2.0f);
    m = clamp(m, min, max);
    assertEquals(m._11, 2.0f);
    assertEquals(m._12, 2.0f);
    assertEquals(m._21, 2.0f);
    assertEquals(m._22, 2.0f);
}

Test getMatrix2Test(const std::string &test)
{
    if (test == "Matrix2Basic") return testMatrix2Basic;
    if (test == "Matrix2Add") return testMatrix2Add;
    if (test == "Matrix2Sub") return testMatrix2Sub;
    if (test == "Matrix2MulScalar") return testMatrix2MulScalar;
    if (test == "Matrix2MulVector") return testMatrix2MulVector;
    if (test == "Matrix2MulMatrix") return testMatrix2MulMatrix;
    if (test == "Matrix2Determinant") return testMatrix2Determinant;
    if (test == "Matrix2Transpose") return testMatrix2Transpose;
    if (test == "Matrix2Cofactor") return testMatrix2Cofactor;
    if (test == "Matrix2Adjugate") return testMatrix2Adjugate;
    if (test == "Matrix2Inverse") return testMatrix2Inverse;
    if (test == "Matrix2Clamp") return testMatrix2Clamp;

    return nullptr;
}