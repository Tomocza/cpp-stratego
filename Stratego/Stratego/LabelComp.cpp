#include "LabelComp.h"
#include <SDL2/SDL_ttf.h>

void LabelComp::render(SDL_Renderer* renderer)
{
	TTF_Font* font = TTF_OpenFont("Roboto-Regular.ttf", 24);
	SDL_Color color{0, 0, 0,SDL_ALPHA_OPAQUE};

	auto surface = TTF_RenderText_Solid(font, text.c_str(), color);
	auto msgTexture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_RenderCopy(renderer, msgTexture, NULL, &rect);

	TTF_CloseFont(font);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(msgTexture);
}
