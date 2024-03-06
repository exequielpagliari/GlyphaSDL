#ifndef INIT_H
#define INIT_H

#include "common.h"

#include <SDL_image.h>
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "structs.h"
#include "draw.h"

extern SDL_Rect		mainWindowRect, backSrcRect, workSrcRect, obSrcRect, playerSrcRect;
extern SDL_Rect		obeliskRects[4], playerRects[11], numbersSrc[11], numbersDest[11];
extern SDL_Rect flameSrcRect, flameDestRects[2], flameRects[4];
extern SDL_Texture* flameSrcMap;
extern	SDL_Texture* obeliskSrcMap;
void initSDL(void);
void InitVariables(void);
#endif // INIT_H
