#include "SnakeBodyPart.h"

SnakeBodyPart::SnakeBodyPart() : IMoveable()
{
}

SnakeBodyPart::SnakeBodyPart(const SDL_Rect& rect)
	: SnakeBodyPart()
{
	this->setRect(rect);
}

SnakeBodyPart::SnakeBodyPart(SDL_Renderer* ren)
	: SnakeBodyPart()
{
	this->init("../assets/snake-body-part.png", ren, 32, 32);
}

SnakeBodyPart::~SnakeBodyPart()
{
}

void SnakeBodyPart::move()
{

}