/*
 * RenderSystem.cpp
 *
 *  Created on: Nov 14, 2013
 *      Author: slacker
 */

#include <ECS/RenderSystem.h>

RenderSystem::RenderSystem(SDL_Renderer* renderer)
	: ISystem()
	, m_pRenderer(renderer)
{
	if(!renderer)
		throw std::runtime_error("RenderSystem::RenderSystem -- Invalid renderer");
}

void RenderSystem::addEntity(int level, EntityPtr entity)
{
	// Request sprite
	m_sprites[level][entity->getID()] = std::dynamic_pointer_cast<Sprite>(entity->getComponent(SpriteID));
}

void RenderSystem::removeEntity(const std::string& id)
{
	// Iterate all levels, find first occurance
	for(auto it = m_sprites.begin(); it != m_sprites.end(); ++it)
	{
		SpriteMap::size_type size = (*it).second.erase(id);

		if(size > 0)
			return;
	}
}

void RenderSystem::removeEntity(EntityPtr entity)
{
	removeEntity(entity->getID());
}

void RenderSystem::render()
{
	// Collect here to reduce allocations
	auto endSpriteIt = m_sprites.end();

	CompMap::const_iterator endCompIt;


	for(auto sit = m_sprites.begin(); sit != endSpriteIt; ++sit)
	{
		endCompIt = (*sit).second.end();

		for(auto cit = (*sit).second.begin(); cit != endCompIt; ++cit)
		{
			(*cit).second->draw();
		}
	}
}

void RenderSystem::initialize()
{

}

void RenderSystem::clean()
{
	// Remove all references
	if(!m_sprites.empty())
		m_sprites.clear();
}

RenderSystem::~RenderSystem()
{
	clean();
}

