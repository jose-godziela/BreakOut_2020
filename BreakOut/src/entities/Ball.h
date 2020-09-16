#ifndef BALL_H
#define BALL_H
#include "raylib.h"

#include "Player.h"

namespace Godziela
{
	//Personal Prefference when writing structs
	struct Ball {
		Vector2 ball_position_init;
		Vector2 ball_position;
		Vector2 ball_speed_init;
		Vector2 ball_speed;
		float ball_radius;
		Color color;
		Texture2D texture;
		Image img;
	};
	extern Ball ball;
	void init_ball();
	void reset_ball();
}

#endif