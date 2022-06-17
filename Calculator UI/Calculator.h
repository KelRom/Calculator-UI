#pragma once
#include "wx/wx.h"

class ButtonFactory;
class Calculator : public wxFrame
{
private:
	int rows = 4;
	int cols = 5;
	int windowWidth = 400;
	int windowHeight = 500;
	ButtonFactory* buttonMaker;
public:
	int id[5] = { 0, 1, 2, 3 };
	Calculator();
	~Calculator();
	wxBoxSizer* sizerHolder = nullptr;
	wxTextCtrl* textBox = nullptr;
	
	wxGridSizer* grid = nullptr;
	std::vector<wxButton*> allButtons;
	wxButton* clearButton = nullptr;
	void OnButtonClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};


