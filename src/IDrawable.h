#pragma once

#include "SDL.h"

class IDrawable
{
public:
	virtual void draw() = 0;
private:
	SDL_Texture* texture;
	SDL_Rect src, dest;
};