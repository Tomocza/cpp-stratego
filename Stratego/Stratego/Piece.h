#pragma once
#include <vector>
#include "BattleOutcome.h"
#include "Coordinate.h"

class Piece
{
public:
	explicit Piece(unsigned short rank)
		: rank(rank)
	{
	}

	BattleOutcome attack(Piece* opponent) const;
	std::vector<Coordinate> getAvailableMoves() const;
	virtual ~Piece();

private:
	const unsigned short rank;

private:
	static const std::vector<DeltaCoordinate> movePattern;
};
