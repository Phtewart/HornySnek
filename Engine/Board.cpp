#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gr)
	:
	gfx(gr)
{

}

void Board::DrawCell(Location& loc, Color c) 
{
	
	assert(loc.x >= 0);
	assert(loc.y >= 0);
	assert(loc.x < width);
	assert(loc.x < height);

	gfx.DrawRectWithOfset(loc.x * dementions+ boardLocation.x, loc.y * dementions+ boardLocation.y, loc.x * dementions + dementions+ boardLocation.x, loc.y * dementions + dementions+ boardLocation.y, c,1);
}

void Board::DrawBorder() const
{
	gfx.DrawRectSides(boardLocation.x, boardLocation.y, width*dementions+ boardLocation.x, height*dementions+ boardLocation.y, Colors::White, 10);
}


int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHight() const
{
	return height;
}

bool Board::IsOnBoard(Location& loc)  const
{
	
	return loc.x>=0 && loc.x<width
		&&loc.y>=0&&loc.y<height;
}
