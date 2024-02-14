#pragma once
#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_render.h"

class Component
{
protected:
	SDL_Rect rect;

public:
	Component(): rect({0, 0, 0, 0,})
	{
	}

	Component(const SDL_Rect& r): rect(r)
	{
	}

	virtual ~Component() = default;
	virtual void render(SDL_Renderer* renderer) = 0;
};
