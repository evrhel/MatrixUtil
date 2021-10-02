# MatrixUtil

## About

MatrixUtil is a header-only library written in C++ designed for handling vector and matrix computations. It is especially designed with graphics programming in mind and features functions to create transform, rotation, and scaling matrices alongside perspective and orthographic projections.

Additionally, the library is designed to be high performance, with minimal copying of data alongside the use of intrinsics and algorithms such as the fast inverse square root.

## Installing

To use the library in your program, simply copy all the header files in `./MatrixUtil` to a directory in which your project can see them (such as in an include folder or directly into your project). To include the files, only including `mutil.h` is necessary.

## Types

### Vector Types

- `Vector2` - A 2-component 32-bit floating point vector.
- `Vector3` - A 3-component 32-bit floating point vector.
- `Vector4` - A 4-component 32-bit floating point vector.
- `IntVector2` - A 2-component signed 32-bit integer vector.
- `IntVector3` - A 3-component signed 32-bit integer vector.
- `IntVector4` - A 4-component signed 32-bit integer vector.

Each vector has multiple ways to access its data. In a vector, the data can either be accessed via `x`, `y`, `z`, and `w` depending on the number of components (a `Vector2` would only have `x` and `y`,  while a `Vector4` would have `x`, `y`, `z`, and `w`, for instance). `r`, `g`, `b`, `a` as well as `s`, `t`, `p`, `q` may also be used to access in the same way as `x`, `y`, `z`, or `w`. The last way to access the data is via the member variable `vec` which, for a vector of `N` components of type `T`, is an array defined as: `T vec[N]`. Like the previous access methods, the elements of the array retain their respective order (`vec[0] == x`, `vec[1] == y`, etc. are all `true`).

### Matrix Types
All matrices are stored in column-major order.

- `Matrix2` - A 2x2 32-bit floating point matrix.
- `Matrix3` - A 3x3 32-bit floating point matrix.
- `Matrix4` - A 4x4 32-bit floating point matrix.
- `IntMatrix2` - A 2x2 signed 32-bit integer matrix.
- `IntMatrix3` - A 2x2 signed 32-bit integer matrix.
- `IntMatrix4` - A 2x2 signed 32-bit integer matrix.

Like vectors, each matrix type has multiple ways to access its data. For an `N`x`N`, a member variable exists named `columns[N]` which stores each column of the matrix. Additionally, there are member variables named in the format: `_RC` where `R` is the row in the matrix and `C` is the column in the matrix. This means, for the `N`x`N` matrix, this ranges from `_11` to `_NN`. Finally, like in vectors, there is an array member which contains the raw elements of the matrix in column major order. For a matrix containing type `T`, the member is defined as: `T mat[N * N]`.
