#include "main.h"



Entity torch;
Entity player;

App app;
int main(int argc, char* argv[])
{
	int mouseX = 0;
	int mouseY = 0;
	memset(&app, 0, sizeof(App));

	memset(&player, 0, sizeof(Entity));

	initSDL();
	int i = 0;
	InitVariables();
	player.x = 0;
	player.y = 0;
	player.texture = loadTexture("Img/130.bmp");
	SDL_Texture* flameSrcMap = loadTexture(kFlamePictID);
	SDL_Texture* obeliskSrcMap = loadTexture(kObeliskPictID);
	SDL_Point punto1;
	punto1.x = 0;
	punto1.y = 0;
	SDL_Point punto2;
	punto2.x = 100;
	punto2.y = 100;
	LogNextTick(100);
	
	


	//atexit(cleanup);

	while (1)
	{
		SDL_GetMouseState(&mouseX, &mouseY);

		prepareScene();
		
		doInput();

		blit(player.texture,  player.x, player.y);
		


		if (flameSrcRect.y > 32)
			flameSrcRect.y = 0;

		SDL_RenderCopy(app.renderer, flameSrcMap, &flameSrcRect,
			&flameDestRects[0]);
		SDL_RenderCopy(app.renderer, flameSrcMap, &flameSrcRect,
			&flameDestRects[1]);
		RenderTorchA();
		RenderTorchB();

		//SDL_RenderDrawLine(app.renderer, punto1.x, punto1.y, punto2.x, punto2.y);
		GenerateLightning(mouseX, mouseY);
		SDL_RenderDrawLines(app.renderer, leftLightningPts, 8);
		SDL_RenderDrawLines(app.renderer, rightLightningPts, 8);
		
		//WaitForNextTick();
		
		/*
		SDL_RenderCopy(app.renderer, obeliskSrcMap, &obSrcRect,
			&obeliskRects[0]);
		
		SDL_RenderCopy(app.renderer, obeliskSrcMap, &obSrcRect,
			&obeliskRects[1]);
		*/

		



		
		WaitForNextTick();
		LogNextTick(50);
		/*
		OffsetRect(&obSrcRect, 0, 0);
		SDL_RenderCopy(app.renderer, obeliskSrcMap, &obSrcRect,
			&obeliskRects[2]);
		OffsetRect(&obSrcRect, 0, 209);
		SDL_RenderCopy(app.renderer, obeliskSrcMap, &obSrcRect,
			&obeliskRects[3]);
		*/
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