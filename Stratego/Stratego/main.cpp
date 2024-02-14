// Stratego.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Needed for SDL2 to not redefine main() and therefore cause a linker error
#define SDL_MAIN_HANDLED

#include "Game.h"
#include "SDL_Game.h"


int main()
{
	//Needed for SDL2 to not redefine main() and therefore cause a linker error
	SDL_SetMainReady();

	const std::unique_ptr<Game> game = std::make_unique<SDL_Game>();

	return game->run();
}
