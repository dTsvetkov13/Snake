#pragma once

#include "IDrawable.h"
#include "IMoveable.h"

class SnakeBodyPart : public IMoveable, public IDrawable
{
public:
	SnakeBodyPart();
	SnakeBodyPart(const SDL_Rect& rect);
	SnakeBodyPart(SDL_Renderer* ren);
	~SnakeBodyPart();

	void move() override;
};