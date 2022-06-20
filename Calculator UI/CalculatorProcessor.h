#pragma once
#include "wx/wx.h"

class Calculator;
class CalculatorProcessor
{
private:
	static CalculatorProcessor* _processor;
	CalculatorProcessor() {};
	int answer = 198;
	Calculator* calculatorMain;
public:
	static CalculatorProcessor* GetInstance();
	CalculatorProcessor(CalculatorProcessor& other) = delete;
	void operator= (const CalculatorProcessor& other) = delete; 
	std::string Add();
	std::string Subtract();
	std::string Multiply();
	std::string Divide();
	std::string Equal();
	std::string Negate();
	std::string Mod();
	void GetBinary(Calculator* window);
	void GetDecimal(Calculator* window);
	void GetHexadecimanl(Calculator* window);
};

