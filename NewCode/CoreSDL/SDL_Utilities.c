//
// Created by exepa on 9/26/25.
//

#include "SDL_Utilities.h"


short Random() {

    //Generar y mostrar varios nmeros aleatorios
    return rand();
}

short TickCount() {
    return (short)SDL_GetTicks();
};

void LogNextTick (long howMany)
{
    tickNext = TickCount() + howMany;		// Get machine's TickCount() and add to it.
}

void WaitForNextTick(void) {
    do {
        // printf(("%d\n"), tickNext);
        // printf(("%d\n"),SDL_GetTicks);
    } while ((int)SDL_GetTicks() <
             tickNext); // Loop until TickCount() catches up.
}


Handle NewHandle(Size size) {
    char **h = malloc(sizeof(char*)); // Master pointer
    if (!h) return NULL;

    *h = malloc(size);                 // Bloque real
    if (!*h) {
        free(h);
        return NULL;
    }
    memset(*h, 0, size);                // Inicializamos a cero
    return h;
}

void DisposeHandle(Handle h) {
    if (h) {
        free(*h);  // Libera bloque
        free(h);   // Libera master pointer
    }
}

Texture *loadTexture(char *filename) {
    Texture *texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                   "Loading %s", filename);

    texture = (TexturePtr)IMG_LoadTexture(renderer, filename);
    if (!texture) {
        fprintf(stderr, "Failed to load %s!\n", filename);
    }

    return texture;
}


void SetRect(SDL_Rect *rect, int x, int y, int w, int h) {
    rect->x = x;
    rect->y = y;
    rect->h = h;
    rect->w = w;
}

void OffsetRect(SDL_Rect *rect, int x, int y) {
    rect->x = x;
    rect->y = y;
};

void CopyBits_SDL(SDL_Renderer* ren,
                  TexturePtr srcTex,
                  SDL_Rect* srcRect,
                  SDL_Rect* dstRect)
{
    SDL_RenderCopy(ren, srcTex, srcRect, dstRect);
}

void ZeroRectCorner(SDL_Rect *theRect)
{
    theRect->w -= theRect->x;	// Move right edge by amount of left.
    theRect->h -= theRect->y;	// Move bottom edge by amount of top.
    theRect->x = 0;					// Can now set left to zero.
    theRect->y = 0;					// Can set top edge to zero as well.
}

/*
PicHandle GetPicture(int ResID) {
    return PicHandle pichandle;
}

DHandle GetMainDevice(void) {
    return GDHandle gdhandle;
}

GetGDevice(void) {
    return GDHandle gdhandle;
}

SetGDevice(thisGDevice)

Ptr NewPtrClear(size_t size) {
    return calloc(1, size);
}

Ptr NewPtr(size_t size) {
    return malloc(size);
}

void ParamText(StringPtr,Str15,Str15,Str15) {
}

void SetRect(Rect *rect, int x, int y, int w, int h) {
    rect->x = x;
    rect->y = y;
    rect->h = h;
    rect->w = w;
}

OSErr HandToHand(Handle *h) {
    OSErr err;
    return err;
}

Handle GetResource(OSType type, short value) {
    if (type  == 'snd ') {
        SoundHandle *sound;
        return sound;
    }
}
*/