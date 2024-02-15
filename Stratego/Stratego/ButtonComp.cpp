#include "ButtonComp.h"

void ButtonComp::render(SDL_Renderer* renderer)
{
	SDL_Color bg = backgroundColor;
	SDL_Color bd = isHovered ? borderHoverColor : borderColor;

	//Paint background
	SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, bg.a);
	SDL_RenderFillRect(renderer, &rect);

	//Paint border
	SDL_SetRenderDrawColor(renderer, bd.r, bd.g, bd.b, bd.a);
	SDL_RenderDrawRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	label.render(renderer);
}

void ButtonComp::move(const int dx, const int dy)
{
	Component::move(dx, dy);
	label.move(dx, dy);
}

void ButtonComp::setColor(const SDL_Color& bg, const SDL_Color& border)
{
	this->borderColor = border;
	this->backgroundColor = bg;
}

void ButtonComp::setTextColor(const SDL_Color& c)
{
	label.setColor(c);
}

void ButtonComp::setHoverColor(const SDL_Color& c)
{
	this->borderHoverColor = c;
}
