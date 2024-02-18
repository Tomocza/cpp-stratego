#pragma once
#include "Piece.h"

class Miner : public Piece
{
public:
	Miner(const unsigned short rank, const Player player) : Piece(rank, player) {}
};
