#pragma once
#include "wx/wx.h"
#include "ButtonFactory.h"

class Calculator;
class CalculatorProcessor
{
private:
	static CalculatorProcessor* _processor;
	CalculatorProcessor() {};
	int leftOperand = 0;
	int rightOperand = 0;
	std::string operation;
	std::string equation;
	void getOperands(Calculator* window);
	void Add();
	void Subtract();
	void Multiply();
	void Divide();	
	void Mod();
	int findOperation(Calculator* window);

public:
	static CalculatorProcessor* GetInstance();
	CalculatorProcessor(CalculatorProcessor& other) = delete;
	void operator= (const CalculatorProcessor& other) = delete;	
	std::string answer;
	std::string Equal(Calculator* window);
	void GetBinary(Calculator* window);
	void GetDecimal(Calculator* window);
	void GetHexadecimal(Calculator* window);
	void Negate(Calculator* window);
};

