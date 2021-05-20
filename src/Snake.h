#pragma once

#include "GameObject.h"
#include "IMoveable.h"

class Snake : public GameObject, public IMoveable
{
public:
	Snake();
	Snake(const Position& position);

	void move() override;
private:
	
};