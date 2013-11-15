/*
 * System.cpp
 *
 *  Created on: Nov 14, 2013
 *      Author: slacker
 */

#include <ECS/System.h>
#include <cassert>

#include <stdexcept>

System::System(): ISystem()
{
}

System::~System()
{
}

void System::addEntity(EntityPtr entity)
{
	m_entityMap[entity->getID()] = entity;
}

void System::removeEntity(const std::string& id)
{
	EntityMap::size_type size = m_entityMap.erase(id);

	// Do not throw exception, not a serious issue
	assert(size > 0);
}

void System::removeEntity(EntityPtr entity)
{
	removeEntity(entity->getID());
}

void System::clean()
{
	for(auto it = m_entityMap.begin(); it != m_entityMap.end(); ++it)
		(*it).second->clean();

	m_entityMap.clear();
}
