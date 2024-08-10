#pragma once
#include <cmath>
#include "../Math/MathUtils.h"
#include <stdint.h>


struct Color
{
	float r = 0;
	float g = 0;
	float b = 0;
	float a = 0;

	Color() = default;
	Color(float r, float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}


	float operator [] (unsigned int index) const { return (&r)[index]; }
	float& operator [] (unsigned int index) { return (&r)[index]; }

	Color operator + (const Color& c) const { return Color{ r + c.r, g + c.g, b + c.b, a + c.a }; }
	Color operator - (const Color& c) const { return Color{ r - c.r, g - c.g, b - c.b, a - c.a }; }
	Color operator * (const Color& c) const { return Color{ r * c.r, g * c.g, b * c.b, a * c.a }; }
	Color operator / (const Color& c) const { return Color{ r / c.r, g / c.g, b / c.b, a / c.a }; }

	/*Color operator + (float s) const { return Color{ x + s, y + s }; }
	Color operator - (float s) const { return Color{ x - s, y - s }; }
	Color operator * (float s) const { return Color{ x * s, y * s }; }
	Color operator / (float s) const { return Color{ x / s, y / s }; }
	
	Color& operator += (const Color& v) { x += v.x; y += v.y; return *this; }
	Color& operator -= (const Color& v) { x -= v.x; y -= v.y; return *this; }
	Color& operator *= (const Color& v) { x *= v.x; y *= v.y; return *this; }
	Color& operator /= (const Color& v) { x /= v.x; y /= v.y; return *this; }

	Color& operator += (float s) { x += s; y += s; return *this; }
	Color& operator -= (float s) { x -= s; y -= s; return *this; }
	Color& operator *= (float s) { x *= s; y *= s; return *this; }
	Color& operator /= (float s) { x /= s; y /= s; return *this; }*/

	static uint8_t ToInt(float c) { return static_cast<uint8_t>(Math::Clamp(c, 0.0f, 1.0f) * 255); }
};