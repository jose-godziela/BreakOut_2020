#include "bricks.h"

namespace Godziela
{
	Color brick_color;

	Brick bricks[cant_bricks];

	Vector2 pos_aux;

	int screen_width_check;

	void init_bricks()
	{
		screen_width_check = GetScreenWidth();
		pos_aux = pos_inic;
		for (int i = 0; i < cant_bricks; i++)
		{
			//Init bricks
			bricks[i].active = true;
			bricks[i].rec.x = pos_aux.x;
			bricks[i].rec.y = pos_aux.y;
			bricks[i].rec.width = brick_width;
			bricks[i].rec.height = brick_height;
			bricks[i].active = true;
			pos_aux.x += dist_x;

			//Space in Y axis
			if (pos_aux.x >= screen_width_check)
			{
				pos_aux.x = pos_inic.x;
				pos_aux.y += dist_y;
			}
			bricks[i].img = LoadImage("res/brick.png");

			ImageResize(&bricks[i].img, bricks[i].rec.width, bricks[i].rec.height);

			bricks[i].texture = LoadTextureFromImage(bricks[i].img);

			UnloadImage(bricks[i].img);
		}
	}

	void draw_bricks()
	{
		for (int i = 0; i < cant_bricks; i++)
		{
			if (bricks[i].active == true)
			{
				if (i % 2 == 0)
					brick_color = BLUE;
				else
					brick_color = YELLOW;

				DrawTexture(bricks[i].texture, bricks[i].rec.x, bricks[i].rec.y, brick_color);
			}

		}

	}
	void reset_bricks()
	{
		for (int i = 0; i < cant_bricks; i++)
		{
			bricks[i].active = true;
		}
	}
}
