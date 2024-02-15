#pragma once
#include <string>

#include "Component.h"

class LabelComp :
	public Component
{
public:
	LabelComp(std::string str): text(std::move(str))
	{
	}

	LabelComp(std::string str, const SDL_Rect& r) : Component(r), text(std::move(str))
	{
	}

	void render(SDL_Renderer* renderer) override;

private:
	std::string text;
};
