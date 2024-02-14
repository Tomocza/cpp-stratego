#pragma once
#include <SDL2/SDL_render.h>

class TextureWrapper
{
public:
	~TextureWrapper();

	void load(SDL_Renderer* renderer, const char* fileName);
	void blit(SDL_Renderer* renderer, SDL_Rect& dest) const;
	bool isLoaded() const;
private:
	SDL_Texture* texture{nullptr};
};
