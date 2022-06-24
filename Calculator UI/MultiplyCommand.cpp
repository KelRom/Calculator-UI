#include "MultiplyCommand.h"

MultiplyCommand::MultiplyCommand(double x, double y) : _x(x), _y(y)
{}

double MultiplyCommand::Multiply()
{
	return _x * _y;
}

double MultiplyCommand::Execute()
{
	return Multiply();
}