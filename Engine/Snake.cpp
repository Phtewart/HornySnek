#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	segment[0].InitHead(loc);
}

void Snake::MuvedBy(const Location& delta)
{
	for (int i = nSegments - 1; i > 0; --i) {
		segment[i].Folow(segment[i - 1]);
	}
	segment[0].MuvedBy(delta);
}

void Snake::Grow()
{
	if (nSegments < nMaxSegments) {
		segment[nSegments].InitBody(bodyColors [nSegments%nBodyColors]);
		nSegments++;
	}
}

void Snake::Draw(Board& brd)
{
	for (int i = 0; i < nSegments; ++i) {
		segment[i].Draw(brd);
	}
}

Location Snake::GetNextHeadlocation(const Location& delta_loc) const
{
	Location l(segment[0].GetLocation());
	l.Add(delta_loc);
	return l;
}


bool Snake::IsBodyTuch(const Location& self) const
{
	for (int i = 0; i < nSegments-1; ++i) {
		if (segment[i].GetLocation() == self) {
			return true;
		}
		
	}
	return false;
}

bool Snake::IsBodyTuchComplitly(const Location& self) const
{
	for (int i = 0; i < nSegments ; ++i) {
		if (segment[i].GetLocation() == self) {
			return true;
		}

	}
	return false;
}





void Snake::Segmet::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segmet::InitBody(Color color)
{
	c = color;
	
}

void Snake::Segmet::Folow(const Segmet& next)
{
	loc = next.loc;
}

void Snake::Segmet::Draw(Board& brd) 
{
	brd.DrawCell(loc, c);
}

void Snake::Segmet::MuvedBy(const Location& delta)
{
	assert(abs(delta.x) + abs(delta.y) == 1);
	loc.Add(delta);
}

const Location& Snake::Segmet::GetLocation() const
{
	return loc;
}




