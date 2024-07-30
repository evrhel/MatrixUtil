#pragma once

#include "../settings.h"
#include "../vec/vec.h"
#include "f_math.h"

#include <cstdint>

namespace mutil
{
	namespace __1
	{
		inline Vector2 randGradient2(int ix, int iy)
		{
			const unsigned w = 8 * sizeof(unsigned);
			const unsigned s = w / 2;
			unsigned a = ix, b = iy;

			a *= 3284157443U;
			b ^= a << s | a >> (w - s);

			b *= 1911520717U;
			a ^= b << s | b >> (w - s);

			a *= 2048419325U;

			float rand = a * (MUTIL_PI / ~(~0u >> 1));
			return Vector2(mutil::cos(rand), mutil::sin(rand));
		}

		inline float dotGradient2(int ix, int iy, const Vector2 &pos)
		{
			Vector2 delta = pos - Vector2((float)ix, (float)iy);
			return dot(randGradient2(ix, iy), delta);
		}

		inline uint8_t hash(unsigned i)
		{
			static const uint8_t kPerm[] = {
				151, 160, 137, 91, 90, 15, 131, 13, 201, 95, 96, 53, 194, 233, 7, 225,
				140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23, 190, 6, 148,
				247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32,
				57, 177, 33, 88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68, 175,
				74, 165, 71, 134, 139, 48, 27, 166, 77, 146, 158, 231, 83, 111, 229, 122,
				60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40, 244, 102, 143, 54,
				65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187, 208, 89, 18, 169,
				200, 196, 135, 130, 116, 188, 159, 86, 164, 100, 109, 198, 173, 186, 3,
				64, 52, 217, 226, 250, 124, 123, 5, 202, 38, 147, 118, 126, 255, 82, 85,
				212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28, 42, 223, 183, 170,
				213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153, 101, 155, 167, 43,
				172, 9, 129, 22, 39, 253, 19, 98, 108, 110, 79, 113, 224, 232, 178, 185,
				112, 104, 218, 246, 97, 228, 251, 34, 242, 193, 238, 210, 144, 12, 191,
				179, 162, 241, 81, 51, 145, 235, 249, 14, 239, 107, 49, 192, 214, 31,
				181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50, 45, 127, 4, 150,
				254, 138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195,
				78, 66, 215, 61, 156, 180,
			};

			return kPerm[(uint8_t)i];
		}

		constexpr float grad(int hash, float x, float y)
		{
			int h = hash & 0x3f;
			float u = h < 4 ? x : y;
			float v = h < 4 ? y : x;
			return ((h & 1) ? -u : u) + ((h & 2) ? -2.0f * v : 2.0f * v);
		}
	}

	// "Classic" Perlin noise, [-1, 1]
	inline float pnoise(const Vector2 &pos)
	{
		using namespace __1;

		int x0 = (int)mutil::floor(pos.x);
		int x1 = x0 + 1;
		int y0 = (int)mutil::floor(pos.y);
		int y1 = y0 + 1;

		float sx = clamp(pos.x - x0, 0.0f, 1.0f);
		float sy = clamp(pos.y - y0, 0.0f, 1.0f);

		float n0, n1, ix0, ix1;

		n0 = dotGradient2(x0, y0, pos);
		n1 = dotGradient2(x1, y0, pos);
		ix0 = smootherstep(n0, n1, sx);

		n0 = dotGradient2(x0, y1, pos);
		n1 = dotGradient2(x1, y1, pos);
		ix1 = smootherstep(n0, n1, sx);

		return smootherstep(ix0, ix1, sy);
	}

	// Perlin noise with octaves, varying result interval
	inline float pnoise(const Vector2 &pos, float persistence, int octaves)
	{
		float total = 0.0f;
		float amplitude = 1.0f;
		float frequency = 1.0f;

		for (int i = 0; i < octaves; i++)
		{
			total += pnoise(pos * frequency) * amplitude;
			frequency *= 2.0f;
			amplitude *= persistence;
		}

		return total;
	}

	// Simplex noise, [-1, 1]
	inline float snoise(const Vector2 &pos)
	{
		// Based on https://github.com/SRombauts/SimplexNoise

		using namespace __1;

		constexpr float F2 = 0.366025403f; // (sqrt(3) - 1) / 2
		constexpr float G2 = 0.211324865f; // (3 - sqrt(3)) / 6

		float n0, n1, n2;

		const float s = (pos.x + pos.y) * F2;
		const float xs = pos.x + s;
		const float ys = pos.y + s;
		const int i = (int)mutil::floor(xs);
		const int j = (int)mutil::floor(ys);

		const float t = (i + j) * G2;
		const float X0 = i - t;
		const float Y0 = j - t;
		const float x0 = pos.x - X0;
		const float y0 = pos.y - Y0;

		int32_t i1, j1;
		if (x0 > y0)
		{
			i1 = 1;
			j1 = 0;
		}
		else
		{
			i1 = 0;
			j1 = 1;
		}

		const float x1 = x0 - i1 + G2;
		const float y1 = y0 - j1 + G2;
		const float x2 = x0 - 1.0f + 2.0f * G2;
		const float y2 = y0 - 1.0f + 2.0f * G2;

		const int gi0 = hash(i + hash(j));
		const int gi1 = hash(i + i1 + hash(j + j1));
		const int gi2 = hash(i + 1 + hash(j + 1));

		// Contribution of first corner
		float t0 = 0.5f - x0*x0 - y0*y0;
		if (t0 < 0.0f)
			n0 = 0.0f;
		else
		{
			t0 *= t0;
			n0 = t0 * t0 * grad(gi0, x0, y0);
		}

		// Contribution of second corner
		float t1 = 0.5f - x1*x1 - y1*y1;
		if (t1 < 0.0f)
			n1 = 0.0f;
		else
		{
			t1 *= t1;
			n1 = t1 * t1 * grad(gi1, x1, y1);
		}

		// Contribution of third corner
		float t2 = 0.5f - x2*x2 - y2*y2;
		if (t2 < 0.0f)
			n2 = 0.0f;
		else
		{
			t2 *= t2;
			n2 = t2 * t2 * grad(gi2, x2, y2);
		}

		// Final noise value
		return 45.23065f * (n0 + n1 + n2);
	}

	// Simplex noise with octaves, varying result interval
	inline float snoise(const Vector2 &pos, float persistence, int octaves)
	{
		float total = 0.0f;
		float amplitude = 1.0f;
		float frequency = 1.0f;

		for (int i = 0; i < octaves; i++)
		{
			total += snoise(pos * frequency) * amplitude;
			frequency *= 2.0f;
			amplitude *= persistence;
		}

		return total;
	}
}
