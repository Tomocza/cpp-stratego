#include "Component.h"

void Component::move(const int dx, const int dy)
{
	rect.x += dx;
	rect.y += dy;
}
