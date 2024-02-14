#pragma once
#include "Component.h"

class BackgroundComp :
	public Component
{
public:
	BackgroundComp(const SDL_Rect& r) : Component(r)
	{
	}

	void render(SDL_Renderer* renderer) override;
};
