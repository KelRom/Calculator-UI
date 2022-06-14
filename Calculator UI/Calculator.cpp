#include "Calculator.h"

//THIS WAS ADDED. Was told not to use bind 
BEGIN_EVENT_TABLE(Calculator, wxFrame)
EVT_BUTTON(IDs::Zero, OnButtonClicked)
EVT_BUTTON(IDs::One, OnButtonClicked)
EVT_BUTTON(IDs::Two, OnButtonClicked)
EVT_BUTTON(IDs::Three, OnButtonClicked)
EVT_BUTTON(IDs::Four, OnButtonClicked)
EVT_BUTTON(IDs::Five, OnButtonClicked)
EVT_BUTTON(IDs::Six, OnButtonClicked)
EVT_BUTTON(IDs::Seven, OnButtonClicked)
EVT_BUTTON(IDs::Eight, OnButtonClicked)
EVT_BUTTON(IDs::Nine, OnButtonClicked)
EVT_BUTTON(IDs::Add, OnButtonClicked)
EVT_BUTTON(IDs::Sub, OnButtonClicked)
EVT_BUTTON(IDs::Mult, OnButtonClicked)
EVT_BUTTON(IDs::Div, OnButtonClicked)
EVT_BUTTON(IDs::Mod, OnButtonClicked)
EVT_BUTTON(IDs::Hex, OnButtonClicked)
EVT_BUTTON(IDs::Bin, OnButtonClicked)
EVT_BUTTON(IDs::Dec, OnButtonClicked)
EVT_BUTTON(IDs::Clear, OnButtonClicked)
EVT_BUTTON(IDs::FlipSign, OnButtonClicked)
EVT_BUTTON(IDs::Equal, OnButtonClicked)
END_EVENT_TABLE()

Calculator::Calculator() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 300), wxSize(400, 500), (wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)))
{
	sizerHolder = new wxBoxSizer(wxVERTICAL);
	textBox = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(0, 0), wxSize(windowWidth, 100), wxTE_BESTWRAP | wxTE_RIGHT | wxTE_READONLY | wxTE_NO_VSCROLL);
	
	clearButton = new wxButton(this, IDs::Clear, "CLEAR", wxDefaultPosition, wxSize(buttonWidth * 2 - 3, buttonHeight));
	buttons = new wxButton * [rows * cols];
	grid = new wxGridSizer(rows, cols, 0, 0);

	// pos will be used to determine what index we are in for the buttons array and the ID of the buttons.
	int pos = 0;
	int id = IDs::One;
	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < cols; y++)
		{
			pos = y * rows + x;
			buttons[pos] = new wxButton(this, id + pos, wxEmptyString, wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
			//buttons[pos]->Bind(pos, &Calculator::OnButtonClicked);  FROM ORIGINAL LOGIC
			grid->Add(buttons[pos], 1, wxEXPAND | wxALL);
		}
	}

	//settings labels for the numbers. 12 is the number of buttons for one to nine plus the buttons on the bottom row.
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

	//THIS WAS ADDED
	setbuttonLabels();

	//adding items to he main sizer and then setting the layout for the window
	sizerHolder->Add(textBox);
	
	sizerHolder->Add(clearButton, 0, wxALIGN_RIGHT);
	sizerHolder->Add(grid);
	SetSizer(sizerHolder);
	sizerHolder->Layout();
	
}

Calculator::~Calculator()
{
	delete[] buttons;
}

void Calculator::OnButtonClicked(wxCommandEvent& evt)
{
	int id = evt.GetId();

	if (id == IDs::Clear)
	{
		textBox->Clear();
	}
	else
	{
		*textBox << buttons[id]->GetLabel();
	}
}

//THIS WAS ADDED
void Calculator::setbuttonLabels()
{
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
}

