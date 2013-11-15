/*
 * RenderSystem.h
 *
 *  Created on: Nov 14, 2013
 *      Author: slacker
 */

#ifndef RENDERSYSTEM_H_
#define RENDERSYSTEM_H_

#include <map>
#include <Graphics/Sprite.h>

#include <ECS/ISystem.h>

class RenderSystem: public ISystem
{
public:
	RenderSystem(SDL_Renderer* renderer);
	~RenderSystem();

	virtual void addEntity(int level, EntityPtr entity) final;

	// Will only delete first occurance of ID
	virtual void removeEntity(const std::string& id) final;
	virtual void removeEntity(EntityPtr entity) final;

	void render();

	virtual void initialize() final;
	virtual void clean() final;

private:
	SDL_Renderer* m_pRenderer;

	// Struct used for ordering map keys according to level
	struct levelCompare
	{
		bool operator() (const int lhs, const int rhs) const
		{
			return lhs < rhs;
		}
	};

	typedef std::map<std::string, SpritePtr> CompMap;
	typedef std::map<int, CompMap, levelCompare > SpriteMap;
	SpriteMap m_sprites;
};

#endif /* RENDERSYSTEM_H_ */
