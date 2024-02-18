#pragma once
#include "Piece.h"

class Spy : public Piece
{
public:
	Spy(const unsigned short rank, const Player player) : Piece(rank, player) {}
};
