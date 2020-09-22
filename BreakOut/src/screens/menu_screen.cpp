#include "menu_screen.h"
#include <iostream>

namespace Godziela
{
	GameState game_state;
	Vector2 mouse_pos = { 0,0 };
	Rectangle buttons[cant_menu_buttons];
	Music menu_music;
	int posY = 10;
	int offside = 40;
	int offside_credits = 20;
	float title_divider = 2.5f;


	void start()
	{
		StopMusicStream(background_music);
	}

	void draw_menu()
	{
		title_font_size = 40;
		DrawText("Arkanoid", static_cast<int>(GetScreenWidth() / title_divider), posY, title_font_size, RAYWHITE);

		DrawText("Play",	static_cast<int>(buttons[2].x + offside), static_cast<int>(buttons[2].y), font_size, DARKBROWN);
		DrawText("Credits", static_cast<int>(buttons[1].x + offside_credits), static_cast<int>(buttons[1].y), font_size, DARKBROWN);
		DrawText("Exit",	static_cast<int>(buttons[0].x + offside), static_cast<int>(buttons[0].y),font_size,DARKBROWN);
	}
	void update_menu()
	{
		mouse_pos = GetMousePosition();
		UpdateMusicStream(background_music);

		//Rectangle Draw
		for (int i = 0; i < cant_menu_buttons; i++)
		{
			if (CheckCollisionPointRec(mouse_pos, buttons[i]))
			{
				DrawRectangleRec(buttons[i], LIME);
				if (CheckCollisionPointRec(mouse_pos, buttons[2]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					std::cout << "Voy a jugar!" << std::endl;
					game_state = GAME;
				}
				if (CheckCollisionPointRec(mouse_pos, buttons[1]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					game_state = CREDITS;
					std::cout << "Estoy en creditos!" << std::endl;
				}
				if (CheckCollisionPointRec(mouse_pos, buttons[0]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					std::cout << "Estoy Saliendo!" << std::endl;
					game_state = CLOSE;
				}
			}
			else
				DrawRectangleRec(buttons[i], GREEN);

		}

	}

}


