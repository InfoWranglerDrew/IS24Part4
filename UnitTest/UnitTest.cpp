#include "pch.h"
#include "CppUnitTest.h"
#include <sstream>
#include "../FizzBuzz/FizzBuzz.h"
 
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(FizzBuzz_with_modulo_OutputTest)
		{
			std::ostringstream oss; // Drew: Create a string stream to capture output
			Logger::WriteMessage("Start FizzBuzz_with_modulo_OutputTest");
			
			//main_FizzBuzz_with_modulo(oss);
			main_FizzBuzz_with_modulo(oss);
			Assert::IsTrue(TestOutput(oss));
			Logger::WriteMessage("FizzBuzz_with_modulo_OutputTest passed");
		}

		TEST_METHOD(FizzBuzz_without_modulo_15_OutputTest)
		{
			std::ostringstream oss; // Drew: Create a string stream to capture output
			Logger::WriteMessage("Start FizzBuzz_without_modulo_15_OutputTest");

			//main_FizzBuzz_with_modulo(oss);
			main_FizzBuzz_without_modulo_15(oss);
			Assert::IsTrue(TestOutput(oss));
			Logger::WriteMessage("FizzBuzz_without_modulo_15_OutputTest passed");
		}

		TEST_METHOD(FizzBuzz_without_modulo_OutputTest)
		{
			std::ostringstream oss; // Drew: Create a string stream to capture output
			Logger::WriteMessage("Start FizzBuzz_without_modulo_OutputTest");

			//main_FizzBuzz_with_modulo(oss);
			main_FizzBuzz_without_modulo(oss);
			Assert::IsTrue(TestOutput(oss));
			Logger::WriteMessage("FizzBuzz_without_modulo_OutputTest passed");
		}

		TEST_METHOD(FizzBuzz_using_std_transform_OutputTest)
		{
			std::ostringstream oss; // Drew: Create a string stream to capture output
			Logger::WriteMessage("Start FizzBuzz_using_std_transform_OutputTest");

			//main_FizzBuzz_with_modulo(oss);
			main_FizzBuzz_using_std_transform(oss);
			Assert::IsTrue(TestOutput(oss));
			Logger::WriteMessage("FizzBuzz_using_std_transform_OutputTest passed");
		}

		bool TestOutput(std::ostringstream& oss)
		{
			bool finalResult = true;
			std::istringstream iss(oss.str());
			std::string curLine;
			char messageBuffer[200];
			int compareResult = 0;
			size_t lineCount = 1;

			while (std::getline(iss, curLine)) {
				if (lineCount > 100) {
					Logger::WriteMessage("More than 100 lines found");
					return false;
				}

				compareResult = 0;

				if ((lineCount % 15) == 0) {
					compareResult = curLine.compare("FizzBuzz");
					if (compareResult != 0) {
						std::snprintf(messageBuffer, 200, "Line %zu should be FizzBuzz, but is %s", lineCount, curLine.c_str());
						Logger::WriteMessage(messageBuffer);
					}
				}
				else if ((lineCount % 3) == 0) {
					compareResult = curLine.compare("Fizz");
					if (compareResult != 0) {
						std::snprintf(messageBuffer, 200, "Line %zu should be Fizz, but is %s", lineCount, curLine.c_str());
						Logger::WriteMessage(messageBuffer);
					}
				}
				else if ((lineCount % 5) == 0) {
					compareResult = curLine.compare("Buzz");
					if (compareResult != 0) {
						std::snprintf(messageBuffer, 200, "Line %zu should be Buzz, but is %s", lineCount, curLine.c_str());
						Logger::WriteMessage(messageBuffer);
					}
				}
				else {
					compareResult = curLine.compare(std::to_string(lineCount));
					if (compareResult != 0) {
						std::snprintf(messageBuffer, 200, "Line %zu should be %zu, but is %s", lineCount, lineCount, curLine.c_str());
						Logger::WriteMessage(messageBuffer);
					}
				}
				if (compareResult != 0) {
					finalResult = false;
				}
				
				++lineCount;
			}
			if (lineCount < 100) {
				std::snprintf(messageBuffer, 200, "Should be 100 lines, but there are only %zu", lineCount);
				Logger::WriteMessage(messageBuffer);
				finalResult = false;
			}

			return finalResult;
		}
	};
}
