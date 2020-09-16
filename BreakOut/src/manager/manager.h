#ifndef MANAGER_H
#define MANAGER_H

#include <cmath>

#include "raylib.h"

#include "Player.h"
#include "Ball.h"
#include "game_over_screen.h"
#include "game_screen.h"
#include "menu_screen.h"
#include "Brick.h"
#include "Credits.h"
#include "audio.h"

namespace Godziela
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	const int FPS = 60;
	const int REC_WIDTH = 150;
	const int REC_HEIGHT = 25;
	const int buttons_X = 300; 

	const float third_screen_height = screenHeight / 3;
	const float fourteenth_screen_width = screenWidth / 14;
	
	extern Color base_background;
	extern Texture2D background_texture;

	void play();
}


#endif