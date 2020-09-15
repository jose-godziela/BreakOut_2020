#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

const float VEL_PLAYER = 385.0f;
const int player_offset_y = 50;
namespace Godziela_BreakOut
{

	struct Player {
		Rectangle rec;
		int score;
		Color color;
	};

	extern Player player;

	void init_player(Player& player);
	void reset_pos_player(Player& player);
}
#endif