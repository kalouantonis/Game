#include "GameStateMachine.h"

#include <cassert>

void GameStateMachine::pushState(std::unique_ptr<GameState> pState)
{
	m_gameStates.push_back(std::move(pState));

	assert(m_gameStates.back()->onEnter() != false);
}

void GameStateMachine::popState()
{
	if(!m_gameStates.empty())
	{
		if(m_gameStates.back()->onExit())
		{
			//delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
}


void GameStateMachine::changeState(std::unique_ptr<GameState> pState)
{
	if(!m_gameStates.empty())
	{
		// Item is already in front of queue
		if(m_gameStates.back()->getStateID() == pState->getStateID())
		{
			return;
		}

		if(m_gameStates.back()->onExit())
		{
			//delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}

	// push back our new state, move ownership
	m_gameStates.push_back(std::move(pState));

	// intialize it
	assert(m_gameStates.back()->onEnter() != false);
}

void GameStateMachine::clean()
{
	for(unsigned int i = 0; i < m_gameStates.size(); ++i)
	{
		assert(m_gameStates.back()->onExit() != false);
		// Remove item
		//delete m_gameStates.back();
		//m_gameStates.pop_back();
	}

	m_gameStates.clear();
}

void GameStateMachine::update(float delta)
{
	if(!m_gameStates.empty())
		m_gameStates.back()->update(delta);
}

void GameStateMachine::render()
{
	if(!m_gameStates.empty())
		m_gameStates.back()->render();
}

GameStateMachine::~GameStateMachine()
{
	// Pop everything from queue, free memory
	if(!m_gameStates.empty())
		clean();
}
