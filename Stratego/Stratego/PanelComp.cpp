#include "PanelComp.h"

#include <algorithm>


void PanelComp::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderFillRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_TRANSPARENT);

	std::for_each(components.begin(), components.end(), [renderer](const std::shared_ptr<Component>& comp)
	{
		comp->render(renderer);
	});
}

void PanelComp::move(const int dx, const int dy)
{
	Component::move(dx, dy);
	std::for_each(components.begin(), components.end(), [dx, dy](const std::shared_ptr<Component>& comp)
	{
		comp->move(dx, dy);
	});
}

void PanelComp::setColor(const Uint8 red, const Uint8 green, const Uint8 blue, const Uint8 alpha)
{
	r = red;
	g = green;
	b = blue;
	a = alpha;
}

void PanelComp::registerComponent(const std::shared_ptr<Component>& comp)
{
	comp->move(rect.x, rect.y);
	components.push_back(comp);
}

void PanelComp::removeComponent(const std::shared_ptr<Component>& comp)
{
	components.erase(std::remove(components.begin(), components.end(), comp), components.end());
}
