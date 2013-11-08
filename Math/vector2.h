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

#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>

const float TO_RADIANS = (1 / 180.f) * (float)M_PI;
const float TO_DEGREES = (1 / (float)M_PI) * 180.f;

class Vector2
{
public:
    Vector2(float x = 0, float y = 0);
	Vector2(const Vector2& vec);
	
	void set(const Vector2& vec);
	
	// Operator overloads
	Vector2& operator+=(const Vector2& vec);
	
	Vector2& operator-=(const Vector2& vec);
	
	Vector2& operator*=(const Vector2& vec);
	
	// Asignment op
	Vector2& operator=(Vector2 rhs);
	
	
	// Math functions
	float length();
	
	Vector2& normalize();
	
	float angle();	
	Vector2& rotate(float angle);
	
	float distance(const Vector2& other);
	float distance(float x, float y);
	float distSquared(const Vector2& other);
	float distSquared(float x, float y);
	
	float x;
	float y;
};

template<typename T>
Vector2 operator*(Vector2 lhs, T scalar);

Vector2 operator+(Vector2 lhs, const Vector2& rhs);
Vector2 operator-(Vector2 lhs, const Vector2& rhs);

// Comparison ops
inline bool operator==(const Vector2& rhs, const Vector2& lhs) 
{
	return (rhs.x == lhs.x) && (rhs.x == lhs.y);
}
inline bool operator!=(const Vector2& rhs, const Vector2& lhs) { return !operator==(lhs, rhs); }
inline bool operator<(const Vector2& rhs, const Vector2& lhs) { return (rhs.x < lhs.x) && (rhs.y < lhs.x); }
inline bool operator>(const Vector2& rhs, const Vector2& lhs) { return operator<(rhs, lhs); }
inline bool operator>=(const Vector2& rhs, const Vector2& lhs) { return !operator<(lhs, rhs); }
inline bool operator<=(const Vector2& rhs, const Vector2& lhs) { return !operator>(lhs, rhs); }


#endif // VECTOR2_H
