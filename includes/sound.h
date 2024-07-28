#pragma once
#include "defs.h"
#include <SDL.h>
#include <SDL_audio.h>
#include <SDL_mixer.h>
void initSounds(void);
static void loadSounds(void);
void playSound(int id, int channel);

Mix_Music *music;
Mix_Chunk *sounds[4];
