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



extern SDL_Rect flameSrcRect, flameDestRects[2], flameRects[4];
extern SDL_Texture* flameSrcMap;
void initSDL(void);
void InitVariables(void);
#endif // INIT_H
