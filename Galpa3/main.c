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


		RenderTorchA();
		RenderTorchB();

		flameSrcRect.y += 16;

		presentScene();

		SDL_Delay(100);
	}

	return 0;
}