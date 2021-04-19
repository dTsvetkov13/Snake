#pragma once

struct Position
{
	double x = 0;
	double y = 0;

	Position(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
};

class GameObject
{
public:
	GameObject();
private:
	Position position;
};