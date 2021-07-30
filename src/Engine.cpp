#include "Engine.h"
#include <iostream>
#include <SDL_image.h>

static SDL_Texture* loadTexture(std::string path, SDL_Renderer* ren)
{
    SDL_Texture* texture = nullptr;

    try
    {
        path = "../assets/" + path;

        SDL_Surface* sur = IMG_Load(path.c_str());
        texture = SDL_CreateTextureFromSurface(ren, sur);
        SDL_FreeSurface(sur);

        if (texture == nullptr)
        {
            throw (-1);
        }
    }
    catch (int i)
    {
        if (i < 0)
        {
            std::cout << "NO TEXTURE LOADED: " << path << std::endl;
        }
    }
    return texture;
}