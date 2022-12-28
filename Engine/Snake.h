#pragma once

#include "Board.h"

class Snake {


private:
	class Segmet {
	public:
		void InitHead(const Location & in_loc);
		void InitBody(Color color);
		void Folow(const Segmet& next);
		void Draw(Board &brd);
		void MuvedBy(const Location& delta);
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
		int colorCounter = 0;
	};
public:
	Snake(const Location& loc);
	void MuvedBy(const Location& delta);
	void Grow();
	void Draw(Board& brd);
	Location GetNextHeadlocation(const Location& delta_loc) const;
	bool IsBodyTuch(const Location& self) const;
	bool IsBodyTuchComplitly(const Location& self) const;

private:
	static constexpr Color headColor = Colors::Cyan;
	static constexpr int nMaxSegments = 100;
	int nSegments = 1;
	Segmet segment[nMaxSegments];
	static constexpr int nBodyColors = 4;
	static constexpr Color bodyColors[nBodyColors] = {
		{ 10,100,32 },
		{ 10,130,48 },
		{ 18,160,48 },
		{ 10,130,48 }
	};
};