#pragma once
#include <vector>
#include "BattleOutcome.h"
#include "Coordinate.h"
#include <set>

#include "Player.h"

class Piece
{
public:
	explicit Piece(const unsigned short rank, const Player player)
		: player(player), rank(rank)
	{
	}

	BattleOutcome attack(Piece* opponent) const;
	std::vector<Coordinate> getAvailableMoves() const;
	virtual ~Piece() = default;
	Coordinate getPosition() const;
	void setPosition(const Coordinate newPosition);
	Player getPlayer() const;

private:
	const Player player;
	const unsigned short rank;
	Coordinate position{-1, -1};
	std::vector<DeltaCoordinate> movePattern;
};
