#include "ball.h"

namespace Godziela
{
	Ball ball;

	void init_ball()
	{
		int triple = 3;
		//Ball Creation
		ball.ball_speed_init.x = 350.0f;
		ball.ball_speed_init.y = 400.0f;
		ball.ball_speed = ball.ball_speed_init;
		ball.ball_radius = 10;
		ball.color = WHITE;
		ball.ball_position_init.x = static_cast<float>(GetScreenHeight() - 30);
		ball.ball_position_init.y = player.rec.y - ball.ball_radius;
		ball.ball_position = ball.ball_position_init;

		ball.img = LoadImage("res/ball.png");

		ImageResize(&ball.img, ball.ball_radius * triple, ball.ball_radius * triple);

		ball.texture = LoadTextureFromImage(ball.img);

		UnloadImage(ball.img);

	}
	void reset_ball()
	{
		init_ball();
	}
}

