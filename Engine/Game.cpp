/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Keyboard.h"
#include <Windows.h>
#include "Sprites.h"

using namespace std;

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx),
	snek({1,1,}),
	rnd(std::random_device()()),
	goal(rnd,brd,snek)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!GameOwer) {
		if (wnd.kbd.KeyIsPressed(VK_UP)) {
			const Location newDelataLoc = { 0,-1 };
			if ( -newDelataLoc != deltaLoc  )
				deltaLoc = newDelataLoc;
		}

		if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
			const Location newDelataLoc = { 0,1 };
			if (-newDelataLoc != deltaLoc)
				deltaLoc = newDelataLoc;
		}

		if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
			const Location newDelataLoc = { -1,0 };
			if (-newDelataLoc != deltaLoc)
				deltaLoc = newDelataLoc;
		}

		if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
			const Location newDelataLoc = { 1,0 };
			if (-newDelataLoc != deltaLoc)
				deltaLoc = newDelataLoc;
		}
		
		if (snakeEatCounter % 5 == 0) {
			--snakeMuvePeriod;
			++snakeEatCounter;
		}
		++snakeMuveCounter;
		if (snakeMuveCounter >= snakeMuvePeriod) {
			snakeMuveCounter = 0;
			Location next = snek.GetNextHeadlocation(deltaLoc);
			if (!brd.IsOnBoard(next)|| snek.IsBodyTuch(next)) {
				GameOwer = true;
			}
			else {
				bool isEating = next == goal.GetLocation(snek);
				if (isEating) {
					snek.Grow();
					++snakeEatCounter;
				}
				snek.MuvedBy(deltaLoc);
				if (isEating) {
					goal.Respawn(rnd, brd, snek);
				}
			}
		}
		
	}
}

void Game::ComposeFrame()
{
	brd.DrawBorder();
	snek.Draw(brd);
	goal.Draw(brd);
	if (GameOwer) {
		Sprites::DrawGameOwer(200,200,gfx);
	}

}
