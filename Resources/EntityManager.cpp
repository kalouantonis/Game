/*
 * EntityManager.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: slacker
 */

#include <Resources/EntityManager.h>
#include <cassert>
#include <Utils/logger.h>

EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{
	clean();
}

EntityPtr EntityManager::createEntity(const std::string& id)
{
	EntityPtr entity(new Entity(id));

	m_entityMap[entity->getID()] = entity;

	return entity;
}

void EntityManager::addEntity(EntityPtr entity)
{
	m_entityMap[entity->getID()] = entity;
}

EntityPtr EntityManager::getEntity(const std::string& id)
{
	EntityPtr sought;

	try
	{
		sought = m_entityMap.at(id);
	}
	catch(std::out_of_range& e)
	{
		sought = nullptr;

		log(DEBUG, "EntityManager::getEntity -- attempted to access invalid map object: %s\n", id.c_str());
	}

	return sought;
}

void EntityManager::removeEntity(const std::string& id)
{
	auto found = m_entityMap.find(id);

	if(found == m_entityMap.end())
		throw std::out_of_range("EntityManager::getEntity -- Attempted to access invalid map object");

	// Clean entity
	((*found).second)->clean();

	m_entityMap.erase(found);
}

void EntityManager::removeEntity(EntityPtr entity)
{
	removeEntity(entity->getID());
}

void EntityManager::clean()
{
	if(!m_entityMap.empty())
	{
		for(auto it = m_entityMap.begin(); it != m_entityMap.end(); ++it)
		{
			((*it).second)->clean();
		}

		m_entityMap.clear();
	}
}
