#include "Player.h"

namespace Godziela
{
	float posX_player = 0;
	float posY_player = 0;
	float vel_player = 375.0f;
	Player player;

	void init_player()
	{

		//Players Creation
		player.score = 0;
		player.lives = 3;
		player.size.x = 10.0f;
		player.size.y = 50.0f;
		posX_player = static_cast<float>((GetScreenWidth() / 2) - player.size.y);
		posY_player = static_cast<float>((GetScreenWidth() / 2));

		player.rec_init.x = posX_player;
		player.rec_init.y = posY_player;

		player.rec_init.width = player.size.y;
		player.rec_init.height = player.size.x;

		player.rec = player.rec_init;
		player.color = BLUE;

		//Player Texture
		player.img = LoadImage("res/player.png");

		ImageResize(&player.img, player.rec.width, player.rec.height);

		player.texture = LoadTextureFromImage(player.img);

		UnloadImage(player.img);
	}
}

