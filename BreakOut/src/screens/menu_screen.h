#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "raylib.h"
#include "manager.h"


namespace Godziela
{
	const int cant_menu_buttons = 3;

	enum GameState {
		MENU,
		GAME,
		CREDITS,
		END,
		CLOSE
	};
	extern GameState game_state;

	extern Vector2 mouse_pos;
	extern Rectangle buttons[cant_menu_buttons];
	extern Music background_music;
	extern Music menu_music;
	extern int title_font_size;
	extern int font_size;

	void draw_menu();
	void update_menu();
}



#endif