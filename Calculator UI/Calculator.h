#pragma once
#include "wx/wx.h"
class Calculator : public wxFrame
{
private:
	int rows = 4;
	int cols = 5;
	int buttonWidth = 80;
	int buttonHeight = 75;
	int windowWidth = 400;
	int windowHeight = 500;
public:
	Calculator();
	~Calculator();
	wxBoxSizer* sizerHolder = nullptr;
	wxTextCtrl* textBox = nullptr;
	wxGridSizer* grid = nullptr;
	wxButton** buttons;
	wxButton* clearButton;
	void OnButtonClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

