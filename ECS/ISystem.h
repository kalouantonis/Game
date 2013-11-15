/*
 * ISystem.h
 *
 *  Created on: Nov 15, 2013
 *      Author: slacker
 */

#ifndef ISYSTEM_H_
#define ISYSTEM_H_

#include <ECS/Entity.h>

class ISystem
{
public:
	ISystem();
	virtual ~ISystem();

	virtual void addEntity(EntityPtr entity) = 0;
	virtual void removeEntity(const std::string& id) = 0;
	virtual void removeEntity(EntityPtr entity) = 0;

	virtual void initialize() = 0;
	virtual void clean() = 0;
};

#endif /* ISYSTEM_H_ */
