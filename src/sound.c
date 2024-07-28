
#include "sound.h"

void initSounds(void)
{
	memset(sounds, 0, sizeof(Mix_Chunk*) * SND_MAX);

	music = NULL;

	loadSounds();

	
}




static void loadSounds(void)
{
	
	sounds[SND_PLAYER_FIRE] = Mix_LoadWAV("Snd/Lightning.wav");


}

void loadMusic(char* filename)
{
	if (music != NULL)
	{
		Mix_HaltMusic();
		Mix_FreeMusic(music);
		music = NULL;
	}

	music = Mix_LoadMUS(filename);
}

void playSound(int id, int channel)
{
	Mix_PlayChannel(channel, sounds[id], 0);
}