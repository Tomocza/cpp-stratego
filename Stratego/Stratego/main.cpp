// Stratego.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Needed for SDL2 to not redefine main() and therefore cause a linker error
#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

#include "Game.h"
#include "SDL_Game.h"


int main()
{
	//Needed for SDL2 to not redefine main() and therefore cause a linker error
	SDL_SetMainReady();

	std::cout << "Hello World!\n";

	return game->run();
}
