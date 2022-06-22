#include "Calculator.h"
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"

Calculator::Calculator() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 300), wxSize(400, 500), (wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)))
{
	processor = CalculatorProcessor::GetInstance();
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
	delete processor;
}

void Calculator::OnButtonClicked(wxCommandEvent& evt)
{
	int id = evt.GetId();
	if (processor->answer == "Can't divide by zero")
	{
		textBox->Clear();
		enableButtons = true;
		EnableButtons();
		processor->answer = "";
	}
	if (id == ButtonFactory::IDs::Clear)
	{
		textBox->Clear();
		enableButtons = true;
		EnableButtons();
		processor->ResetOnClear(evt);
	}
	
	else if (id == ButtonFactory::IDs::Equal)
	{
		*textBox << processor->Equal(this);
		enableButtons = true;
		EnableButtons();
	
	}
	else if (id != ButtonFactory::IDs::Hex &&
			 id != ButtonFactory::IDs::Bin &&
			 id != ButtonFactory::IDs::Dec &&
			 id != ButtonFactory::IDs::FlipSign)
	{
		*textBox << allButtons[id]->GetLabel();
		//Disable all the operations button so the only option left to press is =. This is a restriction to avoid multiple operations at once, avoid PEMDAS and avoid errors
		if (id == ButtonFactory::IDs::Add || id == ButtonFactory::IDs::Sub || id == ButtonFactory::IDs::Mult || id == ButtonFactory::IDs::Div || id == ButtonFactory::IDs::Mod)
		{
			enableButtons = false;
			EnableButtons();
		}
	}
	else if (id == ButtonFactory::IDs::Hex)
	{
		processor->GetHexadecimal(this);
	}
	else if (id == ButtonFactory::IDs::Bin)
	{
		processor->GetBinary(this);
	}
	else if (id == ButtonFactory::IDs::Dec)
	{
		processor->GetDecimal(this);
	}
	else if (id == ButtonFactory::IDs::FlipSign)
	{
		*textBox << allButtons[id]->GetLabel();
		processor->Negate(this);
	}
}
void Calculator::EnableButtons()
{
	if (enableButtons)
	{
		allButtons[ButtonFactory::IDs::Add]->Enable();
		allButtons[ButtonFactory::IDs::Sub]->Enable();
		allButtons[ButtonFactory::IDs::Mult]->Enable();
		allButtons[ButtonFactory::IDs::Div]->Enable();
		allButtons[ButtonFactory::IDs::Mod]->Enable();
	}
	else
	{
		allButtons[ButtonFactory::IDs::Add]->Disable();
		allButtons[ButtonFactory::IDs::Sub]->Disable();
		allButtons[ButtonFactory::IDs::Mult]->Disable();
		allButtons[ButtonFactory::IDs::Div]->Disable();
		allButtons[ButtonFactory::IDs::Mod]->Disable();
	}
	
}