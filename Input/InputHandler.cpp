#include "InputHandler.h"

// SDL_WasInit()
#include <SDL2/SDL_test.h>
#include <SDL2/SDL_messagebox.h>

#include "../Utils/logger.h"
#include "../game.h"

InputHandler::InputHandler(void)
	: m_bJoysticksInitialised(false)
	, m_mousePosition()
	, m_keystates(nullptr)
{
	// No init method needed, mouse is always initialized
	for(int i = 0; i < NUM_MOUSEBUTTONS; ++i)
	{
		m_mouseButtonStates.push_back(false);
	}
}

InputHandler::~InputHandler(void)
{
	if(!m_joysticks.empty())
		clean();
}

void InputHandler::initializeJoysticks()
{
	if(!SDL_WasInit(SDL_INIT_JOYSTICK))
	{
		if(!SDL_InitSubSystem(SDL_INIT_JOYSTICK))
		{
			log(ERROR, "joystick system init failed!!\n\tError:%s\n", SDL_GetError());
			
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Joystick error!", 
				"Failed to start joystick system!\nSee logs for details", TheGame::Instance().getCurrentWindow());
		}
	}

	if(SDL_NumJoysticks() > 0)
	{
		for(Uint8 i = 0; i < SDL_NumJoysticks(); ++i)
		{
			SDL_Joystick* joy = SDL_JoystickOpen(i);

			if(!joy)
			{
				log(ERROR, "Joystick failed to intialize -- %s\n", SDL_GetError());
			}

			m_joysticks.push_back(joy);

			m_joystickValues.push_back(std::make_pair(VecPtr(new Vector2(0, 0)), 
													  VecPtr(new Vector2(0, 0))));

			// init buttons
			std::vector<bool> tmpButtons;

			for(Uint8 j = 0; j < SDL_JoystickNumButtons(joy); ++j)
			{
				tmpButtons.push_back(false);
			}

			m_buttonStates.push_back(tmpButtons);
		}

		SDL_JoystickEventState(SDL_ENABLE);
		m_bJoysticksInitialised = true;

		log(DEBUG, "Initialized %i joystick(s)\n", m_joysticks.size());
	}
}


void InputHandler::update()
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			TheGame::Instance().quit();
		}

		// update the state of keys
		m_keystates = (Uint8*)SDL_GetKeyboardState(0);

		if(m_bJoysticksInitialised)
		{
			if(event.type == SDL_JOYAXISMOTION)
			{
				m_onJoystickAxisMove(event);
			}
			
			if(event.type == SDL_JOYBUTTONDOWN)
			{
				m_onJoystickButtonDown(event);
			}

			if(event.type == SDL_JOYBUTTONUP)
			{
				m_onJoystickButtonUp(event);
			}
		}

			
		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
			m_onMouseButtonDown(event);		
		}

		if(event.type == SDL_MOUSEBUTTONUP)
		{
			m_onMouseButtonUp(event);
		}

		if(event.type == SDL_MOUSEMOTION)
		{
			m_onMouseMove(event);
		}
	}
}

bool InputHandler::isKeyDown(const SDL_Scancode& key)
{
	if(m_keystates != nullptr)
	{
		if(m_keystates[key] == 1)
			return true;

		return false;
	}

	return false;
}

void InputHandler::clean()
{
	if(m_bJoysticksInitialised)
	{
		for(auto it = m_joysticks.begin(); it != m_joysticks.end(); ++it)
		{
			SDL_JoystickClose(*it);
		}
		
		m_joysticks.clear();

		// Clean buttons
		/*
		for(auto it = m_joystickValues.begin(); it != m_joystickValues.end(); ++it)
		{
			delete (*it).first;
			delete (*it).second;
		}*/
	}
}


int InputHandler::jxvalue(int joy, int stick) const
{
	if(m_joystickValues.size() > 0)
	{
		if(stick == 1)
			return m_joystickValues[joy].first->x;
		else if(stick == 2)
			return m_joystickValues[joy].second->x;
	}

	return 0;
}

int InputHandler::jyvalue(int joy, int stick) const
{
	if(m_joystickValues.size() > 0)
	{
		if(stick == 1)
			return m_joystickValues[joy].first->y;
		if(stick == 2)
			return m_joystickValues[joy].second->y;
	}

	return 0;
}

void InputHandler::m_onMouseButtonDown(SDL_Event& event)
{
	if(event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = true;
	}

	if(event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = true;
	}

	if(event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = true;
	}
}

void InputHandler::m_onMouseButtonUp(SDL_Event& event)
{
	if(event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = false;
	}

	if(event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = false;
	}

	if(event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = false;
	}
}

void InputHandler::m_onMouseMove(SDL_Event& event)
{
	m_mousePosition.x = event.motion.x;
	m_mousePosition.y = event.motion.y;
}

void InputHandler::m_onJoystickAxisMove(SDL_Event& event)
{
	// Which joystick?
	int whichOne = event.jaxis.which;

	if(event.jaxis.axis == 0)
	{
		// left stick move left or right
		if(event.jaxis.value > JOYSTICKDEADZONE)
			m_joystickValues[whichOne].first->x = 1;
		else if(event.jaxis.value < -JOYSTICKDEADZONE)
			m_joystickValues[whichOne].first->x = -1;
		else
			m_joystickValues[whichOne].first->x = 0;
	}
	// Left stick move up or down
	if(event.jaxis.axis == 1)
	{
		if(event.jaxis.value > JOYSTICKDEADZONE)
			m_joystickValues[whichOne].first->x = 1;
		else if(event.jaxis.value < -JOYSTICKDEADZONE)
			m_joystickValues[whichOne].first->y = -1;
		else
			m_joystickValues[whichOne].first->y = 0;
	}

	// right stick move left and right
	if(event.jaxis.axis == 3)
	{
		if(event.jaxis.value > JOYSTICKDEADZONE)
			m_joystickValues[whichOne].second->x = 1;
		else if(event.jaxis.value < -JOYSTICKDEADZONE)
			m_joystickValues[whichOne].second->x = -1;
		else
			m_joystickValues[whichOne].second->x = 0;
	}

	// right stick move up and down
	if(event.jaxis.axis == 4)
	{
		if(event.jaxis.value > JOYSTICKDEADZONE)
			m_joystickValues[whichOne].second->y = 1;
		else if(event.jaxis.value < -JOYSTICKDEADZONE)
			m_joystickValues[whichOne].second->y = -1;
		else
			m_joystickValues[whichOne].second->y = 0;
	}

}

void InputHandler::m_onJoystickButtonDown(SDL_Event& event)
{
	int whichOne = event.jaxis.which;

	m_buttonStates[whichOne][event.jbutton.button] = true;
}

void InputHandler::m_onJoystickButtonUp(SDL_Event& event)
{
	int whichOne = event.jaxis.which;

	m_buttonStates[whichOne][event.jbutton.button] = false;
}
