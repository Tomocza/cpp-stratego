#pragma once
#include "Piece.h"

class Marshal : public Piece
{
public:
	Marshal(const unsigned short rank, const Player player) : Piece(rank, player) {}
};
