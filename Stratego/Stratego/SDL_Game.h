#pragma once
#include <iostream>

#include "Component.h"
#include "EventListener.h"
#include "Game.h"
#include "SDL2/SDL.h"

constexpr int WIN_W = 1280;
constexpr int WIN_H = 800;

class SDL_Game :
	public Game
{
public:
	SDL_Game() : window(nullptr), renderer(nullptr)
	{
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
	std::vector<std::shared_ptr<EventListener>> listeners;
	std::vector<std::shared_ptr<Component>> components;
	bool init();
	bool createWindow();
	bool createRenderer();
};
