#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "raylib.h"

#include "manager.h"

namespace Godziela
{
	const Vector2 speedY = { 200, 500 };
	const float speed_up = 35.0f;
	const int score_max = 5;
	const int MOVEMENT = 22;
	const int game_over_condition = 0;
	const int reset_lives = 3;

	extern bool game_start;
	extern bool game_pause;

	void draw_game();
	void game_update();
}

#endif