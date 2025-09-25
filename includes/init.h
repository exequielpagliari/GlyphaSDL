#ifndef INIT_H
#define INIT_H

#include "defs.h"
#include "draw.h"
#include "structs.h"
#include <SDL2/SDL.h>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>

extern App app;
extern SDL_Rect mainWindowRect, backSrcRect, workSrcRect, obSrcRect,
    playerSrcRect;
extern SDL_Rect obeliskRects[4], playerRects[11], numbersSrc[11],
    numbersDest[11];
extern SDL_Rect flameSrcRect, flameDestRects[2], flameRects[4];
extern SDL_Texture *backSrcMapA;
// extern SDL_Texture* flameSrcMap;
extern SDL_Texture *obeliskSrcMap;
void initSDL(void);
void InitVariables(void);
#endif // INIT_H
