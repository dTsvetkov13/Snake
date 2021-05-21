#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <string>

class IDrawable
{
public:
	IDrawable();
	IDrawable(std::string path, SDL_Renderer* ren);
	~IDrawable();

	void init(std::string path, SDL_Renderer* ren, unsigned int heightParts, unsigned int widthParts);
	static SDL_Texture* getTexture(std::string path, SDL_Renderer* ren);

	void setDestRect(SDL_Rect* dest);

	SDL_Texture* getTexture();
	SDL_Rect* getSrcRect();
	SDL_Rect* getDestRect();

	virtual void draw(SDL_Renderer* ren);
	virtual void draw(SDL_Renderer* ren, SDL_Rect* dest);
private:
	SDL_Texture* m_texture;
	SDL_Rect m_src, m_dest;
};