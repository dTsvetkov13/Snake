#pragma once

#include "SDL.h"

class GameObject
{
public:
	GameObject();
	GameObject(const SDL_Rect& position);
	~GameObject();

	void setRect(const SDL_Rect& position);
	SDL_Rect* getRect();

	virtual bool intersects(const SDL_Rect& rect);
private:
	SDL_Rect m_rect;
};