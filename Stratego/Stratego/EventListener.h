#pragma once
#include <functional>
#include <map>
#include <SDL2/SDL_stdinc.h>

#include "SDL2/SDL_events.h"
#include "GameLogic.h"

using Action = std::function<void(const SDL_Event& e, const GameLogic& logic)>;

class EventListener
{
public:
	void regAction(const Uint32 type, const Action& action);
	void regAction(const std::vector<Uint32>& types, const Action& action);
	void delAction(const Uint32 type);
	void executeAction(const Uint32 type, const SDL_Event& e, const GameLogic& logic) const;

private:
	std::map<Uint32, Action> actions;
};
