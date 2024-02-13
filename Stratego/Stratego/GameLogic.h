#pragma once
#include <vector>

#include "Tile.h"
#include "Coordinate.h"
#include "Piece.h"


class GameLogic
{
public:
	GameLogic();

	std::vector<Coordinate> getValidCoordinates(Coordinate position, DeltaCoordinate movePattern) const;

	Coordinate getCoordinateOf(Piece piece) const;

	void movePiece(Piece piece, DeltaCoordinate delta);

private:
	std::vector<std::vector<Tile>> board;
};
