#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(const Position &position)
{
	this->position = Position(position.x, position.y);
}

void GameObject::setPosition(const Position& position)
{
	this->position.x = position.x;
	this->position.y = position.y;
}