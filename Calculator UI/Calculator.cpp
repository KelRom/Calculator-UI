#include "Calculator.h"
Calculator::Calculator() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 300), wxSize(400, 500), (wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)))
{
	sizerHolder = new wxBoxSizer(wxVERTICAL);
	textBox = new wxTextCtrl(this, 1, wxEmptyString, wxPoint(0, 0), wxSize(windowWidth, 100), wxTE_BESTWRAP | wxTE_RIGHT | wxTE_READONLY);
	buttons = new wxButton * [rows * cols];
	grid = new wxGridSizer(rows, cols, 0, 0);

	// pos will be used to determine what index we are in for the buttons array and the ID of the buttons.
	int pos = 0;
	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < cols; y++)
		{
			pos = y * rows + x;
			buttons[pos] = new wxButton(this, 11 + pos, wxEmptyString, wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
			grid->Add(buttons[pos], 1, wxEXPAND | wxALL);
		}
	}

	//settings labels for the numbers 12 is the number of buttons for one to nine plus the buttons on the bottom row.
	int label = 1;
	for (int i = 0; i < 12; i++)
	{
		if (i % 4 == 0 && i == 0)
		{
			buttons[i]->SetLabel(std::to_string(label));
		}
		else if (i % 4 == 0)
		{
			label -= 5;
			buttons[i]->SetLabel(std::to_string(label));
		}
		else if (i % 4 < 3)
		{
			label += 3;
			buttons[i]->SetLabel(std::to_string(label));
		}
	}

	//setting the remainder of the buttons that are not numbers and the 0 button.
	buttons[3]->SetLabel("+/-");
	buttons[7]->SetLabel("0");
	buttons[11]->SetLabel("=");
	buttons[12]->SetLabel("/");
	buttons[13]->SetLabel("*");
	buttons[14]->SetLabel("-");
	buttons[15]->SetLabel("+");
	buttons[16]->SetLabel("MOD");
	buttons[17]->SetLabel("DEC");
	buttons[18]->SetLabel("HEX");
	buttons[19]->SetLabel("BIN");

	sizerHolder->Add(textBox);
	sizerHolder->Add(new wxButton(this, 10, "CLEAR", wxDefaultPosition, wxSize(buttonWidth * 2 - 3, buttonHeight)), 0, wxALIGN_RIGHT);
	sizerHolder->Add(grid);
	SetSizer(sizerHolder);
	sizerHolder->Layout();
	
}

Calculator::~Calculator()
{
	delete[] buttons;
}
