#include "draw.h"
#include <SDL_image.h>
#include <SDL.h>



App app;


short Random()
{


	// Generar y mostrar varios nmeros aleatorios
	return rand();
}

//Funcion creada para generar un Seed para obtener valor aleatorio por ejecucion
void CreateSeed(void)
{
	unsigned int seed = (unsigned int)time(NULL);
	srand(seed);
}

// Takes a short (range) and returns a random number from zero to range - 1.

short RandomInt(short range)
{

	register long int rawResult;

	rawResult = Random();
	if (rawResult < 0L)
		rawResult *= -1L;
	rawResult = (rawResult * (long)range) / 32768L;

	return ((short)rawResult);
}

void prepareScene(void) {
    SDL_SetRenderDrawColor(app.renderer, 255, 255, 0, 255);
    SDL_RenderClear(app.renderer);
}

void presentScene(void) {
    SDL_RenderPresent(app.renderer);
}

SDL_Texture* loadTexture(char* filename)
{
	SDL_Texture* texture;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	texture = IMG_LoadTexture(app.renderer, filename);

	return texture;
}



void blit(SDL_Texture* texture, int x, int y)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}



void blitRect(SDL_Texture* texture, SDL_Rect* src, int x, int y)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	dest.w = src->w;
	dest.h = src->h;

	SDL_RenderCopy(app.renderer, texture, src, &dest);
}

void blitRectHW(SDL_Texture* texture, SDL_Rect* src, int x, int y, int w, int h, int frame)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	src->y = h;
	src->x = x;	
	dest.w = src->w;
	dest.h = src->h;

	SDL_RenderCopy(app.renderer, texture, src, &dest);
}


void SetRect(SDL_Rect *rect, int x, int y, int w, int h)
{
	rect->x = x;
	rect->y = y;
	rect->h = h;
	rect->w = w;
}

void OffsetRect(SDL_Rect *rect, int x, int y)
{
	rect->x = x;
	rect->y = y;
}
;



void RenderTorchA(void)
{


}

void RenderTorchB(void)
{


	
}




void GenerateLightning(short h, short v)
{
#define kLeftObeliskH		172
#define kLeftObeliskV		250
#define kRightObeliskH		468
#define kRightObeliskV		250
#define kWander				16

	short		i, leftDeltaH, rightDeltaH, leftDeltaV, rightDeltaV, range;

	leftDeltaH = h - kLeftObeliskH;				// Determine the h and v distances between…
	rightDeltaH = h - kRightObeliskH;			// obelisks and the target point.
	leftDeltaV = v - kLeftObeliskV;
	rightDeltaV = v - kRightObeliskV;

	for (i = 0; i < kNumLightningPts; i++)		// Calculate an even spread of points between…
	{											// obelisk tips and the target point.
		leftLightningPts[i].x = (leftDeltaH * i) / (kNumLightningPts - 1) + kLeftObeliskH;
		leftLightningPts[i].y = (leftDeltaV * i) / (kNumLightningPts - 1) + kLeftObeliskV;
		rightLightningPts[i].x = (rightDeltaH * i) / (kNumLightningPts - 1) + kRightObeliskH;
		rightLightningPts[i].y = (rightDeltaV * i) / (kNumLightningPts - 1) + kRightObeliskV;
	}

	range = kWander * 2 + 1;					// Randomly scatter the points vertically…
	for (i = 1; i < kNumLightningPts - 1; i++)	// but NOT the 1st or last points.
	{
		leftLightningPts[i].x += RandomInt(range) - kWander;
		rightLightningPts[i].x += RandomInt(range) - kWander;
	}


	
}



//--------------------------------------------------------------  FlashObelisks

// This function either draws the obelisks "normal" or draws them inverted.
// They're drawn "inverted" as if emanating energy or lit up by the bolts…
// of lightning.  The flag "flashThem" specifies how to draw them.


Textures back;
Textures obThunder;

void FlashObelisks(bool flashThem)
{
	
	if (flashThem)		// Draw them "inverted"
	{


		SDL_RenderCopy(app.renderer, back.texture, &backSrcRect,
			&backSrcRect);

		SDL_QueryTexture(back.texture, NULL, NULL, &backSrcRect.w, &backSrcRect.h);

		SDL_RenderCopy(app.renderer, obThunder.texture, &obSrcRect,
			&obeliskRects[2]);

		SDL_RenderCopy(app.renderer, obThunder.texture, &obSrcRect,
			&obeliskRects[3]);



		

		//LogNextTick(2);
		//WaitForNextTick();
		
	}
	else
	{
		presentScene();
		// Restaurar el render target predeterminado
		SDL_SetRenderTarget(app.renderer, NULL);
		SDL_RenderClear(app.renderer);
		SDL_RenderCopy(app.renderer, back.texture, &backSrcRect,
			&backSrcRect);

		SDL_QueryTexture(back.texture, NULL, NULL, &backSrcRect.w, &backSrcRect.h);
	}


}


void StrikeLightning(void)
{
	short i;
	/*
	SDL_RenderDrawLines(app.renderer, leftLightningPts, 8);
	SDL_RenderDrawLines(app.renderer, rightLightningPts, 8);
	*/
	SDL_SetRenderDrawColor(app.renderer, 255, 255, 0, 255);


	for (i = 0; i < kNumLightningPts - 1; i++)	// Draw left lightning bolt.
	{
		
		SDL_RenderDrawLine(app.renderer, leftLightningPts[i].x, leftLightningPts[i].y, leftLightningPts[i + 1].x - 1, leftLightningPts[i + 1].y);
	}
	

	for (i = 0; i < kNumLightningPts - 1; i++)	// Draw right lightning bolt.
	{
		SDL_RenderDrawLine(app.renderer, rightLightningPts[i].x, rightLightningPts[i].y, rightLightningPts[i + 1].x - 1, rightLightningPts[i + 1].y);
	}
	


}

void PenNormal(void)
{
	SDL_RenderCopy(app.renderer, back.texture, &backSrcRect,
		&backSrcRect);

	SDL_QueryTexture(back.texture, NULL, NULL, &backSrcRect.w, &backSrcRect.h);
}