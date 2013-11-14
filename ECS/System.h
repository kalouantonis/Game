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

#include <SDL2/SDL_render.h>

class System
{
public:
	System(SDL_Renderer* renderer);
	virtual ~System();

	void addEntity(EntityPtr entity);
	void removeEntity(const std::string& id);
	void removeEntity(EntityPtr entity);

	virtual void initialize() = 0;
	virtual void update(float dt) = 0;

	virtual void render() = 0;

	virtual void clean();

protected:
	SDL_Renderer* m_pRenderer;

	typedef std::map<std::string, EntityPtr> EntityMap;
	EntityMap m_entityMap;
};

#endif /* SYSTEM_H_ */
