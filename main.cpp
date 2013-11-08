#include "game.h"
#include "Utils/timer.h"

#include <cstdlib>

const unsigned short FPS = 60;
const float DELAY_TIME = 1000.f / (float)FPS;

int main(int argc, char **argv) 
{
	if(!TheGame::Instance().init("Test Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		640, 480, false))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Game failed to start", SDL_GetError(), nullptr);
		
		return EXIT_FAILURE;
	}
	
	Timer timer;
	
	float timeSinceLastUpdate = 0.f;
	
	while(TheGame::Instance().isRunning())
	{
		TheGame::Instance().handleEvents();
			
		timeSinceLastUpdate += timer.restart();
		while(timeSinceLastUpdate > DELAY_TIME)
		{
			timeSinceLastUpdate -= DELAY_TIME;
			
			TheGame::Instance().update(DELAY_TIME);
			TheGame::Instance().handleEvents();
		}
		
		TheGame::Instance().render();
	}
	
	TheGame::Instance().clean();
	
    return EXIT_SUCCESS;
}
