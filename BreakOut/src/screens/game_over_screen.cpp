#include "game_over_screen.h"

namespace Godziela
{
	int frames;
	int draw_x;
	int draw_y;
	int title_font_size;
	int font_size;
	int diff_y;

	void init_game_over()
	{
		frames = 0;
		draw_x = static_cast<int>(GetScreenWidth() / 6);
		draw_y = (GetScreenHeight() / 4);
		title_font_size = 30;
		font_size = 20;
		diff_y = draw_y + (title_font_size * 2);
	}

	void change_screen()
	{
		player.score = 0;
		game_start = false;
		game_state = MENU;
		frames = 0;
	}

	void draw_game_over()
	{
		DrawText("GAME OVER", draw_x, draw_y, title_font_size, RED);

		DrawText(FormatText("Points: %i", player.score), draw_x, diff_y, title_font_size, BLUE);
		frames++;

		if (frames > game_over_time)
		{
			change_screen();
		}
	}
}

