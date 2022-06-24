#include "CppUnitTest.h"
#include "../Calculator UI/ButtonFactory.h"
#include "wx/wx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUITests
{
	TEST_CLASS(ButtonFactoryTests)
	{
	public:
		wxFrame* frame = new wxFrame();
		ButtonFactory* buttonMaker = new ButtonFactory();

		TEST_METHOD(OneButtonIdIsZero)
		{
			//0 is the id for ButtonFactory::IDs::One
			wxButton* oneButton = buttonMaker->createOneButton(frame);
			Assert::AreEqual(oneButton->GetId(), 0);
		}

		TEST_METHOD(TheSizeOfTheButtonsVectorIs20)
		{
			std::vector<wxButton*> allButtons = buttonMaker->createAllButtons(frame);
			Assert::AreEqual(allButtons.size(), (size_t) 20);
		}

		TEST_METHOD(TheBinaryButtonsLabelShouldBeBIN)
		{
			wxButton* binaryButton = buttonMaker->createBinButton(frame);
			Assert::AreEqual("BIN", binaryButton->GetLabel());
		}

		TEST_METHOD(AllButtonsIndex10WithIdOf10)
		{
			//10 is the id for the seven button
			std::vector<wxButton*> allButtons = buttonMaker->createAllButtons(frame);
			Assert::AreEqual(allButtons[10]->GetId(), 10);
		};

		TEST_METHOD(NineButtonShouldNotHaveLabelof10)
		{
			wxButton* nineButton = buttonMaker->createNineButton(frame);
			Assert::AreNotEqual(nineButton->GetLabel(), "10");
		};

		TEST_METHOD(ModButtonLabelIsThePercentOrModuloSign)
		{
			wxButton* modButton = buttonMaker->createModulusButton(frame);
			Assert::AreEqual(modButton->GetLabel(), "%");
		};

		TEST_METHOD(ThreeButtonHasAnIdOf2)
		{
			//2 is the id for the three button
			wxButton* threeButton = buttonMaker->createThreeButton(frame);
			Assert::AreEqual(threeButton->GetId(), 2);
		};
		TEST_METHOD(HexButtonShouldNotHaveLabelOfBIN)
		{
			wxButton* hexButton = buttonMaker->createHexButton(frame);
			Assert::AreNotEqual(hexButton->GetLabel(), "BIN");
		};

		TEST_METHOD(HexButtonShouldNotHaveLabelofDEC)
		{
			wxButton* hexButton = buttonMaker->createHexButton(frame);
			Assert::AreNotEqual(hexButton->GetLabel(), "DEC");
		};

		TEST_METHOD(BinButtonHasAnIDof9)
		{
			//9 is the id for the decimalButton
			wxButton* decButton = buttonMaker->createDecButton(frame);
			Assert::AreEqual(decButton->GetId(), 9);
		};
	};
}