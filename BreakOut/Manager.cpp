#include "manager.h"

namespace Godziela_BreakOut
{
	void init();
	void update();
	void update_game();
	void draw();
	void input();
	void reset();
	void deinit();
	//aux
	bool window_open;

	Brick brick[cant_bricks_horz][cant_bricks_vert];
	Player player;
	Ball ball;
	gameState game_state;

	void init()
	{
		SetExitKey(NULL);
		init_bricks();
		init_ball(ball);
		init_player(player);
	}


	void input()
	{
		if (IsKeyDown(KEY_LEFT))
			player.rec.x -= VEL_PLAYER * GetFrameTime();
		if (IsKeyDown(KEY_RIGHT))
			player.rec.x += VEL_PLAYER * GetFrameTime();
	}

	void draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		DrawText("Here should be the breakout game", GetScreenWidth() / 3 - 30, GetScreenHeight() / 2, GAME_FONT, RED);

		switch (game_state)
		{
		case gameState::MENU:
		{
			//draw_menu();
			//button_action();
		}
		break;
		case gameState::GAME:
		{
			//draw_game();
		}
		break;
		case gameState::CREDITS:
		{
			//draw_credits();
		}break;
		case gameState::CONTROL_SCREEN:
		{
			//draw_change_controls();
		}break;
		}

		EndDrawing();
	}

	void update()
	{

	}

	void deinit()
	{

	}

	void reset()
	{
		reset_pos_player(player);
		reset_ball(ball);
	}

	void start_game()
	{
		InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Window Test");
		window_open = true;
		SetTargetFPS(FPS);
		init();

		while (!WindowShouldClose() && window_open)
		{
			input();
			draw();
			update();
		}


		deinit();
		if (window_open)
			CloseWindow();

	}
}