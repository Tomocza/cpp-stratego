#pragma once
#include <iostream>

#include "EventListener.h"
#include "Game.h"
#include "SDL_Display.h"

class SDL_Game :
	public Game
{
public:
	bool handleEvents();
	~SDL_Game() override = default;
	int run() override;

	SDL_Game()
	{
		er.regAction(SDL_MOUSEBUTTONDOWN, [](const SDL_Event& e, const GameLogic& logic)
		{
			std::cout << "success\n";
		});
	}

private:
	SDL_Display display;
	GameLogic gameLogic;
	EventListener er;
};
