#include "input.h"

App app;
void doInput(void) {
    SDL_Event event;
    int mouseX = 0;
    int mouseY = 0;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            exit(0);
        case SDL_MOUSEBUTTONUP:

            
			Spark = true;
			FlashObelisks(true);					// Do lightning animation.
			LogNextTick(15);							// Lightning will hit cursor location.
			SDL_GetMouseState(&mouseX, &mouseY);
			GenerateLightning(mouseX, mouseY);
			StrikeLightning();
			WaitForNextTick();
			StrikeLightning();
			LogNextTick(15);
			WaitForNextTick();
			playSound(SND_PLAYER_FIRE, CH_PLAYER);
			LogNextTick(15);
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
			//PlayExternalSound(kLightningSound, kLightningPriority);
			LogNextTick(3);
			GenerateLightning(mouseX, mouseY);
			StrikeLightning();
			WaitForNextTick();
			StrikeLightning();
			LogNextTick(2);
			WaitForNextTick();
			FlashObelisks(false);
			Spark = false;

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
