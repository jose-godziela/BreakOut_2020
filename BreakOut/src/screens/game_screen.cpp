#include "game_screen.h"


namespace Godziela
{
	bool game_start;
	bool game_pause;
	static float multiplier = 500.0f;
	Texture2D background_texture;
	Image aux;


	void draw_game()
	{
		int pos_instructions = GetScreenWidth() / 2 - 70;
		int instructions_size = 20;
		int texture_offset = 5;

		DrawTexture(background_texture, 0, 0, WHITE);
		
		if (!game_start)
			DrawText("Press Space", pos_instructions, pos_instructions, instructions_size, RED);

		DrawTexture(player.texture, static_cast<int>(player.rec.x), static_cast<int>(player.rec.y), player.color);
		DrawTexture(ball.texture, ball.ball_position.x - ball.ball_radius - texture_offset, ball.ball_position.y - ball.ball_radius - texture_offset, WHITE);
		draw_bricks();


		if (player.lives <= 0) {
			player.lives = reset_lives;
			game_state = END;
		}
		if (game_pause)
		{
			DrawText("GAME PAUSED", static_cast<int>(fourteenth_screen_width), static_cast<int>(third_screen_height), title_font_size, RAYWHITE);
			DrawText("Press Q to return to main menu", static_cast<int>(fourteenth_screen_width), static_cast<int>(third_screen_height + 40), font_size, RAYWHITE);
		}
	}

	void game_update()
	{
		PlayMusicStream(background_music);

		UpdateMusicStream(background_music);
		if (IsKeyPressed(KEY_P) || IsKeyPressed(KEY_ESCAPE))
		{
			game_pause = !game_pause;
		}


		if (!game_pause)
		{
			if (!game_start)
			{
				ball.ball_position.x = player.rec.x + (player.size.y / 2);
			}
			//Points
			if (ball.ball_position.y >= GetScreenHeight())
			{
				//Reset player's position
				player.rec = player.rec_init;
				player.lives--;
				ball.ball_position = ball.ball_position_init;
				ball.ball_speed = ball.ball_speed_init;
				game_start = false;
			}
			//Player-Ball Collition
			if (CheckCollisionCircleRec(ball.ball_position, ball.ball_radius, player.rec)) {

				//Collision with the player
				if (CheckCollisionCircleRec(ball.ball_position, ball.ball_radius, player.rec))
				{
					ball.ball_speed.y = -ball.ball_speed.y;
					ball.ball_speed.x = (ball.ball_position.x - player.rec.x - player.rec.width / 2) / (player.rec.width / 2) * multiplier;
					ball.ball_position.y -= ball.ball_radius;
					if(game_start)
						PlaySound(hit_sound);
				}

			}
			//wall player's collitions
			if (player.rec.x >= GetScreenWidth() - player.size.y) player.rec.x = static_cast<float>(GetScreenWidth()) - player.size.y;
			if (player.rec.x <= 0) player.rec.x = 0;
			if (game_start)
			{
				ball.ball_position.x += ball.ball_speed.x * GetFrameTime();
				ball.ball_position.y += ball.ball_speed.y * GetFrameTime();
			}
			//Ball-walls collitions
			if (ball.ball_position.y <= 0) ball.ball_speed.y *= -1.0f;
			if ((ball.ball_position.x >= (GetScreenWidth() - ball.ball_radius)) || (ball.ball_position.x <= ball.ball_radius)) ball.ball_speed.x *= -1.0f;

			//Ball-Bricks collitions
			for (int i = 0; i < cant_bricks; i++)
			{

				if (CheckCollisionCircleRec(ball.ball_position, ball.ball_radius, bricks[i].rec) && bricks[i].active == true)
				{
					bricks[i].active = false;
					ball.ball_speed.y *= -1.0f;
					ball.ball_speed.x -= speed_up * GetFrameTime();
					ball.ball_speed.y -= speed_up * GetFrameTime();
					ball.ball_position.y -= ball.ball_radius;
					player.score++;
					PlaySound(hit_sound);
				}
			}
		}

	}
}

