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

#include "vector2.h"
#include <algorithm>

Vector2::Vector2(float x, float y)
	: x(x)
	, y(y)
{
	
}

void Vector2::set(const Vector2& vec)
{
	*this = vec;
}

Vector2::Vector2(const Vector2& vec)
{
	this->x = vec.x;
	this->y = vec.y;
}

float Vector2::length()
{
	return sqrt(x * x + y * y);
}

Vector2& Vector2::normalize()
{
	float len = length();
	
	if(len != 0)
	{
		this->x /= len;
		this->y /= len;
	}
	
	return *this;
}

float Vector2::angle()
{
	float angle = (float)atan2(y, x) * TO_DEGREES;
	
	if(angle < 0)
		angle += 360;
	
	return angle;
}

Vector2& Vector2::rotate(float angle)
{
	float rad = angle * TO_RADIANS;
	float cosine = cos(rad);
	float sine = sin(rad);
	
	x = x * cosine - y * sine;
	y = x * sine + y * cosine;
	
	return *this;
}

float Vector2::distance(const Vector2& other)
{
	return distance(other.x, other.y);
}

float Vector2::distance(float x, float y)
{
	float distX = this->x - x;
	float distY = this->y - y;
	
	return sqrt(distX * distX + distY * distY);
}

float Vector2::distSquared(float x, float y)
{
	float distX = this->x - x;
	float distY = this->y - y;
	
	return distX * distX + distY * distY;
}

float Vector2::distSquared(const Vector2& other)
{
	return distSquared(other.x, other.y);
}


// Operator overloads
Vector2& Vector2::operator=(Vector2 rhs)
{
	std::swap(rhs);
	return *this;
}


Vector2& Vector2::operator+=(const Vector2& vec)
{
	this->x += vec.x;
	this->y += vec.y;
	
	return *this;
}

Vector2& Vector2::operator*=(const Vector2& vec)
{
	this->x *= vec.x;
	this->y *= vec.y;
	
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	
	return *this;
}



Vector2 operator+(Vector2 lhs, const Vector2& rhs)
{
	lhs += rhs;
	return lhs;
}

Vector2 operator-(Vector2 lhs, const Vector2& rhs)
{
	lhs -= rhs;
	return lhs;
}

template<typename T>
Vector2 operator*(Vector2 lhs, T scalar)
{
	lhs.x *= scalar;
	lhs.y *= scalar;
	
	return lhs;
}

// Comparison operators





