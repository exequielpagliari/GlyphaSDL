#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Str15 {
	char data[16];
}Str15;


typedef struct Str255 {
	char data[256];
} Str255;

typedef struct prefsInfo
{
	short		prefVersion, filler;
	Str255		highName;
	Str15		highNames[10];
	long		highScores[10];
	short		highLevel[10];
	short		wasVolume;
} prefsInfo;

short Random();					// Utilities.c
short RandomInt(short);				
/*void RedAlert(StringPtr);
void FindOurDevice(void);
void LoadGraphic(short);
void CreateOffScreenPixMap(Rect*, CGrafPtr*);
void CreateOffScreenBitMap(Rect*, GrafPtr*);
void ZeroRectCorner(Rect*);
void FlashShort(short);
void LogNextTick(long);
void WaitForNextTick(void);
bool TrapExists(short);
bool DoWeHaveGestalt(void);
void CenterAlert(short);
short RectWide(Rect*);
short RectTall(Rect*);
void CenterRectInRect(Rect*, Rect*);
void PasStringCopy(StringPtr, StringPtr);
void CenterDialog(short);
void DrawDefaultButton(DialogPtr);
void PasStringCopyNum(StringPtr, StringPtr, short);
void GetDialogString(DialogPtr, short, StringPtr);
void SetDialogString(DialogPtr, short, StringPtr);
void SetDialogNumToStr(DialogPtr, short, long);
void GetDialogNumFromStr(DialogPtr, short, long*);
void DisableControl(DialogPtr, short);
*/