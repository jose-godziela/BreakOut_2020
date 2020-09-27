#include "Credits.h"

namespace Godziela
{
	short time = 12000;
	short aux = 0;
	short doub = 2;

	void draw_credits()
	{
		short offside = third_screen_height;


		DrawText("Programming: Felix Godziela", fourteenth_screen_width, offside, font_size, RED);

		offside += font_size * doub;

		DrawText("Graphics: Felix Godziela - photoshop", fourteenth_screen_width, offside, font_size, RED);

		offside += font_size * doub;

		DrawText("Music: Cheetamen - Action 52", fourteenth_screen_width, offside, font_size, RED);

		offside += font_size * doub;

		DrawText("BackGround Image: https://tipsmake.com/100-beautiful-background-png", fourteenth_screen_width, offside, font_size, RED);

		//

		aux++;
		if (aux >= time || IsKeyPressed(KEY_ESCAPE))
		{
			game_state = MENU;
			aux = 0;
		}

	}
}