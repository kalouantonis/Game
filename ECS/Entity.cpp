/*
 * Entity.cpp
 *
 *  Created on: Nov 14, 2013
 *      Author: slacker
 */

#include <ECS/Entity.h>
#include <cassert>
#include <stdexcept>

#include <Utils/logger.h>

Entity::Entity(const std::string& id)
	: m_id(id)
{
}

Entity::~Entity()
{
	// Clean itself up
	clean();
}

void Entity::addComponent(CompPtr comp)
{
	m_components[comp->getID()] = comp;
}

void Entity::removeComponent(const std::string& id)
{
	CompMap::size_type size = m_components.erase(id);

	assert(size > 0);
}

void Entity::removeComponent(CompPtr comp)
{
	removeComponent(comp->getID());
}

CompPtr Entity::getComponent(const std::string& id)
{
	CompPtr sought;

	try
	{
		sought = m_components.at(id);
	}
	catch(std::out_of_range& e)
	{
		sought = nullptr;

		log(DEBUG, "Entity::getComponent -- attempted to access invalid map object: %s\n", id.c_str());
	}

	return sought;
}

void Entity::clean()
{
	if(!m_components.empty())
		m_components.clear();
}
