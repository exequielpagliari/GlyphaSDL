//
// Created by exepa on 10/3/25.
//

#include "include/CoreSDL/SDL_Interface.h"
#include <stdio.h>

extern Point mousePoint;
void HandleMouseEvent();
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

    if (ev.type == SDL_MOUSEBUTTONDOWN) {
        if (ev.button.button == SDL_BUTTON_LEFT) {
            printf("Left mouse button clicked\n");
            int mouseX = ev.button.x;
            int mouseY = ev.button.y;
			mousePoint.x = mouseX;
            mousePoint.y = mouseY;
			printf("Mouse position: (%d, %d)\n", mouseX, mouseY);
            HandleMouseEvent();
        }
    }
}
}