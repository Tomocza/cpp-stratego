#pragma once
#include <array>
#include <vector>

#include "Tile.h"
#include "Coordinate.h"
#include "Piece.h"

constexpr int BOARD_DIMENSION = 10;
constexpr int NUMBER_OF_PIECES = 80;

class GameLogic
{
public:
	GameLogic();

	std::vector<Coordinate> getValidCoordinates(Piece* piece) const;

	void movePiece(Piece* piece, const Coordinate newPosition);
	const Player& getCurrentPlayer() const;
	void switchCurrentPlayer();

private:
	std::array<std::array<Tile, BOARD_DIMENSION>, BOARD_DIMENSION> board{};
	std::vector<std::shared_ptr<Piece>> pieces{NUMBER_OF_PIECES};
	Player currentPlayer{ RED };

	bool hasOwnPieceAt(const Coordinate& c, const Player p) const;
	bool hasOpponentPieceAt(const Coordinate& c, const Player p) const;

	const Tile& getTileAt(const Coordinate c) const;
	Tile& getTileAt(const Coordinate c);

	static std::vector<std::shared_ptr<Piece>> generatePieces();
};
