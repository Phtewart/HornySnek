#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	Respawn(rng, brd, snake);
}

void Goal::Respawn(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	std::uniform_int_distribution<int> rngX(0, brd.GetGridHight() - 1);
	std::uniform_int_distribution<int> rngY(0, brd.GetGridWidth() - 1);

	Location l;
	l = { rngX(rng),rngY(rng) };
	do {
		l = { rngX(rng),rngY(rng) };
	} while (snake.IsBodyTuchComplitly(l));
	loc = l;
}

void Goal::Draw(Board& brd)
{
	brd.DrawCell(loc, c);
}

const Location& Goal::GetLocation(Snake& snake) const
{
	return loc;
}
