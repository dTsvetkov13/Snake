#pragma once

#include "GameObject.h"

enum class Direction
{
	West,
	East,
	South,
	North
};

class IMoveable : public GameObject
{
public:
	IMoveable();
	IMoveable(Direction direction, double speed);

	void setDirection(Direction direction);
	void setSpeed(double speed);

	inline Direction getDirection() { return this->direction; }
	inline double getSpeed() { return this->speed; }

	virtual void move() = 0;
private:
	double speed;
	Direction direction;
};