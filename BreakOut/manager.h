#ifndef MANAGER_H
#define MANAGER_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "raylib.h"

#include "ball.h"
#include "bricks.h"
#include "player.h"

const int FPS = 60;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 480;
const int CANT_PLAYERS = 2;
const int GAME_FONT = 20;

namespace Godziela_BreakOut
{
	void start_game();


	enum class gameState
	{
		MENU,
		GAME,
		CREDITS,
		CONTROL_SCREEN
	};

	extern gameState game_state;
}
#endif