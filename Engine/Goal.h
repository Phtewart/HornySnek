#pragma once

#include "Board.h"
#include "Snake.h"
#include <random>

class Goal {
public:
	Goal(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Respawn(std::mt19937& rng,const Board &brd,const Snake& snake);
	void Draw(Board& brd);
	const Location& GetLocation(Snake& snake) const;
private:
	static constexpr Color c = Colors::Red;
	Location loc={0,0};
};