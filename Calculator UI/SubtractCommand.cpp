#include "SubtractCommand.h"

SubtractCommand::SubtractCommand(double x, double y) : _x(x), _y(y)
{}

double SubtractCommand::Subtract()
{
	return _x - _y;
}

double SubtractCommand::Execute()
{
	return Subtract();
}