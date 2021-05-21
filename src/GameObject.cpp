#include "GameObject.h"

GameObject::GameObject()
{
	this->rect = SDL_Rect();
}

GameObject::GameObject(const SDL_Rect& rect) : GameObject()
{
	this->setRect(rect);
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
	return false;
}