#pragma once
#include "Component.h"
#include "EventListener.h"
#include "PieceComp.h"
#include "TextureWrapper.h"

class TileComp :
	public Component,
	public EventListener
{
public:
	TileComp(const SDL_Rect& rectangle, const std::shared_ptr<Tile>& tile, const std::shared_ptr<PieceComp>& pieceComp) : Component(rectangle), tile(tile), pieceComp(pieceComp) {}
	void render(SDL_Renderer* renderer) override;
private:
	std::shared_ptr<Tile> tile;
	std::shared_ptr<PieceComp> pieceComp;
};
