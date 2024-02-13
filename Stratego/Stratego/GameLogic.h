#pragma once
#include <array>
#include <vector>

#include "Tile.h"
#include "Coordinate.h"
#include "Piece.h"

constexpr int BOARD_DIMENSION = 10;

class GameLogic
{
public:
	GameLogic();

	std::vector<Coordinate> getValidCoordinates(Coordinate position,
	                                            const std::vector<DeltaCoordinate>& movePattern) const;

	void movePiece(Piece* piece, const DeltaCoordinate delta);

	private:
	std::array<std::array<Tile, BOARD_DIMENSION>, BOARD_DIMENSION> board{};

	bool isTileEmpty(const Coordinate& c) const;
};
