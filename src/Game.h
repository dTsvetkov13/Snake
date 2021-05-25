#pragma once

#include "SDL.h"

class Game
{
public:
	~Game();

	static Game* getInstance();

private:
	Game();
	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	static Game* instance;

	SDL_Renderer* renderer;
};