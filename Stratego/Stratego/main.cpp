// Stratego.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Needed for SDL2 to not redefine main() and therefore cause a linker error
#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL2/SDL.h>

int main()
{
	//Needed for SDL2 to not redefine main() and therefore cause a linker error
	SDL_SetMainReady();

	std::cout << "Hello World!\n";

	return 0;
}
