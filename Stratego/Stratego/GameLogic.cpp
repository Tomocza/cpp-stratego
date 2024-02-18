#include "GameLogic.h"

#include <algorithm>
#include <iostream>

#include "Coordinate.h"
#include "Scout.h"
#include "Bomb.h"
#include "Marshal.h"
#include "General.h"
#include "Colonel.h"
#include "Major.h"
#include "Captain.h"
#include "Liutenant.h"
#include "Sergant.h"
#include "Miner.h"
#include "Scout.h"
#include "Spy.h"
#include "Flag.h"

GameLogic::GameLogic()
{
	for(int x = 0; x < BOARD_DIMENSION; x++)
	{
		for(int y = 0; y < BOARD_DIMENSION; y++)
		{
			getTileAt({ x, y }).coordinate = { x, y };
		}
	}
	const std::vector<Coordinate> waterCoordinates{
		Coordinate{2, 4}, Coordinate{3, 4}, Coordinate{6, 4}, Coordinate{7, 4},
		Coordinate{2, 5}, Coordinate{3, 5}, Coordinate{6, 5}, Coordinate{7, 5}
	};
	for (const auto c : waterCoordinates)
	{
		getTileAt(c).isLake = true;
	}
	//pieces = generatePieces();
}

std::vector<std::shared_ptr<Piece>> GameLogic::generatePieces()
{
	constexpr int NUMBERS_OF_PLAYERS = 2;

	constexpr int NUMBER_OF_BOMBS = 6;
	constexpr int NUMBER_OF_MARSHALS = 1;
	constexpr int NUMBER_OF_GENERALS = 1;
	constexpr int NUMBER_OF_COLONELS = 2;
	constexpr int NUMBER_OF_MAJORS = 3;
	constexpr int NUMBER_OF_CAPTAINS = 4;
	constexpr int NUMBER_OF_LIUTENANTS = 4;
	constexpr int NUMBER_OF_SERGANTS = 4;
	constexpr int NUMBER_OF_MINERS = 5;
	constexpr int NUMBER_OF_SCOUTS = 8;
	constexpr int NUMBER_OF_SPYS = 1;
	constexpr int NUMBER_OF_FLAGS = 1;

	constexpr int RANK_OF_BOMBS = 11;
	constexpr int RANK_OF_MARSHALS = 10;
	constexpr int RANK_OF_GENERALS = 9;
	constexpr int RANK_OF_COLONELS = 8;
	constexpr int RANK_OF_MAJORS = 7;
	constexpr int RANK_OF_CAPTAINS = 6;
	constexpr int RANK_OF_LIUTENANTS = 5;
	constexpr int RANK_OF_SERGANTS = 4;
	constexpr int RANK_OF_MINERS = 3;
	constexpr int RANK_OF_SCOUTS = 2;
	constexpr int RANK_OF_SPYS = 1;
	constexpr int RANK_OF_FLAGS = 0;

	std::vector<std::shared_ptr<Piece>> result(NUMBER_OF_PIECES);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < NUMBERS_OF_PLAYERS; j++) {
			Player player = j == 0 ? RED : BLUE;
			for (int k = 0; k < NUMBER_OF_BOMBS; k++) {
				std::shared_ptr<Bomb> b = std::make_shared<Bomb>(RANK_OF_BOMBS, player);
				result.emplace_back(b);
			}
			result.emplace_back(std::make_shared<Marshal>(RANK_OF_MARSHALS, player));
			result.emplace_back(std::make_shared<General>(RANK_OF_GENERALS, player));
			for (int k = 0; k < NUMBER_OF_COLONELS; k++)
			{
				result.emplace_back(std::make_shared<Colonel>(RANK_OF_COLONELS, player));

			}
			for (int k = 0; k < NUMBER_OF_MAJORS; k++) {
				result.emplace_back(std::make_shared<Major>(RANK_OF_MAJORS, player));
			}
			for (int k = 0; k < NUMBER_OF_CAPTAINS; k++) {
				result.emplace_back(std::make_shared<Captain>(RANK_OF_CAPTAINS, player));
			}
			for (int k = 0; k < NUMBER_OF_LIUTENANTS; k++) {
				result.emplace_back(std::make_shared<Liutenant>(RANK_OF_LIUTENANTS, player));
			}
			for (int k = 0; k < NUMBER_OF_SERGANTS; k++) {
				result.emplace_back(std::make_shared<Sergant>(RANK_OF_SERGANTS, player));
			}
			for (int k = 0; k < NUMBER_OF_MINERS; k++) {
				result.emplace_back(std::make_shared<Miner>(RANK_OF_MINERS, player));
			}
			for (int k = 0; k < NUMBER_OF_SCOUTS; k++) {
				result.emplace_back(std::make_shared<Scout>(RANK_OF_SCOUTS, player));
			}
			result.emplace_back(std::make_shared<Spy>(RANK_OF_SPYS, player));
			result.emplace_back(std::make_shared<Flag>(RANK_OF_FLAGS, player));
		}
	}

	return result;
}

void GameLogic::placePiecesOnBoard()
{
	for (const auto& piece : pieces) {
		const int minY = piece->getPlayer() == RED ? 6 : 0;
		const int maxY = piece->getPlayer() == RED ? 9 : 3;

		while (true) {
			const int x = rand() % BOARD_DIMENSION;
			const int y = rand() % (maxY - minY + 1) + minY;
			
			if (!getTileAt({ x, y }).piece)
			{
				getTileAt({ x, y }).piece = piece;
				break;
			}
		}
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

std::vector<std::shared_ptr<Piece>>& GameLogic::getPieces()
{
	return pieces;
}
