#pragma once
#include "Piece.h"

class Captain : public Piece
{
public:
	Captain(const unsigned short rank, const Player player) : Piece(rank, player) {}
	
};
