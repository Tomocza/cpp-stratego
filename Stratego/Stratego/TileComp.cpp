#include "TileComp.h"

void TileComp::render(SDL_Renderer* renderer)
{
	//Paint background
	if(tile->isLake)
	{
		SDL_SetRenderDrawColor(renderer, 40, 40, 255, SDL_ALPHA_OPAQUE);
	} else
	{
		SDL_SetRenderDrawColor(renderer, 40, 40, 40, SDL_ALPHA_OPAQUE);
	}
	
	SDL_RenderFillRect(renderer, &rect);

	//Paint border
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

	if (pieceComp->hasPiece()) pieceComp->render(renderer);
}
