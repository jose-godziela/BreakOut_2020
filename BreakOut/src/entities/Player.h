#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

namespace Godziela
{
	const int PLAYER1 = 0;
	const int MAX_COLOR = 6;

	extern float posX_player;
	extern float posY_player;
	extern float vel_player;

	struct Player {
		Rectangle rec_init;
		Rectangle rec;
		Vector2 size;
		int score;
		int lives;
		Color color;
		Texture2D texture;
		Image img;
	};
	extern Player player;

	void init_player();
}

#endif