#ifndef DEFS_H
#define DEFS_H

#define SCREEN_WIDTH   640
#define SCREEN_HEIGHT  460

#define kHandPictID				128		// These are all the resource ID's for�
#define kHandMaskID				129		// the various PICT's were going to�
#define kBackgroundPictID		"../Img/130.bmp"		// load up into offscreen pixmaps and�
#define kHelpPictID				131		// offscreen bitmaps.
#define kObeliskPictID			"../Img/134.bmp"
#define kPlayerPictID			135
#define kPlayerMaskID			136
#define kNumberPictID			137
#define kIdlePictID				138
#define kEnemyWalkPictID		139
#define kEnemyFlyPictID			140
#define kEnemyWalkMaskID		141
#define kEnemyFlyMaskID			142
#define kFlamePictID			"../Img/143.bmp"
#define kEggPictID				144
#define kEggMaskID				145
#define kPlatformPictID			146
#define kEyePictID				147
#define kEyeMaskID				148


#define MAX_SND_CHANNELS 8



enum
{
	CH_ANY = -1,
	CH_PLAYER,
	CH_ALIEN_FIRE
};

enum
{
	SND_PLAYER_FIRE,
	SND_ALIEN_FIRE,
	SND_PLAYER_DIE,
	SND_ALIEN_DIE,
	SND_MAX
};




#endif // DEFS_HHT  720