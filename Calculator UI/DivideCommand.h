#pragma once
#include "IBaseCommand.h"
class DivideCommand : IBaseCommand
{
private:
	double _x = 0;
	double _y = 0;
public:
	DivideCommand(double x, double y);
	double Divide();
	double Execute();
};

