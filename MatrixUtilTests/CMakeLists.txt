cmake_minimum_required(VERSION 3.10)

project(MatrixUtilTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MatrixUtilTests
	src/main.cpp
	src/test.cpp
	src/test_vector2.cpp
	src/test_vector3.cpp
	src/test.h)

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
