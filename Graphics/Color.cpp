/*
 * Color.cpp
 *
 *  Created on: 11 Nov 2013
 *      Author: slacker
 */

#include <Graphics/Color.h>

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	: r(r)
	, g(g)
	, b(b)
	, a(a)
{
}

Color::~Color()
{
}

Color::Color(const Color& col)
{
	r = col.r;
	g = col.g;
	b = col.b;
	a = col.a;
}

Color& Color::operator+=(const Color& col)
{
	this->r += col.r;
	this->g += col.g;
	this->b += col.b;
	this->a += col.a;

	return *this;
}

Color& Color::operator -=(const Color& col)
{
	this->r -= col.r;
	this->g -= col.g;
	this->b -= col.b;
	this->a -= col.a;

	return *this;
}

Color& Color::operator *=(const Color& col)
{
	this->r *= col.r;
	this->g *= col.g;
	this->b *= col.b;
	this->a *= col.a;

	return *this;
}

Color& Color::operator =(Color col)
{
	this->r = col.r;
	this->g = col.g;
	this->b = col.b;
	this->a = col.a;

	return *this;
}

Color& Color::normalize()
{
	r = r / 255;
	g = g / 255;
	b = b / 255;
	a = a / 255;

	return *this;
}
