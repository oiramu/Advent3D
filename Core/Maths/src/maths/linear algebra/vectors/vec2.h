#pragma once

#include <iostream>
#include <math.h>

namespace Advent3D { namespace Maths {

struct vec2
{
	//components
	float x;
	float y;

	//length
	float magnitude;

	//constructors
	vec2();
	vec2(const float& x, const float& y);

	//operations
	vec2& Add(const vec2& other);
	vec2& Subtract(const vec2& other);
	vec2& Multiply(const vec2& other);
	vec2& Divide(const vec2& other);

	//operators
	friend vec2& operator+ (vec2& left, const vec2& right);
	friend vec2& operator- (vec2& left, const vec2& right);
	friend vec2& operator* (vec2& left, const vec2& right);
	friend vec2& operator/ (vec2& left, const vec2& right);
	
	friend std::ostream& operator<< (std::ostream& stream, const vec2& vector);

	vec2& operator+= (const vec2& other);
	vec2& operator-= (const vec2& other);
	vec2& operator*= (const vec2& other);
	vec2& operator/= (const vec2& other);

	//utility functions
	void Normalize();

	void CalculateMagnitude();

};
		 
} }