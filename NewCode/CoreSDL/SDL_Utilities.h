//
// Created by exepa on 9/27/25.
//

#ifndef NEWCODE_SDL_UTILITIES_H
#define NEWCODE_SDL_UTILITIES_H
#include <stddef.h>
#include <SDL2/SDL_image.h>

typedef enum { false, true, FALSE= 0, TRUE } Boolean;
typedef unsigned char Str255[256];
typedef unsigned char Str15[16];

/* primary form */

typedef struct
{

    short left;
    short top;
    short right;
    short bottom;
    int picFrame;
}
Rect;

typedef struct {

}GrafPort, *GrafPtr;

typedef struct {

}CGrafPort, *CGrafPtr;

typedef struct {

}String, *StringPtr;

typedef struct {

}Dialog, *DialogPtr;


typedef struct GDHandle {

}GDHandle;

//----------------------------------------------------------
//               Métodos MacOs Sistema
//----------------------------------------------------------
void ParamText(StringPtr,Str15,Str15,Str15);
void ExitToShell(void);
short Alert(int, short);
GDHandle GetMainDevice(void);


//----------------------------------------------------------
//               Métodos MacOs Dibujado
//----------------------------------------------------------



typedef struct HandleStruct {
    void* ptr;
    int lockCount;
} HandleStruct;

typedef HandleStruct** Handle;


typedef struct MyPictureStruct {

    Rect picFrame;
    short picSize;
    SDL_Texture* sdlTexture;
} Picture, **PicHandle;

PicHandle GetPicture(int ResID);





short Random(void);

#endif //NEWCODE_SDL_UTILITIES_H