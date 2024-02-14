#pragma once
#include <memory>
#include <vector>

#include "Component.h"

class PanelComp :
	public Component
{
public:
	PanelComp(const SDL_Rect& rectangle) : Component(rectangle), r(0), g(0), b(0), a(SDL_ALPHA_TRANSPARENT)
	{
	}

	void render(SDL_Renderer* renderer) override;
	void move(const int dx, const int dy) override;
	void setColor(const Uint8 red, const Uint8 green, const Uint8 blue, const Uint8 alpha);
	void registerComponent(const std::shared_ptr<Component>& comp);
	void removeComponent(const std::shared_ptr<Component>& comp);
private:
	Uint8 r, g, b, a;
	std::vector<std::shared_ptr<Component>> components;
};
