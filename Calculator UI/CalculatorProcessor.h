#pragma once
#include "wx/wx.h"

class Calculator;
class CalculatorProcessor
{
private:
	static CalculatorProcessor* _processor;
	CalculatorProcessor() {};
	int baseNumber = 0;
	Calculator* c;
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
	std::string GetBinary();
	std::string GetDecimal();
	std::string GetHexadecimanl();
};

