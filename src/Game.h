#pragma once

#include "SDL.h"
#include "World.h"

class Game
{
public:
	~Game();

	static Game* getInstance();

	void init(const char* title, int x, int y, int width, int height, bool fullscreen);
	
	void handleEvent();
	void update();
	void render();
	void clean();

	inline bool running() { return m_isRunning; }
private:
	Game();
	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	static Game* m_instance;

	World m_world;
	SDL_Window* m_window;
	bool m_isRunning = false;
	SDL_Renderer* m_renderer;
};