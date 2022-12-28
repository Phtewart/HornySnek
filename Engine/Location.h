#pragma once

struct Location
{
	void Add(const Location& l) {
		x += l.x;
		y += l.y;
	}
	bool operator ==(const Location& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator !=(const Location& rhs) const {
		return !(*this == rhs);
	}
	Location operator +(const Location& rhs)  {
		Location l = { x += rhs.x,y += rhs.y };
		return l;

	}
	Location operator -() const {
		return {-x,-y};
	}
	int x;
	int y;
};