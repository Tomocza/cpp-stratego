#include "GameLogic.h"

#include <algorithm>

#include "Coordinate.h"
#include "Scout.h"

GameLogic::GameLogic()
{
	const std::vector<Coordinate> waterCoordinates{
		Coordinate{2, 4}, Coordinate{3, 4}, Coordinate{6, 4}, Coordinate{7, 4},
		Coordinate{2, 5}, Coordinate{3, 5}, Coordinate{6, 5}, Coordinate{7, 5}
	};
	for (const auto c : waterCoordinates)
	{
		getTileAt(c).isLake = true;
	}
}

bool isOnBoard(const Coordinate& c)
{
	return c.x >= 0 && c.y >= 0 && c.x < BOARD_DIMENSION && c.y < BOARD_DIMENSION;
}

bool GameLogic::hasOwnPieceAt(const Coordinate& c, const Player p) const
{
	return getTileAt(c).piece->getPlayer() == p;
}

bool GameLogic::hasOpponentPieceAt(const Coordinate& c, const Player p) const
{
	auto o = getTileAt(c).piece->getPlayer();
	return (p == RED && o == BLUE) || (p == BLUE && o == RED);
}

std::vector<Coordinate> GameLogic::getValidCoordinates(Piece* piece) const
{
	auto result = piece->getAvailableMoves();
	int maxX, maxY, minX, minY;
	const auto position = piece->getPosition();

	for (int i = 1; ; i++)
	{
		Coordinate c{position.x + i, position.y};
		const auto t = getTileAt(c);
		const auto p = piece->getPlayer();

		if (hasOwnPieceAt(c, p) or !isOnBoard(c) or t.isLake)
		{
			maxX = c.x - 1;
			break;
		}
		else if (hasOpponentPieceAt(c, p))
		{
			maxX = c.x;
			break;
		}
	}

	for (int i = 1; ; i++)
	{
		Coordinate c{position.x - i, position.y};
		const auto t = getTileAt(c);
		const auto p = piece->getPlayer();

		if (hasOwnPieceAt(c, p) or !isOnBoard(c) or t.isLake)
		{
			minX = c.x + 1;
			break;
		}
		else if (hasOpponentPieceAt(c, p))
		{
			minX = c.x;
			break;
		}
	}

	for (int i = 1; ; i++)
	{
		Coordinate c{position.x, position.y + i};
		const auto t = getTileAt(c);
		const auto p = piece->getPlayer();

		if (hasOwnPieceAt(c, p) or !isOnBoard(c) or t.isLake)
		{
			maxY = c.x - 1;
			break;
		}
		else if (hasOpponentPieceAt(c, p))
		{
			maxY = c.x;
			break;
		}
	}

	for (int i = 1; ; i++)
	{
		Coordinate c{position.x, position.y - i};
		const auto t = getTileAt(c);
		const auto p = piece->getPlayer();

		if (hasOwnPieceAt(c, p) or !isOnBoard(c) or t.isLake)
		{
			minY = c.x + 1;
			break;
		}
		else if (hasOpponentPieceAt(c, p))
		{
			minY = c.x;
			break;
		}
	}


	result.erase(std::remove_if(result.begin(), result.end(), [this, piece, maxX, maxY, minX, minY](const Coordinate c)
	{
		return not isOnBoard(c) or hasOwnPieceAt(c, piece->getPlayer()) or getTileAt(c).isLake or
			c.x > maxX or c.x < minX or c.y > maxY or c.y < minY;
	}), result.end());

	return result;
}

void GameLogic::movePiece(Piece* piece, const Coordinate newPosition)
{
	getTileAt(piece->getPosition()).piece.reset();
	piece->setPosition(newPosition);
	getTileAt(newPosition).piece.reset(piece);
}

const Tile& GameLogic::getTileAt(const Coordinate c) const
{
	return board.at(c.y).at(c.x);
}

Tile& GameLogic::getTileAt(const Coordinate c)
{
	return board.at(c.y).at(c.x);
}

const Player& GameLogic::getCurrentPlayer() const
{
	return currentPlayer;
}

void GameLogic::switchCurrentPlayer()
{
	if (currentPlayer == RED) currentPlayer = BLUE;
	else currentPlayer = RED;
}
