#include "main.h"





App app;
int main(int argc, char* argv[])
{

	memset(&app, 0, sizeof(App));

	//memset(&player, 0, sizeof(Entity));

	initSDL();
	int i = 0;
	InitVariables();

	SDL_Texture* backSrcMapA =  loadTexture("Img/130.bmp");
	SDL_QueryTexture(backSrcMapA, NULL, NULL, &backSrcRect.w, &backSrcRect.h);
	SDL_Texture* flameSrcMap = loadTexture(kFlamePictID);
	SDL_Texture* obeliskSrcMap = loadTexture(kObeliskPictID);
	
	LogNextTick(100);
	
	Spark = false;


	//atexit(cleanup);

	while (1)
	{
		printf("%d", Spark);
		prepareScene();
		
		doInput();

		//blit(player.texture,  player.x, player.y);
		
		SDL_RenderCopy(app.renderer, backSrcMapA, &backSrcRect,
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