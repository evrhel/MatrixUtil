cmake_minimum_required(VERSION 3.10)

project(MatrixUtilTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MatrixUtilTests
	src/main.cpp
	src/test.h
	src/test.cpp

	src/test_quaternion.cpp
	src/test_vector2.cpp
	src/test_vector3.cpp
	src/test_vector4.cpp
)

target_link_libraries(MatrixUtilTests PRIVATE MatrixUtil)

# Vector2
add_test(NAME "Vector2Basic" COMMAND MatrixUtilTests Vector2Basic)
add_test(NAME "Vector2Dot" COMMAND MatrixUtilTests Vector2Dot)
add_test(NAME "Vector2Length" COMMAND MatrixUtilTests Vector2Length)
add_test(NAME "Vector2LengthSq" COMMAND MatrixUtilTests Vector2LengthSq)
add_test(NAME "Vector2Distance" COMMAND MatrixUtilTests Vector2Distance)
add_test(NAME "Vector2Normalize" COMMAND MatrixUtilTests Vector2Normalize)
add_test(NAME "Vector2Reflect" COMMAND MatrixUtilTests Vector2Reflect)

# Vector3
add_test(NAME "Vector3Basic" COMMAND MatrixUtilTests Vector3Basic)
add_test(NAME "Vector3Dot" COMMAND MatrixUtilTests Vector3Dot)
add_test(NAME "Vector3Cross" COMMAND MatrixUtilTests Vector3Cross)
add_test(NAME "Vector3Length" COMMAND MatrixUtilTests Vector3Length)
add_test(NAME "Vector3LengthSq" COMMAND MatrixUtilTests Vector3LengthSq)
add_test(NAME "Vector3Distance" COMMAND MatrixUtilTests Vector3Distance)
add_test(NAME "Vector3Normalize" COMMAND MatrixUtilTests Vector3Normalize)
add_test(NAME "Vector3Reflect" COMMAND MatrixUtilTests Vector3Reflect)

# Vector4
add_test(NAME "Vector4Basic" COMMAND MatrixUtilTests Vector4Basic)
add_test(NAME "Vector4Dot" COMMAND MatrixUtilTests Vector4Dot)
add_test(NAME "Vector4Length" COMMAND MatrixUtilTests Vector4Length)
add_test(NAME "Vector4LengthSq" COMMAND MatrixUtilTests Vector4LengthSq)
add_test(NAME "Vector4Distance" COMMAND MatrixUtilTests Vector4Distance)
add_test(NAME "Vector4Normalize" COMMAND MatrixUtilTests Vector4Normalize)
add_test(NAME "Vector4Reflect" COMMAND MatrixUtilTests Vector4Reflect)

# Quaternion
add_test(NAME "QuaternionBasic" COMMAND MatrixUtilTests QuaternionBasic)
add_test(NAME "QuaternionAdd" COMMAND MatrixUtilTests QuaternionAdd)
add_test(NAME "QuaternionSub" COMMAND MatrixUtilTests QuaternionSub)
add_test(NAME "QuaternionMul" COMMAND MatrixUtilTests QuaternionMul)
add_test(NAME "QuaternionMulScalar" COMMAND MatrixUtilTests QuaternionMulScalar)
add_test(NAME "QuaternionDivScalar" COMMAND MatrixUtilTests QuaternionDivScalar)
add_test(NAME "QuaternionLength" COMMAND MatrixUtilTests QuaternionLength)
add_test(NAME "QuaternionLengthSq" COMMAND MatrixUtilTests QuaternionLengthSq)
add_test(NAME "QuaternionNormalize" COMMAND MatrixUtilTests QuaternionNormalize)
add_test(NAME "QuaternionConjugate" COMMAND MatrixUtilTests QuaternionConjugate)
add_test(NAME "QuaternionRotateAxis" COMMAND MatrixUtilTests QuaternionRotateAxis)

# TODO: Add more tests
