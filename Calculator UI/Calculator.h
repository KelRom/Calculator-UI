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
	int id[5] = { 0, 1, 2, 3 };
	Calculator();
	~Calculator();
	wxBoxSizer* sizerHolder = nullptr;
	wxTextCtrl* textBox = nullptr;
	wxGridSizer* grid = nullptr;
	wxButton** buttons;
	wxButton* clearButton;
	void OnButtonClicked(wxCommandEvent& evt);
	void setbuttonLabels();
	wxDECLARE_EVENT_TABLE();
};

enum IDs
{
	One,
	Two,
	Three,
	Div,
	Mod,
	Four,
	Five,
	Six,
	Mult,
	Dec,
	Seven,
	Eight,
	Nine,
	Sub,
	Hex,
	FlipSign,
	Zero,
	Equal,
	Add,
	Bin,
	Clear
};
