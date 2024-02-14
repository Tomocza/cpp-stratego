#include "Piece.h"
#include "Bomb.h"
#include "Miner.h"
#include "Marshal.h"
#include "Spy.h"

BattleOutcome Piece::attack(Piece* opponent) const
{
	//attacker perspective
	if (Bomb* bomb = dynamic_cast<Bomb*>(opponent))
	{
		if (Miner* miner = dynamic_cast<Miner*>(const_cast<Piece*>(this)))
		{
			return WIN;
		}
		return LOSE;
	}
	if (Marshal* marshal = dynamic_cast<Marshal*>(opponent))
	{
		if (Spy* spy = dynamic_cast<Spy*>(const_cast<Piece*>(this)))
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
