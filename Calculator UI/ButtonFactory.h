#pragma once
#include "wx/wx.h"
#include "Calculator.h"
class ButtonFactory
{
private:
	int buttonWidth = 80;
	int buttonHeight = 75;
public:
	ButtonFactory();
	~ButtonFactory();
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

std::vector<wxButton*> createAllButtons(wxWindow* callingWindow);
wxButton* createOneButton(wxWindow* callingWindow);
wxButton* createTwoButton(wxWindow* callingWindow);
wxButton* createThreeButton(wxWindow* callingWindow);
wxButton* createFourButton(wxWindow* callingWindow);
wxButton* createFiveButton(wxWindow* callingWindow);
wxButton* createSixButton(wxWindow* callingWindow);
wxButton* createSevenButton(wxWindow* callingWindow);
wxButton* createEightButton(wxWindow* callingWindow);
wxButton* createNineButton(wxWindow* callingWindow);
wxButton* createZeroButton(wxWindow* callingWindow);
wxButton* createNegateButton(wxWindow* callingWindow);
wxButton* createEqualButton(wxWindow* callingWindow);
wxButton* createHexButton(wxWindow* callingWindow);
wxButton* createBinButton(wxWindow* callingWindow);
wxButton* createDecButton(wxWindow* callingWindow);
wxButton* createPlusButton(wxWindow* callingWindow);
wxButton* createMinusButton(wxWindow* callingWindow);
wxButton* createMultiplyButton(wxWindow* callingWindow);
wxButton* createDivideButton(wxWindow* callingWindow);
wxButton* createModulusButton(wxWindow* callingWindow);
wxButton* createClearButton(wxWindow* callingWindow);

};

