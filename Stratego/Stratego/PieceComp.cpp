#include "PieceComp.h"

void PieceComp::render(SDL_Renderer* renderer)
{
	if (textureWrapper.isLoaded())
	{
		rect.x = piece->getPosition().x * 80;
		rect.y = piece->getPosition().y * 80;
		textureWrapper.blit(renderer, rect);
	}
	else
	{
		textureWrapper.load(renderer, textureFilePath.c_str());
		textureWrapper.blit(renderer, rect);
	}
}
