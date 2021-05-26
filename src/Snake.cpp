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

void Snake::increaseBody()
{
	this->bodyParts.push_back(std::make_unique<SnakeBodyPart>
								(newBodyPart(*bodyParts.back().get())));
}

std::unique_ptr<SnakeBodyPart> const& Snake::getHead()
{
	return bodyParts[0];
}

void Snake::move()
{
	for (int i = 1; i < bodyParts.size(); i++)
	{
		bodyParts[i]->setRect(*bodyParts[i-1].get()->getRect());
	}

	bodyParts[0]->move();
}

void Snake::draw(SDL_Renderer* ren)
{
	for (const auto& bodyPart : bodyParts)
	{
		bodyPart->draw(ren);
	}
}

SnakeBodyPart Snake::newBodyPart(SnakeBodyPart& previousBodyPart)
{
	SnakeBodyPart result = SnakeBodyPart();
	SDL_Rect rect = SDL_Rect();
	rect.h = previousBodyPart.getRect()->h;
	rect.w = previousBodyPart.getRect()->w;
	
	switch (previousBodyPart.getDirection())
	{
		case(Direction::North):
		{
			rect.x = previousBodyPart.getRect()->x;
			rect.y = previousBodyPart.getRect()->y - rect.h;
			break;
		}
		case(Direction::East):
		{
			rect.x = previousBodyPart.getRect()->x - rect.w;
			rect.y = previousBodyPart.getRect()->y;
			break;
		}
		case(Direction::South):
		{
			rect.x = previousBodyPart.getRect()->x;
			rect.y = previousBodyPart.getRect()->y + rect.h;
			break;
		}
		case(Direction::West):
		{
			rect.x = previousBodyPart.getRect()->x + rect.w;
			rect.y = previousBodyPart.getRect()->y;
			break;
		}
		default:
			break;
	}

	result.setRect(rect);
	result.setDirection(previousBodyPart.getDirection());
	return result;
}