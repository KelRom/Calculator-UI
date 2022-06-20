#include "CalculatorProcessor.h"
#include "Calculator.h"

CalculatorProcessor* CalculatorProcessor::_processor = nullptr;


CalculatorProcessor* CalculatorProcessor::GetInstance()
{
	
	if (_processor == nullptr)
		_processor = new CalculatorProcessor();
	
	return _processor;
}

std::string CalculatorProcessor::Add()
{
	return std::string();
}

std::string CalculatorProcessor::Subtract()
{
	return std::string();
}

std::string CalculatorProcessor::Multiply()
{
	return std::string();
}

std::string CalculatorProcessor::Divide()
{
	return std::string();
}

std::string CalculatorProcessor::Equal()
{
	return std::string();
}

std::string CalculatorProcessor::Negate()
{
	return std::string();
}

std::string CalculatorProcessor::Mod()
{
	return std::string();
}

void CalculatorProcessor::GetDecimal(Calculator* window)
{
	calculatorMain = window;
	calculatorMain->textBox->SetValue(std::to_string(answer));
}

void CalculatorProcessor::GetBinary(Calculator* window)
{
	calculatorMain = window;
	std::string result = "";
	int number = answer;
	int mod = 0;
	while (number > 0)
	{
		mod = number % 2;
		result = std::to_string(mod) + result;
		number /= 2;
	}
	calculatorMain->textBox->SetValue(result);
}

void CalculatorProcessor::GetHexadecimanl(Calculator* window)
{
	calculatorMain = window;
	std::string result = "";
	int number = answer;
	int mod = 0;
	while (number > 0)
	{
		mod = number % 16;
		if (mod < 10)
		{
			result = std::to_string(mod) + result;
		}
		else if (mod == 10)
		{
			result = "A" + result;
		}
		else if (mod == 11)
		{
			result = "B" + result;
		}
		else if (mod == 12)
		{
			result = "C" + result;
		}
		else if (mod == 13)
		{
			result = "D" + result;
		}
		else if (mod == 14)
		{
			result = "E" + result;
		}
		else if (mod == 15)
		{
			result = "F" + result;
		}

		number /= 16;
	}

	result = "0x" + result;
	calculatorMain->textBox->SetValue(result);
}

