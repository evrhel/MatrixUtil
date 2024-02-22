# MatrixUtil

[![.github/workflows/ci.yaml](https://github.com/evrhel/MatrixUtil/actions/workflows/ci.yaml/badge.svg)](https://github.com/evrhel/MatrixUtil/actions/workflows/ci.yaml)

## About

MatrixUtil is a header-only library written in C++ designed for handling vector and matrix computations. It is especially designed with graphics programming in mind and features functions to create transform, rotation, and scaling matrices alongside perspective and orthographic projections.

Additionally, the library is designed to be high performance, with minimal copying of data alongside the use of intrinsics and algorithms such as the fast inverse square root.

## Installing

There are a few options for installing MatrixUtil. The preferred method is to use CMake.

### Using CMake

Obtain the library using CMake, or add it as a submodule in your project. You may then use `add_subdirectory` to include the library in your project.

```cmake
add_subdirectory(MatrixUtil)
```

Then, link the library to your target.

```cmake
target_link_libraries(your_target PUBLIC MatrixUtil)
```

### Other Build Systems

MatrixUtil can be added by adding `MatrixUtil/include` as an include directory, or by directly copying the files into your project.

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
- `IntMatrix3` - A 3x3 signed 32-bit integer matrix.
- `IntMatrix4` - A 4x4 signed 32-bit integer matrix.

Like vectors, each matrix type has multiple ways to access its data. For an `N`x`N`, a member variable exists named `columns[N]` which stores each column of the matrix. Additionally, there are member variables named in the format: `_RC` where `R` is the row in the matrix and `C` is the column in the matrix. This means, for the `N`x`N` matrix, this ranges from `_11` to `_NN`. Finally, like in vectors, there is an array member which contains the raw elements of the matrix in column major order. For a matrix containing type `T`, the member is defined as: `T mat[N * N]`.

### Quaternions

Quaternions are a number system in 4D space which are generally used in 3D to more naturally represent rotations. They consist of a real part and three imaginary parts. Normal Euler angles are suseptiable to [Gimbal Lock](https://en.wikipedia.org/wiki/Gimbal_lock). When used correctly, quaternions can easily avoid this limitation using much less trigonometry and multiplication operations. Applying multiple rotations is as simple as multiplying quaternions together, and a quaternion representing a rotation around an arbitrary vector requires only two trigonometric operations! Additioanlly, interpolation between quaternions results in a much more natural animation than linearly interpolating euler angles.

Quaternions can be used via the `Quaternion` class.

- Quaternions can be converted in to either a `Matrix3` or `Matrix4` rotation matrix via the `torotation3` and the `torotation` functions, respectively.
- Conversion functions between Eueler angles and quaternions are avaliable through the `toeuler` and `fromeuler` functions.
- The function with the lowest overhead to create quaternions is the `rotateaxis` function which creates a quaternion that represents a rotation around a direction vector.
- A point can be rotated with lower overhead using the `rotatevector` function.
- Interpolation between quaternions should be done with `slerp`.
