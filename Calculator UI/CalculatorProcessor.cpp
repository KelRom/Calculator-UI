#include "CalculatorProcessor.h"
#include "Calculator.h"

CalculatorProcessor* CalculatorProcessor::_processor = nullptr;


CalculatorProcessor* CalculatorProcessor::GetInstance()
{
	
	if (_processor == nullptr)
		_processor = new CalculatorProcessor();
	
	return _processor;
}

int CalculatorProcessor::findOperation(Calculator* window)
{
	equation = window->textBox->GetLineText(0).ToStdString();
	int operationLocation = -1;
	// at one in case the number is negative
	for (size_t i = 1; i < equation.size(); i++)
	{
		if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/' || equation[i] == '%')
		{
			operation = equation[i];
			operationLocation = i;
			break;
		}
	}
	return operationLocation;
}

void CalculatorProcessor::getOperands(Calculator* window)
{
	int operationLocation = findOperation(window);
	int findEqual = equation.find("=");
	if (answer != "" && operation == "")
	{
		answer = answer;
	}
	else if (findEqual == 0 || operationLocation == 0 || operation == "")
	{
		answer = "";
	}
	else
	{
		operation = equation[operationLocation];
		if (operationLocation + 1 == findEqual)
		{
			leftOperand = std::stoi(equation.substr(0, operationLocation));
			operation = "";
			answer = answer = std::to_string(leftOperand);
		}
		else
		{
			leftOperand = std::stoi(equation.substr(0, operationLocation));
			rightOperand = std::stoi(equation.substr(operationLocation + 1, findEqual));
		}
	}
	
}

void CalculatorProcessor::ResetOnClear(wxCommandEvent& evt)
{
	int id = evt.GetId();
	if (id == ButtonFactory::IDs::Clear)
	{
		answer = "";
		leftOperand = 0;
		rightOperand = 0;
	}
}

void CalculatorProcessor::Divide()
{
	if (rightOperand == 0)
	{
		answer = "Can't divide by zero";
	}
	else
	{
		double result =  leftOperand / rightOperand;
		answer = std::to_string(result);
	}
}

void CalculatorProcessor::Mod()
{
	double result = std::fmod(leftOperand,rightOperand);
	answer = std::to_string(result);
}


void CalculatorProcessor::Negate(Calculator* window)
{
	int operationLocation = findOperation(window);
	int posOfNegate = equation.find("FlipSign");
	if (posOfNegate == 0)
	{
		window->textBox->Clear();
	}
	else if (operationLocation + 1 == posOfNegate)
	{
		window->textBox->Clear();
		int size = equation.size();
		for (int i = 0; i < size - posOfNegate;i++)
		{
			equation.pop_back();
		}
			window->textBox->SetValue(equation);
	}
	else if (operation == "" || posOfNegate < operationLocation || operationLocation == 0)
	{
		leftOperand = std::stoi(equation.substr(0, posOfNegate));
		leftOperand *= -1;
		window->textBox->SetValue(std::to_string(leftOperand));
	}
	else if (posOfNegate > operationLocation)
	{
		leftOperand = std::stoi(equation.substr(0, operationLocation));
		rightOperand = std::stoi(equation.substr(operationLocation + 1));
		rightOperand *= -1;
		window->textBox->SetValue(std::to_string(leftOperand) +  operation + std::to_string(rightOperand));
	}
}

std::string CalculatorProcessor::Equal(Calculator* window)
{
	getOperands(window);
	if (operation == "+")
	{
		AddCommand add(leftOperand, rightOperand);
		commands.push_back((IBaseCommand*) & add);
		double a = commands[0]->Execute();
		commands.pop_back();
		answer = std::to_string(a);
	}
	else if (operation == "-")
	{
		SubtractCommand sub(leftOperand, rightOperand);
		commands.push_back((IBaseCommand*) &sub);
		double a = commands[0]->Execute();
		commands.pop_back();
		answer = std::to_string(a);
	}
	else if (operation == "*")
	{
		MultiplyCommand mult(leftOperand, rightOperand);
		commands.push_back((IBaseCommand*) &mult);
		double a = commands[0]->Execute();
		commands.pop_back();
		answer = std::to_string(a);
	}
	else if (operation == "/")
	{
		if (rightOperand == 0)
		{
			answer = "Can't divide by zero";
		}
		else
		{
			DivideCommand div(leftOperand, rightOperand);
			commands.push_back((IBaseCommand*) &div);
			double a = commands[0]->Execute();
			commands.pop_back();
			answer = std::to_string(a);
		}
		
	}
	else if (operation == "%")
	{
		Mod();
	}
	window->textBox->Clear();
	if (answer == "Can't divide by zero")
	{
		operation = "";
		return answer;
	}
	if (answer != "")
	{
		leftOperand = std::stoi(answer);
		rightOperand = NULL;
	}
	operation = "";
	return answer;
}

void CalculatorProcessor::GetDecimal(Calculator* window)
{
	window->textBox->SetValue(answer);
}

void CalculatorProcessor::GetBinary(Calculator* window)
{
	std::string result = "";
	if (answer == "")
	{
		return;
	}
	int number = std::stoi(answer);
	int mod = 0;
	for (int i = 0; i < 32; i++)
	{
		if (number % 2 == 0)
		{
			result = "0" + result;
		}
		else
		{
			result = "1" + result;
		}
		number = number / 2;
	}
	window->textBox->SetValue(result);
}

void CalculatorProcessor::GetHexadecimal(Calculator* window)
{
	std::string result = "";
	if (answer == "")
	{
		return;
	}
	int number = std::stoi(answer);
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

		number =  number / 16;
	}

	result = "0x" + result;
	window->textBox->SetValue(result);
}

