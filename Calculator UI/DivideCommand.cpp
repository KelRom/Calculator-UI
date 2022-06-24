#include "DivideCommand.h"

DivideCommand::DivideCommand(double x, double y) : _x(x), _y(y)
{}

double DivideCommand::Divide()
{
	return _x / _y;
}

double DivideCommand::Execute()
{
	return Divide();
}