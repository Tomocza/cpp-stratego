#pragma once
#include <iostream>

#include "EventListener.h"
#include "Game.h"
#include "SDL2/SDL.h"

class SDL_Game :
	public Game
{
public:
	SDL_Game() : window(nullptr), renderer(nullptr)
	{
		er.regAction(SDL_MOUSEBUTTONDOWN, [](const SDL_Event& e, const GameLogic& logic)
		{
			std::cout << "success-down\n";
		});
		er.regAction({SDL_MOUSEBUTTONDOWN, SDL_MOUSEBUTTONUP}, [](const SDL_Event& e, const GameLogic& logic)
		{
			std::cout << "success-down-up\n";
		});
	}

	~SDL_Game() override
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	bool handleEvents();
	int run() override;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	GameLogic gameLogic;
	EventListener er;
	EventListener el;
	bool init();
	bool createWindow();
	bool createRenderer();
};
