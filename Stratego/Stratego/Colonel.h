#pragma once
#include "Piece.h"

class Colonel : public Piece
{
public:
	Colonel(const unsigned short rank, const Player player) : Piece(rank, player) {}
};
