/*!
\file
Contains classes for handling different types of matrices.
*/

#pragma once

#include "../vec/vec.h"

namespace mutil
{
	template <typename T, size_t N, size_t M>
	class BasicMatrix
	{
	public:
		T mat[N * M];

		constexpr BasicMatrix()
		{
			for (size_t i = 0; i < N * M; i++)
				mat[i] = T(0);
		
			for (size_t i = 0; i < N; i++)
				mat[i * M + i] = T(1);
		}
		
		explicit constexpr BasicMatrix(T diag)
		{
			for (size_t i = 0; i < N * M; i++)
				mat[i] = T(0);
			for (size_t i = 0; i < N; i++)
				mat[i * M + i] = diag;
		}

		constexpr BasicMatrix(const BasicMatrix<T, N, M> &a)
		{
			for (size_t i = 0; i < N * M; i++)
				mat[i] = a.mat[i];
		}

		constexpr const T &operator[](size_t i) const { return mat[i]; }
		constexpr T &operator[](size_t i) { return mat[i]; }
	};

	template <size_t N, size_t M>
	using Matrix = BasicMatrix<float, N, M>;

	template <size_t N, size_t M>
	using IntMatrix = BasicMatrix<int32_t, N, M>;

	using Matrix2 = Matrix<2, 2>;
	using Matrix3 = Matrix<3, 3>;
	using Matrix4 = Matrix<4, 4>;

	using IntMatrix2 = IntMatrix<2, 2>;
	using IntMatrix3 = IntMatrix<3, 3>;
	using IntMatrix4 = IntMatrix<4, 4>;
}
