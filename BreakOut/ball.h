#ifndef BALL_H
#define BALL_H
#include "raylib.h"

namespace Godziela_BreakOut
{

	struct Ball {
		Vector2 ball_position;
		Vector2 ball_position_init;
		Vector2 ball_speed;
		Vector2 ball_speed_init;
		float ball_radius;
		Color color;
		bool active;
		bool p1_hit;
		bool p2_hit;
		int power_up;
	};

	extern Ball ball;
	void init_ball(Ball& ball);
	void reset_ball(Ball& ball);
}
#endif