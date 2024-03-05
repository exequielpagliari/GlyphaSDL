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
	SDL_Rect torch_sourceRectangle; // the first rectangle
	SDL_Rect torch_destinationRectangle; // another rectangle
	SDL_Rect torch_sourceRectangle2; // the first rectangle
	SDL_Rect torch_destinationRectangle2; // another rectangle
	SDL_QueryTexture(torch.texture, NULL, NULL,
		&torch_sourceRectangle.w, &torch_sourceRectangle.h);
	torch_destinationRectangle.x =  87;
	torch_destinationRectangle.y =  325;
	torch_destinationRectangle.w = torch_sourceRectangle.w = 16;
	torch_destinationRectangle.h = torch_sourceRectangle.h = 16;
	torch_sourceRectangle.x = 0;
	torch_sourceRectangle.y = 0;

	SDL_QueryTexture(torch.texture, NULL, NULL,
		&torch_sourceRectangle2.w, &torch_sourceRectangle2.h);
	torch_destinationRectangle2.x = 535;
	torch_destinationRectangle2.y = 325;
	torch_destinationRectangle2.w = torch_sourceRectangle2.w = 16;
	torch_destinationRectangle2.h = torch_sourceRectangle2.h = 16;
	torch_sourceRectangle2.x = 0;
	torch_sourceRectangle2.y = 0;


	//atexit(cleanup);

	while (1)
	{
		prepareScene();

		doInput();

		blit(player.texture,  player.x, player.y);
		//blit(torch.texture, 87, 325,  16, 16);
		//blit(torch.texture, 535, 325, 16, 16);
		torch_sourceRectangle.y += 16;
		if (torch_sourceRectangle.y > 32)
			torch_sourceRectangle.y = 0;
		SDL_RenderCopy(app.renderer, torch.texture, &torch_sourceRectangle,
			&torch_destinationRectangle);
		torch_sourceRectangle2.y += 16;
		if (torch_sourceRectangle2.y > 32)
			torch_sourceRectangle2.y = 0;
		SDL_RenderCopy(app.renderer, torch.texture, &torch_sourceRectangle2,
			&torch_destinationRectangle2);
		
		//blitRectHW(torch.texture, m_destinationRectangle, 87, 325, 0, 0, 0);
		presentScene();

		SDL_Delay(100);
	}

	return 0;
}