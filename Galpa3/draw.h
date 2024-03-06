#ifndef DRAW_H
#define DRAW_H

#include "common.h"
#include <SDL.h>
#include "structs.h"
#include <stdbool.h>


void prepareScene(void);
void presentScene(void);
SDL_Texture* loadTexture(char* filename);
void blit(SDL_Texture* texture, int x, int y);
void blitRect(SDL_Texture* texture, SDL_Rect* src, int x, int y);
void blitRectHW(SDL_Texture* texture, SDL_Rect* src, int x, int y, int w, int h, int frame);
void SetRect(SDL_Rect rect, int x, int y, int h, int w);
void OffsetRect(SDL_Rect rect, int x, int y);



extern SDL_Rect flameSrcRect, flameDestRects[2], flameRects[4];
extern SDL_Texture* flameSrcMap;
void RenderTorchA(void);
void RenderTorchB(void);
#endif // DRAW_Hd);