#pragma once
#include <vector>

#include "Coordinate.h"

class Piece
{
public:
	explicit Piece(unsigned short rank)
		: rank(rank)
	{
	}

	bool attack(const Piece& opponent) const;
	std::vector<Coordinate> getAvailableMoves() const;

private:
	const unsigned short rank;

private:
	static const std::vector<DeltaCoordinate> movePattern;
};
