#include "SDL_Game.h"

#include <algorithm>
#include <memory>

#include "PanelComp.h"


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
			std::for_each(listeners.begin(), listeners.end(),
			              [e, this](const std::shared_ptr<EventListener>& listener)
			              {
				              listener->executeAction(e.type, e, gameLogic);
			              });
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
		SDL_RenderClear(renderer);
		for (const auto& component : components)
		{
			component->render(renderer);
		}
		SDL_RenderPresent(renderer);
		quit = handleEvents();
	}
	return 0;
}

bool SDL_Game::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) return false;
	if (!createWindow()) return false;
	if (!createRenderer()) return false;

	PanelComp board({20, 0, 200, 200});
	board.setColor(255, 0, 0, SDL_ALPHA_OPAQUE);

	PanelComp p1({10, 10, 10, 10});
	p1.setColor(0, 255, 0, SDL_ALPHA_OPAQUE);

	board.registerComponent(std::make_shared<PanelComp>(p1));
	components.push_back(std::make_shared<PanelComp>(board));

	PanelComp infoPanel({250, 0, 100, 100});
	infoPanel.setColor(0, 0, 255, SDL_ALPHA_OPAQUE);
	components.push_back(std::make_shared<PanelComp>(infoPanel));

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
