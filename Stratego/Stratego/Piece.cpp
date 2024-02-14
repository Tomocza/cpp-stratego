#include "Piece.h"
#include "Bomb.h"
#include "Miner.h"
#include "Marshal.h"
#include "Spy.h"

BattleOutcome Piece::attack(Piece* opponent) const
{
	//attacker perspective
	if (dynamic_cast<Bomb*>(opponent))
	{
		if (dynamic_cast<const Miner*>(this))
		{
			return WIN;
		}
		return LOSE;
	}
	if (dynamic_cast<Marshal*>(opponent))
	{
		if (dynamic_cast<const Spy*>(this))
		{
			return WIN;
		}
		return LOSE;
	}
	if (this->rank == opponent->rank)
	{
		return DRAW;
	}
	else
	{
		return this->rank > opponent->rank ? WIN : LOSE;
	}
}

std::vector<Coordinate> Piece::getAvailableMoves() const
{
	std::vector<Coordinate> result;
	for (int i = 0; i < movePattern.size(); i++)
	{
		short x = position.x + movePattern.at(i).x;
		short y = position.y + movePattern.at(i).y;
		result.push_back(Coordinate{x, y});
	}
	return result;
}

Coordinate Piece::getPosition() const
{
	return position;
}

void Piece::setPosition(const Coordinate newPosition)
{
	this->position = newPosition;
}

Player Piece::getPlayer() const
{
	return player;
}
