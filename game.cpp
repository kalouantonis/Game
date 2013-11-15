/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2013  Antonis Kalou <kalouantonis@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <game.h>
#include <Utils/logger.h>
#include <Input/InputHandler.h>
#include <Resources/TextureManager.h>

using std::shared_ptr;
#include <stdexcept>

#include <SDL2/SDL_image.h>


Game::Game()
	: m_pWindow(nullptr)
	, m_pRenderer(nullptr)
	, m_bRunning(false)
{

}

bool Game::init(const std::string& title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
	
	// init SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		log(ERROR, "SDL Failed to initialize: %s\n", SDL_GetError());
		
		return false;
	}
	
	log(DEBUG, "SDL initialized!\n");
		
	m_pWindow = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, flags);
	
	if(m_pWindow == nullptr)
	{
		log(ERROR, "Window creation failed: %s\n", SDL_GetError());
		
		return false;
	}
	log(DEBUG, "window creation success...\n");
	
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	if(m_pRenderer == nullptr)
	{
		log(ERROR, "Renderer failed to initialize: %s\n", SDL_GetError());
		
		return false;
	}
	

	log(DEBUG, "Renderer creation success...\n");

	// Add renderer to texture manager
	SharedTextureManager::Instance().attachRenderer(m_pRenderer);

	// TODO: Add accesor
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	
	StatePtr startState = GetStartState();
	if(!startState)
		throw std::logic_error("Must declare start state");

	m_gameStateMachine.changeState(std::move(startState));

	m_bRunning = true;
	
	return true;
}

void Game::update(float delta)
{
	m_gameStateMachine.update(delta);
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	
	m_gameStateMachine.render();

	// Present changes
	SDL_RenderPresent(m_pRenderer);
}


void Game::handleEvents()
{
	SharedInputHandler::Instance().update();
}

void Game::clean()
{
	log(DEBUG, "Cleaning game...\n");
	
	if(m_pRenderer != nullptr)
		SDL_DestroyRenderer(m_pRenderer);
	
	if(m_pWindow != nullptr)
		SDL_DestroyWindow(m_pWindow);
	
	log(DEBUG, "Clearing game state machine...\n");
	m_gameStateMachine.clean();

	log(DEBUG, "Removing textures...\n");
	SharedTextureManager::Instance().clean();

	// Clean up image library
	IMG_Quit();

	log(DEBUG, "Quitting SDL...\n");
	SDL_Quit();

	log(DEBUG, "Game exited successfully!\n");
}


Game::~Game()
{
	
}
