#include "SDL_Game.h"

bool SDL_Game::handleEvents()
{
	bool quit = false;
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT || e.type == SDL_MOUSEBUTTONDOWN)
		{
			quit = true;
		}
	}

	return quit;
}

int SDL_Game::run()
{
	if (!display.init()) return 1;
	bool quit = false;
	while (!quit)
	{
		quit = handleEvents();
	}
	return 0;
}
