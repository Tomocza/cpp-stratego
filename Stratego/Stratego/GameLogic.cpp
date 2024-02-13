#include "GameLogic.h"

#include <algorithm>
#include <iterator>

#include "Coordinate.h"

GameLogic::GameLogic()
{
	const std::vector<Coordinate> waterTiles{
		Coordinate{2, 4}, Coordinate{3, 4}, Coordinate{6, 4}, Coordinate{7, 4},
		Coordinate{2, 5}, Coordinate{3, 5}, Coordinate{6, 5}, Coordinate{7, 5}
	};
	for (const Coordinate waterTile : waterTiles)
	{
		board.at(waterTile.y).at(waterTile.x).isLake = true;
	}
}

Coordinate addPositionToDelta(const Coordinate& position, const DeltaCoordinate& delta)
{
	return Coordinate{position.x + delta.x, position.y + delta.y};
}

bool isOnBoard(const Coordinate c)
{
	return c.x >= 0 && c.y >= 0 && c.x < BOARD_DIMENSION && c.y < BOARD_DIMENSION;
}

std::vector<Coordinate> GameLogic::getValidCoordinates(Coordinate position,
                                                       const std::vector<DeltaCoordinate>& movePattern) const
{
	std::vector<Coordinate> coordinates(movePattern.size());

	std::transform(movePattern.begin(), movePattern.end(), coordinates.begin(), coordinates.end(),
	               [position](const DeltaCoordinate delta) { return addPositionToDelta(position, delta); });

	std::vector<Coordinate> result;

	std::copy_if(coordinates.begin(), coordinates.end(), std::back_inserter(result),
	             [](const Coordinate c) { return isOnBoard(c); });

	return result;
}

// TODO
void GameLogic::movePiece(Piece piece, DeltaCoordinate delta)
{
}
