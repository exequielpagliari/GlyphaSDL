//
// Created by exepa on 9/27/25.
//
#pragma once
#include <stddef.h>
#include <SDL2/SDL_image.h>
#ifndef NEWCODE_SDL_UTILITIES_H
#define NEWCODE_SDL_UTILITIES_H


typedef uint8_t Color;
#define blackColor  0x000000FF
#define whiteColor  0xFFFFFFFF
#define ToolTrap 0

typedef enum { false , true, FALSE= 0, TRUE } Boolean;
typedef unsigned char Str255[256];
typedef unsigned char Str15[16];
typedef char Byte;
typedef unsigned long Size;
typedef char* Ptr;
typedef Ptr* Handle;
typedef unsigned short SmallFract;
typedef unsigned long OSType;

extern SDL_Renderer *renderer;
extern SDL_Window *window;

extern Boolean noErr;

typedef struct {
    SmallFract red;
    SmallFract green;
    SmallFract blue;
}RGBColor;

typedef struct colorSpec
{
    short value;
    RGBColor rgb;
} ColorSpec;

typedef ColorSpec CSpecArray[];

typedef struct colorTable {
    long ctSeed;
    short ctFlags;
    short ctSize;
    CSpecArray ctTable;
} ColorTable;

typedef ColorTable *CTabPtr;
typedef CTabPtr *CTabHandle;

typedef struct
{
    short left;
    short right;
    short bottom;
    short top;
}
Rect;

typedef struct PixMap {
    int pixelSize;
    Ptr baseAddr;
    short rowBytes;
    Rect bounds;
    CTabHandle pmTable;
} PixMap;

typedef PixMap *PixMapPtr;
typedef PixMapPtr *PixMapHandle;

Handle NewHandle(Size size);
void DisposeHandle(Handle h);

typedef struct {
    Ptr baseAddr;
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
    PixMapHandle portPixMap;
    RgnHandle clipRgn;
    RgnHandle visRgn;
}GrafPort, *GrafPtr;

//GrafPort qd;

typedef struct {
    PixMapHandle portPixMap;
    RgnHandle clipRgn;
    RgnHandle visRgn;
}CGrafPort;

typedef CGrafPort *CGrafPtr;
typedef CGrafPort** CGrafPortHandle;

typedef unsigned char *StringPtr;

typedef struct {

}Dialog, *DialogPtr;

typedef struct control {

} Control, **ControlHandle;



typedef struct GDHandle {
    PixMapHandle gdPMap;
    CGrafPortHandle grafPort;

}GDevice, *GDPtr, **GDHandle;

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
void SetGDevice(GDHandle gdHandle);

typedef unsigned short OSErr;


//----------------------------------------------------------
//               Métodos MacOs Dibujado
//----------------------------------------------------------



typedef struct HandleStruct {
    void* ptr;
    int lockCount;

} HandleStruct;




typedef struct alertTHndl {
    Rect bounds;
    int lockCount;
    Rect boundsRect;
} AlertType, **AlertTHndl;

typedef struct dialog {
    Rect bounds;
    int lockCount;
    Rect boundsRect;
} dialog, **DialogTHndl;

typedef struct PictureStruct {

    Rect picFrame;
    short picSize;
} Picture, PicPtr, **PicHandle;

typedef struct point {
    short x, y;
} Point, **PointPtr;

typedef Handle **SoundHandle;





void OffsetRect(Rect *rect, int x, int y);
void DrawPicture(PicHandle pic, Rect *rect);
PicHandle GetPicture(int ResID);
void ReleaseResource(PicHandle picHandle);
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
void DisposePtr(Ptr ptr);
void SetPortBits(BitMap *bitMap);
void GetPort(GrafPtr *port);
void NumToString(long value, Str255 string);
void MoveTo(short x, short y);
void SetRect(Rect *rect, int x, int y, int w, int h);
void DrawString(Str255 string);
void ClosePort(GrafPtr graf_ptr);
void SetPort(GrafPtr graf_ptr);
short LMGetMBarHeight(void);
Handle GetResource(OSType type, short value);
Byte HGetState(AlertTHndl h);
void HSetState(Handle handle, Byte state);
void GetDItem(DialogPtr ptr, short sh,short *itemType , Handle *h, Rect *rect);
void GetIText(Handle h, StringPtr string);
void SetIText(Handle h, StringPtr string);
void StringToNum(Str255 string, long *number);
void InsetRect(Rect *rect, short v, short h);
void PenSize(short x, short y);
void FrameRoundRect(Rect *rect, short x, short y);
void PenNormal(void);
Boolean NGetTrapAddress(short trapNumber, short toolTrapNumber);
OSErr ResError(void);
OSErr MemError(void);

long GetHandleSize(Handle h);
short Random(void);
short TickCount(void);
void HiliteControl(ControlHandle h, int i);
void BlockMove(Ptr ptr, Ptr ptr2, long dataSize);


//Sound
typedef struct preferences {

} Preference, *PreferencePrt, **PreferenceHandle;

void SetSoundVol(short volumenValue);
void GetSoundVol(short *volumenValue);


//main
void SysBeep(int count);

// SetupTakeDown

typedef struct window {

} Window, *WindowPtr, **WindowHandle;

RgnHandle NewRgn(void);		// Create empty new region.
void OpenRgn(void);
void LineTo(short x, short y);
void CloseRgn(RgnHandle rgnHandle);
void MoveHHi(Handle h);

typedef struct menu {

} Menu, *MenuPtr, **MenuHandle;

typedef int KeyMap;
#endif //NEWCODE_SDL_UTILITIES_H