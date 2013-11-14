/*
 * Entity.h
 *
 *  Created on: Nov 14, 2013
 *      Author: slacker
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <memory>
#include <map>
#include <string>

#include <ECS/Component.h>

class Entity
{
public:
	typedef std::map<std::string, CompPtr> CompMap;

	Entity(const std::string& id);
	virtual ~Entity();

	void addComponent(CompPtr comp);

	CompPtr getComponent(const std::string& id);

	void removeComponent(const std::string& id);
	void removeComponent(CompPtr comp);

	void clean();

	std::string getID() { return m_id; }

private:
	CompMap m_components;

	std::string m_id;
};

typedef std::shared_ptr<Entity> EntityPtr;

#endif /* ENTITY_H_ */
