#ifndef _INPUTHANDLER_H_
#define _INPUTHANDLER_H_

#include <vector>
#include <memory>

#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_events.h>

#include <Math/vector2.h>

enum MOUSE_BUTTONS
{
	LEFT = 0,
	MIDDLE,
	RIGHT,
	NUM_MOUSEBUTTONS // Not a mouse button, just contains how many
};

class InputHandler
{
public:
	~InputHandler(void);

	static InputHandler& Instance()
	{
		static InputHandler instance;

		return instance;
	}

	void update();
	void clean();

	// Joystick functions ================================================================================
	void initializeJoysticks();

	bool joysticksInitialised() const { return m_bJoysticksInitialised; }

	// get analog info, joy is the id of the joystick, stick is left or right analogue stick
	int jxvalue(int joy, int stick) const;
	int jyvalue(int joy, int stick) const;

	bool getJoystickButtonState(int joy, int buttonNumber) const
	{
		return m_buttonStates[joy][buttonNumber];
	}
	// ====================================================================================================

	// Mouse functions ====================================================================================
	bool getMouseButtonState(MOUSE_BUTTONS buttonNumber) const
	{
		return m_mouseButtonStates[buttonNumber];
	}

	const Vector2& getMousePosition()
	{
		return m_mousePosition;
	}
	// ====================================================================================================

	// Keyboard Functions =================================================================================
	bool isKeyDown(const SDL_Scancode& key);
	// ====================================================================================================
private:
	InputHandler(void);
	InputHandler(const InputHandler&) {}

	// Just shorten the word, you know?
	typedef std::shared_ptr<Vector2> VecPtr;

	// Joystick vars =======================================================================================
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialised;

	// Used for handling multiple joystick positioning, vectors represent analog sticks
	std::vector<std::pair<VecPtr, VecPtr> > m_joystickValues;
	// Joystick button container
	std::vector<std::vector<bool> > m_buttonStates;
	// =====================================================================================================

	// Mouse vars ==========================================================================================
	std::vector<bool> m_mouseButtonStates;

	Vector2 m_mousePosition;
	// =====================================================================================================

	// Keyboard Vars =======================================================================================
	Uint8* m_keystates;
	// =====================================================================================================

	// Event handlers ======================================================================================
	// mouse
	void m_onMouseMove(SDL_Event& event);
	void m_onMouseButtonDown(SDL_Event& event);
	void m_onMouseButtonUp(SDL_Event& event);

	//joystick
	void m_onJoystickAxisMove(SDL_Event& event);
	void m_onJoystickButtonDown(SDL_Event& event);
	void m_onJoystickButtonUp(SDL_Event& event);
	// =====================================================================================================
};

// Joystick sensitivity
// TODO: Set dynamically
const int JOYSTICKDEADZONE = 10000;

typedef InputHandler TheInputHandler;

#endif
