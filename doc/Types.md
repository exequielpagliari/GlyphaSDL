short
short 16 bits

Boolean
typedef enum { false, true. FALSE= 0, TRUE } Boolean;

long
long 32 bits

Str255
typedef unsigned char Str255[256];
The API had data types Str255 (Pascal string, maximum 255 character, in a 256-byte memory block
(https://news.ycombinator.com/item?id=5215995)

Str15
typedef unsigned char Str15[16];
same, max 15 characters, in a 16 byte block
(https://news.ycombinator.com/item?id=5215995)
typedef unsigned short ushort;
Rect

typedef struct
{
Rect dest, wasDest, wrap;
short h, v;
short wasH, wasV;
short hVel, vVel;
short srcNum, mode;
short frame;
Boolean facingRight, flapping;
Boolean walking, wrapping;
Boolean clutched;
} playerType;

typedef struct
{
Rect dest, wasDest;
short h, v;
short wasH, wasV;
short hVel, vVel;
short srcNum, mode;
short kind, frame;
short heightSmell, targetAlt;
short flapImpulse, pass;
short maxHVel, maxVVel;
Boolean facingRight;
} enemyType;

typedef struct
{
Rect dest;
short mode;
} handInfo;

typedef struct
{
Rect dest;
short mode, opening;
short srcNum, frame;
Boolean killed, entering;
} eyeInfo;

typedef struct
{
short prefVersion, filler;
Str255 highName;
Str15 highNames[10];
long highScores[10];
short highLevel[10];
short wasVolume;
} prefsInfo;
