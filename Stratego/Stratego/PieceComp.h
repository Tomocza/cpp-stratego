#pragma once
#include <string>

#include "ButtonComp.h"
#include "Component.h"
#include "EventListener.h"
#include "TextureWrapper.h"

class PieceComp :
	public ButtonComp
{
public:
	PieceComp(const SDL_Rect& rectangle, const std::shared_ptr<Piece>& piece, const std::string& label) : ButtonComp(rectangle, label), piece(piece) {}
	void render(SDL_Renderer* renderer) override;
	bool hasPiece() const;

private:
	std::shared_ptr<Piece> piece;
};
