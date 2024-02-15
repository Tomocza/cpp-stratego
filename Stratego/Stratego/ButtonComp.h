#pragma once
#include <iostream>

#include "Component.h"
#include "EventListener.h"
#include "LabelComp.h"

class ButtonComp : public Component, public EventListener
{
public:
	ButtonComp(const SDL_Rect& r, std::string str) : Component(r), label(r, std::move(str))
	{
		this->regAction(SDL_MOUSEMOTION, [this](const SDL_Event& e, const GameLogic& logic)
		{
			const SDL_Point cursor{e.button.x, e.button.y};
			isHovered = SDL_PointInRect(&cursor, &rect);
		});
	}

	void render(SDL_Renderer* renderer) override;
	void move(int dx, int dy) override;
	void setColor(const SDL_Color& bg, const SDL_Color& border);
	void setTextColor(const SDL_Color& c);
	void setHoverColor(const SDL_Color& c);

private:
	LabelComp label;
	SDL_Color borderColor{40, 40, 40,SDL_ALPHA_OPAQUE};
	SDL_Color borderHoverColor{255, 0, 0,SDL_ALPHA_OPAQUE};
	SDL_Color backgroundColor{200, 200, 200,SDL_ALPHA_OPAQUE};
	bool isHovered{false};
};
