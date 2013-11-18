/*
 * PositionComponent.h
 *
 *  Created on: Nov 18, 2013
 *      Author: slacker
 */

#ifndef POSITIONCOMPONENT_H_
#define POSITIONCOMPONENT_H_

#include <ECS/Component.h>
#include <Math/vector2.h>

const std::string PositionID = "position";

class PositionComponent: public Component
{
public:
	PositionComponent();
	PositionComponent(int x, int y);
	PositionComponent(const Vector2& pos);

	~PositionComponent();

	int getX() { return m_position.x; }
	int getY() { return m_position.y; }
	Vector2 getPosition() { return m_position; }

	void setX(int x) { m_position.x = x; }
	void setY(int y) { m_position.y = y; }
	void setPosition(const Vector2& vec) { m_position = vec; }
	void setPosition(int x, int y) { m_position.x = x; m_position.y = y; }

	virtual std::string getID() { return PositionID; }

private:
	Vector2 m_position;
};

typedef std::shared_ptr<PositionComponent> PositionPtr;

#endif /* POSITIONCOMPONENT_H_ */
