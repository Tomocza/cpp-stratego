#include "EventListener.h"

#include <iostream>

void EventListener::regAction(const Uint32 type, const Action& action)
{
	if (const auto [it, success] = actions.insert({type, action}); !success)
	{
		std::cout << "Couldn't add action to " << this << ", action already found on event type: " << type << "\n";
	}
}

void EventListener::regAction(const std::vector<Uint32>& types, const Action& action)
{
	for (const auto type : types)
	{
		regAction(type, action);
	}
}

void EventListener::delAction(const Uint32 type)
{
	const auto it = actions.find(type);
	actions.erase(it);
}

void EventListener::executeAction(const Uint32 type, const SDL_Event& e, const GameLogic& logic) const
{
	if (const auto it = actions.find(type); it != actions.end())
		it->second(e, logic);
}
