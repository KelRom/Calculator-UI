#pragma once
#include "wx/wx.h"
#include "CalculatorProcessor.h"

class ButtonFactory;
class CalculatorProcessor;
class Calculator : public wxFrame
{
private:
	int rows = 4;
	int cols = 5;
	int windowWidth = 400;
	int windowHeight = 500;
	ButtonFactory* buttonMaker;
	std::vector<wxButton*> allButtons;
	wxButton* clearButton = nullptr;
	wxGridSizer* grid = nullptr;
	wxBoxSizer* sizerHolder = nullptr;
	CalculatorProcessor* processor;

public:
	Calculator();
	~Calculator();
	wxTextCtrl* textBox = nullptr;
	

	void OnButtonClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};


