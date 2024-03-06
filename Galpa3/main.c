#include "main.h"



Entity torch;
Entity player;

App app;
int main(int argc, char* argv[])
{
	memset(&app, 0, sizeof(App));

	memset(&player, 0, sizeof(Entity));

	initSDL();

	InitVariables();
	player.x = 0;
	player.y = 0;
	player.texture = loadTexture("Img/130.bmp");
	SDL_Texture* flameSrcMap = loadTexture(kFlamePictID);

	



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

		flameSrcRect.y += 16;

		presentScene();

		SDL_Delay(100);
	}

	return 0;
}