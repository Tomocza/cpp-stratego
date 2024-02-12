#pragma once

#include <memory>
#include <string>

class Game
{
public:
	virtual ~Game() = default;
	virtual int run() = 0;
};
