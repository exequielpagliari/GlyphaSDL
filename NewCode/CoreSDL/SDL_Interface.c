//
// Created by exepa on 10/3/25.
//

#include "SDL_Interface.h"

void HandleEvent(){
SDL_Event ev;
while( SDL_PollEvent( &ev ) )
{
    if( ( SDL_QUIT == ev.type ) ||
        ( SDL_KEYDOWN == ev.type && SDL_SCANCODE_ESCAPE == ev.key.keysym.scancode ) )
    {
        quitting = true;
        break;
    }
}
}