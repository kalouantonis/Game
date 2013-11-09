/*
 * TextureManager.cpp
 *
 *  Created on: 9 Nov 2013
 *      Author: slacker
 */

#include <Utils/TextureManager.h>

#include <cassert>

#include <stdexcept>

TextureManager::TextureManager()
	: m_pRenderer(nullptr)
{
}

void TextureManager::attachRenderer(SDL_Renderer* renderer)
{
	// Make sure we didn't receive an invalid renderer
	if(renderer == nullptr)
		throw std::runtime_error("Invalid renderer -- TextureManager::TextureManager");

	m_pRenderer = renderer;
}

TextureManager::~TextureManager()
{
	// Check for cleanup
	clean();
}

void TextureManager::load(const std::string& id, const std::string& filename)
{
	SDL_Texture* tex = nullptr;
	tex = IMG_LoadTexture(m_pRenderer, filename.c_str());

	if(tex == nullptr)
		throw std::runtime_error("TextureManager::load -- Could not load filename: " + filename);

	m_textures[id] = tex;
}

SDL_Texture* TextureManager::get(const std::string& id)
{
	auto sought = m_textures.find(id);

	if(sought == m_textures.end())
		throw std::out_of_range("TextureManager::get -- Attempted to access invalid map object");

	return sought->second;
}

void TextureManager::remove(const std::string& id)
{
	// Use find to check for errors
	auto sought = m_textures.find(id);

	if(sought == m_textures.end())
		throw std::logic_error("TextureManager::remove -- Attempted to remove invalid map object");

	// Delete texture
	SDL_DestroyTexture(sought->second);

	m_textures.erase(sought);
}

void TextureManager::clean()
{
	if(!m_textures.empty())
	{
		for(auto it = m_textures.begin(); it != m_textures.end(); ++it)
		{
			// Unload texture
			SDL_DestroyTexture(it->second);
		}

		m_textures.clear();
	}
}
