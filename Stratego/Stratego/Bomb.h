#pragma once
#include "Piece.h"

class Bomb : public Piece
{
public:
	Bomb(const unsigned short rank, const Player player) : Piece(rank, player) {}
};
