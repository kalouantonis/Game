/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2013  Antonis Kalou <kalouantonis@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Math/vector2.h>

class GameObject
{
public:
    GameObject(const Vector2& pos = Vector2(), const Vector2& size = Vector2(1, 1), const Vector2& vel = Vector2());
    virtual ~GameObject();
	
	virtual void update(float delta);
	
	void setVelocity(float x, float y) { m_velocity.x = x; m_velocity.y = y; }
	void setVelocity(const Vector2& vec) { m_velocity = vec; }
	Vector2 getVelocity() const { return m_velocity; }
	
	void setPosition(float x, float y) { m_position.x = x; m_position.y = y; }
	void setPosition(const Vector2& vec) { m_position = vec; }	
	Vector2 getPosition() const { return m_position; }
	
	void setSize(float x, float y) { m_size.x = x; m_size.y = y; }
	void setSize(const Vector2& vec) { m_size = vec; }
	Vector2 getSize() const { return m_size; }
	
private:
	Vector2 m_position;
	Vector2 m_size;
	
	Vector2 m_velocity;
};

#endif // GAMEOBJECT_H
