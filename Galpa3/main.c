#include "main.h"


Textures flameSrcMap;
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


	

	

	
	LogNextTick(100);
	
	Spark = false;


	//atexit(cleanup);

	while (1)
	{
		printf("%d", Spark);
		prepareScene();
		
		doInput();


		
		SDL_RenderCopy(app.renderer, back.texture, &backSrcRect,
			&backSrcRect);


		if (flameSrcRect.y > 32)
			flameSrcRect.y = 0;

		SDL_RenderCopy(app.renderer, flameSrcMap.texture, &flameSrcRect,
			&flameDestRects[0]);
		SDL_RenderCopy(app.renderer, flameSrcMap.texture, &flameSrcRect,
			&flameDestRects[1]);
		RenderTorchA();
		RenderTorchB();

		//SDL_RenderDrawLine(app.renderer, punto1.x, punto1.y, punto2.x, punto2.y);
		
		

		
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



