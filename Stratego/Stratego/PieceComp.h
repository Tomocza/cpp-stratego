#pragma once
#include <string>

#include "Component.h"
#include "EventListener.h"
#include "TextureWrapper.h"

class PieceComp :
	public Component,
	public EventListener
{
public:
	PieceComp(const SDL_Rect& rectangle, Piece& piece) : Component(rectangle), piece(std::make_shared<Piece>(piece)) {};
	void render(SDL_Renderer* renderer) override;

private:
	// TODO: Initialize textureFilePath
	const std::string textureFilePath;
	TextureWrapper textureWrapper;
	std::shared_ptr<Piece> piece;
};
