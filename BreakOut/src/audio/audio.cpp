#include "audio.h"



namespace Godziela
{
	Music background_music;
	Sound hit_sound;
	Wave aux;
	void init_audio()
	{
		InitAudioDevice();
		SetMasterVolume(master_volume);
		background_music = LoadMusicStream("res/music/Cheetamen.ogg");
		aux = LoadWave("res/music/hit_effect.wav");
		hit_sound = LoadSoundFromWave(aux);

		UnloadWave(aux);
	}

	void close_audio()
	{
		UnloadMusicStream(background_music);
		UnloadSound(hit_sound);
		CloseAudioDevice();
	}
}

