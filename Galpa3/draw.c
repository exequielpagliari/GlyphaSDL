#include "draw.h"
#include <SDL_image.h>
#include <SDL.h>



App app;
void prepareScene(void) {
    SDL_SetRenderDrawColor(app.renderer, 96, 128, 255, 255);
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


void SetRect(SDL_Rect rect, int x, int y, int h, int w)
{
	rect.x = x;
	rect.y = y;
	rect.h = h;
	rect.w = w;
}


void OffsetRect(SDL_Rect rect, int x, int y)
{
	rect.x = x;
	rect.y = y;
};



void RenderTorchA(void)
{
	if (flameSrcRect.y > 32)
		flameSrcRect.y = 0;
	
	SDL_RenderCopy(app.renderer, flameSrcMap, &flameSrcRect,
		&flameDestRects[0]);
}

void RenderTorchB(void)
{

	SDL_RenderCopy(app.renderer, flameSrcMap, &flameSrcRect,
		&flameDestRects[1]);
	
}