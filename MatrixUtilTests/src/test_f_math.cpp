#include <mutil/mutil.h>
#include <string>
#include "test.h"

using namespace mutil;

static void testFMathConstants()
{
    assertEquals(3.14159265358979323846f, MUTIL_PI);
    assertEquals(1.0f / 3.14159265358979323846f, MUTIL_1_PI);
    assertEquals(2.0f / 3.14159265358979323846f, MUTIL_2_PI);
    assertEquals(4.0f / 3.14159265358979323846f, MUTIL_4_PI);
    assertEquals(1.57079632679489661923f, MUTIL_PI2);
    assertEquals(0.78539816339744830962f, MUTIL_PI4);
    assertEquals(2.0f * 3.14159265358979323846f, MUTIL_2PI);
    assertEquals(3.0f * 3.14159265358979323846f / 2.0f, MUTIL_3PI2);

    assertEquals(3.14159265358979323846f / 180.0f, MUTIL_D2R);
    assertEquals(180.0f / 3.14159265358979323846f, MUTIL_R2D);

    assertEquals(1.41421356237309504880f, MUTIL_SQRT2);

    assertEquals(2.71828182845904523536f, MUTIL_E);
}

static void testFMathRadians()
{
    float r = radians(180.0f);
    assertEquals(MUTIL_PI, r);

    r = radians(90.0f);
    assertEquals(MUTIL_PI2, r);

    r = radians(45.0f);
    assertEquals(MUTIL_PI4, r);
}

static void testFMathDegrees()
{
    float d = degrees(MUTIL_PI);
    assertEquals(180.0f, d);

    d = degrees(MUTIL_PI2);
    assertEquals(90.0f, d);

    d = degrees(MUTIL_PI4);
    assertEquals(45.0f, d);
}

static void testFMathSgn()
{
    int s = sgn(0);
    assertEquals(0, s);

    s = sgn(2);
    assertEquals(1, s);

    s = sgn(-2);
    assertEquals(-1, s);
}

static void testFMathMin()
{
    float r = min(1.0f, 2.0f);
    assertEquals(1.0f, r);

    r = min(2.0f, 1.0f);
    assertEquals(1.0f, r);

    r = min(1.0f, 1.0f);
    assertEquals(1.0f, r);
}

static void testFMathMax()
{
    float r = max(1.0f, 2.0f);
    assertEquals(2.0f, r);

    r = max(2.0f, 1.0f);
    assertEquals(2.0f, r);

    r = max(1.0f, 1.0f);
    assertEquals(1.0f, r);
}

static void testFMathSqrt()
{
    float r = mutil::sqrt(4.0f);
    assertEquals(2.0f, r);

    r = mutil::sqrt(9.0f);
    assertEquals(3.0f, r);

    r = mutil::sqrt(2.0f);
    assertEquals(MUTIL_SQRT2, r);
}

static void testFMathInverseSqrt()
{
    float r = 1.0f / mutil::sqrt(4.0f);
    assertEquals(0.5f, r);

    r = 1.0f / mutil::sqrt(9.0f);
    assertEquals(1.0f / 3.0f, r);

    r = 1.0f / mutil::sqrt(2.0f);
    assertEquals(1.0f / MUTIL_SQRT2, r);
}

static void testFMathFastInverseSqrt()
{
    float r = mutil::fastInverseSqrt(4.0f);
    assertEquals(0.5f, r);

    r = mutil::fastInverseSqrt(9.0f);
    assertEquals(1.0f / 3.0f, r);

    r = mutil::fastInverseSqrt(2.0f);
    assertEquals(1.0f / MUTIL_SQRT2, r);
}

static void testFMathAbs()
{
    float r = mutil::abs(1.0f);
    assertEquals(1.0f, r);

    r = mutil::abs(-1.0f);
    assertEquals(1.0f, r);

    r = mutil::abs(0.0f);
    assertEquals(0.0f, r);
}

static void testFMathClamp()
{
    float r = mutil::clamp(1.0f, 0.0f, 2.0f);
    assertEquals(1.0f, r);

    r = mutil::clamp(-1.0f, 0.0f, 2.0f);
    assertEquals(0.0f, r);

    r = mutil::clamp(3.0f, 0.0f, 2.0f);
    assertEquals(2.0f, r);
}

static void testFMathCeil()
{
    float r = mutil::ceil(1.0f);
    assertEquals(1.0f, r);

    r = mutil::ceil(1.1f);
    assertEquals(2.0f, r);

    r = mutil::ceil(1.9f);
    assertEquals(2.0f, r);

    r = mutil::ceil(-1.0f);
    assertEquals(-1.0f, r);

    r = mutil::ceil(-1.1f);
    assertEquals(-1.0f, r);

    r = mutil::ceil(-1.9f);
    assertEquals(-1.0f, r);
}

static void testFMathFloor()
{
    float r = mutil::floor(1.0f);
    assertEquals(1.0f, r);

    r = mutil::floor(1.1f);
    assertEquals(1.0f, r);

    r = mutil::floor(1.9f);
    assertEquals(1.0f, r);

    r = mutil::floor(-1.0f);
    assertEquals(-1.0f, r);

    r = mutil::floor(-1.1f);
    assertEquals(-2.0f, r);

    r = mutil::floor(-1.9f);
    assertEquals(-2.0f, r);
}

static void testFMathTrunc()
{
    float r = mutil::trunc(1.0f);
    assertEquals(1.0f, r);

    r = mutil::trunc(1.1f);
    assertEquals(1.0f, r);

    r = mutil::trunc(1.9f);
    assertEquals(1.0f, r);

    r = mutil::trunc(-1.0f);
    assertEquals(-1.0f, r);

    r = mutil::trunc(-1.1f);
    assertEquals(-1.0f, r);

    r = mutil::trunc(-1.9f);
    assertEquals(-1.0f, r);
}

static void testFMathMod()
{
    float r = mutil::mod(1.0f, 1.0f);
    assertEquals(0.0f, r);

    r = mutil::mod(1.0f, 2.0f);
    assertEquals(1.0f, r);

    r = mutil::mod(3.0f, 2.0f);
    assertEquals(1.0f, r);

    r = mutil::mod(-1.0f, 1.0f);
    assertEquals(0.0f, r);

    r = mutil::mod(-1.0f, 2.0f);
    assertEquals(-1.0f, r);

    r = mutil::mod(-3.0f, 2.0f);
    assertEquals(-1.0f, r);
}

static void testFMathRound()
{
    float r = mutil::round(1.0f);
    assertEquals(1.0f, r);

    r = mutil::round(1.1f);
    assertEquals(1.0f, r);

    r = mutil::round(1.5f);
    assertEquals(2.0f, r);

    r = mutil::round(1.9f);
    assertEquals(2.0f, r);

    r = mutil::round(-1.0f);
    assertEquals(-1.0f, r);

    r = mutil::round(-1.1f);
    assertEquals(-1.0f, r);

    r = mutil::round(-1.5f);
    assertEquals(-2.0f, r);

    r = mutil::round(-1.9f);
    assertEquals(-2.0f, r);
}

static void testFMathLerp()
{
    float r = mutil::lerp(0.0f, 1.0f, 0.0f);
    assertEquals(0.0f, r);

    r = mutil::lerp(0.0f, 1.0f, 0.5f);
    assertEquals(0.5f, r);

    r = mutil::lerp(0.0f, 1.0f, 1.0f);
    assertEquals(1.0f, r);

    r = mutil::lerp(0.0f, 1.0f, 2.0f);
    assertEquals(2.0f, r);
}

static void testFMathSmoothStep()
{
    float r = mutil::smoothstep(0.0f, 1.0f, 0.0f);
    assertEquals(0.0f, r);

    r = mutil::smoothstep(0.0f, 1.0f, 0.5f);
    assertEquals(0.5f, r);

    r = mutil::smoothstep(0.0f, 1.0f, 1.0f);
    assertEquals(1.0f, r);

    r = mutil::smoothstep(0.0f, 1.0f, 2.0f);
    assertEquals(1.0f, r);

    r = mutil::smoothstep(0.0f, 1.0f, -1.0f);
    assertEquals(0.0f, r);

    r = mutil::smoothstep(0.0f, 1.0f, 0.25f);
    assertEquals(0.15625f, r);
}

static void testFMathSmootherStep()
{
    float r = mutil::smootherstep(0.0f, 1.0f, 0.0f);
    assertEquals(0.0f, r);

    r = mutil::smootherstep(0.0f, 1.0f, 0.5f);
    assertEquals(0.5f, r);

    r = mutil::smootherstep(0.0f, 1.0f, 1.0f);
    assertEquals(1.0f, r);

    r = mutil::smootherstep(0.0f, 1.0f, 2.0f);
    assertEquals(1.0f, r);

    r = mutil::smootherstep(0.0f, 1.0f, -1.0f);
    assertEquals(0.0f, r);

    r = mutil::smootherstep(0.0f, 1.0f, 0.25f);
    assertEquals(0.103515625f, r);
}

static void testFMathSin()
{
    float r = mutil::sin(0.0f);
    assertEquals(0.0f, r);

    r = mutil::sin(MUTIL_PI);
    assertEquals(0.0f, r);

    r = mutil::sin(MUTIL_PI2);
    assertEquals(1.0f, r);

    r = mutil::sin(MUTIL_PI4);
    assertEquals(MUTIL_SQRT2 / 2.0f, r);

    r = mutil::sin(MUTIL_3PI2);
    assertEquals(-1.0f, r);
}

static void testFMathCos()
{
    float r = mutil::cos(0.0f);
    assertEquals(1.0f, r);

    r = mutil::cos(MUTIL_PI);
    assertEquals(-1.0f, r);

    r = mutil::cos(MUTIL_PI2);
    assertEquals(0.0f, r);

    r = mutil::cos(MUTIL_PI4);
    assertEquals(MUTIL_SQRT2 / 2.0f, r);

    r = mutil::cos(MUTIL_3PI2);
    assertEquals(0.0f, r);
}

static void testFMathTan()
{
    float r = mutil::tan(0.0f);
    assertEquals(0.0f, r);

    r = mutil::tan(MUTIL_PI);
    assertEquals(0.0f, r);

    r = mutil::tan(MUTIL_PI4);
    assertEquals(1.0f, r);
}

static void testFMahAsin()
{
    float r = mutil::asin(0.0f);
    assertEquals(0.0f, r);

    r = mutil::asin(1.0f);
    assertEquals(MUTIL_PI2, r);

    r = mutil::asin(-1.0f);
    assertEquals(-MUTIL_PI2, r);

    r = mutil::asin(MUTIL_SQRT2 / 2.0f);
    assertEquals(MUTIL_PI4, r);

    r = mutil::asin(-MUTIL_SQRT2 / 2.0f);
    assertEquals(-MUTIL_PI4, r);
}

static void testFMathAcos()
{
    float r = mutil::acos(1.0f);
    assertEquals(0.0f, r);

    r = mutil::acos(0.0f);
    assertEquals(MUTIL_PI2, r);

    r = mutil::acos(-1.0f);
    assertEquals(MUTIL_PI, r);

    r = mutil::acos(MUTIL_SQRT2 / 2.0f);
    assertEquals(0.78539816f, r);

    r = mutil::acos(-MUTIL_SQRT2 / 2.0f);
    assertEquals(2.35619449f, r);
}

static void testFMathAtan()
{
    float r = mutil::atan(0.0f);
    assertEquals(0.0f, r);

    r = mutil::atan(1.0f);
    assertEquals(MUTIL_PI4, r);

    r = mutil::atan(-1.0f);
    assertEquals(-MUTIL_PI4, r);

    r = mutil::atan(MUTIL_SQRT2 / 2.0f);
    assertEquals(0.6154797f, r);

    r = mutil::atan(-MUTIL_SQRT2 / 2.0f);
    assertEquals(-0.6154797f, r);

    r = mutil::atan(10.0f);
    assertEquals(1.47112767f, r);

    r = mutil::atan(-10.0f);
    assertEquals(-1.47112767f, r);
}

static void testFMathLog2()
{
    float r = mutil::log2(1.0f);
    assertEquals(0.0f, r);

    r = mutil::log2(2.0f);
    assertEquals(1.0f, r);

    r = mutil::log2(4.0f);
    assertEquals(2.0f, r);

    r = mutil::log2(MUTIL_E);
    assertEquals(MUTIL_LOG2E, r);

    r = mutil::log2(10);
    assertEquals(MUTIL_LOG2_10, r);
}

static void testFMathLog()
{
    float r = mutil::log(1.0f);
    assertEquals(0.0f, r);

    r = mutil::log(MUTIL_E);
    assertEquals(1.0f, r);

    r = mutil::log(MUTIL_E * MUTIL_E);
    assertEquals(2.0f, r);
}

static void testFMathLog10()
{
    float r = mutil::log10(1.0f);
    assertEquals(0.0f, r);

    r = mutil::log10(10.0f);
    assertEquals(1.0f, r);

    r = mutil::log10(100.0f);
    assertEquals(2.0f, r);
}

Test getFMathTest(const std::string &test)
{
    if (test == "FMathConstants")
        return testFMathConstants;
    if (test == "FMathRadians")
        return testFMathRadians;
    if (test == "FMathDegrees")
        return testFMathDegrees;
    if (test == "FMathSgn")
        return testFMathSgn;
    if (test == "FMathMin")
        return testFMathMin;
    if (test == "FMathMax")
        return testFMathMax;
    if (test == "FMathSqrt")
        return testFMathSqrt;
    if (test == "FMathInverseSqrt")
        return testFMathInverseSqrt;
    if (test == "FMathFastInverseSqrt")
        return testFMathFastInverseSqrt;
    if (test == "FMathAbs")
        return testFMathAbs;
    if (test == "FMathClamp")
        return testFMathClamp;
    if (test == "FMathCeil")
        return testFMathCeil;
    if (test == "FMathFloor")
        return testFMathFloor;
    if (test == "FMathTrunc")
        return testFMathTrunc;
    if (test == "FMathMod")
        return testFMathMod;
    if (test == "FMathRound")
        return testFMathRound;
    if (test == "FMathLerp")
        return testFMathLerp;
    if (test == "FMathSmoothStep")
        return testFMathSmoothStep;
    if (test == "FMathSmootherStep")
        return testFMathSmootherStep;
    if (test == "FMathSin")
        return testFMathSin;
    if (test == "FMathCos")
        return testFMathCos;
    if (test == "FMathTan")
        return testFMathTan;
    if (test == "FMathAsin")
        return testFMahAsin;
    if (test == "FMathAcos")
        return testFMathAcos;
    if (test == "FMathAtan")
        return testFMathAtan;
    if (test == "FMathLog2")
        return testFMathLog2;
    if (test == "FMathLog")
        return testFMathLog;
    if (test == "FMathLog10")
        return testFMathLog10;

    return nullptr;
}