#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(const Position &position)
{
	this->position = Position(position.x, position.y);
}