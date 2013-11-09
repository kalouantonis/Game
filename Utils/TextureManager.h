/*
 * TextureManager.h
 *
 *  Created on: 9 Nov 2013
 *      Author: slacker
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include <map>
#include <string>

#include <SDL2/SDL_image.h>

#include <game.h>

class TextureManager {
public:
	~TextureManager();

	static TextureManager& Instance()
	{
		static TextureManager instance;

		return instance;
	}

	/**
	 * Attach SDL_Renderer for drawing. Must do this before calling other functions
	 *
	 * Throws std::runtime_error if renderer is invalid
	 */
	void attachRenderer(SDL_Renderer* renderer);

	/**
	 * Load item using SDL_Image library
	 *
	 * Throws std::rutime_error if invalid file
	 */
	void load(const std::string& id, const std::string& filename);

	/**
	 * Gets an item from manager
	 *
	 * Throws std::out_of_bounds if invalid item is requested
	 */
	SDL_Texture* get(const std::string& id);

	/**
	 * Removes an item from texture manager
	 *
	 * Throws std::logic_error if invalid item is accessed
	 */
	void remove(const std::string& id);

	/**
	 * Clean texture manager, remove all items
	 */
	void clean();

private:
	TextureManager();
	TextureManager(const TextureManager&) {}

	std::map<std::string, SDL_Texture*> m_textures;

	// Renderer reference
	SDL_Renderer* m_pRenderer;
};

#endif /* TEXTUREMANAGER_H_ */
