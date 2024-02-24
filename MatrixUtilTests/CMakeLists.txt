cmake_minimum_required(VERSION 3.10)

project(MatrixUtilTests LANGUAGES CXX)

include(CTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MatrixUtilTests
	src/main.cpp
	src/test.h
	src/test.cpp

	src/test_f_math.cpp
	src/test_i_math.cpp
	src/test_matrix2.cpp
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

# Float Math
add_test(NAME "FMathConstants" COMMAND MatrixUtilTests FMathConstants)
add_test(NAME "FMathRadians" COMMAND MatrixUtilTests FMathRadians)
add_test(NAME "FMathDegrees" COMMAND MatrixUtilTests FMathDegrees)
add_test(NAME "FMathSgn" COMMAND MatrixUtilTests FMathSgn)
add_test(NAME "FMathMin" COMMAND MatrixUtilTests FMathMin)
add_test(NAME "FMathMax" COMMAND MatrixUtilTests FMathMax)
add_test(NAME "FMathSqrt" COMMAND MatrixUtilTests FMathSqrt)
add_test(NAME "FMathInverseSqrt" COMMAND MatrixUtilTests FMathInverseSqrt)
add_test(NAME "FMathFastInverseSqrt" COMMAND MatrixUtilTests FMathFastInverseSqrt)
add_test(NAME "FMathAbs" COMMAND MatrixUtilTests FMathAbs)
add_test(NAME "FMathClamp" COMMAND MatrixUtilTests FMathClamp)
add_test(NAME "FMathCeil" COMMAND MatrixUtilTests FMathCeil)
add_test(NAME "FMathFloor" COMMAND MatrixUtilTests FMathFloor)
add_test(NAME "FMathTrunc" COMMAND MatrixUtilTests FMathTrunc)
add_test(NAME "FMathMod" COMMAND MatrixUtilTests FMathMod)
add_test(NAME "FMathRound" COMMAND MatrixUtilTests FMathRound)
add_test(NAME "FMathLerp" COMMAND MatrixUtilTests FMathLerp)
add_test(NAME "FMathSmoothStep" COMMAND MatrixUtilTests FMathSmoothStep)
add_test(NAME "FMathSmootherStep" COMMAND MatrixUtilTests FMathSmootherStep)
add_test(NAME "FMathSin" COMMAND MatrixUtilTests FMathSin)
add_test(NAME "FMathCos" COMMAND MatrixUtilTests FMathCos)
add_test(NAME "FMathTan" COMMAND MatrixUtilTests FMathTan)
add_test(NAME "FMathAsin" COMMAND MatrixUtilTests FMathAsin)
add_test(NAME "FMathAcos" COMMAND MatrixUtilTests FMathAcos)
add_test(NAME "FMathAtan" COMMAND MatrixUtilTests FMathAtan)
add_test(NAME "FMathLog2" COMMAND MatrixUtilTests FMathLog2)
add_test(NAME "FMathLog" COMMAND MatrixUtilTests FMathLog)
add_test(NAME "FMathLog10" COMMAND MatrixUtilTests FMathLog10)

# Integer Math
add_test(NAME "IMathConstants" COMMAND MatrixUtilTests IMathConstants)
add_test(NAME "IMathClamp" COMMAND MatrixUtilTests IMathClamp)
add_test(NAME "IMathMin" COMMAND MatrixUtilTests IMathMin)
add_test(NAME "IMathMax" COMMAND MatrixUtilTests IMathMax)
add_test(NAME "IMathAbs" COMMAND MatrixUtilTests IMathAbs)
add_test(NAME "IMathSgn" COMMAND MatrixUtilTests IMathSgn)

# Matrix2
add_test(NAME "Matrix2Basic" COMMAND MatrixUtilTests Matrix2Basic)
add_test(NAME "Matrix2Add" COMMAND MatrixUtilTests Matrix2Add)
add_test(NAME "Matrix2Sub" COMMAND MatrixUtilTests Matrix2Sub)
add_test(NAME "Matrix2MulScalar" COMMAND MatrixUtilTests Matrix2MulScalar)
add_test(NAME "Matrix2MulVector" COMMAND MatrixUtilTests Matrix2MulVector)
add_test(NAME "Matrix2MulMatrix" COMMAND MatrixUtilTests Matrix2MulMatrix)
add_test(NAME "Matrix2Determinant" COMMAND MatrixUtilTests Matrix2Determinant)
add_test(NAME "Matrix2Transpose" COMMAND MatrixUtilTests Matrix2Transpose)
add_test(NAME "Matrix2Cofactor" COMMAND MatrixUtilTests Matrix2Cofactor)
add_test(NAME "Matrix2Adjugate" COMMAND MatrixUtilTests Matrix2Adjugate)
add_test(NAME "Matrix2Inverse" COMMAND MatrixUtilTests Matrix2Inverse)
add_test(NAME "Matrix2Clamp" COMMAND MatrixUtilTests Matrix2Clamp)

# TODO: Add more tests

enable_testing()
