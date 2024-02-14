#include "PieceComp.h"

void PieceComp::render(SDL_Renderer* renderer)
{
	if (textureWrapper.isLoaded())
	{
		textureWrapper.blit(renderer, rect);
	}
	else
	{
		textureWrapper.load(renderer, textureFilePath.c_str());
		textureWrapper.blit(renderer, rect);
	}
}
