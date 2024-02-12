#pragma once
#include "Game.h"
#include "SDL_Display.h"

class SDL_Game :
	public Game
{
public:
	bool handleEvents();
	~SDL_Game() override = default;
	int run() override;

private:
	SDL_Display display;
};
