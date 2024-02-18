#pragma once
#include "Piece.h"

class Major : public Piece
{
public:
	Major(const unsigned short rank, const Player player) : Piece(rank, player) {}
};
