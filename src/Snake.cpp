#include "Snake.h"

Snake::Snake() : IMoveable()
{
}

Snake::Snake(const SDL_Rect& rect)
	: IMoveable()
{
	this->setRect(rect);
}

Snake::~Snake()
{
}

void Snake::move()
{
	for (int i = 1; i < bodyParts.size(); i++)
	{
		bodyParts[i]->setRect(*bodyParts[i-1].get()->getRect());
	}
}

void Snake::draw(SDL_Renderer* ren)
{
	for (const auto& bodyPart : bodyParts)
	{
		bodyPart->draw(ren);
	}
}