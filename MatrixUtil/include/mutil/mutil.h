#pragma once

// This is the only header that should be included by the user.

// disable unitialized variable warning for the entire library
#if _WIN32
#pragma warning(push)
#pragma warning(disable : 26495)
#endif

#include "settings.h"

#include "math/math.h"
#include "vec/vec.h"
#include "mat/mat.h"
#include "quat/quaternion.h"

#include "vec/vec_impl.h"
#include "mat/mat_impl.h"
#include "quat/quaternion_impl.h"

#if _WIN32
#pragma warning(pop)
#endif
