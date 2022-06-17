#include "Calculator.h"
#include "ButtonFactory.h"

Calculator::Calculator() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 300), wxSize(400, 500), (wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)))
{
	sizerHolder = new wxBoxSizer(wxVERTICAL);
	textBox = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(0, 0), wxSize(windowWidth, 100), wxTE_BESTWRAP | wxTE_RIGHT | wxTE_READONLY | wxTE_NO_VSCROLL);
	buttonMaker = new ButtonFactory();
	wxButton* clearButton = buttonMaker->createClearButton(this);
	grid = new wxGridSizer(rows, cols, 0, 0);

	allButtons = buttonMaker->createAllButtons(this);
	for (size_t i = 0; i < allButtons.size(); i++)
	{
		grid->Add(allButtons[i], 1, wxEXPAND | wxALL);
	}

	//adding items to he main sizer and then setting the layout for the window
	sizerHolder->Add(textBox);
	sizerHolder->Add(clearButton, 0, wxALIGN_RIGHT);
	sizerHolder->Add(grid);
	SetSizer(sizerHolder);
	sizerHolder->Layout();
	
}

Calculator::~Calculator()
{
	delete buttonMaker;
}

void Calculator::OnButtonClicked(wxCommandEvent& evt)
{
	int id = evt.GetId();

	if (id == ButtonFactory::IDs::Clear)
	{
		textBox->Clear();
	}
	else
	{
		*textBox << allButtons[id]->GetLabel();
	}
}
