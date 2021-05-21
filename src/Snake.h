#pragma once

#include "GameObject.h"
#include "IMoveable.h"
#include "IDrawable.h"

class Snake : public GameObject, public IMoveable, public IDrawable
{
public:
	Snake();
	Snake(const Position& position);

	void move() override;
	void draw(SDL_Renderer* ren) override;
private:
	 
};