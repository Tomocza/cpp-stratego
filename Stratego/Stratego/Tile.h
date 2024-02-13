#pragma once
#include "Piece.h"

struct Tile
{
	bool isLake{false};
	Piece* piece{nullptr};
};
