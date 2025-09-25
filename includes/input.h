#ifndef INPUT_H
#define INPUT_H

#include "defs.h"
#include "draw.h"
#include "sound.h"
#include "structs.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

extern App app;
void doInput(void);
void HandleMouseEvent(void);
extern bool Spark;
#endif // INPUT_H
