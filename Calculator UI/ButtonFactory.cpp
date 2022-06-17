#include "ButtonFactory.h"

BEGIN_EVENT_TABLE(Calculator, wxFrame)
EVT_BUTTON(ButtonFactory::IDs::Zero, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::One, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Two, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Three, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Four, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Five, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Six, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Seven, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Eight, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Nine, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Add, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Sub, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Mult, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Div, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Mod, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Hex, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Bin, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Dec, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Clear, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::FlipSign, OnButtonClicked)
EVT_BUTTON(ButtonFactory::IDs::Equal, OnButtonClicked)
END_EVENT_TABLE()


std::vector<wxButton*> ButtonFactory::createAllButtons(wxWindow* callingWindow)
{
	std::vector<wxButton*> allButtons;
	allButtons.push_back(createOneButton(callingWindow));
	allButtons.push_back(createTwoButton(callingWindow));
	allButtons.push_back(createThreeButton(callingWindow));
	allButtons.push_back(createDivideButton(callingWindow));
	allButtons.push_back(createModulusButton(callingWindow));
	allButtons.push_back(createFourButton(callingWindow));
	allButtons.push_back(createFiveButton(callingWindow));
	allButtons.push_back(createSixButton(callingWindow));
	allButtons.push_back(createMultiplyButton(callingWindow));
	allButtons.push_back(createDecButton(callingWindow));
	allButtons.push_back(createSevenButton(callingWindow));
	allButtons.push_back(createEightButton(callingWindow));
	allButtons.push_back(createNineButton(callingWindow));
	allButtons.push_back(createMinusButton(callingWindow));
	allButtons.push_back(createHexButton(callingWindow));
	allButtons.push_back(createNegateButton(callingWindow));
	allButtons.push_back(createZeroButton(callingWindow));
	allButtons.push_back(createEqualButton(callingWindow));
	allButtons.push_back(createPlusButton(callingWindow));
	allButtons.push_back(createBinButton(callingWindow));
	return allButtons;
}

ButtonFactory::ButtonFactory()
{}

ButtonFactory::~ButtonFactory()
{}

wxButton* ButtonFactory::createOneButton(wxWindow* callingWindow)
{
	wxButton* oneButton = new wxButton(callingWindow, IDs::One, "1", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return oneButton;
}

wxButton* ButtonFactory::createTwoButton(wxWindow* callingWindow)
{
	wxButton* twoButton = new wxButton(callingWindow, IDs::Two, "2", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return twoButton;
}

wxButton* ButtonFactory::createThreeButton(wxWindow* callingWindow)
{
	wxButton* threeButton = new wxButton(callingWindow, IDs::Three, "3", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return threeButton;
}

wxButton* ButtonFactory::createFourButton(wxWindow* callingWindow)
{
	wxButton* fourButton = new wxButton(callingWindow, IDs::Four, "4", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return fourButton;
}

wxButton* ButtonFactory::createFiveButton(wxWindow* callingWindow)
{
	wxButton* fiveButton = new wxButton(callingWindow, IDs::Five, "5", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return fiveButton;
}

wxButton* ButtonFactory::createSixButton(wxWindow* callingWindow)
{
	wxButton* sixButton = new wxButton(callingWindow, IDs::Six, "6", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return sixButton;
}

wxButton* ButtonFactory::createSevenButton(wxWindow* callingWindow)
{
	wxButton* sevenButton = new wxButton(callingWindow, IDs::Seven, "7", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return sevenButton;
}

wxButton* ButtonFactory::createEightButton(wxWindow* callingWindow)
{
	wxButton* eightButton = new wxButton(callingWindow, IDs::Eight, "8", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return eightButton;
}

wxButton* ButtonFactory::createNineButton(wxWindow* callingWindow)
{
	wxButton* nineButton = new wxButton(callingWindow, IDs::Nine, "9", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return nineButton;
}

wxButton* ButtonFactory::createZeroButton(wxWindow* callingWindow)
{
	wxButton* zeroButton = new wxButton(callingWindow, IDs::Zero, "0", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return zeroButton;
}

wxButton* ButtonFactory::createNegateButton(wxWindow* callingWindow)
{
	wxButton* negateButton = new wxButton(callingWindow, IDs::FlipSign, "+/-", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return negateButton;
}

wxButton* ButtonFactory::createEqualButton(wxWindow* callingWindow)
{
	wxButton* equalButton = new wxButton(callingWindow, IDs::Equal, "=", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return equalButton;
}

wxButton* ButtonFactory::createHexButton(wxWindow* callingWindow)
{
	wxButton* hexButton = new wxButton(callingWindow, IDs::Hex, "HEX", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return hexButton;
}

wxButton* ButtonFactory::createBinButton(wxWindow* callingWindow)
{
	wxButton* binButton = new wxButton(callingWindow, IDs::Bin, "BIN", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return binButton;
}

wxButton* ButtonFactory::createDecButton(wxWindow* callingWindow)
{
	wxButton* decButton = new wxButton(callingWindow, IDs::Dec, "DEC", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return decButton;
}

wxButton* ButtonFactory::createPlusButton(wxWindow* callingWindow)
{
	wxButton* plusButton = new wxButton(callingWindow, IDs::Add, "+", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return plusButton;
}

wxButton* ButtonFactory::createMinusButton(wxWindow* callingWindow)
{
	wxButton* subButton = new wxButton(callingWindow, IDs::Sub, "-", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return subButton;
}

wxButton* ButtonFactory::createMultiplyButton(wxWindow* callingWindow)
{
	wxButton* multButton = new wxButton(callingWindow, IDs::Mult, "*", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return multButton;
}

wxButton* ButtonFactory::createDivideButton(wxWindow* callingWindow)
{
	wxButton* divButton = new wxButton(callingWindow, IDs::Div, "/", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return divButton;
}

wxButton* ButtonFactory::createModulusButton(wxWindow* callingWindow)
{
	wxButton* modButton = new wxButton(callingWindow, IDs::Mod, "MOD", wxDefaultPosition, wxSize(buttonWidth, buttonHeight));
	return modButton;
}

wxButton* ButtonFactory::createClearButton(wxWindow* callingWindow)
{
	wxButton* clearButton = new wxButton(callingWindow, IDs::Clear, "Clear", wxDefaultPosition, wxSize(buttonWidth * 2, buttonHeight));
	return clearButton;
}
