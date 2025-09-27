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
typedef void* Ptr;
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
GDHandle GetGDevice(void);
Ptr NewPtrClear(size_t size);
Ptr NewPtr(size_t size);
void SetGDevice(GDHandle handle);
typedef struct OSErr {

} OSErr;


//----------------------------------------------------------
//               Métodos MacOs Dibujado
//----------------------------------------------------------



typedef struct HandleStruct {
    void* ptr;
    int lockCount;
} HandleStruct;

typedef HandleStruct** Handle;


typedef struct PictureStruct {

    Rect picFrame;
    short picSize;
    SDL_Texture* sdlTexture;
} Picture, **PicHandle;

PicHandle GetPicture(int ResID);

typedef struct {
    void* baseAddr;
    short rowBytes;
    Rect bounds;
} BitMap;

typedef struct CTabHandle {

} CTabHandle;

void OffsetRect(Rect *rect, int x, int y);
void DrawPicture(PicHandle pic, Rect *rect);
void ReleaseResource(PicHandle);
short Random(void);

#endif //NEWCODE_SDL_UTILITIES_H