#include "Piece.h"
#include "Bomb.h"
#include "Miner.h"
#include "Marshal.h"
#include "Spy.h"


BattleOutcome Piece::attack(Piece* opponent) const
{//attacker perspective
	if(Bomb* bomb = dynamic_cast<Bomb*>(opponent)){
		if (Miner* miner = dynamic_cast<Miner*>(const_cast<Piece*>(this))) {
			return WIN; 
		}
		return LOSE;
	}
	if (Marshal* marshal = dynamic_cast<Marshal*>(opponent)) {
		if (Spy* spy = dynamic_cast<Spy*>(const_cast<Piece*>(this))) {
			return WIN;
		}
		return LOSE;
	}
	if (this->rank == opponent->rank) {
		return DRAW;
	}
	else {
		return this->rank > opponent->rank ? WIN : LOSE;
	}
}

// TODO
std::vector<Coordinate> Piece::getAvailableMoves() const
{
	return std::vector<Coordinate>{Coordinate{0,0}};
}
