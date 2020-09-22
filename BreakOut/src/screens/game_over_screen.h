#ifndef GAME_OVER_SCREEN_H
#define GAME_OVER_SCREEN_H
#include "raylib.h"

#include "player.h"
#include "audio.h"
#include "menu_screen.h"
#include "game_screen.h"

namespace Godziela
{
	extern int frames;
	extern int draw_x;
	extern int draw_y;
	extern int winner;
	const int game_over_time = 70000;

	void draw_game_over();
	void init_game_over();
}



#endif