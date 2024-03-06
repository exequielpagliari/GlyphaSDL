#include "main.h"



Entity torch;
Entity player;

App app;
int main(int argc, char* argv[])
{
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
	



	//atexit(cleanup);

	while (1)
	{
		

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

		if( i % 5 == 0)
		{ 
		/*
		SDL_RenderCopy(app.renderer, obeliskSrcMap, &obSrcRect,
			&obeliskRects[0]);
		
		SDL_RenderCopy(app.renderer, obeliskSrcMap, &obSrcRect,
			&obeliskRects[1]);
		*/

		
		OffsetRect(&obSrcRect, 0, 0);
		SDL_RenderCopy(app.renderer, obeliskSrcMap, &obSrcRect,
			&obeliskRects[2]);
		OffsetRect(&obSrcRect, 0, 209);
		SDL_RenderCopy(app.renderer, obeliskSrcMap, &obSrcRect,
			&obeliskRects[3]);
		}


		flameSrcRect.y += 16;
		i++;
		presentScene();

		SDL_Delay(100);
	}

	return 0;
}