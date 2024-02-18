#pragma once
#include "Piece.h"

class  General : public Piece
{
public:
	General(const unsigned short rank, const Player player) : Piece(rank, player) {}
};
