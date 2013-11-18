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
#include <Physics/PositionComponent.h>

#include <ECS/ISystem.h>

const float MAX_LEVEL = 1.f;

class RenderSystem: public ISystem
{
public:
	RenderSystem(SDL_Renderer* renderer);
	~RenderSystem();

	void addEntity(float level, EntityPtr entity);
	virtual void addEntity(EntityPtr entity) final;


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

	typedef std::map<std::string, std::pair<SpritePtr, PositionPtr> > CompMap;
	typedef std::map<float, CompMap, levelCompare > SpriteMap;
	SpriteMap m_sprites;
};

#endif /* RENDERSYSTEM_H_ */
