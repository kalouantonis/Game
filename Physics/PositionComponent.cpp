/*
 * PositionComponent.cpp
 *
 *  Created on: Nov 18, 2013
 *      Author: slacker
 */

#include <Physics/PositionComponent.h>

const std::string PositionComponent::ID = "position";

PositionComponent::PositionComponent()
	: Component()
	,m_position()
{
	// TODO Auto-generated constructor stub

}

PositionComponent::PositionComponent(float x, float y)
	: m_position(x, y)
{

}

PositionComponent::PositionComponent(const Vector2& pos)
	: m_position(pos)
{

}

PositionComponent::~PositionComponent()
{
	// TODO Auto-generated destructor stub
}

