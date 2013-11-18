/*
 * EntityManager.h
 *
 *  Created on: Nov 18, 2013
 *      Author: slacker
 */

#ifndef ENTITYMANAGER_H_
#define ENTITYMANAGER_H_

#include <map>
#include <ECS/Entity.h>

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	/**
	 * Create entity and add it to the manager
	 */
	EntityPtr createEntity(const std::string& id);
	/**
	 * Add entity to manager
	 */
	void addEntity(EntityPtr entity);

	EntityPtr getEntity(const std::string& id);
	/**
	 * Will remove entity from map and destroy it
	 */
	void removeEntity(const std::string& id);
	void removeEntity(EntityPtr entity);

	void clean();

private:
	typedef std::map<std::string, EntityPtr> EntityMap;
	EntityMap m_entityMap;
};

#endif /* ENTITYMANAGER_H_ */
