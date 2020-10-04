#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixUtil/mutil.h"

#include "../MatrixUtil/matrix.h"

#include <string>
#include <codecvt>
#include <locale>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace mutil;

using convert_t = std::codecvt_utf8<wchar_t>;
static std::wstring_convert<convert_t, wchar_t> strconverter;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template <>
			static std::wstring ToString<Vector2>(const Vector2 &vec)
			{
				std::string str;
				str += "<";
				str += std::to_string(vec.x);
				str += ", ";
				str += std::to_string(vec.y);
				str += ">";
				return strconverter.from_bytes(str);
			};

			template <>
			static std::wstring ToString<Vector3>(const Vector3 &vec)
			{
				std::string str;
				str += "<";
				str += std::to_string(vec.x);
				str += ", ";
				str += std::to_string(vec.y);
				str += ", ";
				str += std::to_string(vec.z);
				str += ">";
				return strconverter.from_bytes(str);
			};

			template <>
			static std::wstring ToString<Vector4>(const Vector4 &vec)
			{
				std::string str;
				str += "<";
				str += std::to_string(vec.x);
				str += ", ";
				str += std::to_string(vec.y);
				str += ", ";
				str += std::to_string(vec.z);
				str += ", ";
				str += std::to_string(vec.w);
				str += ">";
				return strconverter.from_bytes(str);
			};

			template <>
			static std::wstring ToString<Matrix2>(const Matrix2 &mat)
			{
				std::string str;
				str += "\n[";
				str += std::to_string(mat.columns[0].x) + " " + std::to_string(mat.columns[1].x);
				str += "]\n";

				str += "[";
				str += std::to_string(mat.columns[0].y) + " " + std::to_string(mat.columns[1].y);
				str += "]\n";

				return strconverter.from_bytes(str);
			}

			template <>
			static std::wstring ToString<Matrix3>(const Matrix3 &mat)
			{
				std::string str;
				str += "\n[";
				str += std::to_string(mat.columns[0].x) + " " + std::to_string(mat.columns[1].x) + " " + std::to_string(mat.columns[2].x);
				str += "]\n";

				str += "[";
				str += std::to_string(mat.columns[0].y) + " " + std::to_string(mat.columns[1].y) + " " + std::to_string(mat.columns[2].y);
				str += "]\n";

				str += "[";
				str += std::to_string(mat.columns[0].z) + " " + std::to_string(mat.columns[1].z) + " " + std::to_string(mat.columns[2].z);
				str += "]\n";

				return strconverter.from_bytes(str);
			}

			template <>
			static std::wstring ToString<Matrix4>(const Matrix4 &mat)
			{
				std::string str;
				str += "\n[";
				str += std::to_string(mat.columns[0].x) + " " + std::to_string(mat.columns[1].x) + " " + std::to_string(mat.columns[2].x) + " " + std::to_string(mat.columns[3].x);
				str += "]\n";

				str += "[";
				str += std::to_string(mat.columns[0].y) + " " + std::to_string(mat.columns[1].y) + " " + std::to_string(mat.columns[2].y) + " " + std::to_string(mat.columns[3].y);
				str += "]\n";

				str += "[";
				str += std::to_string(mat.columns[0].z) + " " + std::to_string(mat.columns[1].z) + " " + std::to_string(mat.columns[2].z) + " " + std::to_string(mat.columns[3].z);
				str += "]\n";

				str += "[";
				str += std::to_string(mat.columns[0].w) + " " + std::to_string(mat.columns[1].w) + " " + std::to_string(mat.columns[2].w) + " " + std::to_string(mat.columns[3].w);
				str += "]\n";

				return strconverter.from_bytes(str);
			}
		}
	}
}

namespace MatrixUtilUnitTest
{

	TEST_CLASS(MatrixUtilVectorTests)
	{
	public:
		
		TEST_METHOD(TestVectorEuqlas)
		{
			Vector4 first = Vector4(10, 3, 3, 6);
			Vector4 second = Vector4(10, 3, 3, 6);

			Assert::IsTrue(first == second);
		}

		TEST_METHOD(TestVectorAddition)
		{
			Vector4 first = Vector4(10, 3, 3, 6);
			Vector4 second = Vector4(4, 2, 5, 1);
			first += second;

			Vector4 result = first;
			Vector4 expected = Vector4(14, 5, 8, 7);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestVectorSubtraction)
		{
			Vector4 first = Vector4(10, 3, 3, 6);
			Vector4 second = Vector4(4, 2, 5, 1);

			Vector4 result = first - second;
			Vector4 expected = Vector4(6, 1, -2, 5);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestVectorMultiplication)
		{
			Vector4 first = Vector4(10, 3, 3, 6);
			Vector4 second = Vector4(4, 2, 5, 1);

			Vector4 result = first * second;
			Vector4 expected = Vector4(40, 6, 15, 6);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestVectorDivision)
		{
			Vector4 first = Vector4(10, 3, 3, 6);
			Vector4 second = Vector4(4, 2, 5, 1);

			Vector4 result = first / second;
			Vector4 expected = Vector4(2.5f, 1.5f, 0.6f, 6);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestVectorNegate)
		{
			Vector4 first = Vector4(10, 3, 3, 6);
			Vector4 result = -first;

			Vector4 expected = Vector4(-10, -3, -3, -6);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestVectorDotProduct)
		{
			Vector4 first = Vector4(1, 5, 4, 3);
			Vector4 second = Vector4(3, 5, 3, 2);

			float result = mutil::dot(first, second);
			float expected = 46;

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestVectorCrossProduct)
		{
			Vector3 first = Vector3(1, 5, 4);
			Vector3 second = Vector3(3, 5, 3);

			Vector3 result = mutil::cross(first, second);
			Vector3 expected = Vector3(-5, 9, -10);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestVectorLength)
		{
			Vector2 vec = Vector2(1, 1);

			float result = mutil::length(vec);

			float expected = sqrtf(2.0f);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestVectorNormalize)
		{
			Vector2 vec = Vector2(1, 1);

			Vector2 result = mutil::normalize(vec);
			Vector2 expected = Vector2(sqrtf(2.0f) / 2, sqrtf(2.0f) / 2);

			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(MatrixUtilMatrixTests)
	{

		TEST_METHOD(TestMatrixEquals)
		{
			Matrix3 first = Matrix3(
				Vector3(1, -1, 0),
				Vector3(-1, 2, -1),
				Vector3(0, -1, 2)
			);

			Matrix3 second = Matrix3(
				Vector3(1, -1, 0),
				Vector3(-1, 2, -1),
				Vector3(0, -1, 2)
			);

			Matrix2 mat2 = Matrix2(first);
			Matrix2 other = Matrix2(
				Vector2(1, -1),
				Vector2(-1, 2)
			);

			Assert::IsTrue(mat2 == other);
		}

		TEST_METHOD(TestMatrixAddition)
		{
			Matrix3 first = Matrix3(
				Vector3(30, 4, 5),
				Vector3(8, 33, 0),
				Vector3(4, 9, 2)
			);

			Matrix3 second = Matrix3(
				Vector3(3, 2, 7),
				Vector3(4, 0, 1),
				Vector3(7, 1, 5)
			);

			Matrix3 result = first + second;
			Matrix3 expected = Matrix3(
				Vector3(33, 6, 12),
				Vector3(12, 33, 1),
				Vector3(11, 10, 7)
			);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMatrixSubtraction)
		{
			Matrix3 first = Matrix3(
				Vector3(30, 4, 5),
				Vector3(8, 33, 0),
				Vector3(4, 9, 2)
			);

			Matrix3 second = Matrix3(
				Vector3(3, 2, 7),
				Vector3(4, 0, 1),
				Vector3(7, 1, 5)
			);

			Matrix3 result = first - second;
			Matrix3 expected = Matrix3(
				Vector3(27, 2, -2),
				Vector3(4, 33, -1),
				Vector3(-3, 8, -3)
			);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMatrixMultiplication)
		{
			Matrix3 first = Matrix3(
				Vector3(30, 4, 5),
				Vector3(8, 33, 0),
				Vector3(4, 9, 2)
			);

			Matrix3 second = Matrix3(
				Vector3(3, 2, 7),
				Vector3(4, 0, 1),
				Vector3(7, 1, 5)
			);

			Matrix3 result = first;
			result *= second;
			Matrix3 expected = Matrix3(
				Vector3(134, 141, 29),
				Vector3(124, 25, 22),
				Vector3(238, 106, 45)
			);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMatrixInverse)
		{
			Matrix3 first = Matrix3(
				Vector3(1, -1, 0),
				Vector3(-1, 2, -1),
				Vector3(0, -1, 2)
			);

			bool exists;
			Matrix3 inverse = mutil::inverse(first, &exists);
			if (!exists)
			{
				Assert::Fail(L"Invertable matrix marked not invertable");
				return;
			}
			Matrix3 expected = Matrix3(
				Vector3(3, 2, 1),
				Vector3(2, 2, 1),
				Vector3(1, 1, 1)
			);

			Assert::AreEqual(expected, inverse);
		}

		TEST_METHOD(TestMatrix4Multiplication)
		{
			Matrix4 first = Matrix4(
				Vector4(30, 4, 5, 3),
				Vector4(8, 33, 0, 5),
				Vector4(4, 9, 2, 10),
				Vector4(2, 3, 4, 1)
			);

			Matrix4 second = Matrix4(
				Vector4(3, 2, 7, 0),
				Vector4(4, 0, 1, 5),
				Vector4(7, 1, 5, 5),
				Vector4(3, 0, 10, 7)
			);

			Matrix4 result = first * second;
			Matrix4 expected = Matrix4(
				Vector4(134, 141, 29, 89),
				Vector4(134, 40, 42, 27),
				Vector4(248, 121, 65, 81),
				Vector4(144, 123, 63, 116)
			);

			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestMatrixSpeed)
		{
			Matrix4 first = Matrix4(
				Vector4(30, 4, 5, 3),
				Vector4(8, 33, 0, 5),
				Vector4(4, 9, 2, 10),
				Vector4(2, 3, 4, 1)
			);

			Matrix4 second = Matrix4(
				Vector4(3, 2, 7, 0),
				Vector4(4, 0, 1, 5),
				Vector4(7, 1, 5, 5),
				Vector4(3, 0, 10, 7)
			);

			const long long iterations = 1000000;
			Matrix4 result;
			for (long long i = 0; i < iterations; i++)
			{
				result = first * second;
			}

			Assert::IsTrue(true);
		}
	};

}
