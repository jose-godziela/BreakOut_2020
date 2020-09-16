#include "manager.h"

namespace Godziela
{
	Color base_background;

	static void init();
	static void close_all();
	void game();

	void play()
	{
		init();
		game();
	}


	static void update()
	{
		switch (game_state)
		{
		case MENU:
		{
			update_menu();
			break;
		}
		case GAME:
		{
			game_update();
			break;
		}
		case END:
		{
			draw_game_over();
			break;
		}
		case CLOSE:
		{
			close_all();
			break;
		}
		}

	}

	static void input()
	{
		if (game_pause)
		{
			if (IsKeyPressed(KEY_Q))
			{
				game_start = false;
				game_pause = !game_pause;
				reset_bricks();
				reset_ball();
				game_state = MENU;
			}

			return;
		}
		if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) 
			player.rec.x -= vel_player * GetFrameTime();
		if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) 
			player.rec.x += vel_player * GetFrameTime();

		if (IsKeyPressed(KEY_SPACE) && game_state == GAME) 
		{
			game_start = true;
		}
		
	}

	static void draw()
	{
		if (game_state != CLOSE)
		{
			BeginDrawing();
			ClearBackground(base_background);
			switch (game_state) {
			case MENU:
				draw_menu();
				break;
			case GAME: {
				draw_game();
				break;
			}
			case CREDITS:
			{
				draw_credits();
				break;
			}
			case END: {
				draw_game_over();
				break;
			}
			}
			EndDrawing();
		}
	}

	static void close_texture()
	{
		//When the game has some texture, here's the Unload of them
		UnloadTexture(background_texture);
		UnloadTexture(player.texture);
		UnloadTexture(ball.texture);

		for (int i = 0; i < cant_bricks; i++)
		{
			UnloadTexture(bricks[i].texture);
		}
	}

	static void close_all()
	{
		//When the game has some audio, these are the close variables
		//If hit_sound error is solved
		close_audio();
		close_texture();
		CloseWindow();
	}

	static void init_buttons()
	{
		int buttons_Y = screenHeight - 140;

		for (int i = 0; i < cant_menu_buttons; i++)
		{
			buttons[i].height = REC_HEIGHT;
			buttons[i].width = REC_WIDTH;
			buttons[i].x = static_cast<float>(buttons_X);
			buttons[i].y = static_cast<float>(buttons_Y);
			buttons_Y -= 45;

		}
	}

	void init_background()
	{
		Image aux = LoadImage("res/background.png");

		ImageResize(&aux, screenWidth, screenHeight);

		background_texture = LoadTextureFromImage(aux);

		UnloadImage(aux);
	}

	void init()
	{
		InitWindow(screenWidth, screenHeight, "Arkanoid");
		SetExitKey(NULL);

		//frames = 0;
		init_audio();
		init_player();
		init_ball();
		init_buttons();
		init_bricks();
		init_game_over();
		base_background = BLACK;
		init_background();

		//gameState = MENU;
	}

	void game()
	{
		while (!WindowShouldClose() && game_state != CLOSE)
		{
			input();
			update();
			draw();
		}
		close_all();
	}

}

