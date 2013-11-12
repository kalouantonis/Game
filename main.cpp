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
	
	static SharedGame& instance = SharedGame::Instance();

	while(instance.isRunning())
	{
		instance.handleEvents();
			
		timeSinceLastUpdate += timer.restart();
		while(timeSinceLastUpdate > DELAY_TIME)
		{

			timeSinceLastUpdate -= DELAY_TIME;
			
			instance.update(DELAY_TIME);
			instance.handleEvents();
		}

		instance.render();
	}
	
	instance.clean();


    return EXIT_SUCCESS;
}
