#include "IDrawable.h"

IDrawable::IDrawable()
{
	m_src.x = m_src.y = 0;
	m_dest.x = m_dest.y = 0;
	m_dest.h = m_dest.w = 64;
}

IDrawable::IDrawable(std::string path, SDL_Renderer* ren) : IDrawable()
{
	m_texture = getTexture(path, ren);
}

IDrawable::~IDrawable()
{
	SDL_DestroyTexture(m_texture);
}

void IDrawable::init(std::string path, SDL_Renderer* ren, unsigned int heightPixels, unsigned int widthPixels)
{
	m_src.x = 0;
	m_src.y = 0;
	SDL_Surface* sur = IMG_Load(path.c_str());
	m_src.h = sur->h;
	m_src.w = sur->w;
	m_dest.h = heightPixels;
	m_dest.w = widthPixels;
	m_texture = getTexture(path, ren);
}

SDL_Texture* IDrawable::getTexture(std::string path, SDL_Renderer* ren)
{
	SDL_Surface* sur = IMG_Load(path.c_str());

	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, sur);

	SDL_FreeSurface(sur);
	return tex;
}

void IDrawable::setTexture(SDL_Texture* texture)
{
	this->m_texture = texture;
}

void IDrawable::setSrcRect(SDL_Rect* src)
{
	this->m_src = *src;
}

void IDrawable::setDestRect(SDL_Rect* dest)
{
	this->m_dest = *dest;
}

SDL_Texture* IDrawable::getTexture()
{
	return m_texture;
}

SDL_Rect* IDrawable::getSrcRect()
{
	return &m_src;
}
SDL_Rect* IDrawable::getDestRect()
{
	return &m_dest;
}

void IDrawable::draw(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, m_texture, &m_src, &m_dest);
}

void IDrawable::draw(SDL_Renderer* ren, SDL_Rect* dest)
{
	SDL_RenderCopy(ren, m_texture, &m_src, dest);
}