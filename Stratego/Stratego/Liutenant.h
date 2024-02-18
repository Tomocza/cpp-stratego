#pragma once
#include "Piece.h"

class Liutenant : public Piece
{
public:
	Liutenant(const unsigned short rank, const Player player) : Piece(rank, player) {}
};
