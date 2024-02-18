#pragma once
#include "Piece.h"

class Sergant : public Piece
{
public:
	Sergant(const unsigned short rank, const Player player) : Piece(rank, player) {}
};
