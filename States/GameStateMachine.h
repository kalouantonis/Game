#ifndef _GAMESTATEMACHINE_H_
#define _GAMESTATEMACHINE_H_

#include "GameState.h"

#include <memory>
#include <vector>

#include <States/GameState.h>

// Queue like structure
class GameStateMachine
{
public:
	// add state without removing previous
	void pushState(std::unique_ptr<GameState> pState);
	// remove previous before adding another
	void changeState(std::unique_ptr<GameState> pState);
	// remove current state
	void popState();

	// Clean all states, delete them. Once executed, your states will be gone
	void clean();

	void update(float delta);
	void render();

	~GameStateMachine();

private:
	std::vector<std::unique_ptr<GameState> > m_gameStates;
};

#endif
