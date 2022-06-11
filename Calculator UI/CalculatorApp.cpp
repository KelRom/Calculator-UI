#include "CalculatorApp.h"

wxIMPLEMENT_APP(CalculatorApp);
CalculatorApp::CalculatorApp()
{}

CalculatorApp::~CalculatorApp()
{}

bool CalculatorApp::OnInit()
{
	calculator = new Calculator();
	calculator->Show();
	return true;
}
