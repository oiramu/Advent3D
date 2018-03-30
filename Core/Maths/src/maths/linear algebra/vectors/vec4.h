#pragma once

#include <iostream>
#include <math.h>

namespace Advent3D { namespace Maths {

struct vec4
{
	//components
	float x;
	float y;
	float z;
	float w;

	//length
	float magnitude;

	//constructors
	vec4();
	vec4(const float& x, const float& y, const float& z, const float& w);

	//operations
	vec4& Add(const vec4& other);
	vec4& Subtract(const vec4& other);
	vec4& Multiply(const vec4& other);
	vec4& Divide(const vec4& other);

	//operators
	friend vec4& operator+ (vec4& left, const vec4& right);
	friend vec4& operator- (vec4& left, const vec4& right);
	friend vec4& operator* (vec4& left, const vec4& right);
	friend vec4& operator/ (vec4& left, const vec4& right);

	friend std::ostream& operator<< (std::ostream& stream, const vec4& vector);

	vec4& operator+= (const vec4& other);
	vec4& operator-= (const vec4& other);
	vec4& operator*= (const vec4& other);
	vec4& operator/= (const vec4& other);

	//utility functions
	void Normalize();

	void CalculateMagnitude();

};
} }