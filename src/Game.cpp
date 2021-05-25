#include "Game.h";

Game::Game()
{
}

Game::~Game()
{
	delete instance;
}

Game* Game::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Game();
	}
	return instance;
}