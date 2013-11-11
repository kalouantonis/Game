#include <game.h>
#include <Utils/timer.h>
#include <Utils/logger.h>

#include <cstdlib>

const unsigned short FPS = 60;
const float DELAY_TIME = 1.f / (float)FPS;

int main(int argc, char **argv) 
{
	if(!SharedGame::Instance().init("Test Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480, false))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Game failed to start", SDL_GetError(), nullptr);
		
		return EXIT_FAILURE;
	}
	
	Timer timer;
	
	float timeSinceLastUpdate = 0.f;
	
	while(SharedGame::Instance().isRunning())
	{
		SharedGame::Instance().handleEvents();
			
		timeSinceLastUpdate += timer.restart();
		while(timeSinceLastUpdate > DELAY_TIME)
		{
			timeSinceLastUpdate -= DELAY_TIME;
			
			SharedGame::Instance().update(DELAY_TIME);
			SharedGame::Instance().handleEvents();
		}
		
		SharedGame::Instance().render();
	}
	
	SharedGame::Instance().clean();

    return EXIT_SUCCESS;
}
