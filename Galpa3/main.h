#ifndef MAIN_H
#define MAIN_H

#include "common.h"
#include "draw.h"
#include "init.h"
#include "input.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

//oid cleanup(void);

SDL_Rect flameSrcRect, flameDestRects[2], flameRects[4];
SDL_Texture* flameSrcMap;
#endif // MAIN_H
