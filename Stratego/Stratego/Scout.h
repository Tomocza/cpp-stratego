#pragma once
#include "Piece.h"

class Scout : public Piece
{
public:
	Scout(const unsigned short rank, const Player player) : Piece(rank, player) {}
};
