#pragma once
#include "IBaseCommand.h"
class AddCommand : IBaseCommand
{
private:
	double _x = 0;
	double _y = 0;
public:
	AddCommand(double x, double y);
	double Add();
	double Execute();
};

