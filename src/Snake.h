#pragma once

#include "SnakeBodyPart.h"

#include <vector>
#include <memory>

class Snake : public IMoveable, public IDrawable
{
public:
	Snake();
	Snake(const SDL_Rect& rect);
	~Snake();

	void increaseBody();
	std::unique_ptr<SnakeBodyPart> const& getHead();

	void move() override;
	void draw(SDL_Renderer* ren) override;
private:
	std::vector<std::unique_ptr<SnakeBodyPart>> bodyParts;

	SnakeBodyPart newBodyPart(SnakeBodyPart& previousBodyPart);
};