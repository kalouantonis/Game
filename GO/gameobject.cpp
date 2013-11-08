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

#include "gameobject.h"

GameObject::GameObject(const Vector2& pos, const Vector2& size, const Vector2& vel)
	: m_position(pos)
	, m_size(size)
	, m_velocity(vel)
{
	
}

GameObject::~GameObject()
{

}

void GameObject::update(float delta)
{
	// Default position updating
	m_position += m_velocity * delta;
}

