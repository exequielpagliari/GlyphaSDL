#include "main.h"



Textures back;
Textures obThunder;

App app;
int main(int argc, char* argv[])
{

	memset(&app, 0, sizeof(App));

	//memset(&player, 0, sizeof(Entity));

	initSDL();
	initSounds();
	InitVariables();
	int i = 0;	


	SDL_Texture* flameSrcMap = loadTexture(kFlamePictID);

	

	
	LogNextTick(100);
	
	Spark = false;


	//atexit(cleanup);

	while (1)
	{
		printf("%d", Spark);
		prepareScene();
		
		doInput();

		//blit(player.texture,  player.x, player.y);
		
		SDL_RenderCopy(app.renderer, back.texture, &backSrcRect,
			&backSrcRect);


		if (flameSrcRect.y > 32)
			flameSrcRect.y = 0;

		SDL_RenderCopy(app.renderer, flameSrcMap, &flameSrcRect,
			&flameDestRects[0]);
		SDL_RenderCopy(app.renderer, flameSrcMap, &flameSrcRect,
			&flameDestRects[1]);
		RenderTorchA();
		RenderTorchB();

		//SDL_RenderDrawLine(app.renderer, punto1.x, punto1.y, punto2.x, punto2.y);
		
		StrikeLightning(); //Dibuja los rayos

		
		//WaitForNextTick();
		
		/*
		SDL_RenderCopy(app.renderer, obeliskSrcMap, &obSrcRect,
			&obeliskRects[0]);
		
		SDL_RenderCopy(app.renderer, obeliskSrcMap, &obSrcRect,
			&obeliskRects[1]);
		*/

		



		
		WaitForNextTick();
		LogNextTick(50);
		if (Spark == true)
		{
			OffsetRect(&obSrcRect, 0, 0);
			SDL_RenderCopy(app.renderer, obeliskSrcMap, &obSrcRect,
				&obeliskRects[2]);
			OffsetRect(&obSrcRect, 0, 209);
			SDL_RenderCopy(app.renderer, obeliskSrcMap, &obSrcRect,
				&obeliskRects[3]);
		}


		WaitForNextTick();
		
		LogNextTick(50);
		//printf("%d\n", SDL_GetTicks64());



		flameSrcRect.y += 16;
		i++;
		presentScene();

		SDL_Delay(0);
	}

	return 0;
}



void InitVariables(void)
{
	short		i;


	back.texture = loadTexture("Img/130.bmp");
	SDL_QueryTexture(back.texture, NULL, NULL, &backSrcRect.w, &backSrcRect.h);
	
	SDL_Texture* flameSrcMap = loadTexture(kFlamePictID);
	obThunder.texture = loadTexture(kObeliskPictID);
	//SDL_Texture* obeliskSrcMap = loadTexture(kObeliskPictID);

	SetRect(&workSrcRect, 0, 0, 640, 480);
	SetRect(&mainWindowRect, 0, 0, 640, 480);
	SetRect(&flameSrcRect, 0, 0, 16, 16);
	SetRect(&flameDestRects[0], 87, 325, 16, 16);
	SetRect(&flameDestRects[1], 535, 325, 16, 16);

	SetRect(&obSrcRect, 0, 0, 20, 209);
	SetRect(&obeliskRects[0], 0, 0, 20, 209);
	OffsetRect(&obeliskRects[0], 0, 0);
	SetRect(&obeliskRects[1], 0, 0, 20, 209);
	OffsetRect(&obeliskRects[1], 0, 209);
	SetRect(&obeliskRects[2], 0, 0, 20, 209);
	OffsetRect(&obeliskRects[2], 161, 250);
	SetRect(&obeliskRects[3], 0, 0, 20, 209);
	OffsetRect(&obeliskRects[3], 457, 250);
};