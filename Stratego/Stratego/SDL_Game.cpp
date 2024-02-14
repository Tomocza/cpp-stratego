#include "SDL_Game.h"


bool SDL_Game::handleEvents()
{
	bool quit = false;
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
		else
		{
			er.executeAction(e.type, e, gameLogic);
			el.executeAction(e.type, e, gameLogic);
		}
	}

	return quit;
}

int SDL_Game::run()
{
	if (!this->init()) return 1;
	bool quit = false;
	while (!quit)
	{
		quit = handleEvents();
	}
	return 0;
}

bool SDL_Game::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) return false;
	if (!createWindow()) return false;
	if (!createRenderer()) return false;
	return true;
}

bool SDL_Game::createWindow()
{
	window = SDL_CreateWindow("Stratego", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

bool SDL_Game::createRenderer()
{
	if (!window) return false;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}
