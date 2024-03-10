#include "input.h"

App app;
void doInput(void) {
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            exit(0);
        case SDL_MOUSEBUTTONUP:
			HandleMouseEvent();
            
			

            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_b) {
                
            }
            break;
        default:
            break;
        }
    }
}






void HandleMouseEvent(void)
{
	int mouseX = 0;
	int mouseY = 0;

	FlashObelisks(true);					// Do lightning animation.
	LogNextTick(50);							// Lightning will hit cursor location.
	SDL_GetMouseState(&mouseX, &mouseY);
	GenerateLightning(mouseX, mouseY);
	StrikeLightning();
	WaitForNextTick();
	StrikeLightning();
	LogNextTick(50);
	WaitForNextTick();
	playSound(SND_PLAYER_FIRE, CH_PLAYER);//PlayExternalSound(kLightningSound, kLightningPriority);
	LogNextTick(50);
	GenerateLightning(mouseX, mouseY);
	StrikeLightning();
	WaitForNextTick();
	StrikeLightning();
	LogNextTick(2);
	WaitForNextTick();
	LogNextTick(3);
	GenerateLightning(mouseX, mouseY);
	StrikeLightning();
	WaitForNextTick();
	StrikeLightning();
	LogNextTick(2);
	WaitForNextTick();
	playSound(SND_PLAYER_FIRE, CH_PLAYER);//PlayExternalSound(kLightningSound, kLightningPriority);
	LogNextTick(3);
	GenerateLightning(mouseX, mouseY);
	StrikeLightning();
	WaitForNextTick();
	StrikeLightning();
	LogNextTick(2);
	WaitForNextTick();
	FlashObelisks(false);

};
