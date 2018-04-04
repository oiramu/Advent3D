#pragma once

//STL
#include <iostream>
#include <math.h>

namespace advent { namespace maths {

struct vec4
{
	//components
	float x;
	float y;
	float z;
	float w;

	//constructors
	vec4();
	vec4(const float& x, const float& y, const float& z, const float& w);

	//operations
	vec4& add(const vec4& other);
	vec4& subtract(const vec4& other);
	vec4& multiply(const vec4& other);
	vec4& divide(const vec4& other);

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
	void normalize();

};
} }