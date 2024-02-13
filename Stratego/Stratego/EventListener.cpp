#include "EventListener.h"

void EventListener::regAction(const Uint32 type, Action action)
{
	actions.insert({type, action});
}

void EventListener::delAction(const Uint32 type)
{
	const auto it = actions.find(type);
	actions.erase(it);
}

void EventListener::executeAction(const Uint32 type, const SDL_Event& e, const GameLogic& logic) const
{
	const auto it = actions.find(type);
	if (it != actions.end()) it->second(e, logic);
}
