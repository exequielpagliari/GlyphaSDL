//
// Created by exepa on 9/27/25.
//

#ifndef NEWCODE_SDL_UTILITIES_H
#define NEWCODE_SDL_UTILITIES_H
#include <stddef.h>
#include <SDL2/SDL_image.h>

typedef uint8_t Color;
#define blackColor  0x00000011;
#define whiteColor  0x11111111;
typedef char Byte;
typedef enum { false, true, FALSE= 0, TRUE } Boolean;
typedef unsigned char Str255[256];
typedef unsigned char Str15[16];
typedef void* Ptr;
Boolean noErr = false;
/* primary form */

typedef struct PixMap {
    int pixelSize;

} PixMap;



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
    void* baseAddr;
    short rowBytes;
    Rect bounds;
} BitMap;

typedef struct {
    short rgnSize;
    Rect rgnBBox;
    char rgnData[];
}
Region, *RgnPtr, **RgnHandle;

typedef struct {
    BitMap screenBits;
    PixMap PixMap;
    RgnHandle clipRgn;
    RgnHandle visRgn;
}GrafPort, *GrafPtr;

GrafPort qd;

typedef struct {
    PixMap portPixMap;
    RgnHandle clipRgn;
    RgnHandle visRgn;
}CGrafPort, *CGrafPtr;

typedef struct {
    PixMap portPixMap;
}String, *StringPtr;

typedef struct {

}Dialog, *DialogPtr;



typedef struct GDHandle {
    PixMap portPixMap;
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
Boolean MemError(void);
typedef struct OSErr {

} OSErr;






//----------------------------------------------------------
//               Métodos MacOs Dibujado
//----------------------------------------------------------



typedef struct HandleStruct {
    void* ptr;
    int lockCount;
    Rect boundsRect;
} HandleStruct;

typedef HandleStruct** Handle;

typedef struct AlertTHndl {
    Rect boundsRect;
} alertTHndl;

typedef HandleStruct **AlertTHndl;

typedef struct dialogTHndl {

} dialogTHndl;

typedef HandleStruct **DialogTHndl;

typedef struct PictureStruct {

    Rect picFrame;
    short picSize;
    SDL_Texture* sdlTexture;
} Picture, **PicHandle;

PicHandle GetPicture(int ResID);



typedef struct CTabHandle {

} CTabHandle;



void OffsetRect(Rect *rect, int x, int y);
void DrawPicture(PicHandle pic, Rect *rect);
void ReleaseResource(PicHandle);
void HLock(Handle h);
void HUnlock(Handle h);
void OpenCPort(CGrafPtr h);
void OpenPort(GrafPort *h);
void CloseCPort(CGrafPtr h);
OSErr HandToHand(Handle *h);
void ClipRect(Rect *rect);
void RectRgn(RgnHandle rgn, const Rect* rect);
void ForeColor(uint8_t color);
void BackColor(uint8_t color);
void EraseRect(Rect *rect);
void DisposePtr(Ptr *ptr);
void SetPortBits(BitMap *bitMap);
void GetPort(GrafPtr *port);
void NumToString(long value, Str255 string);
void MoveTo(short x, short y);
void SetRect(Rect *rect, int left, int top, int right , int bottom);
void DrawString(Str255 string);
void ClosePort(GrafPtr graf_ptr);
void SetPort(GrafPtr graf_ptr);
short LMGetMBarHeight(void);

Handle GetResource(Str15 str, short value);
Byte HGetState(AlertTHndl h);
short Random(void);
short TickCount(void);

#endif //NEWCODE_SDL_UTILITIES_H