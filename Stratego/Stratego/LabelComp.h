#pragma once
#include <string>

#include "Component.h"

class LabelComp :
	public Component
{
public:
	LabelComp(const SDL_Rect& r, std::string str) : Component(r), text(std::move(str))
	{
	}

	void render(SDL_Renderer* renderer) override;
	void setColor(const SDL_Color& c);
	void setFont(const std::string& name, int size);

private:
	std::string text;
	std::string fontName{"Roboto-Regular.ttf"};
	int fontSize{72};
	SDL_Color color{0, 0, 0,SDL_ALPHA_OPAQUE};
};
