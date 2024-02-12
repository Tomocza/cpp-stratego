#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

class SDL_Display
{
public:
	SDL_Display() : window(nullptr), renderer(nullptr)
	{
	}

	~SDL_Display()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	bool init();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool createWindow();
	bool createRenderer();
};
