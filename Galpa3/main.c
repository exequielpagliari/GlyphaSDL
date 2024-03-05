#include "main.h"



Entity torch;
Entity player;
App app;
int main(int argc, char* argv[])
{
	memset(&app, 0, sizeof(App));

	memset(&player, 0, sizeof(Entity));

	initSDL();

	player.x = 0;
	player.y = 0;
	player.texture = loadTexture("Img/130.bmp");

	torch.texture = loadTexture("Img/143.bmp");

	
	//atexit(cleanup);

	while (1)
	{
		prepareScene();

		doInput();

		blit(player.texture,  player.x, player.y);
		blit(torch.texture, 87, 325,  16, 16);
		blit(torch.texture, 535, 325, 16, 16);
		presentScene();

		SDL_Delay(16);
	}

	return 0;
}