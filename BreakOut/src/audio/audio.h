#ifndef AUDIO_H
#define AUDIO_H
#include "raylib.h"

namespace Godziela
{
	const float master_volume = 30.0f;

	extern Music background_music;
	extern Sound hit_sound;

	void init_audio();
	void close_audio();
}


#endif