#pragma once

#include "Graphics.h"
#include "Location.h"

class Board {
public:
	Board(Graphics & gr);
	void DrawCell(Location& loc, Color c);
	void DrawBorder() const;
	int GetGridWidth() const;
	int GetGridHight() const;
	bool IsOnBoard(Location& loc) const;
private:
	Location boardLocation = { 20,20 };
	static constexpr int dementions = 20;
	static constexpr int width = 25;
	static constexpr int height = 25;
	Graphics &gfx;
};