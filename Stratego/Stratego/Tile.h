#pragma once
#include <memory>

#include "Piece.h"

struct Tile
{
	bool isLake{false};
	std::shared_ptr<Piece> piece;
	Coordinate coordinate;
};
