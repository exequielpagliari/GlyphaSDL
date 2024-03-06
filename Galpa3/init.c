#include "init.h"






App app;

void initSDL(void) {
    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;

    windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    app.window = SDL_CreateWindow("Glypha III", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if (!app.window) {
        printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

    if (!app.renderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }
}

void InitVariables(void)
{
    short		i;
    

    
    SetRect(flameSrcRect, 0, 0, 64, 16);
    
    flameDestRects[0].x = 87;
    flameDestRects[0].y = 325;
    flameDestRects[0].w = flameSrcRect.w = 16;
    flameDestRects[0].h = flameSrcRect.h = 16;
    flameSrcRect.x = 0;
    flameSrcRect.y = 0;


    flameDestRects[1].x = 535;
    flameDestRects[1].y = 325;
    flameDestRects[1].w = 16;
    flameDestRects[1].h = 16;

};


//SetRect(&flameSrcRect, 0, 0, 16, 64);