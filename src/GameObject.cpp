#include "GameObject.h"

GameObject::GameObject()
{
	this->rect = SDL_Rect();
}

GameObject::GameObject(const SDL_Rect& rect) : GameObject()
{
	this->setRect(rect);
}

GameObject::~GameObject()
{
}

void GameObject::setRect(const SDL_Rect& rect)
{
	this->rect.x = rect.x;
	this->rect.y = rect.y;
	this->rect.h = rect.h;
	this->rect.w = rect.w;
}

bool GameObject::intersects(const SDL_Rect& rect)
{
	return (this->rect.x < (rect.x + rect.w)
			&& (this->rect.x + this->rect.w) > rect.x
			&& this->rect.y < (rect.y + rect.h)
			&& (this->rect.y + this->rect.h) > rect.y);
}