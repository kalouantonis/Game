/*
 * Color.h
 *
 *  Created on: 11 Nov 2013
 *      Author: slacker
 */

#ifndef COLOR_H_
#define COLOR_H_

#include <SDL2/SDL_bits.h>

class Color
{
public:
	Color(Uint8 r = 0, Uint8 g = 0, Uint8 b = 0, Uint8 a = 255);
	~Color();

	// Copy constructor
	Color(const Color& col);

	// Some operators
	Color& operator+=(const Color& col);
	Color& operator-=(const Color& col);
	Color& operator*=(const Color& col);

	Color& operator=(Color col);

	// Normalize for opengl maybe
	Color& normalize();

	// Values
	Uint8 r, g, b, a;
};

inline bool operator==(const Color& rhs, const Color& lhs)
{
	return (rhs.r == lhs.r) && (rhs.g == lhs.g)
			&& (rhs.b == lhs.b) && (rhs.a == lhs.a);
}

inline bool operator!=(const Color& rhs, const Color& lhs) { return !operator==(rhs, lhs); }
inline bool operator<(const Color& rhs, const Color& lhs)
{
	return (rhs.r < lhs.r) && (rhs.g < lhs.g)
			&& (rhs.b < lhs.b) && (rhs.a < lhs.a);
}

inline bool operator>(const Color& rhs, const Color& lhs) { return operator<(rhs, lhs); }
inline bool operator>=(const Color& rhs, const Color& lhs) { return !operator<(lhs, rhs); }
inline bool operator<=(const Color& rhs, const Color& lhs) { return !operator>(lhs, rhs); }

#endif /* COLOR_H_ */
