#pragma once
#include <functional>
#include <map>
#include <SDL2/SDL_stdinc.h>

class EventReceiver
{
private:
	std::map<Uint32, std::function<void()>> actions;
};
