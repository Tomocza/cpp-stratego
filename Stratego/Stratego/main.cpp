// Stratego.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Needed for SDL2 to not redefine main() and therefore cause a linker error
#define SDL_MAIN_HANDLED

#include <iostream>

#include "Coordinate.h"
//#include <SDL2/SDL.h>

int main()
{
	//Needed for SDL2 to not redefine main() and therefore cause a linker error
	//SDL_SetMainReady();

	Coordinate c{1, 2};
	DeltaCoordinate d{ 2, 3 };
	std::count << c.x << '\n' << d.y;
	std::cout << "Hello World!\n";

	return 0;
}
