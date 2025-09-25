//
// Created by exepa on 9/25/25.
//

#include <SDL2/SDL.h>
#include "../includes/common.h"


void LogNextTick(int howMany) {
    tickNext =
        (int)SDL_GetTicks() + howMany; // Get machine's TickCount() and add to it.
}

void WaitForNextTick(void) {
    do {
        // printf(("%d\n"), tickNext);
        // printf(("%d\n"),SDL_GetTicks);
    } while ((int)SDL_GetTicks() <
             tickNext); // Loop until TickCount() catches up.
}