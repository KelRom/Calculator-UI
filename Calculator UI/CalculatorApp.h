#pragma once
#include "wx/wx.h"
#include "Calculator.h"
class CalculatorApp : public wxApp
{
public:
	CalculatorApp();
	~CalculatorApp();
	virtual bool OnInit();

private:
	Calculator* calculator = nullptr;
};

