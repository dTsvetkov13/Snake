#include "IMoveable.h"

IMoveable::IMoveable() : IMoveable(Direction::North, 0)
{
}

IMoveable::IMoveable(Direction direction, double speed)
{
	this->setDirection(direction);
	this->setSpeed(speed);
}

void IMoveable::setDirection(Direction direction)
{
	this->direction == direction;
}

void IMoveable::setSpeed(double speed)
{
	this->speed = speed;
}