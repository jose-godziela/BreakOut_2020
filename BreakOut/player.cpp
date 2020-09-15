#include "player.h"

namespace Godziela_BreakOut
{
	void init_player(Player& player)
	{
		player.rec.width = 80;
		player.rec.height = 20;
		player.rec.x = static_cast<float>(GetScreenWidth() / 2 - player.rec.x);
		player.rec.y = static_cast<float>(GetScreenHeight() - player_offset_y);
		player.color = RED;
	}

	void reset_pos_player(Player& player)
	{
		player.rec.x = GetScreenWidth() / 2 - player.rec.x;
	}
}