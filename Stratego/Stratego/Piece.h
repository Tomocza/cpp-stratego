#pragma once
#include <vector>
#include "BattleOutcome.h"
#include "Coordinate.h"
#include <set>

class Piece
{
public:
	explicit Piece(unsigned short rank)
		: rank(rank)
	{
	}

	BattleOutcome attack(Piece* opponent) const;
	std::set<Coordinate> getAvailableMoves() const;
	virtual ~Piece();
	Coordinate getPosition();
	void setPosition(Coordinate newPosition);
private:
	const unsigned short rank;
	Coordinate position;
	static const std::vector<DeltaCoordinate> movePattern;
};
