/*
 * System.h
 *
 *  Created on: Nov 14, 2013
 *      Author: slacker
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <map>
#include <ECS/Entity.h>

#include <ECS/ISystem.h>

class System: public ISystem
{
public:
	System();
	virtual ~System();

	virtual void addEntity(EntityPtr entity) final;
	virtual void removeEntity(const std::string& id) final;
	virtual void removeEntity(EntityPtr entity) final;

	void getEntity(const std::string& id);

	virtual void update(float dt) = 0;

	virtual void initialize() = 0;
	virtual void clean();

protected:
	// TODO: Change to vector
	typedef std::map<std::string, EntityPtr> EntityMap;
	EntityMap m_entityMap;
};

#endif /* SYSTEM_H_ */
