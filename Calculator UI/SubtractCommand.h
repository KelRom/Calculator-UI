#pragma once
#include "IBaseCommand.h"
class SubtractCommand : IBaseCommand
{
private:
	double _x = 0;
	double _y = 0;
public:
	SubtractCommand(double x, double y);
	double Subtract();
	double Execute();
};


