#pragma once

#include "SDL.h"

class GameObject
{
public:
	GameObject();
	GameObject(const SDL_Rect& position);

	void setRect(const SDL_Rect& position);
	virtual bool intersects(const SDL_Rect& rect);
private:
	SDL_Rect rect;
};