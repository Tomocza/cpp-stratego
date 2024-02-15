#include "LabelComp.h"
#include <SDL2/SDL_ttf.h>

void LabelComp::render(SDL_Renderer* renderer)
{
	TTF_Font* font = TTF_OpenFont(fontName.c_str(), fontSize);
	auto surface = TTF_RenderText_Solid(font, text.c_str(), color);
	auto msgTexture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_RenderCopy(renderer, msgTexture, NULL, &rect);

	TTF_CloseFont(font);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(msgTexture);
}

void LabelComp::setColor(const SDL_Color& c)
{
	this->color = c;
}

void LabelComp::setFont(const std::string& name, const int size)
{
	this->fontName = name;
	this->fontSize = size;
}
