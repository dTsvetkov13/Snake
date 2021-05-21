#include "GameObject.h"

GameObject::GameObject()
{
	this->m_rect = SDL_Rect();
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
	this->m_rect.x = rect.x;
	this->m_rect.y = rect.y;
	this->m_rect.h = rect.h;
	this->m_rect.w = rect.w;
}

SDL_Rect* GameObject::getRect()
{
	return &this->m_rect;
}

bool GameObject::intersects(const SDL_Rect& rect)
{
	return (this->m_rect.x < (rect.x + rect.w)
			&& (this->m_rect.x + this->m_rect.w) > rect.x
			&& this->m_rect.y < (rect.y + rect.h)
			&& (this->m_rect.y + this->m_rect.h) > rect.y);
}