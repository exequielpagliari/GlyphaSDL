#ifndef MAIN_H
#define MAIN_H

#include "common.h"
#include "draw.h"
#include "init.h"
#include "input.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define kNumLightningPts		8

//oid cleanup(void);
SDL_Rect		mainWindowRect, backSrcRect, workSrcRect, obSrcRect, playerSrcRect;
SDL_Rect	obeliskRects[4], playerRects[11], numbersSrc[11], numbersDest[11];
SDL_Rect	flameSrcRect, flameDestRects[2], flameRects[4];

SDL_Texture* flameSrcMap;
SDL_Texture* backSrcMapA;
SDL_Texture* obeliskSrcMap;

SDL_Point leftLightningPts[kNumLightningPts], rightLightningPts[kNumLightningPts];
extern	int		tickNext;
bool Spark = false;
#endif // MAIN_H
