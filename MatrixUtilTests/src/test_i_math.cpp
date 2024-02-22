#include <mutil/mutil.h>
#include <string>
#include "test.h"

using namespace mutil;

static void testIMathConstants()
{
    assertEquals((int32_t)0x7fffffff, MUTIL_INTMAX);
    assertEquals((int32_t)0x80000000, MUTIL_INTMIN);

    assertEquals((uint32_t)0xffffffff, MUTIL_UINTMAX);
    assertEquals((uint32_t)0x00000000, MUTIL_UINTMIN);
}

static void testIMathClamp()
{
    int32_t r = mutil::clamp(5, 0, 10);
    assertEquals(5, r);

    r = mutil::clamp(-5, 0, 10);
    assertEquals(0, r);

    r = mutil::clamp(15, 0, 10);
    assertEquals(10, r);
}

static void testIMathMin()
{
    int32_t r = mutil::min(5, 10);
    assertEquals(5, r);

    r = mutil::min(10, 5);
    assertEquals(5, r);

    r = mutil::min(5, 5);
    assertEquals(5, r);
}

static void testIMathMax()
{
    int32_t r = mutil::max(5, 10);
    assertEquals(10, r);

    r = mutil::max(10, 5);
    assertEquals(10, r);

    r = mutil::max(5, 5);
    assertEquals(5, r);
}

static void testIMathAbs()
{
    int32_t r = mutil::abs(5);
    assertEquals(5, r);

    r = mutil::abs(-5);
    assertEquals(5, r);

    r = mutil::abs(0);
    assertEquals(0, r);
}

static void testIMathSgn()
{
    int32_t r = mutil::sign(5);
    assertEquals(1, r);

    r = mutil::sign(-5);
    assertEquals(-1, r);

    r = mutil::sign(0);
    assertEquals(0, r);
}

Test getIMathTest(const std::string &test)
{
    if (test == "IMathConstants") return testIMathConstants;
    if (test == "IMathClamp") return testIMathClamp;
    if (test == "IMathMin") return testIMathMin;
    if (test == "IMathMax") return testIMathMax;
    if (test == "IMathAbs") return testIMathAbs;
    if (test == "IMathSgn") return testIMathSgn;

    return nullptr;
}
