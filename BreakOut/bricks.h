#ifndef BRICKS_H
#define BRICKS_H
#include "raylib.h"

const int cant_bricks_vert = 5;
const int cant_bricks_horz = 20;
const int BRICKS_WIDTH = 40;
const int RANDOM_POWER_UP_SET = 30;

namespace Godziela_BreakOut
{
	struct Brick
	{
		Vector2 position;
		Vector2 size;
		bool active;
	};

	extern Brick brick[cant_bricks_horz][cant_bricks_vert];


	void init_bricks();

}



#endif