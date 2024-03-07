#ifndef DRAW_H
#define DRAW_H

#include "defs.h"
#include <SDL.h>
#include <structs.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define kNumLightningPts		8

void prepareScene(void);
void presentScene(void);
SDL_Texture* loadTexture(char* filename);
void blit(SDL_Texture* texture, int x, int y);
void blitRect(SDL_Texture* texture, SDL_Rect* src, int x, int y);
void blitRectHW(SDL_Texture* texture, SDL_Rect* src, int x, int y, int w, int h, int frame);
void SetRect(SDL_Rect *rect, int x, int y, int w, int h);
void OffsetRect(SDL_Rect *rect, int x, int y);

extern SDL_Rect		mainWindowRect, backSrcRect, workSrcRect, obSrcRect, playerSrcRect;
extern SDL_Rect flameSrcRect, flameDestRects[2], flameRects[4];
extern SDL_Texture* flameSrcMap;
extern SDL_Texture* obeliskSrcMap;
extern SDL_Point leftLightningPts[kNumLightningPts] , rightLightningPts[kNumLightningPts];



void RenderTorchA(void);
void RenderTorchB(void);
void GenerateLightning(short h, short v);


short Random();
void CreateSeed(void);
short RandomInt(short range);
#endif // DRAW_Hd);