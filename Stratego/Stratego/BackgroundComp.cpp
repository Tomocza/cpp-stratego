#include "BackgroundComp.h"

void BackgroundComp::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 123, 44, 22, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_TRANSPARENT);
}
