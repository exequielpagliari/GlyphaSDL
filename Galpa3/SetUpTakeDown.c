//============================================================================
//----------------------------------------------------------------------------
//								SetUpTakeDown.c
//----------------------------------------------------------------------------
//============================================================================
// 
// The below functions are grouped here becuase they are only called once whenÉ
// Glypha either starts up or quits.
/*
#include "Externs.h"

//#include <Palettes.h>					// Need "Palettes.h" for the depth calls.

#define kHandPictID				Img/128.bmp		// These are all the resource ID's forÉ
#define kHandMaskID				Img/129.bmp		// the various PICT's were going toÉ
#define kBackgroundPictID		"Img/130.bmp"		// load up into offscreen pixmaps andÉ
#define kHelpPictID				Img/131.bmp		// offscreen bitmaps.
#define kObeliskPictID			Img/134.bmp
#define kPlayerPictID			Img/135.bmp
#define kPlayerMaskID			Img/136.bmp
#define kNumberPictID			Img/137.bmp
#define kIdlePictID				Img/138.bmp
#define kEnemyWalkPictID		Img/139.bmp
#define kEnemyFlyPictID			Img/140.bmp
#define kEnemyWalkMaskID		141.bmp
#define kEnemyFlyMaskID			142.bmp
#define kFlamePictID			143.bmp
#define kEggPictID				144.bmp
#define kEggMaskID				145.bmp
#define kPlatformPictID			146.bmp
#define kEyePictID				147.bmp
#define kEyeMaskID				148.bmp


void InitVariables(void)
{
	short		i;

	quitting = FALSE;	// I won't describe every one of these, many areÉ
	playing = FALSE;	// self explanatory.  Suffice it to say that firstÉ
	pausing = FALSE;	// I'm initializing all the Boolean variables.
	canPlay = FALSE;
	whichList = TRUE;
	helpOpen = FALSE;
	scoresOpen = FALSE;
	openTheScores = FALSE;

	numLedges = 3;					// Number of ledges in the "arena".
	beginOnLevel = 1;				// First level to begin playing.
	levelOn = 0;					// Level number player is on.
	livesLeft = kInitNumLives;		// Number of player lives.
	theScore = 0L;					// Player's score (notice it's a long!).
	wasTensOfThousands = 0L;		// For tracking when player gets an extra life.
	GenerateLightning(320, 240);	// Initialize a lightning bolt.

	
	backSrcRect = mainWindowRect;	// Create background offscreen pixmap.
	ZeroRectCorner(&backSrcRect);
	backSrcMap = 0L;
	CreateOffScreenPixMap(&backSrcRect, &backSrcMap);
	LoadGraphic(kBackgroundPictID);

	workSrcRect = mainWindowRect;	// Create "work" offscreen pixmap.
	ZeroRectCorner(&workSrcRect);
	workSrcMap = 0L;
	CreateOffScreenPixMap(&workSrcRect, &workSrcMap);

	SetRect(&obSrcRect, 0, 0, 20, 418);
	obeliskSrcMap = 0L;				// Create pixmap to hold "obelisk" graphics.
	CreateOffScreenPixMap(&obSrcRect, &obeliskSrcMap);
	LoadGraphic(kObeliskPictID);
	SetRect(&obeliskRects[0], 0, 0, 20, 209);
	OffsetRect(&obeliskRects[0], 0, 0);
	SetRect(&obeliskRects[1], 0, 0, 20, 209);
	OffsetRect(&obeliskRects[1], 0, 209);
	SetRect(&obeliskRects[2], 0, 0, 20, 209);
	OffsetRect(&obeliskRects[2], 161, 250);
	SetRect(&obeliskRects[3], 0, 0, 20, 209);
	OffsetRect(&obeliskRects[3], 457, 250);

	SetRect(&playerSrcRect, 0, 0, 48, 436);
	playerSrcMap = 0L;				// Create pixmap to hold "player" graphics.
	CreateOffScreenPixMap(&playerSrcRect, &playerSrcMap);
	LoadGraphic(kPlayerPictID);
	playerMaskMap = 0L;
	CreateOffScreenBitMap(&playerSrcRect, &playerMaskMap);
	LoadGraphic(kPlayerMaskID);

	SetRect(&enemyWalkSrcRect, 0, 0, 48, 576);
	enemyWalkSrcMap = 0L;			// Create pixmap to hold "enemy" graphics.
	CreateOffScreenPixMap(&enemyWalkSrcRect, &enemyWalkSrcMap);
	LoadGraphic(kEnemyWalkPictID);
	enemyWalkMaskMap = 0L;
	CreateOffScreenBitMap(&enemyWalkSrcRect, &enemyWalkMaskMap);
	LoadGraphic(kEnemyWalkMaskID);
	SetRect(&enemyFlySrcRect, 0, 0, 64, 480);
	enemyFlySrcMap = 0L;
	CreateOffScreenPixMap(&enemyFlySrcRect, &enemyFlySrcMap);
	LoadGraphic(kEnemyFlyPictID);
	enemyFlyMaskMap = 0L;
	CreateOffScreenBitMap(&enemyFlySrcRect, &enemyFlyMaskMap);
	LoadGraphic(kEnemyFlyMaskID);
	for (i = 0; i < 12; i++)
	{								// Set up enemy source rectangles.
		SetRect(&enemyRects[i], 0, 0, 48, 48);
		OffsetRect(&enemyRects[i], 0, 48 * i);
	}
	for (i = 0; i < 12; i++)
	{
		SetRect(&enemyRects[i + 12], 0, 0, 64, 40);
		OffsetRect(&enemyRects[i + 12], 0, 40 * i);
	}
	SetRect(&enemyInitRects[0], 0, 0, 48, 1);
	OffsetRect(&enemyInitRects[0], 72, 284);
	SetRect(&enemyInitRects[1], 0, 0, 48, 1);
	OffsetRect(&enemyInitRects[1], 520, 284);
	SetRect(&enemyInitRects[2], 0, 0, 48, 1);
	OffsetRect(&enemyInitRects[2], 72, 105);
	SetRect(&enemyInitRects[3], 0, 0, 48, 1);
	OffsetRect(&enemyInitRects[3], 520, 105);
	SetRect(&enemyInitRects[4], 0, 0, 48, 1);
	OffsetRect(&enemyInitRects[4], 296, 190);

	SetRect(&eggSrcRect, 0, 0, 24, 24);
	eggSrcMap = 0L;					// Create pixmap to hold "egg" graphics.
	CreateOffScreenPixMap(&eggSrcRect, &eggSrcMap);
	LoadGraphic(kEggPictID);
	eggMaskMap = 0L;
	CreateOffScreenBitMap(&eggSrcRect, &eggMaskMap);
	LoadGraphic(kEggMaskID);

	SetRect(&eyeSrcRect, 0, 0, 48, 124);
	eyeSrcMap = 0L;					// Create pixmap to hold "eye" graphics.
	CreateOffScreenPixMap(&eyeSrcRect, &eyeSrcMap);
	LoadGraphic(kEyePictID);
	eyeMaskMap = 0L;
	CreateOffScreenBitMap(&eyeSrcRect, &eyeMaskMap);
	LoadGraphic(kEyeMaskID);
	for (i = 0; i < 4; i++)
	{
		SetRect(&eyeRects[i], 0, 0, 48, 31);
		OffsetRect(&eyeRects[i], 0, i * 31);
	}

	SetRect(&handSrcRect, 0, 0, 56, 114);
	handSrcMap = 0L;				// Create pixmap to hold "mummy hand" graphics.
	CreateOffScreenPixMap(&handSrcRect, &handSrcMap);
	LoadGraphic(kHandPictID);
	handMaskMap = 0L;
	CreateOffScreenBitMap(&handSrcRect, &handMaskMap);
	LoadGraphic(kHandMaskID);
	SetRect(&handRects[0], 0, 0, 56, 57);
	OffsetRect(&handRects[0], 0, 0);
	SetRect(&handRects[1], 0, 0, 56, 57);
	OffsetRect(&handRects[1], 0, 57);
	SetRect(&grabZone, 0, 0, 96, 108);
	OffsetRect(&grabZone, 48, 352);

	SetRect(&idleSrcRect, 0, 0, 48, 48);
	idleSrcMap = 0L;				// Create pixmap to hold "shielded player".
	CreateOffScreenPixMap(&idleSrcRect, &idleSrcMap);
	LoadGraphic(kIdlePictID);

	SetRect(&flameSrcRect, 0, 0, 16, 64);
	flameSrcMap = 0L;				// Create pixmap to hold "torch" graphics.
	CreateOffScreenPixMap(&flameSrcRect, &flameSrcMap);
	LoadGraphic(kFlamePictID);
	SetRect(&flameDestRects[0], 0, 0, 16, 16);
	OffsetRect(&flameDestRects[0], 87, 325);
	SetRect(&flameDestRects[1], 0, 0, 16, 16);
	OffsetRect(&flameDestRects[1], 535, 325);
	for (i = 0; i < 4; i++)
	{
		SetRect(&flameRects[i], 0, 0, 16, 16);
		OffsetRect(&flameRects[i], 0, i * 16);
	}

	SetRect(&numberSrcRect, 0, 0, 8, 121);
	numberSrcMap = 0L;				// Create pixmap to hold "score numbers".
	CreateOffScreenPixMap(&numberSrcRect, &numberSrcMap);
	LoadGraphic(kNumberPictID);
	for (i = 0; i < 11; i++)
	{
		SetRect(&numbersSrc[i], 0, 0, 8, 11);
		OffsetRect(&numbersSrc[i], 0, 11 * i);
	}
	SetRect(&numbersDest[0], 0, 0, 8, 11);	// # of lives digit 1
	OffsetRect(&numbersDest[0], 229, 443);
	SetRect(&numbersDest[1], 0, 0, 8, 11);	// # of lives digit 2
	OffsetRect(&numbersDest[1], 237, 443);
	SetRect(&numbersDest[2], 0, 0, 8, 11);	// score digit 1
	OffsetRect(&numbersDest[2], 293, 443);
	SetRect(&numbersDest[3], 0, 0, 8, 11);	// score digit 2
	OffsetRect(&numbersDest[3], 301, 443);
	SetRect(&numbersDest[4], 0, 0, 8, 11);	// score digit 3
	OffsetRect(&numbersDest[4], 309, 443);
	SetRect(&numbersDest[5], 0, 0, 8, 11);	// score digit 4
	OffsetRect(&numbersDest[5], 317, 443);
	SetRect(&numbersDest[6], 0, 0, 8, 11);	// score digit 5
	OffsetRect(&numbersDest[6], 325, 443);
	SetRect(&numbersDest[7], 0, 0, 8, 11);	// score digit 6
	OffsetRect(&numbersDest[7], 333, 443);
	SetRect(&numbersDest[8], 0, 0, 8, 11);	// # of level digit 1
	OffsetRect(&numbersDest[8], 381, 443);
	SetRect(&numbersDest[9], 0, 0, 8, 11);	// # of level digit 2
	OffsetRect(&numbersDest[9], 389, 443);
	SetRect(&numbersDest[10], 0, 0, 8, 11);	// # of level digit 3
	OffsetRect(&numbersDest[10], 397, 443);

	SetRect(&playerRects[0], 0, 0, 48, 37);
	OffsetRect(&playerRects[0], 0, 0);
	SetRect(&playerRects[1], 0, 0, 48, 37);
	OffsetRect(&playerRects[1], 0, 37);
	SetRect(&playerRects[2], 0, 0, 48, 37);
	OffsetRect(&playerRects[2], 0, 74);
	SetRect(&playerRects[3], 0, 0, 48, 37);
	OffsetRect(&playerRects[3], 0, 111);
	SetRect(&playerRects[4], 0, 0, 48, 48);
	OffsetRect(&playerRects[4], 0, 148);
	SetRect(&playerRects[5], 0, 0, 48, 48);
	OffsetRect(&playerRects[5], 0, 196);
	SetRect(&playerRects[6], 0, 0, 48, 48);
	OffsetRect(&playerRects[6], 0, 244);
	SetRect(&playerRects[7], 0, 0, 48, 48);
	OffsetRect(&playerRects[7], 0, 292);
	SetRect(&playerRects[8], 0, 0, 48, 37);		// falling bones rt.
	OffsetRect(&playerRects[8], 0, 340);
	SetRect(&playerRects[9], 0, 0, 48, 37);		// falling bones lf.
	OffsetRect(&playerRects[9], 0, 377);
	SetRect(&playerRects[10], 0, 0, 48, 22);	// pile of bones
	OffsetRect(&playerRects[10], 0, 414);

	MoveTo(0, 0);			// Generate clipping region that excludes the obelisks.
	playRgn = NewRgn();		// Create empty new region.
	OpenRgn();				// Open region for definition.
	LineTo(0, 450);			// Walk around the vertices of our region.
	LineTo(161, 450);
	LineTo(161, 269);
	LineTo(172, 250);
	LineTo(182, 269);
	LineTo(182, 450);
	LineTo(457, 450);
	LineTo(457, 269);
	LineTo(468, 250);
	LineTo(478, 269);
	LineTo(478, 450);
	LineTo(640, 450);
	LineTo(640, 0);
	LineTo(0, 0);
	CloseRgn(playRgn);		// Stop region definition.
	MoveHHi((Handle)playRgn);
	HLock((Handle)playRgn);

	SetRect(&platformSrcRect, 0, 0, 191, 192);
	platformSrcMap = 0L;	// Create pixmap to hold "platform" graphic.
	CreateOffScreenPixMap(&platformSrcRect, &platformSrcMap);
	LoadGraphic(kPlatformPictID);
	for (i = 0; i < 6; i++)
	{
		SetRect(&platformCopyRects[i], 0, 0, 191, 32);
		OffsetRect(&platformCopyRects[i], 0, 32 * i);
	}
	SetRect(&platformCopyRects[6], 233, 190, 424, 222);
	SetRect(&platformCopyRects[7], 0, 105, 191, 137);
	SetRect(&platformCopyRects[8], 449, 105, 640, 137);
	// These are the platforms.  See diagram for numbering.
	SetRect(&platformRects[0], 206, 424, 433, 438);		//_______________
	SetRect(&platformRects[1], -256, 284, 149, 298);	//
	SetRect(&platformRects[2], 490, 284, 896, 298);		//--3--     --4--
	SetRect(&platformRects[3], -256, 105, 149, 119);	//     --5--
	SetRect(&platformRects[4], 490, 105, 896, 119);		//--1--     --2--
	SetRect(&platformRects[5], 233, 190, 407, 204);		//_____--0--_____

	for (i = 0; i < 6; i++)
	{						// "Hot rects" to sense if player landing on platform.
		touchDownRects[i] = platformRects[i];
		touchDownRects[i].left += 23;
		touchDownRects[i].right -= 23;
		touchDownRects[i].bottom = touchDownRects[i].top;
		touchDownRects[i].top = touchDownRects[i].bottom - 11;
	}

	SetRect(&helpSrcRect, 0, 0, 231, 398);
	helpSrcMap = 0L;		// Create pixmap to hold "help screen" graphic.
	CreateOffScreenPixMap(&helpSrcRect, &helpSrcMap);
	LoadGraphic(kHelpPictID);

	SetPort((GrafPtr)mainWindow);
	*/
}
