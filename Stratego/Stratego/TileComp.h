#pragma once
#include "Component.h"
#include "EventListener.h"
#include "TextureWrapper.h"

class TileComp :
	public Component,
	public EventListener
{
public:
	void render(SDL_Renderer* renderer) override;
private:
};
