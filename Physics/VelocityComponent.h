/*
 * VelocityComponent.h
 *
 *  Created on: Nov 18, 2013
 *      Author: slacker
 */

#ifndef VELOCITYCOMPONENT_H_
#define VELOCITYCOMPONENT_H_

#include <ECS/Component.h>
#include <Math/vector2.h>

class VelocityComponent: public Vector2
{
public:
	VelocityComponent();
	VelocityComponent(float x, float y);
	VelocityComponent(const Vector2& vel);

	~VelocityComponent();

private:
	Vector2 m_velocity;
};

#endif /* VELOCITYCOMPONENT_H_ */
