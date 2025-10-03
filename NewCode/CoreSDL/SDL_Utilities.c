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