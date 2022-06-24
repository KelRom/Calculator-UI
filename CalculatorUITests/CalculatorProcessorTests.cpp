#include "CppUnitTest.h"
#include "../Calculator UI/CalculatorProcessor.h"
#include "wx/wx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUITests
{
	TEST_CLASS(CalculatorProcessorTests)
	{
	public:
		CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
		Calculator* calculator = new Calculator();
		TEST_METHOD(ThereIsOnlyOneInstanceOfTheClassProcessor)
		{
			CalculatorProcessor* processor2 = CalculatorProcessor::GetInstance();
			Assert::IsTrue(processor == processor2);
		}

		TEST_METHOD(Negate123456789IsNegative123456789)
		{
			calculator->textBox->SetValue("123456789FlipSign");
			processor->Negate(calculator);
			Assert::AreEqual(calculator->textBox->GetValue(), "-123456789.000000");
		}

		TEST_METHOD(TwelvePlusTwelveIs24InDouble)
		{
			calculator->textBox->SetValue("12+12");
			processor->Equal(calculator);
			Assert::AreEqual(processor->answer, std::string("24.000000"));
		}

		TEST_METHOD(TwelveMinusTwelveIs0InDouble)
		{
			calculator->textBox->SetValue("12-12");
			processor->Equal(calculator);
			Assert::AreEqual(processor->answer, std::string("0.000000"));
		}

		TEST_METHOD(TwelveTimesTwelveIs144InDouble)
		{
			calculator->textBox->SetValue("12*12");
			processor->Equal(calculator);
			Assert::AreEqual(processor->answer, std::string("144.000000"));
		}

		TEST_METHOD(TwelveDivideTwelveIs1InDouble)
		{
			calculator->textBox->SetValue("12/12");
			processor->Equal(calculator);
			Assert::AreEqual(processor->answer, std::string("1.000000"));
		}

		TEST_METHOD(ThirteenModTenIs3InDouble)
		{
			calculator->textBox->SetValue("13%10");
			processor->Equal(calculator);
			Assert::AreEqual(processor->answer, std::string("3.000000"));
		}

		TEST_METHOD(Answer255inBinaryIs24ZerosAnd8Ones)
		{
			processor->answer = "255";
			processor->GetBinary(calculator);
			Assert::AreEqual(calculator->textBox->GetValue(), "00000000000000000000000011111111");
		}
		
		TEST_METHOD(BiggestIntTesting2to31GivesOneZeroAndRestOnes)
		{
			processor->answer = "2147483647";
			processor->GetBinary(calculator);
			Assert::AreEqual(calculator->textBox->GetValue(), "01111111111111111111111111111111");
		}

		TEST_METHOD(Answer2048InHexIs0x800)
		{
			processor->answer = "2048";
			processor->GetHexadecimal(calculator);
			Assert::AreEqual(calculator->textBox->GetValue(), "0x800");
		}

		TEST_METHOD(Answer16777215InHexIs0xFFFFFFI)
		{
			processor->answer = "16777215";
			processor->GetHexadecimal(calculator);
			Assert::AreEqual(calculator->textBox->GetValue(), "0xFFFFFF");
		}
	};
}