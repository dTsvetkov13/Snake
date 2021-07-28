#include "Game.h";
#include <iostream>

Game* Game::m_instance = nullptr;

Game::Game()
{
}

Game::~Game()
{
	delete m_renderer;
	delete m_window;
	delete m_instance;
}

Game* Game::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new Game();
	}
	return m_instance;
}

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Initilize\n";

		m_window = SDL_CreateWindow(title, x, y, width, height, flags);
		m_renderer = SDL_CreateRenderer(m_window, -1, 0);

		SDL_SetWindowTitle(m_window, title);

		int x1, y1;

		SDL_GetWindowPosition(m_window, &x1, &y1);

		if (m_renderer)
		{
			SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
			SDL_RenderPresent(m_renderer);
		}

		m_isRunning = true;
	}
	else
	{
		m_isRunning = false;
	}
}

void Game::handleEvent()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		m_isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{

}

void Game::render()
{

}

void Game::clean()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}