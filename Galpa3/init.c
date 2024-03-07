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
    
    SetRect(&workSrcRect, 0, 0, 640, 480);
    SetRect(&mainWindowRect, 0, 0, 640, 480);
    SetRect(&flameSrcRect, 0, 0, 16, 16);
    SetRect(&flameDestRects[0], 87, 325, 16, 16);
    SetRect(&flameDestRects[1], 535, 325, 16, 16);

    SetRect(&obSrcRect, 0, 0, 20, 209);
    SetRect(&obeliskRects[0], 0, 0, 20, 209);
    OffsetRect(&obeliskRects[0], 0, 0);
    SetRect(&obeliskRects[1], 0, 0, 20, 209);
    OffsetRect(&obeliskRects[1], 0, 209);
    SetRect(&obeliskRects[2], 0, 0, 20, 209);
    OffsetRect(&obeliskRects[2], 161, 250);
    SetRect(&obeliskRects[3], 0, 0, 20, 209);
    OffsetRect(&obeliskRects[3], 457, 250);
};


//SetRect(&flameSrcRect, 0, 0, 16, 64);