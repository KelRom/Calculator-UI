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

std::string CalculatorProcessor::GetBinary()
{
	return std::string();
}

std::string CalculatorProcessor::GetDecimal()
{
	return std::string();
}

std::string CalculatorProcessor::GetHexadecimanl()
{
	return std::string();
}

