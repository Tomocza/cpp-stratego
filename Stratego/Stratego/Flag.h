#pragma once
#include "Piece.h"

class Flag : public Piece
{
public:
	Flag(const unsigned short rank, const Player player) : Piece(rank, player) {}
};
