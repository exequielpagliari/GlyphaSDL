#include "SDL.h"
#include <Externs.h>






#define kPrefsVersion			0x0001


void ReadInPrefs(void);
void WriteOutPrefs(void);
int main(int argc, char* argv[]);
SDL_Window* Window = 0;
SDL_Renderer* pRenderer = 0;
SDL_Texture* m_pTexture; // the new SDL_Texture variable
SDL_Rect m_sourceRectangle; // the first rectangle
SDL_Rect m_destinationRectangle; // another rectangle

prefsInfo	thePrefs;
short		wasVolume;



extern	bool		quitting, playing, pausing, evenFrame;

//==============================================================  Functions
//--------------------------------------------------------------  ReadInPrefs

//	This function loads up the preferences.  If the preferences 
//	aren't found, all settings are set to their defaults.

void ReadInPrefs(void)
{
	printf("Leer Preferencias\n\n");
	/*
	short		i;

	// Call LoadPrefs() function - returns TRUE if it worked.
	if (LoadPrefs(&thePrefs, kPrefsVersion))
		SetSoundVol(thePrefs.wasVolume);
	else					// If LoadPrefs() failed, set defaults.
	{
		thePrefs.prefVersion = kPrefsVersion;				// version of prefs
		thePrefs.filler = 0;								// just padding
		PasStringCopy("\pYour Name", thePrefs.highName);	// last highscores name
		for (i = 0; i < 10; i++)							// loop through scores
		{
			PasStringCopy("\pNemo", thePrefs.highNames[i]);	// put "Nemo" in name
			thePrefs.highScores[i] = 0L;					// set highscore to 0
			thePrefs.highLevel[i] = 0;						// level attained = 0
		}
		GetSoundVol(&thePrefs.wasVolume);
	}
	// Get sound volume so we can restore it.
	GetSoundVol(&wasVolume);
	*/
}

//--------------------------------------------------------------  WriteOutPrefs

//	This function writes out the preferences to disk and restores 
//	the sound volume to its setting before Glypha was launched.

void WriteOutPrefs(void)
{
	printf("Escribir Preferencias\n\n");
	/*
	if (!SavePrefs(&thePrefs, kPrefsVersion))
		SysBeep(1);
	SetSoundVol(wasVolume);
	*/
}



int main(int argc, char* argv[])
{
	long		tickWait;
	CreateSeed();
	/*
	ToolBoxInit();			// Call function that initializes the ToolBox managers.
	CheckEnvirons();		// Check the Mac we're on to see if we can run.
	OpenMainWindow();		// Open up the main window - it will fill the monitor.
	InitVariables();		// Initialize Glypha's variables.
	InitSound();			// Create sound channels and load up sounds.
	InitMenubar();			// Set up the game's menubar.
	*/
	ReadInPrefs();			// Load up the preferences.
	printf(("%d \n \n"), Random());
	printf(("%d \n \n"), RandomInt(24L));


		SDL_Init(SDL_INIT_VIDEO);

		SDL_Window* Window =
			SDL_CreateWindow("Title",
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				640, 480, 0);

		if(Window != 0)
			pRenderer = SDL_CreateRenderer(Window, -1, 0);

		int Running = 1;

		SDL_Event Event = { 0 };
		SDL_Surface* pTempSurface = SDL_LoadBMP("Img/130.bmp");

		m_pTexture = SDL_CreateTextureFromSurface(pRenderer,
			pTempSurface);
		SDL_FreeSurface(pTempSurface);
		SDL_QueryTexture(m_pTexture, NULL, NULL,
			&m_sourceRectangle.w, &m_sourceRectangle.h);
		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;

		while (Running) {
			// everything succeeded lets draw the window
// set to black // This function expects Red, Green, Blue and
// Alpha as color values
			SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
			// clear the window to black
			SDL_RenderClear(pRenderer);

			SDL_RenderCopy(pRenderer, m_pTexture, &m_sourceRectangle,
				&m_destinationRectangle);


			// show the window
			SDL_RenderPresent(pRenderer);
			while (SDL_PollEvent(&Event)) {
				switch (Event.type) {
				case SDL_QUIT: {
					Running = 0;
				} break;
				case SDL_KEYDOWN: {
					switch (Event.key.keysym.sym) {
					case SDLK_o: {
						Running = 0;
					} break;
					}
				} break;
				}
			}
		}



		


	/*
	do						// Here begins the main loop.
	{
		HandleEvent();		// Check for events.
		if ((playing) && (!pausing))
			PlayGame();		// If user began game, drop in game loop. (play mode)
		else				// If no game, animate the screen. (idle mode)
		{
			tickWait = TickCount() + 2L;
			evenFrame = !evenFrame;
			DrawTorches();	// Flicker torches.
			CopyAllRects();	// Refresh screen.
			do				// Wait for 2 Ticks to pass to keep fast Macs at bay.
			{
			} while (TickCount() < tickWait);
		}
	} while (!quitting);

	KillSound();			// Dispose of sound channels.
	ShutItDown();			// Dispose of other structures.
	*/
	WriteOutPrefs();		// Save preferences to disk.
	SDL_Quit();
	return 0;
}
