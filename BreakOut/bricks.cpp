#include "bricks.h"

namespace Godziela_BreakOut
{
	//aux
	short brick_y_offset = 50;

	void init_bricks()
	{
		for (int i = 0; i < cant_bricks_horz; i++)
		{
			for (int j = 0; j < cant_bricks_vert; j++)
			{
				brick[i][j].size = {static_cast<float>(GetScreenWidth() / cant_bricks_horz), BRICKS_WIDTH};
				brick[i][j].position = { j * brick[i][j].size.x + brick[i][j].size.x / 2, i * brick[i][j].size.y + brick_y_offset };
				brick[i][j].active = true;
			}
		}



	}

	void reset_bricks()
	{
		for (int i = 0; i < cant_bricks_horz; i++)
		{
			for (int j = 0; j < cant_bricks_vert; j++)
			{
				brick[i][j].active = true;
			}
		}
	}

}