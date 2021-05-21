#pragma once

#include "GameObject.h"
#include "IMoveable.h"
#include "IDrawable.h"
#include "SnakeBodyPart.h"

#include <vector>
#include <memory>

class Snake : public IMoveable, public IDrawable
{
public:
	Snake();
	Snake(const SDL_Rect& position);
	~Snake();

	void move() override;
	void draw(SDL_Renderer* ren) override;
private:
	std::vector<std::unique_ptr<SnakeBodyPart>> bodyParts;
};