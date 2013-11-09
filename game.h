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

#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <string>

#include <memory>

class Game
{
public:
    ~Game();
	
	static Game& Instance()
	{
		static Game instance;
		
		return instance;
	}
	
	bool init(const std::string& title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void update(float delta);
	void render();
	void handleEvents();
	
	void clean();
	
	bool isRunning() { return m_bRunning; }
	
	void quit() { m_bRunning = false; }
	
	SDL_Renderer* getRenderer() { return m_pRenderer; }
	SDL_Window* getCurrentWindow() { return m_pWindow; }
		
	
private:
    Game();
	Game(const Game&) {}
	
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	
	bool m_bRunning;
};

typedef Game TheGame;

#endif // GAME_H
