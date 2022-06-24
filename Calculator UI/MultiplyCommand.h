#pragma once
#include "IBaseCommand.h"
class MultiplyCommand : IBaseCommand
{
private:
	double _x = 0;
	double _y = 0;
public:
	MultiplyCommand(double x, double y);
	double Multiply();
	double Execute();
};

