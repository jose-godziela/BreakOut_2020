#ifndef BRICK_H
#define BRICK_H

#include "Raylib.h"

namespace Godziela
{
	const int cant_bricks = 80;
	const Vector2 pos_inic = {10,20};
	const int brick_height = 15;
	const int brick_width = 20;
	const int dist_x = 40;
	const int dist_y = 30;



	struct Brick {
		Rectangle rec;
		bool active;
		Image img;
		Texture2D texture;
	};

	extern Brick bricks[cant_bricks];
	extern int screen_width_check;
	extern Color brick_color;


	void init_bricks();
	void draw_bricks();
	void reset_bricks();
}



#endif