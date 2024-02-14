#include "TextureWrapper.h"

#include <iostream>

#include "SDL2/SDL_image.h"

TextureWrapper::~TextureWrapper()
{
	SDL_DestroyTexture(texture);
}

void TextureWrapper::load(SDL_Renderer* renderer, const char* fileName)
{
	texture = IMG_LoadTexture(renderer, fileName);

	if (!texture) std::cerr << SDL_GetError() << '\n';
}

void TextureWrapper::blit(SDL_Renderer* renderer, SDL_Rect& dest) const
{
	SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);

	SDL_RenderCopy(renderer, texture, nullptr, &dest);
}

bool TextureWrapper::isLoaded() const
{
	return texture;
}
